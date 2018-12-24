/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asicat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:12:41 by asicat            #+#    #+#             */
/*   Updated: 2018/12/21 11:02:07 by asicat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int		g_zeropad;
int		g_negpad;
int		g_sign;
int		g_ash;
int		g_len;
int		g_space;

static int		precision_check(char *format, int n)
{
	int		i;
	int		k;
	int		mem;
	char	*str;

	i = 0;
	k = 0;
	mem = n;
	while (format[n] >= '0' && format[n++] <= '9')
		i++;
	if (!(str = (char*)malloc(i + 1)))
		return (-1);
	n = mem;
	while (i > 0)
	{
		str[k] = format[n + k];
		i--;
		k++;
	}
	str[k] = '\0';
	free(str);
	return (ft_atoi(str));
}

static char		*ft_itoafloat(double nb, int sub_size)
{
	int		n;
	double	d;
	char	*res;

	n = (int)nb;
	d = nb - n;
	if (sub_size == -1)
		sub_size = 6;
	if (sub_size == 0)
		return (ft_itoa(n));
	while (sub_size-- > 0)
		d = d * 10;
	if ((int)d % 10 == 9)
		d++;
	if (!(res = (char*)malloc(ft_strlen(ft_itoa(n)) + ft_strlen(ft_itoa((int)d)) + 2)))
		return (NULL);
	res = ft_strcpy(res, ft_itoa(n));
	res[ft_strlen(ft_itoa(n))] = '.';
	res = ft_strcat(res, ft_itoa((int)d));
	return (res);
}

static char		*flag_appli_str(char *str)
{
	char	*tmp;
	int		n;

	n = 0;
	printf("%d", g_len);
	if (g_negpad > 0)
	{
		if (!(tmp = (char*)malloc(g_negpad + 1)))
			return (str);
		while (g_negpad-- > 0)
			tmp[n++] = ' ';
		tmp[n] = '\0';
		str = ft_strjoin(str, tmp);
		free(tmp);
	}
	else if (g_zeropad > 0)
	{
		if (!(tmp = (char*)malloc(g_zeropad + 1)))
			return (str);
		while (g_zeropad-- > 0)
			tmp[n++] = '0';
		tmp[n] = '\0';
		str = ft_strjoin(tmp, str);
		free(tmp);
	}
	if (g_len > 0)
	{
		n = 0;
		g_len = g_len - ft_strlen(str);
		if (!(tmp = (char*)malloc(g_len + 1)))
			return (str);
		while (g_len-- > 0)
			tmp[n++] = ' ';
		tmp[n] = '\0';
		str = ft_strjoin(tmp, str);
		free(tmp);
	}
	return (str);
}

static char		*base_appli(char *str)
{
	char	*tmp;
	int		i;
	int		k;

	k = 0;
	i = ft_strlen(str) - ft_strlen(ft_itoa_base(ft_atoi(str), 16));
	if (i > 0)
	{
		if (!(tmp = (char*)malloc(i + 1)))
				return (NULL);
	}
	else
		return (ft_itoa_base(ft_atoi(str), 16));
	while (i-- > 0)
		tmp[k++] = '0';
	tmp[k] = '\0';
	str = ft_strjoin(tmp, ft_itoa_base(ft_atoi(str), 16));
	free(tmp);
	return (str);
}

static char		*substitute_str(char *str, char *res, int sub_size, int n)
{
	char		*tmp;
	int			i;
	int			k;

	k = 0;
	if (res[n - 1] == 'x' || res[n - 1] == 'X')
		str = base_appli(str);
	if (sub_size > (int)ft_strlen(str) && (res[n - 1] == 'd' || res[n - 1] == 'i' || res[n - 1] =='o'
				|| res[n - 1] == 'x' || res[n - 1] == 'X' || res[n - 1] == 'u'))
	{
		if (!(tmp = (char*)malloc(sub_size - (int)ft_strlen(str))))
			return (NULL);
		while (sub_size-- > ft_strlen(str))
			tmp[k++] = '0';
		k = 0;
		str = ft_strjoin(tmp, str);
		free(tmp);
	}
	if (g_ash == 1 && res[n - 1] == 'o')
		str = ft_strjoin("0", str);
	if (g_ash == 1 && res[n - 1] == 'x')
		str = ft_strjoin("0x", str);
	if (g_ash == 1 && res[n - 1] == 'X')
		str = ft_strjoin("0X", str);
	if (g_sign == 1 && (res[n - 1] == 'o' || res[n - 1] == 'x' || res[n  - 1] == 'X' || res[n - 1] == 'u'))
		str = ft_strjoin("+", str);
	if (g_sign == 1 && (res[n - 1] == 'd' || res[n - 1] == 'i' || res[n - 1] == 'f') && ft_atoi(str) > 0)
		str = ft_strjoin("+", str);
	if (g_space == 1 && (res[n - 1] == 'd' || res[n - 1] == 'i'))
		str = ft_strjoin(" ", str);
	str = flag_appli_str(str);
	tmp = res;
	while (tmp[k] != '%' || tmp[k + 1] == '%')
		k++;
	if (sub_size >= 0 && sub_size <= ft_strlen(str) && res[n - 1] == 's')
		str = ft_strsub(str, 0, sub_size);
	tmp = ft_strsub(tmp, 0, k);
	tmp = ft_strjoin(tmp, str);
	res = ft_strjoin(tmp, &res[n]);
	free(tmp);
	return (res);
}

static int		field_w_check(char *format, int n)
{
	if (format[n - 1] == '.' || format[n - 1] == '0' || format[n - 1] == '-'
			|| (format[n - 1] >= '0' && format[n - 1] <= '9'))
		return (-1);
	return (1);
}

static int		flag_gestion(char *format, int n)
{
	g_negpad = -1;
	g_zeropad = -1;
	g_ash = -1;
	g_len = -1;
	g_sign = -1;
	g_space = -1;
	while (format[++n] == '#' || format[n] == '-' || format[n] == '+'
			|| (format[n] >= '0' && format[n] <= '9') || format[n] == 'h' || format[n] == 'l'
			|| format[n] == ' ')
	{
		if (format[n] > '0' && format[n] <= '9' && field_w_check(format, n) == 1 && g_len == -1)
			g_len = precision_check(format, n);
		if (format[n] == '0' && g_zeropad == -1)
			g_zeropad = precision_check(format, n + 1);
	   	if (format[n] == '#')
			g_ash = 1;
		if (format[n] == ' ')
			g_space = 1;
	    if (format[n] == '-')
		{
			g_negpad = precision_check(format, n + 1);
			g_zeropad = -1;
		}
		if (format[n] == '+')
			g_sign = 1;
	}
	return (n);
}

static char		*conversion_check(char *format, va_list va, int n)
{
	int		sub_size;
	char	c;

	sub_size = -1;
	n = flag_gestion(format, n);
	if (format[n] == '.')
	{
		sub_size = precision_check(format, ++n);
		while (format[n] >= '0' && format[n] <= '9')
			n++;
		g_zeropad = -1;
	}
	if (format[n] == 'c')
	{
		c = va_arg(va, int);
		return (substitute_str(ft_strsub(&c, 0, 1), format, sub_size, ++n));
	}
	if (format[n] == 'p' && (g_ash = 1))
	{
		format[n] = 'x';
		return (substitute_str(ft_itoa(ft_abs(*va_arg(va, unsigned int*))), format, sub_size, ++n));
	}
	if (format[n] == 's')
		return (substitute_str(va_arg(va, char*), format, sub_size, ++n));
	if (format[n] == 'd' || format[n]  == 'i')
		return (substitute_str(ft_itoa(va_arg(va, int)), format, sub_size, ++n));
	if (format[n] == 'u')
		return (substitute_str(ft_itoa(ft_abs(va_arg(va, unsigned int))), format, sub_size, ++n));
	if (format[n] == 'o')
		return (substitute_str(ft_itoa_base(ft_abs(va_arg(va, unsigned int)), 8), format, sub_size, ++n));
	if (format[n] == 'x' || format[n] == 'X')
		return (substitute_str(ft_itoa(ft_abs(va_arg(va, unsigned int))), format, sub_size, ++n));
	if (format[n] == 'f')
		return (substitute_str(ft_itoafloat(va_arg(va, double), sub_size), format, sub_size, ++n));
	return (format);
}

int 			ft_printf(const char *format, ...)
{
	va_list		va;
	int			n;
	char		*res;

	g_len = -1;
	va_start(va, format);
	n = -1;
	res = ft_strdup(format);
	while (res[++n])
	{
		if (res[n] == '%' && res[n + 1] != '%' && res[n - 1] != '%')
			res = conversion_check(res, va, n);
	}
	ft_putstr(res);
	free(res);
	va_end(va);
	return (0);
}

int		main(void)
{
	ft_printf("%#096 120x", 10);
}
