# define PROTOTYPES_H_
#ifndef PROTOTYPES_H_
int	is_number(char *str);
int	line_cmp(char *str);
int	fill_line(t_champ *champ, t_settings *sets, int cmp, int value);
int	add_in_list(t_champ *new_elem, t_champ *champ, char *str);
t_champ	*init_champ();
int	add_champs_in_list(t_champ *champ, char **stock, t_settings *sets);
int	rd_open(char *name, int *fd);
int	read_header(t_champ *champ, int fd);
int	read_code(t_champ *champ, int fd);
int	fill_champs(t_champ *champ);
int	syntax_error();
int	option_error(int cmp);
int	not_a_number(char *str);
int	write_in_arena(char *arena, char *code, int size, int pos);
int	get_size(t_arena *arena, t_champ *root);
t_arena	*init_arena(t_champ *root);
int	shw_list(t_champ *root);
void	display_arena(char *str);
void	display_sets(t_settings *sets);
int	start_battle(t_champ *root, t_arena *arena, t_settings sets);

#endif /* !PROTOTYPES_H_
