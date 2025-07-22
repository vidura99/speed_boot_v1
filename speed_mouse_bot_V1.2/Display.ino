void clearDisplay(){
  display.clearDisplay();
}

void setTextSize(int size){
  display.setTextSize(size);
  display.setTextColor(WHITE);
}

void setCursor(int loc1, int loc2){
  display.setCursor(loc1, loc2);
}

void display_text(const String& text){
  display.println(text);
}

void display_out(){
  display.display();
}
