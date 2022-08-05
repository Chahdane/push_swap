/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:21:45 by achahdan          #+#    #+#             */
/*   Updated: 2022/02/19 19:14:20 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + (str[i] - 48);
		else
			return (99999999999);
		i++;
	}
	return (res * sign);
}
