#!/bin/bash
dir_depth(){

    local dir
    cd "$1"                                                                                              #moverse al directorio dado
    ((counter++))                                                                                        #sumar el nivel de profundidad ahora, para cuando se llame en la linea 12 

    for dir in *                                                                                         #para todos los archivos del directorio dado
    do
      if [ -d "$dir" ]                                                                                   #si se trata de un directorio
      then
        dir_depth "$dir"                                                                                 #seguimos bajando
      fi
    done
    if ((counter > max))                                                                                 #entra aqui cuando no hay mas directorios. max siendo 0 de base, entrara a la condicional
    then
        max=$counter                                                                                     #y asignamos el contador actual (el maximo encontrado en esta subcarpeta) a max
    fi

    ((counter--))                                                                                        #reasignamos el valor del counter acorde al cd ..
    if (( counter == 0 ))                                                                                #hasta llegar al dir inicial 
    then
        echo $max
        unset counter      
    else
        cd ..  
    fi
}

dir_depth $1
