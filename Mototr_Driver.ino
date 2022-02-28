int pwmMax=255;
int pwmValue;
int pin12=2;
int pin11=3;
int pin21=4;
int pin22=5;
int speed1=9;
int speed2=10;

void setup() {
  pinMode(pin11, OUTPUT);
  pinMode(pin22, OUTPUT);
  pinMode(pin12, OUTPUT);
  pinMode(pin21, OUTPUT);
  pinMode(speed1,OUTPUT);
  pinMode(speed2,OUTPUT);
  Serial.begin(9600); 
  delay(2000);  
 
  Serial.println("Type something!");
}
 
void loop() {
    handleSerial();
}

void handleSerial() {
  analogWrite(speed1, pwmValue); 
  analogWrite(speed2, pwmValue);
 while (Serial.available() > 0) {
   char incomingCharacter = Serial.read();
   switch (incomingCharacter) {
     case '+':
      pwmValue = pwmValue + 5;
      if (pwmValue >= pwmMax)
         pwmValue = pwmMax;
      Serial.print("Increasing Speed by 5 .....Now it is: ");
      Serial.println(pwmValue);
      //Serial.write("Increasing.....");
      break;
 
     case '-':
      pwmValue = pwmValue - 5;
      if (pwmValue <= 0)
         pwmValue = 0;
      Serial.print("Slowing Speed by 5 .....Now it is: ");
      Serial.println(pwmValue);
      //Serial.write("Slowinging.....");
      break;

      case 'w':
      digitalWrite(pin11, HIGH);
      digitalWrite(pin12, LOW);
      Serial.println("Forwarding..");
      //Serial.write("Forwarding.....");
      break;

      case 's':
       digitalWrite(pin21, HIGH);
       digitalWrite(pin22, LOW);
       Serial.println("Backwarding.....");
      //Serial.write("Backwarding.....");
      break;
    }
 }
}
