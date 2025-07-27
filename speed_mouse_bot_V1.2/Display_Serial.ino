void DisplayDebugs(){
    Serial.print("Left   Sensor : ");
    Serial.println(readSharpSensor_Left());
    Serial.print("Middle Sensor : ");
    Serial.println(readSharpSensor_Middle());
    Serial.print("Right  Sensor : ");
    Serial.println(readSharpSensor_Right());
  }

void DisplayEssentials(){
    Serial.println();
    Serial.print("Left motor encoder value:");
    Serial.print(LMEncodervalue);
    delay(500);

    Serial.println();
    Serial.print("Right motor encoder value:");
    Serial.println(RMEncodervalue);
    delay(500);
}
