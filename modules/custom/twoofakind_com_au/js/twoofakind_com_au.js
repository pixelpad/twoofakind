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
  Drupal.behaviors.sideBarProcesing = {
    attach: function (context, settings) {
      $('div.region-sidebar-right:not(.js-processed)', context).each(function () {
        $(this).addClass('js-processed');
        var sidebar = $(this);
        
        /* block expansion */
        $('a.block-expand:not(.js-processed)', sidebar).each(function () {
          $(this).addClass('js-processed');
          $(this).bind('click', function(e) {
            $('div.' + $(this).attr('href').substr(1), sidebar).fadeToggle();

            return false;
          });
        });
        
        /* hide labels that should not appear */
        $('label:not(.js-processed)', sidebar).each(function () {
          $(this).addClass('js-processed');
          var label_for = $(this).attr('for');
          var label_input = $('#'+label_for, sidebar);
          if (label_input.length == 0) {
            $(this).hide();
          }
        });
      });
    }
  }

})(jQuery);