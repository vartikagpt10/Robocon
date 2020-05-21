int pwmFL=1;
//front left wheel

int pwmRL=2;
//rear left wheel

int pwmFR=3;
//front right wheel

int pwmRR=4;
//rear right wheel

int FL1=5;
int FL2=6;
int RL1=7;
int RL2=8;
int FR1=9;
int FR2=10;
int RR1=11;
int RR2=12;

int sensor=13;
float error;
//input from open cv

float w;
//rpm added

const int base_rpm = 200;

void setup() {
  // put your setup code here, to run o
  
  PinMode(sensor,INPUT);
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
  // put your main code here, to run repeatedly:
  digitalRead(sensor,e)

  digitalWrite(FL1,HIGH);
  digitalWrite(FL2,LOW);
  analogWrite(pwmFL,w);
  
  digitalWrite(FR1,LOW);
  digitalWrite(FR2,HIGH);
  analogWrite(pwmFR,w);
  
  digitalWrite(RL1,HIGH);
  digitalWrite(RL2,LOW);
  analogWrite(pwmRL,w);
  
  digitalWrite(RR1,LOW);
  digitalWrite(RR2,HIGH);
  analogWrite(pwmRR,w);

  w=Kp*error + Ki(error) + Kd*d/dt*error + base_rpm; 

}
