#include "libreria.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define ERR_ARGS "Usage: test -<function> [numero de lineas]"
#define ERR_N "[numero de lineas] not valid"
#define ERR_FUNC "<function> not valid: '-head', '-tail' or '-longlines'"

static void	exit_msg(char *msg);

int	main(int argc, char **argv)
{
	int	N;

	if (argc < 2 || argc > 3)
		exit_msg(ERR_ARGS);
	if (argc == 3) {
		if ((N = atoi(argv[2])) < 1)
			exit_msg(ERR_N);
	} else
		N = 10;
	if (!strcmp(argv[1], "-head"))
		return (head(N));
	if (!strcmp(argv[1], "-tail"))
		return (tail(N));
	if (!strcmp(argv[1], "-longlines"))
		return (longlines(N));
	exit_msg(ERR_FUNC);
}

static void	exit_msg(char *msg)
{
	printf("%s\n", msg);
	exit (1);
}
