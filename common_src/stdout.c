/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdout.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 14:27:22 by aperol-h          #+#    #+#             */
/*   Updated: 2021/08/30 15:25:00 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_count_digits(int n)
{
	int	c;

	c = 0;
	while (n != 0)
	{
		n /= 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	int		dc;
	char	*out;

	dc = ft_count_digits(n);
	out = malloc((dc + 1) * sizeof(char));
	if (!out)
		exit(0);
	out[dc--] = '\0';
	while (n != 0)
	{
		out[dc--] = (n % 10) + '0';
		n /= 10;
	}
	return (out);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *s)
{
	int	n;

	n = 0;
	while (*s)
	{
		n *= 10;
		if (!ft_isdigit(*s))
			return (-1);
		n += *s++ - '0';
	}
	return (n);
}

void	ft_print(char *s)
{
	while (*s)
		write(1, s++, 1);
}
