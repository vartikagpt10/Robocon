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

float lasterror = 0;
float Kp = ;
float Kd = ;
float Ki = ;
float baseRPM = 250; 
float PWMFL_cal = baseRPM ;
float PWMFR_cal = baseRPM ;
float PWMRL_cal = baseRPM ;
float PWMRR_cal = baseRPM ;

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
        float rpm = Kp * error + Kd * (error - lastError) + Ki*( error + lastError );
        lastError = error;
        float finalrpm = map(rpm,-4000,4000,-255,255);

        if(error>=0){//implies the bot is towards the right of line 
//the bot moves diagonally to the left
  digitalWrite(FL1,HIGH);
  digitalWrite(FL2,LOW);
  analogWrite(pwmFL,PWMFL_cal);
  
  digitalWrite(FR1,HIGH);
  digitalWrite(FR2,LOW);
  analogWrite(pwmFR,PWMFR_cal + abs(finalrpm));
  
  digitalWrite(RL1,HIGH);
  digitalWrite(RL2,LOW);
  analogWrite(pwmRL,PWMRL_cal + abs(finalrpm));
  
  digitalWrite(RR1,HIGH);
  digitalWrite(RR2,LOW);
  analogWrite(pwmRR,PWMRR_cal);
      }
  else{  //implies the bot is towards left of the line 
  //the bot moves diagonally to the right
  digitalWrite(FL1,HIGH);
  digitalWrite(FL2,LOW);
  analogWrite(pwmFL,PWMFL_cal + abs(finalrpm));
  
  digitalWrite(FR1,HIGH);
  digitalWrite(FR2,LOW);
  analogWrite(pwmFR,PWMFR_cal);
  
  digitalWrite(RL1,HIGH);
  digitalWrite(RL2,LOW);
  analogWrite(pwmRL,PWMRL_cal);
  
  digitalWrite(RR1,HIGH);
  digitalWrite(RR2,LOW);
  analogWrite(pwmRR,PWMRR_cal + abs(finalrpm));
  }   
}
