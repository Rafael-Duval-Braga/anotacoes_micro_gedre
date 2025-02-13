
//codigo com o tempo setado conferir
void main(void) {
    
    CMCON = 0x07;  // Desativa os comparadores analógicos
    
    TRISBbits.TRISB5 = 0;  // Define RB5 como saída
    PORTBbits.RB5 = 0;  // Inicializa RB5 em nível baixo
    
    while(1) {
        PORTBbits.RB5 = 1;  // Ativa saída (nível alto)
        __delay_us(2.927);  // Tempo de ON

        PORTBbits.RB5 = 0;  // Desativa saída (nível baixo)
        __delay_us(9.025);  // Tempo de OFF
    }
}


// codigo funcional
// obs ver por que funciona feito
// CONFIGURAÇÃO DO MICROCONTROLADOR PIC16F628A

#pragma config FOSC = HS        // Oscilador High-Speed para cristal de 16MHz
#pragma config WDTE = OFF       // Watchdog Timer desativado
#pragma config PWRTE = ON       // Power-up Timer ativado
#pragma config MCLRE = ON       // MCLR ativado (RA5 funcionando como Reset)
#pragma config BOREN = ON       // Brown-out Reset ativado
#pragma config LVP = OFF        // Low-Voltage Programming desativado
#pragma config CPD = OFF        // Proteção da memória EEPROM desativada
#pragma config CP = OFF         // Proteção da memória Flash desativada

#include <xc.h>

#define _XTAL_FREQ 16000000UL  // Define a frequência do clock para 16MHz

void main(void) {
    // **CONFIGURAÇÃO INICIAL**

    //ESSAS DUAS LINHAS SÃO AS UNICAS DIFERENCAS DO MEU CODIGO COM ESSE OUTRO
    CMCON = 0x07;               // Desativa os comparadores analógicos
    OPTION_REGbits.nRBPU = 0;   // Ativa pull-ups internos (se necessário)
    
    TRISBbits.TRISB5 = 0;       // Configura RB5 como saída
    PORTBbits.RB5 = 0;          // Inicializa RB5 em nível baixo
    
    // **LOOP DE TESTE INICIAL** (Pisca 3 vezes para indicar que o código está rodando)
    for (int i = 0; i < 3; i++) {
        PORTBbits.RB5 = 1;
        __delay_ms(500);
        PORTBbits.RB5 = 0;
        __delay_ms(500);
    }
    
    // **LOOP PRINCIPAL**
    while (1) {
        PORTBbits.RB5 = 1;      // Seta RB5 em nível alto (5V)
        __delay_ms(3000);       // Atraso de 3 segundos
        
        PORTBbits.RB5 = 0;      // Seta RB5 em nível baixo (0V)
        __delay_ms(3000);       // Atraso de 3 segundos
    }
}


/**codigo nao funcional 

// CONFIG
#pragma config FOSC = HS        // Oscilador High-Speed para cristal de 16MHz
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
    
    TRISBbits.TRISB5 = 0;               //direciona o pino 6 da porta b como saida 
    
    //PORTA/B.R_A/B_numero_da_porta = 0/... atribui nivel logico 0/... ao pino numero_da_porta da porta A/B
    
    PORTBbits.RB5 = 0;                  //atribui o nivel logico 0 (0V) ao pino 6 da porta B
    
    //Ou seja, port serve para atribuir nivel logico, e tris serve para direcionar tal pino como entrada e saída      
    
    
    while(1){
    
        PORTBbits.RB5 = 1;              //atribui o nivel logico 0 ao pino 6 da porta B
    
        //__delay_ms(tempo); é o comando de delay, o quanto tempo dura o comando
        
        __delay_ms(3000);               //gera atraso de 3 seg
        
        
        PORTBbits.RB5 = 0;              //atribui o nivel logico 1 (5V) ao pino 6 da porta B
    
        //__delay_ms(tempo); é o comando de delay, o quanto tempo dura o comando
        
        __delay_ms(3000);               //gera atraso de 3 seg
                       
    }
    
}
**/




