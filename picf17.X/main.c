/*
 * File:   main.c
 * Author: Gedre
 * Target: PIC16F1769 (SSOP-20)
 */

#pragma config FOSC = INTOSC    // Oscilador interno
#pragma config WDTE = OFF       // Watchdog Timer desativado
#pragma config PWRTE = ON       // Power-up Timer habilitado
#pragma config MCLRE = ON       // MCLR habilitado (necessário para ICSP)
#pragma config CP = OFF         // Proteção de código desabilitada
#pragma config BOREN = OFF      // Brown-out Reset desativado
#pragma config CLKOUTEN = OFF   // CLKOUT desabilitado
#pragma config IESO = ON        // Troca automática entre osciladores
#pragma config FCMEN = ON       // Fail-safe clock monitor

// CONFIG2
#pragma config WRT = OFF
#pragma config PPS1WAY = ON
#pragma config ZCD = OFF
#pragma config PLLEN = ON       // PLL ativado (pode ou não estar efetivamente atuando)
#pragma config STVREN = ON
#pragma config BORV = LO
#pragma config LPBOR = OFF
#pragma config DEBUG = OFF
#pragma config LVP = OFF        // Programação por alta tensão (MCLR habilitado)

#include <xc.h>

// Frequência real do clock interno usado para __delay_ms
#define _XTAL_FREQ 16000000UL  // Corrigido para refletir 16 MHz

void initOscillator(void) {
    // Seleciona HFINTOSC como fonte de clock com frequência de 16 MHz
    OSCCON = 0b01111010;  // IRCF = 1111 (16 MHz), SCS = 10 (uso do oscilador interno)
}

void main(void) {
    initOscillator();

    // Configura RC4 (pino 5) como saída digital
    TRISCbits.TRISC4 = 0;
    LATCbits.LATC4 = 0; // Inicialmente desligado

    while(1) {
        LATCbits.LATC4 = 1;  // Liga LED
        __delay_ms(500);
        LATCbits.LATC4 = 0;  // Desliga LED
        __delay_ms(500);
    }
}
