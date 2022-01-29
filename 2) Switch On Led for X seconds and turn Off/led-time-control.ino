int ledPin = 8; 
int buttonPin = 4; 
unsigned long ledTimer;

void setup()
{
  pinMode(ledPin, OUTPUT); // init de ma led
  pinMode(buttonPin, INPUT); // init de mon bouton
}

void loop()
{
   if (digitalRead(buttonPin) == HIGH)
   {
       ledTimer = millis();
       digitalWrite(ledPin, HIGH);
       
       while(ledTimer <= 30000) 
       {
           ledTimer = millis();
           continue;
        }
        
        digitalWrite(ledPin, LOW);
  }
}