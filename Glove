
#include <SoftwareSerial.h>
#include <Wire.h>
#include <MPU6050.h>   

int servo_pin = 2;
int rp=9,gp=6,bp=5;
MPU6050 sensor ;

int16_t ax, ay, az ;

int16_t gx, gy, gz ;


SoftwareSerial BTSerial(10,11);

const int flexpin[]={1, 2, 3, 0, 0};
const int misc=10;

int flex[]={0, 0, 0, 0, 0};
int maxi[]= { -999, -999, -999, -999, -999};
int mini[]= { 999, 999, 999, 999, 999};


void setup() 
{ 
    pinMode(rp,OUTPUT);
  pinMode(gp,OUTPUT);
  pinMode(bp,OUTPUT);
  delay(100);
 // SetColor(255,255,0);
Wire.begin ( );

Serial.begin  (9600); 
Serial.println  ( "Initializing the sensor" ); 
sensor.initialize ( ); 
Serial.println (sensor.testConnection ( ) ? "Successfully Connected" : "Connection failed"); 
delay (1000); 
Serial.println ( "Taking Values from the sensor" );
delay (1000);
    while (millis () < 10000)
    {
        for (int i=0; i<=4; i++)
        {
           SetColor(255,255,0);
          flex[i] = analogRead(flexpin[i]);
          if (flex[i] < mini[i])
          {
            mini[i]=flex[i];
          }
          if (flex[i] > maxi[i])          
          {
            maxi[i]=flex[i];
          }
          delay(20);
    }
  }
 SetColor(0,0,255);


  Serial.begin(9600);
  BTSerial.begin(9600);
 

} 
  void SetColor(int r, int g, int b)
{
  

analogWrite(rp,r);
analogWrite(gp,g);
analogWrite(bp,b);

}

int first_pass=1;
void loop() 
{
   
  int newValue[]={0, 0, 0, 0, 0};
  sensor.getMotion6 (&ax, &ay, &az, &gx, &gy, &gz);

  ax = map (ax, -17000, 17000, 0, 180) ;

  for(int i=0;i<=4;i++)
  {
    newValue[i] = analogRead(flexpin[i]);
       newValue[i]=map(newValue[i],mini[i],maxi[i],1,179);
        newValue[i]=constrain(newValue[i],0,180);    
  }

  if(newValue>0 && newValue < 180)
   for (int i=0; i<=4; i++)
        {
          if (newValue[i] < mini[i])
          {
            mini[i]=newValue[i];
          }
          if (newValue[i] > maxi[i])          
          {
            maxi[i]=newValue[i];
          }
    }

  if( first_pass )
  {
     for(int i=0;i<=4;i++)
  {
  Serial.print(maxi[i]) ;
  Serial.print(" ");
 }
 Serial.println();
     for(int i=0;i<=4;i++)
 {
 
  Serial.print(mini[i]);
  Serial.print(" ");
  }
  
   Serial.println();
   delay(5000);

      first_pass=0;

      for(int i=0;i<=4;i++)
      {
        Serial.print(newValue[i]);
        Serial.print(" ");
        BTSerial.write(byte(newValue[i]));
        flex[i]=newValue[i];
      }  
      Serial.print("  *");
       Serial.println (ax);
      BTSerial.write (ax);
      Serial.println(); 
  }
  else
  {
    for(int i=0;i<=4;i++)
    {
      if(abs(flex[i]-newValue[i])>=misc)
      {
        flex[i]=newValue[i];
      }
        Serial.print(flex[i]);
        Serial.print(" ");
        BTSerial.write(byte(flex[i]));

    }
      Serial.print("  *");
      Serial.println (ax);
      BTSerial.write (ax);
 
    Serial.println();    
  }
  delay(200);
} 
