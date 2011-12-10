<?php

/**
 * Converts a date to an age value and then builds upon numeric
 * filter
 */
class twoofakind_com_au_handler_filter_date_age extends twoofakind_com_au_handler_filter_datestamp_age {
  
  function __queryAddAgeField($fieldName = 'age') {
    
    $this->field_alias = $this->query->add_field(NULL,
      "DATEDIFF(YEAR, STR_TO_DATE($this->table_alias.$this->real_field,'%Y-%m-%d'), now())",
      $fieldName);
    
  }
  
}