<div class="portfolio-item">
<?php if ($fields['entity_id_1']->content) { print $fields['entity_id_1']->content; } ?>
<div class="portfolio-description">
<h4><?php print $fields['title']->content; ?></h4>
<div class="m6"><?php print $fields['entity_id']->content; ?></div>
<?php print $fields['view_node']->content; ?>
</div>
<?php //print '<pre>'. check_plain(print_r($fields, 1)) .'</pre>'; ?>
<?php //foreach ($fields as $key => $value) { print '$key = '.$key.' | '; print '$value = '.$value->content.'<br />'; } ?>
</div>