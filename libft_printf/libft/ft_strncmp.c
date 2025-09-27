/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:06:32 by radandri          #+#    #+#             */
/*   Updated: 2025/09/27 04:44:14 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compares up to 'n' characters of the strings s1 and s2.
 * Returns an integer less than, equal to, or greater than zero if s1 (or the
 * first n bytes thereof) is found, respectively, to be less than, to match,
 * or be greater than s2.
 *
 * Example:
 *   ft_strncmp("abc", "abd", 2); // returns 0 (first 2 chars are equal)
 *   ft_strncmp("abc", "abd", 3); // returns negative value ('c' < 'd')
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != '\0')
		{
			if ((unsigned char)s1[i] == (unsigned char)s2[i])
				i++;
			else
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
