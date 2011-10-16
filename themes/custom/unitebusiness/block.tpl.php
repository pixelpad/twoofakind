<?php if (($block->module == 'system' and $block->delta == 'navigation') or ($block->module == 'user' and $block->delta == 1) or ($block->module == 'menu')){ ?>
<?php if ($block->subject): ?><h4 class="title"><?php print $block->subject ?></h4><?php endif;?>
<div class="sideNavWrapper"><div class="sideNavBox-1">&nbsp;<div class="sideNavBox-2">
<?php print $content ?>
&nbsp;</div></div></div>
<?php } elseif (($block->module == 'montharchive' and $block->delta == 'montharchive_all') or ($block->module == 'taxonomy_blocks') or ($block->module == 'blog')){ ?>
<?php if ($block->subject): ?><h4 class="title"><?php print $block->subject ?></h4><?php endif;?>
<div class="sideNavWrapper"><div class="sideNavBox-1">&nbsp;<div class="sideNavBox-2">
<?php print str_replace('<ul>','<ul class="menu">',$content) ?>
&nbsp;</div></div></div>
<?php } elseif ($block->module == 'comment'){ ?>
<?php if ($block->subject): ?><h4 class="title"><?php print $block->subject ?></h4><?php endif;?>
<div class="sideNavWrapper"><div class="sideNavBox-1">&nbsp;<div class="sideNavBox-2">
<?php print preg_replace("'&nbsp;<span>.*?</span></li>'si", '</li>', str_replace(array('<ul>', 'class="active"'),array('<ul class="menu">', ''),$content)) ?>
&nbsp;</div></div></div>
<?php } elseif ($block->region == 'footer_1' or $block->region == 'footer_2' or $block->region == 'footer_3'){ ?>
<?php if ($block->subject): ?><h3><?php print $block->subject ?></h3><?php endif;?>
<?php print $content ?>
<?php } elseif ($block->region == 'featured_content'){ ?>
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
<?php } elseif ($block->region == 'portfolio_top_txt' or $block->region == 'slide_shows' or $block->region == 'home_banner_1' or $block->region == 'home_banner_2' or $block->region == 'home_banner_3' or $block->module == 'views' or $block->region == 'footer'){ ?>
<?php print $content ?>
<?php } else { ?>
<?php if ($block->subject): ?><h4 class="title"><?php print $block->subject ?></h4><?php endif;?>
<div>
<?php print $content ?>
</div>
<?php } ?>
<?php //print serialize($block) ?>
