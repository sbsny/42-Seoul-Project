FROM alpine:3.16

RUN apk update \
	&& apk upgrade \
	&& apk add --no-cache mariadb mariadb-client \
	&& mkdir -p /var/run/mysqld /var/lib/mysql \
	&& chown -R mysql:mysql /var/run/mysqld /var/lib/mysql \
	&& mysql_install_db --user=mysql --datadir=/var/lib/mysql

COPY ./conf/db_script.sh /usr/local/bin/db_script.sh
RUN chmod +x /usr/local/bin/db_script.sh

CMD ["/usr/local/bin/db_script.sh"]
