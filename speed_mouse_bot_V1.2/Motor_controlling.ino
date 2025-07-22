void motorBreak(int pwmSpeed) { //in1A = left forward (forward,right Motor)  in2B = right reverse

  digitalWrite(in1A, LOW);    // Set direction reverse
  digitalWrite(in2A, LOW);   // Forward direction is LOW
  analogWrite(pwmA, pwmSpeed);  // Set the PWM speed

  digitalWrite(in1B, LOW);    // Set direction reverse
  digitalWrite(in2B, LOW);   // Forward direction is LOW
  analogWrite(pwmB, pwmSpeed);  // Set the PWM speed
}

void motorForward(int pwmSpeed) {

  digitalWrite(in1A, HIGH);   // Set direction forward
  digitalWrite(in2A, LOW);    // Reverse direction is LOW
  analogWrite(pwmA, pwmSpeed);  // Set the PWM speed

  digitalWrite(in1B, HIGH);   // Set direction forward
  digitalWrite(in2B, LOW);    // Reverse direction is LOW
  analogWrite(pwmB, pwmSpeed);  // Set the PWM speed
}

void motorLeft(int pwmSpeed){
  digitalWrite(in1A, HIGH);   // Set direction forward
  digitalWrite(in2A, LOW);    // Reverse direction is LOW
  analogWrite(pwmA, pwmSpeed);  // Set the PWM speed

  digitalWrite(in1B, LOW);   // Set direction forward
  digitalWrite(in2B, HIGH);    // Reverse direction is LOW
  analogWrite(pwmB, pwmSpeed);  // Set the PWM speed
}

void motorReverse(int pwmSpeed) {

  digitalWrite(in1A, LOW);    // Set direction reverse
  digitalWrite(in2A, HIGH);   // Forward direction is LOW
  analogWrite(pwmA, pwmSpeed);  // Set the PWM speed

  digitalWrite(in1B, LOW);    // Set direction reverse
  digitalWrite(in2B, HIGH);   // Forward direction is LOW
  analogWrite(pwmB, pwmSpeed);  // Set the PWM speed
}

void motorRight(int pwmSpeed){
  digitalWrite(in1A, LOW);   // Set direction forward
  digitalWrite(in2A, HIGH);    // Reverse direction is LOW
  analogWrite(pwmA, pwmSpeed);  // Set the PWM speed

  digitalWrite(in1B, HIGH);   // Set direction forward
  digitalWrite(in2B, LOW);    // Reverse direction is LOW
  analogWrite(pwmB, pwmSpeed);  // Set the PWM speed
}
