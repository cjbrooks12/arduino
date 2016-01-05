void digitalCommand(YunClient client) {
    int pin = client.readStringUntil('/').toInt();
    String value = client.readStringUntil('\r');

    if (value == "high") {
        digitalWrite(pin, HIGH);
        client.print("Pin D");
        client.print(pin);
        client.print(" set to HIGH");
    }
    else if(value == "low") {
        digitalWrite(pin, LOW);
        client.print("Pin D");
        client.print(pin);
        client.print(" set to LOW");
    }
    else if(value == "read") {
        int readValue = digitalRead(pin);
        client.print("Pin D");
        client.print(pin);
        client.print(" has value ");
        if(readValue == 0) {
            client.print("LOW");
        }
        else {
            client.print("LOW");
        }
    }
    else {
        client.print("error: invalid digital value ");
        client.print(value);
    }
}

void analogCommand(YunClient client) {
    int pin = client.readStringUntil('/').toInt();
    String value = client.readStringUntil('\r');

    if (value == "read") {
        int analogValue = analogRead(pin);

        // Send feedback to client
        client.print("Pin A");
        client.print(pin);
        client.print(" reads analog ");
        client.println(analogValue);
    }
    else { // Read value and execute command
        int analogValue = value.toInt();
        analogWrite(pin, analogValue);

        // Send feedback to client
        client.print("Pin D");
        client.print(pin);
        client.print(" set to analog ");
        client.println(analogValue);
    }
}

void modeCommand(YunClient client) {
    int pin = client.readStringUntil('/').toInt();
    String value = client.readStringUntil('\r');

    if (value == "input") {
        pinMode(pin, INPUT);
        // Send feedback to client
        client.print("Pin D");
        client.print(pin);
        client.print(" configured as INPUT!");
    }
    else if (value == "output") {
        pinMode(pin, OUTPUT);
        client.print("Pin D");
        client.print(pin);
        client.print(" configured as OUTPUT!");
    }
    else {
        client.print("error: invalid mode ");
        client.print(value);
    }
}
