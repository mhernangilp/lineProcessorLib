#!/bin/bash

#Compilación
gcc -c libreria.c -o libreria.o
ar -rv liblibreria.a libreria.o
gcc -o test test.c -L ./ -llibreria -Wall -Werror -Wextra #-g3 -fsanitize=address

#Limpieza de objetos
rm -rf *.a *.o
echo -e "\e[1;32mCompilation finished !\e[0m"
