int led1Pin = 2;
int led2Pin = 4;
int password = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led1Pin, INPUT);
  pinMode(led2Pin, OUTPUT);
}

void loop()
{
  int val = 0;
  int mes[4], temp[4];
  for(int i = 0; i < 4; i++)
  {
    mes[i] = digitalRead(led1Pin);
    delay(1000);
  }
  if (!password)
  {
    Serial.println ("Please Enter the password to decrypt your message");
    while (Serial.available() == 0);
    password = Serial.read() - '0';
    if (password < 4) Serial.println ("Password accepted,your message will be decrypted");
    else Serial.println ("incorrect Password,you are an imposter");
  }
temp[0] = mes[0];
temp[1] = mes[1];
temp[2] = mes[2];
temp[3] = mes[3];
  if (password < 4)
  {
    for (int i = 0; i < 4; i++)
    {
      mes[((i+4-password) % 4)] = temp[i]; 
    }
  }
  /*for (int i = 0; i < 8; i++)
  {
    val = val + mes[i] * pow(2, i);
  }*/
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(led2Pin, mes[i]);
  }
  val =  mes[3] * pow(2, 3) + mes[2] * pow(2, 2) + mes[1] * pow(2, 1) + mes[0] * pow(2, 0);
  //  Serial.println(analogRead(sensePin));
  Serial.println(val);
  
}
