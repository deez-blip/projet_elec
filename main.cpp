#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN        6
#define NUMPIXELS 64

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 250 // Time (in milliseconds) to pause between pixels

// Recupere la position du pointeur
int Convert (int x, int y){
  int val_return = x + 8*y;
  return(val_return);
}
int anim_victoire_j1(){
  int x;
  int y;
  for(y = 0; y < 7; y++){
    if(y%2 == 0){
      for(x = 0; x < 64; x++){
        pixels.setPixelColor(x, pixels.Color(0,150,0));
      }
    }else{
      for(x = 0; x < 64; x++){
        pixels.setPixelColor(x, pixels.Color(0,0,0));
      }
    }
    delay(200);
  }
}
int anim_victoire_j2(){
  int x;
  int y;
  for(y = 0; y < 7; y++){
    if(y%2 == 0){
      for(x = 0; x < 64; x++){
        pixels.setPixelColor(x, pixels.Color(0,150,150));
      }
    }else{
      for(x = 0; x < 64; x++){
        pixels.setPixelColor(x, pixels.Color(0,0,0));
      }
    }
    delay(200);
  }
}

int val_x = 3;
int val_y = 3;
bool next_rouge = false;
bool retour_rouge = false;

int tableau[3][4] = {{0,1,8,9},{3,4,11,12},{6,7,14,15},
};

// Initialisation de toutes les cases disponibles
int tableau_1[4] = {0,1,8,9};
int tableau_2[4] = {3,4,11,12};
int tableau_3[4] = {6,7,14,15};

int tableau_4[4] = {24,25,32,33};
int tableau_5[4] = {27,28,35,36};
int tableau_6[4] = {30,31,38,39};

int tableau_7[4] = {48,49,56,57};
int tableau_8[4] = {51,52,59,60};
int tableau_9[4] = {54,55,62,63};
// Initialisation des cases "en possession" des joueurs
int tab[3][3];
int tab2[3][3];


bool tableau1 = false;
bool tableau2 = false;
bool tableau3 = false;
bool tableau4 = false;
bool tableau5 = false;
bool tableau6 = false;
bool tableau7 = false;
bool tableau8 = false;
bool tableau9 = false;

int joueur = 0;



void setup(){
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(80);
  Serial.begin(9600);
  pinMode(9, OUTPUT);

  // QUADRILLAGE ROUGE
  for(int x=0; x<8; x++) { // For each pixel...
    for (int y = 0; y < 8; y++){
      if(x==2 || x==5 || y==2 || y==5){
        pixels.setPixelColor(Convert(x,y), pixels.Color(150, 0, 0));
      }
    }
  pixels.show();   // Send the updated pixel colors to the hardware.
  }
  pixels.setPixelColor(Convert(val_x,val_y), pixels.Color(0,0,150));
}

void loop(){

  // QUADRILLAGE ROUGE 
  for(int x=0; x<8; x++) { // For each pixel...
  for (int y = 0; y < 8; y++){
    if(x==2 || x==5 || y==2 || y==5){
      pixels.setPixelColor(Convert(x,y), pixels.Color(150, 0, 0));
      }
    }
  }
  pixels.show();

  /* -------------------------------------- BOUTON --------------------------------- */
  if(digitalRead(9) == 1){
    int valeur = Convert(val_x, val_y);
    int x;
    Serial.println("boutton appuyé");
    Serial.println(val_x);
    Serial.println(val_y);
    for(x = 0; x <4; x++){
      // Verifie dans quelle case est le joueur
      if(tableau_1[x] == valeur){
        // Verifie si la case ou il est est vide
        if(pixels.getPixelColor(Convert((val_x + 1), val_y)) == 0 || pixels.getPixelColor(Convert((val_x - 1), val_y)) == 0|| pixels.getPixelColor(Convert(val_x, (val_y + 1))) == 0 || pixels.getPixelColor(Convert(val_x, (val_y - 1))) == 0){
          tableau1 = true;
          val_x = 3;
          val_y = 3;
          if(joueur == 0){
            tab[0][0] = 1;
          }else{
            tab2[0][0] = 1;
          }
        }
      }
      if(tableau_2[x] == valeur){
        if(pixels.getPixelColor(Convert((val_x + 1), val_y)) == 0 || pixels.getPixelColor(Convert((val_x - 1), val_y)) == 0|| pixels.getPixelColor(Convert(val_x, (val_y + 1))) == 0 || pixels.getPixelColor(Convert(val_x, (val_y - 1))) == 0){
          tableau2 = true;
          val_x = 3;
          val_y = 3;
          if(joueur == 0){
            tab[0][1] = 1;
          }else{
            tab2[0][1] = 1;
          }
        }
      }
      if(tableau_3[x] == valeur){
        if(pixels.getPixelColor(Convert((val_x + 1), val_y)) == 0 || pixels.getPixelColor(Convert((val_x - 1), val_y)) == 0|| pixels.getPixelColor(Convert(val_x, (val_y + 1))) == 0 || pixels.getPixelColor(Convert(val_x, (val_y - 1))) == 0){
          tableau3 = true;
          val_x = 3;
          val_y = 3;
          if(joueur == 0){
            tab[0][2] = 1;
          }else{
            tab2[0][2] = 1;
          }
        }
      }
      if(tableau_4[x] == valeur){
        if(pixels.getPixelColor(Convert((val_x + 1), val_y)) == 0 || pixels.getPixelColor(Convert((val_x - 1), val_y)) == 0|| pixels.getPixelColor(Convert(val_x, (val_y + 1))) == 0 || pixels.getPixelColor(Convert(val_x, (val_y - 1))) == 0){
          tableau4 = true;
          val_x = 3;
          val_y = 3;
          if(joueur == 0){
            tab[1][0] = 1;
          }else{
            tab2[1][0] = 1;
          }
        }
      }
      if(tableau_5[x] == valeur){
        if(pixels.getPixelColor(Convert((val_x + 1), val_y)) == 0 || pixels.getPixelColor(Convert((val_x - 1), val_y)) == 0|| pixels.getPixelColor(Convert(val_x, (val_y + 1))) == 0 || pixels.getPixelColor(Convert(val_x, (val_y - 1))) == 0){
          tableau5 = true;
          val_x = 3;
          val_y = 3;
          if(joueur == 0){
            tab[1][1] = 1;
          }else{
            tab2[1][1] = 1;
          }
        }
      }
      if(tableau_6[x] == valeur){
        if(pixels.getPixelColor(Convert((val_x + 1), val_y)) == 0 || pixels.getPixelColor(Convert((val_x - 1), val_y)) == 0|| pixels.getPixelColor(Convert(val_x, (val_y + 1))) == 0 || pixels.getPixelColor(Convert(val_x, (val_y - 1))) == 0){
          tableau6 = true;
          val_x = 3;
          val_y = 3;
          if(joueur == 0){
            tab[1][2] = 1;
          }else{
            tab2[1][2] = 1;
          }
        }
      }
      if(tableau_7[x] == valeur){
        if(pixels.getPixelColor(Convert((val_x + 1), val_y)) == 0 || pixels.getPixelColor(Convert((val_x - 1), val_y)) == 0|| pixels.getPixelColor(Convert(val_x, (val_y + 1))) == 0 || pixels.getPixelColor(Convert(val_x, (val_y - 1))) == 0){
          tableau7 = true;
          val_x = 3;
          val_y = 3;
          if(joueur == 0){
            tab[2][0] = 1;
          }else{
            tab2[2][0] = 1;
          }
        }
      }
      if(tableau_8[x] == valeur){
        if(pixels.getPixelColor(Convert((val_x + 1), val_y)) == 0 || pixels.getPixelColor(Convert((val_x - 1), val_y)) == 0|| pixels.getPixelColor(Convert(val_x, (val_y + 1))) == 0 || pixels.getPixelColor(Convert(val_x, (val_y - 1))) == 0){
          tableau8 = true;
          val_x = 3;
          val_y = 3;
          if(joueur == 0){
            tab[2][1] = 1;
          }else{
            tab2[2][1] = 1;
          }
        }
      }
      if(tableau_9[x] == valeur){
        if(pixels.getPixelColor(Convert((val_x + 1), val_y)) == 0 || pixels.getPixelColor(Convert((val_x - 1), val_y)) == 0|| pixels.getPixelColor(Convert(val_x, (val_y + 1))) == 0 || pixels.getPixelColor(Convert(val_x, (val_y - 1))) == 0){
          tableau9 = true;
          val_x = 3;
          val_y = 3;
          if(joueur == 0){
            tab[2][2] = 1;
          }else{
            tab2[2][2] = 1;
          }
        }
      }
    }
  }

  // Change le joueur et fait que la case qui vient detre prise ne puisse pas etre reprise une autre fois
  if(tableau1){
    if(joueur == 0){
      joueur = 1;
      tableau1 = false;
    }else if(joueur == 1){
        joueur = 0;
        tableau1 = false;
      }
    }
  if(tableau2){
    if(joueur == 0){
      joueur = 1;
      tableau2 = false;
    }else if(joueur == 1){
        joueur = 0;
        tableau2 = false;
      }
    }
  if(tableau3){
    if(joueur == 0){
      joueur = 1;
      tableau3 = false;
    }else if(joueur == 1){
        joueur = 0;
        tableau3 = false;
      }
    }
  if(tableau4){
    if(joueur == 0){
      joueur = 1;
      tableau4 = false;
    }else if(joueur == 1){
        joueur = 0;
        tableau4 = false;
      }
    }
  if(tableau5){
    if(joueur == 0){
      joueur = 1;
      tableau5 = false;
    }else if(joueur == 1){
        joueur = 0;
        tableau5 = false;
      }
    }
  if(tableau6){
    if(joueur == 0){
      joueur = 1;
      tableau6 = false;
    }else if(joueur == 1){
        joueur = 0;
        tableau6 = false;
      }
    }
  if(tableau7){
    if(joueur == 0){
      joueur = 1;
      tableau7 = false;
    }else if(joueur == 1){
        joueur = 0;
        tableau7 = false;
      }
    }
  if(tableau8){
    if(joueur == 0){
      joueur = 1;
      tableau8 = false;
    }else if(joueur == 1){
        joueur = 0;
        tableau8 = false;
      }
    }
  if(tableau9){
    if(joueur == 0){
      joueur = 1;
      tableau9 = false;
    }else if(joueur == 1){
        joueur = 0;
        tableau9 = false;
      }
    }

 /* ----------------------- CASE DES JOUEURS ---------------- */
  int x;
  int y;
  for(x = 0; x < 3; x++){
    for(y = 0; y < 3; y++){
      if(tab[x][y] == 1){
        if(x == 0){
          if(y == 0){
            pixels.setPixelColor(tableau_1[0], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_1[1], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_1[2], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_1[3], pixels.Color(0,150,0));
          }
          if(y == 1){
            pixels.setPixelColor(tableau_2[0], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_2[1], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_2[2], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_2[3], pixels.Color(0,150,0));
          }
          if(y == 2){
            pixels.setPixelColor(tableau_3[0], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_3[1], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_3[2], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_3[3], pixels.Color(0,150,0));
          }
        }
        if(x == 1){
          if(y == 0){
            pixels.setPixelColor(tableau_4[0], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_4[1], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_4[2], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_4[3], pixels.Color(0,150,0));
          }
          if(y == 1){
            pixels.setPixelColor(tableau_5[0], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_5[1], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_5[2], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_5[3], pixels.Color(0,150,0));
          }
          if(y == 2){
            pixels.setPixelColor(tableau_6[0], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_6[1], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_6[2], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_6[3], pixels.Color(0,150,0));
          }
        }
        if(x == 2){
          if(y == 0){
            pixels.setPixelColor(tableau_7[0], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_7[1], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_7[2], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_7[3], pixels.Color(0,150,0));
          }
          if(y == 1){
            pixels.setPixelColor(tableau_8[0], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_8[1], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_8[2], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_8[3], pixels.Color(0,150,0));
          }
          if(y == 2){
            pixels.setPixelColor(tableau_9[0], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_9[1], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_9[2], pixels.Color(0,150,0));
            pixels.setPixelColor(tableau_9[3], pixels.Color(0,150,0));
          }
        }
      }
    }
  }

  for(x = 0; x < 3; x++){
    for(y = 0; y < 3; y++){
      if(tab2[x][y] == 1){
        if(x == 0){
          Serial.println(y);
          if(y == 0){
            pixels.setPixelColor(tableau_1[0], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_1[1], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_1[2], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_1[3], pixels.Color(0,150,150));
          }
          if(y == 1){
            pixels.setPixelColor(tableau_2[0], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_2[1], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_2[2], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_2[3], pixels.Color(0,150,150));
          }
          if(y == 2){
            pixels.setPixelColor(tableau_3[0], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_3[1], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_3[2], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_3[3], pixels.Color(0,150,150));
          }
        }
        if(x == 1){
          if(y == 0){
            pixels.setPixelColor(tableau_4[0], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_4[1], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_4[2], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_4[3], pixels.Color(0,150,150));
          }
          if(y == 1){
            pixels.setPixelColor(tableau_5[0], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_5[1], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_5[2], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_5[3], pixels.Color(0,150,150));
          }
          if(y == 2){
            pixels.setPixelColor(tableau_6[0], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_6[1], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_6[2], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_6[3], pixels.Color(0,150,150));
          }
        }
        if(x == 2){
          if(y == 0){
            pixels.setPixelColor(tableau_7[0], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_7[1], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_7[2], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_7[3], pixels.Color(0,150,150));
          }
          if(y == 1){
            pixels.setPixelColor(tableau_8[0], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_8[1], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_8[2], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_8[3], pixels.Color(0,150,150));
          }
          if(y == 2){
            pixels.setPixelColor(tableau_9[0], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_9[1], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_9[2], pixels.Color(0,150,150));
            pixels.setPixelColor(tableau_9[3], pixels.Color(0,150,150));
          }
        }
      }
    }
  }

/* ------------------------------ VICTOIRE J1 --------------- */
  if(tab[0][0] == 1){
    if(tab[0][1] == 1 && tab[0][2] == 1){
      anim_victoire_j1();
    }
    if(tab[1][0] == 1 && tab[2][0] == 1){
      anim_victoire_j1();
    }
    if(tab[1][1] == 1 && tab[2][2] == 1){
      anim_victoire_j1();
    }
  }
  if(tab[1][0] == 1 && tab[1][1] == 1 && tab[1][2] == 1){
    anim_victoire_j1();
  }
  if(tab[0][1] == 1 && tab[1][1] == 1 && tab[2][1] == 1){
    anim_victoire_j1();
  }
  if(tab[2][0] == 1){
    if(tab[1][1] == 1 && tab[0][2] == 1){
      anim_victoire_j1();
    }
    if(tab[2][1] == 1 && tab[2][2] == 1){
      anim_victoire_j1();
    }
  }

/* ------------------------ VICTOIRE J2 ------------ */
  if(tab2[0][0] == 1){
    if(tab2[0][1] == 1 && tab2[0][2] == 1){
      anim_victoire_j2();
    }
    if(tab2[1][0] == 1 && tab2[2][0] == 1){
      anim_victoire_j2();
    }
    if(tab2[1][1] == 1 && tab2[2][2] == 1){
      anim_victoire_j2();
    }
  }
  if(tab2[1][0] == 1 && tab2[1][1] == 1 && tab2[1][2] == 1){
    anim_victoire_j2();
  }
  if(tab2[0][1] == 1 && tab2[1][1] == 1 && tab2[2][1] == 1){
    anim_victoire_j2();
  }
  if(tab2[2][0] == 1){
    if(tab2[1][1] == 1 && tab2[0][2] == 1){
      anim_victoire_j2();
    }
    if(tab2[2][1] == 1 && tab2[2][2] == 1){
      anim_victoire_j2();
    }
  }


// ------------------------------------- DEPLACEMENT AXE X ---------------------------------------------------//
  if(analogRead(A0)<1000 && analogRead(A0)>100){
    pixels.setPixelColor(Convert(val_x,val_y), pixels.Color(0,0,150));
  }else if(analogRead(A0)>=100){
    // Pour pas depasser du terrain
    if(val_x >= 7){
      }else{
        val_x += 1;
        //Change la couleur de la position actuel du pointeur
        pixels.setPixelColor(Convert(val_x,val_y), pixels.Color(0,0,150));
        //SI la position précédente du pointeur n'est pas rouge, alors on la "vide" en la rendant blanche
        if(pixels.getPixelColor(Convert((val_x - 1), val_y)) != pixels.getPixelColor(2)){
          pixels.setPixelColor(Convert((val_x - 1), val_y), pixels.Color(0,0,0));
        }
      }

    }else if(analogRead(A0)<= 100){
    // POur pas depasser du terrain
    if(val_x <= 0){
    }else{
      val_x -= 1;
      pixels.setPixelColor(Convert(val_x,val_y), pixels.Color(0,0,150));
      if(pixels.getPixelColor(Convert((val_x + 1), val_y)) != pixels.getPixelColor(2)){
        pixels.setPixelColor(Convert((val_x + 1), val_y), pixels.Color(0,0,0));
      }
    }
  }

// ------------------------------------- DEPLACEMENT AXE y ---------------------------------------------------//
  if(analogRead(A1)<1000 && analogRead(A1)>100){
      pixels.setPixelColor(Convert(val_x,val_y), pixels.Color(0,0,150));
    }else if(analogRead(A1)>=1000){
      if(val_y >= 7){
        }else{
          val_y += 1;
          pixels.setPixelColor(Convert(val_x,val_y), pixels.Color(0,0,150));
          if(pixels.getPixelColor(Convert(val_x, (val_y - 1))) != pixels.getPixelColor(2)){
            pixels.setPixelColor(Convert(val_x, (val_y - 1)), pixels.Color(0,0,0));
          }
        }

      }else if(analogRead(A1)<= 100){
      if(val_y <= 0){
      }else{
        val_y -= 1;
        pixels.setPixelColor(Convert(val_x,val_y), pixels.Color(0,0,150));
        if(pixels.getPixelColor(Convert(val_x, (val_y + 1))) != pixels.getPixelColor(2)){
          pixels.setPixelColor(Convert(val_x, (val_y + 1)), pixels.Color(0,0,0));
        }
      }
    }
  //vert 35584 , bleu 35723
  pixels.show();
  delay(250);
}







  /*----------------------------- COURS D'ELECS -------------------------------------------------------------------------------------------------------------------------------
  Serial.println(analogRead(A0));
  Serial.println(analogRead(A1));
  analogWrite(10, (analogRead(A0)/4));
  analogWrite(9, (analogRead(A1)/4));
  /*
  int etatBT = digitalRead(5);
  Serial.println(digitalRead(6));
  if(digitalRead(5)==0 && etatBT==1){
    if(digitalRead(6)==1){
      digitalWrite(6, LOW);
    }else{
      digitalWrite(6, HIGH);
    }
  }
  */



  /*
  for (int i = 5; i < 8; i++) {
    digitalWrite(i, HIGH);
    delay(500);
    digitalWrite(i, LOW);
  }
  */

/*
   // analogique = infinité de valeur; digitale = 0 ou 1
  Serial.begin(9600);
  Serial.println("oklm");
  /*
  for (int i = 5; i < 8; i++) pinMode(i, OUTPUT);
  pinMode(5, INPUT);

  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
*/

  /*
  if(tableau2){
    if(joueur == 0){
      pixels.setPixelColor(tableau_2[0], pixels.Color(0,150,0));
      pixels.setPixelColor(tableau_2[1], pixels.Color(0,150,0));
      pixels.setPixelColor(tableau_2[2], pixels.Color(0,150,0));
      pixels.setPixelColor(tableau_2[3], pixels.Color(0,150,0));
      joueur = 1;
      tableau2 = false;
    }else if(joueur == 1){
      pixels.setPixelColor(tableau_2[0], pixels.Color(0,150,150));
      pixels.setPixelColor(tableau_2[1], pixels.Color(0,150,150));
      pixels.setPixelColor(tableau_2[2], pixels.Color(0,150,150));
      pixels.setPixelColor(tableau_2[3], pixels.Color(0,150,150));
      joueur = 0;
      tableau2 = false;
    }
  }
  if(tableau3){
    if(joueur == 0){
      pixels.setPixelColor(tableau_3[0], pixels.Color(0,150,0));
      pixels.setPixelColor(tableau_3[1], pixels.Color(0,150,0));
      pixels.setPixelColor(tableau_3[2], pixels.Color(0,150,0));
      pixels.setPixelColor(tableau_3[3], pixels.Color(0,150,0));
      joueur = 1;
    }else if(joueur == 1){
      pixels.setPixelColor(tableau_3[0], pixels.Color(0,150,150));
      pixels.setPixelColor(tableau_3[1], pixels.Color(0,150,150));
      pixels.setPixelColor(tableau_3[2], pixels.Color(0,150,150));
      pixels.setPixelColor(tableau_3[3], pixels.Color(0,150,150));
      joueur = 0;
    }
  }*/