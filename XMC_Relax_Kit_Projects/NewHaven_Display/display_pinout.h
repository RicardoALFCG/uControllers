#ifndef DISPLAY_PINOUT_H_
#define DISPLAY_PINOUT_H_

// The 8 bit data bus is connected to PORTD[7..0]

#define LOW 0
#define HIGH 1

#define   SDI_PIN   11    // SDI (serial mode) signal connected to pin 11
#define   SCL_PIN   13    // SCL (serial mdoe) signal connected to pin 13
#define    RS_PIN    4    // RS signal connected to pin 4
#define    RW_PIN    9    // R/W (6800 mode) signal connected to pin 9
#define    WR_PIN    9    // /WR (8080 mode) signal connected to pin 9
#define     E_PIN   10    // E (6800 mode) signal connected to pin 10
#define    RD_PIN   10    // /RD (8080 mode) signal connected to pin 10
#define   RES_PIN   6    // /RES signal connected to pin 6
#define    CS_PIN   5    // /CS signal connected to pin 5
#define    PS_PIN   A0    // PS signal connected to pin A0
#define   CPU_PIN   A1    // CPU signal connected to pin A1
#define   LVL_DIR   A2    // DIR (direction control) signal of level shifter IC connected to pin A2
#define   LVL_OEN   A3    // /OE (output enable) signal of level shifter IC connected to pin A3

#define    RED  0x0000FF
#define  GREEN  0x00FF00
#define   BLUE  0xFF0000
#define  WHITE  0xFFFFFF
#define  BLACK  0x000000













#endif /* DISPLAY_PINOUT_H_ */
