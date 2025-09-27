/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 22:11:15 by radandri          #+#    #+#             */
/*   Updated: 2025/09/27 04:44:14 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ft_isalpha - Checks if a character is an alphabetic letter.
 * @c: The character to check (as an int).
 *
 * Return: 1 if the character is an alphabetic letter (a-z or A-Z), 0 otherwise.
 *
 * Example:
 *     if (ft_isalpha('A')) {
 *         // This will execute because 'A' is an alphabetic letter.
 *     }
 */
int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
