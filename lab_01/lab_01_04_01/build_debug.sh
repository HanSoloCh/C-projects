#!/bin/bash

# Проверяем, что скрипт запущен из его собственной директории
if [[ $(realpath "$(dirname "$0")") != "$PWD" ]]; then
	echo "Please run script from its own direcory"
else
	gcc -std=c99 -Wall -Werror -Wextra -Wfloat-equal -Wfloat-conversion -Wvla \
	-c -O0 -g3 main.c
	gcc -o app.exe main.o -lm
fi
