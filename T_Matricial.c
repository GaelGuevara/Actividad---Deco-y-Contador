#include "T_Matricial.h"
#include "MKL25Z4.h"
#include <ctype.h>

#define Ncolum 4
#define Nrows 4

int colum[Ncolum]={0,1,2,3};
int rows[Nrows]={4,5,6,7};
char keys[Nrows][Ncolum] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

void init_Keyboard(char Puerto){
    char puerto = tolower(Puerto);
    switch (puerto){
        case 'a':
            SIM->SCGC5|= SIM_SCGC5_PORTA_MASK; 
            for (int i = 0; i < 4; i++){
                PORTA -> PCR[rows[i]]|= PORT_PCR_MUX(1);
                PORTA -> PCR[colum[i]]|=PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
                PTA -> PSOR|= (1<<rows[i])
            }
        break;
        case 'b':
            SIM->SCGC5|= SIM_SCGC5_PORTB_MASK; 
            for (int i = 0; i < 4; i++){
                PORTB -> PCR[rows[i]]|= PORT_PCR_MUX(1);
                PORTB -> PCR[colum[i]]|=PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
                PTB -> PSOR|= (1<<rows[i]);
            }
        break;
        case 'c':
            SIM->SCGC5|= SIM_SCGC5_PORTC_MASK; 
            for (int i = 0; i < 4; i++){
                PORTC -> PCR[rows[i]]|= PORT_PCR_MUX(1);
                PORTC -> PCR[colum[i]]|=PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
                PTC -> PSOR|= (1<<rows[i]);
            }
        break;
        case 'd':
            SIM->SCGC5|= SIM_SCGC5_PORTD_MASK; 
            for (int i = 0; i < 4; i++){
                PORTD -> PCR[rows[i]]|= PORT_PCR_MUX(1);
                PORTD -> PCR[colum[i]]|=PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
                PTD -> PSOR|= (1<<rows[i]);
            }
        break;
        case 'e':
            SIM->SCGC5|= SIM_SCGC5_PORTE_MASK; 
            for (int i = 0; i < 4; i++){
                PORTE -> PCR[rows[i]]|= PORT_PCR_MUX(1);
                PORTE -> PCR[colum[i]]|=PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
                PTE -> PSOR|= (1<<rows[i]);
            }
        break;
   } 
}

char read_Keyboard(char Puerto){
    char puerto = tolower(Puerto);
    switch (puerto){
    case 'a':
        for (int i = 0; i < Nrows; i++){
            PTA -> PSOR|= (0<<rows[i]);
            for (int j = 0; j < Ncolum; j++){
                if (!(PTA -> PDIR&(1<<colum[j]))){
                    return keys[i][j];   
                }
            }
            PTA -> PSOR|= (1<<rows[i]);
        }
    break;
    case 'b':
        for (int i = 0; i < Nrows; i++){
            PTB -> PSOR|= (0<<rows[i]);
            for (int j = 0; j < Ncolum; j++){
                if (!(PTB -> PDIR&(1<<colum[j]))){
                    return keys[i][j];   
                }
            }
            PTB -> PSOR|= (1<<rows[i]);
        }
    break;
    case 'c':
        for (int i = 0; i < Nrows; i++){
            PTC -> PSOR|= (0<<rows[i]);
            for (int j = 0; j < Ncolum; j++){
                if (!(PTC -> PDIR&(1<<colum[j]))){
                    return keys[i][j];   
                }
            }
            PTC -> PSOR|= (1<<rows[i]);
        }
    break;
    case 'd':
        for (int i = 0; i < Nrows; i++){
            PTD -> PSOR|= (0<<rows[i]);
            for (int j = 0; j < Ncolum; j++){
                if (!(PTD -> PDIR&(1<<colum[j]))){
                    return keys[i][j];   
                }
            }
            PTD -> PSOR|= (1<<rows[i]);
        }
    break;
    case 'e':
        for (int i = 0; i < Nrows; i++){
            PTE -> PSOR|= (0<<rows[i]);
            for (int j = 0; j < Ncolum; j++){
                if (!(PTE -> PDIR&(1<<colum[j]))){
                    return keys[i][j];   
                }
            }
            PTE -> PSOR|= (1<<rows[i]);
        }
    break;
    }
}