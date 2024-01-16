#!/bin/bash

#Compilación
gcc -c libreria.c -o libreria.o -Wall -Werror -Wextra
ar -rv liblibreria.a libreria.o
gcc -o test test.c -I . -L . -llibreria -Wall -Werror -Wextra

#Limpieza de objetos
rm -rf *.o
echo -e "\e[1;32mCompilation finished !\e[0m"
