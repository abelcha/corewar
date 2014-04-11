/*
** op.h
**
** Nicolas Sadirac
** Tue Jul 13 18:53:48 1993
*/

#ifndef _OP_H_
# define _OP_H_



#define MEM_SIZE               (6 * 1024)
#define IDX_MOD                 512   /* modulo de l'index < */
#define MAX_ARGS_NUMBER         4     /* this may not be changed 2^*IND_SIZE */

#define COMMENT_CHAR            '#'
#define LABEL_CHAR              ':'
#define DIRECT_CHAR             '%'
#define SEPARATOR_CHAR          ','

#define LABEL_CHARS             "abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING         ".name"
#define COMMENT_CMD_STRING      ".comment"

/*
 ** regs
 */

#define REG_NUMBER      16              /* r1 <--> rx */

/*
 **
 */

typedef char    args_type_t;

#define T_REG           1       /* registre */
#define T_DIR           2       /* directe  (ld  #1,r1  met 1 dans r1) */
#define T_IND           4       /* indirecte toujours relatif
                                   ( ld 1,r1 met ce qu'il y a l'adress (1+pc)
                                   dans r1 (4 octecs )) */
#define T_LAB           8       /* LABEL */

#define REG_SIZE        1               /* en octet */
#define IND_SIZE        2               /* en octet */
#define DIR_SIZE        4	        /* en octet */

typedef struct	s_op
{
  char		*name;
  char		nbr_args;
  args_type_t	type[MAX_ARGS_NUMBER];
  char		code;
  int		nbr_cycles;
  char		*comment;
}		t_op;

typedef struct	s_param
{
  int		type;
  int		w_size;
  int		param;
  char		*l_flag;
}		t_param;

typedef struct	s_list
{
  t_param	param[MAX_ARGS_NUMBER];
  int		coding_byte;
  int		size;
  int		num;
  char		*label; // -> NULL si il n'y en a pas / label associé
  struct s_list	*next;
  struct s_list	*prev;
}		t_list;

typedef struct	s_args
{
  char		**args;
  char		*label;
}		t_args;

/*
 ** size
 */

/*
** op_tab
*/


extern  t_op    op_tab[];


/*
** header
*/

#define PROG_NAME_LENGTH        128
#define COMMENT_LENGTH          2048

struct header_s
{
   int  magic;
# define COREWAR_EXEC_MAGIC      0xea83f3	/* why not */
   char prog_name[PROG_NAME_LENGTH+1];
   int  prog_size;
   char comment[COMMENT_LENGTH+1];
};

typedef struct header_s header_t;

/*
** live
*/

#define CYCLE_TO_DIE    (3 *1560)   /* nombre de cycle pour etre d\'eclarer mort */
#define CYCLE_DELTA     5
#define NBR_LIVE        400
#endif
