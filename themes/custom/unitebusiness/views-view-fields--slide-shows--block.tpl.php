<?php 
$slide = theme_get_setting('slide_shows');

switch ($slide) {
	case 0: 
		if ($fields['entity_id_1']->content) { 
			print $fields['entity_id_1']->content;
		}
		break;
	case 1:
		print '<li>'.$fields['entity_id_2']->content.'<div class="panel-overlay"><a href="'.$fields['path']->content.'" class="lno"></a><h2>'.$fields['title']->content.'</h2><div>'.$fields['entity_id']->content.'</div></div></li>';
		break;
	default:
		if ($fields['entity_id_1']->content) { 
			print $fields['entity_id_1']->content;
		}
}
?>