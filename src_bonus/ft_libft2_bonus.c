/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:38:32 by isainz-r          #+#    #+#             */
/*   Updated: 2024/05/16 16:22:55 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t	ft_strlen2(const char *s)
{
	size_t	i;

	i = 0;
	if (!s || !s[0])
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin2(char const *s1, char const s2)
{
	char	*resultado;
	size_t	i;
	size_t	j;
	size_t	len_s1;

	i = 0;
	j = 0;
	len_s1 = ft_strlen2(s1);
	resultado = ft_calloc(len_s1 + 1 + 1, 1);
	if (!resultado)
		return (NULL);
	while (i < len_s1 && s1[0] != '\0')
		resultado[j++] = s1[i++];
	i = 0;
	if (s2)
		resultado[j++] = s2;
	return (resultado);
}

char	*ft_add(char *s1, char *s2)
{
	char	*line;
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;

	len_s1 = ft_strlen2(s1);
	len_s2 = ft_strlen2(s2);
	i = 0;
	j = 0;
	line = ft_calloc(len_s1 + len_s2 + 1, 1);
	if (!line)
		return (NULL);
	while (i < len_s1)
		line[j++] = s1[i++];
	i = 0;
	while (i < len_s2)
		line[j++] = s2[i++];
	return (line);
}

void	ft_putnbr(int number)
{
	int	div_n;
	int	to_write;

	if (number == INT_MIN)
		write(1, "-2147483648", 11);
	if (number > INT_MIN && number <= INT_MAX)
	{
		if (number < 0)
		{
			number = -number;
			write(1, "-", 1);
		}
		div_n = number / 10;
		if (number >= 10)
			ft_putnbr(div_n);
		to_write = ((number % 10) + '0');
		write(1, &to_write, 1);
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
