#include <stdlib.h>
#include <time.h>

//Unterprogramm deklarieren
int geheimzahl();

//Mainprogramm zur Abfrage der Ratezahl
int main(){
    int ratezahl;
    int zufallszahl;
    int versuche;
    int weiter;

    zufallszahl = geheimzahl(zufallszahl);
    printf ("An welche Zahl denke ich?  ");
    scanf ("%d", &ratezahl);

//Abbruchbedingung
    if (ratezahl < 1){
        exit(-1);
    }

//Zahl überprüfen
    while (ratezahl != zufallszahl){
        if (ratezahl > zufallszahl){
            ++versuche;
            printf ("\nDeine Zahl ist zu gross\n");
            printf ("Versuche es erneut: ");
            scanf ("%d", &ratezahl);
        }
        else if (ratezahl < zufallszahl){
            ++versuche;
            printf ("\nDeine Zahl ist zu klein\n");
            printf ("Versuche es erneut: ");
            scanf ("%d", &ratezahl);
        }
    }

//Richtige Zahl erraten
    if (ratezahl == zufallszahl){
        ++versuche;
        printf ("\nDu hast die richtige Zahl gefunden");
        printf ("\nDu hast %d Versuche gebraucht\n", versuche);
    }

//Abbruchbedingung
    printf("\nWollen Sie nochmal spielen, dann Druecken sie die 1\n");
    scanf ("%d", &weiter);
    if (weiter == 1){
        main();
    }
    else{
        exit(-1);
    }
}


//Zahl zwischen 1 und 50 generieren
int geheimzahl(){
    srand (time(NULL));

    int zufallszahl;

    zufallszahl = rand() %50+1;

    while (zufallszahl < 1){
        zufallszahl = rand () %50+1;
    }

    return zufallszahl;
}