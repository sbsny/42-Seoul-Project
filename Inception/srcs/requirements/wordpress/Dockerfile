FROM alpine:3.16

WORKDIR /var/www/wordpress

RUN apk update \
	&& apk upgrade \
	&& apk add --no-cache \
		php8-fpm \
		php8-mysqli \
		php8-phar \
		php8-iconv \
		php8-tokenizer \
		mariadb-client \
		wget \
	&& wget -O /tmp/wp-cli.phar https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
	&& chmod +x /tmp/wp-cli.phar \
	&& mv /tmp/wp-cli.phar /usr/local/bin/wp \
	&& wp core download --version=6.2 --allow-root

COPY ./conf/wp_script.sh /usr/local/bin/wp_script.sh
RUN chmod +x /usr/local/bin/wp_script.sh

CMD ["/usr/local/bin/wp_script.sh"]
