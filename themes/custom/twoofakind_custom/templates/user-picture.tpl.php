<?php

/**
 * @file
 * Default theme implementation to present a picture configured for the
 * user's account.
 *
 * Available variables:
 * - $user_picture: Image set by the user or the site's default. Will be linked
 *   depending on the viewer's permission to view the user's profile page.
 * - $account: Array of account information. Potentially unsafe. Be sure to
 *   check_plain() before use.
 *
 * @see template_preprocess_user_picture()
 */
//dsm($account);
//dsm($user_picture);
?>
<?php if (isset($account->content['user_picture_alternate'])): ?>
  <div class="user-picture fuck">what
    <?php print $account->content['user_picture_alternate']; ?>
  </div>
<?php elseif (isset($user_picture)): ?>
  <div class="user-picture">
    <?php print $user_picture; ?>
  </div>
<?php endif; ?>
