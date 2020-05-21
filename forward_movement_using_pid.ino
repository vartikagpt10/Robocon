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
  if(error<___){
    forward();
  }else{
    sideways();
  }
  
}

  void forward(){
    digitalRead(sensor,error);
   
    float rpm = SKp * error + SKd * (error - lastError) + SKi*( error + lastError );
    float lastError = error;

    float rpmr=baseRPM-rpm;
    float rpml=baseRPM+rpm; 

    digitalWrite(FL1,HIGH);
    digitalWrite(FL2,LOW);
    analogWrite(pwmFL,rpml);
  
    digitalWrite(FR1,LOW);
    digitalWrite(FR2,HIGH);
    analogWrite(pwmFR,rpmr);
  
    digitalWrite(RL1,HIGH);
    digitalWrite(RL2,LOW);
    analogWrite(pwmRL,rpml);
  
    digitalWrite(RR1,LOW);
    digitalWrite(RR2,HIGH);
    analogWrite(pwmRR,rpmr);

  delay(2000);
}
  
  void sideways(){
    //input of error
    digitalRead(sensor,error); 

    float rpm = SKp * error + SKd * (error - lastError) + SKi*( error + lastError ); // code for PID
    float lastError = error; //stores this value for the next time
  
    float rpmr=baseRPM-rpm; //rpm for rightwards movement
    float rpml=baseRPM+rpm; //rpm for leftwards movement

    digitalWrite(FL1,HIGH);
    digitalWrite(FL2,LOW);
    analogWrite(pwmFL,rpml);
  
    digitalWrite(FR1,LOW);
    digitalWrite(FR2,HIGH);
    analogWrite(pwmFR,rpmr);
  
    digitalWrite(RL1,HIGH);
    digitalWrite(RL2,LOW);
    analogWrite(pwmRL,rpml);
  
    digitalWrite(RR1,LOW);
    digitalWrite(RR2,HIGH);
    analogWrite(pwmRR,rpmr);

    delay(2000);
  }
  
  
    
