<?php
/**
 * @file
 * theme_unite_config.features.inc
 */

/**
 * Implementation of hook_image_default_styles().
 */
function theme_unite_config_image_default_styles() {
  $styles = array();

  // Exported image style: blog_teaser
  $styles['blog_teaser'] = array(
    'name' => 'blog_teaser',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '556',
          'height' => '133',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: featured_content
  $styles['featured_content'] = array(
    'name' => 'featured_content',
    'effects' => array(
      3 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '148',
          'height' => '78',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: portfolio_block
  $styles['portfolio_block'] = array(
    'name' => 'portfolio_block',
    'effects' => array(
      4 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '150',
          'height' => '100',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: portfolio_page_body
  $styles['portfolio_page_body'] = array(
    'name' => 'portfolio_page_body',
    'effects' => array(
      5 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '556',
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: portfolio_page_teaser
  $styles['portfolio_page_teaser'] = array(
    'name' => 'portfolio_page_teaser',
    'effects' => array(
      6 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '261',
          'height' => '174',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: slide_shows_1
  $styles['slide_shows_1'] = array(
    'name' => 'slide_shows_1',
    'effects' => array(
      7 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '948',
          'height' => '341',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: slide_shows_2
  $styles['slide_shows_2'] = array(
    'name' => 'slide_shows_2',
    'effects' => array(
      8 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '938',
          'height' => '340',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}
