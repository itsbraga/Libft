/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:29:00 by annabrag          #+#    #+#             */
/*   Updated: 2024/04/03 22:23:28 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	i_belong2charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static int	word_count(char *str, char *charset)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (!i_belong2charset(str[i], charset))
		{
			counter++;
			while (str[i] && !i_belong2charset(str[i], charset))
				i++;
		}
		else
			i++;
	}
	return (counter);
}

static char	*ft_strxdup(char *str, char *charset)
{
	int		i;
	int		slen;
	char	*dup;

	i = 0;
	slen = ft_strlen(str);
	dup = malloc(sizeof(char) * (slen + 1));
	if (!dup)
		return (NULL);
	while (str[i] && (!i_belong2charset(str[i], charset)))
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split_charset(char *str, char *charset)
{
	int		i;
	int		j;
	int		counter;
	char	**split;

	if (!str || !str[0])
		return (NULL);
	counter = word_count(str, charset);
	split = malloc(sizeof(char *) * (counter + 1));
	if (!split)
		return (NULL);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (!i_belong2charset(str[i], charset))
		{
			split[j++] = ft_strxdup(&str[i], charset);
			while (str[i] && !i_belong2charset(str[i], charset))
				i++;
		}
	}
	split[j] = NULL;
	return (split);
}

// int	main(int argc, char **argv)
// {
// 	int		i;
// 	char	**split;

// 	i = 0;
// 	split = NULL;
// 	if (argc < 3)
// 		return (0);
// 	split = ft_split(argv[1], argv[2]);
// 	if (!split)
// 		return (0);
// 	while (i < word_count(argv[1], argv[2]))
// 	{
// 		printf("%s\n", split[i]);
// 		free(split[i]);
// 		i++;
// 	}
// 	free(split);
// }