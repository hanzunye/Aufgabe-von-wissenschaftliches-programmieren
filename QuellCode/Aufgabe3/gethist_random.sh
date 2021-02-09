#!/bin/bash


awk '{print (int($0/2)*2+1)}' ./ergebnis_random.dat > hist_ran.dat


for i in $(seq 1 2 359);
do
{
    echo -n $i;
    echo -n "  ";
    gawk -v nvar=$i '($1==nvar){SUM=SUM+1} END{print SUM/NR}' hist_ran.dat

}>>hist_random.dat

done