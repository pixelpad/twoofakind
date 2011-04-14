Description
-----------
This module defines two blocks:
- a list of users who winked at the current user
- a list of users who the current user winked at.

It also adds a "send a wink" button to each profile which is being displayed.


Requirements
------------
Drupal 7.x
entity


Installation
------------
1. Copy the entire wink directory the Drupal sites/all/modules directory.

2. Login as an administrator. Enable the two blocks under "Structure" -> "Blocks"
    (to find them, search for 'wink')

3. Go to an user profile and click "send a wink"

4. You should a new record popping up in the "Who I've winked at" block.


