/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:33:41 by radandri          #+#    #+#             */
/*   Updated: 2025/09/27 03:12:17 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_substr - Allocates and returns a substring from 's'.
 *
 * @s:     Source string.
 * @start: Starting index in 's'.
 * @len:   Max length of substring.
 *
 * Returns:
 *   Newly allocated substring from 's' starting at 'start' of max length 'len'.
 *   Returns empty string if 'start' > length of 's'. Returns NULL on failure.
 *
 * Note:
 *   Result is null-terminated. Handles out-of-bounds 'start' and large 'len'.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
