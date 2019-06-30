/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 09:54:52 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/23 19:04:52 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LIBFT_H
#	define LIBFT_H

#include "macrosoft.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define IS_LOWER(x) (x >= 'a' && x <= 'z' ? 1 : 0)
#define IS_UPPER(x) (x >= 'A' && x <= 'Z' ? 1 : 0)

#define ABS_V(x) (x < 0 ? -x : x)

#define BASE_16 "0123456789abcdef"
#define BASE_10 "0123456789"
#define BASE_8 "01234567"
#define BASE_2 "01"

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_vector
{
	size_t			len;
	size_t			cap;
	char			*data;
}					t_vector;

/*
** Bitwise Handlers
*/

u_int64_t			ft_bitinsert(u_int64_t nb, u_int64_t ins,
					unsigned lb, unsigned ub);
void				ft_printbits(u_int64_t nb);
u_int64_t			get_msb(u_int64_t nb);

/*
** Math Functions
*/
int					ft_lcm(int a, int b);
double				ft_rand(int seed);

/*
** Character
*/

int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_wchrlen(wchar_t c);
int					ft_isspace(int c);
void				ft_charswap(char *a, char *b);

/*
** Conversions
*/

char				*ft_imaxtoa(int64_t value);
char				*ft_itoa(int n);
char				*ft_uimaxtoa_base(u_int64_t value, int8_t base,
					const char *str);
int					ft_atoi(const char *str);
/*
** Integer
*/

int					ft_intlen(int64_t n);
int					ft_max(int *tab, size_t len);
int					ft_uintlen(u_int64_t n);

/*
** Linked List
*/

t_list				*ft_lstpushfront(t_list **begin_list, t_list *node);
t_list				*ft_lstpushback(t_list **begin_list, t_list *node);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);

/*
** Memory Management
*/

void				*ft_realloc(void *ptr, size_t src_size, size_t new_size);
void				*ft_recalloc(void *ptr, size_t src_size, size_t new_size);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				ft_memdel(void **ap);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memalloc(size_t size);
void				ft_bzero(void *s, size_t n);

/*
** I/O Handlers
*/

void				ft_putstr(char const *str);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putnbr(int64_t nb);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr_unsigned(u_int64_t nb);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putchar(int c);
void				ft_putnchar(int len, int c);
void				ft_putchar_fd(char c, int fd);

/*
** String Manipulation
*/

int					ft_str_is_char(char *s, char c);
wchar_t				*ft_wstrdup(wchar_t *str);
char				*ft_wstr_to_str(wchar_t *ws);
size_t				ft_wstrlen(wchar_t *str);
size_t				ft_wordcount(char *s, char c);
size_t				ft_strzchr(const char *s, int c);
char				*ft_strtrim(char const *s);
char				*ft_strtok(char *s, const char *delim);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strstr(const char *str, const char *to_find);
char				**ft_strsplit(char const *s, char c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
void				shift_char_to(char *selected, char *target);
char				*find_next_any(char *haystack, const char *search_list);
char				*find_last_any(char *haystack, const char *search_list);
char				*ft_strnew(size_t size);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strncpy(const char *dest, char *src, unsigned int n);
int					ft_strncmp(const char *s1, const char *s2, unsigned int n);
char				*ft_strncat(char *dest, char *src, int nb);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strlowcase(char *str);
size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dest, const char *src, size_t dest_size);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_strequ(const char *s1, const char *s2);
char				*ft_strdup(const char *src);
void				ft_strdel(char **as);
char				*ft_strcpy(char *dest, char *src);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_strclr(char *s);
char				*ft_strchr(const char *str, int c);
char				*ft_strcat(char *dest, char *src);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_str_to_unicode(wchar_t c, char *s);
void				ft_str_toupper(char *s);
int					ft_str_is_uppercase(char *str);
int					ft_str_is_printable(char *str);
int					ft_str_is_numeric(char *str);
char				*ft_join(char *s1, char *joiner, char*s2);
int					ft_str_is_lowercase(char *str);
int					ft_str_is_alpha(char *str);
char				*ft_strfill(char *s, char c, size_t n);
void				ft_sortwords(char **tab, ssize_t size);
char				*ft_skipspace(char *s);
char				*ft_prepend_str(char *prefix, char *suffix);
void				ft_insert_str(char **s1, char *s2);
void				ft_freestrarr(char **arr);
char				*ft_flattenarr(char **arr);
size_t				ft_arrlen(char **arr);
/*
** Vector-type String Buffer
*/

t_vector			**ft_vectorspace_create(size_t init_cap, size_t size);
t_vector			*ft_vector_create(size_t init_cap);
void				ft_vectorspace_free(t_vector **vspace, int size);
void				ft_subvector_slide(char *data, char *target,
					size_t data_len);
int					ft_vector_init(t_vector *vector, size_t init_cap);
void				ft_vector_append(t_vector *vector, char *newdata);
void				ft_vector_resize(t_vector *vector, size_t min);
void				ft_vector_nappend(t_vector *vector, char *newdata,
					size_t n);
void				ft_vector_free(t_vector *vector);

#	endif
