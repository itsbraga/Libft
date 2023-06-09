/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:54:06 by annabrag          #+#    #+#             */
/*   Updated: 2023/05/12 13:25:54 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libc/libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

/*int	main(void)
{
	int	c = 80;
	printf("%d\n", ft_tolower(c));
	return (0);
}*/
