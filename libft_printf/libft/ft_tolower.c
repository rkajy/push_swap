/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:26:45 by radandri          #+#    #+#             */
/*   Updated: 2025/09/27 03:12:17 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Converts an uppercase letter to lowercase.
 *
 * @param c The character to convert, as an int.
 * @return Lowercase if c is 'A'-'Z', else c unchanged.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	return (c);
}
