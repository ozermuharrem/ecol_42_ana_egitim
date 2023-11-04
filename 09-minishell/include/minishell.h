/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:24:56 by oozturk           #+#    #+#             */
/*   Updated: 2023/02/13 12:39:14 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <time.h>
# include <stdbool.h>
# include <signal.h>
# include <fcntl.h>

typedef struct s_env
{
	char	**env;
	char	*user;
	char	*line;
	char	*to_open;
	int		exit_status;
	int		saved_stdout;
	int		saved_stdin;
	int		l_redirect;
	int		r_redirect;
	int		dl_redirect;
	int		dr_redirect;
	int		h_count;
	int		heredoc_quit;
	int		pipe;
	int		cd;
	int		cmp;
	t_list	*iter;
	t_list	*arg;
	t_list	*pipe_arg;
	t_list	*lst_env;
	t_list	*declare;
}	t_env;

t_env	*g_data;

// init.c
void	env_init(char **env);
void	reset_stdin(void);

// exit.c
void	sighandler(int num);
void	ctrl_d(void);

// utils.c
int		ft_strcmp(char *dst, char *src);
int		ft_strcmp2(char *asd, char *sda);
int		ft_strcmp3(char *dst, char *src);
void	lst_free(void);
int		lstcmp(char *str);

void	fd_free(int **fd);
int		lstcmp2(t_list *iter, char *str);

// utils2.c
char	*ft_strjoin3(char *s1, char *s2);
char	*ft_strjoin2(char *s1, char *s2);
void	go_pipe(void);
void	reset_stdout(void);

// lexer.c
int		lexer(void);
int		text_compare(void);
int		return_text(int a, int i);
int		lexer_count(int count, int i);
void	lex_add(int count);

// lexer2.c
int		compare2(void);
void	command_cut(int len);
int		commands(void);
int		command_length(int i);
void	space(void);

// lexer3.c
int		lexer_next(int count);
void	errormessage(int i);

// lists.c
t_list	*list_last_data(t_list *root, int index);
char	*list_data(t_list *root, int index);
void	ft_lstremove(t_list *list, int i);
char	**list_to_char(t_list *list);

// check.c
int		arg_check(void);
void	status_decider(int status, int index);
void	check_cmnd2(int **fd, int i);

// expand.c
void	expand(void);

// expand2.c
void	expand2(int index);
int		single_39_next(char *content);
void	redirect_decider(int status, int index, int r_c);

// redirect.c
void	cut_redirect(int index);
void	double_right_redirect(int index, int r_c);

// redirect2.c
void	right_redirect(int index, int r_c);
void	left_redirect(int index, int r_c);
void	ft_dstry_node_for_red(t_list *iter, int c);
int		which_redirect(char *content);
int		redirect_cntr(void);

void	run_heredoc(int i);

// usd_sign.c
char	*usd_sign(char *str, int i);
char	*check_env(char *env);

// usd_sign2.c
char	*env_name(char *str);

// execute.c
void	executor(void);

// heredoc.c
int		heredoc_check(void);

// heredoc2.c
int		heredoc_finder(void);
int		heredoc_count(void);
void	cut_heredoc(int index);

// pipe.c
int		has_pipe(void);
void	pipe_count(void);
void	run_pipe(void);

// pipe2.c
void	other_pipe_child(int i, int **fd);
void	wr_close_pipe(int **fd);

// cd.c
void	pwd_update(int i, t_list *list);
void	ft_export(t_list *list);
void	alpha_finder(void);
void	print_alpha2(void);
void	print_alpha(void);

// cd2.c
int		babe_finder(int i, t_list *iter, char *str, char *str2);
int		babe_finder_declared(int i, t_list *iter, char *str, char *str2);
void	just_cd(int i, t_list *list);
void	destroy_node(int i);
void	command_echo(t_list *list, int i);
void	destroy2(t_list *iter, int c); // ft_dstry_node2

// run.c
void	run_cmd(t_list *list);

// run_cmd.c
void	run_echo(t_list *list);
void	run_cd(t_list *list);
void	run_pwd(void);
void	run_unset(t_list *list);
void	ft_env(void);

// run_cmd2.c
void	exporter(char *content, int i, t_list *list);
void	run_exit(t_list *list);
void	run_next(char **arg);

#endif