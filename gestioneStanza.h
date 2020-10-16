#ifndef GESTIONESTANZA_H_INCLUDED
#define GESTIONESTANZA_H_INCLUDED

void subroutineStanza(void){
    int dado1, dado2, dadoSomma;//variabili per il dado
    int scelta;

    dado1=MIN_DADO+rand()%(MAX_DADO-MIN_DADO+1);//generazione casuale lancio dado 1
    dado2=MIN_DADO+rand()%(MAX_DADO-MIN_DADO+1);//generazione casuale lancio dado 2
    dadoSomma=dado1+dado2;//somma dei due dadi

    #if DEBUG_MODE_DADO==1
        printf("\nDEBUG_MODE_DADO");
        printf("Inserire il valore del dado1 = ");
        scanf("%d", &dado1);
        printf("Inserire il valore del dado2 = ");
        scanf("%d", &dado2);
        dadoSomma=dado1+dado2;//somma dei due dadi
    #endif // DEBUG_MODE_DADO

    printf("\nDADO1 = %d", dado1);
    printf("\nDADO2 = %d", dado2);
    printf("\nSOMMA = %d", dadoSomma);

    switch(Utente->stanzaGiocatore[Utente->giocatoreCorrente]){
        case LAB_T://lab T
            if((dadoSomma>=4)&&(dadoSomma<=7)){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nel lab M digita..........'1'");
                    printf("\nPer andare nell'aula Costa digita....'2'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)));//ciclo se scelta non ha un valore compreso entro un range

            }else if((dadoSomma>=8)&&(dadoSomma<=11)){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nel lab M digita..........'1'");
                    printf("\nPer andare nell'aula Costa digita....'2'");
                    printf("\nPer andare nel bagno digita..........'3'");
                    printf("\nPer andare nel giardino digita.......'4'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)));//ciclo se scelta non ha un valore compreso entro un range

            }else if(dadoSomma==12){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nel lab M digita..........'1'");
                    printf("\nPer andare nell'aula Costa digita....'2'");
                    printf("\nPer andare nel bagno digita..........'3'");
                    printf("\nPer andare nel  giardino digita......'4'");
                    printf("\nPer andare nell' entrata digita......'5'");
                    printf("\nPer andare nel simaz digita..........'6'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)||(scelta==6))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)||(scelta==6)));//ciclo se scelta non ha un valore compreso entro un range
            }
            switch(scelta){//controllo sulla scelta effettuata e poi assegnamento
                case 1:
                    printf("Hai scelto 'lab M'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=LAB_M;//assegnamento
                    break;
                case 2:
                    printf("\nHai scelto 'aula Costa'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=AULA_COSTA;//assegnamento
                    break;
                case 3:
                    printf("\nHai scelto 'bagno'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=BAGNO;//assegnamento
                    break;
                case 4:
                    printf("\nHai scelto 'giardino'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=GIARDINO;//assegnamento
                    break;
                case 5:
                    printf("\nHai scelto 'entrata'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=ENTRATA;//assegnamento
                    break;
                case 6:
                    printf("\nHai scelto 'simaz'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=SIMAZ;//assegnamento
                    break;
            }
            break;
        case LAB_M://lab M
            if((dadoSomma>=4)&&(dadoSomma<=7)){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nel lab T digita....'1'");
                    printf("\nPer andare nel bagno digita....'2'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)));//ciclo se scelta non ha un valore compreso entro un range

            }else if((dadoSomma==8)||(dadoSomma==9)){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nel lab T digita..........'1'");
                    printf("\nPer andare nel bagno digita..........'2'");
                    printf("\nPer andare nell' aula Costa digita...'3'");
                    printf("\nPer andare nell' entrata digita......'4'");
                    printf("\nPer andare nel simaz digita..........'5'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)));//ciclo se scelta non ha un valore compreso entro un range

            }else if((dadoSomma==10)||(dadoSomma==11)){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nel lab T digita..........'1'");
                    printf("\nPer andare nel bagno digita..........'2'");
                    printf("\nPer andare nell' aula Costa digita...'3'");
                    printf("\nPer andare nell' entrata digita......'4'");
                    printf("\nPer andare nel simaz digita..........'5'");
                    printf("\nPer andare nella batcaverna digita...'6'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)||(scelta==6))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)||(scelta==6)));//ciclo se scelta non ha un valore compreso entro un range

            }else if(dadoSomma==12){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nel lab T digita..........'1'");
                    printf("\nPer andare nel bagno digita..........'2'");
                    printf("\nPer andare nell' aula Costa digita...'3'");
                    printf("\nPer andare nell' entrata digita......'4'");
                    printf("\nPer andare nel simaz digita..........'5'");
                    printf("\nPer andare nella batcaverna digita...'6'");
                    printf("\nPer andare nel giardino digita.......'7'");
                    printf("\nPer andare nel parcheggio digita.....'8'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)||(scelta==6)||(scelta==7)||(scelta==8))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)||(scelta==6)||(scelta==7)||(scelta==8)));//ciclo se scelta non ha un valore compreso entro un range
            }
            switch(scelta){//controllo sulla scelta effettuata e poi assegnamento
                case 1:
                    printf("Hai scelto 'lab T'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=LAB_T;//assegnamento
                    break;
                case 2:
                    printf("\nHai scelto 'bagno'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=BAGNO;//assegnamento
                    break;
                case 3:
                    printf("\nHai scelto 'aula Costa'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=AULA_COSTA;//assegnamento
                    break;
                case 4:
                    printf("\nHai scelto 'entrata'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=ENTRATA;//assegnamento
                    break;
                case 5:
                    printf("\nHai scelto 'simaz'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=SIMAZ;//assegnamento
                    break;
                case 6:
                    printf("\nHai scelto 'batcaverna'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=BATCAVERNA;//assegnamento
                    break;
                case 7:
                    printf("\nHai scelto 'giardino'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=GIARDINO;//assegnamento
                    break;
                case 8:
                    printf("\nHai scelto 'parcheggio'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=PARCHEGGIO;//assegnamento
                    break;
            }
            break;
        case BAGNO://bagno
            if((dadoSomma==4)||(dadoSomma==5)){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nel lab M digita..........'1'");
                    printf("\nPer andare nel simaz digita..........'2'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)));//ciclo se scelta non ha un valore compreso entro un range

            }else if((dadoSomma==6)||(dadoSomma==7)){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nel lab M digita..........'1'");
                    printf("\nPer andare nel simaz digita..........'2'");
                    printf("\nPer andare nel batcaverna digita.....'3'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2)||(scelta==3))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)||(scelta==3)));//ciclo se scelta non ha un valore compreso entro un range

            }else if((dadoSomma>=8)&&(dadoSomma<=11)){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nel lab M digita..........'1'");
                    printf("\nPer andare nel simaz digita..........'2'");
                    printf("\nPer andare nel batcaverna digita.....'3'");
                    printf("\nPer andare nel Lab T digita..........'4'");
                    printf("\nPer andare nel parcheggio digita.....'5'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)));//ciclo se scelta non ha un valore compreso entro un range

            }else if(dadoSomma==12){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nel lab M digita..........'1'");
                    printf("\nPer andare nel simaz digita..........'2'");
                    printf("\nPer andare nel batcaverna digita.....'3'");
                    printf("\nPer andare nel Lab T digita..........'4'");
                    printf("\nPer andare nel parcheggio digita.....'5'");
                    printf("\nPer andare nel aula Costa digita.....'6'");
                    printf("\nPer andare nel entrata digita........'7'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)||(scelta==6)||(scelta==7))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)||(scelta==6)||(scelta==7)));//ciclo se scelta non ha un valore compreso entro un range
            }
            switch(scelta){//controllo sulla scelta effettuata e poi assegnamento
                case 1:
                    printf("Hai scelto 'lab M'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=LAB_M;//assegnamento
                    break;
                case 2:
                    printf("\nHai scelto 'simaz'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=SIMAZ;//assegnamento
                    break;
                case 3:
                    printf("\nHai scelto 'batcaverna'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=BATCAVERNA;//assegnamento
                    break;
                case 4:
                    printf("\nHai scelto 'lab T'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=LAB_T;//assegnamento
                    break;
                case 5:
                    printf("\nHai scelto 'parcheggio'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=PARCHEGGIO;//assegnamento
                    break;
                case 6:
                    printf("\nHai scelto 'aula Costa'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=AULA_COSTA;//assegnamento
                    break;
                case 7:
                    printf("\nHai scelto 'entrata'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=ENTRATA;//assegnamento
                    break;
            }
            break;
        case AULA_COSTA://aula Costa
            if((dadoSomma>=4)&&(dadoSomma<=7)){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nel lab T digita..........'1'");
                    printf("\nPer andare nel giardino digita.......'2'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)));//ciclo se scelta non ha un valore compreso entro un range

            }else if((dadoSomma==8)||(dadoSomma==9)){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nel lab T digita..........'1'");
                    printf("\nPer andare nel giardino digita.......'2'");
                    printf("\nPer andare nel lab M digita..........'3'");
                    printf("\nPer andare nel entrata digita........'4'");
                    printf("\nPer andare nel simaz digita..........'5'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)));//ciclo se scelta non ha un valore compreso entro un range

            }else if((dadoSomma==10)||(dadoSomma==11)){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nel lab T digita..........'1'");
                    printf("\nPer andare nel giardino digita.......'2'");
                    printf("\nPer andare nel lab M digita..........'3'");
                    printf("\nPer andare nel entrata digita........'4'");
                    printf("\nPer andare nel simaz digita..........'5'");
                    printf("\nPer andare nel batcaverna digita.....'6'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)||(scelta==6))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)||(scelta==6)));//ciclo se scelta non ha un valore compreso entro un range

            }else if(dadoSomma==12){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nel lab T digita..........'1'");
                    printf("\nPer andare nel giardino digita.......'2'");
                    printf("\nPer andare nel lab M digita..........'3'");
                    printf("\nPer andare nel entrata digita........'4'");
                    printf("\nPer andare nel simaz digita..........'5'");
                    printf("\nPer andare nel batcaverna digita.....'6'");
                    printf("\nPer andare nel bagno digita..........'7'");
                    printf("\nPer andare nel parcheggio digita.....'8'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)||(scelta==6)||(scelta==7)||(scelta==8))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)||(scelta==6)||(scelta==7)||(scelta==8)));//ciclo se scelta non ha un valore compreso entro un range
            }
            switch(scelta){//controllo sulla scelta effettuata e poi assegnamento
                case 1:
                    printf("Hai scelto 'lab T'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=LAB_T;//assegnamento
                    break;
                case 2:
                    printf("\nHai scelto 'giardino'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=GIARDINO;//assegnamento
                    break;
                case 3:
                    printf("\nHai scelto 'lab M'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=LAB_M;//assegnamento
                    break;
                case 4:
                    printf("\nHai scelto 'entrata'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=ENTRATA;//assegnamento
                    break;
                case 5:
                    printf("\nHai scelto 'simaz'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=SIMAZ;//assegnamento
                    break;
                case 6:
                    printf("\nHai scelto 'batcaverna'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=BATCAVERNA;//assegnamento
                    break;
                case 7:
                    printf("\nHai scelto 'bagno'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=BAGNO;//assegnamento
                    break;
                case 8:
                    printf("\nHai scelto 'parcheggio'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=PARCHEGGIO;//assegnamento
                    break;
            }
            break;
        case GIARDINO://giardino
            if((dadoSomma>=4)&&(dadoSomma<=7)){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nell' aula Costa digita....'1'");
                    printf("\nPer andare nell' entrata digita.......'2'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)));//ciclo se scelta non ha un valore compreso entro un range

            }else if((dadoSomma==8)||(dadoSomma==9)){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nell' aula Costa digita...'1'");
                    printf("\nPer andare nell' entrata digita......'2'");
                    printf("\nPer andare nel lab T digita..........'3'");
                    printf("\nPer andare nel parcheggio digita.....'4'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2)|(scelta==3)||(scelta==4))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)|(scelta==3)||(scelta==4)));//ciclo se scelta non ha un valore compreso entro un range

            }else if((dadoSomma==10)||(scelta==11)){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nell' aula Costa digita...'1'");
                    printf("\nPer andare nell' entrata digita......'2'");
                    printf("\nPer andare nel lab T digita..........'3'");
                    printf("\nPer andare nel parcheggio digita.....'4'");
                    printf("\nPer andare nel batcaverna digita.....'5'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2)|(scelta==3)||(scelta==4)||(scelta==5))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)|(scelta==3)||(scelta==4)||(scelta==5)));//ciclo se scelta non ha un valore compreso entro un range

            }else if(dadoSomma==12){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nell' aula Costa digita...'1'");
                    printf("\nPer andare nell' entrata digita......'2'");
                    printf("\nPer andare nel lab T digita..........'3'");
                    printf("\nPer andare nel parcheggio digita.....'4'");
                    printf("\nPer andare nel batcaverna digita.....'5'");
                    printf("\nPer andare nel lab M digita..........'6'");
                    printf("\nPer andare nel simaz digita..........'7'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2)|(scelta==3)||(scelta==4)||(scelta==5)||(scelta==6)||(scelta==7))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)|(scelta==3)||(scelta==4)||(scelta==5)||(scelta==6)||(scelta==6)||(scelta==7)));//ciclo se scelta non ha un valore compreso entro un range
            }
            switch(scelta){//controllo sulla scelta effettuata e poi assegnamento
                case 1:
                    printf("\nHai scelto 'aula Costa'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=AULA_COSTA;//assegnamento
                    break;
                case 2:
                    printf("\nHai scelto 'entrata'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=ENTRATA;//assegnamento
                    break;
                case 3:
                    printf("\nHai scelto 'lab T'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=LAB_T;//assegnamento
                    break;
                case 4:
                    printf("\nHai scelto 'parcheggio'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=PARCHEGGIO;//assegnamento
                    break;
                case 5:
                    printf("\nHai scelto 'batcaverna'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=BATCAVERNA;//assegnamento
                    break;
                case 6:
                    printf("\nHai scelto 'lab M'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=LAB_M;//assegnamento
                    break;
                case 7:
                    printf("\nHai scelto 'simaz'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=SIMAZ;//assegnamento
                    break;
            }
            break;
        case ENTRATA://entrata
            if((dadoSomma==4)||(dadoSomma==5)){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nel giardino digita.........'1'");
                    printf("\nPer andare nel parcheggio digita.......'2'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)));//ciclo se scelta non ha un valore compreso entro un range

            }else if((dadoSomma==6)||(dadoSomma==7)){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nel giardino digita.........'1'");
                    printf("\nPer andare nel parcheggio digita.......'2'");
                    printf("\nPer andare nella batcaverna digita.....'3'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2)||(scelta==3))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)||(scelta==3)));//ciclo se scelta non ha un valore compreso entro un range

            }else if((dadoSomma>=8)&&(dadoSomma<=11)){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nel giardino digita.........'1'");
                    printf("\nPer andare nel parcheggio digita.......'2'");
                    printf("\nPer andare nella batcaverna digita.....'3'");
                    printf("\nPer andare nel lab M digita............'4'");
                    printf("\nPer andare nell'aula Costa digita......'5'");
                    printf("\nPer andare nel simaz digita............'6'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)||(scelta==6))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)||(scelta==6)));//ciclo se scelta non ha un valore compreso entro un range
            }else if(dadoSomma==12){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nel giardino digita.........'1'");
                    printf("\nPer andare nel parcheggio digita.......'2'");
                    printf("\nPer andare nella batcaverna digita.....'3'");
                    printf("\nPer andare nel lab M digita............'4'");
                    printf("\nPer andare nell'aula Costa digita......'5'");
                    printf("\nPer andare nel simaz digita............'6'");
                    printf("\nPer andare nel lab T digita............'7'");
                    printf("\nPer andare nel bagno digita............'8'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)||(scelta==6)||(scelta==7)||(scelta==8))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)||(scelta==6)||(scelta==7)||(scelta==8)));//ciclo se scelta non ha un valore compreso entro un range
            }
            switch(scelta){//controllo sulla scelta effettuata e poi assegnamento
                case 1:
                    printf("\nHai scelto 'giardino'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=GIARDINO;//assegnamento
                    break;
                case 2:
                    printf("\nHai scelto 'parcheggio'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=PARCHEGGIO;//assegnamento
                    break;
                case 3:
                    printf("\nHai scelto 'batcaverna'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=BATCAVERNA;//assegnamento
                    break;
                case 4:
                    printf("\nHai scelto 'lab M'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=LAB_M;//assegnamento
                    break;
                case 5:
                    printf("\nHai scelto 'aula Costa'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=AULA_COSTA;//assegnamento
                    break;
                case 6:
                    printf("\nHai scelto 'simaz'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=SIMAZ;//assegnamento
                    break;
                case 7:
                    printf("\nHai scelto 'lab T'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=LAB_T;//assegnamento
                    break;
                case 8:
                    printf("\nHai scelto 'bagno'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=BAGNO;//assegnamento
                    break;
            }
            break;
        case PARCHEGGIO://parcheggio
            if((dadoSomma==2)||(dadoSomma==3)){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nella batcaverna digita.........'1'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!(scelta==1)){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!(scelta==1));//ciclo se scelta non ha un valore compreso entro un range

            }else if((dadoSomma>=4)&&(dadoSomma<=7)){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nella batcaverna digita.........'1'");
                    printf("\nPer andare nel entrata digita..............'2'");
                    printf("\nPer andare nel simaz digita................'3'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2)||(scelta==3))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)||(scelta==3)));//ciclo se scelta non ha un valore compreso entro un range

            }else if((dadoSomma>=8)&&(dadoSomma<=11)){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nella batcaverna digita.........'1'");
                    printf("\nPer andare nel entrata digita..............'2'");
                    printf("\nPer andare nel simaz digita................'3'");
                    printf("\nPer andare nel bagno digita................'4'");
                    printf("\nPer andare nel giardino digita.............'5'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)));//ciclo se scelta non ha un valore compreso entro un range

            }else if(dadoSomma==12){//controllo somma dei dadi compresi entro un range
                do{
                    printf("\nPer andare nella batcaverna digita.........'1'");
                    printf("\nPer andare nel entrata digita..............'2'");
                    printf("\nPer andare nel simaz digita................'3'");
                    printf("\nPer andare nel bagno digita................'4'");
                    printf("\nPer andare nel giardino digita.............'5'");
                    printf("\nPer andare nel lab M digita................'6'");
                    printf("\nPer andare nell'aula Costa digita..........'7'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)||(scelta==6)||(scelta==7))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)||(scelta==6)||(scelta==7)));//ciclo se scelta non ha un valore compreso entro un range
            }
            switch(scelta){//controllo sulla scelta effettuata e poi assegnamento
                case 1:
                    printf("\nHai scelto 'batcaverna'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=BATCAVERNA;//assegnamento
                    break;
                case 2:
                    printf("\nHai scelto 'entrata'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=ENTRATA;//assegnamento
                    break;
                case 3:
                    printf("\nHai scelto 'simaz'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=SIMAZ;//assegnamento
                    break;
                case 4:
                    printf("\nHai scelto 'bagno'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=BAGNO;//assegnamento
                    break;
                case 5:
                    printf("\nHai scelto 'giardino'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=GIARDINO;//assegnamento
                    break;
                case 6:
                    printf("\nHai scelto 'lab M'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=LAB_M;//assegnamento
                    break;
                case 7:
                    printf("\nHai scelto 'aula Costa'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=AULA_COSTA;//assegnamento
                    break;
            }
            break;
        case SIMAZ://simaz
            if((dadoSomma==2)||(dadoSomma==3)){
                do{
                    printf("\nPer andare nella batcaverna digita.........'1'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!(scelta==1)){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!(scelta==1));//ciclo se scelta non ha un valore compreso entro un range

            }else if((dadoSomma>=4)&&(dadoSomma<=7)){
                do{
                    printf("\nPer andare nella batcaverna digita.........'1'");
                    printf("\nPer andare nel bagno digita................'2'");
                    printf("\nPer andare nel parcheggio digita...........'3'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2)||(scelta==3))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)||(scelta==3)));//ciclo se scelta non ha un valore compreso entro un range

            }else if((dadoSomma>=8)&&(dadoSomma<=11)){
                do{
                    printf("\nPer andare nella batcaverna digita.........'1'");
                    printf("\nPer andare nel bagno digita................'2'");
                    printf("\nPer andare nel parcheggio digita...........'3'");
                    printf("\nPer andare nel lab M digita................'4'");
                    printf("\nPer andare nell'aula Costa digita..........'5'");
                    printf("\nPer andare nel entrata digita..............'6'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)||(scelta==6))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)||(scelta==6)));//ciclo se scelta non ha un valore compreso entro un range

            }else if(dadoSomma==12){
                do{
                    printf("\nPer andare nella batcaverna digita.........'1'");
                    printf("\nPer andare nel bagno digita................'2'");
                    printf("\nPer andare nel parcheggio digita...........'3'");
                    printf("\nPer andare nel lab M digita................'4'");
                    printf("\nPer andare nell'aula Costa digita..........'5'");
                    printf("\nPer andare nel entrata digita..............'6'");
                    printf("\nPer andare nel lab T digita................'7'");
                    printf("\nPer andare nel giardino digita.............'8'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)||(scelta==6)||(scelta==7)||(scelta==8))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)||(scelta==6)||(scelta==7)||(scelta==8)));//ciclo se scelta non ha un valore compreso entro un range
            }
            switch(scelta){//controllo sulla scelta effettuata e poi assegnamento
                case 1:
                    printf("\nHai scelto 'batcaverna'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=BATCAVERNA;//assegnamento
                    break;
                case 2:
                    printf("\nHai scelto 'bagno'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=BAGNO;//assegnamento
                    break;
                case 3:
                    printf("\nHai scelto 'parcheggio'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=PARCHEGGIO;//assegnamento
                    break;
                case 4:
                    printf("\nHai scelto 'lab M'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=LAB_M;//assegnamento
                    break;
                case 5:
                    printf("\nHai scelto 'aula Costa'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=AULA_COSTA;//assegnamento
                    break;
                case 6:
                    printf("\nHai scelto 'entrata'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=ENTRATA;//assegnamento
                    break;
                case 7:
                    printf("\nHai scelto 'lab T'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=LAB_T;//assegnamento
                    break;
                case 8:
                    printf("\nHai scelto 'giardino'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=GIARDINO;//assegnamento
                    break;
            }
            break;
        case BATCAVERNA://batcaverna
            if((dadoSomma>=2)&&(dadoSomma<=5)){
                do{
                    printf("\nPer andare nella parcheggio digita.........'1'");
                    printf("\nPer andare nella simaz digita..............'2'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)));//ciclo se scelta non ha un valore compreso entro un range

            }else if((dadoSomma>=6)&&(dadoSomma<=9)){
                do{
                    printf("\nPer andare nella parcheggio digita.........'1'");
                    printf("\nPer andare nella simaz digita..............'2'");
                    printf("\nPer andare nella bagno digita..............'3'");
                    printf("\nPer andare nella entrata digita............'4'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)));//ciclo se scelta non ha un valore compreso entro un range

            }else if((dadoSomma>=10)&&(dadoSomma<=12)){
                do{
                    printf("\nPer andare nella parcheggio digita.........'1'");
                    printf("\nPer andare nella simaz digita..............'2'");
                    printf("\nPer andare nella bagno digita..............'3'");
                    printf("\nPer andare nella entrata digita............'4'");
                    printf("\nPer andare nella lab M digita..............'5'");
                    printf("\nPer andare nell' aula Costa digita.........'6'");
                    printf("\nPer andare nel giatdino digita.............'7'\n");
                    scanf("%d", &scelta);//acquisizione
                    getchar();

                    if(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)||(scelta==6)||(scelta==7))){//controllo scelta compresa entro un range
                        printf("\nErrore!\nValore inserito non valido\nripetere\n");
                    }
                }while(!((scelta==1)||(scelta==2)||(scelta==3)||(scelta==4)||(scelta==5)||(scelta==6)||(scelta==7)));//ciclo se scelta non ha un valore compreso entro un range
            }
            switch(scelta){//controllo sulla scelta effettuata e poi assegnamento
                case 1:
                    printf("\nHai scelto 'parcheggio'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=PARCHEGGIO;//assegnamento
                    break;
                case 2:
                    printf("\nHai scelto 'simaz'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=SIMAZ;//assegnamento
                    break;
                case 3:
                    printf("\nHai scelto 'bagno'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=BAGNO;//assegnamento
                    break;
                case 4:
                    printf("\nHai scelto 'entrata'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=ENTRATA;//assegnamento
                    break;
                case 5:
                    printf("\nHai scelto 'lab M'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=LAB_M;//assegnamento
                    break;
                case 6:
                    printf("\nHai scelto 'aula Costa'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=AULA_COSTA;//assegnamento
                    break;
                case 7:
                    printf("\nHai scelto 'giardino'\n");
                    Utente->stanzaGiocatore[Utente->giocatoreCorrente]=GIARDINO;//assegnamento
                    break;
            }
            break;
    }
}
#endif // GESTIONESTANZA_H_INCLUDED
