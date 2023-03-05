int main(){
    float h, k, wochentag;
    int tag, monat, jahr, wochentag1;

    printf ("Gib einen Tag ein: ");
    scanf ("%d", &tag);
    printf ("Gib einen Monat ein: ");
    scanf ("%d", &monat);
    printf ("Gib ein Jahr ein: ");
    scanf ("%d", &jahr);

    if (monat<=2){
        h = monat+12;
        k = jahr-1;
    }
    else{
        h=monat;
        k=jahr;
    }
    wochentag1 = (tag+2*h+(3*h+3)/5+k+k/4-k/100+k/400+1);
    wochentag = wochentag1 % 7;

    if (wochentag == 0){
        printf ("\nEs ist Sonntag");
    }
    else if (wochentag == 1){
        printf ("\nEs ist Montag");
    }
    else if (wochentag == 2){
        printf ("\nEs ist Dienstag");
    }
    else if (wochentag == 3){
        printf ("\nEs ist Mittwoch");
    }
    else if (wochentag == 4){
        printf ("\nEs ist Donnerstag");
    }
    else if (wochentag == 5){
        printf ("\nEs ist Freitag");
    }
    else if (wochentag == 6){
        printf ("\nEs ist Samstag");
    }

    return 0;
}