

//testar
// CONFIG



// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <stdio.h>
#include <stdlib.h>


#include <xc.h>


#define _XTAL_FREQ 16000000 //define a frequencia do clock, deve ser o mesmo valor do cristal

void main(void) {
    
    //registrador para redirecionamento dos pinos
    
    //TRISA/B = 0/1; => todos os pinos A/B sao de entrada/saida
    
    //para especificar qual porta dos conjuntos de pinos a e b eu quero usar
    //eu uso TRISA/Bbits.TRISA/Bnumero_do_pino = 0/1
    //ou só TRISA/Bnumero_do_bit
    
    TRISBbits.TRISB6 = 0;               //direciona o pino 6 da porta b como saida 
    
    //PORTA/B.R_A/B_numero_da_porta = 0/... atribui nivel logico 0/... ao pino numero_da_porta da porta A/B
    
    PORTBbits.RB6 = 0;                  //atribui o nivel logico 0 (0V) ao pino 6 da porta B
    
    //Ou seja, port serve para atribuir nivel logico, e tris serve para direcionar tal pino como entrada e saída      
    
    
    while(1){
    
        PORTBbits.RB6 = 1;              //atribui o nivel logico 0 ao pino 6 da porta B
    
        //__delay_ms(tempo); é o comando de delay, o quanto tempo dura o comando
        
        __delay_ms(3000);               //gera atraso de 3 seg
        
        
        PORTBbits.RB6 = 0;              //atribui o nivel logico 1 (5V) ao pino 6 da porta B
    
        //__delay_ms(tempo); é o comando de delay, o quanto tempo dura o comando
        
        __delay_ms(3000);               //gera atraso de 3 seg
                       
    }
    
}





