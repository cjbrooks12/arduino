//convert the 6-character String RRGGBB into its component colors
void stringToRGB(int* rgb, String hex) {
    long number = strtol(hex.c_str(), NULL, 16);
    long r = number >> 16;
    long g = number >> 8 & 0xFF;
    long b = number & 0xFF;

    rgb[0] = (int) r;
    rgb[1] = (int) g;
    rgb[2] = (int) b;
}

//clear LCD screen at the specified row, or -1 to clear the whole screen
void clearLCD(int row) {
    if(row != -1) {
        lcd.setCursor(0, row);
        lcd.print("                    ");
    }
    else if(row == -1) {
        lcd.clear();
    }
}

//writes the text to the specified row. Text will only be written to the
//specified row and will not overflow. If row is -1, then text will write 
//as much as it possibly can, overwriting anything else that may be there
void writeToLcd(int row, String text) {
    clearLCD(row);

    if(row != -1) {
        if(text.length() > 20) {
            text = text.substring(0, 20);
        }
        
        lcd.setCursor(0, row);
        lcd.print(text);
    }
    else if(row == -1) {


      
        for(int i = 0; i < 4; i++) {
            lcd.setCursor(0, i);
            if(text.length() > 20) {
                lcd.print(text.substring(0, 20));
                text = text.substring(20);
                continue;
            }
            else {
                lcd.print(text);
                break;
            }
        }
        
    }
}

