/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 21:30:26 by aziyani           #+#    #+#             */
/*   Updated: 2022/10/21 19:12:08 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ss;
	size_t			len;
	unsigned int	i;

	if (!s || !f)
		return (0);
	len = 0;
	len = ft_strlen(s);
	ss = malloc(len + 1);
	if (!ss)
		return (0);
	i = 0;
	while (s[i])
	{
		ss[i] = f(i, s[i]);
			i++;
	}
	ss[i] = '\0';
	return (ss);
}
// #include <stdio.h>
// char f(unsigned int i, char c)
// {
// 	(void)i;
// 	if(c == ' ')
// 		return '_';
// 	return c;	
// }
// int main()
// {
// 	char s[] =  "ayo ub";
// 	printf ("%s", ft_strmapi(s, f));
// }