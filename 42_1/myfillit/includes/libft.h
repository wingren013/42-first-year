/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 11:01:11 by kyork             #+#    #+#             */
/*   Updated: 2016/09/28 13:51:34 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putendl(char const *str);
void				ft_putnbr(int nbr);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

char				*ft_itoa(int n);
int					ft_atoi(const char *str);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *restrict src,
						int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big,
						const char *little, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

# ifndef IS_SPACE
#  define IS_SPACE(x) (x==' '||x=='\n'||x=='\t'||x=='\r'||x=='\v'||x=='\f')
# endif

# ifndef UNUSED
#  define UNUSED(x) (void)(x)
# endif

# define FD_STDIN  0
# define FD_STDOUT 1
# define FD_STDERR 2

/*
** Linked list
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *n);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Growing Array
**
** grow, append, and insert take a int *fail parameter. when a malloc call
** fails, they will set *fail to 1 and return the original array instead of
** returning NULL. users must inspect the value of *fail after every
** invocation.
**
** No bounds checking is performed, or is on a best-effort basis. The caller
** must pass correct indices to all functions.
**
** If item_cap is 0, the array is a view of other memory and cannot be grown.
** functions returning a t_array* will fail. (ft_ary_viewof())
*/

typedef struct		s_array
{
	void			*ptr;
	const size_t	item_size;
	size_t			item_count;
	size_t			item_cap;
}					t_array;

# define FT_ARY_DEFAULT_CAP 4
# define FT_ARY_GROW_FACTOR 2

t_array				*ft_ary_create(const size_t sizeof_item);
t_array				ft_ary_viewof(void *ptr, size_t count,
						const size_t sizeof_item);
void				*ft_ary_get(t_array *ary, size_t idx);
void				ft_ary_set(t_array *ary, void *item, size_t idx);
t_array				*ft_ary_grow(t_array *ary, size_t min_item_cap, int *fail);
t_array				*ft_ary_append(t_array *ary, void *item, int *fail);
t_array				*ft_ary_insert(t_array *ary, void *item,
						size_t idx, int *fail);
t_array				*ft_ary_remove(t_array *ary, size_t idx);
t_array				*ft_ary_clear(t_array *ary, int *fail);
void				ft_ary_destroy(t_array **pary);
void				ft_ary_swap(t_array *ary, size_t i, size_t j);

/*
** Extra functions
*/

void				*ft_memdup(const void *content, size_t size);
void				ft_lstpop(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_arytolst(const void *start, size_t content_size,
						size_t count);

#endif
