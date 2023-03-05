float berechne (float groesse, float gewicht);

int main(){
    float groesse;
    float gewicht;
    float bmi = 0;

    printf ("Bitte geben Sie ihre Groesse ein: ");
    scanf ("%f", &groesse);
    printf ("\nBitte geben Sie ihr Gewicht ein: ");
    scanf ("%f", &gewicht);

    bmi = berechne (groesse, gewicht);

    printf ("\nIhr BMI beträgt: %f", bmi);
}



float berechne (float groesse, float gewicht){
    float bmi;
    bmi = gewicht / (groesse*groesse);
    return bmi;
}