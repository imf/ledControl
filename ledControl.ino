#define RED 4
#define GREEN 5
#define BLUE 6
#define delayTime 20

void setup() {

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
}

int redVal;
int blueVal;
int greenVal;
 
void loop() { 
 /* 
  setColor(0xFFFFFFL);
  delay(1000);
  setColor(0x00FF0000L);
  delay(500);
  setColor(0x00FF00L);
  delay(500);
  setColor(0x0000FFL);
  delay(500);

  
  setColor(255,255,255);
  delay(1000);
  setColor(255,0,0);
  delay(500);
  setColor(0,255,0);
  delay(500);
  setColor(0,0,255);
  delay(500);
  setColor(255,0,255);
  delay(500);
  setColor(0,255,255);
  delay(500);
  setColor(255,255,0);
  delay(500);
  setColor(255,255,255);
  delay(500);
  for (int i = 255; i > 0; i--) {
    setColor(i, i, i);
    delay(20);
  }
  delay(500);
  for (int i = 0; i < 255; i++) {
    setColor(i, 0, i);
    delay(20);
  }*/
  error();
  gradient(255,255,0, 128,0,255);
  off(200);
  gradient(128,0,255, 255,0,0);
  off(200);
  gradient(255,0,0, 0,255,0);
  delay(500);
  off(100);

}

void setColor(unsigned long rgb) {
  int red = (rgb & 0xFF0000L) >> 16;
  int green = (rgb & 0x00FF00L) >> 8;
  int blue = rgb & 0xFFL;
  setColor(red, green, blue);
}
  
void setColor(int red, int green, int blue) {
  analogWrite(RED,   red);
  analogWrite(GREEN, green);
  analogWrite(BLUE,  blue);
}

void gradient(int startRed, int startGreen, int startBlue, int endRed, int endGreen, int endBlue) {
  gradient(startRed, startGreen, startBlue, endRed, endGreen, endBlue, 1000, 16);
}
void gradient(int startRed, int startGreen, int startBlue, int endRed, int endGreen, int endBlue, int duration) {
  gradient(startRed, startGreen, startBlue, endRed, endGreen, endBlue, duration, 16);
}

void gradient(int startRed, int startGreen, int startBlue, int endRed, int endGreen, int endBlue, int duration, int steps) {
  float stepRed = startRed - endRed / steps; // It's ok if these are negative, because they will still get 'added' to the start color.
  float stepGreen = startGreen - endGreen / steps;
  float stepBlue = startBlue - endBlue / steps;
  
  for (int i = 0; i < steps; i++) {
    setColor(startRed, startGreen, startBlue);
    startRed += stepRed;
    startGreen += stepGreen;
    startBlue += stepBlue;
    delay(duration / steps);
  }
}

void off(int duration) {
  setColor(0x000000);
  delay(duration);
}

void error() {
  for (int i = 0; i < 10; i++) {
    setColor(0xFF0000);
    delay(100);
    setColor(0x000000);
    delay(25);
  }
}
