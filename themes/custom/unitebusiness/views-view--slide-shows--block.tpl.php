<?php 
$slide = theme_get_setting('slide_shows');

switch ($slide) {
	case 0: 
		print '<div id="Slideshow"><div id="SlideTop"></div><div id="SlideRepeat"></div><div id="SlideBottom"></div><div id="Slides">'.$rows.'</div><a href="#" class="slidePrev"></a><a href="#" class="slideNext"></a><div id="slidePager"></div></div>';
		break;
	case 1:
		print '<div id="SlideShow-GalleryView"><ul id="GalleryView">'.$rows.'</ul></div>';
		break;
	default:
		print '<div id="Slideshow"><div id="SlideTop"></div><div id="SlideRepeat"></div><div id="SlideBottom"></div><div id="Slides">'.$rows.'</div><a href="#" class="slidePrev"></a><a href="#" class="slideNext"></a><div id="slidePager"></div></div>';
}
?>