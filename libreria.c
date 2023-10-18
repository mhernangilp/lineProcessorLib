#include "libreria.h"

static char	*cat_mem(char *, char *buf, int end, int readed)
{
	return NULL;
}

static char	*read_input()
{
	char	*buf;
	char	*target;
	int	readed;
	int	i;

	target = NULL;
	if (!(buf = malloc(BUFF_SIZE *  sizeof(char))))
		return (NULL);
	readed = read(0, buf, BUFF_SIZE);
	i = readed;
	while (readed) {
		if (!(target = cat_mem(target, buf, i - readed, readed))) {
			free(buf);
			free(target);
			return (NULL);
		}
		readed = read(0, buf, BUFF_SIZE);
		i += readed;
	}
	printf("%s\n", buf);
	return (NULL);
}

int	head(int N)
{
	printf("Hago head con %d lineas\n", N);
	return (0);
}

int	tail(int N)
{
	printf("Hago tail con %d lineas\n", N);
	return (0);
}

int	longlines(int N)
{
	printf("Hago longlines con %d lineas\n", N);
	return (0);
}
