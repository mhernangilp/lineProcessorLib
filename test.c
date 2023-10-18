#include "libreria.h"

static void	exit_msg(char *msg)
{
	printf("%s\n", msg);
	exit (2);
}

int	main(int argc, char **argv)
{
	int	N;

	if (argc < 2 || argc > 3 || strncmp(argv[1], "-", 1))
		exit_msg(ERR_ARGS);
	if (argc == 3) {
		if (atoi(argv[2]) < 1)
			exit_msg(ERR_N);
		N = atoi(argv[2]);
	} else
		N = 10;
	if (!strcmp(&argv[1][1], "head"))
		head(N);
	else if (!strcmp(&argv[1][1], "tail"))
		tail(N);
	else if (!strcmp(&argv[1][1], "longlines"))
		longlines(N);
	else
		exit_msg(ERR_FUNC);
	return (0);
}
