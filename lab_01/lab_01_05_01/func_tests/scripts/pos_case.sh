#!/bin/bash
# Флаг -v указывает на то, что нужно печатать дополнительную информацию
VERBOSE=false
# Обработка аргументов командной строки
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

# Проверяем, что было передано ровно два аргумента
if [ $# -ne 2 ]; then
	if [ "$VERBOSE" == "true" ]; then
    		echo "Usage: $0 <input_file> <expected_output_file>"
  	fi
    exit 1
fi

input_file="$1"
expected_output_file="$2"

# Определяем путь к директории скрипта и к исполняемому файлу
script_dir=$(realpath "$(dirname "$0")")
app_path="$(realpath "$script_dir/../../app.exe")"

# Проверяем, существует ли файл входных данных
if [ ! -f "$script_dir"/../data/"$input_file" ]; then
	if [ "$VERBOSE" == "true" ]; then
    		echo "Input file $input_file not found"
  	fi
  	exit 1
fi

# Проверяем, существует ли файл эталонных выходных данных
if [ ! -f "$script_dir"/../data/"$expected_output_file" ]; then
  	if [ "$VERBOSE" == "true" ]; then
    		echo "Expected output file $expected_output_file not found"
  	fi
  	exit 1
fi
# Создаем временный файл, куда будет записан выход программы
actual_output_file="$(mktemp)"
# Запускаем программу и сохраняем ее выход в файл
"$app_path" < "$script_dir"/../data/"$input_file" > "$actual_output_file"
# Сравниваем выход программы с эталонным выходом с помощью comparator.sh
if "$script_dir"/comparator.sh "$actual_output_file" \
"$script_dir"/../data/"$expected_output_file"; then
	if [ "$VERBOSE" == "true" ]; then
		echo "Test passed"
	fi
	exit 0
else
	if [ "$VERBOSE" == "true" ]; then
		echo "Test failed"
	fi
	exit 1
fi
