/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 09:38:16 by smifsud           #+#    #+#             */
/*   Updated: 2016/10/06 14:14:53 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define ABS(x) (x < 0 ? -x : x)
# define TOABS(x) if (x < 0) x *= -1
# define IS(x, y) (x == y)
# define NOT(x, y) (x != y)
# define ISUPPER(x) (x <= 90 && x >= 65)
# define ISLOWER(x) (x <= 122 && x >= 97)
# define ISPRINT(x) (x>=32 && x<=126)
# define ISDIGIT(x) (x>=48 && x<=57)
# define ISASCII(x) (x>=0 && x<=127)
# define ISALPHA(x) ((x<= 122 && x>=97) || (x<= 90 && x >= 65))
# define ISALPHANUM(x) ((x>=48 && x<=57)||(x<=90 && x>=65)||(x<=122 && x>=97))
# define SPACE(x) (x == ' ' || x == '\n' || x == '\t')
# define SPACEE(x) (x=='\t'||x=='\n'||x=='\v'||x=='\f'||x=='\r'||x==' ')
# define MALLOC_GUARD(x) if(!x) return (0)
# define ARRAY_GUARD(x) {if(!x){ ft_free_everything(x); return (0);}}
# define ALLOC(type, size) malloc(sizeof(type) * size)
# define MAL(x, cast, type, size) x=(cast)ALLOC(type, size)
# define PR_MALLOC(x, cast, type, size) MALLOC_GUARD((MAL(x, cast, type, size)))
# define REALLOCATE(x, newsize, oldsize) ft_realloc_nptr(x, newsize, oldsize)
# define RE(x, cast, s1, s2) x=(cast)REALLOCATE(x, s1, s2)
# define PR_REALLOC(x, cast, s1, s2) MALLOC_GUARD((RE(x, cast, s1, s2)))

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char				*ft_reversestr(char *str);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_realloc(void *buf, size_t buf_cap);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *b, const char *l, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
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
char				*ft_itoa(int n);
void				ft_putchar(int c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(int c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_free_everything(void **ptr);
void				*ft_realloc_nptr(void *buf, size_t n_size, size_t o_size);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *newlst);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
