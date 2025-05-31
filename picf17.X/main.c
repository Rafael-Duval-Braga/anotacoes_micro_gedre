/*
 * File:   main.c
 * Author: Gedre
 * Target: PIC16F1769 (SSOP-20)
 */


//Código com o tempo fixo

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
        __delay_ms(0.00292723378);
        LATCbits.LATC4 = 0;  // Desliga LED
        __delay_ms(0.0114);
    }
}








//Código com o tempo variado com potenciometro
//testar funcao void delay_us_var(unsigned int us)

// CONFIG1
#pragma config FOSC = INTOSC
#pragma config WDTE = OFF
#pragma config PWRTE = ON
#pragma config MCLRE = ON
#pragma config CP = OFF
#pragma config BOREN = OFF
#pragma config CLKOUTEN = OFF
#pragma config IESO = ON
#pragma config FCMEN = ON

// CONFIG2
#pragma config WRT = OFF
#pragma config PPS1WAY = ON
#pragma config ZCD = OFF
#pragma config PLLEN = ON
#pragma config STVREN = ON
#pragma config BORV = LO
#pragma config LPBOR = OFF
#pragma config DEBUG = OFF
#pragma config LVP = OFF

#include <xc.h>
#include <stdint.h>

#define _XTAL_FREQ 16000000UL

unsigned int adc_value = 0;
unsigned int periodo = 1000;
unsigned int ton = 0;
unsigned int toff = 0;

/*
void delay_us_var(unsigned int us) 
{
    while (us--) {
        __delay_us(1);
    }
}
*/


void delay_us_var(unsigned int us)
{
    for (; us > 0; us--)
    {
        __delay_ms(1);
    }
}
 
 


void main(void) {
    // Configuração do oscilador interno
    OSCCONbits.IRCF = 0b1111;

    // Configura RC4 como saída digital
    TRISCbits.TRISC4 = 0;
    LATCbits.LATC4 = 0;

    // Configura RA0 como entrada analógica
    TRISA = 0xFF;
    ANSELAbits.ANSA0 = 1;

    // Configura ADC
    ADCON0bits.CHS = 0b0000; // AN0
    ADCON0bits.ADON = 1;
    ADCON1bits.ADNREF = 0;
    ADCON1bits.ADPREF = 0b00;
    ADCON1bits.ADFM = 1;     // Justificado à direita
    ADCON1bits.ADCS = 0b010; // FOSC/32

    // Desativa comparadores
    CM1CON0bits.C1ON = 0;
    CM2CON0bits.C2ON = 0;

    while (1) {
        // Inicia conversão ADC
        ADCON0bits.GO = 1;
        while (ADCON0bits.GO); // Espera a conversão terminar

        // Lê valor de 10 bits do ADC
        adc_value = (((unsigned int)ADRESH) << 8) | ADRESL;

        // Calcula o 'ton' corretamente sem perda de bits
        unsigned long temp = (unsigned long)periodo * adc_value; // 32 bits
        
                // comentarios do professor
        //periodo = 1000
        
        //ton = (periodo*adc_read())>>10
        //toff = periodo - ton
        
        //ton = (periodo * adc_value) >> 10;
                
        ton = temp >> 10; // Divide por 1024 (valor máximo do ADC de 10 bits)

        toff = periodo - ton;

        // Gera pulso
        LATCbits.LATC4 = 1;
        delay_us_var(ton);

        LATCbits.LATC4 = 0;
        delay_us_var(toff);
    }
}

