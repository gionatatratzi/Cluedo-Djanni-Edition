#ifndef GESTIONECLUEDO_H_INCLUDED
#define GESTIONECLUEDO_H_INCLUDED

void dealloca(void){
    free(listaGiocatore1);//de-allocazione lista giocatore 1
    free(listaGiocatore2);//de-allocazione lista giocatore 2
    free(listaGiocatore3);//de-allocazione lista giocatore 3
    free(listaGiocatore4);//de-allocazione lista giocatore 4
    free(listaGiocatore5);//de-allocazione lista giocatore 5
    free(listaGiocatore6);//de-allocazione lista giocatore 6
    free(listaArma);//de-allocazione lista arma
    free(listaSospetto);//de-allocazione lista sospetto
    free(listaStanza);//de-allocazione lista stanza
    free(listaIncognita);//de-allocazione lista incognita
    free(listaMescolate);//de-allocazione lista carte mescolate
    free(Utente);//de-allocazione struttura utente
}
void subroutineCluedo(CarteGioco carteRecordStanza[NOVE], CarteGioco carteRecordArma[SEI], CarteGioco carteRecordSospetto[SEI]){
    char scelta;//scelta opzione
    int dado1, dado2, dadoSomma;//variabili

    printf("\n\n**************************************************");
    printf("\nNumero turno=%d\tGiocatore=%s", Utente->numeroTurni, Utente->nomeGiocatore[Utente->giocatoreCorrente]);
    printf("\nStanza=%s\n", carteRecordStanza[Utente->stanzaGiocatore[Utente->giocatoreCorrente]].stringaCarte);

    if(Utente->ipotesiCorretta[Utente->giocatoreCorrente]==true){
        do{
            printf("\nHai già indovinato la tripla incognita\ndevi lanciare i dadi ed ottenere due valori uguali ed hai vinto|\n");
            printf("\nTira i dadi.................'t'");
            printf("\nSalvare partita.............'s'");
            printf("\nUscita......................'x'\n");
            scanf("%c", &scelta);
            getchar();

            switch(scelta){
                case 't':
                case 'T':
                    printf("\nTIRO DI DADI");

                    dado1=MIN_DADO+rand()%(MAX_DADO-MIN_DADO+1);//generazione casuale lancio dado 1
                    dado2=MIN_DADO+rand()%(MAX_DADO-MIN_DADO+1);//generazione casuale lancio dado 2
                    dadoSomma=dado1+dado2;//somma dei due dadi

                    #if DEBUG_MODE_DADO==1
                        printf("\nDEBUG_MODE_DADO\n");
                        printf("Inserire il valore del dado1 = ");
                        scanf("%d", &dado1);
                        printf("Inserire il valore del dado2 = ");
                        scanf("%d", &dado2);
                        dadoSomma=dado1+dado2;//somma dei due dadi
                    #endif // DEBUG_MODE_DADO

                    printf("\nDADO1 = %d", dado1);
                    printf("\nDADO2 = %d", dado2);
                    printf("\nSOMMA = %d", dadoSomma);

                    if(dado1==dado2){
                        printf("\nHai fatto un tiro doppio!!\n");

                        //PROCLAMAZIONE VINCITORE
                        printf("\n*********************************************************************");
                        printf("\n  IL GIOCATORE %s HA VINTO!", Utente->nomeGiocatore[Flag.vinto]);
                        printf("\n*********************************************************************");

                        //deallocazione
                        dealloca();
                        exit(-1);
                    }
                    break;
                case 's':
                case 'S':
                    printf("\nSALVATAGGIO PARTITA\n");
                    salvataggioPartita();
                    break;
                case 'x':
                case 'X':
                    //deallocazione
                    dealloca();
                    printf("\nUSCITA GIOCO\n");
                    exit(-1);
                    break;
                default:
                    printf("\nERRORE\nCarattere inserito non valido\nripetere la scelta\n");
                    break;
            }
        }while(!((scelta=='t')||(scelta=='T')||(scelta=='x')||(scelta=='X')));

    }else if(Utente->ipotesiCorretta[Utente->giocatoreCorrente]==false){
        do{
            printf("\nFormula ipotesi.............'f'");
            printf("\nTira i dadi.................'t'");
            printf("\nSalvare partita.............'s'");
            printf("\nUscita......................'x'\n");
            scanf("%c", &scelta);
            getchar();

            switch(scelta){
                case 'f':
                case 'F':
                    printf("\nFORMULAZIONE IPOTESI");
                    formulazioneIpotesi(carteRecordStanza, carteRecordArma, carteRecordSospetto);
                    break;
                case 't':
                case 'T':
                    printf("\nTIRO DI DADI");
                    subroutineStanza();
                    break;
                case 's':
                case 'S':
                    printf("\nSALVATAGGIO PARTITA\n");
                    salvataggioPartita();
                    break;
                case 'x':
                case 'X':
                    //deallocazione
                    dealloca();;
                    printf("\nUSCITA GIOCO\n");
                    exit(-1);
                    break;
                default:
                    printf("\nERRORE\nCarattere inserito non valido\nripetere la scelta\n");
                    break;
            }
        }while(!((scelta=='t')||(scelta=='T')||(scelta=='x')||(scelta=='X')||(scelta=='f')||(scelta=='F')));
    }
}
#endif // GESTIONECLUEDO_H_INCLUDED
