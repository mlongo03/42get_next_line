#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int	fd = open("./test.txt", 0);
	char *res = get_next_line(fd);
	int	 i;
	printf("%s", res);
	while (res && *res)
	{
		res = get_next_line(fd);
		if (res)
			printf("%s", res);
	}
	return 0;
}
