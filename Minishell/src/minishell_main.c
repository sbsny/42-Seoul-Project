/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:24:35 by seonyun           #+#    #+#             */
/*   Updated: 2022/12/23 01:24:35 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	g_exit_code;

int	main(int argc, char **argv, char **builtin_env)
{
	t_data	shell_state;

	if (argc != 1)
	{
		printf("minishell: %s: No such path_name or directory\n", argv[1]);
		return (EXIT_FAILURE);
	}
	(void) argv;
	bootstrap_shell(&shell_state, builtin_env);
	while (shell_state.exit_minishell == false)
	{
		configure_signal_mode(SIGNAL_MODE_MAIN);
		capture_prompt_history(&shell_state);
		tokenize_input(&shell_state);
		if (shell_state.lex_error == false)
		{
			analyze_tokens(&shell_state);
			if (shell_state.parse_error == false)
				run_token_pipeline(&shell_state);
		}
		clear_token_stream(&shell_state);
	}
	shutdown_shell(&shell_state);
	return (g_exit_code);
}
