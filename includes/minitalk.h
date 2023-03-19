/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 14:34:09 by aperol-h          #+#    #+#             */
/*   Updated: 2021/09/02 18:57:57 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

typedef struct s_byte
{
	char	c;
	int		b_i;
	pid_t	cid;
}	t_byte;
void	ft_print(char *s);
char	*ft_itoa(int n);
int		ft_atoi(char *s);
#endif