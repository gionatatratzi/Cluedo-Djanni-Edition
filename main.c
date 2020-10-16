//**********************************************
//**********************************************
//    progetto finale programmazione 1
//
//          anno academico 2017/2018
//
//          CLUEDO DJANNI EDITION
//
//          Tratzi Gionata
//
//           60/61/65246
//**********************************************
//**********************************************
#include "struttureListe.h"
#include "subroutineListe.h"
#include "gestioneStanza.h"
#include "gestioneIpotesi.h"
#include "salvataggioCaricamento.h"
#include "gestioneCluedo.h"

int main(int argc, char *argv[]){
    int h, i;//variabili indice
    char scelta;//variabile
    int vectorStanzaIniziale[NOVE]={0};//vettore d'appoggio settato a zero

    srand(time(NULL));//seme di randomizzazione

    //record della struttura carta stanza
    CarteGioco carteRecordStanza[NOVE]={{0, STANZA, "LABORATORIO T"},{1, STANZA, "LABORATORIO M"}, {2, STANZA, "BAGNO"},
                                        {3, STANZA, "AULA COSTA"}, {4, STANZA, "GIARDINO"}, {5, STANZA, "ENTRATA"},
                                        {6, STANZA, "PARCHEGGIO"}, {7, STANZA, "SIMAZ"}, {8, STANZA, "BATCAVERNA"}};
    //record della struttura carta arma
    CarteGioco carteRecordArma[SEI]={{9, ARMA, "CAVO DI RETE"},{10, ARMA, "SPARACORIANDOLI"}, {11, ARMA, "CALCINACCIO"},
                                        {12, ARMA, "TASTIERA USB"}, {13, ARMA, "FUMO CALDAIA"}, {14, ARMA, "FLOPPY DISK 3.5"}};
    //record della struttura carta sospetto
    CarteGioco carteRecordSospetto[SEI]={{15, SOSPETTO, "ALAN TURING"},{16, SOSPETTO, "G.M. HOPPER"}, {17, SOSPETTO, "EDSGER DIJKSTRA"},
                                        {18, SOSPETTO, "G.F.VORONOJ"}, {19, SOSPETTO, "J.V.NEUMANN"}, {20, SOSPETTO, "M.HAMILTON"}};

    //MENU' INTRODUTTIVO
    printf("******************************************************************\n\n");
    printf("         CCC     L        U  U     EEEE     DDD       OO  \n");
    printf("        C        L        U  U     E        D  D     O  O \n");
    printf("        C        L        U  U     EEE      D  D     O  O \n");
    printf("        C        L        U  U     E        D  D     O  O \n");
    printf("         CCC     LLLL      UU      EEEE     DDD       OO  \n\n");
    printf("                      DJANNI  EDITION\n\n");
    printf("******************************************************************\n\n");

    do{
        printf("\n\tMENU' PRINCIPALE");
        printf("\nNuova partita.........'n'");
        printf("\nCarica partita........'c'");
        printf("\nIstruzioni............'i'");
        printf("\nEsci..................'x'\n");
        scanf("%c", &scelta);
        getchar();

        switch(scelta){
            case 'n':
            case 'N':
                Flag.caricaPartita=false;//flag caricamento partita false

                printf("\n\nNUOVA PARTITA\n");
                do{
                    printf("\nInserire il numero dei giocatori\nda 3 a 6\n");
                    scanf("%d", &Flag.numeroGiocatori);
                    getchar();

                    if(!((Flag.numeroGiocatori>=TRE)&&(Flag.numeroGiocatori<=SEI))){
                        printf("\nERRORE numero inserito non valido\nripeti\n");
                    }
                }while(!((Flag.numeroGiocatori>=TRE)&&(Flag.numeroGiocatori<=SEI)));//cicla se il numero inserito non è valido

                Utente=(GestioneGiocatori*)malloc(Flag.numeroGiocatori*sizeof(GestioneGiocatori));//allocazione dinamica struttura utenti giocatori
                if(Utente==NULL) exit(-1);//verifica allocazione dinamica

                if((Flag.numeroGiocatori>=3)&&(Flag.numeroGiocatori<=6)){
                    printf("\nINSERIRE I NOMI DEI GIOCATORI\n");
                    printf("Giocatore 1: ");
                    scanf("%[^\n]MAX_STRs", Utente->nomeGiocatore[UTENTE1]);
                    getchar();
                    printf("Giocatore 2: ");
                    scanf("%[^\n]MAX_STRs", Utente->nomeGiocatore[UTENTE2]);
                    getchar();
                    printf("Giocatore 3: ");
                    scanf("%[^\n]MAX_STRs", Utente->nomeGiocatore[UTENTE3]);
                    getchar();
                }
                if((Flag.numeroGiocatori>=4)&&(Flag.numeroGiocatori<=6)){
                    printf("Giocatore 4: ");
                    scanf("%[^\n]MAX_STRs", Utente->nomeGiocatore[UTENTE4]);
                    getchar();
                }
                if((Flag.numeroGiocatori==5)||(Flag.numeroGiocatori==6)){
                    printf("Giocatore 5: ");
                    scanf("%[^\n]MAX_STRs", Utente->nomeGiocatore[UTENTE5]);
                    getchar();
                }
                if(Flag.numeroGiocatori==6){
                    printf("Giocatore 6: ");
                    scanf("%[^\n]MAX_STRs", Utente->nomeGiocatore[UTENTE6]);
                    getchar();
                }
                //ASSEGNAMENTO DA RECORD A LISTA
                #if DEBUG_MODE_ASSEGNAMENTO==1
                    printf("Assegnamento lista\n");
                    printf("Stanza\n");
                #endif // DEBUG_MODE_ASSEGNAMENTO
                Flag.counter=0;//flag settato a zero
                listaStanza=allocazioneStanza(carteRecordStanza, listaStanza);//subroutine allocazione stanza

                //allocazione dinamica carte da gioco assegnate
                #if DEBUG_MODE_ASSEGNAMENTO==1
                    printf("Arma\n");
                #endif // DEBUG_MODE_ASSEGNAMENTO
                Flag.counter=0;//flag settato a zero
                listaArma=allocazioneArma(carteRecordArma, listaArma);//subroutine allocazione arma

                #if DEBUG_MODE_ASSEGNAMENTO==1
                    printf("Sospetto\n");
                #endif // DEBUG_MODE_ASSEGNAMENTO
                Flag.counter=0;//flag settato a zero
                listaSospetto=allocazioneSospetto(carteRecordSospetto, listaSospetto);//subroutine allocazione sospetto

                //MESCOLAMENTO LISTE
                #if DEBUG_MODE_MESCOLAMENTO==1
                    printf("\nMescolamento carte lista\n");
                    printf("Stanza\n");
                #endif // DEBUG_MODE_MESCOLAMENTO
                listaStanza=mescolamentoCarteStanza(listaStanza);//subroutine mescolamento stanza

                #if DEBUG_MODE_MESCOLAMENTO==1
                    printf("Arma\n");
                #endif // DEBUG_MODE_MESCOLAMENTO
                listaArma=mescolamentoCarteArma(listaArma);//subroutine mescolamento arma

                #if DEBUG_MODE_MESCOLAMENTO==1
                    printf("Sospetto\n");
                #endif // DEBUG_MODE_MESCOLAMENTO
                listaSospetto=mescolamentoCarteSospetto(listaSospetto);//subroutine mescolamento sospetto

                //MESCOLAMENTO 2
                //allocazione dinamica carte mescolate e poste in un unico mazzo
                #if DEBUG_MODE_ASSEGNAMENTO2==1
                    printf("\n\nAllocazioneMescolate");
                #endif // DEBUG_MODE_ASSEGNAMENTO
                Flag.counter=0;//flag settato a zero
                listaMescolate=allocazioneMescolateStanza(listaMescolate);
                Flag.counter=MIN_ARMA;//flag settato a zero
                listaMescolate=allocazioneMescolateArma(listaMescolate);
                Flag.counter=MIN_SOSPETTO;//flag settato a zero
                listaMescolate=allocazioneMescolateSospetto(listaMescolate);

                #if DEBUG_MODE_MESCOLAMENTO2==1
                    printf("\n\nMescolamento finale");
                #endif // DEBUG_MODE_MESCOLAMENTO2
                listaMescolate=mescolateFinale(listaMescolate);

                break;
            case 'c':
            case 'C':
                printf("\n\nCARICAMENTO PARTITA\n");

                for(h=0; h<Flag.numeroGiocatori; h++){
                    Utente->ipotesiCorretta[h]=false;//settare a false ipotesi corretta dei giocatori
                }
                caricamentoPartita();
                Flag.caricaPartita=true;//flag caricamento partita true

                Utente=(GestioneGiocatori*)malloc(Flag.numeroGiocatori*sizeof(GestioneGiocatori));//allocazione dinamica struttura utenti giocatori
                if(Utente==NULL) exit(-1);//verifica allocazione dinamica

                break;
            case 'i':
            case 'I':
                printf("\n\nISTRUZIONI\n");
                printf("\nIl gioco è ambientato nei locali del Palazzo delle Scienze\n");
                printf("e lo scopo dei giocatori (numero scelto dall’utente da 3 a 6)\n");
                printf("è indagare sulla misteriosa uccisione del famoso gatto Djanni.\n");
                printf("I principali sospetti sono stati fermati e identificati,\n");
                printf("anche le possibili armi del delitto sono state catalogate e depositate.\n");
                printf("I vari giocatori durante il gioco dovranno formulare le ipotesi del delitto del tipo:\n");
                printf("il sospettato ha ucciso Djanni nella stanza con l’arma e gli altri giocatori\n");
                printf("confuteranno o confermeranno tale ipotesi.\n");
                printf("Vince il giocatore che per primo indovinerà la tripla: sospetto, stanza e arma.\n");
                break;
            case 'x':
            case 'X':
                printf("\n\nGAME OVER\n");
                exit(-1);
                break;
            default:
                printf("\n\nERRORE!\nCARATTERE INSERITO NON VALIDO\n");
                break;
        }
    }while(!((scelta=='n')||(scelta=='N')||(scelta=='c')||(scelta=='C')));

    //LISTA INCOGNITA
    //allocazione dinamica carte incognita
    listaIncognita=(ListaCarteIncognita*)malloc(sizeof(ListaCarteIncognita));
    listaIncognita->next=(ListaCarteIncognita*)malloc(sizeof(ListaCarteIncognita));
    listaIncognita->next->next=(ListaCarteIncognita*)malloc(sizeof(ListaCarteIncognita));

    if(listaIncognita==NULL) exit(-1);//verifica se l'allocazione è andata a buon fine
    if(listaIncognita->next==NULL) exit(-1);//verifica se l'allocazione è andata a buon fine
    if(listaIncognita->next->next==NULL) exit(-1);//verifica se l'allocazione è andata a buon fine

    //assegnamento 3 carte incognita su lista incognita
    listaIncognita->Id=Flag.vettoreAppoggio1[MIN_STANZA];
    listaIncognita->next->Id=Flag.vettoreAppoggio1[MIN_ARMA];
    listaIncognita->next->next->Id=Flag.vettoreAppoggio1[MIN_SOSPETTO];

    Flag.vettoreCarteIncognita[0]=Flag.vettoreAppoggio1[MIN_STANZA];
    Flag.vettoreCarteIncognita[1]=Flag.vettoreAppoggio1[MIN_ARMA];
    Flag.vettoreCarteIncognita[2]=Flag.vettoreAppoggio1[MIN_SOSPETTO];

    #if DEBUG_MODE_INCOGNITA==1
        printf("\nCarte incognita");
        printf("\nn: 1\tId: %d\tStr: %s", listaIncognita->Id, carteRecordStanza[listaIncognita->Id].stringaCarte);
        printf("\nn: 2\tId: %d\tStr: %s", listaIncognita->next->Id, carteRecordArma[listaIncognita->next->Id-MIN_ARMA].stringaCarte);
        printf("\nn: 3\tId: %d\tStr: %s", listaIncognita->next->next->Id, carteRecordSospetto[listaIncognita->next->next->Id-MIN_SOSPETTO].stringaCarte);
    #endif // DEBUG_MODE_INCOGNITA

    Flag.quoziente=DICIOTTO/Flag.numeroGiocatori;//calcolo numero carte a giocatore
    Flag.resto=DICIOTTO%Flag.numeroGiocatori;//calcolo carte rimaste

    #if DEBUG_MODE_GIOCATORI==1
        printf("\n\nCarte assegnate ai giocatori");
    #endif // DEBUG_MODE_GIOCATORI

    if((Flag.numeroGiocatori>=3)&&(Flag.numeroGiocatori<=6)){
        #if DEBUG_MODE_GIOCATORI==1
            printf("\nGiocatore 1");
        #endif // DEBUG_MODE_GIOCATORI
        Flag.counter=0;//flag contatore settato a zero
        listaGiocatore1=mazzoGiocatore1(Flag.quoziente, listaGiocatore1);

        #if DEBUG_MODE_GIOCATORI==1
            printf("\nGiocatore 2");
        #endif // DEBUG_MODE_GIOCATORI
        Flag.counter=0;//flag contatore settato a zero
        listaGiocatore2=mazzoGiocatore2(Flag.quoziente, listaGiocatore2);

        #if DEBUG_MODE_GIOCATORI==1
            printf("\nGiocatore 3");
        #endif // DEBUG_MODE_GIOCATORI
        Flag.counter=0;//flag contatore settato a zero
        listaGiocatore3=mazzoGiocatore3(Flag.quoziente, listaGiocatore3);
    }
    if((Flag.numeroGiocatori>=4)&&(Flag.numeroGiocatori<=6)){
        #if DEBUG_MODE_GIOCATORI==1
            printf("\nGiocatore 4");
        #endif // DEBUG_MODE_GIOCATORI
        Flag.counter=0;//flag contatore settato a zero
        listaGiocatore4=mazzoGiocatore4(Flag.quoziente, listaGiocatore4);
    }
    if((Flag.numeroGiocatori==5)||(Flag.numeroGiocatori==6)){
        #if DEBUG_MODE_GIOCATORI==1
            printf("\nGiocatore 5");
        #endif // DEBUG_MODE_GIOCATORI
        Flag.counter=0;//flag contatore settato a zero
        listaGiocatore5=mazzoGiocatore5(Flag.quoziente, listaGiocatore5);
    }
    if(Flag.numeroGiocatori==6){
        #if DEBUG_MODE_GIOCATORI==1
            printf("\nGiocatore 6");
        #endif // DEBUG_MODE_GIOCATORI
        Flag.counter=0;//flag contatore settato a zero
        listaGiocatore6=mazzoGiocatore6(Flag.quoziente, listaGiocatore6);
    }
    printf("\n\nCarte rimaste sul tavolo dai giocatori");

    if(Flag.resto==0){//controllo se resto e' uguale a zero
        printf("\n0\n");
    }else{//altrimenti se il resto e' diverso da zero memorizza in carte rimaste
        for(h=Flag.quoziente*Flag.numeroGiocatori; h<Flag.resto+Flag.quoziente*Flag.numeroGiocatori; h++){
            if((Flag.vettoreAppoggio2[h]>=MIN_STANZA)&&(Flag.vettoreAppoggio2[h]<=MAX_STANZA)){
                printf("\nn: %d\tId: %d\tStr: %s", h+1, Flag.vettoreAppoggio2[h], carteRecordStanza[Flag.vettoreAppoggio2[h]].stringaCarte);
                Flag.vettoreCarteRimaste[h]=Flag.vettoreAppoggio2[h];

            }else if((Flag.vettoreAppoggio2[h]>=MIN_ARMA)&&(Flag.vettoreAppoggio2[h]<=MAX_ARMA)){
                printf("\nn: %d\tId: %d\tStr: %s", h+1, Flag.vettoreAppoggio2[h], carteRecordArma[Flag.vettoreAppoggio2[h]].stringaCarte);
                Flag.vettoreCarteRimaste[h]=Flag.vettoreAppoggio2[h];

            }else if((Flag.vettoreAppoggio2[h]>=MIN_SOSPETTO)&&(Flag.vettoreAppoggio2[h]<=MAX_SOSPETTO)){
                printf("\nn: %d\tId: %d\tStr: %s", h+1, Flag.vettoreAppoggio2[h], carteRecordSospetto[Flag.vettoreAppoggio2[h]].stringaCarte);
                Flag.vettoreCarteRimaste[h]=Flag.vettoreAppoggio2[h];
            }
        }
    }
    if(Flag.caricaPartita==false){//non sto caricando la partita
        //generazione stanza iniziale
        #if DEBUG_MODE_GIOCATORI==1
            printf("\n\nStanza iniziale\n");
        #endif // DEBUG_MODE_GIOCATORI

        for(h=1; h<=Flag.numeroGiocatori; h++){//cicla per h da 1 a 9 incluso
            do{
                Flag.random=MIN+rand()%(MAX_OTTO-MIN+1);//generazione casuale
            }while(vectorStanzaIniziale[Flag.random]!=0);//cicla sinchè il vettore non è pieno

            vectorStanzaIniziale[Flag.random]=h;//il vettore prende il valore di h
            Utente->stanzaGiocatore[h-1]=Flag.random;//assegnamento valore random

            #if DEBUG_MODE_GIOCATORI==1
                printf("Giocatore: Id: %d\t%s\tStanza: %s\n", Flag.random, Utente->nomeGiocatore[h-1], carteRecordStanza[Flag.random].stringaCarte);
            #endif // DEBUG_MODE_GIOCATORI
        }
        //generazione stanza iniziale
        #if DEBUG_MODE_GIOCATORI==1
            printf("\n\nTurno iniziale\n");
        #endif // DEBUG_MODE_GIOCATORI
        Flag.random=MIN+rand()%(Flag.numeroGiocatori-UNO-MIN+1);//generazione casuale
        Utente->turnoIniziale=Flag.random;//assegnamento valore random
        Utente->numeroTurni=0;//setto a zero il numero turni

        for(h=0; h<Flag.numeroGiocatori; h++){
            Utente->ipotesiCorretta[h]=false;//settare a false ipotesi corretta dei giocatori
        }
    }
    Flag.giocatoreVinto=false;//setto a false il flag della vittoria

    if(Flag.caricaPartita==true){//sto caricando la partita
        Utente->turnoIniziale=Utente->giocatoreCorrente;//sovrascrivo turno iniziale con giocatore corrente
    }
    #if DEBUG_MODE_GIOCATORI==1
        printf("Giocatore: %s inizia il gioco\n", Utente->nomeGiocatore[Utente->turnoIniziale]);
    #endif // DEBUG_MODE_GIOCATORI

    //INIZIO GIOCO
    do{
        for(h=Utente->turnoIniziale; h<(Flag.numeroGiocatori+Utente->turnoIniziale); h++){//ciclo che stabilisce il turno dei giocatori
            if(h<Flag.numeroGiocatori){
                Utente->giocatoreCorrente=h;
            }else{
                for(i=0; i<SEI; i++){
                     if(h==Flag.numeroGiocatori+i) Utente->giocatoreCorrente=i;
                }
            }
            //SUBROUTINE GIOCO CLUEDO
            subroutineCluedo(carteRecordStanza, carteRecordArma, carteRecordSospetto);
            Utente->numeroTurni=Utente->numeroTurni+1;//incremento numero turni
        }
    }while(Flag.giocatoreVinto==false);

    return 0;//fine del programma
}

