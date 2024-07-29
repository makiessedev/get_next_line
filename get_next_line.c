#include "get_next_line.h"

static char	*read_line(int fd, char *buffer);
static char	*get_first_line(char *buffer, char *line);
static char	*without_first_line(char *buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*line;

	if (fd <= 0)
		return (NULL);
	buffer = read_line(fd, buffer);
	line = NULL;
	line = get_first_line(buffer, line);
	buffer = without_first_line(buffer);
	return (line);
}

static char	*read_line(int fd, char *buffer)
{
	int	read_len;
	char	*buffer_temp;

	buffer_temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer_temp == NULL)
		return (NULL);
	read_len = 1;
	while (ft_strchr(buffer, '\n') == NULL && read_len != 0)
	{
		read_len = read(fd, buffer_temp, BUFFER_SIZE);
		if (read_len < 0)
		{
			free(buffer_temp);
			return (NULL);
		}
		buffer_temp[read_len] = '\0';
		buffer = ft_strjoin(buffer, buffer_temp);
	}
	free(buffer_temp);
	return (buffer);
}

static char	*get_first_line(char *buffer, char *line)
{
	int	count;

	count = 0;
	while (buffer[count] != '\0' && buffer[count] != '\n')
		++count;
	line = (char *)malloc(sizeof(char) * (count + 1));
	if (line == NULL)
		return (NULL);
	count = 0;
	while (buffer[count] && buffer[count] != '\n')
	{
		line[count] = buffer[count];
		++count;
	}
	line[count] = '\0';
	return (line);
}

static char	*without_first_line(char *buffer)
{
	int	rest_init;
	int	count;
	char	*rest;

	rest_init = 0;
	count = 0;
	while (buffer[rest_init] && buffer[rest_init] != '\n')
		rest_init++;
	if (buffer[rest_init] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	rest = (char *)malloc(sizeof(char) * ft_strlen(buffer + rest_init));
	if (rest == NULL)
		return (NULL);
	rest_init++;
	while (buffer[rest_init + count])
	{
		rest[count] = buffer[rest_init + count];
		count++;
	}
	rest[count] = '\0';
	free(buffer);
	return (rest);
}
