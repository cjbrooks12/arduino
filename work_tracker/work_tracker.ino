/**
  The beginnings of my work tracker. This sketch will create a REST API 
  through bridge and connect it to several auxillary services, such as
  getting the real time, checking for email or flowdock messages, and 
  determining whether I am currently clocked in or not. All external 
  interrupts should be like a simple gateway to commands available
  through the REST API, and the buttons will only access the basic
  functions, leaving much more than can be done with the REST API.
*/

#include <LiquidCrystal.h>
#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>
#include <stdlib.h>

YunServer server;

//listing of all pins that will be used for any loop function. Set them all
//up at the very beginning and try to avoid having to change them later

int BUS[3] = { 5, 6, 7 };
int LED_SELECT[5] = { 22, 24, 26, 28, 30 };
int POT = A15;
int PIEZO = 32;

int WAIT = 1;
int WAIT_MULTIPLIER = 1;

int FUNCTION = 1;
int checkClientCount = 0;

LiquidCrystal lcd(42, 43, 40, 41, 38, 39);

int DS = 31;
int ST_CP = 32;
int SH_CP = 30;

//main Arduino setup code 
//------------------------------------------------------------------------------
void setup() {
    // Bridge startup
    pinMode(13, OUTPUT);
    digitalWrite(13, LOW);

    //setup LEDs and other peripherals
    for(int i = 0; i < 3; i++) {
        pinMode(BUS[i], OUTPUT);
    }

    for(int i = 0; i < 5; i++) {
        pinMode(LED_SELECT[i], OUTPUT);
        digitalWrite(LED_SELECT[i], LOW);
    }

    pinMode(POT, INPUT);
    pinMode(PIEZO, OUTPUT);

    pinMode(DS, OUTPUT);
    pinMode(ST_CP, OUTPUT);
    pinMode(SH_CP, OUTPUT);

    digitalWrite(ST_CP, LOW);
    shiftOut(DS, SH_CP, MSBFIRST, 0);
    digitalWrite(ST_CP, HIGH);

    analogWrite(5, 255);
    analogWrite(6, 0);
    analogWrite(7, 0);
    
    lcd.begin(20, 4);
    lcd.clear();
    lcd.write("Starting Bridge...");
    Bridge.begin();

    lcd.setCursor(0, 1);
    lcd.write("Done");
    digitalWrite(13, HIGH);

    server.listenOnLocalhost();
    server.begin();

    analogWrite(5, 0);
    analogWrite(6, 255);
    analogWrite(7, 255);

    randomSeed(analogRead(0));
}

void loop() {
    
    loopBridge();

    if(FUNCTION == 1) {
        loopCrossfader();
    }
    else {
        loopNothing();
    }
}

//code to loop nothing, essentially, giving full control over to the REST API
//to turn on and off pins as desired
//------------------------------------------------------------------------------
void setupNothing() {
  //setup LEDs and other peripherals
    for(int i = 0; i < 3; i++) {
        pinMode(BUS[i], OUTPUT);
    }

    for(int i = 0; i < 5; i++) {
        pinMode(LED_SELECT[i], OUTPUT);
        digitalWrite(LED_SELECT[i], HIGH);
    }

    pinMode(POT, INPUT);
    pinMode(PIEZO, OUTPUT);

    randomSeed(analogRead(0));
}

void loopNothing() {
    digitalWrite(PIEZO, LOW);
    WAIT = WAIT_MULTIPLIER * sqrt(1 + analogRead(POT));
    delay(WAIT);
    digitalWrite(PIEZO, HIGH);
}

//code to manage the REST API through Bridge
//------------------------------------------------------------------------------
void loopBridge() {
    YunClient client = server.accept();

    if (client) {
        process(client);
        client.stop();
    }
}

void process(YunClient client) {
    // read the command
    String command = client.readStringUntil('/');

    if (command == "digital") {
        digitalCommand(client);
    }
    else if (command == "analog") {
        analogCommand(client);
    }
    else if (command == "mode") {
        modeCommand(client);
    }
    else if(command == "function") {
      functionCommand(client);
    }
    else if(command == "lcd") {
      lcdCommand(client);
    }
    else if(command == "status") {
      statusCommand(client);
    }
}

void functionCommand(YunClient client) {
    int function;

    // Read number
    function = client.parseInt();

    if (function == 1) {
        FUNCTION = function;
        setupCrossfader();
        // Send feedback to client
        client.print(F("Now displaying CrossFader"));
        return;
    }

    if (function == 2) {
        FUNCTION = function;
        setupNothing();
        // Send feedback to client
        client.print(F("Now displaying REST calls only"));
        return;
    }

    client.print(F("Invalid function, "));
    client.print(function);
}
