const int trig=6;                    //for the sensor
const int echo=7;                    //trig is for trigger and echo is for the echo pin HC- SR04
int usVal;                           //value received from sensor
float dist;
int IN1=8;                           //connected to l298n driver
int IN2=9;
int IN3=10;
int IN4=11;
int en1=3;                           //for speed control using PWM
int en2=5;

void fwd()                           //forward function
{
  analogWrite(en1,200);
  analogWrite(en2,200);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}
void rev()                           //reverse function
{
  analogWrite(en1,200);
  analogWrite(en2,200);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}
void rt()                            //turn right
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void pause()                         //stop the car
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}


void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);             //all pins except echo are set to output
  pinMode(echo,INPUT);              //echo receives the transmitted signal from the sensor
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(en1,OUTPUT);
  pinMode(en2,OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

  fwd();

  delay(2);
  digitalWrite(trig,HIGH);                    //send a signal through the echo pin for 5ms
  delay(5);
  digitalWrite(trig,LOW);
  usVal=pulseIn(echo,HIGH);                   //receive the puls through echo pin
  dist=usVal/58.2;                            //calculate distance from object
  if(dist>=19)                                //if object is far away
    fwd();
  else                                        //if object is near, stop at a place, reverse the car, take a right turn
  {
    pause();
    delay(500);
    rev();
    delay(500);
    pause();
    delay(500);
    rt();
    delay(250);
  }
    

}
