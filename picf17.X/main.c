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


//codigo com pwm: conferir

//codigo do com adicao de pwm

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

void main(void) {
    unsigned int adc_value = 0;
    unsigned int duty = 0;

    // Configura o oscilador interno para 16 MHz
    OSCCONbits.IRCF = 0b1111;

    // Configura RA0 como entrada analógica (potenciômetro)
    TRISAbits.TRISA0 = 1;
    ANSELAbits.ANSA0 = 1;

    // Configura ADC
    ADCON0bits.CHS = 0b0000;   // Canal AN0
    ADCON0bits.ADON = 1;       // Liga o ADC
    ADCON1bits.ADFM = 1;       // Resultado justificado à direita
    ADCON1bits.ADPREF = 0b00;  // Referência = VDD
    ADCON1bits.ADCS = 0b010;   // Clock ADC = FOSC/32
    ANSELA = 0x01;
    
    // Desativa comparadores
    CM1CON0bits.C1ON = 0;
    CM2CON0bits.C2ON = 0;

    // PWM no pino RC4 (CCP1)
    TRISCbits.TRISC4 = 1;      // Temporariamente como entrada
    RC4PPS = 0x09;             // CCP1 no RC4

    // Calcula T2PR para obter período de 1 ms (1 kHz PWM)
    T2PR = 249;  // 1 ms → 4 * Tosc * prescaler * (T2PR + 1) = 1ms

    // Configura CCP1 como PWM
    CCP1CONbits.CCP1MODE = 0b1100; // PWM mode
    CCP1CONbits.FMT = 0;          // Left-aligned 10-bit format

    // Seleciona Timer2 para CCP1
    CCPTMRSbits.C1TSEL = 0b00;    // CCP1 usa Timer2

    // Configura Timer2
    T2CLKCON = 0x01;              // Clock = Fosc/4
    T2CONbits.T2CKPS = 0b11;      // Prescaler = 1:16
    T2CONbits.TMR2ON = 1;         // Liga Timer2

    while (!PIR1bits.TMR2IF);     // Espera Timer2 iniciar
    PIR1bits.TMR2IF = 0;
    TRISCbits.TRISC4 = 0;         // Agora RC4 é saída PWM

    while (1) {
        // Inicia conversão ADC com pequeno delay
        __delay_us(5); // Tempo de aquisição
        ADCON0bits.GO = 1;
        while (ADCON0bits.GO);

        // Lê valor ADC
        adc_value = ((ADRESH << 8) | ADRESL);

        // Saturação (opcional)
        if (adc_value > 1022) adc_value = 1022;

        // Atualiza duty
        duty = adc_value;

        // Carrega nos registradores CCP
        CCPR1H = duty >> 2;                  // Bits 9:2
        CCPR1L = (duty & 0b11) << 6;         // Bits 1:0 nos bits 7:6
    }
}

