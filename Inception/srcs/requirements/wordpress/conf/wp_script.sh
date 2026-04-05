#!/bin/sh
set -eu

cd /var/www/wordpress

sed -i 's|listen = 127.0.0.1:9000|listen = 9000|g' /etc/php8/php-fpm.d/www.conf

if [ ! -f wp-config.php ]; then
	wp config create \
		--dbhost="${DB_HOST}" \
		--dbname="${DB_NAME}" \
		--dbuser="${DB_USER}" \
		--dbpass="${DB_PASS}" \
		--allow-root
fi

if ! wp core is-installed --allow-root >/dev/null 2>&1; then
	wp core install \
		--url="${WP_URL}" \
		--title="${WP_TITLE}" \
		--admin_user="${WP_ADMIN_NAME}" \
		--admin_password="${WP_ADMIN_PASS}" \
		--admin_email="${WP_ADMIN_EMAIL}" \
		--skip-email \
		--allow-root
fi

if ! wp user get "${WP_USER_NAME}" --field=ID --allow-root >/dev/null 2>&1; then
	wp user create "${WP_USER_NAME}" "${WP_USER_EMAIL}" \
		--user_pass="${WP_USER_PASS}" \
		--role="${WP_USER_ROLE}" \
		--allow-root
fi

exec php-fpm8 --nodaemonize
