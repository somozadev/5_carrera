#!/bin/bash
founded_user=false
for name in $(cut -d: -f 1 /etc/passwd); do
if [[ $name == $1 ]]; then
        founded_user=true
    fi
done

if [[ $founded_user == true ]]; then
        echo "SI"
else
        echo "NO"
fi


