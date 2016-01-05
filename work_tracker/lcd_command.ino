void lcdCommand(YunClient client) {
    String lcdFunction = client.readStringUntil('/');

    if(lcdFunction == "clear") {
        lcdClearCommand(client);
    }
    else if(lcdFunction == "write") {
        lcdWriteCommand(client);
    }
    else if(lcdFunction == "color") {
        lcdColorCommand(client);
    }
}

void lcdClearCommand(YunClient client) {
    int row = client.parseInt();
    
    clearLCD(row);

    client.print(F("Cleared LCD row "));
    client.print(row);
}

void lcdWriteCommand(YunClient client) {
    int row = client.readStringUntil('/').toInt();
    String value = client.readStringUntil('\r');
  
    writeToLcd(row, value);
    
    client.print("Writing '");
    client.print(value);
    client.print("' to row ");
    client.println(row);
}

void lcdColorCommand(YunClient client) {
    String hex = client.readStringUntil('\r');

    int* rgb = (int*) malloc(3*sizeof(int));
    
    stringToRGB(rgb, hex);
    
    int r = rgb[0];
    int g = rgb[1];
    int b = rgb[2];
    analogWrite(5, r);
    analogWrite(6, g);
    analogWrite(7, b);
    
    client.println("Changed LCD color to: ");

    client.print("#");
    client.println(hex);
    client.print(r);
    client.print(",");
    client.print(g);
    client.print(",");
    client.print(b);
}

