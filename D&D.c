#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int stmbestimmen(int st, int stm);
int gembestimmen(int ge, int gem);
int kombestimmen(int ko, int kom);
int rkbestimmen(int rk, int gem);
int kampf(int held[], int len);

enum attributname{STAERKE, GESCHICK, KONSTITUTION, STAERKEMOD, GESCHICKMOD, KONSTITUTIONMOD, LEBEN, RUESTUNG, VOLK, NAME};

int main(){
    srand (time(NULL));
    int wurf1, wurf2, wurf3, st, ge, ko, stm, gem, kom, tp, tpcopie, rk, volk, volkbonus, ini, aw, awm, waffe, i=0, play=1;
    char name[15];

//Auswahl des Volkes
    printf("Waehle ein Volk (jedes Volk hat eigene Vor und Nachteile)\n\n");
    printf("1) Zwerg\n");
    printf("2) Elf\n");
    printf("3) Mensch\n");
    printf("4) Halbling\n");
    printf("\nFuer was entscheiden Sie sich?: ");
    scanf("%d", &volk);

//Name des Charakters
    printf("\nWie ist der Name ihres Charakters: ");
    scanf("%14s", name);

//Generieren der Attribute
    wurf1 = rand()%6+1;
    wurf2 = rand()%6+1;
    wurf3 = rand()%6+1;
    st = wurf1+wurf2+wurf3;

    wurf1 = rand()%6+1;
    wurf2 = rand()%6+1;
    wurf3 = rand()%6+1;
    ge = wurf1+wurf2+wurf3;

    wurf1 = rand()%6+1;
    wurf2 = rand()%6+1;
    wurf3 = rand()%6+1;
    ko = wurf1+wurf2+wurf3;

//Rassenbonus der Attribute
    if(volk==1){
        ko = ko+2;
    }
    else if(volk==2){
        ge = ge+2;
        ko = ko-2;
    }
    else if (volk==4){
        ge = ge+2;
        st = st-2;
        rk = rk+1;
    }
    else if(volk==3){
        printf("\n\nAls Volkbonus kannst du einem beliebigen Attribut 2 Punkte zuweisen");
        printf("\n1) Staerke");
        printf("\n2) Geschicklichkeit");
        printf("\n3) Konstitution\n");
        scanf("%d", &volkbonus);
        if(volkbonus==1){
            st = st+2;
        }
        if(volkbonus==2){
            ge = ge+2;
        }
        if(volkbonus==3){
            ko = ko+2;
        }
    }

//Atrribut Modifikationen bestimmen
    ///Attribut-Modifikator Stärke
    stm = stmbestimmen(st, stm);

    ///Attribut-Modifikator Geschicklichkeit
    gem = gembestimmen(ge, gem);

    ///Attribut-Modifikator Konstitution
    kom = kombestimmen(ko, kom);

//TP bestimmen
    if(volk==1){
        tp = 10+kom;
        tpcopie = tp;
    }
    else if(volk==2){
        tp = 6+kom;
        tpcopie = tp;
    }
    else if(volk==3){
        tp = 8+kom;
        tpcopie = tp;
    }
    else if(volk==4){
        tp = 6+kom;
        tpcopie = tp;
    }

//Rüstunksklasse bestimmen
    rk = rkbestimmen(rk, gem);

//Ausgabe des Status
    printf("\n---Ihr Charakter wurde erstellt---\n");
    printf("\n>>>Personalien<<<");
    printf("\nNAME: %s", name);

    if(volk==1){
        printf("\nVOLK: ZWERG");
    }
    else if(volk==2){
        printf("\nVOLK: ELF");
    }
    else if(volk==3){
        printf("\nVOLK: MENSCH");
    }
    else if(volk==4){
        printf("\nVOLK: HALBLING");
    }
    printf("\n\n>>>Leben und Verteidigung<<<");
    printf("\nTREFFERPUNKTE: %d PUNKTE", tp);
    printf("\nRUESTUNGSKLASSE: %d", rk);

    printf("\n\n>>>Ihre Attribute<<<");
    printf("\nSTAERKE: %d PUNKTE", st);
    printf("\nGESCHICKLICHKEIT: %d PUNKTE", ge);
    printf("\nKONSTITUTION: %d PUNKTE\n", ko);

    printf("\n>>>Ihr Attribut-Modifikator<<<");
    printf("\nSTAERKE-MODIFIKATOR: %d", stm);
    printf("\nGESCHICKLICHKEIT-MODIFIKATOR: %d", gem);
    printf("\nKONSTITUTION-MODIFIKATOR: %d\n", kom);

//Kampfsystem
    while(play==1){
        while(i<5){
            printf("\n\n------>>>>>>    Der %d. Kampf beginnt   <<<<<<------", i+1);
            tp = tpcopie;
            int held[11] = {st, ge, ko, stm, gem, kom, tp, rk, volk, name};
            kampf(held, 11);
            i++;
            printf("\n\n\n------>>>>>>      Das war %d. erste Kampf     <<<<<<------\n\n", i);
            if(i<5){
                printf("Druecken Sie eine Taste zum weiterspielen");
                getchar();
            }
        }
        printf("\n\nDruecken Sie 1 um nochmal zu spielen oder 2 zum Verlassen\n\n");
        scanf("%d", &play);
        if(play==1){
            i = 0;
        }
    }
    if(play==2){
        printf("\n\n<<<     Sie moechten das Spiel verlassen?    >>>\n\n");
        printf("Bestaetigen Sie mit Enter\n\n");
        getchar();
    }
}







int stmbestimmen(int st, int stm){

    if(st<2){
        stm = -5;
    }
    else if(st<4){
        stm = -4;
    }
    else if(st<6){
        stm = -3;
    }
    else if(st<8){
        stm = -2;
    }
    else if(st<10){
        stm = -1;
    }
    else if(st<12){
        stm = 0;
    }
    else if(st<14){
        stm = 1;
    }
    else if(st<16){
        stm = 2;
    }
    else if(st<18){
        stm = 3;
    }
    else if(st<20){
        stm = 4;
    }

    return (stm);
}



int gembestimmen(int ge, int gem){

    if(ge<2){
        gem = -5;
    }
    else if(ge<4){
        gem = -4;
    }
    else if(ge<6){
        gem = -3;
    }
    else if(ge<8){
        gem = -2;
    }
    else if(ge<10){
        gem = -1;
    }
    else if(ge<12){
        gem = 0;
    }
    else if(ge<14){
        gem = 1;
    }
    else if(ge<16){
        gem = 2;
    }
    else if(ge<18){
        gem = 3;
    }
    else if(ge<20){
        gem = 4;
    }

    return (gem);
}



int kombestimmen(int ko, int kom){
    if(ko<2){
        kom = -5;
    }
    else if(ko<4){
        kom = -4;
    }
    else if(ko<6){
        kom = -3;
    }
    else if(ko<8){
        kom = -2;
    }
    else if(ko<10){
        kom = -1;
    }
    else if(ko<12){
        kom = 0;
    }
    else if(ko<14){
        kom = 1;
    }
    else if(ko<16){
        kom = 2;
    }
    else if(ko<18){
        kom = 3;
    }
    else if(ko<20){
        kom = 4;
    }

    return (kom);
}



int rkbestimmen(int rk, int gem){
    rk = 10+gem;
    return (rk);
}



int kampf(int held[], int len){
//Gegner erstellen
    int iniU=3, rkU=10, tpU=16, awmU=1, awU;
    char nameW[] = "Untoter";
    int Untoter[5] = {iniU,rkU, tpU, awmU, awU};

//Kampf
    int ini, angriffswurf, s;
    ini = held[GESCHICKMOD]+rand()%20+1;
    iniU = iniU+3;

    if(ini<iniU){
        awU = awmU+rand()%6+1;
        held[LEBEN] = held[LEBEN]-awU;
        if(held[LEBEN]>0){
            printf("\n\nDer Untote trifft als erstes");
            printf("\n\nDu bekommst %d Schaden und hast noch %d TP", awU, held[LEBEN]);
        }
        else if(held[LEBEN]<=0){
            printf("\n\nDer Untote hat einen kritischen treffer gelandet");
            held[LEBEN]=1;
            printf("\n\nDu hast mit %d Trefferpunkt ueberlebt", held[LEBEN]);
        }
        while(tpU>0 || held[LEBEN]>0){
                angriffswurf = held[STAERKEMOD]+rand()%20+1;
                tpU = tpU-angriffswurf;
                printf("\n\nDruecke eine Taste zum angreifen");
                getchar();
                getchar();
                printf("\n\nDer Untote bekommt %d Schaden und hat noch %d TP", angriffswurf, tpU);
                if(tpU<=0){
                    printf("\n\nDu hast den Untoten besiegt");
                    break;
                }
                awU = 1+rand()%6+1;
                held[LEBEN] = held[LEBEN]-awU;
                printf("\n\nDu bekommst %d Schaden und hast noch %d TP", awU, held[LEBEN]);
                if(held[LEBEN]<=0){
                    printf("\n\nDer Untote hat dich besiegt");
                    break;
                }
        }
    }
    else{
        angriffswurf = held[STAERKEMOD]+rand()%20+1;
        tpU = tpU-angriffswurf;
        if(tpU>0){
            printf("\n\nDruecke eine Taste zum angreifen");
            getchar();
            getchar();
            printf("\n\nDer Untote bekommt %d Schaden und hat noch %d TP", angriffswurf, tpU);
        }
        else if(tpU<=0){
            printf("\n\nDruecke eine Taste zum angreifen");
            getchar();
            getchar();
            printf("\n\nDu hast einen kritischen Treffer gelandet");
            tpU = 1;
            printf("\n\nDer Untote hat mit %d Trefferpunkt ueberlebt", tpU);
        }
        while(tpU>0 || held[LEBEN]>0){
                awU = 1+rand()%6+1;
                held[LEBEN] = held[LEBEN]-awU;
                printf("\n\nDu bekommst %d Schaden und hast noch %d TP", awU, held[LEBEN]);
                if(held[LEBEN]<=0){
                    printf("\n\nDer Untote hat dich besiegt");
                    break;
                }
                angriffswurf = held[STAERKEMOD]+rand()%20+1;
                tpU = tpU-angriffswurf;
                printf("\n\nDruecke eine Taste zum angreifen");
                getchar();
                printf("\n\nDer Untote bekommt %d Schaden und hat noch %d TP", angriffswurf, tpU);
                if(tpU<=0){
                    printf("\n\nDu hast den Untoten besiegt");
                    break;
                }
        }
    }
}