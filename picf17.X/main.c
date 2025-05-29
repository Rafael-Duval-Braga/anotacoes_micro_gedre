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
        __delay_ms(0.00292723378);
        LATCbits.LATC4 = 0;  // Desliga LED
        __delay_ms(0.0114);
    }
}


/**
possivel codigo para mudar frequencia

 * File:   main.c
 * Author: Gedre
 * Target: PIC16F1769 (SSOP-20)


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
#pragma config PLLEN = ON       // PLL ativado
#pragma config STVREN = ON
#pragma config BORV = LO
#pragma config LPBOR = OFF
#pragma config DEBUG = OFF
#pragma config LVP = OFF        // Programação por alta tensão (MCLR habilitado)

#include <xc.h>
#include <stdint.h>

#define _XTAL_FREQ 16000000UL   // Oscilador interno com PLL = 16 MHz

void ADC_Init(void) {
    ANSELA = 0x01;      // RA0 como entrada analógica
    TRISA0 = 1;         // RA0 como entrada
    ADCON0 = 0x01;      // Habilita ADC, seleciona AN0
    ADCON1 = 0x30;      // Justificado à direita, Vref = Vdd/Vss
}

uint16_t ADC_Read(void) {
    ADCON0bits.GO = 1;                 // Inicia a conversão
    while (ADCON0bits.GO);            // Espera terminar
    return ((ADRESH << 8) + ADRESL);  // Retorna resultado 10 bits
}

// Delay por software com base em múltiplos de 1 ms
void software_delay(uint16_t ms) {
    while (ms--) {
        __delay_ms(1);  // Delay fixo permitido pelo compilador
    }
}

void main(void) {
    // Configura RC4 como saída digital
    TRISCbits.TRISC4 = 0;
    LATCbits.LATC4 = 0;

    ADC_Init();  // Inicializa ADC

    while (1) {
        uint16_t adc_value = ADC_Read();  // Lê valor do potenciômetro RA0

        // Mapeia valor ADC (0–1023) para tempo de 50 ms a 500 ms
        uint16_t delay_time = 50 + (adc_value * 450 / 1023);

        // Pisca o LED com o delay ajustado
        LATCbits.LATC4 = 1;
        software_delay(delay_time);

        LATCbits.LATC4 = 0;
        software_delay(delay_time);
    }
}


//testar este outro codigo:
// Arquivo: main.c
// Autor: Adaptado por ChatGPT para mapeamento de delay entre 3us e 2us

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

#define _XTAL_FREQ 16000000UL   // Oscilador interno com PLL ativado (16 MHz)

void ADC_Init(void) {
    ANSELA = 0x01;            // RA0 como entrada analógica
    TRISAbits.TRISA0 = 1;     // RA0 como entrada
    ADCON0 = 0x01;            // Habilita ADC, seleciona canal AN0
    ADCON1 = 0x30;            // Justificado à direita, Vref = Vdd/Vss
}

uint16_t ADC_Read(void) {
    __delay_us(5);            // Tempo de aquisição
    ADCON0bits.GO = 1;        // Inicia conversão
    while (ADCON0bits.GO);    // Aguarda fim
    return ((ADRESH << 8) + ADRESL);
}

void delay_us(uint16_t us) {
    while (us--) {
        __delay_us(1);
    }
}

void main(void) {
    TRISCbits.TRISC4 = 0;    // RC4 como saída
    LATCbits.LATC4 = 0;      // Inicialmente desligado

    ADC_Init();  // Inicializa ADC

    while (1) {
        uint16_t adc_value = ADC_Read();  // Lê valor do potenciômetro RA0

        // Mapeia adc_value (0–1023) para delay entre 3us e 2us
        // tempo = 3 - (adc_value * 1 / 1023)
        uint16_t period_us = 3 - ((uint32_t)adc_value * 1 / 1023);
        uint16_t half_period = period_us / 2;

        // Pisca LED com o período ajustado
        LATCbits.LATC4 = 1;
        delay_us(half_period);

        LATCbits.LATC4 = 0;
        delay_us(half_period);
    }
}



//arrumar isso:

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
#include <stdint.h>

#define _XTAL_FREQ 16000000UL   // Oscilador interno com PLL ativado (16 MHz)

int adc_value = 0; //  0?1023



void main(void) {
    //TRISCbits.TRISC4 = 0;  // RC4 como saída
    //LATCbits.LATC4 = 0;

    
    TRISA = 0b11111111; //definindo o pino a0 como entrada
    
    ADCON0bits.CHS = 0b0000; //canal AN0 
    ADCON0bits.ADON = 1; // ativar o conversor ADC
    
    ADCON1bits.ADNREF = 000 //configurando tensao de referencia
    ADCON1.ADFM = 1;       //bit mais significativo na direita 
    ADCON1.ADCS = 0b010 // ADC Conversion Clock Select bits FOSC/32
    
            //ver esses links
            //https://youtu.be/Zx-p7BscHK8?feature=shared
            //https://www.youtube.com/playlist?list=PLW6De-P8jCuh5aK5ybeJuZHn6_gc9oLhH
            //https://www.youtube.com/playlist?list=PLW6De-P8jCuh5aK5ybeJuZHn6_gc9oLhH
    while(1) {
        
        ADCON0bits.GO = 1; //entra em conversao
        
        while(ADCON0bits.GO){ //aguarda processo de conversao
        
            adc_value = ((int));
        
        }
        
        //const uint8_t total_period = 14.2857; //  14.2857 ?s         
        
          //X esta entre 0-1023
          //y esta entre 2?s - 3?s
          //formula que relaciona y = 2 + (x/1023)
        
        // comentarios do professor
        //periodo = 1000
        //ton = (periodo*adc_read())>>10
        //toff = periodo - ton

       /* uint8_t on_time = 2 + ((uint16_t)adc_value / 1023);
        uint8_t off_time = total_period - on_time;

        LATCbits.LATC4 = 1;
        __delay_us(on_time);

        LATCbits.LATC4 = 0;
        __delay_ms(off_time);
        */
//    }

//}



