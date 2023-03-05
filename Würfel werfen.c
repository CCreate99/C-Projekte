#include <stdlib.h>
#include <time.h>

int wuerfelwerfen ();

int main(){
    int zufallszahl;
    int exit;

    zufallszahl = wuerfelwerfen(zufallszahl);

    printf ("Du hast eine %d gewuerfelt", zufallszahl);

    printf ("\n Druecke 1 um erneut zu Wuerfeln ");
    scanf ("%d", &exit);
    if (exit == 1){
        main();
    }
    else {
        exit(-1);
    }
}

int wuerfelwerfen(){
    srand (time(NULL));

    int zufallszahl;

    zufallszahl = rand() %6+1;

    while (zufallszahl == 0){
        zufallszahl = rand () %6+1;
    }

    return zufallszahl;
}