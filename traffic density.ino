 #include<SoftwareSerial.h>
  #include<string.h>

SoftwareSerial swftwr(7,6);// RX TX

const int N_trigPin1 = 10;
const int N_echoPin1 = 11;
const int N_trigPin2 = 12;
const int N_echoPin2 = 13;

const int S_trigPin1 = A0;
const int S_echoPin1 = A1;
const int S_trigPin2 = 8;
const int S_echoPin2 = 9;

const int E_trigPin1 = 3;
const int E_echoPin1 = 2;
const int E_trigPin2 = 5;
const int E_echoPin2 = 4;

const int W_trigPin1 = A2;
const int W_echoPin1 = A3;
const int W_trigPin2 = A4;
const int W_echoPin2 = A5;

long N_duration1, S_duration1, E_duration1, W_duration1;
int N_distance1, S_distance1, E_distance1, W_distance1;

long N_duration2, S_duration2, E_duration2, W_duration2;
int N_distance2, S_distance2, E_distance2, W_distance2;

String N, S, E, W,density = "";

String  green_led_status = "N*";

void setup() 
{

 pinMode(N_trigPin1,OUTPUT); 
 pinMode(N_echoPin1,INPUT);
 pinMode(N_trigPin2,OUTPUT); 
 pinMode(N_echoPin2,INPUT);

 pinMode(S_trigPin1,OUTPUT); 
 pinMode(S_echoPin1,INPUT);
 pinMode(S_trigPin2,OUTPUT); 
 pinMode(S_echoPin2,INPUT);

 pinMode(E_trigPin1,OUTPUT); 
 pinMode(E_echoPin1,INPUT);
 pinMode(E_trigPin2,OUTPUT); 
 pinMode(E_echoPin2,INPUT);

 pinMode(W_trigPin1,OUTPUT); 
 pinMode(W_echoPin1,INPUT);
 pinMode(W_trigPin2,OUTPUT); 
 pinMode(W_echoPin2,INPUT);
 
 Serial.begin(9600); 
 swftwr.begin(9600);
}

void loop() 
{
  digitalWrite(N_trigPin1,LOW);
  delayMicroseconds(2);
  digitalWrite(N_trigPin1,HIGH);
  delayMicroseconds(10);
  digitalWrite(N_trigPin1,LOW);
  N_duration1 = pulseIn(N_echoPin1,HIGH);
  N_distance1 = N_duration1*0.034/2;

  digitalWrite(N_trigPin2,LOW);
  delayMicroseconds(2);
  digitalWrite(N_trigPin2,HIGH);
  delayMicroseconds(10);
  digitalWrite(N_trigPin2,LOW);
  N_duration2 = pulseIn(N_echoPin2,HIGH);
  N_distance2 = N_duration2*0.034/2;

 /////////////////////////////////////////////////////

  digitalWrite(S_trigPin1,LOW);
  delayMicroseconds(2);
  digitalWrite(S_trigPin1,HIGH);
  delayMicroseconds(10);
  digitalWrite(S_trigPin1,LOW);
  S_duration1 = pulseIn(S_echoPin1,HIGH);
  S_distance1 = S_duration1*0.034/2;

  digitalWrite(S_trigPin2,LOW);
  delayMicroseconds(2);
  digitalWrite(S_trigPin2,HIGH);
  delayMicroseconds(10);
  digitalWrite(S_trigPin2,LOW);
  S_duration2 = pulseIn(S_echoPin2,HIGH);
  S_distance2 = S_duration2*0.034/2;

/////////////////////////////////////////////////////


  digitalWrite(E_trigPin1,LOW);
  delayMicroseconds(2);
  digitalWrite(E_trigPin1,HIGH);
  delayMicroseconds(10);
  digitalWrite(E_trigPin1,LOW);
  E_duration1 = pulseIn(E_echoPin1,HIGH);
  E_distance1 = E_duration1*0.034/2;

  digitalWrite(E_trigPin2,LOW);
  delayMicroseconds(2);
  digitalWrite(E_trigPin2,HIGH);
  delayMicroseconds(10);
  digitalWrite(E_trigPin2,LOW);
  E_duration2 = pulseIn(E_echoPin2,HIGH);
  E_distance2 = E_duration2*0.034/2;

 ////////////////////////////////////////////////////

  digitalWrite(W_trigPin1,LOW);
  delayMicroseconds(2);
  digitalWrite(W_trigPin1,HIGH);
  delayMicroseconds(10);
  digitalWrite(W_trigPin1,LOW);
  W_duration1 = pulseIn(W_echoPin1,HIGH);
  W_distance1 = W_duration1*0.034/2;

  digitalWrite(W_trigPin2,LOW);
  delayMicroseconds(2);
  digitalWrite(W_trigPin2,HIGH);
  delayMicroseconds(10);
  digitalWrite(W_trigPin2,LOW);
  W_duration2 = pulseIn(W_echoPin2,HIGH);
  W_distance2 = W_duration2*0.034/2;

 ////////////////////////////////////////////////////

      if((N_distance1 < 6) && (N_distance2 < 6))
      {
       // Serial.print("HIGH TRAFFIC IN NORTH");
       N = "HIGH*";
      }
      else if((N_distance1 < 6) && (N_distance2 > 6))
      {
        //Serial.print("LOW TRAFFIC IN NORTH");
        N = "LOW*";
      }
      else if((N_distance1 > 6) && (N_distance2 > 6))
      {
       // Serial.print("NO TRAFFIC IN NORTH");
       N = "ZERO*";
      }
      else
      {
        N = "ZERO*";
      }
      

      if((E_distance1 < 6) && (E_distance2 < 6))
      {
       // Serial.print("HIGH TRAFFIC IN EAST");
       E = "HIGH*";
      }
      else if((E_distance1 < 6) && (E_distance2 > 6))
      {
        //Serial.print("LOW TRAFFIC IN EAST");
        E = "LOW*";
      }
      else if((E_distance1 > 6) && (E_distance2 > 6))
      {
        //Serial.print("NO TRAFFIC IN EAST");
        E = "ZERO*";
      }
      else
      {
        E = "ZERO*";
      }


      if((S_distance1 < 6) && (S_distance2 < 6))
      {
        //Serial.print("HIGH TRAFFIC IN SOUTH");
        S = "HIGH*";
      }
      else if((S_distance1 < 6) && (S_distance2 > 6))
      {
        //Serial.print("LOW TRAFFIC IN SOUTH");
        S = "LOW*";
      }
      else if((S_distance1 > 6) && (S_distance2 > 6))
      {
       // Serial.print("NO TRAFFIC IN SOUTH");
       S = "ZERO*";
      }
      else
      {
        S = "ZERO*";
      }


     if((W_distance1 < 6) && (W_distance2 < 6))
      {
       // Serial.print("HIGH TRAFFIC IN WEST");
       
        W = "HIGH*";
      }
      else if((W_distance1 < 6) && (W_distance2 > 6))
      {
        //Serial.print("LOW TRAFFIC IN WEST");
        W = "LOW*";
      }
      else if((W_distance1 > 6) && (W_distance2 > 6))
      {
       // Serial.print("NO TRAFFIC IN WEST");
       W = "ZERO*";
      } 
      else
      {
        W = "ZERO*";
      }
      
      density = N+E+S+W+green_led_status;
      Serial.print(density);
      delay(1000);
      
////////////////////////////////////////////////////
  
  if (Serial.available())
   {
    delay(100);
    char c=Serial.read();

    if(c == 'N')
    {
      swftwr.print("N");
    }
    else if(c == 'S')
    {
      swftwr.print("S");
    }
    else if(c == 'E')
    {
      swftwr.print("E");
    }
    else if(c == 'W')
    {
      swftwr.print("W");
    }
   }

///////////////////////////////////////////////////

  
   if (swftwr.available())
   {
    delay(100);
    char q=swftwr.read();


    
    if(q == 'A')
    {
      green_led_status = "N*";
    }
    if(q == 'B')
    {
      green_led_status = "E*";
    }
    if(q == 'C')
    {
      green_led_status = "S*";
    }
    if(q == 'D')
    {
      green_led_status = "W*";
    }
    
    if(q == 'N')
    {
      if((N_distance1 < 6) && (N_distance2 < 6))
      {
        swftwr.print("D");
        green_led_status = "N*";
        //Serial.print("#N");
      }
      else if((N_distance1 < 6) && (N_distance2 > 6))
      {
        swftwr.print("L");
        green_led_status = "N*";
        //Serial.print("#N");
      }
      else if((N_distance1 > 6) && (N_distance2 > 6))
      {
        swftwr.print("Z");
      }
      else
      {
        swftwr.print("Z");
      }
    }

    if(q == 'S')
    {
      if((S_distance1 < 6) && (S_distance2 < 6))
      {
        swftwr.print("D");
        //Serial.print("#S");
         green_led_status = "S*";
      }
      else if((S_distance1 < 6) && (S_distance2 > 6))
      {
        swftwr.print("L");
       // Serial.print("#S");
       green_led_status = "S*";
      }
      else if((S_distance1 > 6) && (S_distance2 > 6))
      {
        swftwr.print("Z");
      }
      else
      {
        swftwr.print("Z");
      }
    }

    if(q == 'E')
    {
      if((E_distance1 < 6) && (E_distance2 < 6))
      {
        swftwr.print("D");
        //Serial.print("#E");
        green_led_status = "E*";
      }
      else if((E_distance1 < 6) && (E_distance2 > 6))
      {
        swftwr.print("L");
       // Serial.print("#E");
       green_led_status = "E*";
      }
      else if((E_distance1 > 6) && (E_distance2 > 6))
      {
        swftwr.print("Z");
      }
      else
      {
        swftwr.print("Z");
      }
    }

    if(q == 'W')
    {
      if((W_distance1 < 6) && (W_distance2 < 6))
      {
        swftwr.print("D");
        //Serial.print("#W");
        green_led_status = "W*";
      }
      else if((W_distance1 < 6) && (W_distance2 > 6))
      {
        swftwr.print("L");
       // Serial.print("#W");
       green_led_status = "W*";
      }
      else if((W_distance1 > 6) && (W_distance2 > 6))
      {
        swftwr.print("Z");
      }
      else
      {
        swftwr.print("Z");
      }
    }
  }

}
