#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	*buf;

	fd = open("./text.txt", O_RDONLY);
	if (fd == -1)
		printf("file open error.\n");
	else
	{
		while (1)
		{
			buf = get_next_line(fd);
			if (!buf)
			{
				free(buf);
				close(fd);
				return (0);
			}
			printf("=> %s", buf);
		}
	}
}
