<?php

if (module_exists('taxonomy')) {
//	$taxonomy = taxonomy_link('taxonomy terms', $node);

	$out = array();
	if (!empty($content['body']['#object']->field_tags))
	if (is_array($content['body']['#object']->field_tags['und']))
	foreach ($content['body']['#object']->field_tags['und'] as $k => $d) {
		$t = taxonomy_term_load($d['tid']);
		$out[] = l($t->name, 'taxonomy/term/'.$t->tid);
	}
	$output = '';
	if (count($out) > 0) {
		$output = ' '.t("in").' '.implode(', ', $out);
	}
}

// grab the event date
// use it for the black strip
// and then remove it so it doesn't frig with anything else
$event_date = $content['field_date'];
unset($content['field_date']);
if (isset($event_date['#items']) && count($event_date['#items'])) {
  $event_date_data = current($event_date['#items']);
  if (isset($event_date_data['value'])) {
    $event_date_time = strtotime($event_date_data['value']);
    $event_date_display = format_date($event_date_time, 'custom', 'j M. Y');
    if ($event_date_time > time()) {
      $event_date_display = 'Coming up on ' . $event_date_display;
    }
    else {
      $event_date_display = 'Went down on ' . $event_date_display;
    }
  }
}

// give links a higher weight
$content['links']['#weight'] = 10;

?>
<?php if (!drupal_is_front_page() && $display_submitted) { ?>
<div class="ribbon">
	<div class="wrapAround"></div>
	<div class="tab">
		<span class="blogDate"><?php 
    if (isset($event_date_display)) {
      print $event_date_display;
    }
    ?></span>
		<span class="blogPostInfo"><?php print t("Posted by") ?> <?php print theme('username', array('account' => $node)).$output ?> </span>
	</div>
</div>
<?php } ?>
<div class="blogPostSummary">
	<?php if (!$page): ?><h1><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h1><?php endif; ?>
	<?php if (isset($content['body']['#object']->field_image['und'][0])) { ?>
	<div class="blogPostImage">
	<a href="<?php print file_create_url($content['body']['#object']->field_image['und'][0]['uri']); ?>" title="<?php print $content['body']['#object']->field_image['und'][0]['title'] ?>" class="img zoom" rel="blogpostimage"><?php print theme('image_style', array('style_name' => 'blog_teaser', 'path' => $content['body']['#object']->field_image['und'][0]['uri'], 'alt' => $content['body']['#object']->field_image['und'][0]['alt'], 'title' => $content['body']['#object']->field_image['und'][0]['title'], 'attributes' => array('class' => 'img'),'getsize' => false) );?></a>
	</div>
	<?php } ?>
  <?php
    hide($content['comments']);
    // this is a small hacky fix to remove the 1 that is appearing 
    // at the start of the $content['comments'] output
    if (!is_array($content['comments']) && substr($content['comments'], 0, 1) == '1') {
      $content['comments'] = substr($content['comments'], 1);
    }
  ?>
	<div class="m5"><?php print str_replace('rel="tag"','',render($content)); ?></div>
	<?php print render($content['comments']) ?>
</div>