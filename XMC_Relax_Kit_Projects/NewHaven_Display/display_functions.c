
#include "display_database.h"
#include "display_pinout.h"

void digital_write(pin, state){
	if(state == 1){
		DIGITAL_IO_SetOutputHigh(&pin);
	}
	else{
		DIGITAL_IO_SetOutputLow(&pin);
	}
}

void OLED_Command_160128RGB(unsigned char c)        // send command to OLED
{
    unsigned char i;
    unsigned char mask = 0x80;

    switch(interface)
    {
        case 0:
        	digitalWrite(CS_PIN, LOW);
            digitalWrite(RS_PIN, LOW);
            PORTD = c;
            digitalWrite(RW_PIN, LOW);
            digitalWrite(E_PIN, HIGH);
            digitalWrite(E_PIN, LOW);
            digitalWrite(CS_PIN, HIGH);
            break;
        case 1:
        	digitalWrite(CS_PIN, LOW);
            digitalWrite(RS_PIN, LOW);
            digitalWrite(WR_PIN, HIGH);
            PORTD = c;
            digitalWrite(WR_PIN, LOW);
            digitalWrite(WR_PIN, HIGH);
            digitalWrite(CS_PIN, HIGH);
            break;
        case 2:
        	digitalWrite(CS_PIN, LOW);
            digitalWrite(RS_PIN, LOW);
            for(i=0;i<8;i++)
            {
                digitalWrite(SCL_PIN, LOW);
                if((c & mask) >> 7 == 1)
                {
                    digitalWrite(SDI_PIN, HIGH);
                }
                else
                {
                    digitalWrite(SDI_PIN, LOW);
                }
                digitalWrite(SCL_PIN, HIGH);
                c = c << 1;
            }
            digitalWrite(CS_PIN, HIGH);
            break;
        default:  break;
    }
}

void OLED_Data_160128RGB(unsigned char d)        // send data to OLED
{
    unsigned char i;
    unsigned char mask = 0x80;

    switch(interface)
    {
        case 0:
        	digitalWrite(CS_PIN, LOW);
            digitalWrite(RS_PIN, HIGH);
            PORTD = d;
            digitalWrite(RW_PIN, LOW);
            digitalWrite(E_PIN, HIGH);
            digitalWrite(E_PIN, LOW);
            digitalWrite(CS_PIN, HIGH);
            break;
        case 1:
        	digitalWrite(CS_PIN, LOW);
            digitalWrite(RS_PIN, HIGH);
            digitalWrite(WR_PIN, HIGH);
            PORTD = d;
            digitalWrite(WR_PIN, LOW);
            digitalWrite(WR_PIN, HIGH);
            digitalWrite(CS_PIN, HIGH);
            break;
            break;
        case 2:
        	digitalWrite(CS_PIN, LOW);
            digitalWrite(RS_PIN, HIGH);
            for(i=0;i<8;i++)
            {
                digitalWrite(SCL_PIN, LOW);
                if((d & mask) >> 7 == 1)
                {
                    digitalWrite(SDI_PIN, HIGH);
                }
                else
                {
                    digitalWrite(SDI_PIN, LOW);
                }
                digitalWrite(SCL_PIN, HIGH);
                d = d << 1;
            }
            digitalWrite(CS_PIN, HIGH);
            break;
        default:  break;
    }
}

void OLED_SerialPixelData_160128RGB(unsigned char d)    // serial write for pixel data
{
    unsigned char i;
    unsigned char mask = 0x80;
    digitalWrite(CS_PIN, LOW);
    digitalWrite(RS_PIN, HIGH);
    for(i=0;i<6;i++)
    {
        digitalWrite(SCL_PIN, LOW);
        if((d & mask) >> 7 == 1)
        {
            digitalWrite(SDI_PIN, HIGH);
        }
        else
        {
            digitalWrite(SDI_PIN, LOW);
        }
        digitalWrite(SCL_PIN, HIGH);
        d = d << 1;
    }
    digitalWrite(CS_PIN, HIGH);
}

void OLED_SetColumnAddress_160128RGB(unsigned char x_start, unsigned char x_end)    // set column address start + end
{
    OLED_Command_160128RGB(0x17);
    OLED_Data_160128RGB(x_start);
    OLED_Command_160128RGB(0x18);
    OLED_Data_160128RGB(x_end);
}

void OLED_SetRowAddress_160128RGB(unsigned char y_start, unsigned char y_end)    // set row address start + end
{
    OLED_Command_160128RGB(0x19);
    OLED_Data_160128RGB(y_start);
    OLED_Command_160128RGB(0x1A);
    OLED_Data_160128RGB(y_end);
}

void OLED_WriteMemoryStart_160128RGB(void)    // write to RAM command
{
    OLED_Command_160128RGB(0x22);
}

void OLED_Pixel_160128RGB(unsigned long color)    // write one pixel of a given color
{
    switch(interface)
    {
        case 0:
            OLED_Data_160128RGB((color>>16));
            OLED_Data_160128RGB((color>>8));
            OLED_Data_160128RGB(color);
            break;
        case 1:
            OLED_Data_160128RGB((color>>16));
            OLED_Data_160128RGB((color>>8));
            OLED_Data_160128RGB(color);
            break;
        case 2:
            OLED_SerialPixelData_160128RGB((color>>16));
            OLED_SerialPixelData_160128RGB((color>>8));
            OLED_SerialPixelData_160128RGB(color);
            break;
        default:
            break;
    }
}

void OLED_SetPosition_160128RGB(unsigned char x_pos, unsigned char y_pos)    // set x,y address
{
    OLED_Command_160128RGB(0x20);
    OLED_Data_160128RGB(x_pos);
    OLED_Command_160128RGB(0x21);
    OLED_Data_160128RGB(y_pos);
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

void OLED_Text2x_160128RGB(unsigned char x_pos, unsigned char y_pos, unsigned char letter, unsigned long textColor, unsigned long backgroundColor)  // function to show text (2x size)
{
    int i;
    int count;
    unsigned char mask = 0x80;

    for(i=1;i<=16;i++)     // each character is 16 pixels tall
    {
        OLED_SetPosition_160128RGB(x_pos,y_pos);
        OLED_WriteMemoryStart_160128RGB();
        for (count=0;count<10;count++)    // each character is 10 pixels wide
        {
            if((Ascii_1[letter][(count/2)] & mask) == mask)
                OLED_Pixel_160128RGB(textColor);
            else
                OLED_Pixel_160128RGB(backgroundColor);
        }
        y_pos++;
        if((i%2)==0)
        {
            mask = mask >> 1;
        }
    }
}

void OLED_NHDText_160128RGB(unsigned long textColor, unsigned long backgroundColor)    // function to show NEWHAVEN DISPLAY
{
    int i;
    int count;
    unsigned char index = 0;
    unsigned char y_pos = 110;
    unsigned char mask = 0x80;

    for(i=0;i<11;i++)     // display custom character N
    {
        OLED_SetPosition_160128RGB(26,y_pos);
        OLED_WriteMemoryStart_160128RGB();
        for (count=0;count<8;count++)
        {
            if((N10pt[index] & mask) == mask)
                OLED_Pixel_160128RGB(textColor);
            else
                OLED_Pixel_160128RGB(backgroundColor);
            mask = mask >> 1;
        }
        index++;
        mask = 0x80;
        for (count=0;count<8;count++)
        {
            if((N10pt[index] & mask) == mask)
                OLED_Pixel_160128RGB(textColor);
            else
                OLED_Pixel_160128RGB(backgroundColor);
            mask = mask >> 1;
        }
        index++;
        mask = 0x80;
        y_pos--;
    }
    index = 0;
    y_pos = 110;

    for(i=0;i<11;i++)     // display custom character E
    {
        OLED_SetPosition_160128RGB(40,y_pos);
        OLED_WriteMemoryStart_160128RGB();
        for (count=0;count<8;count++)
        {
            if((E10pt[index] & mask) == mask)
                OLED_Pixel_160128RGB(textColor);
            else
                OLED_Pixel_160128RGB(backgroundColor);
            mask = mask >> 1;
        }
        index++;
        mask = 0x80;
        y_pos--;
    }
    index = 0;
    y_pos = 110;

    for(i=0;i<11;i++)     // display custom character W
    {
        OLED_SetPosition_160128RGB(51,y_pos);
        OLED_WriteMemoryStart_160128RGB();
        for (count=0;count<8;count++)
        {
            if((W10pt[index] & mask) == mask)
                OLED_Pixel_160128RGB(textColor);
            else
                OLED_Pixel_160128RGB(backgroundColor);
            mask = mask >> 1;
        }
        index++;
        mask = 0x80;
        for (count=0;count<8;count++)
        {
            if((W10pt[index] & mask) == mask)
                OLED_Pixel_160128RGB(textColor);
            else
                OLED_Pixel_160128RGB(backgroundColor);
            mask = mask >> 1;
        }
        index++;
        mask = 0x80;
        y_pos--;
    }
    index = 0;
    y_pos = 110;

    for(i=0;i<11;i++)     // display custom character H
    {
        OLED_SetPosition_160128RGB(71,y_pos);
        OLED_WriteMemoryStart_160128RGB();
        for (count=0;count<8;count++)
        {
            if((H10pt[index] & mask) == mask)
                OLED_Pixel_160128RGB(textColor);
            else
                OLED_Pixel_160128RGB(backgroundColor);
            mask = mask >> 1;
        }
        index++;
        mask = 0x80;
        y_pos--;
    }
    index = 0;
    y_pos = 110;

    for(i=0;i<11;i++)     // display custom character A
    {
        OLED_SetPosition_160128RGB(83,y_pos);
        OLED_WriteMemoryStart_160128RGB();
        for (count=0;count<8;count++)
        {
            if((A10pt[index] & mask) == mask)
                OLED_Pixel_160128RGB(textColor);
            else
                OLED_Pixel_160128RGB(backgroundColor);
            mask = mask >> 1;
        }
        index++;
        mask = 0x80;
        for (count=0;count<8;count++)
        {
            if((A10pt[index] & mask) == mask)
                OLED_Pixel_160128RGB(textColor);
            else
                OLED_Pixel_160128RGB(backgroundColor);
            mask = mask >> 1;
        }
        index++;
        mask = 0x80;
        y_pos--;
    }
    index = 0;
    y_pos = 110;

    for(i=0;i<11;i++)     // display custom character V
    {
        OLED_SetPosition_160128RGB(96,y_pos);
        OLED_WriteMemoryStart_160128RGB();
        for (count=0;count<8;count++)
        {
            if((V10pt[index] & mask) == mask)
                OLED_Pixel_160128RGB(textColor);
            else
                OLED_Pixel_160128RGB(backgroundColor);
            mask = mask >> 1;
        }
        index++;
        mask = 0x80;
        for (count=0;count<8;count++)
        {
            if((V10pt[index] & mask) == mask)
                OLED_Pixel_160128RGB(textColor);
            else
                OLED_Pixel_160128RGB(backgroundColor);
            mask = mask >> 1;
        }
        index++;
        mask = 0x80;
        y_pos--;
    }
    index = 0;
    y_pos = 110;

    for(i=0;i<11;i++)     // display custom character E
    {
        OLED_SetPosition_160128RGB(110,y_pos);
        OLED_WriteMemoryStart_160128RGB();
        for (count=0;count<8;count++)
        {
            if((E10pt[index] & mask) == mask)
                OLED_Pixel_160128RGB(textColor);
            else
                OLED_Pixel_160128RGB(backgroundColor);
            mask = mask >> 1;
        }
        index++;
        mask = 0x80;
        y_pos--;
    }
    index = 0;
    y_pos = 110;

    for(i=0;i<11;i++)     // display custom character N
    {
        OLED_SetPosition_160128RGB(122,y_pos);
        OLED_WriteMemoryStart_160128RGB();
        for (count=0;count<8;count++)
        {
            if((N10pt[index] & mask) == mask)
                OLED_Pixel_160128RGB(textColor);
            else
                OLED_Pixel_160128RGB(backgroundColor);
            mask = mask >> 1;
        }
        index++;
        mask = 0x80;
        for (count=0;count<8;count++)
        {
            if((N10pt[index] & mask) == mask)
                OLED_Pixel_160128RGB(textColor);
            else
                OLED_Pixel_160128RGB(backgroundColor);
            mask = mask >> 1;
        }
        index++;
        mask = 0x80;
        y_pos--;
    }
    index = 0;
    y_pos = 94;

    for(i=0;i<11;i++)     // display custom character D
    {
        OLED_SetPosition_160128RGB(40,y_pos);
        OLED_WriteMemoryStart_160128RGB();
        for (count=0;count<8;count++)
        {
            if((D10pt[index] & mask) == mask)
                OLED_Pixel_160128RGB(textColor);
            else
                OLED_Pixel_160128RGB(backgroundColor);
            mask = mask >> 1;
        }
        index++;
        mask = 0x80;
        for (count=0;count<8;count++)
        {
            if((D10pt[index] & mask) == mask)
                OLED_Pixel_160128RGB(textColor);
            else
                OLED_Pixel_160128RGB(backgroundColor);
            mask = mask >> 1;
        }
        index++;
        mask = 0x80;
        y_pos--;
    }
    index = 0;
    y_pos = 94;

    for(i=0;i<11;i++)     // display custom character I
    {
        OLED_SetPosition_160128RGB(54,y_pos);
        OLED_WriteMemoryStart_160128RGB();
        for (count=0;count<8;count++)
        {
            if((I10pt[index] & mask) == mask)
                OLED_Pixel_160128RGB(textColor);
            else
                OLED_Pixel_160128RGB(backgroundColor);
            mask = mask >> 1;
        }
        index++;
        mask = 0x80;
        y_pos--;
    }
    index = 0;
    y_pos = 94;

    for(i=0;i<11;i++)     // display custom character S
    {
        OLED_SetPosition_160128RGB(61,y_pos);
        OLED_WriteMemoryStart_160128RGB();
        for (count=0;count<8;count++)
        {
            if((S10pt[index] & mask) == mask)
                OLED_Pixel_160128RGB(textColor);
            else
                OLED_Pixel_160128RGB(backgroundColor);
            mask = mask >> 1;
        }
        index++;
        mask = 0x80;
        y_pos--;
    }
    index = 0;
    y_pos = 94;

    for(i=0;i<11;i++)     // display custom character P
    {
        OLED_SetPosition_160128RGB(72,y_pos);
        OLED_WriteMemoryStart_160128RGB();
        for (count=0;count<8;count++)
        {
            if((P10pt[index] & mask) == mask)
                OLED_Pixel_160128RGB(textColor);
            else
                OLED_Pixel_160128RGB(backgroundColor);
            mask = mask >> 1;
        }
        index++;
        mask = 0x80;
        y_pos--;
    }
    index = 0;
    y_pos = 94;

    for(i=0;i<11;i++)     // display custom character L
    {
        OLED_SetPosition_160128RGB(84,y_pos);
        OLED_WriteMemoryStart_160128RGB();
        for (count=0;count<8;count++)
        {
            if((L10pt[index] & mask) == mask)
                OLED_Pixel_160128RGB(textColor);
            else
                OLED_Pixel_160128RGB(backgroundColor);
            mask = mask >> 1;
        }
        index++;
        mask = 0x80;
        y_pos--;
    }
    index = 0;
    y_pos = 94;

    for(i=0;i<11;i++)     // display custom character A
    {
        OLED_SetPosition_160128RGB(95,y_pos);
        OLED_WriteMemoryStart_160128RGB();
        for (count=0;count<8;count++)
        {
            if((A10pt[index] & mask) == mask)
                OLED_Pixel_160128RGB(textColor);
            else
                OLED_Pixel_160128RGB(backgroundColor);
            mask = mask >> 1;
        }
        index++;
        mask = 0x80;
        for (count=0;count<8;count++)
        {
            if((A10pt[index] & mask) == mask)
                OLED_Pixel_160128RGB(textColor);
            else
                OLED_Pixel_160128RGB(backgroundColor);
            mask = mask >> 1;
        }
        index++;
        mask = 0x80;
        y_pos--;
    }
    index = 0;
    y_pos = 94;

    for(i=0;i<11;i++)     // display custom character Y
    {
        OLED_SetPosition_160128RGB(109,y_pos);
        OLED_WriteMemoryStart_160128RGB();
        for (count=0;count<8;count++)
        {
            if((Y10pt[index] & mask) == mask)
                OLED_Pixel_160128RGB(textColor);
            else
                OLED_Pixel_160128RGB(backgroundColor);
            mask = mask >> 1;
        }
        index++;
        mask = 0x80;
        y_pos--;
    }
}

void OLED_Icon_160128RGB(unsigned char x_pos, unsigned char y_pos)    // function to show icon
{
    unsigned int i, j;
    unsigned int incr = 0;

    for(i=0;i<20;i++)
    {
        OLED_SetPosition_160128RGB(x_pos,y_pos+i);
        OLED_WriteMemoryStart_160128RGB();
        for(j=0;j<60;j+=3)
        {
            switch(interface)
            {
                case 0:
                case 1:
                    OLED_Data_160128RGB(smiley20x20[(j+incr)]);
                    OLED_Data_160128RGB(smiley20x20[((j+incr)+1)]);
                    OLED_Data_160128RGB(smiley20x20[((j+incr)+2)]);
                    break;
                case 2:
                    OLED_SerialPixelData_160128RGB(smiley20x20[(j+incr)]);
                    OLED_SerialPixelData_160128RGB(smiley20x20[((j+incr)+1)]);
                    OLED_SerialPixelData_160128RGB(smiley20x20[((j+incr)+2)]);
                    break;
                default:
                    break;
            }
        }
        incr += 60;
    }
}

void OLED_Spectrum_160128RGB(void)                  // function to show color spectrum
{
    unsigned char i, j;
    unsigned char blue, green, red;

    OLED_SetPosition_160128RGB(0,0);
    OLED_WriteMemoryStart_160128RGB();
    for(i=0;i<160;i++)
    {
        OLED_Pixel_160128RGB(WHITE);
    }
    OLED_SetPosition_160128RGB(0,1);
    OLED_WriteMemoryStart_160128RGB();
    for(i=0;i<160;i++)
    {
        OLED_Pixel_160128RGB(WHITE);
    }
    for(i=0;i<40;i++)
    {
        blue = 0x00;
        green = 0x00;
        red = 0xFF;
        OLED_SetPosition_160128RGB(0,(2+i));
        OLED_WriteMemoryStart_160128RGB();
        OLED_Pixel_160128RGB(WHITE);
        OLED_Pixel_160128RGB(WHITE);
        for(j=0;j<26;j++)
        {
            OLED_Data_160128RGB(blue);
            OLED_Data_160128RGB(green);
            OLED_Data_160128RGB(red);
            green += 9;
        }
        for(j=0;j<26;j++)
        {
            OLED_Data_160128RGB(blue);
            OLED_Data_160128RGB(green);
            OLED_Data_160128RGB(red);
            red -= 9;
        }
        for(j=0;j<26;j++)
        {
            OLED_Data_160128RGB(blue);
            OLED_Data_160128RGB(green);
            OLED_Data_160128RGB(red);
            blue += 9;
        }
        for(j=0;j<26;j++)
        {
            OLED_Data_160128RGB(blue);
            OLED_Data_160128RGB(green);
            OLED_Data_160128RGB(red);
            green -= 9;
        }
        for(j=0;j<26;j++)
        {
            OLED_Data_160128RGB(blue);
            OLED_Data_160128RGB(green);
            OLED_Data_160128RGB(red);
            red += 9;
        }
        for(j=0;j<26;j++)
        {
            OLED_Data_160128RGB(blue);
            OLED_Data_160128RGB(green);
            OLED_Data_160128RGB(red);
            blue -= 9;
        }
        OLED_Pixel_160128RGB(WHITE);
        OLED_Pixel_160128RGB(WHITE);
    }

    OLED_SetPosition_160128RGB(0,42);
    OLED_WriteMemoryStart_160128RGB();
    for(i=0;i<160;i++)
    {
        OLED_Pixel_160128RGB(WHITE);
    }
    OLED_SetPosition_160128RGB(0,43);
    OLED_WriteMemoryStart_160128RGB();
    for(i=0;i<160;i++)
    {
        OLED_Pixel_160128RGB(WHITE);
    }
}



/*********************************/
/******** INITIALIZATION *********/
/************ START **************/
/*********************************/

void OLED_Init_160128RGB(void)      //OLED initialization
{
    digitalWrite(RES_PIN, LOW);
    delay(2);
    digitalWrite(RES_PIN, HIGH);
    delay(2);

    // display off, analog reset
    OLED_Command_160128RGB(0x04);
    OLED_Data_160128RGB(0x01);
    delay(1);

     // normal mode
    OLED_Command_160128RGB(0x04);
    OLED_Data_160128RGB(0x00);
    delay(1);

    // display off
    OLED_Command_160128RGB(0x06);
    OLED_Data_160128RGB(0x00);
    delay(1);

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
}


/*===============================*/
/*======= INITIALIZATION ========*/
/*============= END =============*/
/*===============================*/

void setup()
{
    pinMode(LVL_OEN, OUTPUT);                       // configure LVL_OEN as output
    digitalWrite(LVL_OEN, LOW);
    pinMode(LVL_DIR, OUTPUT);                       // configure LVL_DIR as output
    digitalWrite(LVL_DIR, HIGH);
    DDRD = 0xFF;                                    // configure PORTD as output
    pinMode(RS_PIN, OUTPUT);                        // configure RS_PIN as output
    pinMode(RES_PIN, OUTPUT);                       // configure RES_PIN as output
    pinMode(CS_PIN, OUTPUT);                        // configure CS_PIN as output
    pinMode(PS_PIN, OUTPUT);                        // configure PS_PIN as output
    pinMode(CPU_PIN, OUTPUT);                       // configure CPU_PIN as output
    digitalWrite(LVL_OEN, LOW);
    digitalWrite(CS_PIN, HIGH);                     // set CS_PIN
    switch(interface)
    {
        case 0:
            pinMode(RW_PIN, OUTPUT);                    // configure RW_PIN as output
            pinMode(E_PIN, OUTPUT);                     // configure E_PIN as output
            digitalWrite(PS_PIN, HIGH);                 // set PS_PIN
            digitalWrite(CPU_PIN, HIGH);                // set CPU_PIN
            digitalWrite(RW_PIN, LOW);                  // reset RW_PIN
            digitalWrite(E_PIN, HIGH);                  // set E_PIN
            break;
        case 1:
            pinMode(WR_PIN, OUTPUT);                    // configure WR_PIN as output
            pinMode(RD_PIN, OUTPUT);                    // configure RD_PIN as output
            digitalWrite(PS_PIN, HIGH);                 // set PS_PIN
            digitalWrite(CPU_PIN, LOW);                 // reset CPU_PIN
            digitalWrite(WR_PIN, HIGH);                 // set WR_PIN
            digitalWrite(RD_PIN, HIGH);                 // set RD_PIN
            break;
        case 2:
            pinMode(SDI_PIN, OUTPUT);                   // configure SDI_PIN as output
            pinMode(SCL_PIN, OUTPUT);                   // configure SCL_PIN as output
            PORTD = 0x00;                               // reset SDI_PIN and SCL_PIN, ground DB[5..0] of the display
            digitalWrite(PS_PIN, LOW);                  // reset PS_PIN
            break;
        default:
            break;
    }
}

void loop()                                         // main loop, runs after "setup()"
{
    OLED_Init_160128RGB();                           // initialize display

    OLED_FillScreen_160128RGB(BLACK);                // fill screen with black

    OLED_NHDText_160128RGB(GREEN, BLACK);            // show NEWHAVEN DISPLAY

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

    OLED_Icon_160128RGB(120, 52);                    // show icon

    OLED_Spectrum_160128RGB();                       // show color spectrum

    while(1);                                        // wait here forever
}
