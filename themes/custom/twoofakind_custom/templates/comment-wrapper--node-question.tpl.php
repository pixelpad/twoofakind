<?php if ($content['comments'] || $content['comment_form']) :
  $front = drupal_is_front_page();
  ?>

<div id="comments">
<?php if (!$front) : ?>
<div class="ribbon">
	<div class="wrapAround"></div>
	<div class="tab">
		<span class="blogDate"><?php print t('Responses'); ?></span>
		<span class="blogPostInfo"> </span>
	</div>
</div>
<?php endif; ?>
    <?php print render($content['comments']); ?>
	<div class="box">
  <?php if (!$front) : ?>
	<h2><?php print t('Post your response'); ?></h2>
  <?php endif; ?>
	<?php print render($content['comment_form']); ?>
	</div>
</div>

<?php endif; ?>