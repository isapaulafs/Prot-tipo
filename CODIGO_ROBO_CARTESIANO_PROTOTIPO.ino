#include <SoftwareSerial.h>
SoftwareSerial mySerial(0,1); // RX, TX

#define pinSensorA A0
#define pinSensorD 12
#define pinSolenoide 9

char BT_input;                           // to store input character received via BT.
  int StepX = 2;
  int DirX = 5;
  int StepY = 3;
  int DirY = 6;
  int StepZ = 4;
  int DirZ = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);                      //default baud rate of module
  mySerial.begin(9600);
  pinMode(StepX, OUTPUT);
  pinMode(DirX, OUTPUT);
  pinMode(StepY, OUTPUT);
  pinMode(DirY, OUTPUT);
  pinMode(StepZ, OUTPUT);
  pinMode(DirZ, OUTPUT);
  pinMode(pinSolenoide, OUTPUT);
  pinMode(pinSensorD, INPUT);
  while (!Serial);
}

void loop() {
  
 
  // put your main code here, to run repeatedly:
  if (mySerial.available())
  {   
    BT_input = mySerial.read();   // read input string from bluetooth 
    Serial.println(BT_input);
        
    //eixo x
    
    if (BT_input=='X')                
    {
      digitalWrite(DirX, HIGH);
      
      for(int x = 0; x<1000; x++) { // loop for 1000 steps
      digitalWrite(StepX,HIGH);
      delayMicroseconds(500);
      digitalWrite(StepX,LOW); 
      delayMicroseconds(500);
 }
      delay(1000); // delay for 1 second
    }
    if (BT_input=='x')                
    {
      digitalWrite(StepX, LOW);
    }
    
        //eixo x invertido
    
    if (BT_input=='A')                
    {
      digitalWrite(DirX, LOW);
      
      for(int x = 0; x<1000; x++) { // loop for 1000 steps
      digitalWrite(StepX,HIGH);
      delayMicroseconds(500);
      digitalWrite(StepX,LOW); 
      delayMicroseconds(500);
 }
delay(1000); // delay for 1 second
    }
    if (BT_input=='a')                
    {
      digitalWrite(StepX, LOW);
    }
    
    // eixo y
    
     if (BT_input=='Y')                
    {
      digitalWrite(DirY, HIGH);
      
     for(int x = 0; x<1000; x++) { // loop for 2250 steps
     digitalWrite(StepY,HIGH);
     delayMicroseconds(500);
     digitalWrite(StepY,LOW); 
     delayMicroseconds(500);
 }
delay(1000); // delay for 1 second   
    }
    if (BT_input=='y')                
    {
      digitalWrite(StepY, LOW);
    }
    //eixo y invertido
    
         if (BT_input=='B')                
    {
      digitalWrite(DirY, LOW);
      
      for(int x = 0; x<1000; x++) { // loop for 200 steps
      digitalWrite(StepY,HIGH);
      delayMicroseconds(500);
      digitalWrite(StepY,LOW); 
      delayMicroseconds(500);
 }
delay(1000); // delay for 1 second    
    }
    if (BT_input=='b')                
    {
      digitalWrite(StepY, LOW);
    }
    
    
    //eixo z 
    
    if(BT_input=='Z')
    {
      digitalWrite(DirZ, HIGH);
      
      for(int x = 0; x<1000; x++) { // loop for 1000 steps
      digitalWrite(StepZ,HIGH);
      delayMicroseconds(500);
      digitalWrite(StepZ,LOW); 
      delayMicroseconds(500);
 }
      delay(1000); // delay for 1 second 
      if (analogRead(pinSensorA) > 700) 
     {
     delay(3000); // delay for 1 second
     Serial.println("SOLENOIDE LIGADO");
     digitalWrite(pinSolenoide, HIGH);
     delay(3000); // delay for 1 second
     } 
     else 
     {
     Serial.println("SOLENOIDE DESLIGADO");
     digitalWrite(pinSolenoide, LOW);
    }
    
    digitalWrite(DirZ, LOW);
    for(int x = 0; x<1000; x++) { // loop for 200 steps
    digitalWrite(StepZ,HIGH);
    delayMicroseconds(500);
    digitalWrite(StepZ,LOW); 
    delayMicroseconds(500);
 }
    delay(1000); // delay for 1 second
    }   
    if (BT_input=='z')                
    {
      digitalWrite(pinSolenoide, LOW);
      digitalWrite(StepZ, LOW);
    }
    
        //eixo z invertido
        
       if (BT_input=='C')                
    {
      digitalWrite(DirZ, LOW);
      for(int x = 0; x<1000; x++) { // loop for 200 steps
      digitalWrite(StepZ,HIGH);
      delayMicroseconds(500);
      digitalWrite(StepZ,LOW); 
      delayMicroseconds(500);
    }
    }
    
     if (BT_input=='c')                
    {
      digitalWrite(StepZ, LOW);
    }    
    }

    // sistema no automático

       if (BT_input=='R') 
{
       
 digitalWrite(DirX, HIGH); // set direction, HIGH for clockwise, LOW for anticlockwise
 digitalWrite(DirY, HIGH);
 digitalWrite(DirZ, HIGH);
 
 for(int x = 0; x<2250; x++) { // loop for 200 steps
  digitalWrite(StepX,HIGH);
  delayMicroseconds(500);
  digitalWrite(StepX,LOW); 
  delayMicroseconds(500);
 }
delay(1000); // delay for 1 second

for(int x = 0; x<2000; x++) { // loop for 200 steps
  digitalWrite(StepY,HIGH);
  delayMicroseconds(500);
  digitalWrite(StepY,LOW); 
  delayMicroseconds(500);
 }
delay(1000); // delay for 1 second

for(int x = 0; x<2000; x++) { // loop for 200 steps
  digitalWrite(StepZ,HIGH);
  delayMicroseconds(500);
  digitalWrite(StepZ,LOW); 
  delayMicroseconds(500);
 }
 
  delay(1000); // delay for 1 second
  digitalWrite(DirZ, LOW);
 
 for(int x = 0; x<2000; x++) { // loop for 200 steps
  digitalWrite(StepZ,HIGH);
  delayMicroseconds(500);
  digitalWrite(StepZ,LOW); 
  delayMicroseconds(500);
 }
delay(1000); // delay for 1 second
digitalWrite(DirX, LOW);
digitalWrite(DirY, LOW);
digitalWrite(DirZ, HIGH);

// 2 LINHA

 for(int x = 0; x<2000; x++) { // loop for 200 steps
  digitalWrite(StepX,HIGH);
  delayMicroseconds(500);
  digitalWrite(StepX,LOW); 
  delayMicroseconds(500);
 }
delay(1000); // delay for 1 second

for(int x = 0; x<2000; x++) { // loop for 200 steps
  digitalWrite(StepY,HIGH);
  delayMicroseconds(500);
  digitalWrite(StepY,LOW); 
  delayMicroseconds(500);
 }
delay(1000); // delay for 1 second

for(int x = 0; x<2000; x++) { // loop for 200 steps
  digitalWrite(StepZ,HIGH);
  delayMicroseconds(500);
  digitalWrite(StepZ,LOW); 
  delayMicroseconds(500);
 }
 
  delay(1000); // delay for 1 second
  digitalWrite(DirZ, LOW);
 
 for(int x = 0; x<2000; x++) { // loop for 200 steps
  digitalWrite(StepZ,HIGH);
  delayMicroseconds(500);
  digitalWrite(StepZ,LOW); 
  delayMicroseconds(500);
 }

}
}  
