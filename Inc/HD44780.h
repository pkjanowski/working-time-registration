#include "stm32f0xx_hal.h"
#define HD44780_CLEAR 				0x01

#define HD44780_HOME 				0x02

#define HD44780_MODE_SET 			0x04
	#define HD44780_MODE_SET_R 			0x02
	#define HD44780_MODE_SET_L 			0
	#define HD44780_MODE_SET_SHIFT		0x01

#define HD44780_ONOFF				0x08
	#define HD44780_DISP_ON				0x04
	#define HD44780_CURSOR_ON			0x02
	#define HD44780_CURSOR_OFF			0
	#define HD44780_CURSOR_BLINK			0x01

#define HD44780_SHIFT				0x10
	#define HD44780_DISP_SHIFT			0x08
	#define HD44780_CURSOR_SHIFT		0
	#define HD44780_SHIFT_R				0x04
	#define HD44780_SHIFT_L				0

#define HD44780_FUNC				0x20
	#define HD44780_FUNC_8B				0x10
	#define HD44780_FUNC_4B				0
	#define HD44780_FUNC_2L				0x08
	#define HD44780_FUNC_1L				0
	#define HD44780_FUNC_5x10			0x04
	#define HD44780_FUNC_5x7			0x00

#define HD44780_CGRAM_SET_ADDRESS	0x40

#define HD44780_DDRAM_SET_ADDRESS	0x80

void HD44780_init();
void HD44780_clearDisp();
void HD44780_sendString (char * str);
void HD44780_locate(uint8_t row, uint8_t col);


