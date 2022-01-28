// *** affectation des variables ***
int ledPin = 8; // ma led = pin 8 du arduino
int buttonPin = 4; // le bouton = pin 4
int timeDelay = 500; // mon temps de delai 

// L'état initial de mon bouton poussoir (ici éteint)
bool buttonState = false; 

void setup()
{
  pinMode(ledPin, OUTPUT); // init de ma led
  pinMode(buttonPin, INPUT); // init de mon bouton
}

void loop()
{
  // condition 1 : bouton appuyé ET état actuel du bouton éteint
  if (digitalRead(buttonPin) == HIGH && !buttonState)
  {
    digitalWrite(ledPin, HIGH); // j'allume ma led 
    buttonState = !buttonState;  // je change l'état de false à true 
    delay(timeDelay); // je mets un temps de delai
  }

      // condition 2 : bouton appuyé ET état actuel du bouton allumé
  if (digitalRead(buttonPin) == HIGH && buttonState)
  {
    digitalWrite(ledPin, LOW); // j'éteins ma led
    buttonState = !buttonState; // je change l'état du bouton à false
    delay(timeDelay); // je mets un temps de delai
  }
}