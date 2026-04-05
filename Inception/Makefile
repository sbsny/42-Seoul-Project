COMPOSE_FILE := ./srcs/docker-compose.yml
DATA_DIR := $(HOME)/data
DB_DATA_DIR := $(DATA_DIR)/mariadb
WP_DATA_DIR := $(DATA_DIR)/wordpress

.PHONY: all up clean fclean re logs ps

all: up

up:
	@mkdir -p "$(DB_DATA_DIR)" "$(WP_DATA_DIR)"
	docker-compose -f "$(COMPOSE_FILE)" up --build

clean:
	docker-compose -f "$(COMPOSE_FILE)" down --volumes

fclean: clean
	docker image prune -af
	rm -rf "$(DATA_DIR)"

re: fclean up

logs:
	docker-compose -f "$(COMPOSE_FILE)" logs -f

ps:
	docker-compose -f "$(COMPOSE_FILE)" ps
