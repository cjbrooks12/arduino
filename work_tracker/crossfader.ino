
//code that treats all LEDs as a single unit, spending valuable clock cycles coloring
//the lights more finely instead of rapidly switching between lights to turn on
//------------------------------------------------------------------------------
int fadeVal[3] = { 0255, 255, 255 };
int fadePreviousVal[3] = { 255, 255, 255 };

void setupCrossfader() {
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

    randomSeed(analogRead(0));
}

void loopCrossfader() {
    int randomColors[3] = { 
        random(10, 100), 
        random(10, 100), 
        random(10, 100), 
    };
    crossFade(randomColors);
}

void crossFade(int color[3]) {  
    int stepR = calculateStep(fadePreviousVal[0], color[0]);
    int stepG = calculateStep(fadePreviousVal[1], color[1]); 
    int stepB = calculateStep(fadePreviousVal[2], color[2]);

    for (int i = 0; i <= 1020; i++) {
        fadeVal[0] = calculateVal(stepR, fadeVal[0], i);
        fadeVal[1] = calculateVal(stepG, fadeVal[1], i);
        fadeVal[2] = calculateVal(stepB, fadeVal[2], i);

        analogWrite(BUS[0], fadeVal[0]);   // Write current values to LED pins
        analogWrite(BUS[1], fadeVal[1]);      
        analogWrite(BUS[2], fadeVal[2]); 

        digitalWrite(PIEZO, LOW);
        WAIT = WAIT_MULTIPLIER * sqrt(1 + analogRead(POT));
        delay(WAIT);
        digitalWrite(PIEZO, HIGH);
    }
    // Update current values for next loop
    fadePreviousVal[0] = fadeVal[0]; 
    fadePreviousVal[1] = fadeVal[1]; 
    fadePreviousVal[2] = fadeVal[2];
}

int calculateStep(int prevValue, int endValue) {
    int step = endValue - prevValue; // What's the overall gap?
    if (step) {                      // If its non-zero, 
        step = 1020/step;              //   divide by 1020
    } 
    return step;
}

/* The next function is calculateVal. When the loop value, i,
*  reaches the step size appropriate for one of the
*  colors, it increases or decreases the value of that color by 1. 
*  (R, G, and B are each calculated separately.)
*/

int calculateVal(int step, int val, int i) {
    if ((step) && i % step == 0) { // If step is non-zero and its time to change a value,
        if (step > 0) {              //   increment the value if step is positive...
            val += 1;           
        } 
        else if (step < 0) {         //   ...or decrement it if step is negative
            val -= 1;
        } 
    }
    // Defensive driving: make sure val stays in the range 0-255
    if (val > 255) {
        val = 255;
    } 
    else if (val < 0) {
        val = 0;
    }
    return val;
}
