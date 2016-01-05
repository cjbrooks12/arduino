
int pin_R = 5;
int pin_G = 6;
int pin_B = 3;

int leds[5] = { 22, 24, 26, 28, 30 };

int bus_R[5] = { 25, 0,   0,   25, 0    };
int bus_G[5] = { 0,   25, 0,   0, 25 };
int bus_B[5] = { 0,   0,   25, 25,   25 };


void setup() {
  pinMode(pin_R, OUTPUT);
  pinMode(pin_G, OUTPUT);
  pinMode(pin_B, OUTPUT);

  pinMode(32, OUTPUT);

  for(int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], HIGH);
  }

  pinMode(A15, INPUT);
}

void loop() { 
  for(int led_index = 0; led_index < 5; led_index++) {
    
    
    digitalWrite(leds[led_index], LOW);
    
    if(led_index > 0) digitalWrite(leds[led_index - 1], HIGH);
    else digitalWrite(leds[4], HIGH);
  
    digitalWrite(pin_R, bus_R[led_index]);
    digitalWrite(pin_G, bus_G[led_index]);
    digitalWrite(pin_B, bus_B[led_index]);

    digitalWrite(32, LOW);
    delay(sqrt(1 + analogRead(A15)));
    digitalWrite(32, HIGH);
  }
}
