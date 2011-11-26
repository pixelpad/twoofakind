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
        $('a.block-expand', sidebar).each(function () {
          var expand_link = $(this);
          var expand_block = $('div#' + $(this).attr('href').substr(1), sidebar);
          /* check if block is expanded or not and apply link class accordingly */
          if (expand_block.css('display') != 'none') {
            expand_link.toggleClass('block-expanded');
          }
          /* bind click function to the link */
          expand_link.bind('click', function(e) {
            /* this could be improved, i.e. improve animation */
            expand_block.fadeToggle(500, 'swing', function() {
              expand_link.toggleClass('block-expanded');
            });

            return false;
          });
        });
      
        /* I DON'T LIKE THIS BEING HERE AS IT'S A TEMPLATE BASED SELECTOR (div#SearchOptions)
         * BUT I WANTED THE COOKIE STUFF IN HERE SO...
         * UNTIL A BETTER SOLUTION (OR TEMPLATE) PRESENTS ITSELF WE'LL STICK
         * WITH THIS DIRTY HACK
         **/
        
        /* matches form stuff */
        var matchesForm = $('div#matches_form', sidebar);

        /* Init search form i.e. open the search form based on certain criteria */
        if (search_open()) {
          /* the cookie is set, keep it open */
          matchesForm.fadeToggle();
        }
        else if (window.location.pathname.indexOf('user-search') > -1) {
          /* we're on the search page, keep it open */
          matchesForm.fadeToggle();
        }
        
        /* "show less options" link functionality */
        matchesForm.each(function() {
          var matches_form = $(this);
          $('div.less-options a', matches_form).bind({
            click: function () {
              matches_form.fadeToggle();
              search_state_toggle();
              return false;
            }
          });
        });
        
        /* make the more options link open and close the search box */
        $('div#SearchOptions a').bind({
          click: function () {
            matchesForm.fadeToggle();
            search_state_toggle();
            return false;
          }
        });
        
      });
      
      /* hide form elements that should not appear */
      $('body.not-logged-in div.region-sidebar-right:not(.js-processed-twice)', context).each(function () {
        var sidebar = $(this);
        $(this).addClass('js-processed-twice');
        $('div.views-exposed-widget', sidebar).each(function () {
          var widget = $('div.views-widget', $(this));
          if (widget.length > 0) {
            var widget_children = widget.children();
            if (widget_children.length == 0) {
              $(this).hide();
            }
          }
        });
      });
      
      /* make the terms and conditions link in registration pop up */
      $('label a[href*="terms"]').bind({
        click: function () {
          window.open($(this).attr('href'), 'termsConditions');
          return false;
        }
      });
      
      /* add links that will perform the clear search button action */
      $('a.clear-action').bind('click', function(e) {
        e.preventDefault();
        $('button#edit-reset').click();
        return false;
      });
      
    }
  }

  /*
   * Wrapper to set cookie
   */
  function drupal_set_cookie(key, val) {
    $.cookie(key, val, {expires: 1, path: '/', domain: document.location.host});
  }
  
  /*
   * Wrapper to get cookie
   */
  function drupal_get_cookie(key) {
    if ($.cookie) {
      return $.cookie(key);
    } else {
      return false;
    }
  }
  
  /*
   * Wrapper to clear cookie
   */
  function drupal_clear_cookie(key) {
    $.cookie(key, null, {expires: -1, path: '/', domain: document.location.host});
  }
  
  /*
   * Wrapper to toggle search sate
   */
  function search_state_toggle() {
    /* if cookie is set then it's currently open, close it by destroying cookie */
    if (search_open()) {
      drupal_clear_cookie('search_state');
    } else {
      /* otherwise it's closed, open it by setting the cookie */
      drupal_set_cookie('search_state', 1);
    }
  }
  
  /*
   * Wrapper to get search state
   */
  function search_open() {
    var search_state = drupal_get_cookie('search_state');
    if (search_state) {
      return true;
    } else {
      return false;
    }
  }

})(jQuery);