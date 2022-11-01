#include <stdio.h>
#include <stdlib.h>

int ggT(int x, int y){
    int rest;     //temporäre variable um den Rest von x und y zu speichern
    if (x == 0) return abs(y); //Falls x 0 ist wird positiv y als ggT ausgegeben
    if (y == 0) return abs(x); //Falls y 0 ist wird positiv x als ggT ausgegeben
    /* x%y wird berechnet und im nächsten Schritt als divisor vom voherigen y Wert verwendet.
    Das passiert solange bis als Rest 0 rauskommt und somit der Dividend der ggT ist.*/
    do {
        rest = x % y;   //Rest wird berechnet
        x = y;  //x nimmt den Wert y an, damit beim nächsten Durchlauf y%Rest berechnet wird.
        y = rest;   //y nimmt den Wert von Rest an
    } while (y != 0); //Schlange wird nur ausgeführt bis Rest = 0

    return abs(x); //positiver ggT wird ausgegben
}

int kgV(int x, int y) {
  int kgv = (abs(x)/ggT( x, y))*abs(y); //kgv wird über die Formel |ab|/ggT(a,b) berechnet
  return kgv;
}

int main() {
  // Lies x und y ein
  char buf[0x30];
  int x = atoi(fgets(buf, 0x30, stdin));
  int y = atoi(fgets(buf, 0x30, stdin));
  
  printf("ggT(x,y) = %d, kgV(x,y) = %d\n", ggT(x,y), kgV(x,y));
  return 0;
}
