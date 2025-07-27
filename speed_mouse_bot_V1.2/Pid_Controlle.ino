#define speed_R  120
#define speed_L  120

// #define kp_left 0.22
// #define ki_left 0
// #define kd_left 0

int p_error;
float moment, spd_right, spd_left;
int spd_left_abs, spd_right_abs;


void follow_wall(){

 int position = readSharpSensor_Left();

 int error = position - 1000;
  moment = kp_left * error + ki_left * (error + p_error) + kd_left * (error - p_error);
  p_error = error;
  
  feed_motor_left(moment);
  feed_motor_right(moment);
}

  void feed_motor_left(float moment){
   
  spd_left = moment + speed_L;
  spd_left_abs = abs(spd_left);

  if(spd_left_abs >= 255){
      spd_left_abs = 255;
    }else if(spd_left <= 0){
      spd_left_abs = 0;
    }
  // analogWrite(R_M,spd_left_abs); 
  // digitalWrite(R1,HIGH);
  // digitalWrite(R2,LOW);
  leftMotorForward(spd_left_abs);
  }

void feed_motor_right(float moment){   

  spd_right = -moment + speed_R; 
  spd_right_abs = abs(spd_right);

  if(spd_right_abs >= 255){
      spd_right_abs = 255;
    }else if(spd_right <= 0){
      spd_right_abs = 0;
    }
  // analogWrite(L_M,spd_right_abs); 
  // digitalWrite(L1,HIGH);
  // digitalWrite(L2,LOW);
  rightMotorForward(spd_right_abs);
  }