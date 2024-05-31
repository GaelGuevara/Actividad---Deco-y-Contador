#include "deg7seg.h"
#include "T_Matricial.h"
#include "MKL25Z4.h"
#define btnPin 32
#define output 4
int bc1[output] = {1,2,3,4};
int bc2[output] = {5,6,7,8};
bool estados[10][4] = {
    {0,0,0,0},
    {0,0,0,1},
    {0,0,1,0},
    {0,0,1,1},
    {0,1,0,0},
    {0,1,0,1},
    {0,1,1,0},
    {0,1,1,1},
    {1,0,0,0},
    {1,0,0,1}    
}

int main(){
    SIM -> SCGC5|=SIM_SCGC5_PORTA_MASK;
    for (int i = 0; i < output; i++){
        PORTA -> PCR[bc1[i]]|= PORT_PCR_MUX(1);
        PORTA -> PCR[bc2[i]]|= PORT_PCR_MUX(1);
    }
    PORTA -> PCR[btnPin]|= PORT_PCR_MUX(0);
    int cont1 = 0, cont2 = 0;
    while (1){
        int btn = PTA -> PDIR&(1<<btnPin);
        if (btn){
            for(int i=0;i<10;i++){
                for (int j = 0; j < output; j++){
                    PTA -> PSOR|=(estados[i][j]<<bc1[j]);
                }
                if(i==9){
                    cont2++;
                    for (int j = 0; j < output; j++){
                        PTA -> PSOR|=(estados[cont2][j]<<bc1[j]);
                    }
                    i=0;    
                } 
            }
        }else{
            for(int i=10;i>0;i--){
                for (int j = 0; j < output; j++){
                    PTA -> PSOR|=(estados[i][j]<<bc1[j]);
                }
                if(i==1){
                    cont2--;
                    for (int j = 0; j < output; j++){
                        PTA -> PSOR|=(estados[cont2][j]<<bc1[j]);
                    }
                    i=0;    
                }       
            }
        }
    }    
}