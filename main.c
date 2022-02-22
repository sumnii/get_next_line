#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int		fd;
	char	*buf;
	
	fd = open("./text.txt", O_RDONLY);
	if (fd == -1)
		printf("file open error.\n");
	else
	{
		buf = get_next_line(fd);
		printf("1 : \"%s\"\n", buf);
		buf = get_next_line(fd);
		printf("2 : \"%s\"\n", buf);
		buf = get_next_line(fd);
		printf("3 : \"%s\"\n", buf);
	}
	free(buf);
	close(fd);
	return (0);
}