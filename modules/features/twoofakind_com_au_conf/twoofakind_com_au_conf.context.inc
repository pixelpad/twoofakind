<?php
/**
 * @file
 * twoofakind_com_au_conf.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function twoofakind_com_au_conf_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'anon_dashboard';
  $context->description = 'Dashboard context for anonymous user';
  $context->tag = 'anonymous';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-home_banner_left' => array(
          'module' => 'boxes',
          'delta' => 'home_banner_left',
          'region' => 'home_banner_1',
          'weight' => '-9',
        ),
        'boxes-home_banner_right' => array(
          'module' => 'boxes',
          'delta' => 'home_banner_right',
          'region' => 'home_banner_2',
          'weight' => '-10',
        ),
        'boxes-welcome' => array(
          'module' => 'boxes',
          'delta' => 'welcome',
          'region' => 'home_banner_3',
          'weight' => '-10',
        ),
        'views-featured_users-block' => array(
          'module' => 'views',
          'delta' => 'featured_users-block',
          'region' => 'featured_content',
          'weight' => '-10',
        ),
        'views-slideshows-block_anon' => array(
          'module' => 'views',
          'delta' => 'slideshows-block_anon',
          'region' => 'slide_shows',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Dashboard context for anonymous user');
  t('anonymous');
  $export['anon_dashboard'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'anon_global';
  $context->description = 'Global context for anonymous user';
  $context->tag = 'anonymous';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-173c7e3d196e3f3224233440599f6fba' => array(
          'module' => 'views',
          'delta' => '173c7e3d196e3f3224233440599f6fba',
          'region' => 'sidebar_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global context for anonymous user');
  t('anonymous');
  $export['anon_global'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'auth_dashboard';
  $context->description = 'Dashboard blocks for authenticated user';
  $context->tag = 'authenticated';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-member_dashboard_left' => array(
          'module' => 'boxes',
          'delta' => 'member_dashboard_left',
          'region' => 'home_banner_1',
          'weight' => '-9',
        ),
        'boxes-member_dashboard_right' => array(
          'module' => 'boxes',
          'delta' => 'member_dashboard_right',
          'region' => 'home_banner_2',
          'weight' => '-10',
        ),
        'boxes-member_dashboard_welcome' => array(
          'module' => 'boxes',
          'delta' => 'member_dashboard_welcome',
          'region' => 'home_banner_3',
          'weight' => '-10',
        ),
        'menu-menu-user-major-actions' => array(
          'module' => 'menu',
          'delta' => 'menu-user-major-actions',
          'region' => 'home_banner_3',
          'weight' => '-9',
        ),
        'views-questions-block' => array(
          'module' => 'views',
          'delta' => 'questions-block',
          'region' => 'featured_content',
          'weight' => '-24',
        ),
        'views-featured_users-block' => array(
          'module' => 'views',
          'delta' => 'featured_users-block',
          'region' => 'featured_content',
          'weight' => '-23',
        ),
        'views-matches-slideshow' => array(
          'module' => 'views',
          'delta' => 'matches-slideshow',
          'region' => 'slide_shows',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Dashboard blocks for authenticated user');
  t('authenticated');
  $export['auth_dashboard'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'auth_global';
  $context->description = 'Global blocks for authenticated user';
  $context->tag = 'authenticated';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-173c7e3d196e3f3224233440599f6fba' => array(
          'module' => 'views',
          'delta' => '173c7e3d196e3f3224233440599f6fba',
          'region' => 'sidebar_right',
          'weight' => '-10',
        ),
        'twoofakind_com_au-twoofakind_profile' => array(
          'module' => 'twoofakind_com_au',
          'delta' => 'twoofakind_profile',
          'region' => 'sidebar_right',
          'weight' => '-9',
        ),
        'twoofakind_com_au-twoofakind_privatemsg_messages' => array(
          'module' => 'twoofakind_com_au',
          'delta' => 'twoofakind_privatemsg_messages',
          'region' => 'sidebar_right',
          'weight' => '-8',
        ),
        'views-matches-block' => array(
          'module' => 'views',
          'delta' => 'matches-block',
          'region' => 'sidebar_right',
          'weight' => '-7',
        ),
        'views-matches_me-block' => array(
          'module' => 'views',
          'delta' => 'matches_me-block',
          'region' => 'sidebar_right',
          'weight' => '-6',
        ),
        'views-winks_received-block' => array(
          'module' => 'views',
          'delta' => 'winks_received-block',
          'region' => 'sidebar_right',
          'weight' => '-5',
        ),
        'views-winks-block' => array(
          'module' => 'views',
          'delta' => 'winks-block',
          'region' => 'sidebar_right',
          'weight' => '-4',
        ),
        'views-favourites-block' => array(
          'module' => 'views',
          'delta' => 'favourites-block',
          'region' => 'sidebar_right',
          'weight' => '-3',
        ),
        'views-recent_views-block' => array(
          'module' => 'views',
          'delta' => 'recent_views-block',
          'region' => 'sidebar_right',
          'weight' => '-2',
        ),
        'views-users_online-block' => array(
          'module' => 'views',
          'delta' => 'users_online-block',
          'region' => 'sidebar_right',
          'weight' => '-1',
        ),
        'views-users_new-block' => array(
          'module' => 'views',
          'delta' => 'users_new-block',
          'region' => 'sidebar_right',
          'weight' => '0',
        ),
        'twoofakind_com_au-twoofakind_profile_completion' => array(
          'module' => 'twoofakind_com_au',
          'delta' => 'twoofakind_profile_completion',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global blocks for authenticated user');
  t('authenticated');
  $export['auth_global'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'footer';
  $context->description = 'Global footer content';
  $context->tag = 'footer';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-footer_partners' => array(
          'module' => 'boxes',
          'delta' => 'footer_partners',
          'region' => 'footer_1',
          'weight' => '-10',
        ),
        'boxes-footer_social' => array(
          'module' => 'boxes',
          'delta' => 'footer_social',
          'region' => 'footer_2',
          'weight' => '-10',
        ),
        'boxes-footer_contact' => array(
          'module' => 'boxes',
          'delta' => 'footer_contact',
          'region' => 'footer_3',
          'weight' => '-10',
        ),
        'boxes-footer_copyright' => array(
          'module' => 'boxes',
          'delta' => 'footer_copyright',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'menu-menu-footer-other' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-other',
          'region' => 'footer',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global footer content');
  t('footer');
  $export['footer'] = $context;

  return $export;
}
