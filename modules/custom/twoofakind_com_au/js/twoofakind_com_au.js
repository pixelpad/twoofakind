(function ($) {

  /* Ajax response message fade
  -------------------------------------------------------------- */
  Drupal.behaviors.ajaxResponseMessageFade = {
    attach: function (context, settings) {
      $('span.ajax-message:not(.js-processed)', context).each(function () {
        $(this).addClass('js-processed');
        $(this).delay(800).fadeOut(800);
      });
    }
  }
  
  /* Show and hide the blocks
  -------------------------------------------------------------- */
  Drupal.behaviors.expandBlocks = {
    attach: function (context, settings) {
      $('div.region-sidebar-right:not(.js-processed)', context).each(function () {
        $(this).addClass('js-processed');
        var sidebar = $(this);
        $('a.block-expand:not(.js-processed)', sidebar).each(function () {
          $(this).addClass('js-processed');
          $(this).bind('click', function(e) {
            $('div.' + $(this).attr('href').substr(1), sidebar).fadeToggle();

            return false;
          });
        });
      });
    }
  }

})(jQuery);