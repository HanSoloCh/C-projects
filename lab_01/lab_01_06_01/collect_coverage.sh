#!/bin/bash

if [[ $(realpath "$(dirname "$0")") != "$PWD" ]]; then
	echo "Please run script from its own direcory"
	exit 1
fi

# Удаление предыдущего файла .gcda
rm -f ./*.gcda

# Компилируем программу
gcc -std=c99 -Wall -Werror -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -c -O0 -g3 --coverage main.c
gcc -o app.exe main.o --coverage -lm

# Запуск функциональных тестов
./func_tests/scripts/func_tests.sh

# Регулярным выражение получаем процент покрытия кода
coverage=$(gcov main.c | tail -1 | sed "s/.*://g" | sed "s/%.*//g")

# Выводим процент
echo -e "\n\e[35mThe lines coverage is ${coverage}%\e[0m"
