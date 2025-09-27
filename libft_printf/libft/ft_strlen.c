/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 22:24:24 by radandri          #+#    #+#             */
/*   Updated: 2025/09/27 04:44:14 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Calculates the length of a null-terminated string.
 *
 * Iterates through the string pointed to by 's' until it finds the
 * null terminator ('\0'), counting the number of characters.
 *
 * @param s Pointer to the null-terminated string.
 * @return The number of characters in the string (not counting '\0').
 *
 * @example
 * const char *str = "hello";
 * size_t len = ft_strlen(str); // len == 5
 */
size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
	{
		size++;
	}
	return (size);
}
