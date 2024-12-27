const int TRIG_PIN1 = 6; 
const int ECHO_PIN1 = 8;
const int TRIG_PIN2 = 7;
const int ECHO_PIN2 = 9;
const int motor1PWM = 11;
const int motor2PWM = 10;
const int motor1DIR1 =2;
const int motor1DIR2 = 3;
const int motor2DIR1 = 4;
const int motor2DIR2 = 5;

void setup() {
  pinMode(TRIG_PIN1, OUTPUT);
  pinMode(ECHO_PIN1, INPUT);
  pinMode(TRIG_PIN2, OUTPUT);
  pinMode(ECHO_PIN2, INPUT);
  pinMode(motor1PWM, OUTPUT);
  pinMode(motor2PWM, OUTPUT);
  pinMode(motor1DIR1, OUTPUT);
  pinMode(motor1DIR2, OUTPUT);
  pinMode(motor2DIR1, OUTPUT);
  pinMode(motor2DIR2, OUTPUT);

  Serial.begin(9600);
}

void moveForward() {
  digitalWrite(motor1DIR1, HIGH);
  digitalWrite(motor1DIR2, LOW);
  digitalWrite(motor2DIR1, HIGH);
  digitalWrite(motor2DIR2, LOW);
  analogWrite(motor1PWM, 255);
  analogWrite(motor2PWM, 255);
}

void moveBackward() {
  digitalWrite(motor1DIR1, LOW);
  digitalWrite(motor1DIR2, HIGH);
  digitalWrite(motor2DIR1, LOW);
  digitalWrite(motor2DIR2, HIGH);
  analogWrite(motor1PWM, 255);
  analogWrite(motor2PWM, 255);
}

void turnRight() {
  digitalWrite(motor1DIR1, HIGH);
  digitalWrite(motor1DIR2, LOW);
  digitalWrite(motor2DIR1, LOW);
  digitalWrite(motor2DIR2, LOW);
  analogWrite(motor1PWM, 255);
  analogWrite(motor2PWM, 100);
}

void loop() {
  long duration1;
  int distance1;
  long duration2;
  int distance2;

  
  digitalWrite(TRIG_PIN1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN1, LOW);


  duration1 = pulseIn(ECHO_PIN1, HIGH);
  distance1 = duration1 * 0.0344 / 2;


  Serial.print("Distance Front: ");
  Serial.print(distance1);
  Serial.println(" cm");

  digitalWrite(TRIG_PIN2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN2, LOW);


  duration2 = pulseIn(ECHO_PIN2, HIGH);

  distance2 = duration2 * 0.0344 / 2;
  Serial.print("Distance Back: ");
  Serial.print(distance2);
  Serial.println(" cm");

  if (distance1 >= 100) {

    moveForward();
  } else if (distance1 <= 100, distance2 >= 100) {
    // Obstacle ahead, move backward
    // No obstacles in back, move backward
    moveBackward();}
   else { 
    turnRight();
  }
}