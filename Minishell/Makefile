NAME := minishell

CC := cc
RM := rm -f
CFLAGS := -Wall -Wextra -Werror -g

READLINE_INC := -I /Users/$(USER)/.brew/opt/readline/include
READLINE_LIB := -lreadline -L /Users/$(USER)/.brew/opt/readline/lib
CPPFLAGS := $(READLINE_INC)
LDFLAGS := $(READLINE_LIB)

SRC := \
	src/tools/ft_join_char.c \
	src/builtins/unset_builtin.c \
	src/tools/ft_atoi.c \
	src/parser/syntax_validator.c \
	src/initializer/fd_state_setup.c \
	src/parser/redirection/redirection_processor.c \
	src/builtins/export_identifier_utils.c \
	src/lexer/token_scanner.c \
	src/tools/ft_lstsize.c \
	src/tools/ft_strjoin.c \
	src/builtins/export_builtin.c \
	src/tools/ft_isnumber.c \
	src/tools/ft_isalpha.c \
	src/tools/ft_strlen.c \
	src/tools/ft_new_builtin_envp.c \
	src/tools/ft_bzero.c \
	src/tools/ft_lstclear.c \
	src/parser/redirection/redirection_fd_open.c \
	src/tools/ft_get_builtin_envp.c \
	src/pipex/stdio_state_restore.c \
	src/tools/ft_strcmp.c \
	src/prompt_reader.c \
	src/tools/ft_isdigit.c \
	src/tools/ft_join_tilde.c \
	src/signals/signal_handlers.c \
	src/tools/ft_strdup.c \
	src/lexer/double_quote_handler.c \
	src/tools/ft_split.c \
	src/lexer/expander/expansion_processor.c \
	src/initializer/shell_context_setup.c \
	src/lexer/input_lexer.c \
	src/tools/ft_haschar.c \
	src/lexer/redirection_token_handler.c \
	src/executor/path_command_builder.c \
	src/lexer/word_handler.c \
	src/tools/ft_print_list.c \
	src/initializer/builtin_registry_setup.c \
	src/tools/ft_strtrim.c \
	src/tools/ft_cleansplit.c \
	src/builtins/env_builtin.c \
	src/tools/ft_append_token_back.c \
	src/lexer/single_quote_handler.c \
	src/parser/token_collapse.c \
	src/builtins/cd_builtin.c \
	src/minishell_main.c \
	src/tools/ft_del_first_token.c \
	src/pipex/pipeline_stage_spawner.c \
	src/tools/count_pipeline_commands.c \
	src/tools/identify_builtin_command.c \
	src/lexer/expander/expansion_special_cases.c \
	src/executor/pipeline_runner.c \
	src/tools/ft_new_token.c \
	src/tools/ft_calloc.c \
	src/tools/ft_add_builtin_envp_back.c \
	src/builtins/cd_env_utils.c \
	src/tools/ft_check_plus.c \
	src/tools/ft_splitlen.c \
	src/pipex/pipeline_command_executor.c \
	src/parser/redirection/heredoc_processor.c \
	src/tools/count_command_word_tokens.c \
	src/tools/ft_isprint.c \
	src/initializer/builtin_env_setup.c \
	src/shell_cleanup.c \
	src/initializer/shell_bootstrap.c \
	src/tools/ft_itoa.c \
	src/builtins/cd_path_utils.c \
	src/builtins/echo_builtin.c \
	src/builtins/pwd_builtin.c \
	src/parser/syntax_analyzer.c \
	src/parser/redirection/redirection_fd_close.c \
	src/executor/command_lookup.c \
	src/error_printer.c \
	src/builtins/exit_builtin.c
OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
