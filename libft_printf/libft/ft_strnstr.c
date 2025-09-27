/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:13:02 by radandri          #+#    #+#             */
/*   Updated: 2025/09/27 03:19:12 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of the null-terminated string 'needle'
 *        within the string 'haystack', searching at most 'len' characters.
 *        Characters after a '\0' are not searched.
 *
 * @param haystack The string to search in.
 * @param needle The substring to search for.
 * @param len Max number of characters to search.
 * @return Pointer to first occurrence of 'needle' in 'haystack', or NULL if not
 *         found within the first 'len' characters.
 *
 * Example:
 * char *s = "Hello, world!";
 * char *res = ft_strnstr(s, "world", 13);
 * // res points to "world!"
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	if (!haystack && len == 0)
	{
		if (!needle)
			return (NULL);
		return (NULL);
	}
	needle_len = ft_strlen(needle);
	i = 0;
	if (needle[i] == 0)
	{
		return ((char *)haystack);
	}
	while (haystack[i] && i + needle_len <= len)
	{
		if (ft_strncmp(&haystack[i], needle, needle_len) == 0)
		{
			return ((char *)(&(haystack[i])));
		}
		i++;
	}
	return (NULL);
}
