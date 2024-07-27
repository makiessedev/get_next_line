/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorais <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:07:16 by mmorais           #+#    #+#             */
/*   Updated: 2024/07/27 17:15:06 by mmorais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
		++count;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *next_lines, char *temp)
{
	char	*joined;
	int	next_lines_len;
	int	temp_len;
	int	count;

	next_lines_len = ft_strlen(next_lines);
	temp_len = ft_strlen(temp);
	joined = (char *)malloc((next_lines_len + temp_len + 1) * sizeof(char));
	count = 0;
	while (next_lines[count])
	{
		joined[count] = next_lines[count];
		count++;
	}
	count = 0;
	while (temp[count])
	{
		joined[next_lines_len + count] = temp[count];
		count++;
	}
	joined[next_lines_len + count] = '\0';
	return (joined);
}
