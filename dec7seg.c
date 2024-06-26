#include "dec7seg.h"
#include "MKL25Z4.h"
#include <stdio.h>

bool numeros[10][7] = {
    {1,1,1,1,1,1,0}, //0
    {0,1,1,0,0,0,0}, //1
    {1,1,0,1,1,0,1}, //2
    {1,1,1,1,0,0,1}, //3
    {0,1,1,0,0,1,1}, //4
    {1,0,1,1,0,1,1}, //5
    {1,0,1,1,1,1,1}, //6
    {1,1,1,0,0,0,0}, //7
    {1,1,1,1,1,1,1}, //8
    {1,1,1,0,0,1,1}  //9
}


void deco7seg(char num){
    for (int i = 0; i < 7; i++){
        PTA -> PSOR|=(numeros[(int)(num)][i]u << i);
    }
}