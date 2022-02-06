#include <stdlib.h>
#include <unistd.h>
char *line_join(char *line, char c)
{
	char	*new;
	int i;

	i = 0;
	while (line && line[i])
		i++;
	new = malloc(sizeof(char) * (i + 2));
	if (!new)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (line && line[i])
	{
		new[i] = line[i];
		i++;
	}
	new[i++] = c;
	new[i] = 0;
	free(line);
	return (new);
}

char    *get_next_line(int fd)
{
	char	*line;
	char	c;
	int		count;

	// if (BUFFER_SIZE < 1)
	// 	return (NULL);
	line = NULL;
	count = read(fd, &c, 1);
	while (count)
	{
		line = line_join(line, c);
		if (c == '\n')
			break ;
		count = read(fd, &c, 1);
	}
	return (line);
}
