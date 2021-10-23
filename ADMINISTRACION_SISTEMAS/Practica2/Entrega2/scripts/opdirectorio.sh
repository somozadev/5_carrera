#!/bin/bash
delete_specific_extension() {
    echo "Set extension: "
    read -r extension
    find "$1" -type f -name "*.$extension" -delete
}
delete_files_type_o() {
    find "$1" -type f -name "*.o" -delete
}
delete_files_zero_size() {
    find "$1" -type f -size 0b -delete
}
list_content_in_dir() {
    echo "parent: $PWD"
    for item in $(ls "$1"); do
        echo "$item"
    done
}
print_base_menu() {
    echo "Select an option: "
    echo "1>> Listar contenido en dir dado"
    echo "2>> Eliminar los archivos de tamaño 0"
    echo "3>> Eliminar los archivos de tipo objeto (*.o)"
    echo "4>> Eliminar con una extensión concreta"
    echo "5>> Salir"
}
check_dir() {
    echo "Set directory:"
    read -r readed
    if [ -d "$readed" ]; then
        dir="$readed"
    else
        dir="."
    fi
}

EXIT=false
dir=.
while [ $EXIT = false ]; do
    print_base_menu
    read -r selected
    case $selected in
    "1")
        check_dir
        list_content_in_dir "$dir"
        ;;
    "2")
        check_dir
        delete_files_zero_size "$dir"
        ;;
    "3")
        check_dir
        delete_files_type_o "$dir"
        ;;
    "4")
        check_dir
        delete_specific_extension "$dir"
        ;;
    "5")
        EXIT=true
        ;;
    "*") ;;

    esac
    sleep 1
    clear
done
