const int trigger1 = 2; 
const int echo1 = 3; 
const int trigger2 = 4; 
const int echo2 = 5;

long time_taken;
int dist,distL,distR;

 

void setup() {
Serial.begin(9600); 
  
pinMode(trigger1, OUTPUT); 
pinMode(echo1, INPUT); 
pinMode(trigger2, OUTPUT); 
pinMode(echo2, INPUT); 
}

/*Function to calculate distance*/
void calculate_distance(int trigger, int echo)
{
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);

time_taken = pulseIn(echo, HIGH);
dist= time_taken*0.034/2;
if (dist>80)
dist = 80;
}

void loop() { //infinite loopy
calculate_distance(trigger1,echo1);
distL =dist; 

calculate_distance(trigger2,echo2);
distR =dist; 

if ((distL >40 && distR>40) && (distL <60&& distR<60)) 
{Serial.println("Play/Pause"); delay (250);}

calculate_distance(trigger1,echo1);
distL =dist;

calculate_distance(trigger2,echo2);
distR =dist;

 

if (distL>=10 && distL<=40)
{
  delay(250);
  calculate_distance(trigger1,echo1);
  distL =dist;
  if (distL>=10 && distL<=40)  
  {
    Serial.println("Left Locked");
    while(distL<=40)
    {
      calculate_distance(trigger1,echo1);
      distL =dist;
      if (distL<30) //Hand pushed in 
      {Serial.println ("Vup"); delay (100);}
      if (distL>30) //Hand pulled out
      {Serial.println ("Vdown"); delay (100);}
    }
  }
}


if (distR>=10 && distR<=40)
{
  delay(250);
  calculate_distance(trigger2,echo2);
  distR =dist;
  if (distR>=10 && distR<=40)
  {
    Serial.println("Right Locked");
    while(distR<=40)
    {
      calculate_distance(trigger2,echo2);
      distR =dist;
      if (distR<30) 
      {Serial.println ("Rewind"); delay (100);}
      if (distR>30) 
      {Serial.println ("Forward"); delay (100);}
  }
}
}


delay(200);
     
     }
