//datatypes meegeven
int piezoPin = D3;
const int RED = D1;
const int GREEN = D2;

//pins benoemen
void setup() {
    pinMode(A0, INPUT);
    pinMode(piezoPin, OUTPUT);
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    //data type sensorValue aanmaken en vullen met pin A0 dus de rookdetector
    int sensorValue;
    sensorValue = analogRead(A0);

    //In de Serial Monirit aangeven wat de waardes van de rook zijn.
    Serial.println("hoeveelheid rook = ");
    Serial.println(sensorValue);
    delay(1000);

    //Als de rook waarde boven de 60 is word het lampje rood en het alarm harder.
  if (sensorValue > 60 ){
    tone(piezoPin, 1000, 500);
    analogWrite(GREEN, 0);
    analogWrite(RED, 255);
  }
    //Als de rook waarde tussen de 60 en 50 is word het lampje geel en begint het alarm
  else if(sensorValue < 60 && sensorValue > 50 ){
    tone(piezoPin, 1000, 100);
    analogWrite(GREEN, 150);
    analogWrite(RED, 150);
  }
    //Als de rookwaarde goed is, is het lampje groen
  else{
    analogWrite(RED, 0);
    analogWrite(GREEN, 255);
    }
    
  }
