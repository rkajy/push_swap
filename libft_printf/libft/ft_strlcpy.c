/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:16:18 by radandri          #+#    #+#             */
/*   Updated: 2025/09/27 04:44:14 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies up to dstsize - 1 chars from src to dst, NUL-terminating dst.
 *
 * @param dst      Destination buffer.
 * @param src      Source string.
 * @param dstsize  Size of destination buffer.
 * @return         Length of src.
 *
 * Example:
 *   char buf[5];
 *   ft_strlcpy(buf, "hello", sizeof(buf));
 *   // buf now contains "hell"
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size_src;

	size_src = ft_strlen(src);
	if (!dstsize)
	{
		return (size_src);
	}
	if (!size_src)
	{
		dst[0] = '\0';
	}
	if (dstsize > 0)
	{
		i = 0;
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (size_src);
}
