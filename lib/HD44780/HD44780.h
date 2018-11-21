#define HD44780_CLEAR 				0x01

#define HD4480_HOME 				0x02

#define HD4480_MODE_SET 			0x04
	#define HD4480_MODE_SET_R 			0x02
	#define HD4480_MODE_SET_L 			0
	#define HD4480_MODE_SET_SHIFT		0x01

#define HD4480_ONOFF				0x08
	#define HD4480_DISP_ON				0x04
	#define HD4480_CURSOR_ON			0x02
	#define HD4480_CURSOR_OFF			0
	#define HD4480_CURSOR_BLINK			0x01

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

#define HD44780_DDRAN_SET_ADDRESS	0x80


void sendHalfByte(uint8_t data);


