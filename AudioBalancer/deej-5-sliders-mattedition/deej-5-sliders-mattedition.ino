const int NUM_SLIDERS = 5;
const int analogInputs[NUM_SLIDERS] = {A0, A1, A2, A3};

int analogSliderValues[NUM_SLIDERS];

float linearize(int input){
  float i = input*1.0;
  float o;
  if(i <= 14){
    o = i/14.0;
  } else if (i <= 32){
    o = (i-32.0)/(32-14)+2;
  } else if (i <= 72){
    o = (i-72.0)/(72-32)+3;
  } else if (i <= 117){
    o = (i-117.0)/(117-72)+4;
  } else if (i <= 158){
    o = (i-158.0)/(158-117)+5;
  } else if (i <= 203){
    o = (i-203.0)/(203-158)+6;
  } else if (i <= 436){
    o = (i-436.0)/(436-203)+7;
  } else if (i <= 728){
    o = (i-728.0)/(728-436)+8;
  } else if (i <= 1007){
    o = (i-1007.0)/(1007-728)+9;
  } else if (i <= 1023){
    o = (i-1023.0)/(1023-1007)+10;
  }
  return int(o*102.3);
}

void setup() { 
  for (int i = 0; i < NUM_SLIDERS; i++) {
    pinMode(analogInputs[i], INPUT);
  }

  Serial.begin(9600);
}

void loop() {
  updateSliderValues();
  sendSliderValues(); // Actually send data (all the time)
//   printSliderValues(); // For debug
  delay(10);
}

void updateSliderValues() {
  for (int i = 0; i < NUM_SLIDERS; i++) {
    analogSliderValues[i] = linearize(analogRead(analogInputs[i]));
  }
}

void sendSliderValues() {
  String builtString = String("");

  for (int i = 0; i < NUM_SLIDERS; i++) {
    builtString += String((int)analogSliderValues[i]);

    if (i < NUM_SLIDERS - 1) {
      builtString += String("|");
    }
  }
  
  Serial.println(builtString);
}

void printSliderValues() {
  for (int i = 0; i < NUM_SLIDERS; i++) {
    String printedString = String("Slider #") + String(i + 1) + String(": ") + String(analogSliderValues[i]) + String(" mV");
    Serial.write(printedString.c_str());

    if (i < NUM_SLIDERS - 1) {
      Serial.write(" | ");
    } else {
      Serial.write("\n");
    }
  }
}
