#include "libreria.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFF_SIZE 10

static void	print_head(char **lines, int N, int max);
static void	print_tail(char **lines, int N, int max);
static int	lines_length(char **lines);
static char	**split_lines(char *input);
static char	*read_input();
static char	*cat_mem(char *s1, char *buf, int readed);
static void	free_lines(char **lines);
static void	bubbleSort(char **lines, int n);

int	head(int N)
{
	char	*input;
	char	**lines;
	int	max;

	//Leemos por pantalla y separamos las lineas
	if (!(input = read_input()))
		return (2);
	if (!(lines = split_lines(input)))
		return (3);

	//Ejecutamos la funcionalidad principal
	max = lines_length(lines);
	print_head(lines, N, max);

	//Liberamos todo
	free(input);
	free_lines(lines);
	return (0);
}

int	tail(int N)
{
	char	*input;
	char	**lines;
	int	max;

	//Leemos por pantalla y separamos las lineas
	if (!(input = read_input()))
		return (2);
	if (!(lines = split_lines(input)))
		return (3);

	//Ejecutamos la funcionalidad principal
	max = lines_length(lines);
	print_tail(lines, N, max);
	
	//Liberamos todo
	free(input);
	free_lines(lines);
	return (0);
}

int	longlines(int N)
{
	char	*input;
	char	**lines;
	int	max;

	//Leemos por pantalla y separamos las lineas
	if (!(input = read_input()))
		return (2);
	if (!(lines = split_lines(input)))
		return (3);
	
	//Ejecutamos la funcionalidad principal
	max = lines_length(lines);
	bubbleSort(lines, max);
	print_head(lines, N, max);
	
	//Liberamos todo
	free(input);
	free_lines(lines);
	return (0);
}

//Ordena las lineas segun su tamaño
static void bubbleSort(char **lines, int n)
{
	char	*aux;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (strlen(lines[j]) < strlen(lines[j + 1])) {
				aux = lines[j + 1];
				lines[j + 1] = lines[j];
				lines[j] = aux;
			}
		}
	}
}

//Printea las lineas en caso de "head" (longlines también)
static void	print_head(char **lines, int N, int max)
{
	int	i;

	i = 0;
	while (i < N && i < max)
		printf("%s", lines[i++]);
}

//Printea las lineas en caso de "tail"
static void print_tail(char **lines, int N, int max)
{
	int     i;

	i = max - N;
	if (i < 0)
		i = 0;
	while (lines[i])
	{
		printf("%s", lines[i]);
		i++;
	}
}

//Devuelve el numero de lineas que contiene "lines"
static int lines_length(char **lines)
{
	int     m;

	m = 0;
	while (lines[m])
		m++;
	return(m);
}

//Separa el input en multiples strings separados por '\n', terminando en NULL
static char **split_lines(char *input)
{
	char    **lines;
	char    *buf, *token, *p;
	char    *delimit = "\n";
	int     num_lineas, i;

	// Inicializo bufer apuntando a input, num_lineas e i
	buf = input;
	num_lineas = 1;
	i = 0;

	// Para contar el numero de lineas que tiene el input (el buf)
	while (*buf) {
		if (*buf == '\n') {
			num_lineas++;
		}
		buf++;
	}

	if (!(p = strdup(input))) {
		free(p);
		return (NULL);
	}

	// Declaro token, que guardara las distintas lineas de la entrada y las ira pasando a lines
	token = strtok(p, delimit);
	if (!token)
		return(NULL);

	// Reservo memoria para lines (para los primeros huecos de puntero)
	if(!(lines = (char **)calloc((num_lineas + 1), sizeof(char *)))) {
		free(lines);
		return (NULL);
	}

	// Mientras exista token, hago una copia de token y la asigno al espacio de memoria reservado de lines correspondiente
	while (token) {
		if(!(lines[i] = strdup(token))) {
			for (int j = 0; j < i; j++) {
				free(lines[j]);
			}
			return(NULL);
		}
		lines[i] = cat_mem(lines[i], "\n", 1);
		token = strtok(NULL, delimit);
		i++;
	}

	lines[i] = NULL;
	free(p);
	return (lines);
}

//Lee de entrada standar usando un buffer temporal, devuelve un string con lo que ha leido
static char	*read_input()
{
	char	*buf;
	char	*target;
	int	readed;

	//Inicializamos el string que vamos a devolver y el buffer
	if(!(target = strdup("")))
		return (NULL);
	if (!(buf = malloc(BUFF_SIZE *  sizeof(char))))
		return (NULL);

	//Leemos en bucle hasta que se cierre la entrada estandar
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

//Concatena el string "s1" y "buf"
static char	*cat_mem(char *s1, char *buf, int readed)
{
	char	*target;
	int	i,j;

	//Asignamos memoria dinamica al string que vamos a devolver
	if (!(target = malloc((strlen(s1) + readed + 1) * sizeof(char))))
		return (NULL);
	i = -1;

	//Concatenamos
	while (s1[++i])
		target[i] = s1[i];
	j = -1;
	while (++j < readed)
		target[i++] = buf[j];
	target[i] = '\0';
	free(s1);
	return target;
}

//Libera completamente la variable "lines"
static void	free_lines(char **lines)
{
	int	i;

	i = -1;
	while (lines[++i])
		free(lines[i]);
	free(lines);
}
