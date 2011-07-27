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
        var inputSearch = $('input#edit-name', context);
        
        /* send the value of this input field to the relevant field in
         * the matches exposed filters form
         */
        $('input#SearchInput', $(this)).each(function () {
          $(this).val(inputSearch.val());
        }).bind({
          blur: function() {
            inputSearch.val($(this).val());
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
      
      /* grab the mactehs exposed filters form */
      var matchesForm = $('div.region-sidebar-right div#matches_form:not(.js-processed)', context);
      
      /* make the more options link open and close the search box */
      $('div#SearchOptions a').bind({
        click: function () {
          matchesForm.toggle();
        }
      });
    }
  }

})(jQuery);