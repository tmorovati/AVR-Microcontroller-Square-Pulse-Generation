/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 7/21/2020
Author  : 
Company : 
Comments: 


Chip type               : ATmega32
Program type            : Application
AVR Core Clock frequency: 1.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*******************************************************/

#include <mega32.h>
#include <delay.h>

// Declare your global variables here

void main(void)
{


// Port D initialization
// Function: Bit7=In Bit6=In Bit5=Out Bit4=Out Bit3=In Bit2=In Bit1=In Bit0=In 
DDRD=(0<<DDD7) | (0<<DDD6) | (1<<DDD5) | (1<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);
// State: Bit7=T Bit6=T Bit5=0 Bit4=0 Bit3=T Bit2=T Bit1=T Bit0=T 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);





while (1)
      { 
      TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (1<<WGM01) | (0<<CS02) | (0<<CS01) | (1<<CS00); //enable timer
      TCNT0=0x00;
      OCR0=0x64  ; // 5KHz = 0.2ms / 2 = 0.1 ms /  1 us(micro-frequency) = 100 dec = 0x64 hex
      while((TIFR  & ( 1 << OCF0 )) == 0 );//polling 
      TCCR0 = 0 ; 
      PORTD = PORTD ^ 0x10 ; //PD4 
      delay_us(100) ;   
      PORTD = PORTD ^ 0x20 ; //PD5 
      TCNT0 = 0 ; 
      TIFR = ( 1 << OCF0 ) ; //clear flag 

      }
}
