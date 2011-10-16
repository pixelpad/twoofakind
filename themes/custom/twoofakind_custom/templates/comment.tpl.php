<div id="comment-<?php print $content['comment_body']['#object']->cid; ?>" class="img comment<?php print (drupal_ucfirst($new)) ? ' comment-new' : ''; print ' '. $status; ?> clear-block">
    <?php print $picture ?>

    <?php if (FALSE && $new): ?>
        <span class="new"><?php print drupal_ucfirst($new) ?></span>
    <?php endif; ?>

        <h4><?php print t('Submitted by !username on !datetime', array('!username' => theme('username', array('account' => $content['comment_body']['#object'])), '!datetime' => format_date($content['comment_body']['#object']->created))); ?> <a href="#comment-<?php print $content['comment_body']['#object']->cid; ?>">#</a></h4>

    <div class="content">
        <?php hide($content['links']); print render($content); ?>

        <?php if ($signature): ?>
            <div class="user-signature clear-block">
                <?php print $signature ?>
            </div>
        <?php endif; ?>
    </div>

    <?php if ($content['links']): ?>
        <div class="comment-links clear-block">
            <?php print render($content['links']) ?>
        </div>
    <?php endif; ?>
</div>
<?php //print '<pre>'. check_plain(print_r($content, 1)) .'</pre>'; ?>
<div class="clear"></div>