int sensePin = 1;
int led1Pin = 2;
int led2Pin = 3;
int led3Pin = 4;
int led4Pin = 5;


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
  int val = 800;
  if (val <= 19)
  {
    val = 0;
  }
  if ((val > 19) && (val <= 67))
  {
    val = 1;
  }
  if ((val > 67) && (val <= 115))
  {
    val = 2;
  }
  if ((val > 115) && (val <= 187))
  {
    val = 3;
  }
  if ((val > 187) && (val <= 260))
  {
    val = 4;
  }
  if ((val > 260) && (val <= 309))
  {
    val = 5;
  }
  if ((val > 309) && (val <= 360))
  {
    val = 6;
  }
  if ((val > 360) && (val <= 500))
  {
    val = 7;
  }
  if ((val > 500) && (val <= 637))
  {
    val = 8;
  }
  if ((val > 637) && (val <= 686))
  {
    val = 9;
  }
  if ((val > 686) && (val <= 735))
  {
    val = 10;
  }
  if ((val > 735) && (val <= 807))
  {
    val = 11;
  }
  if ((val > 807) && (val <= 880))
  {
    val = 12;
  }
  if ((val > 880) && (val <= 930))
  {
    val = 13;
  }
  if ((val > 930) && (val <= 980))
  {
    val = 14;
  }
  if (val > 980)
  {
    val = 15;
  }
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
      mes[((i + password) % 4)] = temp[i];
    }
  }

  for (int i = 0; i < 4; i++)
    {
      digitalWrite(i+2, mes[i]);
    }
  Serial.println(digitalRead(2));
  Serial.println(digitalRead(3));
  Serial.println(digitalRead(4));
  Serial.println(digitalRead(5));
  /*digitalWrite(led1Pin, mes[0]);
    digitalWrite(led2Pin, mes[1]);
    digitalWrite(led3Pin, mes[2]);
    digitalWrite(led4Pin, mes[3]);
    digitalWrite(led5Pin, mes[4]);
    digitalWrite(led6Pin, mes[5]);
    digitalWrite(led7Pin, mes[6]);
    digitalWrite(led8Pin, mes[7]);*/
delay(1000);
}
