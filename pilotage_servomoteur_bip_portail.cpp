/*====================================================
 *  Programme permettant de piloter un bip de
 *  portail à l'aide d'un appui via un servomoteur
 *  + utilisation ESP8266 pour pilotage
 *====================================================*/

/*bibliothèques requises*/
#include<Servo.h>

Servo monServo;

int positioninitDuServo = 0;  //déclaration et définition variable pour position initiale du servomoteur
int i;
const int gpio = 8;   //déclaration pin 8 --> sortie gpio du esp8266

void setup() {
  monServo.attach(9);   //servomoteur branché sur pin 9
  monServo.write(positioninitDuServo);  //initialiser servomoteur
  pinMode(gpio,INPUT);    //déclarer pin 8 (sortie esp8266) --> entrée
}


void loop() {
  /*pilotage du servomoteur en fct sortie ESP8266*/
  if(digitalRead(gpio)==1){
    /*servomoteur tourne sens horaire*/
    for(i=0;i<5;i++){   //boucle (5fois) pour + de proba au clic
      for(positioninitDuServo=0;positioninitDuServo<=30;positioninitDuServo++){
        monServo.write(positioninitDuServo);    //appliquer position servomoteur
        delay(15);
      }
      /*servomoteur tourne sens trigo*/
      for(positioninitDuServo=30;positioninitDuServo>=0;positioninitDuServo--){
        monServo.write(positioninitDuServo);    //appliquer position servomoteur
        delay(15);
      }
    }
  }
  /*----(DEBUG)--test gpio état bas------
  else if(digitalRead(gpio)==0){
    positioninitDuServo = 0;
    monServo.write(positioninitDuServo);
  }
  --------------------------------------*/
}
