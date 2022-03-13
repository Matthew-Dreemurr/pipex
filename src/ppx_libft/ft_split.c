/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:16:53 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/13 13:03:17 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ppx_libft.h"

#include "ppx_debug.h"

/**
 * @brief Count word in `str`.
 * 
 * @param str
 * @param c
 * @return size_t
 */
static size_t	word_count(const char *str, char c)
{
	size_t	size;

	size = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (!*str)
			break ;
		while (*str && *str != c)
			str++;
		size++;
		if (*str)
			str++;
	}
	return (size);
}

/**
 * @brief alloc a tab.
 *        all tab point a NULL pointer.
 * @param str 
 * @param c   The separator caracter
 * @return size_t 
 */
static char	**alloc_tab(const char *str, char c)
{
	size_t	size;
	char	**tab;

	if (!str)
		return (NULL);
	size = word_count(str, c) + 1;
	tab = (char **)ft_calloc(size, sizeof(char *));
	if (!tab)
		return (NULL);
	while (--size)
		tab[size] = NULL;
	return (tab);
}

/**
 * @brief
 * 
 * @param str
 * @param c
 * @return char*
 */
static char	*world_dup(const char *str, char c)
{
	void	*ptr;
	char	*start;

	ptr = (void *)str;
	while (*(const char *)ptr && *(const char *)ptr != c)
		ptr++;
	ptr = ft_calloc((size_t)((const char *)ptr - str) + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	start = (char *)ptr;
	while (*str && *str != c)
		*(char *)ptr++ = *str++;
	*(char *)ptr = '\0';
	return (start);
}

/**
 * @brief Will free all allocate tab and the tab pointer.
 * 
 * @param tab 
 * @return char** Will return `NULL` pointer.
 */
static char	**error_tab_free(char **tab)
{
	char	**start;

	if (!tab)
		return (NULL);
	start = tab;
	while (*tab)
	{
		free(*tab);
		tab++;
	}
	free (start);
	return (NULL);
}

/**
 * @brief Allocates (with malloc(3)) and returns an array
 *        of strings obtained by splitting ’s’ using the
 *        character ’c’ as a delimiter.  The array must be
 *        ended by a NULL pointer.
 * 
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return char** The array of new strings resulting from the split.
 *         NULL if the allocation fails.
 */
char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	**ptr;
	size_t	word;

	tab = alloc_tab(s, c);
	if (!tab)
		return (NULL);
	ptr = tab;
	word = word_count(s, c);
	while (*s && word--)
	{
		while (*s && *s == c)
			s++;
		if (*s != c)
			*ptr = world_dup(s, c);
		if (!*ptr)
			return (error_tab_free(tab));
		while (*s && *s != c)
			s++;
		ptr++;
		if (*s)
			s++;
	}
	*ptr = NULL;
	return (tab);
}
