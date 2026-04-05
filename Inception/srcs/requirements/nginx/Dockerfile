FROM alpine:3.16

RUN apk update \
	&& apk upgrade \
	&& apk add --no-cache nginx openssl \
	&& mkdir -p /etc/ssl/private /etc/ssl/certs \
	&& openssl req \
		-newkey rsa:2048 \
		-nodes \
		-keyout /etc/ssl/private/seonyun.42.fr.key \
		-x509 \
		-days 365 \
		-subj "/CN=seonyun.42.fr" \
		-out /etc/ssl/certs/seonyun.42.fr.crt

COPY ./conf/default.conf /etc/nginx/http.d/default.conf

CMD ["nginx", "-g", "daemon off;"]
