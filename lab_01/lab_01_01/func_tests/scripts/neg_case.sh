#!/bin/bash

VERBOSE=false

# Обработка флага -v для включения режима verbose
while getopts ":v" opt; do
	case ${opt} in
  		v )
  			VERBOSE=true
  	  		;;
  		\? )
  	  		exit 1
  	  		;;
  	esac
done

# Сдвигаем аргументы командной строки так, чтобы остались только имена файлов
shift $((OPTIND -1))

# Проверяем, что количество аргументов равно 1
if [ $# -ne 1 ]; then
	if [ "$VERBOSE" == "true" ]; then
		echo "Usage: $0 <input_file>"
	fi
	exit 1
fi

input_file="$1"

# Определяем путь к директории скрипта и к исполняемому файлу
script_dir=$(realpath "$(dirname "$0")")
app_path="$(realpath "$script_dir/../../app.exe")"

# Проверяем, существует ли файл входных данных
if [ ! -f "$script_dir"/../data/"$input_file" ]; then
	if [ "$VERBOSE" == "true" ]; then
		echo "File $input_file not found"
	fi
	exit 1
fi

# Запускаем программу и перенаправляем ее выход
"$app_path" < "$script_dir"/../data/"$input_file" >/dev/null

# Получаем код возврата
code_return=$?

# Обрабатываем код возврата
if [ "$code_return" -eq 0 ]; then
	if [ "$VERBOSE" == "true" ]; then
		echo "Test failed"
	fi
	exit 1
	
else
	if [ "$VERBOSE" == "true" ]; then
		echo "Test passed"
	fi
	exit 0	
fi
