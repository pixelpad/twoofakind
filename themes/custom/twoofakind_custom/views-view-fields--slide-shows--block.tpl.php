<?php 
$slide = theme_get_setting('slide_shows');
switch ($slide) {
	case 0:
		if ($fields['field_image']->content) { 
			print $fields['field_image']->content;
		}
		break;
	case 1:
		print '<li>'.$fields['field_image_1']->content.'<div class="panel-overlay"><a href="'.$fields['path']->content.'" class="lno"></a><h2>'.$fields['title']->content.'</h2><div>'.$fields['body']->content.'</div></div></li>';
		break;
	default:
		if ($fields['field_image']->content) { 
			print $fields['field_image']->content;
		}
}
?>