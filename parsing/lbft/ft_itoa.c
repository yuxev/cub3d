/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:30:10 by aziyani           #+#    #+#             */
/*   Updated: 2022/10/21 19:11:21 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cnumber(int num)
{
	int	sum;

	sum = 0;
	while (num)
	{
		num /= 10;
		sum++;
	}
	return (sum);
}

char	*zeroft(void)
{
	char	*xn;

	xn = ft_calloc(2, sizeof(char));
	if (!xn)
		return (0);
	xn[0] = '0';
	return (xn);
}

void	helper(long long n, char *s, int n_len, int var)
{
	while (n)
	{
		s[n_len - 1] = (n % 10) + 48;
		n = (n / 10);
		n_len--;
	}
	if (var == 1)
		s[n_len - 1] = '-';
}

char	*ft_itoa(int x)
{
	char		*s;
	int			n_len;
	int			var;
	long long	n;

	if (x == 0)
		return (zeroft());
	n = x;
	var = 0;
	if (n < 0)
	{
		n = n * -1;
		var = 1;
	}
	n_len = cnumber(n);
	s = malloc(n_len + 1 + var);
	if (!s)
		return (0);
	n_len = n_len + (var);
	s[n_len] = '\0';
	helper(n, s, n_len, var);
	return (s);
}
// int main()
// {
// 	int i = 0x045;

// 	printf("%s", ft_itoa(i));
// }