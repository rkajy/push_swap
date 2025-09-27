/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:04:57 by radandri          #+#    #+#             */
/*   Updated: 2025/09/27 03:17:06 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strrchr - Locate last occurrence of a char in a string.
 * @s: String to search.
 * @c: Char to search for (as unsigned char).
 *
 * Returns pointer to last occurrence of c in s, or NULL if not found.
 * The '\0' is considered part of s, so if c is '\0', returns pointer
 * to the terminator.
 *
 * Example:
 *   const char *str = "hello world";
 *   char *res = ft_strrchr(str, 'o');
 *   // res points to the 'o' in "world"
 */
char	*ft_strrchr(const char *s, int c)
{
	char	pc;
	size_t	i;

	i = ft_strlen(s);
	pc = (char)c;
	while (i > 0)
	{
		if (s[i] == pc)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	if (s[i] == pc)
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
