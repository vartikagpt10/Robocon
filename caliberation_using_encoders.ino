int encoderPinFL1 = 2;
int encoderPinFL2 = 3;

int encoderPinFR1 = 2;
int encoderPinFR2 = 3;

int encoderPinRR1 = 2;
int encoderPinRR2 = 3;

int encoderPinRL1 = 2;
int encoderPinRL2 = 3;

volatile int lastEncodedFL = 0;
volatile long encoderValueFL = 0;

volatile int lastEncodedFR = 0;
volatile long encoderValueFR = 0;

volatile int lastEncodedRL = 0;
volatile long encoderValueRL = 0;

volatile int lastEncodedRR = 0;
volatile long encoderValueRR = 0;


long lastencoderValueFL = 0;
long lastencoderValueFR = 0;
long lastencoderValueRL = 0;
long lastencoderValueRR = 0;

int lastMSB_FL = 0;
int lastLSB_FL = 0;

int lastMSB_FR = 0;
int lastLSB_FR = 0;

int lastMSB_RL = 0;
int lastLSB_RL = 0;

int lastMSB_RR = 0;
int lastLSB_RR = 0;

void setup() {
  Serial.begin (9600);

  pinMode(encoderPinFL1, INPUT); 
  pinMode(encoderPinFL2, INPUT);

    digitalWrite(encoderPinFL1, HIGH); //turn pullup resistor on
    digitalWrite(encoderPinFL2, HIGH); //turn pullup resistor on

  pinMode(encoderPinFR1, INPUT); 
  pinMode(encoderPinFR2, INPUT);

    digitalWrite(encoderPinFR1, HIGH); //turn pullup resistor on
    digitalWrite(encoderPinFR2, HIGH); //turn pullup resistor on

  pinMode(encoderPinRL1, INPUT); 
  pinMode(encoderPinRL2, INPUT);

    digitalWrite(encoderPinRL1, HIGH); //turn pullup resistor on
    digitalWrite(encoderPinRL2, HIGH); //turn pullup resistor on

  pinMode(encoderPinRR1, INPUT); 
  pinMode(encoderPinRR2, INPUT);

    digitalWrite(encoderPinRR1, HIGH); //turn pullup resistor on
    digitalWrite(encoderPinRR2, HIGH); //turn pullup resistor on

  //call updateEncoder() when any high/low changed seen
  attachInterrupt(0, updateEncoderFL, CHANGE); 
  attachInterrupt(1, updateEncoderFL, CHANGE);

  attachInterrupt(0, updateEncoderFR, CHANGE); 
  attachInterrupt(1, updateEncoderFR, CHANGE);

  attachInterrupt(0, updateEncoderRL, CHANGE); 
  attachInterrupt(1, updateEncoderRL, CHANGE);

  attachInterrupt(0, updateEncoderRR, CHANGE); 
  attachInterrupt(1, updateEncoderRR, CHANGE);

}

void loop(){ 

    Serial.println(encoderValueFL);

    Serial.println(encoderValueFR);

    Serial.println(encoderValueRL);

    Serial.println(encoderValueRR);
    delay(1000); 
}


void updateEncoderFL(){
  int MSB = digitalRead(encoderPinFL1); //MSB = most significant bit
  int LSB = digitalRead(encoderPinFL2); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastEncodedFL << 2) | encoded; //adding it to the previous encoded value

  if(sum == b1 || sum == b2 || sum == b3 || sum == b4) encoderValueFL ++;
  if(sum == b1 || sum == b2 || sum == b3 || sum == b4) encoderValueFL --;
  // b1, b2, b3, b4 are some bits associated to the specific encoders we use and those values are to be filled here...

  lastEncodedFL = encoded; //store this value for next time
}
void updateEncoderFR(){
  int MSB = digitalRead(encoderPinFR1); //MSB = most significant bit
  int LSB = digitalRead(encoderPinFR2); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; 
  //converting the 2 pin value to single number
  int sum  = (lastEncodedFR << 2) | encoded; 
  //adding it to the previous encoded value

  if(sum == b1 || sum == b2 || sum == b3 || sum == b4) encoderValueFR ++;
  if(sum == b1 || sum == b2 || sum == b3 || sum == b4) encoderValueFR --;

  lastEncodedFR = encoded; 
  //store this value for next time
}
void updateEncoderRL(){
  int MSB = digitalRead(encoderPinRL1); //MSB = most significant bit
  int LSB = digitalRead(encoderPinRL2); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastEncodedRL << 2) | encoded; //adding it to the previous encoded value

  if(sum == b1 || sum == b2 || sum == b3 || sum == b4) encoderValueRL ++;
  if(sum == b1 || sum == b2 || sum == b3 || sum == b4) encoderValueRL --;

  lastEncodedRL = encoded; //store this value for next time
}
void updateEncoderRR(){
  int MSB = digitalRead(encoderPinRR1); //MSB = most significant bit
  int LSB = digitalRead(encoderPinRR2); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastEncodedRR << 2) | encoded; //adding it to the previous encoded value

  if(sum == b1 || sum == b2 || sum == b3 || sum == b4) encoderValueRR ++;
  if(sum == b1 || sum == b2 || sum == b3 || sum == b4) encoderValueRR --;

  lastEncodedRR = encoded; //store this value for next time
}
