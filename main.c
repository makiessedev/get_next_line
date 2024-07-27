#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	FILE *file = fopen("file", "r");
	printf("%s", get_next_line(fileno(file)));
	return (0);
}
