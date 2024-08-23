#include <Servo.h>      // bibliothèque Servomoteur

Servo myservo;  //initialisation de la variable du servomoteur

int potpin = 1;  // pin A1 analogique utilisé pour connecté le potentiomètre
int val;    // variable utilisée pour lire la valeur depuis le pin analogique

void setup() {
  myservo.attach(2);  //pin 2 numérique définit pour l'entrée signal du servomoteur
}

void loop() {
  val = analogRead(potpin);            // on lit la valeur du potentiomètre (comprise entre 0 et 1023)
  val = map(val, 0, 1023, 0, 180);     // on adapte cette valeur à celle du servomoteur (valeur comprise entre 0 et 180)
  myservo.write(val);                  // on définit la position du servomoteur à la valeur précédemment adaptée
  delay(15);                           //on attend 15 millisecondes
}
