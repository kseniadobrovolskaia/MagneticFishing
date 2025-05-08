#include <Servo.h>

const int ForwardSpeed = 90; // < 90!
const int BackwardSpeed = 90; // < 90!
const unsigned long DebounceDelay = 50;

struct PinnedServo {
  int servoPin;
  int forwardButtonPin;
  int reverseButtonPin;
  Servo servo;
  bool isRotating;
  unsigned long lastDebounceTime;

  void setup(int servoPin_, int forwardButtonPin_, int reverseButtonPin_) {
    servoPin = servoPin_;
    forwardButtonPin = forwardButtonPin_;
    reverseButtonPin = reverseButtonPin_;

    servo.attach(servoPin);
    pinMode(forwardButtonPin, INPUT_PULLUP);
    pinMode(reverseButtonPin, INPUT_PULLUP);
    servo.detach();

    isRotating = false;
    lastDebounceTime = 0;
  }

  void rotateForward() {
    servo.attach(servoPin);
    servo.write(90 + ForwardSpeed); // Full counterclockwise rotation
  }

  void rotateReverse() {
    servo.attach(servoPin);
    servo.write(90 - BackwardSpeed);   // Full clockwise rotation
  }

  void stop() {
    servo.detach();
  }

  void update() {
    int forwardReading = digitalRead(forwardButtonPin);
    int reverseReading = digitalRead(reverseButtonPin);
    
    // Debounce check
    if ((millis() - lastDebounceTime) > DebounceDelay) {
      if (forwardReading == LOW && !isRotating) { // Forward button pressed
        Serial.println("Forward button pressed!");
        rotateForward();
        isRotating = true;
      } else if (reverseReading == LOW && !isRotating) { // Reverse button pressed
        Serial.println("Reverse button pressed!");
        rotateReverse();
        isRotating = true;
      } else if ((forwardReading == HIGH || reverseReading == HIGH) && isRotating) {
        Serial.println("Button released!");
        stop();
        isRotating = false;
      }
      lastDebounceTime = millis();
    }
  }
};

PinnedServo servoX;
PinnedServo servoY;

void setup() {
  Serial.begin(9600);
  servoX.setup(6, 10, 11);
  servoX.stop();

  servoY.setup(7, 12, 13);
  servoY.stop();
}

void loop() {
  // Serial.println(digitalRead(10));
  servoX.update();
  servoY.update();
}
