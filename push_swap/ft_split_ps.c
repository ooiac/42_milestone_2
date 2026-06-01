/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:29:08 by caida-si          #+#    #+#             */
/*   Updated: 2025/10/06 13:17:18 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++s;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c)
{
	static int	cursor;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	cursor = 0;
	i = 0;
	while (s[cursor] == c)
		++cursor;
	while ((s[cursor + len] != c) && s[cursor + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

static char	*skip_to_next_word(char *s, char c)
{
	while (*s == c)
		++s;
	while (*s && *s != c)
		++s;
	return (s);
}

static char	**fill_result(char **result, char *s, char c, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		result[i] = get_next_word(s, c);
		if (!result[i])
		{
			while (i > 0)
				free(result[--i]);
			free(result);
			return (NULL);
		}
		s = skip_to_next_word(s, c);
		i++;
	}
	result[words] = NULL;
	return (result);
}

char	**ft_split_ps(char *s, char c)
{
	int		words;
	char	**result;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (fill_result(result, s, c, words));
}
