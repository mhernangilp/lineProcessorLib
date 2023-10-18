#ifndef _LIBRERIA_H
#define _LIBRERIA_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define ERR_ARGS "Usage: test -<function> [numero de lineas]"
#define ERR_N "[numero de lineas] not valid"
#define ERR_FUNC "<function> not valid: '-head', '-tail' or '-longlines'"

int	head(int N);
int	tail(int N);
int	longlines(int N);

#endif
