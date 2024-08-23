#include <Servo.h>                   //ajout de la bibliothèque servo.h qui va nous permettre de commander ce composant
  Servo myservo;                     //on définit la variable de ce composant
    
void setup(){                        //on définit le pin 3 à utiliser pour commander le servomoteur (pin signal)
  myservo.attach(3);
}

void loop(){
  for(int i=0; i<=180; i++){          //une boucle est créée dans laquelle l'angle du servomoteur va varier de 0° à 180°
    myservo.write(i);
    delay(10);                        //on applique cette boucle pour prendre 1° toutes les 10 ms
  }                                      //fin de la boucle

  delay(500);                         //on attend une demiseconde

  for(int i=180; i>=0; i--){          //une boucle est créée dans laquelle l'angle du servomoteur va varier de 180° à 0°
    myservo.write(i);
    delay(10);                        //on applique cette boucle pour enlever 1° toutes les 10 ms
  }                                     //fin de la boucle
}
