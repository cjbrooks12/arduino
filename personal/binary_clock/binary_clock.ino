int hours_LEDs[] = {13,12,11,10,9,8};
int minutes_LEDs[] = {7,6,5,4,3,2,1};
int hour=1, mminute=03, second=0;
static unsigned long last_tick=0, time_held=0;

void first_time() {
  for(int i = 0; i < 6; i++) digitalWrite(hours_LEDs[i], HIGH);
  for(int i = 0; i < 7; i++) digitalWrite(minutes_LEDs[i], HIGH);
  digitalWrite(A0, HIGH);
  delay(250);
  
  for(int i = 0; i < 6; i++) digitalWrite(hours_LEDs[i], LOW);
  for(int i = 0; i < 7; i++) digitalWrite(minutes_LEDs[i], LOW);
  digitalWrite(A0, LOW);
  delay(250);
  
  for(int i = 0; i < 6; i++) digitalWrite(hours_LEDs[i], HIGH);
  for(int i = 0; i < 7; i++) digitalWrite(minutes_LEDs[i], HIGH);
  digitalWrite(A0, HIGH);
  delay(250);
  
  for(int i = 0; i < 6; i++) digitalWrite(hours_LEDs[i], LOW);
  for(int i = 0; i < 7; i++) digitalWrite(minutes_LEDs[i], LOW);
  digitalWrite(A0, LOW);
  delay(250);
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
  int minute_tens = mminute / 10;
  int minute_ones = mminute % 10;
  
  switch(minute_tens) {
  case 0:
    digitalWrite(minutes_LEDs[0], LOW);
    digitalWrite(minutes_LEDs[1], LOW);
    digitalWrite(minutes_LEDs[2], LOW);
    break;
  case 1:
    digitalWrite(minutes_LEDs[0], HIGH);
    digitalWrite(minutes_LEDs[1], LOW);
    digitalWrite(minutes_LEDs[2], LOW);
    break;
  case 2:
    digitalWrite(minutes_LEDs[0], LOW);
    digitalWrite(minutes_LEDs[1], HIGH);
    digitalWrite(minutes_LEDs[2], LOW);
    break;
  case 3:
    digitalWrite(minutes_LEDs[0], HIGH);
    digitalWrite(minutes_LEDs[1], HIGH);
    digitalWrite(minutes_LEDs[2], LOW);
    break;
  case 4:
    digitalWrite(minutes_LEDs[0], LOW);
    digitalWrite(minutes_LEDs[1], LOW);
    digitalWrite(minutes_LEDs[2], HIGH);
    break;
  case 5:
    digitalWrite(minutes_LEDs[0], HIGH);
    digitalWrite(minutes_LEDs[1], LOW);
    digitalWrite(minutes_LEDs[2], HIGH);
    break;
  case 6:
    digitalWrite(minutes_LEDs[0], LOW);
    digitalWrite(minutes_LEDs[1], HIGH);
    digitalWrite(minutes_LEDs[2], HIGH);
    break;
  case 7:
    digitalWrite(minutes_LEDs[0], HIGH);
    digitalWrite(minutes_LEDs[1], HIGH);
    digitalWrite(minutes_LEDs[2], HIGH);
    break;
  case 8:
    digitalWrite(minutes_LEDs[0], LOW);
    digitalWrite(minutes_LEDs[1], LOW);
    digitalWrite(minutes_LEDs[2], LOW);
    break;
  case 9:
    digitalWrite(minutes_LEDs[0], HIGH);
    digitalWrite(minutes_LEDs[1], LOW);
    digitalWrite(minutes_LEDs[2], LOW);
    break;
  } 
 
  switch(minute_ones) {
  case 0:
    digitalWrite(minutes_LEDs[3], LOW);
    digitalWrite(minutes_LEDs[4], LOW);
    digitalWrite(minutes_LEDs[5], LOW);
    digitalWrite(minutes_LEDs[6], LOW);
    break;
  case 1:
    digitalWrite(minutes_LEDs[3], HIGH);
    digitalWrite(minutes_LEDs[4], LOW);
    digitalWrite(minutes_LEDs[5], LOW);
    digitalWrite(minutes_LEDs[6], LOW);
    break;
  case 2:
    digitalWrite(minutes_LEDs[3], LOW);
    digitalWrite(minutes_LEDs[4], HIGH);
    digitalWrite(minutes_LEDs[5], LOW);
    digitalWrite(minutes_LEDs[6], LOW);
    break;
  case 3:
    digitalWrite(minutes_LEDs[3], HIGH);
    digitalWrite(minutes_LEDs[4], HIGH);
    digitalWrite(minutes_LEDs[5], LOW);
    digitalWrite(minutes_LEDs[6], LOW);
    break;
  case 4:
    digitalWrite(minutes_LEDs[3], LOW);
    digitalWrite(minutes_LEDs[4], LOW);
    digitalWrite(minutes_LEDs[5], HIGH);
    digitalWrite(minutes_LEDs[6], LOW);
    break;
  case 5:
    digitalWrite(minutes_LEDs[3], HIGH);
    digitalWrite(minutes_LEDs[4], LOW);
    digitalWrite(minutes_LEDs[5], HIGH);
    digitalWrite(minutes_LEDs[6], LOW);
    break;
  case 6:
    digitalWrite(minutes_LEDs[3], LOW);
    digitalWrite(minutes_LEDs[4], HIGH);
    digitalWrite(minutes_LEDs[5], HIGH);
    digitalWrite(minutes_LEDs[6], LOW);
    break;
  case 7:
    digitalWrite(minutes_LEDs[3], HIGH);
    digitalWrite(minutes_LEDs[4], HIGH);
    digitalWrite(minutes_LEDs[5], HIGH);
    digitalWrite(minutes_LEDs[6], LOW);
    break;
  case 8:
    digitalWrite(minutes_LEDs[3], LOW);
    digitalWrite(minutes_LEDs[4], LOW);
    digitalWrite(minutes_LEDs[5], LOW);
    digitalWrite(minutes_LEDs[6], HIGH);
    break;
  case 9:
    digitalWrite(minutes_LEDs[3], HIGH);
    digitalWrite(minutes_LEDs[4], LOW);
    digitalWrite(minutes_LEDs[5], LOW);
    digitalWrite(minutes_LEDs[6], HIGH);
    break;
  } 
}

void update_hours() {
  int hour_tens = hour / 10;
  int hour_ones = hour % 10;
  
  switch(hour_tens) {
  case 0:
    digitalWrite(hours_LEDs[0], LOW);
    digitalWrite(hours_LEDs[1], LOW);
    break;
  case 1:
    digitalWrite(hours_LEDs[0], HIGH);
    digitalWrite(hours_LEDs[1], LOW);
    break;
  case 2:
    digitalWrite(hours_LEDs[0], LOW);
    digitalWrite(hours_LEDs[1], HIGH);
    break;
  case 3:
    digitalWrite(hours_LEDs[0], HIGH);
    digitalWrite(hours_LEDs[1], HIGH);
    break;
  case 4:
    digitalWrite(hours_LEDs[0], LOW);
    digitalWrite(hours_LEDs[1], LOW);
    break;
  case 5:
    digitalWrite(hours_LEDs[0], HIGH);
    digitalWrite(hours_LEDs[1], LOW);
    break;
  case 6:
    digitalWrite(hours_LEDs[0], LOW);
    digitalWrite(hours_LEDs[1], HIGH);
    break;
  case 7:
    digitalWrite(hours_LEDs[0], HIGH);
    digitalWrite(hours_LEDs[1], HIGH);
    break;
  case 8:
    digitalWrite(hours_LEDs[0], LOW);
    digitalWrite(hours_LEDs[1], LOW);
    break;
  case 9:
    digitalWrite(hours_LEDs[0], HIGH);
    digitalWrite(hours_LEDs[1], LOW);
    break;
  } 
 
  switch(hour_ones) {
  case 0:
    digitalWrite(hours_LEDs[2], LOW);
    digitalWrite(hours_LEDs[3], LOW);
    digitalWrite(hours_LEDs[4], LOW);
    digitalWrite(hours_LEDs[5], LOW);
    break;
  case 1:
    digitalWrite(hours_LEDs[2], HIGH);
    digitalWrite(hours_LEDs[3], LOW);
    digitalWrite(hours_LEDs[4], LOW);
    digitalWrite(hours_LEDs[5], LOW);
    break;
  case 2:
    digitalWrite(hours_LEDs[2], LOW);
    digitalWrite(hours_LEDs[3], HIGH);
    digitalWrite(hours_LEDs[4], LOW);
    digitalWrite(hours_LEDs[5], LOW);
    break;
  case 3:
    digitalWrite(hours_LEDs[2], HIGH);
    digitalWrite(hours_LEDs[3], HIGH);
    digitalWrite(hours_LEDs[4], LOW);
    digitalWrite(hours_LEDs[5], LOW);
    break;
  case 4:
    digitalWrite(hours_LEDs[2], LOW);
    digitalWrite(hours_LEDs[3], LOW);
    digitalWrite(hours_LEDs[4], HIGH);
    digitalWrite(hours_LEDs[5], LOW);
    break;
  case 5:
    digitalWrite(hours_LEDs[2], HIGH);
    digitalWrite(hours_LEDs[3], LOW);
    digitalWrite(hours_LEDs[4], HIGH);
    digitalWrite(hours_LEDs[5], LOW);
    break;
  case 6:
    digitalWrite(hours_LEDs[2], LOW);
    digitalWrite(hours_LEDs[3], HIGH);
    digitalWrite(hours_LEDs[4], HIGH);
    digitalWrite(hours_LEDs[5], LOW);
    break;
  case 7:
    digitalWrite(hours_LEDs[2], HIGH);
    digitalWrite(hours_LEDs[3], HIGH);
    digitalWrite(hours_LEDs[4], HIGH);
    digitalWrite(hours_LEDs[5], LOW);
    break;
  case 8:
    digitalWrite(hours_LEDs[2], LOW);
    digitalWrite(hours_LEDs[3], LOW);
    digitalWrite(hours_LEDs[4], LOW);
    digitalWrite(hours_LEDs[5], HIGH);
    break;
  case 9:
    digitalWrite(hours_LEDs[2], HIGH);
    digitalWrite(hours_LEDs[3], LOW);
    digitalWrite(hours_LEDs[4], LOW);
    digitalWrite(hours_LEDs[5], HIGH);
    break;
  } 
}

//Arduino functions
//-----------------------------------------------------------------------
void setup() {
  for(int i = 0; i < 6; i++) pinMode(hours_LEDs[i], OUTPUT);
  for(int i = 0; i < 7; i++) pinMode(minutes_LEDs[i], OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  //first_time();
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
