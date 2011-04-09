<div class="blogPostSummary">
	<?php if (!$page): ?><h1><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h1><?php endif; ?>
	<?php if (isset($content['body']['#object']->field_image['und'][0]) and $page) { ?>
	<div class="blogPostImage">
	<a href="<?php print file_create_url($content['body']['#object']->field_image['und'][0]['uri']); ?>" title="<?php print $content['body']['#object']->field_image['und'][0]['title'] ?>" class="img zoom" rel="blogpostimage"><?php print theme('image_style', array('style_name' => 'portfolio_page_body', 'path' => $content['body']['#object']->field_image['und'][0]['uri'], 'alt' => $content['body']['#object']->field_image['und'][0]['alt'], 'title' => $content['body']['#object']->field_image['und'][0]['title'], 'attributes' => array('class' => 'img'),'getsize' => false) );?></a>
	</div>
	<?php } ?>
	<div class="m5"><?php hide($content['comments']); print str_replace('rel="tag"','',render($content)) ?></div>
	<?php print render($content['comments']) ?>
</div>