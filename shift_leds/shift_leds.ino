
int m_data = 27;
int m_clock = 25;
int m_latch = 23;

void setup() {
  pinMode(m_data, OUTPUT);
  pinMode(m_clock, OUTPUT);
  pinMode(m_latch, OUTPUT);

}

void loop() {
  for(int i = 0; i < 256; i++) {
    updateLeds(i);
    delay(250);
  }
}

void updateLeds(int value) {
  digitalWrite(m_latch, LOW);
  shiftOut(m_data, m_clock, MSBFIRST, value);
  digitalWrite(m_latch, HIGH);
}

