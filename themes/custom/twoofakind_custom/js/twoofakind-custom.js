(function ($) {

  /* Interactive blocks
   * NOTE : This is not working currently
  -------------------------------------------------------------- */
  Drupal.behaviors.interactiveBlocks = function(context) {
    $('h4.interactive:not(.interactive-processed)', context).each(function () {
      $(this).addClass('interactive-processed');
      $(this).bind('click', function(e) {
        var open_id = $(this).attr('id').match(/open\-([0-9][a-z][A-Z]\-)/g);
        console.log(open_id);
      });
    });
  };

  Drupal.behaviors.subaruFormOverlabels = {
    attach: function (context, settings) {
      if (jQuery().overlabel) {
        $("form#views-exposed-form-matches-page-matches label").overlabel();
//        $("form#views-exposed-form-matches-page-matches input[type=text]").hide();
//        $("input#edit-city").overlabel();
      }
    }
  }

})(jQuery);