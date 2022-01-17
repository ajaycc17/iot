//Ajay Choudhury (18018)
//Project-1 (IoT)

// library for LCD display
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// constants for ultrasonic sensor
const int trigPin = 8;
const int echoPin = 9;

// variables for ultrasonic sensor
long duration;
int distance;

// variable for temperature sensor
float temp;

// setup function
void setup()
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);

    // define output and input pin for ultrasonic sensor
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    // define input pin for PIR sensor
    pinMode(6, INPUT);

    // begin serial monitor
    Serial.begin(9600);
}

// loop function
void loop()
{
    // initialize trigger pin of ultrasonic sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    // turn on trigger to initialize the sensor
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // receive the signal on echo
    duration = pulseIn(echoPin, HIGH);

    // calculate distance of the object with reference to speed of sound
    // and double distance travelled by sound
    distance = duration * 0.034 / 2;

    // read PIR's output
    int value;
    value = digitalRead(6);

    // read temperature and convert it to celsius
    temp = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);

    // printing temperature on serial monitor
    Serial.print(temp);
    Serial.print(", ");

    // printing presence/absence on serial monitor and LCD
    if (value == 1)
    {
        Serial.print("Present, ");
        lcd.print("Present, ");
    }
    else
    {
        Serial.print("Absent, ");
        lcd.print("Absent, ");
    }

    // print distance calculated on serial monitor and LCD
    Serial.println(distance);
    lcd.print(distance);
    lcd.print(" ");

    // delay of 2 seconds
    delay(2000);

    // set the cursor to column 0, line 0 to clear the previous output
    // and log new output
    lcd.setCursor(0, 0);
}
