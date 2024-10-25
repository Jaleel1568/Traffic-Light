const int redPin = 5;
const int yellowPin = 4;
const int greenPin = 3;

enum TrafficState { RED, YELLOW_AFTER_RED, GREEN, YELLOW_AFTER_GREEN };
TrafficState currentState = RED;

void setup() {
    pinMode(redPin, OUTPUT);
    pinMode(yellowPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    currentState = RED;
    digitalWrite(redPin, HIGH); // Start with Red light
}

void loop() {
    switch (currentState) {
        case RED:
            // Turn on Red, wait 25 seconds, then switch to Yellow
            digitalWrite(redPin, HIGH);
            digitalWrite(yellowPin, LOW);
            digitalWrite(greenPin, LOW);
            delay(25000); 
            currentState = YELLOW_AFTER_RED;
            break;

        case YELLOW_AFTER_RED:
            // Turn on Yellow, wait 5 seconds, then switch to Green
            digitalWrite(redPin, LOW);
            digitalWrite(yellowPin, HIGH);
            delay(5000); 
            currentState = GREEN;
            break;

        case GREEN:
            // Turn on Green, wait 20 seconds, then switch to Yellow
            digitalWrite(greenPin, HIGH);
            digitalWrite(yellowPin, LOW);
            delay(20000); 
            currentState = YELLOW_AFTER_GREEN;
            break;

        case YELLOW_AFTER_GREEN:
            // Turn on Yellow, wait 5 seconds, then switch to Red
            digitalWrite(greenPin, LOW);
            digitalWrite(yellowPin, HIGH);
            delay(5000); 
            currentState = RED;
            break;
    }
}
