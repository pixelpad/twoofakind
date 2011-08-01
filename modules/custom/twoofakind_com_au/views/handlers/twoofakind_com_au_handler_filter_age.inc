<?php

/**
 * Converts a date to an age value and then builds upon numeric
 * filter
 */
class twoofakind_com_au_handler_filter_age extends views_handler_filter_numeric {
  
  function query() {
    
    $this->ensure_my_table();
    
    $field = 'age';
    
    $this->field_alias = $this->query->add_field(NULL,
      "DATE_FORMAT(NOW(), '%Y') - DATE_FORMAT(FROM_UNIXTIME($this->table_alias.$this->real_field), '%Y') - (DATE_FORMAT(NOW(), '00-%m-%d') < DATE_FORMAT(FROM_UNIXTIME($this->table_alias.$this->real_field), '00-%m-%d'))",
      $field);

    $info = $this->operators();
    if (!empty($info[$this->operator]['method'])) {
      $this->{$info[$this->operator]['method']}($field);
    }
  }
  
  function op_between($field) {
    if ($this->operator == 'between') {
      $this->query->add_having($this->options['group'], $field, array($this->value['min'], $this->value['max']), 'BETWEEN');
    }
    else {
      $this->query->add_having($this->options['group'], db_or()->condition($field, $this->value['min'], '<=')->condition($field, $this->value['max'], '>='));
    }
  }

  function op_simple($field) {
    $this->query->add_having($this->options['group'], $field, $this->value['value'], $this->operator);
  }

  function op_empty($field) {
    if ($this->operator == 'empty') {
      $operator = "IS NULL";
    }
    else {
      $operator = "IS NOT NULL";
    }

    $this->query->add_having($this->options['group'], $field, NULL, $operator);
  }
  
}