#include <stdio.h>
#include <stdlib.h>

double sin(double x){
  double sinus = 0; // Berechnet den Sinus als Taylorentwicklung
  double summand = x; // Aktueller Summand der Taylorentwicklung
  int count = 1; // Hilft beim Berechnen des Nenners
  double klein = 1e-8; // Eine kleine Zahl
  
  // Solange |summand| > klein
  while (summand > klein || -summand > klein) {
    sinus += summand; //sinus wird zum summand addiert
    summand = -(summand*x*x) / ((count+1) * (count+2)); //nächster Summand wird berechnet
    count += 2; 
  }
  return sinus;
}

double cos(double x){
  double cosinus = 0; // Berechnet den Cosinus als Taylorentwicklung
  double summand = 1; // Startet bei eins, da erster Summand eins ist
  int count = 1;      // Hilft beim Berechnen des Nenners
  double klein = 1e-8;// Eine kleine Zahl

  // Solange |summand| > klein
  while (summand > klein || -summand > klein) {
    cosinus += summand; //cosinus wird zum Summand addiert
    summand = -(summand*x*x) / ((count+1) * (count)); //nächster Summand wird berechnet
    count += 2; 
  }
  return cosinus;
}

double tan(double x){
  double tangens = sin(x)/cos(x); //tangens wird durch sin/cos berechnet
  return tangens;
}

int main() {
  // x wird eingelesen
  char buf[0x30];
  double x = atof(fgets(buf, 0x30, stdin));
  
  printf("cos(x) = %0.4f\nsin(x) = %0.4f\ntan(x) = %0.4f\n", cos(x), sin(x), tan(x));
  return 0;
}
