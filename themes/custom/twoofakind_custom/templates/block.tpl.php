<?php
  if (
      ($block->module == 'system' && $block->delta == 'navigation')
      || ($block->module == 'user' && $block->delta == 1)
//      || ($block->module == 'menu')
     ) { ?>

<?php if ($block->subject): ?><h4 class="title"><?php print $block->subject ?></h4><?php endif;?>
<div class="sideNavWrapper"><div class="sideNavBox-1">&nbsp;<div class="sideNavBox-2">
<?php print $content ?>
&nbsp;</div></div></div>

<?php }
  elseif (
      ($block->module == 'montharchive' && $block->delta == 'montharchive_all')
      || ($block->module == 'taxonomy_blocks')
      || ($block->module == 'blog')
     ) { ?>

<?php if ($block->subject): ?><h4 class="title"><?php print $block->subject ?></h4><?php endif;?>
<div class="sideNavWrapper"><div class="sideNavBox-1">&nbsp;<div class="sideNavBox-2">
<?php print str_replace('<ul>','<ul class="menu">',$content) ?>
&nbsp;</div></div></div>

<?php }
  elseif (
      $block->module == 'comment'
     ) { ?>

<?php if ($block->subject): ?><h4 class="title"><?php print $block->subject ?></h4><?php endif;?>
<div class="sideNavWrapper"><div class="sideNavBox-1">&nbsp;<div class="sideNavBox-2">
<?php print preg_replace("'&nbsp;<span>.*?</span></li>'si", '</li>', str_replace(array('<ul>', 'class="active"'),array('<ul class="menu">', ''),$content)) ?>
&nbsp;</div></div></div>

<?php }
  elseif (
      $block->region == 'footer_1'
      || $block->region == 'footer_2'
      || $block->region == 'footer_3'
     ) { ?>

<?php if ($block->subject): ?><h3><?php print $block->subject ?></h3><?php endif;?>
<?php print $content ?>

<?php }
  elseif (
      $block->region == 'featured_content'
     ) { ?>

<div class="ribbon">
	<div class="wrapAround"></div>
	<div class="tab">
		<span><?php print $block->subject ?></span>
	</div>
</div>	
<div class="featuredContent">
<?php print $content ?>						
<div class="clear"></div>	
</div>

<?php }
  elseif (
      $block->region == 'portfolio_top_txt'
      || $block->region == 'slide_shows'
      || $block->region == 'home_banner_1'
      || $block->region == 'home_banner_2'
      || $block->region == 'home_banner_3'
      || $block->region == 'footer'
     ) { ?>

<?php print $content ?>

<?php }
  else { ?>

<div class="block">
<?php if ($block->subject): ?><h4 class="title"><?php print $block->subject ?></h4><?php endif;?>
  <div class="block-content">
  <?php print $content ?>
  </div>
</div>

<?php } ?>
<?php //print serialize($block) ?>
