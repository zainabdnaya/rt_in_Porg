/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <diyanazizo13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:22:58 by zdnaya            #+#    #+#             */
/*   Updated: 2020/10/19 19:57:38 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBTF_H
#ifndef LIBFT_H
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

typedef struct  s_list
{
    void            *content;
    struct s_list   *next;
}               t_list;

int 	        ft_atoi(char *str);
void	        ft_bzero(void *s, size_t n);
void	        *ft_calloc(size_t count , size_t size);
int		        ft_isalnum(int c);
int 	        ft_isdigit(int c);
int 	        ft_isalpha(int c);
int 	        ft_isascii(int c);
int 	        ft_isprint(int c);
void	        *ft_memccpy(void *dest, const void *src, char c, size_t len );
void	        *ft_memchr(void *s, int c , size_t n);
int 	        ft_memcmp(const void *s1, const void *s2, size_t n);
void	        *ft_memcpy(void *str1, void *str2, size_t n);
void	        *ft_memmove(void *dest, const void *src, size_t n);
void	        *ft_memset(void *str, int c,size_t n);
char	        *ft_strchr(const char *s, int c);
char	        *ft_strdup(char *src);
size_t 	        ft_strlcat(char *dest, const char *src, size_t size);
unsigned int	ft_strlen(const char *s);
int 	        ft_strncmp(const char *s1, const char *s2, size_t n);
char	        *ft_strnstr(const char *str1, const char *str2, size_t len);
char	        *ft_strrchr(const char *s, int c);
int 	        ft_tolower(int c);
int             ft_toupper(int c);
char            *ft_substr(char const *s,unsigned int start, size_t len );
void            ft_putendl_fd(char *s, int fd);
void            ft_putnbr_fd(int n, int fd);
char            *ft_strjoin(char const *s1, char const *s2);
char            *ft_strmapi(char const *s, char (*f)(unsigned int , char ));
char            *ft_strtrim(char const *s1 , char const *set);
void            ft_putstr_fd(char *s, int fd);
char            **ft_split (char *s , char c);
int		        ft_strncmp(const char *s1, const char *s2,size_t n);
void	        ft_putchar_fd(char c, int fd);
char            *ft_itoa( int n);
size_t          ft_strlcpy(char *dst, const char *src , size_t size);


#endif