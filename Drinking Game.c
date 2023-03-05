#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int wuerfeln(int zahl);

int main(){
    srand(time(NULL));
    int zahl, anzahlSpieler, stop=0, game, start, spieler1, spieler2, wurf1=1, wurf2=2, wurf3, wurf4, wurf5, versuche1=0, versuche2=0, versuche3, versuche4, versuche5, i, k=1;


///Die Regeln des Trinkspiels
    printf("-----Willkommen zum Wuerfel Trinkspiel-----\n\n");
    printf ("Hier die Regeln:\n");
    printf ("1) Wird eine eins gewuerfelt, so muss der, der als letzes 'ERSTER' ruft trinken.\n\n");
    printf ("2) Wird eine zwei gewuerfelt, so bestimmt der, der gewuerfelt hat zwei Spieler, welche gegeneinander wuerfeln.\n");
    printf ("   Es wird 3 mal gewuerfelt und die Augenzahlen addiert, wer am wenigsten hat muss trinken.\n\n");
    printf ("3) Wird eine drei gewuerfelt, muessen der Wuerfler und der Spieler links neben ihm solange mit 2 Wuerfeln wuerfeln,\n");
    printf ("   bis einer einen Pasch erzielt. Der andere muss dann trinken.\n\n");
    printf ("4) Wird eine vier gewuerfelt, wuerfelt jeder solange bis er eine 4 gewuerfelt hat, der der überig bleibt muss trinken.\n\n");
    printf ("5) Schwein gehabt, niemand muss trinken.\n\n");
    printf ("6) Wird eine 6 gewuerfelt, steigt der Wuerfler zum Wuerfel-Graf auf. Das bedeutet, jeder bekommt ein Glass und wuerfelt\n");
    printf ("   gegen den Wuerfel-Graf. Die hoehere Zahl gewinnt, aber Vorsicht Graf, evtl. musst du alles trinken!!!\n\n");

    while (stop==0){
        printf("Druecke eine Taste zum wuerfeln.\n\n");
        getchar();
        game = wuerfeln(zahl);
    ///Spiel Nummer 1
        if(game==1){
            printf("----SPIEL NUMMER 1----\n\n");
            printf ("Du haste eine 1 gewuerfelt. ERSTER!!!\n\n");
        }
    ///Spiel Nummer 2
        else if(game==2){
            printf("----SPIEL NUMMER 2----\n\n");
            printf("Du hast eine 2 gewuerfelt. Waehle einen weiteren Spieler um gegen ihr zu wuerfeln.\n\n");
            printf("Druecke eine Taste zum wuerfeln.");
            getchar();

        //Spieler 1 würfelt 3 mal
            wurf1 = wuerfeln(zahl);
            wurf2 = wuerfeln(zahl);
            wurf3 = wuerfeln(zahl);
            spieler1 = wurf1+wurf2+wurf3;
            printf("\n\nWurf 1: %d\n", wurf1);
            printf("Wurf 2: %d\n", wurf2);
            printf("Wurf 3: %d\n", wurf3);
            printf("Summe: %d", spieler1);

            printf("\n\nDruecke eine Taste zum wuerfeln.");
            getchar();

        //Spieler 2 würfelt 3 mal
            wurf1 = wuerfeln(zahl);
            wurf2 = wuerfeln(zahl);
            wurf3 = wuerfeln(zahl);
            spieler2 = wurf1+wurf2+wurf3;
            printf("\n\nWurf 1: %d\n", wurf1);
            printf("Wurf 2: %d\n", wurf2);
            printf("Wurf 3: %d\n", wurf3);
            printf("Summe: %d\n\n", spieler2);

        //Auswertung der Würfe
            if(spieler1>spieler2){
                printf("--->>>      Spieler 1 hat gewonnen      <<<---\n\n");
            }
            else if(spieler2>spieler1){
                printf("--->>>      Spieler 2 hat gewonnen    <<<---\n\n");
            }
            else if(spieler1==spieler2){
                printf("Ihr habt beide Verloren, also trinkt gemeinsam.\n\n");
            }
        }
    ///Spiel Nummer 3
        else if(game==3){
            printf("----SPIEL NUMMER 3----\n\n");
            printf("Nun wird gewuerfelt bis einer einen Pasch wuerfelt\n\n");
            printf("Druecke eine Taste zum wuerfeln.\n");
            getchar();

        //Würfe Spieler 1
            while (wurf1!=wurf2){
                wurf1 = wuerfeln(zahl);
                wurf2 = wuerfeln(zahl);
                printf("Spieler 1 hat eine %d und eine %d gewuerfelt\n\n", wurf1, wurf2);
                versuche1++;
                if(wurf1==wurf2){
                    printf("Spieler 1 hat %d Versuche gebraucht\n\n", versuche1);
                }

        //Würfe Spieler 2
                printf("Druecke eine Taste zum wuerfeln.\n");
                getchar();
                wurf1 = wuerfeln(zahl);
                wurf2 = wuerfeln(zahl);
                printf("Spieler 2 hat eine %d und eine %d gewuerfelt\n\n", wurf1, wurf2);
                versuche2++;

        //Auswertung der Würfe
                if(wurf1==wurf2){
                    printf("Spieler 2 hat %d Versuche gebraucht\n\n", versuche2);
                }
                if(versuche1<versuche2){
                    printf("--->>>      Spieler 1 hat gewonnen      <<<---\n\n");
                }
                if(versuche2<versuche1){
                    printf("--->>>      Spieler 2 hat gewonnen      <<<---\n\n");
                }
            }
        }
    ///Spiel Nummer 4
        else if(game==4){
            printf("----SPIEL NUMMER 4----\n\n");
            printf("Nun wuerfelt jeder so lange bis jeder eine 4 gewuerfelt hat. Der letze muss trinken.\n\n");
        //Anzahl der Spieler 2
            if(anzahlSpieler==2){
                while(wurf1!=4){
                printf("Druecke eine Taste zum wuerfeln.\n\n");
                getchar();
                wurf1 = wuerfeln(zahl);
                printf("Du hast eine %d gewuerfelt\n\n", wurf1);
                versuche1++;
                }
                printf("Spieler 1 hat %d Versuche gebraucht\n\n", versuche1);

                while(wurf1!=4){
                printf("Druecke eine Taste zum wuerfeln.\n\n");
                getchar();
                wurf2 = wuerfeln(zahl);
                printf("Du hast eine %d gewuerfelt\n\n", wurf2);
                versuche2++;
                }
                printf("Spieler 2 hat %d Versuche gebraucht\n\n", versuche2);

                if(versuche1<versuche2){
                    printf("--->>>      Spieler 1 hat gewonnen      <<<---\n\n");
                }
                else if(versuche2<versuche1){
                    printf("--->>>      Spieler 2 hat gewonnen      <<<---\n\n");
                }
            }
        //Anzahl der Spieler 3
            else if(anzahlSpieler==3){
                while(wurf1!=4){
                printf("Druecke eine Taste zum wuerfeln.\n\n");
                getchar();
                wurf1 = wuerfeln(zahl);
                printf("Du hast eine %d gewuerfelt", wurf1);
                versuche1++;
                }
                while(wurf1!=4){
                printf("Druecke eine Taste zum wuerfeln.\n\n");
                getchar();
                wurf2 = wuerfeln(zahl);
                printf("Du hast eine %d gewuerfelt", wurf2);
                versuche2++;
                }
                while(wurf1!=4){
                printf("Druecke eine Taste zum wuerfeln.\n\n");
                getchar();
                wurf3 = wuerfeln(zahl);
                printf("Du hast eine %d gewuerfelt", wurf3);
                versuche3++;
                }
            }
        //Anzahl der Spieler 4
            else if(anzahlSpieler==4){
                while(wurf1!=4){
                printf("Druecke eine Taste zum wuerfeln.\n\n");
                getchar();
                wurf1 = wuerfeln(zahl);
                printf("Du hast eine %d gewuerfelt", wurf1);
                versuche1++;
                }
                while(wurf1!=4){
                printf("Druecke eine Taste zum wuerfeln.\n\n");
                getchar();
                wurf2 = wuerfeln(zahl);
                printf("Du hast eine %d gewuerfelt", wurf2);
                versuche2++;
                }
                while(wurf1!=4){
                printf("Druecke eine Taste zum wuerfeln.\n\n");
                getchar();
                wurf3 = wuerfeln(zahl);
                printf("Du hast eine %d gewuerfelt", wurf3);
                versuche3++;
                }
                while(wurf1!=4){
                printf("Druecke eine Taste zum wuerfeln.\n\n");
                getchar();
                wurf4 = wuerfeln(zahl);
                printf("Du hast eine %d gewuerfelt", wurf4);
                versuche4++;
                }
            }
        //Anzahl der Spieler 5
            else if(anzahlSpieler==5){
                while(wurf1!=4){
                printf("Druecke eine Taste zum wuerfeln.\n\n");
                getchar();
                wurf1 = wuerfeln(zahl);
                printf("Du hast eine %d gewuerfelt", wurf1);
                versuche1++;
                }
                while(wurf1!=4){
                printf("Druecke eine Taste zum wuerfeln.\n\n");
                getchar();
                wurf2 = wuerfeln(zahl);
                printf("Du hast eine %d gewuerfelt", wurf2);
                versuche2++;
                }
                while(wurf1!=4){
                printf("Druecke eine Taste zum wuerfeln.\n\n");
                getchar();
                wurf3 = wuerfeln(zahl);
                printf("Du hast eine %d gewuerfelt", wurf3);
                versuche3++;
                }
                while(wurf1!=4){
                printf("Druecke eine Taste zum wuerfeln.\n\n");
                getchar();
                wurf4 = wuerfeln(zahl);
                printf("Du hast eine %d gewuerfelt", wurf4);
                versuche4++;
                }
                while(wurf1!=4){
                printf("Druecke eine Taste zum wuerfeln.\n\n");
                getchar();
                wurf5 = wuerfeln(zahl);
                printf("Du hast eine %d gewuerfelt", wurf5);
                versuche5++;
                }
            }
            else if(anzahlSpieler>5){
                printf("Ihr seid zu viele Spieler, redet mit CC :D");
            }
        }
    ///Spiel Nummer 5
        else if(game==5){
            printf("---->>>>    Die 5 ist wohl eure Glueckszahl     <<<<----\n\n");
            getchar();
        }
    ///Spiel Nummer 6
        else if(game==6){
            printf("----SPIEL NUMMER 6----\n\n");
            printf("Der Wuerfel-Graf muss einmal gegen jeden wuerfeln. Die hoehere Zahl gewinnt.\n\n");
            for(i=1; i<anzahlSpieler; i++){
                printf("Der Wuerfel-Graf wuerfelt gegen Spieler %d\n\n", i);
                printf("Der Wuerfel-Graf beginnt\n");
                printf("Druecke Enter zum wuerfeln\n\n");
                getchar();
                wurf1 = rand()%6+1;
                printf("Der Wuerfel- Graf hat eine %d gewuerfelt\n\n", wurf1);
                printf("Spieler %d ist an der Reihe\n", i);
                printf("Druecke Enter zum wuerfeln\n\n");
                getchar();
                wurf2 = rand()%6+1;
                printf("Spieler %d hat eine %d gewuerfelt\n\n", i, wurf2);
                if(wurf1>wurf2){
                    printf("Der Wuerfel-Graf hat gewonnen\n");
                    printf("Trink Spieler %d\n\n", i);
                }
                else if(wurf1<wurf2){
                    printf("Spieler %d hat gewonnen\n\n",i);
                    printf("Der Wuerfel-Graf muss trinken\n\n");
                }
            }
        }
    }
}

///Unterprogramm zum Würfeln
int wuerfeln(int zahl){
    zahl = rand()%6+1;
    return (zahl);
}