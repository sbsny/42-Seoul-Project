# Inception 구성 안내

이 폴더는 **Nginx + WordPress(PHP-FPM) + MariaDB** 3개 컨테이너를 docker-compose로 묶어 실행하는 설정입니다.

## 폴더 구조

```text
Inception/
├── Makefile
└── srcs/
    ├── docker-compose.yml
    └── requirements/
        ├── nginx/
        │   ├── Dockerfile
        │   └── conf/default.conf
        ├── wordpress/
        │   ├── Dockerfile
        │   └── conf/wp_script.sh
        └── mariadb/
            ├── Dockerfile
            └── conf/db_script.sh
```

## 빠른 실행

```bash
cd Inception
make
```

- `make`: 이미지 빌드 + 컨테이너 실행
- `make clean`: 컨테이너/볼륨 정리
- `make fclean`: 이미지와 데이터 디렉터리까지 전체 정리
- `make logs`: 전체 로그 팔로우
- `make ps`: 컨테이너 상태 확인

## 서비스 연결

- `nginx` : 외부 443 포트 수신, `wordpress:9000`으로 PHP 요청 전달
- `wordpress` : PHP-FPM 실행, 초기 WP 설치/사용자 생성 자동화
- `mariadb` : 초기 DB/유저 생성 SQL 적용 후 서버 실행

## 데이터 저장 위치

호스트 경로:
- `${HOME}/data/mariadb`
- `${HOME}/data/wordpress`

컨테이너 재생성 후에도 위 경로 덕분에 데이터가 유지됩니다.
