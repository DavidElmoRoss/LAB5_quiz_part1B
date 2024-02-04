/*
This program should increase the count from 0-5 on the top line of the
LCD every time there is a RISING EDGE on SW3

What one statement must you add to this code to make this happen
*/
#include "mbed.h"
#include "Grove_LCD_RGB_Backlight.h"


InterruptIn Sally(SW3);


short counter=0;
char buf[4];

void count(void)
{
    counter++;
}

Grove_LCD_RGB_Backlight lcd(D14,D15);

int main(void)
{
                                     // YOUR STATEMENT goes on THIS LINE
    lcd.clear();
    lcd.setRGB(0x00,0xFF,0x00);
    for(;;)
    {
        if(counter <=5)
        {
          lcd.locate(7,0);
          sprintf(buf,"%d",counter);
          lcd.print(buf);
        }
        else
            {        
                counter=0;
            }
    }
}

