#include<SoftwareSerial.h>
#include<Servo.h>

SoftwareSerial BTSerial(10,11);

Servo test;
Servo s[6];

void setup() {
  s[3].attach(4);
  s[2].attach(3);
  s[0].attach(7);
  s[1].attach(5);
  s[4].attach(6);
  s[5].attach(2);
  
  test.attach(8);

  BTSerial.begin(9600);
  delay(30);
  Serial.begin(9600);
  delay(30);
}
int var[]={0, 0, 0, 0, 0, 0};

int x=150;


byte values[5];  

void loop() {
  if(x==150){test.write(150); x=50; }
  else{test.write(50);x=150;}
if(BTSerial.available() >0)
{
    for(int i=0;i<=5;i++)
      var[i]=BTSerial.read();
    
    var[0]=180-var[0];
    var[4]=180-var[4];
    var[3]=180-var[3];
}

int test=1;
for(int i=0;i<=5;i++)
{
  if(var[i]<0)
    test=0;
}
if(test)
{
  for(int i=0;i<=5;i++)
  {
    
      Serial.print(var[i]);
      Serial.print(" ");
      
      if(var[i]>0 && var[i]<180)
      {
        s[i].write(var[i]);
      }
  }
  Serial.println();
}
   delay(200);

}
