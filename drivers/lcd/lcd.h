#pragma once
#ifndef LCD_H_
#define LCD_H_


#include <avr/io.h>
#include "../clockfreq.h"
#include <util/delay.h>


#define PORT_LCD_RS			PORTF		// LCD RS PORT
#define DDR_LCD_RS			DDRF		// LCD RS DDR
#define PIN_LCD_RS			PF1			// LCD RS PIN

#define PORT_LCD_RW			PORTF		// LCD RW PORT
#define DDR_LCD_RW			DDRF		// LCD RW DDR
#define PIN_LCD_RW			PF2			// LCD RW PIN

#define PORT_LCD_E			PORTF		// LCD E PORT
#define DDR_LCD_E			DDRF		// LCD E DDR
#define PIN_LCD_E			PF3			// LCD E PIN

#define PORT_LCD_DATA		PORTE		// LCD DATA PORT
#define DDR_LCD_DATA		DDRE		// LCD DATA DDR
#define PIN_LCD_DATA		PINE		// LCD DATA WHOLE PIN		
#define MASK_H_LCD_DATA		0xF0		// LCD DATA HIGH MASK
#define MASK_L_LCD_DATA		0x0F		// LCD DATA LOW MASK


#define LCD_DATA7			7 // LCD PORT DB7
#define LCD_DATA6			6 // LCD PORT DB6
#define LCD_DATA5			5 // LCD PORT DB5
#define LCD_DATA4			4 // LCD PORT DB4
#define LCD_DATA3			3 // LCD PORT DB3
#define LCD_DATA2			2 // LCD PORT DB2
#define LCD_DATA1			1 // LCD PORT DB1
#define LCD_DATA0			0 // LCD PORT DB0

#define BIT7 0x80
#define BIT6 0x40
#define BIT5 0x20
#define BIT4 0x10
#define BIT3 0x08
#define BIT2 0x04
#define BIT1 0x02
#define BIT0 0x01

#define LCD_BUSY_FLAG       LCD_DATA7
#define LCD_DISP_CLEAR      0x01
#define LCD_DISP_OFF        0x08
#define LCD_DISP_ON         0x0C
#define LCD_CURSOR_ON       0x0E
#define LCD_CURSOR_OFF      0x0C
#define LCD_CURSOR_BLINK    0x0F
#define LCD_RETURN_HOME     0x02
#define LCD_ENTRY_MODE      0x06
#define LCD_POSITION        0x80

#define LCD_4BIT_MODE       0x20
#define LCD_8BIT_MODE       0x30
#define LCD_2_ROWS          0x08
#define LCD_FONT_5x8        0x00
#define LCD_FONT_5x10       0x04


#define HD44780_SHIFT           0x10
#define HD44780_CURSOR          0x00
#define HD44780_DISPLAY         0x08
#define HD44780_LEFT            0x00
#define HD44780_RIGHT           0x04



// Macro definitions
#define SETBIT(PORT, BIT)        { PORT |= (1 << BIT); }        // Set bit
#define CLRBIT(PORT, BIT)        { PORT &= ~(1 << BIT); }       // Clear bit


// LCD Function declarations
void LCD_Initialization();                              // LCD initialization
void LCD_Clock();                                       // Clock pulse (E 0__|1|__0)
void LCD_SendInstruction(uint8_t cmd);                  // Send instruction to LCD
void LCD_SendData(uint8_t data);                        // Send data to LCD
void LCD_SendString(char* p);                           // Send string to LCD
void LCD_SendStringToLine(char* p, uint8_t line);       // Send string to one of the LCD's line

uint8_t LCD_GetLineAddres(int row);                     // Returns the address of the first character of the given row
void LCD_SetCursorPos(uint8_t line, uint8_t column);    // Set cursor position
void LCD_SetCursorLine(uint8_t line);                   // Set cursor line 

void LCD_Send8bitsIn4bitMode(uint8_t data);             // Send 8 bits in 4 bit mode
void LCD_SetLowData(uint8_t data);                      // Set low data

void LCD_CheckBusyFlag();                               // Check busy flag

void LCD_DisplayClear();                                // Clear display
void LCD_DisplayOn();                                   // Turn the display on
void LCD_CursorOn();                                    // Turn the cursor on
void LCD_CursorOff();                                   // Turn the cursor off
void LCD_CursorBlink();                                 // Turn the cursor blink on

void LCD_SetPORT_DATA4to7();                            // Initialize the LCD data port
void LCD_SetDDR_DATA4to7();                             // Set the LCD data port as output
void LCD_ClearDDR_DATA4to7();                           // Clear the LCD data port

#endif