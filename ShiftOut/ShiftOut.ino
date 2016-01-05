//**************************************************************//
//  Name    : shiftOutCode, Hello World                         //
//  Author  : Carlyn Maw,Tom Igoe                               //
//  Date    : 25 Oct, 2006                                      //
//  Version : 1.0                                               //
//  Notes   : Code for using a 74HC595 Shift Register           //
//          : to count from 0 to 255                            //
//****************************************************************

//Pin connected to ST_CP of 74HC595
int DS = 31;
//Pin connected to SH_CP of 74HC595
int ST_CP = 32;
////Pin connected to DS of 74HC595
int SH_CP = 30;

void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(DS, OUTPUT);
  pinMode(ST_CP, OUTPUT);
  pinMode(SH_CP, OUTPUT);
}

void loop() {
    //R1
    digitalWrite(ST_CP, LOW);
    shiftOut(DS, SH_CP, MSBFIRST, B00000001);   
    digitalWrite(ST_CP, HIGH);
    delay(1000);

    //G1
    digitalWrite(ST_CP, LOW);
    shiftOut(DS, SH_CP, MSBFIRST, B00000010);
    digitalWrite(ST_CP, HIGH);
    delay(1000);

    //B1
    digitalWrite(ST_CP, LOW);
    shiftOut(DS, SH_CP, MSBFIRST, B00000100);   
    digitalWrite(ST_CP, HIGH);
    delay(1000);

    //G1
    digitalWrite(ST_CP, LOW);
    shiftOut(DS, SH_CP, MSBFIRST, B00001000);
    digitalWrite(ST_CP, HIGH);
    delay(1000);

    //G1
    digitalWrite(ST_CP, LOW);
    shiftOut(DS, SH_CP, MSBFIRST, B00010000);
    digitalWrite(ST_CP, HIGH);
    delay(1000);

    //G1
    digitalWrite(ST_CP, LOW);
    shiftOut(DS, SH_CP, MSBFIRST, B00100000);
    digitalWrite(ST_CP, HIGH);
    delay(1000);

    //G1
    digitalWrite(ST_CP, LOW);
    shiftOut(DS, SH_CP, MSBFIRST, B01000000);
    digitalWrite(ST_CP, HIGH);
    delay(1000);

    //G1
    digitalWrite(ST_CP, LOW);
    shiftOut(DS, SH_CP, MSBFIRST, B10000000);
    digitalWrite(ST_CP, HIGH);
    delay(1000);
} 
