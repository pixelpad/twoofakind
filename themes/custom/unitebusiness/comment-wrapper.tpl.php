<?php if ($content['comments'] or $content['comment_form']) { ?>
<div id="comments">
<div class="ribbon">
	<div class="wrapAround"></div>
	<div class="tab">
		<span class="blogDate"><?php print t('Comments'); ?></span>
		<span class="blogPostInfo"> </span>
	</div>
</div>
    <?php print render($content['comments']); ?>
	<div class="box">
	<h2><?php print t('Post new comment'); ?></h2>
	<?php print render($content['comment_form']); ?>
	</div>
</div>
<?php } ?>