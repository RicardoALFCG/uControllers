#ifndef DISPLAY_FUNCTIONS_H_
#define DISPLAY_FUNCTIONS_H_

#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)


#define    RED  0x0000FF
#define  GREEN  0x00FF00
#define   BLUE  0xFF0000
#define  WHITE  0xFFFFFF
#define  BLACK  0x000000


/* Low Level Functions*/
void OLED_Command_160128RGB(unsigned char c);
void OLED_Data_160128RGB(unsigned char d);
void OLED_SerialPixelData_160128RGB(unsigned char d);
void OLED_SetColumnAddress_160128RGB(unsigned char x_start, unsigned char x_end);
void OLED_SetRowAddress_160128RGB(unsigned char y_start, unsigned char y_end);
void OLED_WriteMemoryStart_160128RGB(void);
void OLED_Pixel_160128RGB(unsigned long color);
void OLED_SetPosition_160128RGB(unsigned char x_pos, unsigned char y_pos);
void OLED_FillScreen_160128RGB(unsigned long color);

/* High Level Functions*/
void OLED_Text_160128RGB(unsigned char x_pos, unsigned char y_pos, unsigned char letter, unsigned long textColor, unsigned long backgroundColor);
void OLED_Text2x_160128RGB(unsigned char x_pos, unsigned char y_pos, unsigned char letter, unsigned long textColor, unsigned long backgroundColor);
void OLED_NHDText_160128RGB(unsigned long textColor, unsigned long backgroundColor);
void OLED_Icon_160128RGB(unsigned char x_pos, unsigned char y_pos);
void OLED_Spectrum_160128RGB(void);


/*Setup */
void loop();
void display_setup();
void OLED_Init_160128RGB(void);

#endif
