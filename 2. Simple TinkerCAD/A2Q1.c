// A2Q1
//Ajay Choudhury (18018)
void setup()
{
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  // for Blue LED
  digitalWrite(10, HIGH);
  delay(3000);
  digitalWrite(10, LOW);

  // for Red LED
  digitalWrite(13, HIGH);
  delay(2000);
  digitalWrite(13, LOW);

  // for Green LED
  digitalWrite(8, HIGH);
  delay(3000);
  digitalWrite(8, LOW);
}