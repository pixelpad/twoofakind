<?php

/**
 * @file
 * Legacy user migration
 * 
 * NOTE
 * using an alternate DB doesn't work as you need the migrate module tables to be on the same DB as both the Drupal
 * (for results tracking) installation and the source tables (for JOINS).
 */

/**
 * Basic migration class
 */
abstract class TwooofakindMigration extends Migration {

  public $imageUri;
  public $imagePath;
  
  public function __construct() {

    parent::__construct();

    // set image path (to write to from DB)
    $this->imageUri = file_build_uri('pictures');
    $this->imagePath = drupal_realpath($this->imageUri);

    $this->team = array(
      new MigrateTeamMember('Mike Kelly', 'mike@whatsthatweb.com.au', t('System administrator'))
    );
  }
  
  /**
   * Get Image query
   */
  public function __getQueryImage($userId = null) {

//    $query = db_select('osdate_usersnaps', 's', array('target' => 'legacy'));
    $query = db_select('osdate_usersnaps', 's');
    $query->fields('s', array('id', 'picture', 'picno'));
//    $query->addExpression('s.id', 'sid');
    $query->addExpression('CONCAT(s.userid, \'-\', s.picno, \'.\', LOWER(s.picext))', 'filename');
    // we can't join the user table due to the same ambiguous id problem
    // I need to find a solution for this
    $query->addExpression('CONCAT(\'User\', \' pic\')', 'image_title');
//    $query->addExpression('CONCAT(u.username, \'s pic\')', 'image_title');
//    $query->leftJoin('osdate_user', 'u', 's.userid = u.id');
//    $query->condition('u.active', 1, '=');
    if (!empty($userId)) {
      $query->condition('s.userid', $userId, '=');
    }
    $query->condition('s.active', 'Y', '=');
    $query->condition('s.picture', '', '!=');
    return $query;
    
  }

}

/**
 * Image migration class
 */
class LegacyImageMigration extends TwooofakindMigration {
  
  public function __construct() {
    parent::__construct();
    
    $this->description = t('Legacy user images');
    $this->map = new MigrateSQLMap($this->machineName,
        array('id' => array(
                'type' => 'int',
                'unsigned' => TRUE,
                'not null' => TRUE,
                'description' => 'Image ID.'
                )
             ),
        MigrateDestinationFile::getKeySchema()
    );
    
    $query = $this->__getQueryImage();
    
    $source_fields = array(
      'uri' => t('URI for this file'),
    );
    
    $this->source = new MigrateSourceSQL($query, $source_fields);
    $this->destination = new MigrateDestinationFile();

    // Just map the incoming path to the destination's 'uri'
    $this->addFieldMapping('uri', 'uri');
    
    // unmapped source
    $this->addFieldMapping(NULL, 'picture')
        ->description(t('Used in prepareRow'))
        ->issueGroup(t('DNM'));
    $this->addFieldMapping(NULL, 'picno')
        ->description(t('Used in prepareRow'))
        ->issueGroup(t('DNM'));
    $this->addFieldMapping(NULL, 'filename')
        ->description(t('Used in prepareRow'))
        ->issueGroup(t('DNM'));
    $this->addFieldMapping(NULL, 'image_title')
        ->description(t('Used in prepareRow'))
        ->issueGroup(t('DNM'));
    
    // unmapped destination
    $this->addUnmigratedDestinations(array('fid', 'uid', 'filename', 'status',
      'filemime', 'timestamp', 'contents', 'path'));
  }
  
  /**
   * prepareRow runs AFTER values have been retrieved but BEFORE the values have been mapped
   *
   * @param type $current_row 
   */
  public function prepareRow($current_row) {

    // if no pic string do nothing
    if (empty($current_row->picture)) {
      return FALSE;
    }
    
    // update the uri value
    $current_row->uri = $this->imageUri . '/' . $current_row->filename;
    
    // generate a path value
    $filepath = $this->imagePath . '/' . $current_row->filename;
    
    // write file from DB
    $this->__writeDbImageToFile($current_row->picture, $filepath);
    
    // all good
    return TRUE;
    
  }

  /**
   * Write image data to a file
   * 
   * @param type $image_data
   * @param type $filepath
   */
  private function __writeDbImageToFile($image_data, $filepath) {

    $image_string = base64_decode($image_data);
    $image = imagecreatefromstring($image_string);
    imagejpeg($image, $filepath);
  }
}

/**
 * Legacy user migration class
 */
class LegacyUserMigration extends TwooofakindMigration {

  public function __construct() {

    parent::__construct();
    
    $this->description = t('Legacy users');
    $this->dependencies = array('LegacyImage');
    $this->map = new MigrateSQLMap($this->machineName,
      array('id' => array(
          'type' => 'int',
          'not null' => TRUE,
          'description' => 'Legacy user ID.'
        )
      ),
      MigrateDestinationUser::getKeySchema()
    );

    $query = $this->__getQuery();

    $source_fields = array(
      // images
      'images' => t('Images for this user'),
      'profile_picture_id' => t('Profile picture for this user'),
      // additional roles
      'roles' => t('Additional roles'),
      // questions
      'relation_status' => t('Relationship status'),
      'relig_affiliation' => t('Religious affiliation'),
      'height' => t('Height'),
      'body_type' => t('Body type'),
      'kosher' => t('Do they keep kosher?'),
      'colour_eyes' => t('Eye colour'),
      'colour_hair' => t('Hair colour'),
      'friend_summary' => t('Friends say'),
      'smoker' => t('Smoker?'),
      'drinking' => t('Drinking habits'),
      'passionate_about' => t('Passionate about...'),
      'education' => t('Level of education'),
      'languages' => t('Languages spoken'),
      'children' => t('Do they want children'),
    );

//    $count_query = db_select('osdate_user', 'u', array('target' => 'legacy'));
    $count_query = db_select('osdate_user', 'u');
    $count_query->addExpression('COUNT(u.id)', 'cnt');

    $this->source = new MigrateSourceSQL($query, $source_fields, $count_query);
    $this->destination = new MigrateDestinationUser();

    // Mapped fields
    // from users table
//    $this->addFieldMapping('uid', 'id')
//        ->description(t('Preserve user id as uid in Drupal'));
    $this->addFieldMapping('is_new')
        ->defaultValue(1); // is new
    $this->addFieldMapping('name', 'username')
        ->dedupe('users', 'name');
    $this->addFieldMapping('status', 'active');
//    $this->addFieldMapping('login', 'lastvisit');
    $this->addFieldMapping('created', 'regdate');
    $this->addFieldMapping('field_online', 'allow_viewonline');
    $this->addFieldMapping('mail', 'email');
    $this->addFieldMapping('field_heard_about_us', 'hearboutus');
    $this->addFieldMapping('field_name_first', 'firstname');
    $this->addFieldMapping('field_name_last', 'lastname');
    $this->addFieldMapping('field_sex', 'gender');
    $this->addFieldMapping('field_match_sex', 'lookgender');
    $this->addFieldMapping('field_match_age_min', 'lookagestart');
    $this->addFieldMapping('field_match_age_max', 'lookageend');
    $this->addFieldMapping('field_date_of_birth', 'birth_date');
    $this->addFieldMapping('field_match_user_location', 'lookcity');
    // question answers
    $this->addFieldMapping('field_relation_status', 'relation_status');
    $this->addFieldMapping('field_relig_affiliation', 'relig_affiliation');
    $this->addFieldMapping('field_height', 'height');
    $this->addFieldMapping('field_body_type', 'body_type');
    $this->addFieldMapping('field_kosher', 'kosher');
    $this->addFieldMapping('field_eye_colour', 'colour_eyes');
    $this->addFieldMapping('field_hair_colour', 'colour_hair');
    $this->addFieldMapping('field_friend_summary', 'friend_summary');
    $this->addFieldMapping('field_smoker', 'smoker');
    $this->addFieldMapping('field_drinking', 'drinking');
    $this->addFieldMapping('field_passionate_about', 'passionate_about');
    $this->addFieldMapping('field_education', 'education');
    $this->addFieldMapping('field_languages', 'languages');
    $this->addFieldMapping('field_have_kids', 'children');
    // other defaults
    $this->addFieldMapping('roles', 'roles')
        ->defaultValue(2); // authenticated
    // images
    // profile image
    $this->addFieldMapping('picture', 'profile_picture_id')
         ->sourceMigration('LegacyImage');
    // other images
    // We will get the image data from a related table in prepareRow()
    $this->addFieldMapping('field_images', 'images')
        ->sourceMigration('LegacyImage');

    // Unmapped source fields
    // these will be used to build a location in prepare function below
    $this->addFieldMapping(NULL, 'address_line1')
        ->description(t('Location values used within prepare method'))
        ->issueGroup(t('DNM'));
    $this->addFieldMapping(NULL, 'address_line2')
        ->description(t('Location values used within prepare method'))
        ->issueGroup(t('DNM'));
    $this->addFieldMapping(NULL, 'state_province')
        ->description(t('Location values used within prepare method'))
        ->issueGroup(t('DNM'));
    $this->addFieldMapping(NULL, 'county')
        ->description(t('Location values used within prepare method'))
        ->issueGroup(t('DNM'));
    $this->addFieldMapping(NULL, 'city')
        ->description(t('Location values used within prepare method'))
        ->issueGroup(t('DNM'));
    $this->addFieldMapping(NULL, 'zip')
        ->description(t('Location values used within prepare method'))
        ->issueGroup(t('DNM'));
    $this->addFieldMapping(NULL, 'country')
        ->description(t('Location values used within prepare method'))
        ->issueGroup(t('DNM'));
    // last visit - we're not recording this against login at this time
    $this->addFieldMapping(NULL, 'lastvisit')
        ->description(t('We\'re not going to record this against login at this time'))
        ->issueGroup(t('DNM'));

    // Unmapped destination fields
    $this->addFieldMapping('login')
        ->description(t('We\'re not going to record a login value at this time'))
        ->issueGroup(t('DNM'));
    $this->addUnmigratedDestinations(array('pass', 'theme', 'signature', 'signature_format', 'access',
      'timezone', 'language', 'init', 'data', 'field_have_pets', 'field_headline', 'field_industry',
      'field_other_pet', 'field_personality', 'field_political', 'field_star_sign', 'field_want_kids',
      'field_match_star_sign', 'field_match_personality', 'field_match_eye_colour', 'field_match_hair_colour',
      'field_match_height', 'field_match_body_type', 'field_match_relig_affiliation', 'field_match_kosher',
      'field_match_smoker', 'field_match_drinking', 'field_match_have_kids', 'field_self_summary',
      'field_match_self_summary', 'field_match_friend_summary', 'field_match_passionate_about', 'field_match_headline',
      'field_phone_mobile', 'field_admin_notes', 'path', 'field_other_language'));
  }

  /**
   * prepareRow runs AFTER values have been retrieved but BEFORE the values have been mapped
   *
   * @param type $current_row 
   */
  public function prepareRow($current_row) {

    // images
    $this->__prepareRowImages($current_row);

    // DOING ALL OF THE QUESTIONS SEPARATELY DUE TO AMBIGUITY ISSUES (IN SQL)
    $this->__prepareRowQuestionRelationshipStatus($current_row);
    $this->__prepareRowQuestionReligiousAffiliation($current_row);
    $this->__prepareRowQuestionHeight($current_row);
    $this->__prepareRowQuestionBodyType($current_row);
    $this->__prepareRowQuestionKosher($current_row);
    $this->__prepareRowQuestionColourEyes($current_row);
    $this->__prepareRowQuestionColourHair($current_row);
    $this->__prepareRowQuestionFriendSummary($current_row);
    $this->__prepareRowQuestionSmoker($current_row);
    $this->__prepareRowQuestionDrinking($current_row);
    $this->__prepareRowQuestionPassionateAbout($current_row);
    $this->__prepareRowQuestionEducation($current_row);
    $this->__prepareRowQuestionLanguages($current_row);
    $this->__prepareRowQuestionChildren($current_row);

    // add a deactivated role if user is blocked
    if (!$current_row->active) {
      $current_row->roles[] = 7; // deactivated
    }

    // this row is OK
    return TRUE;
  }

  /**
   * Run image functions in prepareRow
   * 
   * @param type $current_row
   */
  private function __prepareRowImages($current_row) {
    
    // extract files from the DB
    $query = $this->__getQueryImage($current_row->id);
    $result = $query->execute();
    $current_row->images = array();
    foreach ($result as $row) {
      
      // check for empty pic string
      if (empty($row->picture)) {
        $current_row->profile_picture_id = 0;
        $current_row->images = array();
        $current_row->image_title = '';
        continue;
      }
      
      // picno 1 is profile pic
      // the rest are field images
      if ($row->picno == 1) {
        $current_row->profile_picture_id = $row->id;
      }
      else {
        $current_row->images[] = $row->id;
      }
    }

  }

  /**
   * Question - relationship status
   * 
   * @param type $current_row
   */
  private function __prepareRowQuestionRelationshipStatus($current_row) {
    $expression = 'REPLACE(REPLACE(REPLACE(LOWER(o.answer), \'reform\', \'reform_progressive\'), '
        . '\'other\', \'\'), \' \', \'_\')';
    $result = $this->__prepareRowQuestionQuery($expression, $current_row->id, 1);
    foreach ($result as $row) {
      $current_row->relation_status = $row->answer;
      break; // only one value
    }
  }

  /**
   * Question - religious affiliation
   * 
   * @param type $current_row
   */
  private function __prepareRowQuestionReligiousAffiliation($current_row) {
    $expression = 'REPLACE(REPLACE(REPLACE(LOWER(o.answer), \'reform\', \'reform_progressive\'), '
        . '\'other\', \'\'), \' \', \'_\')';
    $result = $this->__prepareRowQuestionQuery($expression, $current_row->id, 3);
    foreach ($result as $row) {
      $current_row->relig_affiliation = $row->answer;
      break; // only one value
    }
  }

  /**
   * Question - height
   * 
   * @param type $current_row
   */
  private function __prepareRowQuestionHeight($current_row) {
    $expression = 'CONVERT(TRIM(MID(o.answer, 14, 4)), UNSIGNED)';
    $result = $this->__prepareRowQuestionQuery($expression, $current_row->id, 5);
    foreach ($result as $row) {
      $current_row->height = $row->answer;
      break; // only one value
    }
  }

  /**
   * Question - body type
   * 
   * @param type $current_row
   */
  private function __prepareRowQuestionBodyType($current_row) {
    $expression = 'LOWER(o.answer)';
    $result = $this->__prepareRowQuestionQuery($expression, $current_row->id, 6);
    foreach ($result as $row) {
      $current_row->body_type = $row->answer;
      break; // only one value
    }
  }

  /**
   * Question - kosher
   * 
   * @param type $current_row
   */
  private function __prepareRowQuestionKosher($current_row) {
    $expression = 'REPLACE(REPLACE(LOWER(o.answer), \'will eat out vegetarian\', \'eat_out_vegetarian\'), '
        . '\' \', \'_\')';
    $result = $this->__prepareRowQuestionQuery($expression, $current_row->id, 7);
    foreach ($result as $row) {
      $current_row->kosher = $row->answer;
      break; // only one value
    }
  }

  /**
   * Question - eye colour
   * 
   * @param type $current_row
   */
  private function __prepareRowQuestionColourEyes($current_row) {
    $expression = 'REPLACE(LOWER(o.answer), \' \', \'_\')';
    $result = $this->__prepareRowQuestionQuery($expression, $current_row->id, 8);
    foreach ($result as $row) {
      $current_row->colour_eyes = $row->answer;
      break; // only one value
    }
  }

  /**
   * Question - hair colour
   * 
   * @param type $current_row
   */
  private function __prepareRowQuestionColourHair($current_row) {
    $expression = 'REPLACE(REPLACE(REPLACE(REPLACE(REPLACE(REPLACE(LOWER(o.answer), \' \', \'_\'), '
        . '\'white/grey\', \'grey_white\'), \'blackish_brown\', \'dark_brown\'), \'red\', \'red_auburn\'), \'auburn\', '
        . '\'red_auburn\'), \'red_red_auburn\', \'red_auburn\')';
    $result = $this->__prepareRowQuestionQuery($expression, $current_row->id, 9);
    foreach ($result as $row) {
      $current_row->colour_hair = $row->answer;
      break; // only one value
    }
  }

  /**
   * Question - friends summary
   * 
   * @param type $current_row
   */
  private function __prepareRowQuestionFriendSummary($current_row) {
    $result = $this->__prepareRowQuestionQuerySimple($current_row->id, 17);
    foreach ($result as $row) {
      $current_row->friend_summary = $row->answer;
      break; // only one value
    }
  }

  /**
   * Question - smoker
   * 
   * @param type $current_row
   */
  private function __prepareRowQuestionSmoker($current_row) {
    $expression = 'REPLACE(REPLACE(REPLACE(LOWER(o.answer), \'socially\', \'occasionally\'), \'infrequently\', '
        . '\'occasionally\'), \'frequently\', \'yes\')';
    $result = $this->__prepareRowQuestionQuery($expression, $current_row->id, 18);
    foreach ($result as $row) {
      $current_row->smoker = $row->answer;
      break; // only one value
    }
  }

  /**
   * Question - drinking
   * 
   * @param type $current_row
   */
  private function __prepareRowQuestionDrinking($current_row) {
    $expression = 'REPLACE(REPLACE(REPLACE(LOWER(o.answer), \'just socially\', \'sometimes\'), '
        . '\'occasionally\',\'sometimes\'),\'frequently\',\'often\')';
    $result = $this->__prepareRowQuestionQuery($expression, $current_row->id, 21);
    foreach ($result as $row) {
      $current_row->drinking = $row->answer;
      break; // only one value
    }
  }

  /**
   * Question - passionate about
   * 
   * @param type $current_row
   */
  private function __prepareRowQuestionPassionateAbout($current_row) {
    $result = $this->__prepareRowQuestionQuerySimple($current_row->id, 25);
    foreach ($result as $row) {
      $current_row->passionate_about = $row->answer;
      break; // only one value
    }
  }

  /**
   * Question - education
   * 
   * @param type $current_row
   */
  private function __prepareRowQuestionEducation($current_row) {
    $expression = 'REPLACE(REPLACE(REPLACE(REPLACE(REPLACE(LOWER(o.answer),\' \',\'_\'), '
        . '\'_degree\',\'\'),\'secondary_education_(high_school)\',\'secondary\'), '
        . '\'diploma_/_certificate\',\'diploma_certificate\'),\'graduate_diploma/certificate\',\'graduate\')';
    $result = $this->__prepareRowQuestionQuery($expression, $current_row->id, 29);
    foreach ($result as $row) {
      $current_row->education = $row->answer;
    }
  }

  /**
   * Question - languages
   * 
   * @param type $current_row
   */
  private function __prepareRowQuestionLanguages($current_row) {
    $expression = 'LOWER(o.answer)';
    $result = $this->__prepareRowQuestionQuery($expression, $current_row->id, 30);
    foreach ($result as $row) {
      $current_row->languages[] = $row->answer;
    }
  }

  /**
   * Question - children
   * 
   * @param type $current_row
   */
  private function __prepareRowQuestionChildren($current_row) {
    $expression = 'LOWER(o.answer)';
    $result = $this->__prepareRowQuestionQuery($expression, $current_row->id, 37);
    foreach ($result as $row) {
      $current_row->children = $row->answer;
      break; // only one value
    }
  }

  /**
   * Question SQL
   * 
   * @param type $image_data
   * @param type $filename 
   */
  private function __prepareRowQuestionQuery($expression, $sourceId, $questionId) {
//    $query = db_select('osdate_userpreference', 'p', array('target' => 'legacy'));
    $query = db_select('osdate_userpreference', 'p');
    $query->leftJoin('osdate_questionoptions', 'o', 'p.answer = o.id');
    $query->addExpression($expression, 'answer');
    $query->condition('p.questionid', $questionId, '=');
    $query->condition('p.userid', $sourceId, '=');
    $result = $query->execute();
    return $result;
  }

  /**
   * Question SQL
   * 
   * @param type $image_data
   * @param type $filename 
   */
  private function __prepareRowQuestionQuerySimple($sourceId, $questionId) {
//    $query = db_select('osdate_userpreference', 'p', array('target' => 'legacy'));
    $query = db_select('osdate_userpreference', 'p');
    $query->fields('p', array('answer'));
    $query->condition('p.questionid', $questionId, '=');
    $query->condition('p.userid', $sourceId, '=');
    $result = $query->execute();
    return $result;
  }

  /**
   * prepareRow runs AFTER values have been retrieved AND AFTER the values have been mapped
   * 
   * @param stdClass $account
   * @param stdClass $row 
   */
  public function prepare(stdClass $account, stdClass $row) {

    // update sex field
    switch ($row->gender) {
      case 'm':
      case 'M':
        $account->field_sex[LANGUAGE_NONE][0]['value'] = 'male';
        break;
      case 'f':
      case 'F':
        $account->field_sex[LANGUAGE_NONE][0]['value'] = 'female';
        break;
      default:
        $account->field_sex = NULL;
        break;
    }

    // update match sex field
    switch ($row->lookgender) {
      case 'm':
      case 'M':
        $account->field_match_sex[LANGUAGE_NONE][0]['value'] = 'male';
        break;
      case 'f':
      case 'F':
        $account->field_match_sex[LANGUAGE_NONE][0]['value'] = 'female';
        break;
      default:
        $account->field_match_sex = NULL;
        break;
    }

    // update hear about us
    if (strpos(strtolower($row->hearboutus), 'email') !== FALSE) {
      $account->field_heard_about_us[LANGUAGE_NONE][0]['value'] = 'email';
    }
    else if (strpos(strtolower($row->hearboutus), 'internet') !== FALSE) {
      $account->field_heard_about_us[LANGUAGE_NONE][0]['value'] = 'internet';
    }
    else if (strpos(strtolower($row->hearboutus), 'friend') !== FALSE) {
      $account->field_heard_about_us[LANGUAGE_NONE][0]['value'] = 'friend';
    }
    else if (strpos(strtolower($row->hearboutus), 'chat') !== FALSE) {
      $account->field_heard_about_us[LANGUAGE_NONE][0]['value'] = 'chat';
    }
    else if (strpos(strtolower($row->hearboutus), 'network') !== FALSE) {
      $account->field_heard_about_us[LANGUAGE_NONE][0]['value'] = 'organisation';
    }
    else if (strpos(strtolower($row->hearboutus), 'google') !== FALSE) {
      $account->field_heard_about_us[LANGUAGE_NONE][0]['value'] = 'google';
    }
    else {
      $account->field_heard_about_us[LANGUAGE_NONE][0]['value'] = 'other';
    }
    
    // fix date of birth
    if (!empty($row->birth_date)) {
      $birth_date_parts = explode('-', $row->birth_date);
      if (count($birth_date_parts) == 3) {
        $year = $birth_date_parts[0];
        $month = (int) $birth_date_parts[1];
        $day = (int) $birth_date_parts[2];
        $account->field_date_of_birth[LANGUAGE_NONE][0]['value'] = mktime(0, 0, 0, $month, $day, $year);
      }
    }

    // add location information
    $location = array(
      'street' => trim($row->address_line1),
      'additional' => trim($row->address_line2),
      'city' => trim($row->county),
      'postal_code' => (int) trim($row->zip),
      'country' => trim($row->country)
    );
    // fix the stupid state thing
    $state_mappings = array(
      'NS' => 'NSW',
      'VT' => 'VIC',
      'QL' => 'QLD',
      'WA' => 'WA',
      'SA' => 'SA',
      'AC' => 'ACT',
      'NT' => 'NT',
      'TA' => 'TAS',
      'Auckland' => 'Auckland'
    );
    if (isset($state_mappings[$row->state_province])) {
      $location['province'] = $row->state_province;
    }
    // make sure post code is the right length
    if (strlen($location['postal_code']) > 4) {
      $location['postal_code'] = substr($location['postal_code'], 0, 4);
    }
    // fix the country value
    $countries_allowed = array(
      'AU',
      'NZ'
    );
    if (!in_array($location['country'], $countries_allowed)) {
      $location['country'] = 'AU';
    }
    // the county and city fields were both used to hold city info
    // city should override county if info is available
    if (!empty($row->city)) {
      $location['city'] = trim($row->city);
    }
    $account->locations = array($location);
    $account->location = $location;
  }

  /**
   * Get query
   */
  private function __getQuery() {

//    $query = db_select('osdate_user', 'u', array('target' => 'legacy'));
    $query = db_select('osdate_user', 'u');
    $query->fields('u', array('id', 'active', 'username', 'lastvisit', 'regdate', 'allow_viewonline', 'email', 'hearboutus',
      'firstname', 'lastname', 'gender', 'lookgender', 'lookagestart', 'lookageend', 'birth_date', 'lookcity',
      'address_line1', 'address_line2', 'state_province', 'county', 'city', 'zip', 'country'));

    // unambiguate user id
    // don't need this anymore due to reasons below
//    $query->addExpression('u.id', 'uid');
    // questions
    // removed and implemented in prepareRow
    // because all of these tables have an id field it causes ambiguity when joining them
    // migrate throws another join in
    // LEFT OUTER JOIN {migrate_map_legacyuser} map ON id = map.sourceid1
    // and it doesn't use the table alias you've defined
    // so it would seem no matter how much you unambiguate your own SQL migrate will eventually screw it
    // ONLY if all of your source DB tables use id as their key (for all tables)
    // UPDATE
    // If you use $query->addExpression('u.id', 'uid') and then define your identifier to be uid instead all works OK
    // UPDATE
    // This doesn't actually work as you can't use expression defined fields (uid) in a LEFT JOIN * ON statement
    // I think there will be a way though...
//    $query->addExpression('LOWER(o1.answer)', 'answer_1');
//    $query->leftJoin('osdate_userpreference', 'p1', 'u.id = p1.userid AND p1.questionid = 1');
//    $query->leftJoin('osdate_questions', 'q1', 'p1.questionid = q1.id');
//    $query->leftJoin('osdate_questionoptions', 'o1', 'p1.answer = o1.id');
//    $query->addExpression('REPLACE(REPLACE(REPLACE(LOWER(o2.answer), \'reform\', \'reform_progressive\'), 
//      \'other\', \'\'), \' \', \'_\')', 'answer_2');
//    $query->leftJoin('osdate_userpreference', 'p2', 'u.id = p2.userid AND p2.questionid = 3');
//    $query->leftJoin('osdate_questions', 'q2', 'p2.questionid = q2.id');
//    $query->leftJoin('osdate_questionoptions', 'o2', 'p2.answer = o2.id');
//    $query->addExpression('CONVERT(TRIM(MID(o3.answer, 14, 4)), UNSIGNED)', 'answer_3');
//    $query->leftJoin('osdate_userpreference', ' p3', 'u.id = p3.userid AND p3.questionid = 5');
//    $query->leftJoin('osdate_questions', 'q3', 'p3.questionid = q3.id');
//    $query->leftJoin('osdate_questionoptions', 'o3', 'p3.answer = o3.id');
//    $query->addExpression('LOWER(o4.answer)', 'answer_4');
//    $query->leftJoin('osdate_userpreference', 'p4', 'u.id = p4.userid AND p4.questionid = 6');
//    $query->leftJoin('osdate_questions', 'q4', 'p4.questionid = q4.id');
//    $query->leftJoin('osdate_questionoptions', 'o4', 'p4.answer = o4.id');
//    $query->addExpression('REPLACE(REPLACE(LOWER(o5.answer), \'will eat out vegetarian\', \'eat_out_vegetarian\'), 
//      \' \', \'_\')', 'answer_5');
//    $query->leftJoin('osdate_userpreference', 'p5', 'u.id = p5.userid AND p5.questionid = 7');
//    $query->leftJoin('osdate_questions', 'q5', 'p5.questionid = q5.id');
//    $query->leftJoin('osdate_questionoptions', 'o5', 'p5.answer = o5.id');
//    $query->addExpression('REPLACE(LOWER(o6.answer), \' \', \'_\')', 'answer_6');
//    $query->leftJoin('osdate_userpreference', 'p6', 'u.id = p6.userid AND p6.questionid = 8');
//    $query->leftJoin('osdate_questions', 'q6', 'p6.questionid = q6.id');
//    $query->leftJoin('osdate_questionoptions', 'o6', 'p6.answer = o6.id');
//    $query->addExpression('REPLACE(REPLACE(REPLACE(REPLACE(REPLACE(REPLACE(LOWER(o7.answer), \' \', \'_\'), 
//      \'white/grey\', \'grey_white\'), \'blackish_brown\', \'dark_brown\'), \'red\', \'red_auburn\'), \'auburn\', 
//      \'red_auburn\'), \'red_red_auburn\', \'red_auburn\')', 'answer_7');
//    $query->leftJoin('osdate_userpreference', 'p7', 'u.id = p7.userid AND p7.questionid = 9');
//    $query->leftJoin('osdate_questions', 'q7', 'p7.questionid = q7.id');
//    $query->leftJoin('osdate_questionoptions', 'o7', 'p7.answer = o7.id');
//    $query->addExpression('REPLACE(REPLACE(REPLACE(LOWER(o8.answer), \'socially\', \'occasionally\'), \'infrequently\', 
//      \'occasionally\'), \'frequently\', \'yes\')', 'answer_8');
//    $query->leftJoin('osdate_userpreference', 'p8', 'u.id = p8.userid AND p8.questionid = 18');
//    $query->leftJoin('osdate_questions', 'q8', 'p8.questionid = q8.id');
//    $query->leftJoin('osdate_questionoptions', 'o8', 'p8.answer = o8.id');
//    $query->addExpression('REPLACE(REPLACE(REPLACE(LOWER(o9.answer), \'just socially\', \'sometimes\'),
//      \'occasionally\',\'sometimes\'),\'frequently\',\'often\')', 'answer_9');
//    $query->leftJoin('osdate_userpreference', 'p9', 'u.id = p9.userid AND p9.questionid = 21');
//    $query->leftJoin('osdate_questions', 'q9', 'p9.questionid = q9.id');
//    $query->leftJoin('osdate_questionoptions', 'o9', 'p9.answer = o9.id');
//    $query->addExpression('p10.answer', 'answer_10');
//    $query->leftJoin('osdate_userpreference', 'p10', 'u.id = p10.userid AND p10.questionid = 25');
//    $query->leftJoin('osdate_questions', 'q10', 'p10.questionid = q10.id');
//    $query->addExpression('GROUP_CONCAT(REPLACE(REPLACE(REPLACE(REPLACE(REPLACE(LOWER(o11.answer),\' \',\'_\'),
//      \'_degree\',\'\'),\'secondary_education_(high_school)\',\'secondary\'),
//      \'diploma_/_certificate\',\'diploma_certificate\'),\'graduate_diploma/certificate\',\'graduate\'))', 'answer_11');
//    $query->leftJoin('osdate_userpreference', 'p11', 'u.id = p11.userid AND p11.questionid = 29');
//    $query->leftJoin('osdate_questions', 'q11', 'p11.questionid = q11.id');
//    $query->leftJoin('osdate_questionoptions', 'o11', 'p11.answer = o11.id');
//    $query->addExpression('GROUP_CONCAT(LOWER(o12.answer))', 'answer_12');
//    $query->leftJoin('osdate_userpreference', 'p12', 'u.id = p12.userid AND p12.questionid = 30');
//    $query->leftJoin('osdate_questions', 'q12', 'p12.questionid = q12.id');
//    $query->leftJoin('osdate_questionoptions', 'o12', 'p12.answer = o12.id');
//    $query->addExpression('LOWER(o13.answer)', 'answer_13');
//    $query->leftJoin('osdate_userpreference', 'p13', 'u.id = p13.userid AND p13.questionid = 37');
//    $query->leftJoin('osdate_questions', 'q13', 'p13.questionid = q13.id');
//    $query->leftJoin('osdate_questionoptions', 'o13', 'p13.answer = o13.id');
//    $query->addExpression('p14.answer', 'answer_14');
//    $query->leftJoin('osdate_userpreference', 'p14', 'u.id = p14.userid AND p14.questionid = 17');
//    $query->leftJoin('osdate_questions', 'q14', 'p14.questionid = q14.id');
    // images
    // moved to prepareRow (for same reason as questions)
//    $query->addExpression('CONCAT(u.id, \'-\', s.picno, \'.\', LOWER(s.picext))', 'profile_picture');
//    $query->addExpression('CONCAT(u.username, \'s pic\')', 'image_title');
//    $query->leftJoin('osdate_usersnaps', 's', 'u.id = s.userid AND s.picno = 1');

    $query->groupBy('u.id');

    return $query;
  }

}
