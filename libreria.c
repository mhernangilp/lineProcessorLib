#include "libreria.h"

static char	**split_lines(char *input);
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
	char	**lines;

	printf("Hago tail con %d lineas\n", N);
	if (!(input = read_input()))
		return (-1);
	printf("%s", input);
	if (!(lines = split_lines("ola marcos\nesta es una\nprueba para\n ver quetal\n")))
		return (-1);
	free(input);
	return (0);
}

int	longlines(int N)
{
	printf("Hago longlines con %d lineas\n", N);
	return (0);
}

//Splits the input in multiple strings separated by '\n', terminating in NULL
static char **split_lines(char *input)
{
    char    **lines;
    char    *buf, *token, *p;
    char    *delimit = "\n";
    int     num_lineas, i;

    if (!(buf = strdup(input)))
    {
        free(buf);
        return (NULL);
    }
    // buf = input;

    // Para contar el numero de lineas que tiene el input (el buf)
    while (*buf) {
        if (*buf == '\n') {
            num_lineas++;
        }
        buf++;
    }

    if (!(p = strdup(input)))
    {
        free(p);
        return (NULL);
    }

    // Declaro token, que guardara las distintas lineas de la entrada y las ira pasando a lines
    token = strtok(p, delimit);
    if (!token)
    {
        free(token);
        return(NULL);
    }
    num_lineas = 1;
    i = 0;

    // Reservo memoria para lines (para los primeros huecos de puntero)
    if(!(lines = (char **)calloc((num_lineas + 1), sizeof(char *)))) {
        free(lines);
        free(token);
        return (NULL);
    }

    // Mientras exista token, hago una copia de token y la asigno al espacio de memoria reservado de lines correspondiente
    while (token)
    {
        //printf("TOKEN %d: '%s'", i, token);
        if(!(lines[i] = strdup(token))) {
            for (int j = 0; j < i; j++) {
                free(lines[j]);
            }
            free(buf);
            return(NULL);
        }
        printf("LINES[%d]: '%s'", i, lines[i]);

        token = strtok(NULL, delimit);
        i++;
    }
	
	//printf("LINEA 1: %s, LINEA 2: %s, LINEA 3: %s", lines[0], lines[1], lines[2]);

    printf("\n------------------------------\n");
    for (int k = 0; k < i; k++)
    {
        printf("Linea[%d]: %s", k, lines[k]);
    }
    
    printf("\n------------------------------\n");

    lines[i] = NULL;
    free(token);
    return (lines);
}
//Reads the input using a temporal buffer, returns a string with the input
static char	*read_input()
{
	char	*buf;
	char	*target;
	int	readed;

	if(!(target = strdup("")))
		return (NULL);
	if (!(buf = malloc(BUFF_SIZE *  sizeof(char))))
		return (NULL);
	do {
		readed = read(0, buf, BUFF_SIZE);
		if (readed) {
			if (!(target = cat_mem(target, buf, readed))) {
				free(buf);
				free(target);
				return (NULL);
			}
		}
	} while (readed);
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
