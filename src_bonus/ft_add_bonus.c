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

/**
 * @brief Concatenates two strings into a newly allocated string.
 * 
 * This function creates a new string by concatenating the contents of
 * two input strings. Memory is allocated for the resulting string which
 * must be freed by the caller.
 * 
 * @param s1 The first string to concatenate
 * @param s2 The second string to concatenate
 * @return char* Pointer to the newly allocated concatenated string,
 *               or NULL if memory allocation fails
 */
char	*ft_add(char *s1, char *s2)
{
	char	*line;
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
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
