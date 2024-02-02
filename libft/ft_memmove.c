/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:49:03 by cogata            #+#    #+#             */
/*   Updated: 2023/07/20 19:49:05 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_move_s_after_d(char *d, const char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
}

void	ft_move_s_before_d(char *d, const char *s, size_t n)
{
	while (n > 0)
	{
		d[n - 1] = s[n - 1];
		n--;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = (char *)dest;
	s = (const char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (s > d)
		ft_move_s_after_d(d, s, n);
	else
	{
		ft_move_s_before_d(d, s, n);
	}
	return (dest);
}
