#!/bin/bash
create()
{
        mkdir -p DP/$1;
        for i in 1 2 3;do
        echo > DP/$1/f$2$i
                done
}

create "DA" "a"
create "DB" "b"
create "DC" "c"
