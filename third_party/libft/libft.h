/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:13:50 by maldavid          #+#    #+#             */
/*   Updated: 2023/05/14 11:00:16 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

# ifndef FT_NULL
#  if defined(__cplusplus)
#   define FT_NULL 0L
#  elif __STDC_VERSION__ >= 199901L
#   define FT_NULL 0
#  else
#   define FT_NULL ((void *)0)
#  endif
# endif

typedef enum __attribute__((__packed__)) e_bool { FALSE = 0, TRUE = 1 }	t_bool;
typedef unsigned long		t_size;
typedef unsigned char		t_uint8;
typedef unsigned char		t_u8;
typedef unsigned short		t_uint16;
typedef unsigned short		t_u16;
typedef unsigned int		t_uint32;
typedef unsigned int		t_u32;
typedef unsigned long long	t_uint64;
typedef unsigned long long	t_u64;

typedef void				*(*t_alloc)(t_size);
typedef void				(*t_free)(void *);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

void	ft_set_internal_malloc(t_alloc f);
t_alloc	*ft_get_internal_alloc(void);
void	*ft_malloc(t_size size);
void	ft_set_internal_free(t_free f);
t_free	*ft_get_internal_free(void);
void	ft_free(void *ptr);
int		ft_putchar(unsigned char c);
int		ft_putchar_fd(unsigned char c, int fd);
int		ft_putstr(char *s);
int		ft_putstr_fd(char *s, int fd);
int		ft_putendl_fd(char *s, int fd);
int		ft_putnbr(long long nb);
int		ft_putnbr_fd(long long nb, int fd);
void	*ft_memset(void *s, int c, t_size n);
void	*ft_memalloc(t_size size);
void	*ft_memcpy(void *dest, const void *src, t_size n);
void	*ft_memccpy(void *dest, const void *src, int c, t_size n);
void	*ft_memmove(void *dest, const void *src, t_size n);
int		ft_memcmp(const void *s1, const void *s2, t_size n);
void	*ft_memchr(const void *buf, int c, t_size size);
void	*ft_nmemchr(const void *buf, int c, t_size size);
void	*ft_calloc(t_size n, t_size size);
void	ft_memdel(void **ap);
void	*ft_memshrink(void *buf);
void	ft_bzero(void *ptr, t_size n);
void	ft_swap(void *a, void *b);
t_size	ft_strlen(const char *s);
t_size	ft_nbrlen(long nbr);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, t_size size);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, t_size n);
char	*ft_strnew(t_size size);
void	ft_strdel(char **as);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
t_size	ft_strlcpy(char *dest, const char *src, t_size size);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *dest, const char *src, t_size n);
t_size	ft_strlcat(char *dst, const char *src, t_size size);
char	*ft_strchr(const char *s, int c);
char	*ft_nstrchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *haystack, const char *needle);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strnstr(const char *str, const char *to_find, t_size n);
char	*ft_nlltoa(unsigned long long num, char *dest, int pos, int base);
int		ft_strncmp(const char *s1, const char *s2, t_size n);
char	*ft_substr(const char *str, unsigned int start, t_size len);
char	*ft_strjoin(const char *s1, const char *s2);
char	**ft_split(const char *s, const char sep);
char	**ft_splits(const char *s, const char *charset);
int		ft_atoi(const char *nptr);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_islower(int c);
int		ft_isupper(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	ft_strrev(char *str);
char	*ft_itoa(int num);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char	*get_next_line(int fd);
int		ft_printf(const char *str, ...);

#endif
