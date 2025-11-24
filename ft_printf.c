/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 10:53:38 by tle-rhun          #+#    #+#             */
/*   Updated: 2025/11/24 19:16:08 by tle-rhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>
# include "include/ft_printf.h"

void	ft_pointerinhexadécimal(void *pointeur)
{
	char	*base;
	char *str;
	int	i;
	int	indice;
	
	base = "0123456789abcdef";
	str = (char *) pointeur;
	i = 0;
	while (str[i])
	{
		indice = 0;
		while (str[i] != base[indice])
			indice++;
		ft_putchar_fd(base[indice], 1);
		i++;
	}
}



void	ft_arg(char *s, int i, va_list ap)
{
	if (s[i + 1] == 'c')
		ft_putchar_fd(((char) va_arg(ap, int)), 1);
	if (s[i + 1] == 's')
		ft_putstr_fd(((char *) va_arg(ap, char *)), 1);
	if (s[i + 1] == 'p')
		ft_pointerinhexadécimal((void *) va_arg(ap, void *));
	// if (s[i + 1] == 'd')

	if (s[i + 1] == 'i')
		ft_putnbr_fd(((int) va_arg(ap, int)), 1);
	// if (s[i + 1] == 'u')

	// if (s[i + 1] == 'x')

	// if (s[i + 1] == 'X')

}
int	ft_condition(char *s, int i)
{
	if (s[i] == '%'
		|| s[i] == 'c'
		|| s[i] == 's'
		|| s[i] == 'p'
		|| s[i] == 'd'
		|| s[i] == 'i'
		|| s[i] == 'u'
		|| s[i] == 'x'
		|| s[i] == 'X'
	)
	{
		if (s[i + 1] == 'c' 
			|| s[i + 1] == 's' 
			|| s[i + 1] == 'p' 
			|| s[i + 1] == 'd' 
			|| s[i + 1] == 'i'
			|| s[i + 1] == 'u'
			|| s[i + 1] == 'x'
			|| s[i + 1] == 'X'
			|| s[i - 1] == '%')
			return (0);
		return (1);
	}
	else
		return (1);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	nbarg;
	char	*s;
	
	va_list ap;
	va_start(ap, str);
	i = 0;
	nbarg = 0;
	s = (char *) str;
	while (s[i])
	{
		if (s[i]== '%' && s[i+1]!= '%')
		{
			ft_arg(s, i, ap);
			nbarg ++;
		}
		if (ft_condition(s, i))
			ft_putchar_fd(s[i],1);
		i++;
	}
	va_end(ap);
	return (1);
}
// if (s[i] == '\0' && nbarg == 0)
	// ft_putstr_fd(s, 1);

#include <stdio.h>
int main (void)
{
	const char * str ="\nsalut %c %s %p %%";
	char *s ="tout le monde";
	char b ='b';
	int	nb = 64;
	int *ptr = &nb;
	ft_printf(str , b, s, ptr);
	printf(str , b, s, ptr);
	return (1);
}