#!/bin/bash

# Проверяем, запущен ли скрипт из его собственной директории
if [[ $(realpath "$(dirname "$0")") != "$PWD" ]]; then
	echo "Please run script from its own direcory"
else
	clang -std=c99 -Wall -Wextra -Wfloat-equal -Wfloat-conversion -Wvla \
	-fsanitize=address -fno-omit-frame-pointer -O0 -c -g3 main.c
	clang -o app.exe main.o -fsanitize=address -lm
fi



