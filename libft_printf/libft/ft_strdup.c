/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:25:45 by radandri          #+#    #+#             */
/*   Updated: 2025/09/27 03:44:03 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Duplicates a string.
 *
 * Allocates memory for a copy of the string s1, does the copy,
 * and returns a pointer to it.
 *
 * @param s1 The string to duplicate.
 * @return Pointer to the duplicated string, or NULL if allocation fails.
 *
 * Example:
 * char *copy = ft_strdup("hello");
 * // copy now points to a new string "hello"
 */
char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	size_t	i;
	char	*res;

	s1_len = ft_strlen(s1);
	i = 0;
	res = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (!res)
	{
		return (NULL);
	}
	while (i < s1_len)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
