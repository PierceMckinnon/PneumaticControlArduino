#include <stdlib.h>
#define Pread A0

String num;
int Relay[4] = {6,7,8,9};
int pressure; 
int ardPress;
int z =0;


char buffer2[12];
char buffer3[12];

void setup() 
{
  // put your setup code here, to run once:
  pinMode(Pread,INPUT);

  while(z<4)
    {
      pinMode(Relay[z], OUTPUT);    //initialize all relays to low, writing high is low relay
      digitalWrite(Relay[z], HIGH);
      z++;
    }
  Serial.begin(9600);

}

void loop() 
{
  // put your main code here, to run repeatedly:
  ardPress = (analogRead(Pread));
  pressure = int((ardPress*0.1976) - 25.142);
  /*
  if(i ==4)
  {
    i=0;
  }
  digitalWrite(Relay[i], LOW); //test stuff
  delay(1000);
  digitalWrite(Relay[i], HIGH);
   delay(1000);
   i++;
   */

int i =0;
if( Serial.available()==6)  //once received 6 digit serial
{
  num = Serial.readString();
  Serial.println(num);
  if(num[0]=='A' && num[1] == 'C')
  {
    //num[0] = int(num[0]);
    //num[1] = int(num[1]);
    while(i<4)
    {
      if (num[i+2] == '1')  //going through characters in serial string if 1 turn on else off
      {
      digitalWrite(Relay[i], LOW);
      }
      else
      {
      digitalWrite(Relay[i], HIGH);
      }
      num[i] = int(num[i]);
    }
  }
  //itoa(pressure, buffer2, 10);
  // itoa(ardPress, buffer3, 10);
  Serial.print('P');
  Serial.print(pressure);
  Serial.print('S');
  Serial.print(num);
  Serial.print('R');
  Serial.print(ardPress); 
  } 
}
