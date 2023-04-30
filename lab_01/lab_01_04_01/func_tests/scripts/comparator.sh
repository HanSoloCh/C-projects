#!/bin/bash
# Проверяем, что скрипту передаются два аргумента
if [ $# -ne 2 ]; then
	exit 1
fi

# Задаем переменные для путей к файлам с выходными данными
programm_output="$1"
test_output="$2"

# Задаем регулярное выражение
mask="[+-]?[0-9]*/.?[0-9]*"

# Ищем по маске результат в фалйах
result_programm_output=$(grep -Eo "$mask" "$programm_output")
result_test_output=$(grep -Eo "$mask" "$test_output")

# Сравниваем результаты и выходим с соответствующим кодом возврата
if [ "$result_programm_output" == "$result_test_output" ]; then
	exit 0
else
	exit 1
fi

