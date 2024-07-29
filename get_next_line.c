#include "get_next_line.h"

static char *read_line(int fd, char *buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;
	if (fd <= 0)
		return (NULL);
	buffer = read_line(fd, buffer);
	return (buffer);
}

static char	*read_line(int fd, char *buffer)
{
	int	read_len;
	char	*buffer_temp;

	buffer_temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
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
