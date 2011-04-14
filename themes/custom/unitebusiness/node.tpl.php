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

?>
<?php if ($display_submitted) { ?>
<div class="ribbon">
	<div class="wrapAround"></div>
	<div class="tab">
		<span class="blogDate"><?php print format_date($content['body']['#object']->created, 'custom', 'j M. Y') ?></span>
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
	<div class="m5"><?php hide($content['comments']); print str_replace('rel="tag"','',render($content)); ?></div>
	<?php print render($content['comments']) ?>
</div>
<?php //print '<pre>'. check_plain(print_r($name, 1)) .'</pre>'; ?>