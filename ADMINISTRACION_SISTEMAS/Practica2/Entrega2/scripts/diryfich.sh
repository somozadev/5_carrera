#!/bin/bash
counter=0
incrementer=1
print_files() {
    for i in $(find $1 -type f -name "*.$2"); do
      ((counter+=incrementer))
    done
echo "hay $counter ficheros con la extension $2"
}

if [ -d "$1" ]; then
    echo "Directorio $1 encontrado :)"
    echo "************************** "
    print_files $1 $2

else
    echo "Directorio $1 no encontrado :("
    echo "******************************"
    print_files . $2

fi
