#include "HD44780.h"
#include "main.h"
#include "stm32f0xx_hal.h"

#define HD44780_SET_RS		HAL_GPIO_WritePin(HD44780_RS_GPIO_Port, HD44780_RS_Pin, GPIO_PIN_SET);
#define HD44780_RESET_RS	HAL_GPIO_WritePin(HD44780_RS_GPIO_Port, HD44780_RS_Pin, GPIO_PIN_RESET);

#define HD44780_SET_E		HAL_GPIO_WritePin(HD44780_E_GPIO_Port, HD44780_E_Pin, GPIO_PIN_SET);
#define HD44780_RESET_E		HAL_GPIO_WritePin(HD44780_E_GPIO_Port, HD44780_E_Pin, GPIO_PIN_RESET);


void HD44780_locate(uint8_t row, uint8_t col) {
	switch(row) {
	case 0:
		HD44780_sendCommand(HD44780_DDRAM_SET_ADDRESS | col);
		break;

	case 1:
		HD44780_sendCommand(HD44780_DDRAM_SET_ADDRESS | (0x40 + col));
		break;
	}
}

void HD44780_sendHalfByte(uint8_t data) {
	if (data & 0x01) HAL_GPIO_WritePin(HD44780_D4_GPIO_Port, HD44780_D4_Pin, GPIO_PIN_SET);
		else HAL_GPIO_WritePin(HD44780_D4_GPIO_Port, HD44780_D4_Pin, GPIO_PIN_RESET);

	if (data & 0x02) HAL_GPIO_WritePin(HD44780_D5_GPIO_Port, HD44780_D5_Pin, GPIO_PIN_SET);
		else HAL_GPIO_WritePin(HD44780_D5_GPIO_Port, HD44780_D5_Pin, GPIO_PIN_RESET);

	if (data & 0x04) HAL_GPIO_WritePin(HD44780_D6_GPIO_Port, HD44780_D6_Pin, GPIO_PIN_SET);
		else HAL_GPIO_WritePin(HD44780_D6_GPIO_Port, HD44780_D6_Pin, GPIO_PIN_RESET);

	if (data & 0x08) HAL_GPIO_WritePin(HD44780_D7_GPIO_Port, HD44780_D7_Pin, GPIO_PIN_SET);
		else HAL_GPIO_WritePin(HD44780_D7_GPIO_Port, HD44780_D7_Pin, GPIO_PIN_RESET);
}


void HD44780_sendByte(uint8_t data) {
	HD44780_SET_E;
	HD44780_sendHalfByte(data>>4);
	HD44780_RESET_E;

	HD44780_SET_E;
	HD44780_sendHalfByte(data);
	HD44780_RESET_E;

	HAL_Delay(0.12);
}

void HD44780_sendCommand(uint8_t command) {
	HD44780_RESET_RS;
	HD44780_sendByte(command);
}

void HD44780_sendData(uint8_t data) {
	HD44780_SET_RS;
	HD44780_sendByte(data);
}

void HD44780_init() {
	HAL_Delay(15);
	HD44780_SET_E;
	HD44780_sendHalfByte(0x03);
	HD44780_RESET_E;

	HAL_Delay(4.1);
	HD44780_SET_E;
	HD44780_sendHalfByte(0x03);
	HD44780_RESET_E;

	HAL_Delay(0.1);
	HD44780_SET_E;
	HD44780_sendHalfByte(0x03);
	HD44780_RESET_E;

	HAL_Delay(4.1);
	HD44780_SET_E;
	HD44780_sendHalfByte(0x02);
	HD44780_RESET_E;

	HD44780_sendCommand(HD44780_FUNC | HD44780_FUNC_4B | HD44780_FUNC_2L| HD44780_FUNC_5x7);
	HD44780_sendCommand(HD44780_ONOFF | HD44780_CURSOR_OFF);
	HD44780_sendCommand(HD44780_ONOFF | HD44780_DISP_ON);
	HD44780_sendCommand(HD44780_MODE_SET | HD44780_MODE_SET_R);

	HD44780_clearDisp();
}

void HD44780_clearDisp() {
	HD44780_sendCommand(HD44780_CLEAR);
	HAL_Delay(4.9);
}

void HD44780_sendString (char * str) {
	while(*str) HD44780_sendData(*str++);
}

void HD44780_sendStringRowCol (uint8_t row, uint8_t col, char * str) {
	HD44780_locate(row, col);
	HD44780_sendString(str);
}



