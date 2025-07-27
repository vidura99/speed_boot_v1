

void Blutooth() {
  //  if (Serial.available()) {
  //    SerialBT.write(Serial.read());
  //  }
   if (SerialBT.available()) {
    
     String myString = (SerialBT.readString());
    
     String kpS = getValue(myString, ' ', 0);
     String kiS = getValue(myString, ' ', 1);
     String kdS = getValue(myString, ' ', 2);

     const char* kpN = kpS.c_str();
     const char* kiN = kiS.c_str();
     const char* kdN = kdS.c_str();

     kp_left = atof(kpN);
     ki_left = atof(kiN);
     kd_left = atof(kdN);
    
    //  Serial.println(kp+1);
    //  Serial.println(ki+2);
    //  Serial.println(kd+3);

  }
 
 }

 String getValue(String data, char separator, int index)
 {
     int found = 0;
     int strIndex[] = { 0, -1 };
     int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
             strIndex[0] = strIndex[1] + 1;
             strIndex[1] = (i == maxIndex) ? i+1 : i;
         }
    }     return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
 }
