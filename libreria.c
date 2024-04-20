#include "libreria.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFF_SIZE 1024

static int	add_line_tail(char **lines, char *input, int read, int N);
static int	add_line_long(char **lines, char *input, int N);
static void	free_lines(char **lines);

int	head(int N)
{
	char	line[BUFF_SIZE];

	//Mostramos cada linea leida
	while (N > 0 && fgets(line, BUFF_SIZE, stdin))
	{
		printf("%s", line);
		N--;
	}
	return (0);
}

int	tail(int N)
{
	char	input[BUFF_SIZE];
	char	**lines;
	int	read = 0;
	int	i;

	//Asignamos memoria y comprobamos errores de memoria
	lines = malloc((N + 1) * sizeof(char *));
	if (!lines)
		return (2);
	lines[N] = NULL;

	//Leemos las lineas y las vamos asignando
	while (fgets(input, BUFF_SIZE, stdin)) {
		read++;
		if (add_line_tail(lines, input, read, N))
			return (2);
	}

	//Mostramos las ultimas lineas leidas
	i = -1;
	while (++i < read && lines[i]) {
		printf("%s", lines[i]);
	}

	//Liberamos memoria
	free_lines(lines);
	return (0);
}

static int	add_line_tail(char **lines, char *input, int read, int N)
{
	int	i = 0;

	if (read <= N) {
		lines[read - 1] = strdup(input);
		if (!lines[read - 1])
			return (1);
	} else {
		free(lines[0]);
		while (lines[i + 1]) {
			lines[i] = lines[i + 1];
			i++;
		}
		lines[i] = strdup(input);
		if (!lines[i])
			return (1);
	}
	return (0);
}

int	longlines(int N)
{
	char	input[BUFF_SIZE];
	char	**lines;
	int	i;

	//Asignamos memoria y comprobamos errores de memoria
	lines = malloc((N + 1) * sizeof(char *));
	if (!lines)
		return (2);
	i = -1;
	while (++i < N)
		lines[i] = strdup("");
	lines[N] = NULL;

	//Leemos las lineas y las vamos asignando con el algoritmo
	while (fgets(input, BUFF_SIZE, stdin)) {
		if (add_line_long(lines, input, N))
			return (2);
	}

	//Mostramos las lineas mas largas
	i = -1;
	while (lines[++i]) {
		printf("%s", lines[i]);
	}

	//Liberamos memoria
	free_lines(lines);
	return (0);
}

static int	add_line_long(char **lines, char *input, int N)
{
	int	i = -1;
	int	end = N;

	while (++i < N) {
		if (strlen(lines[i]) < strlen(input)) {
			free(lines[--end]);
			while (--end >= i)
				lines[end + 1] = lines[end];
			lines[i] = strdup(input);
			if (!lines[i])
				return (1);
			return (0);
		}
	}
	return (0);
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
