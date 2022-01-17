// A2Q2
// Ajay Choudhury (18018)
void setup()
{
    // for red led
    pinMode(2, INPUT);
    pinMode(13, OUTPUT);
    // for blue led
    pinMode(3, INPUT);
    pinMode(10, OUTPUT);
    // for green led
    pinMode(4, INPUT);
    pinMode(8, OUTPUT);
}

void loop()
{
    // for red led
    if (digitalRead(2) == 1)
    {
        digitalWrite(13, HIGH);
    }
    else
    {
        digitalWrite(13, LOW);
        // for blue led
        if (digitalRead(3) == 1)
        {
            digitalWrite(10, HIGH);
        }
        else
        {
            digitalWrite(10, LOW);
            // for green led
            if (digitalRead(4) == 1)
            {
                digitalWrite(8, HIGH);
            }
            else
            {
                digitalWrite(8, LOW);
            }
        }
    }
}