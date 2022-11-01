#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void print_array(const int* array, const int laenge){
    for(int i = 0; i < laenge;i++){        
      printf("%d ", array[i]);
    }
    printf("\n");
}

int rand_num(){
    int random = (rand()*1103515245 + 12345) % 214; //weiter randomisiert rand() nocheinmal
    return random;
}

int* int_array_erstellen(const int size){
    int *array = malloc(size * sizeof(int));    //Speicherplatz wird erstellt
    srand(time(NULL));                          //srand wird aufgerufen

    for(int i = 0; i < size; i++){              //jeder Platz bekommt ein random Wert
        array[i] = rand_num();
    }

    return(array);
}

int array_summe(const int *array, const int size){
    int summe = 0;                  
    for (int i = 0; i < size; i++){//for schleife um jedes Element zu summe zu addieren
        summe += array[i];
    }
    return summe;
}

int int_comp(const void* p1, const void* p2) {
    int x1 = *((int*)p1); // Wert an Adr p1
    int x2 = *((int*)p2); // Wert an Adr p2
    if (x1 > x2) { return -1; } // Over- und Underflowsicher
    else if (x1 < x2) { return 1; } // Over- und Underflowsicher
    else { return 0; }
}

void sort_array(void *array, const int size){
    qsort(array, size, sizeof(int), &int_comp);
}

void swap(void *p1, void *p2, size_t width){
    void *temp = malloc(width);     //temporärer Speicherplatz
    memcpy(temp, p2, width);        
    memcpy(p2, p1, width);          
    memcpy(p1, temp, width);        //tausch von p2 und p1
    free(temp);                     //temp wird freigelassen
}

void quicksort(void* array, int byte_size, int array_size, int kisten_vergleichs_funktion(const void *, const void *)){

    if(array_size > 1){         // keine weitere Teilung mehr wenn Array eins groß ist
        int cur = 1, high = 1;  //Zwei variablen zur Orientierung innerhalb des arrays
        //das erste Element im Array agiert als Pivot um das Array zu spalten, einmal in kleiner als, und in größer als Pivot 
        for(int i = 1; i < array_size; i++, cur++){     
            //aktuelles Element wird mit dem Pivot verglichen, falls es größer/gleich ist wird es mit einem Element am ende der Liste vertauscht
            if (kisten_vergleichs_funktion((char*) array + cur * byte_size, array) != 1 ){  //Element wird mit dem Pivot verglichen
                swap((char*) array + cur*byte_size, (char*) array + (array_size - high) * byte_size, byte_size);  // Element wird mit einem am Ende vertauscht
                high++; cur--;  //Array wird eingegrenzt damit schon behandelte Elemente ausgelassen werden
            }    
        }
        cur -= 1, high -= 1;
        swap(array, (char*) array+ cur * byte_size, byte_size); //der Pivot wird in die Mitte der beiden Gruppen getauscht
        quicksort(array, byte_size, cur, kisten_vergleichs_funktion); //kleinerer Teil wird iterativ übergeben
        quicksort((char*) array + (array_size - high) * byte_size, byte_size, high, kisten_vergleichs_funktion);//größerer Teil wird übergeben iterativ
   } 
}



int main(){
    int size = 10;
    int *array = int_array_erstellen(size);
    print_array(array, size);

    quicksort(array, sizeof(int), size, &int_comp);

    print_array(array, size);

    printf("%d\n", array_summe(array, size));

    free(array);
}