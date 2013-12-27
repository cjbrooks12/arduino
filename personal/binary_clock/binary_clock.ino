int hours_LEDs[] = {13,12,11,10,9,8};
int minutes_LEDs[] = {7,6,5,4,3,2,1};
int hour=2, mminute=16, second=0;
static unsigned long last_tick=0, time_held=0;

void first_time() {
  for(int i = 0; i < 2; i++) {
    for(int i = 0; i < 6; i++) digitalWrite(hours_LEDs[i], HIGH);
    for(int i = 0; i < 7; i++) digitalWrite(minutes_LEDs[i], HIGH);
    digitalWrite(A0, HIGH);
    delay(250);
  
    for(int i = 0; i < 6; i++) digitalWrite(hours_LEDs[i], LOW);
    for(int i = 0; i < 7; i++) digitalWrite(minutes_LEDs[i], LOW);
    digitalWrite(A0, LOW);
    delay(250);
  }
}

void set_time() {
  if(digitalRead(A1) == HIGH) {
    if(millis() - time_held < 50) {
      mminute++;
    } 
    else if(millis() - time_held >= 10000 && millis() - time_held < 50000) {
      mminute++;
    }  
    else if(millis() - time_held >= 50000 && millis() - time_held < 100000) {
      mminute += 10;
    } 
    else if(time_held >= 100000) {
      mminute += 60;
    }  
    //delay(10);
  }
  else time_held = millis();
}

void update_minutes() {
  int temp_min = mminute / 10;
  
  for(int i = 0; i < 3; i++) {
    if(temp_min % 2 == 1) digitalWrite(minutes_LEDs[i], HIGH);
    else digitalWrite(minutes_LEDs[i], LOW);
  
    temp_min /= 2;
  }
  
  temp_min = mminute % 10;
  
  for(int i = 0; i < 4; i++) {
    if(temp_min % 2 == 1) digitalWrite(minutes_LEDs[3+i], HIGH);
    else digitalWrite(minutes_LEDs[3+i], LOW);
  
    temp_min /= 2;
  }
}

void update_hours() {
  int temp_hour = hour / 10;
  
  for(int i = 0; i < 2; i++) {
    if(temp_hour % 2 == 1) digitalWrite(hours_LEDs[i], HIGH);
    else digitalWrite(hours_LEDs[i], LOW);
  
    temp_hour /= 2;
  }
  
  temp_hour = hour % 10;
  
  for(int i = 0; i < 4; i++) {
    if(temp_hour % 2 == 1) digitalWrite(hours_LEDs[2+i], HIGH);
    else digitalWrite(hours_LEDs[2+i], LOW);
  
    temp_hour /= 2;
  }
}

//Arduino functions
//-----------------------------------------------------------------------
void setup() {
  for(int i = 0; i < 6; i++) pinMode(hours_LEDs[i], OUTPUT);
  for(int i = 0; i < 7; i++) pinMode(minutes_LEDs[i], OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  first_time();
}

void loop() {
  //set_time();
  if(millis() - last_tick >= 1000) {
    last_tick = millis();
    second++;
    digitalWrite(A0, HIGH);
    delay(1);
    digitalWrite(A0, LOW); 
  }
  
  if(second >= 60) {
    mminute++;
    second = 0; 
  }
  
  if(mminute >= 60) {
    hour++;
    mminute = 0; 
  }
  
  if(hour >= 24) {
    hour = 0;
  }
  
  update_minutes();
  update_hours();
  
}
