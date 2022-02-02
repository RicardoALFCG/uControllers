#include"display_functions.h"
#include"display_database.h"


void display_setup(){
	SPI_MASTER_Init (&SPI_MASTER_0);
	DIGITAL_IO_SetOutputLow(&RESET);

    DIGITAL_IO_SetOutputHigh(&RESET);
	DIGITAL_IO_SetOutputHigh(&REGISTER_SIGNAL);
	DIGITAL_IO_SetOutputHigh(&OLED_CS);


    // display off, analog reset
    OLED_Command_160128RGB(0x04);
    OLED_Data_160128RGB(0x01);

     // normal mode
    OLED_Command_160128RGB(0x04);
    OLED_Data_160128RGB(0x00);

    // display off
    OLED_Command_160128RGB(0x06);
    OLED_Data_160128RGB(0x00);

    // turn on internal oscillator using external resistor
    OLED_Command_160128RGB(0x02);
    OLED_Data_160128RGB(0x01);

    // 90 hz frame rate, divider 0
    OLED_Command_160128RGB(0x03);
    OLED_Data_160128RGB(0x30);

    // duty cycle 127
    OLED_Command_160128RGB(0x28);
    OLED_Data_160128RGB(0x7F);

    // start on line 0
    OLED_Command_160128RGB(0x29);
    OLED_Data_160128RGB(0x00);

    // rgb_if
    OLED_Command_160128RGB(0x14);
    OLED_Data_160128RGB(0x31);

    // Set Memory Write Mode
    OLED_Command_160128RGB(0x16);
    OLED_Data_160128RGB(0x76);

    // driving current r g b (uA)
    OLED_Command_160128RGB(0x10);
    OLED_Data_160128RGB(0x45);
    OLED_Command_160128RGB(0x11);
    OLED_Data_160128RGB(0x34);
    OLED_Command_160128RGB(0x12);
    OLED_Data_160128RGB(0x33);

    // precharge time r g b
    OLED_Command_160128RGB(0x08);
    OLED_Data_160128RGB(0x04);
    OLED_Command_160128RGB(0x09);
    OLED_Data_160128RGB(0x05);
    OLED_Command_160128RGB(0x0A);
    OLED_Data_160128RGB(0x05);

    // precharge current r g b (uA)
    OLED_Command_160128RGB(0x0B);
    OLED_Data_160128RGB(0x9D);
    OLED_Command_160128RGB(0x0C);
    OLED_Data_160128RGB(0x8C);
    OLED_Command_160128RGB(0x0D);
    OLED_Data_160128RGB(0x57);

    // Set Reference Voltage Controlled by External Resister
    OLED_Command_160128RGB(0x80);
    OLED_Data_160128RGB(0x00);

    // mode set
    OLED_Command_160128RGB(0x13);
    OLED_Data_160128RGB(0xA0);

    OLED_SetColumnAddress_160128RGB(0, 159);
    OLED_SetRowAddress_160128RGB(0, 127);

    // Display On
    OLED_Command_160128RGB(0x06);
    OLED_Data_160128RGB(0x01);

    OLED_FillScreen_160128RGB(BLACK);                // fill screen with black

   // OLED_NHDText_160128RGB(GREEN, BLACK);            // show NEWHAVEN DISPLAY

    OLED_Text_160128RGB(20, 58, 40, WHITE, BLACK);   // H
	OLED_Text_160128RGB(27, 58, 69, WHITE, BLACK);   // e
	OLED_Text_160128RGB(34, 58, 76, WHITE, BLACK);   // l
	OLED_Text_160128RGB(41, 58, 76, WHITE, BLACK);   // l
	OLED_Text_160128RGB(48, 58, 79, WHITE, BLACK);   // o
	OLED_Text_160128RGB(55, 58, 0, WHITE, BLACK);    //

	OLED_Text_160128RGB(62, 58, 55, WHITE, BLACK);   // W
	OLED_Text_160128RGB(69, 58, 79, WHITE, BLACK);   // o
	OLED_Text_160128RGB(76, 58, 82, WHITE, BLACK);   // r
	OLED_Text_160128RGB(83, 58, 76, WHITE, BLACK);   // l
	OLED_Text_160128RGB(90, 58, 68, WHITE, BLACK);   // d
	OLED_Text_160128RGB(97, 58, 1, WHITE, BLACK);    // !
}


void OLED_Command_160128RGB(uint8_t command){
	DIGITAL_IO_SetOutputLow(&REGISTER_SIGNAL);
	SPI_MASTER_Transmit(&SPI_MASTER_0, command, sizeof(command));
	DIGITAL_IO_SetOutputHigh(&REGISTER_SIGNAL);
	}

void OLED_Data_160128RGB(uint8_t data){
	SPI_MASTER_Transmit(&SPI_MASTER_0, data, sizeof(data));
}

void OLED_Text_160128RGB(unsigned char x_pos, unsigned char y_pos, unsigned char letter, unsigned long textColor, unsigned long backgroundColor)  // function to show text
{
    int i;
    int count;
    unsigned char mask = 0x80;

    for(i=0;i<8;i++)     // each character is 8 pixels tall
    {
        OLED_SetPosition_160128RGB(x_pos,y_pos);
        OLED_WriteMemoryStart_160128RGB();
        for (count=0;count<5;count++)    // each character is 5 pixels wide
        {
            if((Ascii_1[letter][count] & mask) == mask)
                OLED_Pixel_160128RGB(textColor);
            else
                OLED_Pixel_160128RGB(backgroundColor);
        }
        y_pos++;
        mask = mask >> 1;
    }
}

void OLED_SetColumnAddress_160128RGB(unsigned char x_start, unsigned char x_end){
    OLED_Command_160128RGB(0x17);
    OLED_Data_160128RGB(x_start);
    OLED_Command_160128RGB(0x18);
    OLED_Data_160128RGB(x_end);
}

void OLED_SetRowAddress_160128RGB(unsigned char y_start, unsigned char y_end){
    OLED_Command_160128RGB(0x19);
    OLED_Data_160128RGB(y_start);
    OLED_Command_160128RGB(0x1A);
    OLED_Data_160128RGB(y_end);
}

void OLED_FillScreen_160128RGB(unsigned long color)    // fill screen with a given color
{
    unsigned int i;
    OLED_SetPosition_160128RGB(0,0);
    OLED_WriteMemoryStart_160128RGB();
    for(i=0;i<20480;i++)
    {
        OLED_Pixel_160128RGB(color);
    }
}

void OLED_SetPosition_160128RGB(unsigned char x_pos, unsigned char y_pos)    // set x,y address
{
    OLED_Command_160128RGB(0x20);
    OLED_Data_160128RGB(x_pos);
    OLED_Command_160128RGB(0x21);
    OLED_Data_160128RGB(y_pos);
}

void OLED_WriteMemoryStart_160128RGB(void)    // write to RAM command
{
    OLED_Command_160128RGB(0x22);
}

void OLED_Pixel_160128RGB(unsigned long color)    // write one pixel of a given color
{
	OLED_SerialPixelData_160128RGB((color>>16));
	OLED_SerialPixelData_160128RGB((color>>8));
	OLED_SerialPixelData_160128RGB(color);
}

void OLED_SerialPixelData_160128RGB(unsigned char d)    // serial write for pixel data
{

    DIGITAL_IO_SetOutputLow(&OLED_CS);
    DIGITAL_IO_SetOutputLow(&RESET);

	SPI_MASTER_Transmit(&SPI_MASTER_0, d, sizeof(d));

    DIGITAL_IO_SetOutputHigh(&OLED_CS);
}
