const int north_red = 6; 
const int north_yellow = A3; 
const int north_green = 10; 

const int south_red = 8; 
const int south_yellow = A2; 
const int south_green = 12; 

const int west_red = 7; 
const int west_yellow = A0; 
const int west_green = 11; 

const int east_red = 9; 
const int east_yellow = A1; 
const int east_green = 13;

int emergency_enable_flag = 0, delay_time = 0;

int north_flag = 1, south_flag = 0, east_flag = 0, west_flag = 0;

int enable_north_flag = 0, enable_south_flag = 0, enable_east_flag = 0, enable_west_flag = 0;

char emergency_flag;


void setup() 
{
  pinMode(north_red,OUTPUT);
  pinMode(north_yellow,OUTPUT);
  pinMode(north_green,OUTPUT);
  
  pinMode(east_red,OUTPUT);
  pinMode(east_yellow,OUTPUT);
  pinMode(east_green,OUTPUT);

  pinMode(west_red,OUTPUT);
  pinMode(west_yellow,OUTPUT);
  pinMode(west_green,OUTPUT);

  pinMode(south_red,OUTPUT);
  pinMode(south_yellow,OUTPUT);
  pinMode(south_green,OUTPUT);

  Serial.begin(9600); 
}

void loop() 
{
  if (Serial.available())
   {
    delay(100);
    char c = Serial.read();

    if(c == 'N')
    {
      emergency_enable_flag = 1;
      emergency_flag = 'N';   
    }
    if(c == 'E')
    {
      emergency_enable_flag = 1;
      emergency_flag = 'E';
    }
    if(c == 'W')
    {
      emergency_enable_flag = 1;
      emergency_flag = 'W';
    }
    if(c == 'S')
    {
      emergency_enable_flag = 1;
      emergency_flag = 'S';
    }

    if(c == 'D')
    {
      delay_time = 10;
      
      //Serial.print("DT = 10");
      
      if(enable_north_flag == 1)
      {
        north_flag = 1;
      }
      if(enable_east_flag == 1)
      {
        east_flag = 1;
      }
      if(enable_south_flag == 1)
      {
        south_flag = 1;
      }
      if(enable_west_flag == 1)
      {
        west_flag = 1;
      }
    }
    
    if(c == 'L')
    {
      delay_time = 5;
      
     // Serial.print("DT = 5");
      
      if(enable_north_flag == 1)
      {
        north_flag = 1;
      }
      if(enable_east_flag == 1)
      {
        east_flag = 1;
      }
      if(enable_south_flag == 1)
      {
        south_flag = 1;
      }
      if(enable_west_flag == 1)
      {
        west_flag = 1;
      }
    }

    
    if(c == 'Z')
    {
      delay_time = 0;

      //Serial.print("DT = 0");
      
      if(enable_north_flag == 1)
      {
        Serial.print("E");
        enable_east_flag = 1;
        enable_north_flag = 0;
        enable_south_flag = 0;
        enable_west_flag = 0;
      }
      else if(enable_east_flag == 1)
      {
        Serial.print("S");
        enable_south_flag = 1;
        enable_east_flag = 0;
        enable_west_flag = 0;
        enable_north_flag = 0;
      }
      else if(enable_south_flag == 1)
      {
        Serial.print("W");
        enable_west_flag = 1;
        enable_south_flag = 0;
        enable_east_flag = 0;
        enable_north_flag = 0;
      }
      else if(enable_west_flag == 1)
      {
        
        Serial.print("N");
        enable_north_flag = 1;
        enable_west_flag = 0;
        enable_south_flag = 0;
        enable_east_flag = 0;
      }
    }
    
   }

//////////////////////////////////////////////////////////////////

  if(emergency_enable_flag == 1)
  {
    emergency_enable_flag = 0;
    
    if(emergency_flag == 'N')
    {
      if(east_flag == 1)
      {
        digitalWrite(east_yellow,HIGH);
        digitalWrite(north_red,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(south_red,HIGH);
  
        digitalWrite(east_red,LOW);
        digitalWrite(east_green,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);

        delay(2000);

        Serial.print("A");
        digitalWrite(north_green,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(south_red,HIGH);
        digitalWrite(east_red,HIGH);
        
        digitalWrite(east_green,LOW);
        digitalWrite(east_yellow,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_red,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);
        
        delay(10000);

        digitalWrite(north_green,LOW);
        digitalWrite(north_yellow,HIGH);

        delay(2000);
        
      }
      else if(west_flag == 1)
      {
        digitalWrite(west_yellow,HIGH);
        digitalWrite(north_red,HIGH);
        digitalWrite(east_red,HIGH);
        digitalWrite(south_red,HIGH);
  
        digitalWrite(east_yellow,LOW);
        digitalWrite(east_green,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(west_red,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);

        delay(2000);

        Serial.print("A");
        digitalWrite(north_green,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(south_red,HIGH);
        digitalWrite(east_red,HIGH);
        
        digitalWrite(east_green,LOW);
        digitalWrite(east_yellow,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_red,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);
        

        delay(10000);

        digitalWrite(north_green,LOW);
        digitalWrite(north_yellow,HIGH);

        delay(2000);
        
      }

     else if(south_flag == 1)
      {
        digitalWrite(south_yellow,HIGH);
        digitalWrite(north_red,HIGH);
        digitalWrite(east_red,HIGH);
        digitalWrite(west_red,HIGH);
  
        digitalWrite(east_yellow,LOW);
        digitalWrite(east_green,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_red,LOW);
        digitalWrite(south_green,LOW);

        delay(2000);

        Serial.print("A");
        digitalWrite(north_green,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(south_red,HIGH);
        digitalWrite(east_red,HIGH);
        
        digitalWrite(east_green,LOW);
        digitalWrite(east_yellow,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_red,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);
        
        delay(10000);

        digitalWrite(north_green,LOW);
        digitalWrite(north_yellow,HIGH);

        delay(2000);
        
      }
      else if(north_flag == 1)
      {
        Serial.print("A");
        digitalWrite(north_green,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(south_red,HIGH);
        digitalWrite(east_red,HIGH);
        
        digitalWrite(east_green,LOW);
        digitalWrite(east_yellow,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_red,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);
        delay(10000);
      }
      else if(enable_east_flag == 1)
      {
        Serial.print("A");
        digitalWrite(north_green,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(south_red,HIGH);
        digitalWrite(east_red,HIGH);
        
        digitalWrite(east_green,LOW);
        digitalWrite(east_yellow,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_red,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);
        delay(10000);
        if(delay_time == 0)
        {
          digitalWrite(north_green,LOW);
          digitalWrite(north_yellow,HIGH);
        }
        Serial.print("E");
      }
      else if(enable_south_flag == 1)
      {
        digitalWrite(east_yellow,HIGH);
        digitalWrite(north_red,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(south_red,HIGH);
  
        digitalWrite(east_red,LOW);
        digitalWrite(east_green,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);

        delay(2000);

        Serial.print("A");
        digitalWrite(north_green,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(south_red,HIGH);
        digitalWrite(east_red,HIGH);
        
        digitalWrite(east_green,LOW);
        digitalWrite(east_yellow,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_red,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);
        
        delay(10000);

        digitalWrite(north_green,LOW);
        digitalWrite(north_yellow,HIGH);

        delay(2000);
        Serial.print("S");
      }
      else if(enable_west_flag == 1)
      {
        digitalWrite(south_yellow,HIGH);
        digitalWrite(north_red,HIGH);
        digitalWrite(east_red,HIGH);
        digitalWrite(west_red,HIGH);
  
        digitalWrite(east_yellow,LOW);
        digitalWrite(east_green,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_red,LOW);
        digitalWrite(south_green,LOW);

        delay(2000);

        Serial.print("A");
        digitalWrite(north_green,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(south_red,HIGH);
        digitalWrite(east_red,HIGH);
        
        digitalWrite(east_green,LOW);
        digitalWrite(east_yellow,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_red,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);
        
        delay(10000);

        digitalWrite(north_green,LOW);
        digitalWrite(north_yellow,HIGH);

        delay(2000);
        Serial.print("W");
      }
      else if(enable_north_flag == 1)
      {
        digitalWrite(west_yellow,HIGH);
        digitalWrite(north_red,HIGH);
        digitalWrite(east_red,HIGH);
        digitalWrite(south_red,HIGH);
  
        digitalWrite(east_yellow,LOW);
        digitalWrite(east_green,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(west_red,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);

        delay(2000);

        Serial.print("A");
        digitalWrite(north_green,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(south_red,HIGH);
        digitalWrite(east_red,HIGH);
        
        digitalWrite(east_green,LOW);
        digitalWrite(east_yellow,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_red,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);
        

        delay(10000);

        digitalWrite(north_green,LOW);
        digitalWrite(north_yellow,HIGH);

        delay(2000);
        
        Serial.print("E");
      }
      
     }
/////////////////////////////////////////////////////////////////////////
       else if(emergency_flag == 'E')
       {
        if(west_flag == 1)
        {
        digitalWrite(west_yellow,HIGH);
        digitalWrite(north_red,HIGH);
        digitalWrite(east_red,HIGH);
        digitalWrite(south_red,HIGH);
  
        digitalWrite(east_yellow,LOW);
        digitalWrite(east_green,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(west_red,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);

        delay(2000);

        Serial.print("B");
        digitalWrite(east_green,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(south_red,HIGH);
        digitalWrite(north_red,HIGH);
        
        digitalWrite(east_red,LOW);
        digitalWrite(east_yellow,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);


        delay(10000);

        digitalWrite(east_green,LOW);
        digitalWrite(east_yellow,HIGH);

        delay(2000);
        
      }
      else if(south_flag == 1)
      {
        digitalWrite(south_yellow,HIGH);
        digitalWrite(north_red,HIGH);
        digitalWrite(east_red,HIGH);
        digitalWrite(west_red,HIGH);
  
        digitalWrite(east_yellow,LOW);
        digitalWrite(east_green,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_red,LOW);
        digitalWrite(south_green,LOW);

        delay(2000);

        Serial.print("B");
        digitalWrite(east_green,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(south_red,HIGH);
        digitalWrite(north_red,HIGH);
        
        digitalWrite(east_red,LOW);
        digitalWrite(east_yellow,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);
        
        

        delay(10000);

        digitalWrite(east_green,LOW);
        digitalWrite(east_yellow,HIGH);

        delay(2000);
        
      }

     else if(north_flag == 1)
      {
        digitalWrite(north_yellow,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(east_red,HIGH);
        digitalWrite(south_red,HIGH);
  
        digitalWrite(east_yellow,LOW);
        digitalWrite(east_green,LOW);
        digitalWrite(north_red,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(east_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);

        delay(2000);

        Serial.print("B");
        digitalWrite(east_green,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(south_red,HIGH);
        digitalWrite(north_red,HIGH);
        
        digitalWrite(east_red,LOW);
        digitalWrite(east_yellow,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);
        

        delay(10000);

        digitalWrite(east_green,LOW);
        digitalWrite(east_yellow,HIGH);

        delay(2000);
        
      }
      else if(east_flag == 1)
      {
        Serial.print("B");
        digitalWrite(east_green,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(south_red,HIGH);
        digitalWrite(north_red,HIGH);
        
        digitalWrite(east_red,LOW);
        digitalWrite(east_yellow,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);
        delay(10000);
      }
      else if(enable_south_flag == 1)
      {
        Serial.print("B");
        digitalWrite(east_green,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(south_red,HIGH);
        digitalWrite(north_red,HIGH);
        
        digitalWrite(east_red,LOW);
        digitalWrite(east_yellow,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);
        delay(10000);

        if(delay_time == 0)
        {
          digitalWrite(east_green,LOW);
          digitalWrite(east_yellow,HIGH);
        }
        Serial.print("S");
      }
      else if(enable_west_flag == 1)
      {
        digitalWrite(south_yellow,HIGH);
        digitalWrite(north_red,HIGH);
        digitalWrite(east_red,HIGH);
        digitalWrite(west_red,HIGH);
  
        digitalWrite(east_yellow,LOW);
        digitalWrite(east_green,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_red,LOW);
        digitalWrite(south_green,LOW);

        delay(2000);

        Serial.print("B");
        digitalWrite(east_green,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(south_red,HIGH);
        digitalWrite(north_red,HIGH);
        
        digitalWrite(east_red,LOW);
        digitalWrite(east_yellow,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);
        
        

        delay(10000);

        digitalWrite(east_green,LOW);
        digitalWrite(east_yellow,HIGH);

        delay(2000);
        Serial.print("W");
      }
      else if(enable_north_flag == 1)
      {
        digitalWrite(west_yellow,HIGH);
        digitalWrite(north_red,HIGH);
        digitalWrite(east_red,HIGH);
        digitalWrite(south_red,HIGH);
  
        digitalWrite(east_yellow,LOW);
        digitalWrite(east_green,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(west_red,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);

        delay(2000);

        Serial.print("B");
        digitalWrite(east_green,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(south_red,HIGH);
        digitalWrite(north_red,HIGH);
        
        digitalWrite(east_red,LOW);
        digitalWrite(east_yellow,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);


        delay(10000);

        digitalWrite(east_green,LOW);
        digitalWrite(east_yellow,HIGH);

        delay(2000);
        Serial.print("N");
      }
      else if(enable_east_flag == 1)
      {
        digitalWrite(north_yellow,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(east_red,HIGH);
        digitalWrite(south_red,HIGH);
  
        digitalWrite(east_yellow,LOW);
        digitalWrite(east_green,LOW);
        digitalWrite(north_red,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(east_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);

        delay(2000);

        Serial.print("B");
        digitalWrite(east_green,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(south_red,HIGH);
        digitalWrite(north_red,HIGH);
        
        digitalWrite(east_red,LOW);
        digitalWrite(east_yellow,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);
        

        delay(10000);

        digitalWrite(east_green,LOW);
        digitalWrite(east_yellow,HIGH);

        delay(2000);
        Serial.print("S");
      }
     }

/////////////////////////////////////////////////////////////////////

    else if(emergency_flag == 'W')
    {

      if(east_flag == 1)
      {
        digitalWrite(east_yellow,HIGH);
        digitalWrite(north_red,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(south_red,HIGH);
  
        digitalWrite(east_red,LOW);
        digitalWrite(east_green,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);

        delay(2000);

        Serial.print("D");
        digitalWrite(west_green,HIGH);
        digitalWrite(north_red,HIGH);
        digitalWrite(south_red,HIGH);
        digitalWrite(east_red,HIGH);
        
        digitalWrite(east_green,LOW);
        digitalWrite(east_yellow,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(south_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(west_red,LOW);
        
        delay(10000);

        digitalWrite(west_green,LOW);
        digitalWrite(west_yellow,HIGH);

        delay(2000);
      }
            
      else if(south_flag == 1)
        {
          digitalWrite(south_yellow,HIGH);
          digitalWrite(north_red,HIGH);
          digitalWrite(east_red,HIGH);
          digitalWrite(west_red,HIGH);
    
          digitalWrite(east_yellow,LOW);
          digitalWrite(east_green,LOW);
          digitalWrite(north_yellow,LOW);
          digitalWrite(north_green,LOW);
          digitalWrite(west_yellow,LOW);
          digitalWrite(west_green,LOW);
          digitalWrite(south_red,LOW);
          digitalWrite(south_green,LOW);
  
          delay(2000);

          Serial.print("D");
          digitalWrite(west_green,HIGH);
          digitalWrite(north_red,HIGH);
          digitalWrite(south_red,HIGH);
          digitalWrite(east_red,HIGH);
          
          digitalWrite(east_green,LOW);
          digitalWrite(east_yellow,LOW);
          digitalWrite(north_yellow,LOW);
          digitalWrite(north_green,LOW);
          digitalWrite(west_yellow,LOW);
          digitalWrite(west_red,LOW);
          digitalWrite(south_yellow,LOW);
          digitalWrite(south_green,LOW);
          
          delay(10000);
  
          digitalWrite(west_green,LOW);
          digitalWrite(west_yellow,HIGH);

          delay(2000);
        }
  
       else if(north_flag == 1)
        {
          digitalWrite(north_yellow,HIGH);
          digitalWrite(west_red,HIGH);
          digitalWrite(east_red,HIGH);
          digitalWrite(south_red,HIGH);
    
          digitalWrite(east_yellow,LOW);
          digitalWrite(east_green,LOW);
          digitalWrite(north_red,LOW);
          digitalWrite(north_green,LOW);
          digitalWrite(east_yellow,LOW);
          digitalWrite(west_green,LOW);
          digitalWrite(south_yellow,LOW);
          digitalWrite(south_green,LOW);
  
          delay(2000);

          Serial.print("D");
          digitalWrite(west_green,HIGH);
          digitalWrite(north_red,HIGH);
          digitalWrite(south_red,HIGH);
          digitalWrite(east_red,HIGH);
          
          digitalWrite(east_green,LOW);
          digitalWrite(east_yellow,LOW);
          digitalWrite(north_yellow,LOW);
          digitalWrite(north_green,LOW);
          digitalWrite(west_yellow,LOW);
          digitalWrite(west_red,LOW);
          digitalWrite(south_yellow,LOW);
          digitalWrite(south_green,LOW);
          
          delay(10000);
  
          digitalWrite(west_green,LOW);
          digitalWrite(west_yellow,HIGH);

          delay(2000);
        }
        else if(west_flag == 1)
        {
          Serial.print("D");
          digitalWrite(west_green,HIGH);
          digitalWrite(north_red,HIGH);
          digitalWrite(south_red,HIGH);
          digitalWrite(east_red,HIGH);
          
          digitalWrite(east_green,LOW);
          digitalWrite(east_yellow,LOW);
          digitalWrite(north_yellow,LOW);
          digitalWrite(north_green,LOW);
          digitalWrite(west_yellow,LOW);
          digitalWrite(west_red,LOW);
          digitalWrite(south_yellow,LOW);
          digitalWrite(south_green,LOW);
          
          delay(10000);
        }
        else if(enable_north_flag == 1)
        {
          Serial.print("D");
          digitalWrite(west_green,HIGH);
          digitalWrite(north_red,HIGH);
          digitalWrite(south_red,HIGH);
          digitalWrite(east_red,HIGH);
          
          digitalWrite(east_green,LOW);
          digitalWrite(east_yellow,LOW);
          digitalWrite(north_yellow,LOW);
          digitalWrite(north_green,LOW);
          digitalWrite(west_yellow,LOW);
          digitalWrite(west_red,LOW);
          digitalWrite(south_yellow,LOW);
          digitalWrite(south_green,LOW);
          
          delay(10000);
          if(delay_time == 0)
          {
          digitalWrite(west_green,LOW);
          digitalWrite(west_yellow,HIGH);
          }
          Serial.print("N");        
        }
        else if(enable_east_flag == 1)
        {
          digitalWrite(north_yellow,HIGH);
          digitalWrite(west_red,HIGH);
          digitalWrite(east_red,HIGH);
          digitalWrite(south_red,HIGH);
    
          digitalWrite(east_yellow,LOW);
          digitalWrite(east_green,LOW);
          digitalWrite(north_red,LOW);
          digitalWrite(north_green,LOW);
          digitalWrite(east_yellow,LOW);
          digitalWrite(west_green,LOW);
          digitalWrite(south_yellow,LOW);
          digitalWrite(south_green,LOW);
  
          delay(2000);

          Serial.print("D");
          digitalWrite(west_green,HIGH);
          digitalWrite(north_red,HIGH);
          digitalWrite(south_red,HIGH);
          digitalWrite(east_red,HIGH);
          
          digitalWrite(east_green,LOW);
          digitalWrite(east_yellow,LOW);
          digitalWrite(north_yellow,LOW);
          digitalWrite(north_green,LOW);
          digitalWrite(west_yellow,LOW);
          digitalWrite(west_red,LOW);
          digitalWrite(south_yellow,LOW);
          digitalWrite(south_green,LOW);
          
          delay(10000);
  
          digitalWrite(west_green,LOW);
          digitalWrite(west_yellow,HIGH);

          delay(2000);
          Serial.print("E");
        }
        else if(enable_south_flag == 1)
        {
          digitalWrite(east_yellow,HIGH);
          digitalWrite(north_red,HIGH);
          digitalWrite(west_red,HIGH);
          digitalWrite(south_red,HIGH);
    
          digitalWrite(east_red,LOW);
          digitalWrite(east_green,LOW);
          digitalWrite(north_yellow,LOW);
          digitalWrite(north_green,LOW);
          digitalWrite(west_yellow,LOW);
          digitalWrite(west_green,LOW);
          digitalWrite(south_yellow,LOW);
          digitalWrite(south_green,LOW);
  
          delay(2000);

          Serial.print("D");
          digitalWrite(west_green,HIGH);
          digitalWrite(north_red,HIGH);
          digitalWrite(south_red,HIGH);
          digitalWrite(east_red,HIGH);
          
          digitalWrite(east_green,LOW);
          digitalWrite(east_yellow,LOW);
          digitalWrite(north_yellow,LOW);
          digitalWrite(north_green,LOW);
          digitalWrite(west_yellow,LOW);
          digitalWrite(south_green,LOW);
          digitalWrite(south_yellow,LOW);
          digitalWrite(west_red,LOW);
          
          delay(10000);

          digitalWrite(west_green,LOW);
          digitalWrite(west_yellow,HIGH);

        delay(2000);

        Serial.print("S");
        }
        else if(enable_west_flag == 1)
        {
          digitalWrite(south_yellow,HIGH);
          digitalWrite(north_red,HIGH);
          digitalWrite(east_red,HIGH);
          digitalWrite(west_red,HIGH);
    
          digitalWrite(east_yellow,LOW);
          digitalWrite(east_green,LOW);
          digitalWrite(north_yellow,LOW);
          digitalWrite(north_green,LOW);
          digitalWrite(west_yellow,LOW);
          digitalWrite(west_green,LOW);
          digitalWrite(south_red,LOW);
          digitalWrite(south_green,LOW);
  
          delay(2000);

          Serial.print("D");
          digitalWrite(west_green,HIGH);
          digitalWrite(north_red,HIGH);
          digitalWrite(south_red,HIGH);
          digitalWrite(east_red,HIGH);
          
          digitalWrite(east_green,LOW);
          digitalWrite(east_yellow,LOW);
          digitalWrite(north_yellow,LOW);
          digitalWrite(north_green,LOW);
          digitalWrite(west_yellow,LOW);
          digitalWrite(west_red,LOW);
          digitalWrite(south_yellow,LOW);
          digitalWrite(south_green,LOW);
          
          delay(10000);
  
          digitalWrite(west_green,LOW);
          digitalWrite(west_yellow,HIGH);

          delay(2000);
          Serial.print("N");
        }
     }

/////////////////////////////////////////////////////////////////////////

  else if(emergency_flag == 'S')
    {

        if(east_flag == 1)
        {
          digitalWrite(east_yellow,HIGH);
          digitalWrite(north_red,HIGH);
          digitalWrite(west_red,HIGH);
          digitalWrite(south_red,HIGH);
    
          digitalWrite(east_red,LOW);
          digitalWrite(east_green,LOW);
          digitalWrite(north_yellow,LOW);
          digitalWrite(north_green,LOW);
          digitalWrite(west_yellow,LOW);
          digitalWrite(west_green,LOW);
          digitalWrite(south_yellow,LOW);
          digitalWrite(south_green,LOW);
  
          delay(2000);

          Serial.print("C");
          digitalWrite(south_green,HIGH);
          digitalWrite(north_red,HIGH);
          digitalWrite(west_red,HIGH);
          digitalWrite(east_red,HIGH);
          
          digitalWrite(east_green,LOW);
          digitalWrite(east_yellow,LOW);
          digitalWrite(north_yellow,LOW);
          digitalWrite(north_red,LOW);
          digitalWrite(west_yellow,LOW);
          digitalWrite(west_green,LOW);
          digitalWrite(south_yellow,LOW);
          digitalWrite(south_red,LOW);
          
          delay(10000);
  
          digitalWrite(south_green,LOW);
          digitalWrite(south_yellow,HIGH);

          delay(2000);
        }

       else if(west_flag == 1)
        {
          digitalWrite(west_yellow,HIGH);
          digitalWrite(north_red,HIGH);
          digitalWrite(east_red,HIGH);
          digitalWrite(south_red,HIGH);
    
          digitalWrite(east_yellow,LOW);
          digitalWrite(east_green,LOW);
          digitalWrite(north_yellow,LOW);
          digitalWrite(north_green,LOW);
          digitalWrite(west_red,LOW);
          digitalWrite(west_green,LOW);
          digitalWrite(south_yellow,LOW);
          digitalWrite(south_green,LOW);
  
          delay(2000);

          Serial.print("C");
          digitalWrite(south_green,HIGH);
          digitalWrite(north_red,HIGH);
          digitalWrite(west_red,HIGH);
          digitalWrite(east_red,HIGH);
          
          digitalWrite(east_green,LOW);
          digitalWrite(east_yellow,LOW);
          digitalWrite(north_yellow,LOW);
          digitalWrite(north_green,LOW);
          digitalWrite(west_yellow,LOW);
          digitalWrite(west_green,LOW);
          digitalWrite(south_yellow,LOW);
          digitalWrite(south_red,LOW);
          
          delay(10000);
  
          digitalWrite(south_green,LOW);
          digitalWrite(south_yellow,HIGH);
  
          delay(2000);
      }
    
       else if(north_flag == 1)
        {
          digitalWrite(north_yellow,HIGH);
          digitalWrite(west_red,HIGH);
          digitalWrite(east_red,HIGH);
          digitalWrite(south_red,HIGH);
    
          digitalWrite(east_yellow,LOW);
          digitalWrite(east_green,LOW);
          digitalWrite(north_red,LOW);
          digitalWrite(north_green,LOW);
          digitalWrite(east_yellow,LOW);
          digitalWrite(west_green,LOW);
          digitalWrite(south_yellow,LOW);
          digitalWrite(south_green,LOW);
  
          delay(2000);

          Serial.print("C");
          digitalWrite(south_green,HIGH);
          digitalWrite(north_red,HIGH);
          digitalWrite(west_red,HIGH);
          digitalWrite(east_red,HIGH);
          
          digitalWrite(east_green,LOW);
          digitalWrite(east_yellow,LOW);
          digitalWrite(north_yellow,LOW);
          digitalWrite(north_red,LOW);
          digitalWrite(west_yellow,LOW);
          digitalWrite(west_green,LOW);
          digitalWrite(south_yellow,LOW);
          digitalWrite(south_red,LOW);
          
          delay(10000);
  
          digitalWrite(south_green,LOW);
          digitalWrite(south_yellow,HIGH);

          delay(2000);
          
        }
        else if(south_flag == 1)
        {
          Serial.print("S");
          digitalWrite(south_green,HIGH);
          digitalWrite(north_red,HIGH);
          digitalWrite(west_red,HIGH);
          digitalWrite(east_red,HIGH);
          
          digitalWrite(east_green,LOW);
          digitalWrite(east_yellow,LOW);
          digitalWrite(north_yellow,LOW);
          digitalWrite(north_red,LOW);
          digitalWrite(west_yellow,LOW);
          digitalWrite(west_green,LOW);
          digitalWrite(south_yellow,LOW);
          digitalWrite(south_red,LOW);
          
          delay(10000);
        }
        else if(enable_west_flag == 1)
        {
          Serial.print("C");
          digitalWrite(south_green,HIGH);
          digitalWrite(north_red,HIGH);
          digitalWrite(west_red,HIGH);
          digitalWrite(east_red,HIGH);
          
          digitalWrite(east_green,LOW);
          digitalWrite(east_yellow,LOW);
          digitalWrite(north_yellow,LOW);
          digitalWrite(north_red,LOW);
          digitalWrite(west_yellow,LOW);
          digitalWrite(west_green,LOW);
          digitalWrite(south_yellow,LOW);
          digitalWrite(south_red,LOW);
          
          delay(10000);
          if(delay_time == 0)
          {
          digitalWrite(south_green,LOW);
          digitalWrite(south_yellow,HIGH);
          }
          Serial.print("W");   
        }
        else if(enable_north_flag == 1)
        {
          digitalWrite(west_yellow,HIGH);
          digitalWrite(north_red,HIGH);
          digitalWrite(east_red,HIGH);
          digitalWrite(south_red,HIGH);
    
          digitalWrite(east_yellow,LOW);
          digitalWrite(east_green,LOW);
          digitalWrite(north_yellow,LOW);
          digitalWrite(north_green,LOW);
          digitalWrite(west_red,LOW);
          digitalWrite(west_green,LOW);
          digitalWrite(south_yellow,LOW);
          digitalWrite(south_green,LOW);
  
          delay(2000);

          Serial.print("C");
          digitalWrite(south_green,HIGH);
          digitalWrite(north_red,HIGH);
          digitalWrite(west_red,HIGH);
          digitalWrite(east_red,HIGH);
          
          digitalWrite(east_green,LOW);
          digitalWrite(east_yellow,LOW);
          digitalWrite(north_yellow,LOW);
          digitalWrite(north_green,LOW);
          digitalWrite(west_yellow,LOW);
          digitalWrite(west_green,LOW);
          digitalWrite(south_yellow,LOW);
          digitalWrite(south_red,LOW);
          
          delay(10000);
  
          digitalWrite(south_green,LOW);
          digitalWrite(south_yellow,HIGH);
  
          delay(2000);
          Serial.print("N");
        }
        else if(enable_east_flag == 1)
        {
          digitalWrite(north_yellow,HIGH);
          digitalWrite(west_red,HIGH);
          digitalWrite(east_red,HIGH);
          digitalWrite(south_red,HIGH);
    
          digitalWrite(east_yellow,LOW);
          digitalWrite(east_green,LOW);
          digitalWrite(north_red,LOW);
          digitalWrite(north_green,LOW);
          digitalWrite(east_yellow,LOW);
          digitalWrite(west_green,LOW);
          digitalWrite(south_yellow,LOW);
          digitalWrite(south_green,LOW);
  
          delay(2000);

          Serial.print("C");
          digitalWrite(south_green,HIGH);
          digitalWrite(north_red,HIGH);
          digitalWrite(west_red,HIGH);
          digitalWrite(east_red,HIGH);
          
          digitalWrite(east_green,LOW);
          digitalWrite(east_yellow,LOW);
          digitalWrite(north_yellow,LOW);
          digitalWrite(north_red,LOW);
          digitalWrite(west_yellow,LOW);
          digitalWrite(west_green,LOW);
          digitalWrite(south_yellow,LOW);
          digitalWrite(south_red,LOW);
          
          delay(10000);
  
          digitalWrite(south_green,LOW);
          digitalWrite(south_yellow,HIGH);

          delay(2000);
          Serial.print("E");
        }
        else if(enable_south_flag == 1)
        {
          digitalWrite(east_yellow,HIGH);
          digitalWrite(north_red,HIGH);
          digitalWrite(west_red,HIGH);
          digitalWrite(south_red,HIGH);
    
          digitalWrite(east_red,LOW);
          digitalWrite(east_green,LOW);
          digitalWrite(north_yellow,LOW);
          digitalWrite(north_green,LOW);
          digitalWrite(west_yellow,LOW);
          digitalWrite(west_green,LOW);
          digitalWrite(south_yellow,LOW);
          digitalWrite(south_green,LOW);
  
          delay(2000);

          Serial.print("C");
          digitalWrite(south_green,HIGH);
          digitalWrite(north_red,HIGH);
          digitalWrite(west_red,HIGH);
          digitalWrite(east_red,HIGH);
          
          digitalWrite(east_green,LOW);
          digitalWrite(east_yellow,LOW);
          digitalWrite(north_yellow,LOW);
          digitalWrite(north_red,LOW);
          digitalWrite(west_yellow,LOW);
          digitalWrite(west_green,LOW);
          digitalWrite(south_yellow,LOW);
          digitalWrite(south_red,LOW);
          
          delay(10000);
  
          digitalWrite(south_green,LOW);
          digitalWrite(south_yellow,HIGH);

          delay(2000);
          Serial.print("W");
        }
     }
  }

  else
  {
    if(delay_time > 0)
    {
      delay_time = delay_time - 1;

      if(north_flag == 1)
      {
        digitalWrite(north_green,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(south_red,HIGH);
        digitalWrite(east_red,HIGH);

        digitalWrite(east_green,LOW);
        digitalWrite(east_yellow,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_red,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);
      }
      else if(south_flag == 1)
      {
        digitalWrite(south_green,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(north_red,HIGH);
        digitalWrite(east_red,HIGH);

        digitalWrite(east_green,LOW);
        digitalWrite(east_yellow,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_red,LOW);
      }
      else if(east_flag == 1)
      {
        digitalWrite(east_green,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(north_red,HIGH);
        digitalWrite(south_red,HIGH);

        digitalWrite(east_red,LOW);
        digitalWrite(east_yellow,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);
      }
      else if(west_flag == 1)
      {
        digitalWrite(west_green,HIGH);
        digitalWrite(east_red,HIGH);
        digitalWrite(north_red,HIGH);
        digitalWrite(south_red,HIGH);

        digitalWrite(east_green,LOW);
        digitalWrite(east_yellow,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_red,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);
      }
      delay(1000);
    }

   else
    {
      if(north_flag == 1)
      {
        digitalWrite(north_yellow,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(south_red,HIGH);
        digitalWrite(east_red,HIGH);

        digitalWrite(east_green,LOW);
        digitalWrite(east_yellow,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(north_red,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);

        delay(2000);
          
        north_flag = 0;
        
        enable_east_flag = 1;
        enable_south_flag = 0;
        enable_north_flag = 0;
        enable_west_flag  = 0;
      
        Serial.print("E"); 
      }

      else if(east_flag == 1)
      {
        digitalWrite(east_yellow,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(south_red,HIGH);
        digitalWrite(north_red,HIGH);

        digitalWrite(east_green,LOW);
        digitalWrite(east_red,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);

        delay(2000);

        east_flag = 0;
        
        enable_south_flag = 1;
        enable_east_flag = 0;
        enable_north_flag = 0;
        enable_west_flag  = 0;

        Serial.print("S"); 
      }

      else if(west_flag == 1)
      {
        digitalWrite(west_yellow,HIGH);
        digitalWrite(east_red,HIGH);
        digitalWrite(south_red,HIGH);
        digitalWrite(north_red,HIGH);

        digitalWrite(east_green,LOW);
        digitalWrite(east_yellow,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(west_red,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_yellow,LOW);
        digitalWrite(south_green,LOW);

        delay(2000);

        west_flag = 0;
        
        enable_north_flag = 1;
        enable_east_flag = 0;
        enable_south_flag = 0;
        enable_west_flag  = 0;

        Serial.print("N"); 
      }

      else if(south_flag == 1)
      {
        digitalWrite(south_yellow,HIGH);
        digitalWrite(east_red,HIGH);
        digitalWrite(west_red,HIGH);
        digitalWrite(north_red,HIGH);

        digitalWrite(east_green,LOW);
        digitalWrite(east_yellow,LOW);
        digitalWrite(north_green,LOW);
        digitalWrite(north_yellow,LOW);
        digitalWrite(west_yellow,LOW);
        digitalWrite(west_green,LOW);
        digitalWrite(south_red,LOW);
        digitalWrite(south_green,LOW);

        delay(2000);

        south_flag = 0;
        
        enable_west_flag  = 1;
        enable_east_flag = 0;
        enable_south_flag = 0;
        enable_north_flag = 0;

        Serial.print("W"); 
      }
    }
  }

}