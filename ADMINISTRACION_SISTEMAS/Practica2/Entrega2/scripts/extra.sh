#!/bin/bash

print_base_menu() {
    echo "Select an option: "
    echo "A>> Uso de recursos"
    echo "B>> Conectividad"
    echo "C>> Información general"
    echo "D>> Salir"
}
print_A_menu() {
    echo "Select an option: "
    echo "1>> Uso de CPU"
    echo "2>> Uso de Memoria"
    echo "3>> Uso de Disco"
    echo "4>> Volver"
}
show_cpu() {
    top -bn1 | grep load | awk '{printf "CPU Load: %.2f\n", $(NF-2), usage }'
}
show_memory() {
    free -m | awk 'NR==2{printf "Memory Usage: %s/%sMB (%.2f%%)\n", $3,$2,$3*100/$2 }'
}
show_disk() {
    df -h | awk '$NF=="/"{printf "Disk Usage: %d/%dGB (%s)\n", $3,$2,$5}'
}
print_B_menu() {
    echo "Select an option: "
    echo "1>> Listado de interfaces"
    echo "2>> IPs asignadas"
    echo "3>> Volver"
}
list_interfaces() {
    interfaces=$(ifconfig | cut -d ' ' -f1)
    echo $interfaces
}
assigned_ips() {
    ips=$(ip addr | awk '/inet/ {print $2}' | grep -v ^::1)
    echo $ips
}
print_C_menu() {
    echo "Select an option: "
    echo "1>> Usuario actual"
    echo "2>> Sistema operativo actual"
    echo "3>> Volver"
}
show_curren_user() {
    echo "$USER"
}
show_current_so() {
    echo $(uname -o)
}
EXIT=false
while [ $EXIT = false ]; do
    print_base_menu
    read -r selected
    case $selected in
    "A")
        clear
        RETURN=false
        while [ $RETURN = false ]; do
            print_A_menu
            read -r selected
            case $selected in
            "1") show_cpu ;;
            "2") show_memory ;;
            "3") show_disk ;;
            "4") RETURN=true ;;
            esac
            sleep 1
            clear
        done
        ;;
    "B")
        clear
        RETURN=false
        while [ $RETURN = false ]; do
            print_B_menu
            read -r selected
            case $selected in
            "1") list_interfaces ;;
            "2") assigned_ips ;;
            "3") RETURN=true ;;
            esac
            sleep 1
            clear
        done
        ;;
    "C")
        clear
        RETURN=false
        while [ $RETURN = false ]; do
            print_C_menu
            read -r selected
            case $selected in
            "1") show_curren_user ;;
            "2") show_current_so ;;
            "3") RETURN=true ;;
            esac
            sleep 1
            clear
        done
        ;;
    "D")
        EXIT=true
        ;;
    "*") ;;

    esac
    sleep 1
    clear
done
