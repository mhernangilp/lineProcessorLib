#include "libreria.h"

static char	*read_input();
static char	*cat_mem(char *s1, char *buf, int readed);

int	head(int N)
{
	printf("Hago head con %d lineas\n", N);
	return (0);
}

int	tail(int N)
{
	char	*input;

	printf("Hago tail con %d lineas\n", N);
	if (!(input = read_input()))
		return (-1);
	return (0);
}

int	longlines(int N)
{
	printf("Hago longlines con %d lineas\n", N);
	return (0);
}

//Reads the input using a temporal buffer, returns a string with the input
static char	*read_input()
{
	char	*buf;
	char	*target;
	int	readed;
	int	i;

	if(!(target = strdup("")))
		return (NULL);
	if (!(buf = malloc(BUFF_SIZE *  sizeof(char))))
		return (NULL);
	readed = read(0, buf, BUFF_SIZE);
	i = readed;
	while (readed) {
		if (!(target = cat_mem(target, buf, readed))) {
			free(buf);
			free(target);
			return (NULL);
		}
		readed = read(0, buf, BUFF_SIZE);
		i += readed;
	}
	free(buf);
	return (target);
}

//Concatenates the data in 's1' and 'buf' using dynamic memory and returns it
static char	*cat_mem(char *s1, char *buf, int readed)
{
	char	*target;
	int	i,j;

	//printf("----Tenemos ya '%s', malloc de %d con %d readed----\n", s1, (int)strlen(s1) + readed, readed);
	if (!(target = malloc((strlen(s1) + readed + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (s1[++i])
		target[i] = s1[i];
	j = -1;
	while (++j < readed)
		target[i++] = buf[j];
	target[i] = '\0';
	free(s1);
	return target;
}
