int station1, station2, station3;
int Speed, speedval, Direction;

void setup() {
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
}

void loop() {
  //potetiometer input
  speedval=analogRead(A3);
  Speed=map(speedval,0,1023,0,255); 
  analogWrite(3,Speed);
  
  // IR-sensor update
  station1=analogRead(A0);
  station2=analogRead(A1);
  station3=analogRead(A2);
  
  //Train Loop
  if (station1 < 500)
  {
    Forward();
  }
  //Train Loop
  if (station2 < 500)
  {
    if (Direction==0)
      {
        Stop;
        Forward();
        
      }
      else 
      {
        Back();
      }
  }
  //Train Loop
  if (station3 < 500)
  {
    Stop();
    Back();
  }
}

  void Forward()
  {
    Direction = 0;
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    delay(1500);
  }
  
  void Back() 
  {
    Direction = 1;
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    delay(1500);
  }
  
  void Stop()
  {
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    delay(5000);
  }
