#define NOTE_A5  880
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_D6  1175
#define NOTE_E6  1319
#define NOTE_F6  1397

#define flexpin0 A0
#define flexpin1 A1
#define flexpin2 A2
#define flexpin3 A3
#define flexpin4 A4
#define flexpin5 A5

int flag0 = 0;
int flag1 = 0;
int flag2 = 0;
int flag3 = 0;
int flag4 = 0;
int flag5 = 0;

#define THRESHOLD 28
#define THRESHOLD2 22

 // change tempo to make the song slower or faster  
 int tempo = 140;
 int buzzer = 11;  //Buzzer Pin
 // notes of the melody followed by the duration.  
 // a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on  
 int mel0 = NOTE_A5;
 int mel1 = NOTE_B5;
 int mel2 = NOTE_C6;
 int mel3 = NOTE_D6;
 int mel4 = NOTE_E6;
 int mel5 = NOTE_F6;

 int wholenote0 = 60000 / tempo;  //wholeote decides duration of the note, if temp higher, duration lesser, 60000-> millisec in miniute
 int wholenote1 = 60000 / tempo;
 int wholenote2 = 60000 / tempo;
 int wholenote3 = 60000 / tempo;
 int wholenote4 = 60000 / tempo;
 int wholenote5 = 60000 / tempo;  

 void setup() {  
  Serial.begin(9600);  
  pinMode(flexpin0,INPUT);
  pinMode(flexpin1,INPUT);
  pinMode(flexpin2,INPUT);
  pinMode(flexpin3,INPUT);
  pinMode(flexpin4,INPUT);
  pinMode(flexpin5,INPUT);
  pinMode(buzzer, OUTPUT);
 }  
 void loop(){  
  int sensorValue0 = analogRead(flexpin0);
  int sensorValue1 = analogRead(flexpin1);
  int sensorValue2 = analogRead(flexpin2);
  int sensorValue3 = analogRead(flexpin3);
  int sensorValue4 = analogRead(flexpin4);
  int sensorValue5 = analogRead(flexpin5);

  Serial.print("Sensor 0: ");
  Serial.print(sensorValue0);
  Serial.print(" Sensor 1: ");
  Serial.print(sensorValue1);
  Serial.print(" Sensor 2: ");
  Serial.print(sensorValue2);
  Serial.print(" Sensor 3: ");
  Serial.print(sensorValue3);
  Serial.print(" Sensor 4: ");
  Serial.print(sensorValue4);
  Serial.print(" Sensor 5: ");
  Serial.println(sensorValue5);

  if(sensorValue0 < THRESHOLD){
    if(flag0 == 0){
      flag0 = 1; // it is playing now
      tone(buzzer, mel0, wholenote0 * 1);  
      delay(wholenote0);  
      noTone(buzzer);  
    }
  }
  else{
    flag0 = 0;
  }

  if(sensorValue1 < THRESHOLD){
    if(flag1 == 0){
      flag1 = 1; // it is playing now
      tone(buzzer, mel1, wholenote1 * 1);  
      delay(wholenote1);  
      noTone(buzzer);  
    }
  }
  else{
    flag1 = 0;
  }
 }
