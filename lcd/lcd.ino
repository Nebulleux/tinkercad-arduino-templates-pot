#include <LiquidCrystal.h> // bibliothèque écran LCD
#include <Servo.h>          // bibliothèque Servomoteur
  Servo myservo;            //initialisation de la variable du servomoteur
  LiquidCrystal lcd(12, 11, 5, 4, 3, 2);    // initialisation de l'écran LCD avec les nombres correspondants au pins

void setup() {
  myservo.attach(9);          //pin 9 numérique définit pour l'entrée signal du servomoteur
  lcd.begin(16, 2);           // Démarrage de l'écran LCD avec le nombre de colonnes et de lignes
  lcd.print("pos servo(degre)");  // affichage d'un message sur la première ligne de l'écran
}

void loop() {
  
  for(int i=0; i<=180; i++){  //une boucle est créée dans laquelle l'angle du servomoteur va varier de 0° à 180°
    myservo.write(i);
    lcd.setCursor(0, 1);         //on définit la 2eme ligne d'écriture pour l'écran LCD
    lcd.print(i);
    delay(10);                //on applique cette boucle pour prendre 1° toutes les 10 ms
  }                         //fin de la boucle

  delay(500);             //on attend une demiseconde entre l'aller et le retour

  for(int a=180; a>=0; a--){  //une boucle est créée dans laquelle l'angle du servomoteur va varier de 180° à 0°
    myservo.write(a);
    lcd.setCursor(0, 1);         //on définit la 2eme ligne d'écriture pour l'écran LCD
    lcd.print(a);
    lcd.print("   ");       // print créé pour "débugger" l'écran LCD au retour du servomoteur
    delay(10);              //on applique cette boucle pour enlever 1° toutes les 10 ms
  }                        //fin de la boucle
}
 
