/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:35:27 by radandri          #+#    #+#             */
/*   Updated: 2025/10/18 20:49:46 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static char	*ft_replace_spaces(char *args)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = malloc(sizeof(char) * (ft_strlen(args) + 1));
	if (!tmp)
		return (NULL);
	i = -1;
	j = 0;
	while (args[++i])
	{
		if (args[i] == '\t')
			tmp[j++] = ' ';
		else if (args[i] == '\\' && args[i + 1] == 't')
		{
			tmp[j++] = ' ';
			i++;
		}
		else if (is_space(args[i]))
			tmp[j++] = ' ';
		else
			tmp[j++] = args[i];
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*ft_string_sanitize(char *args)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = ft_replace_spaces(args);
	if (!tmp)
		return (NULL);
	i = 0;
	j = 0;
	while (tmp[i])
	{
		if (tmp[i] == ' ' && j > 0 && tmp[j - 1] == ' ')
			i++;
		else
			tmp[j++] = tmp[i++];
	}
	tmp[j] = '\0';
	return (tmp);
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
	init_list(list);
	split = ft_split(str, ' ');
	if (!split)
		return (free_list(list), NULL);
	i = -1;
	while (split[++i])
	{
		if (!is_valid_token(split[i]))
			return (free_split(split), free_list(list), NULL);
		num = ft_atol(split[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (free_split(split), free_list(list), NULL);
		if (!insert_int_in_tail_checked(list, (int)num))
			return (free_split(split), free_list(list), NULL);
	}
	free_split(split);
	return (list);
}
