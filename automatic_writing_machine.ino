#include <Servo.h>
#include <Stepper.h>

#define STEPS 2048

Stepper stepperX(STEPS, 8, 10, 9, 11);
Stepper stepperY(STEPS, 4, 6, 5, 7);

Servo pen;

void setup() {
  stepperX.setSpeed(10);
  stepperY.setSpeed(10);
  pen.attach(3);
  penUp();
}

void loop() {

  writeA();
  moveNext();

  writeB();
  moveNext();

  writeC();
  moveNext();

  draw1();
  moveNext();

  draw2();
  moveNext();

  drawSquare();
  moveNext();

  drawTriangle();
  moveNext();

  drawSignature();

  while (1); // stop forever
}

// ---------------- PEN CONTROL ----------------
void penUp() {
  pen.write(90);
  delay(300);
}

void penDown() {
  pen.write(40);
  delay(300);
}

void moveNext() {
  penUp();
  stepperX.step(150);  // space between characters
}

// ---------------- LETTERS ----------------
void writeA() {
  penDown();
  stepperY.step(200);
  stepperX.step(100);
  stepperY.step(-200);
  penUp();

  stepperY.step(100);
  penDown();
  stepperX.step(-100);
  penUp();
  stepperY.step(-100);
}

void writeB() {
  penDown();
  stepperY.step(200);
  stepperX.step(80);
  stepperY.step(-100);
  stepperX.step(-80);
  stepperY.step(-100);
  penUp();
}

void writeC() {
  penDown();
  stepperX.step(-100);
  stepperY.step(200);
  stepperX.step(100);
  penUp();
}

// ---------------- NUMBERS ----------------
void draw1() {
  penDown();
  stepperY.step(200);
  penUp();
}

void draw2() {
  penDown();
  stepperX.step(100);
  stepperY.step(100);
  stepperX.step(-100);
  stepperY.step(100);
  penUp();
}

// ---------------- SHAPES ----------------
void drawSquare() {
  penDown();
  stepperX.step(150);
  stepperY.step(150);
  stepperX.step(-150);
  stepperY.step(-150);
  penUp();
}

void drawTriangle() {
  penDown();
  stepperX.step(150);
  stepperY.step(150);
  stepperX.step(-150);
  penUp();
}

// ---------------- SIGNATURE ----------------
void drawSignature() {
  penDown();
  stepperX.step(60);
  stepperY.step(40);
  stepperX.step(60);
  stepperY.step(-40);
  stepperX.step(60);
  stepperY.step(40);
  penUp();
}
