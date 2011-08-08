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
  Drupal.behaviors.sideBarProcessing = {
    attach: function (context, settings) {
      $('div.region-sidebar-right:not(.js-processed)', context).each(function () {
        $(this).addClass('js-processed');
        var sidebar = $(this);
        
        /* block expansion */
        $('a.block-expand:not(.js-processed)', sidebar).each(function () {
          $(this).addClass('js-processed');
          var expand_link = $(this);
          $(this).bind('click', function(e) {
            /* this could be improved, i.e. improve animation */
            $('div#' + $(this).attr('href').substr(1), sidebar).fadeToggle(500, 'swing', function() {
              expand_link.toggleClass('block-expanded');
            });

            return false;
          });
        });
      });
      
      /* hide labels that should not appear */
      $('body.not-logged-in div.region-sidebar-right:not(.js-processed-twice)', context).each(function () {
        var sidebar = $(this);
        $(this).addClass('js-processed-twice');
        $('label:not(.js-processed)', sidebar).each(function () {
          $(this).addClass('js-processed');
          var label_for = $(this).attr('for');
          var label_input = $('#'+label_for, sidebar);
          /* dodgy hack to deal with date of birth fields */
          if (label_input.length == 0 && label_for.indexOf('birth') == -1) {
            $(this).hide();
          }
        });
      });
    }
  }

})(jQuery);