/**
  PIN MANAGER Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.c

  @Summary:
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for PIN MANAGER.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.4
        Device            :  PIC24FJ128GA705
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB 	          :  MPLAB X v6.05
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/


/**
    Section: Includes
*/

#include <xc.h>
#include <stdio.h>
#include "pin_manager.h"

/**
 Section: File specific functions
*/
void (*START_GAME_InterruptHandler)(void) = NULL;
void (*STOP_GAME_InterruptHandler)(void) = NULL;
void (*BUTTON_GREEN_InterruptHandler)(void) = NULL;
void (*BUTTON_BLUE_InterruptHandler)(void) = NULL;
void (*BUTTON_YELLOW_InterruptHandler)(void) = NULL;
void (*BUTTON_RED_InterruptHandler)(void) = NULL;

/**
 Section: Driver Interface Function Definitions
*/
void PIN_MANAGER_Initialize (void)
{
    /****************************************************************************
     * Setting the Output Latch SFR(s)
     ***************************************************************************/
    LATA = 0x0000;
    LATB = 0x0010;
    LATC = 0x0038;

    /****************************************************************************
     * Setting the GPIO Direction SFR(s)
     ***************************************************************************/
    TRISA = 0x7F97;
    TRISB = 0xFFEF;
    TRISC = 0x03C7;

    /****************************************************************************
     * Setting the Weak Pull Up and Weak Pull Down SFR(s)
     ***************************************************************************/
    IOCPDA = 0x0000;
    IOCPDB = 0x0000;
    IOCPDC = 0x0000;
    IOCPUA = 0x0480;
    IOCPUB = 0x0000;
    IOCPUC = 0x0000;

    /****************************************************************************
     * Setting the Open Drain SFR(s)
     ***************************************************************************/
    ODCA = 0x0000;
    ODCB = 0x0000;
    ODCC = 0x0000;

    /****************************************************************************
     * Setting the Analog/Digital Configuration SFR(s)
     ***************************************************************************/
    ANSA = 0x0004;
    ANSB = 0xF20C;
    ANSC = 0x0007;
    
    /****************************************************************************
     * Interrupt On Change: negative
     ***************************************************************************/
    IOCNAbits.IOCNA0 = 1;    //Pin : RA0
    IOCNAbits.IOCNA1 = 1;    //Pin : RA1
    IOCNAbits.IOCNA10 = 1;    //Pin : RA10
    IOCNAbits.IOCNA7 = 1;    //Pin : RA7
    IOCNBbits.IOCNB0 = 1;    //Pin : RB0
    IOCNBbits.IOCNB1 = 1;    //Pin : RB1
    /****************************************************************************
     * Interrupt On Change: flag
     ***************************************************************************/
    IOCFAbits.IOCFA0 = 0;    //Pin : RA0
    IOCFAbits.IOCFA1 = 0;    //Pin : RA1
    IOCFAbits.IOCFA10 = 0;    //Pin : RA10
    IOCFAbits.IOCFA7 = 0;    //Pin : RA7
    IOCFBbits.IOCFB0 = 0;    //Pin : RB0
    IOCFBbits.IOCFB1 = 0;    //Pin : RB1
    /****************************************************************************
     * Interrupt On Change: config
     ***************************************************************************/
    PADCONbits.IOCON = 1;    //Config for PORTA
    
    /* Initialize IOC Interrupt Handler*/
    START_GAME_SetInterruptHandler(&START_GAME_CallBack);
    STOP_GAME_SetInterruptHandler(&STOP_GAME_CallBack);
    BUTTON_GREEN_SetInterruptHandler(&BUTTON_GREEN_CallBack);
    BUTTON_BLUE_SetInterruptHandler(&BUTTON_BLUE_CallBack);
    BUTTON_YELLOW_SetInterruptHandler(&BUTTON_YELLOW_CallBack);
    BUTTON_RED_SetInterruptHandler(&BUTTON_RED_CallBack);
    
    /****************************************************************************
     * Interrupt On Change: Interrupt Enable
     ***************************************************************************/
    IFS1bits.IOCIF = 0; //Clear IOCI interrupt flag
    IEC1bits.IOCIE = 1; //Enable IOCI interrupt
}

void __attribute__ ((weak)) START_GAME_CallBack(void)
{

}

void __attribute__ ((weak)) STOP_GAME_CallBack(void)
{

}

void __attribute__ ((weak)) BUTTON_GREEN_CallBack(void)
{

}

void __attribute__ ((weak)) BUTTON_BLUE_CallBack(void)
{

}

void __attribute__ ((weak)) BUTTON_YELLOW_CallBack(void)
{

}

void __attribute__ ((weak)) BUTTON_RED_CallBack(void)
{

}

void START_GAME_SetInterruptHandler(void (* InterruptHandler)(void))
{ 
    IEC1bits.IOCIE = 0; //Disable IOCI interrupt
    START_GAME_InterruptHandler = InterruptHandler; 
    IEC1bits.IOCIE = 1; //Enable IOCI interrupt
}

void START_GAME_SetIOCInterruptHandler(void *handler)
{ 
    START_GAME_SetInterruptHandler(handler);
}

void STOP_GAME_SetInterruptHandler(void (* InterruptHandler)(void))
{ 
    IEC1bits.IOCIE = 0; //Disable IOCI interrupt
    STOP_GAME_InterruptHandler = InterruptHandler; 
    IEC1bits.IOCIE = 1; //Enable IOCI interrupt
}

void STOP_GAME_SetIOCInterruptHandler(void *handler)
{ 
    STOP_GAME_SetInterruptHandler(handler);
}

void BUTTON_GREEN_SetInterruptHandler(void (* InterruptHandler)(void))
{ 
    IEC1bits.IOCIE = 0; //Disable IOCI interrupt
    BUTTON_GREEN_InterruptHandler = InterruptHandler; 
    IEC1bits.IOCIE = 1; //Enable IOCI interrupt
}

void BUTTON_GREEN_SetIOCInterruptHandler(void *handler)
{ 
    BUTTON_GREEN_SetInterruptHandler(handler);
}

void BUTTON_BLUE_SetInterruptHandler(void (* InterruptHandler)(void))
{ 
    IEC1bits.IOCIE = 0; //Disable IOCI interrupt
    BUTTON_BLUE_InterruptHandler = InterruptHandler; 
    IEC1bits.IOCIE = 1; //Enable IOCI interrupt
}

void BUTTON_BLUE_SetIOCInterruptHandler(void *handler)
{ 
    BUTTON_BLUE_SetInterruptHandler(handler);
}

void BUTTON_YELLOW_SetInterruptHandler(void (* InterruptHandler)(void))
{ 
    IEC1bits.IOCIE = 0; //Disable IOCI interrupt
    BUTTON_YELLOW_InterruptHandler = InterruptHandler; 
    IEC1bits.IOCIE = 1; //Enable IOCI interrupt
}

void BUTTON_YELLOW_SetIOCInterruptHandler(void *handler)
{ 
    BUTTON_YELLOW_SetInterruptHandler(handler);
}

void BUTTON_RED_SetInterruptHandler(void (* InterruptHandler)(void))
{ 
    IEC1bits.IOCIE = 0; //Disable IOCI interrupt
    BUTTON_RED_InterruptHandler = InterruptHandler; 
    IEC1bits.IOCIE = 1; //Enable IOCI interrupt
}

void BUTTON_RED_SetIOCInterruptHandler(void *handler)
{ 
    BUTTON_RED_SetInterruptHandler(handler);
}

/* Interrupt service routine for the IOCI interrupt. */
void __attribute__ (( interrupt, no_auto_psv )) _IOCInterrupt ( void )
{
    if(IFS1bits.IOCIF == 1)
    {
        if(IOCFAbits.IOCFA7 == 1)
        {
            if(START_GAME_InterruptHandler) 
            { 
                START_GAME_InterruptHandler(); 
            }
            
            IOCFAbits.IOCFA7 = 0;  //Clear flag for Pin - RA7

        }
        
        if(IOCFAbits.IOCFA10 == 1)
        {
            if(STOP_GAME_InterruptHandler) 
            { 
                STOP_GAME_InterruptHandler(); 
            }
            
            IOCFAbits.IOCFA10 = 0;  //Clear flag for Pin - RA10

        }
        
        if(IOCFAbits.IOCFA1 == 1)
        {
            if(BUTTON_GREEN_InterruptHandler) 
            { 
                BUTTON_GREEN_InterruptHandler(); 
            }
            
            IOCFAbits.IOCFA1 = 0;  //Clear flag for Pin - RA1

        }
        
        if(IOCFAbits.IOCFA0 == 1)
        {
            if(BUTTON_BLUE_InterruptHandler) 
            { 
                BUTTON_BLUE_InterruptHandler(); 
            }
            
            IOCFAbits.IOCFA0 = 0;  //Clear flag for Pin - RA0

        }
        
        if(IOCFBbits.IOCFB0 == 1)
        {
            if(BUTTON_YELLOW_InterruptHandler) 
            { 
                BUTTON_YELLOW_InterruptHandler(); 
            }
            
            IOCFBbits.IOCFB0 = 0;  //Clear flag for Pin - RB0

        }
        
        if(IOCFBbits.IOCFB1 == 1)
        {
            if(BUTTON_RED_InterruptHandler) 
            { 
                BUTTON_RED_InterruptHandler(); 
            }
            
            IOCFBbits.IOCFB1 = 0;  //Clear flag for Pin - RB1

        }
        
        
        // Clear the flag
        IFS1bits.IOCIF = 0;
    }
}

