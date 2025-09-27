/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:23:43 by radandri          #+#    #+#             */
/*   Updated: 2025/09/27 03:12:17 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts a lowercase letter to its uppercase equivalent.
 *
 * Takes an int representing an ASCII character. If it's a lowercase
 * letter ('a'-'z'), returns its uppercase. Otherwise, returns c.
 *
 * @param c The character to convert, as an int.
 * @return Uppercase equivalent if c is lowercase, else c unchanged.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}
