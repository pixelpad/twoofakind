#!/bin/bash
# Use proxy (e.g. squid) to speed up regular builds
rm -rf modules/contrib
rm -rf themes/contrib
rm -rf libraries
http_proxy="http://localhost:3128/" drush make --working-copy --no-core --contrib-destination=. twoofakind.make .
# Usually run update.php and clear the cache here
