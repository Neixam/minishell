/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:03:26 by ambouren          #+#    #+#             */
/*   Updated: 2022/11/30 16:20:06 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_tree
{
	void			*content;
	struct s_tree	*bro;
	struct s_tree	*child;
}					t_tree;

typedef struct s_hash_set
{
	t_list			**entries;
	int				capacity;
	int				size;
	int				(*hashcode)(void *);
}					t_hash_set;

/* Memory function */
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				*ft_malloc(size_t size);
void				ft_free(void *ptr);
void				ft_clean_memory(void);
int					ft_adcmp(void *a1, void *a2);
void				ft_free_tab(void *a);

/* Char function */
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/* String function */
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_atoi(const char *nptr);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_coll_string(void *a, void *b);

/* Display function */
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);

/* Linked List function */
t_list				*ft_lstnew(void *content);
t_list				*ft_lstremove(t_list **lst, t_list *unit);
t_list				*ft_lstremove_elem(t_list **lst, void *elem,
						int (*cmp)(void *, void *));
void				ft_lstadd_front(t_list **alst, t_list *nw);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *nw);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/* Reading File */
char				*get_next_line(int fd);

/* Tree function */
void				ft_destroy_tree(t_tree **tree, void (*del)(void *));
t_tree				*ft_new_node(void *content);
void				ft_add_child(t_tree **tree, t_tree *node);
void				ft_add_bro(t_tree **tree, t_tree *node);
void				ft_depth_first_iter(t_tree *tree, void (*f)(void *));
void				ft_breadth_first_iter(t_tree *tree, void (*f)(void *));

/* HashSet function */
t_hash_set			*ft_new_hashset(int (*hashcode)());
void				ft_put_element(t_hash_set *set, void *element);
void				ft_free_hashset(t_hash_set *set, void (*del)(void *));
void				*ft_remove_element(t_hash_set *set, void *element,
						int (*cmp)(void *, void *));
void				ft_foreach(t_hash_set *set, void (*f)(void *));
void				*ft_get_elem(t_hash_set *set, void *elem, int (*cmp)(void *,
							void *));
int					ft_hashcode(t_hash_set *set, void *cnt);
void				*ft_collect(t_hash_set *set, size_t size,
						void (*collector)(void *, void *));

#endif
