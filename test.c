#include "libreria.h"
#define ERR_ARGS "Usage: test -<function> [numero de lineas]"
#define ERR_N "[numero de lineas] not valid"
#define ERR_FUNC "<function> not valid: '-head', '-tail' or '-longlines'"

static void	exit_msg(char *msg)
{
	printf("%s\n", msg);
	exit (2);
}

int	main(int argc, char **argv)
{
	int	N;

	if (argc < 2 || argc > 3)
		exit_msg(ERR_ARGS);
	if (argc == 3) {
		if (atoi(argv[2]) < 1)
			exit_msg(ERR_N);
		N = atoi(argv[2]);
	} else
		N = 10;
	if (!strcmp(argv[1], "-head"))
		head(N);
	else if (!strcmp(argv[1], "-tail"))
		tail(N);
	else if (!strcmp(argv[1], "-longlines"))
		longlines(N);
	else
		exit_msg(ERR_FUNC);
	return (0);
}
