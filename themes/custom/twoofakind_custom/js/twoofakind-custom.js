(function ($) {

  /* Matches view exposed filter form
   * NOTE : If you switch themes this won't work
   * This is due to the poor theme that we have chosen :(
  -------------------------------------------------------------- */
  Drupal.behaviors.matchesExposedFilters = {
    attach: function (context, settings) {
      
      /* find current search block and modify it's behaviour */
      $('div#Search:not(.js-processed)', context).each(function () {
        $(this).addClass('js-processed');
        
        /* grab the input field the search will be replacing */
        var input_username = $('input#edit-name-search', context);
        var dummy_text = 'Enter a username';
        
        /* send the value of this input field to the relevant field in
         * the matches exposed filters form
         */
        $('input#SearchInput', $(this)).each(function () {
          var input_username_val = input_username.val();
          if (typeof input_username_val != 'undefined' && input_username_val.length > 0) {
            $(this).val(input_username_val);
          }
          else {
            $(this).val(dummy_text);
          }
        }).bind({
          blur: function() {
            var search_input_val = $(this).val();
            if (search_input_val.length > 0 && search_input_val != dummy_text) {
              input_username.val(search_input_val);
            } else {
              $(this).val(dummy_text);
            }
          },
          focus: function() {
            var search_input_val = $(this).val();
            if (search_input_val == dummy_text) {
              $(this).val('');
            }
          }
        });
        /* make sure the search button doesn't submit this form but
         * the matches exposed filters form
         */
        $('#SearchSubmit', $(this)).bind({
          click: function() {
            $('form#views-exposed-form-user-search-page-user-search').submit();
            return false;
          }
        });
      });
      
      /* make the home page login button reveal the login slider */
      $('div.region-home-banner-1 a[href="/user/login"]').bind({
        click: function() {
          $('#ContentPanel').slideToggle(800,'easeOutQuart');	// show/hide the content area
          $.scrollTo('#ContentPanel');
          return false;
        }
      });
      
      /* adding a form navigate confirm */
      var form_user_profile = $('form#user-profile-form');
      if (form_user_profile.size() > 0) {
        form_user_profile.FormNavigate('Have you saved your changes?');
      }
    }
  }

})(jQuery);