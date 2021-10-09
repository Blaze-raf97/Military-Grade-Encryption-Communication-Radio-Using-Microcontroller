int sensePin = 1;
int led1Pin = 2;
//int led2Pin = 3;
//int led3Pin = 4;
//int led4Pin = 5;


int password = 0;
void setup() {
  Serial.begin(9600);
  pinMode(led1Pin, OUTPUT);
  //pinMode(led2Pin, OUTPUT);
  //pinMode(led3Pin, OUTPUT);
  //pinMode(led4Pin, OUTPUT);
}

void loop() {
  //int val = analogRead(sensePin);
  //val = map(val, 0, 1023, 0, 15);
  int val = 12;
  int quot = val, rem = 0;
  boolean mes[] = {false, false, false, false};
  boolean temp[] = {false, false, false, false};
  for (int i = 0; i < 4; i++)
  {
    if ( quot )
    {
      rem = quot % 2;
      quot = quot / 2;
      if (rem)
      {
        mes[i] = true;
        temp[i] = true;
      }
    }

  }

  if (!password)
  {
    Serial.println ("Please Enter the password to encrypt your message");
    while (Serial.available() == 0);
    password = Serial.read() - '0';
    if (password < 4) Serial.println ("correct Password,your message will be encrypted");
    else Serial.println ("incorrect Password,there will be no encryption");
  }

  if (password < 4)
  {
    for (int i = 0; i < 4; i++)
    {
      mes[((i+password) % 4)] = temp[i]; 
    }
  }
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(led1Pin, mes[i]);
    delay(1000);
  }
  /*digitalWrite(led1Pin, mes[0]);
    digitalWrite(led2Pin, mes[1]);
    digitalWrite(led3Pin, mes[2]);
    digitalWrite(led4Pin, mes[3]);
    digitalWrite(led5Pin, mes[4]);
    digitalWrite(led6Pin, mes[5]);
    digitalWrite(led7Pin, mes[6]);
    digitalWrite(led8Pin, mes[7]);*/

}
