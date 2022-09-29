#define motor1_pin1  5
#define motor1_pin2  4
#define motor2_pin1  3
#define motor2_pin2  2
#define ENA  7
#define ENB  6

#define car_speed 100

#define ir_right  9

#define ir_left   8

void setup() {
  Serial.begin(9600);

  // motors pins

  pinMode(motor1_pin1, OUTPUT);
  pinMode(motor1_pin2, OUTPUT);
  pinMode(motor2_pin1, OUTPUT);
  pinMode(motor2_pin2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);


  // IR pins

  pinMode(ir_right, INPUT);
  pinMode(ir_left, INPUT);

}

void loop() {
  int read_right = digitalRead(ir_right);
  int read_left = digitalRead(ir_left);

  if (read_right == 0 && read_right == 0) {
    Serial.println("black");
    stright();
  }
  else if (read_right == 1 && read_left == 0) {
    car_left();
  }
  else if (read_right == 0 && read_left == 1) {
    car_right();
  }
  else if (read_right == 1 && read_left == 1) {
    car_stop();
  }
}


void stright() {
  analogWrite(ENA , car_speed);
  analogWrite(ENB , car_speed);
  digitalWrite (motor1_pin1 , HIGH);
  digitalWrite (motor1_pin2 , LOW);
  digitalWrite (motor2_pin1 , HIGH);
  digitalWrite (motor2_pin2 , LOW);
}

void backforwd() {
  analogWrite(ENA , car_speed);
  analogWrite(ENB , car_speed);
  digitalWrite (motor1_pin1 , LOW);
  digitalWrite (motor1_pin2 , HIGH);
  digitalWrite (motor2_pin1 , LOW);
  digitalWrite (motor2_pin2 , HIGH);
}

void car_stop() {
  digitalWrite (motor1_pin1 , LOW);
  digitalWrite (motor1_pin2 , LOW);
  digitalWrite (motor2_pin1 , LOW);
  digitalWrite (motor2_pin2 , LOW);
}
void car_left() {
  analogWrite(ENA , car_speed);
  analogWrite(ENB , car_speed);
  digitalWrite (motor1_pin1 , HIGH);
  digitalWrite (motor1_pin2 , LOW);
  digitalWrite (motor2_pin1 , LOW);
  digitalWrite (motor2_pin2 , HIGH);
}
void car_right() {
  analogWrite(ENA , car_speed);
  analogWrite(ENB , car_speed);
  digitalWrite (motor1_pin1 , LOW);
  digitalWrite (motor1_pin2 , HIGH);
  digitalWrite (motor2_pin1 , HIGH);
  digitalWrite (motor2_pin2 , LOW);
}
