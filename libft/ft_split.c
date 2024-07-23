/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:52:32 by jesopan-          #+#    #+#             */
/*   Updated: 2024/04/18 18:35:04 by jesopan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	num_words(const char *str, char c)
{
	int	count;
	int	target;

	count = 0;
	target = 0;
	while (*str)
	{
		if (*str != c && target == 0)
		{
			count++;
			target = 1;
		}
		else if (*str == c)
			target = 0;
		str++;
	}
	return (count);
}

static char	*dup_word(const char *s, char c)
{
	static int	position = 0;
	char		*word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[position] == c)
		++position;
	while ((s[position + len] != c) && s[position + len])
		++len;
	word = malloc((size_t)len * sizeof(char) + 1);
	if (!word)
		return (NULL);
	while ((s[position] != c) && s[position])
		word[i++] = s[position++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	int		num_of_words;
	char	**result_array;
	int		i;

	i = 0;
	num_of_words = num_words(s, c);
	if (!num_of_words)
		exit(1);
	result_array = malloc(sizeof(char *) * (size_t)(num_of_words + 2));
	if (!result_array)
		return (NULL);
	while (num_of_words-- >= 0)
	{
		if (i == 0)
		{
			result_array[i] = malloc(sizeof(char));
			if (!result_array[i])
				return (NULL);
			result_array[i++][0] = '\0';
			continue ;
		}
		result_array[i++] = dup_word(s, c);
	}
	result_array[i] = NULL;
	return (result_array);
}
