# define PROTOTYPES_H_
#ifndef PROTOTYPES_H_
int	cut_label(char *line, t_args *args/* char **label */);
int	count_sep(char *str);
int	split_list(char *line, t_args *args);
int	is_legit(char *str);
char	*cut_double_quotes(char	*str);
int	get_info(char **stock, t_info **info);
void	header_handler(t_info *info);
int	only_label(char *str);
char	*ls_joint(char *str1, char *str2);
char	*epur_str(char *str);
int	get_param_value(char *str, int num);
int	get_param_type(char *str, int num);
int	line_parsing(t_args *args, t_list *list);
int	show_list(t_list *list);
int	asm_parsing(t_list *list, char **stock);
int	add_elem_prev(t_list *elem, t_args *args, int num);
int	add_elem_next(t_list *elem, t_args *args, int num);
int	my_delete_elem(t_list *list);
t_list	*init_list();
void	my_freelist(t_list *list);
int	which_instruction(char *str);

#endif /* !PROTOTYPES_H_
