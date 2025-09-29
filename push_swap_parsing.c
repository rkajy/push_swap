/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:35:27 by radandri          #+#    #+#             */
/*   Updated: 2025/09/28 05:53:30 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Checks if the given string token is valid according to specific criteria.
 *

	* A valid token is a non-empty string representing a signed or unsigned integer,
 * with an optional '+' or '-' at the beginning, followed by digits only.
 *
 * Example:
 *   is_valid_token("42")      -> 1
 *   is_valid_token("-123")    -> 1
 *   is_valid_token("+0")      -> 1
 *   is_valid_token("abc")     -> 0
 *   is_valid_token("")        -> 0
 *   is_valid_token("+")       -> 0
 *
 * @param s Pointer to the string token to validate.
 * @return 1 if the token is valid, 0 otherwise.
 */
int	is_valid_token(char *s)
{
	int	i;

	if (!s || !s[0])
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		/* sign alone is invalid */
		if (!s[i + 1])
			return (0);
		i++;
	}
	/* reject leading zero followed by other digits (ex: "03", "000") */
	if (s[i] == '0' && s[i + 1])
		return (0);
	/* all remaining chars must be digits */
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static char	*append_with_space(char *s1, char *s2)
{
	char	*tmp;
	char	*out;

	tmp = ft_strjoin(s1, s2);
	free(s1);
	if (!tmp)
		return (NULL);
	out = ft_strjoin(tmp, " ");
	free(tmp);
	return (out);
}

char	*ft_string_sanitize(char *args)
{
	int		i;
	int		j;
	char	*output;

	i = -1;
	while (args[++i])
	{
		if (is_space(args[i]))
		{
			args[i] = ' ';
			if (args[i + 1] && is_space(args[i + 1]))
				args[i + 1] = 127;
		}
	}
	output = malloc(sizeof(char) * (i + 1));
	if (!output)
		return (NULL);
	i = -1;
	j = 0;
	while (args[++i])
	{
		if (args[i] != 127)
			output[j++] = args[i];
	}
	return (output[j] = '\0', output);
}

/**
 * @brief Joins command-line arguments into a single string.
 *
 * Concatenates all arguments (except the program name) into a single
 * space-separated string. Returns a newly allocated string.
 *
 * Example:
 *   int argc = 4;
 *   char *argv[] = {"./a.out", "12", "34", "56"};
 *   char *joined = ft_join_args(argc, argv);
 *   // joined -> "12 34 56 "
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of argument strings.
 * @return Pointer to the joined string, or NULL on failure.
 *
 * @note The returned string must be freed by the caller.
 */
char	*ft_join_args(int argc, char *argv[])
{
	char	*output;
	char	*clean_arg;
	int		i;

	if (argc < 2)
		return (NULL);
	output = ft_strdup("");
	if (!output)
		return (NULL);
	i = 0;
	while (++i < argc)
	{
		clean_arg = ft_strtrim(argv[i], "\n\v\r\f \t");
		if (!clean_arg)
			return (free(output), NULL);
		output = append_with_space(output, clean_arg);
		free(clean_arg);
		if (!output)
			return (NULL);
	}
	clean_arg = ft_string_sanitize(output);
	free(output);
	if (!clean_arg)
		return (NULL);
	return (clean_arg);
}

t_stack	*parse_numbers_to_stack(char *str)
{
	long	num;
	t_stack	*list;
	char	**split;
	int		i;

	list = malloc(sizeof(t_stack));
	if (!list)
		return (NULL);
	initList(list);
	split = ft_split(str, ' ');
	if (!split)
		return (free(list), NULL);
	i = -1;
	while (split[++i])
	{
		if (!is_valid_token(split[i]))
			return (free_split(split), free(list), NULL);
		num = ft_atol(split[i]);
//        ft_printf("INT_MAX = %ld and INT_MIN = %d\n", INT_MAX, INT_MIN);
		if (num > INT_MAX || num < INT_MIN)
			return (free_split(split), free(list), NULL);
		if (!insertInTail_checked(list, (int)num))
			return (free_split(split), free(list), NULL);
	}
	free_split(split);
	return (list);
}
