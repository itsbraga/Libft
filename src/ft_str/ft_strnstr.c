/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:49:26 by annabrag          #+#    #+#             */
/*   Updated: 2024/04/03 22:23:28 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!big && !len)
		return (NULL);
	if (little[0] == '\0' || big == little)
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && ((i + j) < len))
		{
			if (big[i + j] == '\0' && little[j] == '\0')
				return ((char *)(big + i));
			j++;
		}
		if (little[j] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}

/*int		main(void)
{
	char	*big = "Hello les amis, les petites vaches sont dans le pre";
	char	*little = "";

	printf("Result: %s\n", ft_strnstr(big, little, 1));
}*/
