<?php


class WinkItController extends DrupalDefaultEntityController{
    
  
  public function save($wink) {
    drupal_write_record('wink', $wink);
    field_attach_insert('wink', $wink);
    module_invoke_all('entity_insert', 'wink', $wink);
    return $wink;
  }
}
