int pwmFL=1;
int pwmRL=2;
int pwmFR=3;
int pwmRR=4;

int FL1=5;
int FL2=6;

int RL1=7;
int RL2=8;

int FR1=9;
int FR2=10;

int RR1=11;
int RR2=12;

void setup() {
  // put your setup code here, to run once:
  PinMode(pwmFL,OUTPUT);
  PinMode(pwmRL,OUTPUT);
  PinMode(pwmFR,OUTPUT);
  PinMode(pwmRR,OUTPUT);
  PinMode(FL1,OUTPUT);
  PinMode(FL2,OUTPUT);
  PinMode(RL1,OUTPUT);
  PinMode(RL2,OUTPUT);
  PinMode(FR1,OUTPUT);
  PinMode(FR2,OUTPUT);
  PinMode(RR1,OUTPUT);
  PinMode(RR2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: error=distance;
  //digitalRead(sensor,e)

  digitalWrite(FL1,HIGH);
  digitalWrite(FL2,LOW);
  analogWrite(pwmFL,0);
  
  digitalWrite(FR1,LOW);
  digitalWrite(FR2,HIGH);
  analogWrite(pwmFR,0);
  
  digitalWrite(RL1,HIGH);
  digitalWrite(RL2,LOW);
  analogWrite(pwmRL,0);
  
  digitalWrite(RR1,LOW);
  digitalWrite(RR2,HIGH);
  analogWrite(pwmRR,0);
  
  delay(1500);
  
  digitalWrite(FL1,HIGH);
  digitalWrite(FL2,LOW);
  analogWrite(pwmFL,100);
  
  digitalWrite(FR1,LOW);
  digitalWrite(FR2,HIGH);
  analogWrite(pwmFR,100);
  
  digitalWrite(RL1,HIGH);
  digitalWrite(RL2,LOW);
  analogWrite(pwmRL,100);
  
  digitalWrite(RR1,LOW);
  digitalWrite(RR2,HIGH);
  analogWrite(pwmRR,100);
  delay(2000);

        //float rpm = SKp * error + SKd * (error - lastError) + SKi*( error + lastError );
        //lastError = error;

        //float rpmr=baseRPM-rpm;
        //float rpml=baseRPM+rpm;
}
