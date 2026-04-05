#include "../../incl/minishell.h"

static void	handle_sigint_main(int sig_num)
{
	struct termios	att;

	(void)sig_num;
	tcgetattr(STDIN_FILENO, &att);
	att.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, 0, &att);
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	rl_on_new_line();
	rl_replace_line("", 0);
}

static void	handle_sigint_child(int sig)
{
	(void)sig;
	signal(SIGINT, SIG_DFL);
	ioctl(STDOUT_FILENO, TIOCSTI, "\n");
	rl_replace_line("", 0);
}

static int	track_heredoc_signal(int sig_num)
{
	static int	save;

	if (sig_num == 10)
		return (save);
	if (sig_num == 2)
	{
		save = 11;
		return (1);
	}
	save = 0;
	return (-1);
}

void	configure_signal_mode(int flag)
{
	if (flag == SIGNAL_MODE_MAIN)
	{
		signal(SIGINT, &handle_sigint_main);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (flag == SIGNAL_MODE_CHILD)
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, &handle_sigint_child);
	}
	else if (flag == SIGNAL_MODE_HEREDOC)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, &handle_sigint_main);
		signal(SIGINT, (void *)track_heredoc_signal);
		if (track_heredoc_signal(10) == 11)
			exit(EXIT_SIGINT);
	}
}
