/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:53:40 by mdouglas          #+#    #+#             */
/*   Updated: 2022/05/10 13:51:29 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digit(int n)
{
	int	idx;

	idx = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		idx++;
	}
	return (idx);
}

static char	*ft_printoa(int n, char *str, size_t len)
{
	if (n == 0)
		str[0] = '0';
	else if (len == 1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	size_t		len;
	char		*str;
	long int	num;

	num = n;
	len = 0;
	if (num < 0)
	{
		num = num * -1;
		len = 1;
	}
	len = len + ft_count_digit(n);
	str = malloc((len + 1));
	if (str == 0)
		return (0);
	str[len] = '\0';
	while (num > 0)
	{
		str[len -1] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (ft_printoa(n, str, len));
}