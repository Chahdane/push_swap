/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ato.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:21:12 by achahdan          #+#    #+#             */
/*   Updated: 2022/02/11 23:28:02 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	nb_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*fill(int size, int i, long n, long nb)
{
	char	*nbr;

	nbr = (char *)malloc(sizeof(char) * (size + 1));
	if (!nbr)
		return (NULL);
	nbr[size] = '\0';
	size--;
	while (size >= i)
	{
		nbr[size] = (n % 10) + 48;
		size--;
		n = n / 10;
	}
	if (nb < 0)
		nbr[size] = '-';
	return (nbr);
}

int	ft_itoa(int n)
{
	char	*nbr;
	int		size;
	int		i;
	long	nb;

	nb = n;
	i = 0;
	size = nb_len(n);
	if (n < 0)
	{
		n = n * -1;
		size++;
		i = 1;
	}
	nbr = fill(size, i, n, nb);
	ft_putstr(nbr);
	free(nbr);
	return (size);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res);
}
