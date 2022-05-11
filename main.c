#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*buf;

	fd = open("../test", O_RDONLY);
	if (fd == -1)
		printf("file open error.\n");
	else
	{
		/*
		buf = get_next_line(fd);
		printf("=> %s", buf);
		system("leaks a.out");
		buf = get_next_line(fd);
		printf("=> %s", buf);
		system("leaks a.out");
		*/
		while (1)
		{
			buf = get_next_line(fd);
			if (!buf)
			{
				close(fd);
				free(buf);
				return (0);
			}
			printf("=> %s", buf);
			free (buf);
			// system("leaks a.out");
		}
	}
}
