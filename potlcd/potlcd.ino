#include <LiquidCrystal.h> // bibliothèque écran LCD
#include <Servo.h>          // bibliothèque Servomoteur
  Servo myservo;                          //initialisation de la variable du servomoteur
  LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // initialisation de l'écran LCD avec les nombres correspondants au pins

int potpin = 1;  // pin A1 analogique utilisé pour connecté le potentiomètre
int val;          // variable utilisée pour lire la valeur depuis le pin analogique

void setup() {
  myservo.attach(9);      //pin 9 numérique définit pour l'entrée signal du servomoteur
  lcd.begin(16, 2);        // Démarrage de l'écran LCD avec le nombre de colonnes et de lignes
  lcd.print("pos servo(degre)");  // affichage d'un message sur la première ligne de l'écran
}

void loop() {
    lcd.setCursor(0, 1);                //on définit la 2eme ligne d'écriture pour l'écran LCD
    val = analogRead(potpin);            // on lit la valeur du potentiomètre (comprise entre 0 et 1023)
    val = map(val, 0, 1023, 0, 180);     // on adapte cette valeur à celle du servomoteur (valeur comprise entre 0 et 180)
    myservo.write(val);                  // on définit la position du servomoteur à la valeur précédemment adaptée
    lcd.print(val);                       //on affiche cette valeur en temps réel sur l'écran LCD
  
  if (val<100) {
    lcd.print("   ");                     // boucle créée pour "débugger" l'écran LCD au retour du servomoteur
  }
  
  delay(15);                              //on attend 15 millisecondes
}
 
