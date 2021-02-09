#!/bin/bash


awk '{print ((int($0*5)*2+1)/10)}' ./ergebnis_cube.dat > hist_cu.dat

for i in $(seq 0.1 0.2 45.1);
do
{
    echo -n $i;
    echo -n "  ";
    gawk -v nvar=$i '($1==nvar){SUM=SUM+1} END{print SUM/NR}' hist_cu.dat

}>>hist_cube.dat

done

