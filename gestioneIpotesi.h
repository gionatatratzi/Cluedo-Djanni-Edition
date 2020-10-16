#ifndef GESTIONEIPOTESI_H_INCLUDED
#define GESTIONEIPOTESI_H_INCLUDED

void formulazioneIpotesi(CarteGioco carteRecordStanza[NOVE], CarteGioco carteRecordArma[SEI], CarteGioco carteRecordSospetto[SEI]){
    int sceltaArma, sceltaSospetto;//variabili scelta
    int h, j, k;//variabile indice
    int value;//variabile

    Utente->stanzaIpotizzata[Utente->giocatoreCorrente]=Utente->stanzaGiocatore[Utente->giocatoreCorrente];//stanza attuale

    #if DEBUG_MODE_IPOTESI==1
        int sceltaStanza;//variabile scelta

        do{
            printf("\nDEBUG_MODE_IPOTESI");
            printf("\nScegli una stanza digitando il numero affianco");
            for(h=0; h<NOVE; h++){//ciclo stampa arma
                printf("\n%d)  %s", h+1, carteRecordStanza[h].stringaCarte);
            }
            printf("\n");
            scanf("%d", &sceltaStanza);//acquisizione
            getchar();

            if(!((sceltaStanza>=1)&&(sceltaStanza<=9))){//controlla scelta entro un certo range
                printf("\nERRORE\nValore inserito non valido\nRipetere\n");
            }
        }while(!((sceltaStanza>=1)&&(sceltaStanza<=9)));//cicla se scelta non e' entro un certo range

        if((sceltaStanza>=1)&&(sceltaStanza<=9)){//controlla scelta entro un certo range con assegnamento
            Utente->stanzaIpotizzata[Utente->giocatoreCorrente]=sceltaStanza-1;//assegnamento
            printf("\nHai scelto %s\n", carteRecordStanza[sceltaStanza-1].stringaCarte);
        }
    #endif // DEBUG_MODE_IPOTESI
    do{
        printf("\nScegli un'arma digitando il numero affianco");
        for(h=0; h<SEI; h++){//ciclo stampa arma
            printf("\n%d)  %s", h+1, carteRecordArma[h].stringaCarte);
        }
        printf("\n");
        scanf("%d", &sceltaArma);//acquisizione
        getchar();

        if(!((sceltaArma>=1)&&(sceltaArma<=6))){//controlla scelta entro un certo range
            printf("\nERRORE\nValore inserito non valido\nRipetere\n");
        }
    }while(!((sceltaArma>=1)&&(sceltaArma<=6)));//cicla se scelta non e' entro un certo range

    if((sceltaArma>=1)&&(sceltaArma<=6)){//controlla scelta entro un certo range con assegnamento
        Utente->armaIpotizzata[Utente->giocatoreCorrente]=sceltaArma-1;//assegnamento
        printf("\nHai scelto %s\n", carteRecordArma[sceltaArma-1].stringaCarte);
    }
    do{
        printf("\nScegli un sospettato digitando il numero affianco");
        for(h=0; h<SEI; h++){//ciclo stampa arma
            printf("\n%d)  %s", h+1, carteRecordSospetto[h].stringaCarte);
        }
        printf("\n");
        scanf("%d", &sceltaSospetto);//acquisizione
        getchar();

        if(!((sceltaSospetto>=1)&&(sceltaSospetto<=6))){//controlla scelta entro un certo range
            printf("\nERRORE\nValore inserito non valido\nRipetere\n");
        }
    }while(!((sceltaSospetto>=1)&&(sceltaSospetto<=6)));//cicla se scelta non e' entro un certo range

    if((sceltaSospetto>=1)&&(sceltaSospetto<=6)){//controlla scelta entro un certo range con assegnamento
        Utente->sospettoIpotizzato[Utente->giocatoreCorrente]=sceltaSospetto-1;//assegnamento
        printf("\nHai scelto %s\n", carteRecordSospetto[sceltaSospetto-1].stringaCarte);
    }
    if(Flag.vettoreCarteIncognita[0]==Utente->stanzaIpotizzata[Utente->giocatoreCorrente]){//verifica carta incognita

        if(Flag.vettoreCarteIncognita[1]==Utente->armaIpotizzata[Utente->giocatoreCorrente]+MIN_ARMA){//verifica carta incognita

            if(Flag.vettoreCarteIncognita[2]==Utente->sospettoIpotizzato[Utente->giocatoreCorrente]+MIN_SOSPETTO){//verifica carta incognita
                Utente->ipotesiCorretta[Utente->giocatoreCorrente]=true;//ipotesi corretta
            }
        }
    }
    if(Flag.vettoreCarteIncognita[0]!=Utente->stanzaIpotizzata[Utente->giocatoreCorrente]){//verifica carta incognita
        Utente->ipotesiCorretta[Utente->giocatoreCorrente]=false;//ipotesi errata

        if(Flag.vettoreCarteIncognita[1]!=Utente->armaIpotizzata[Utente->giocatoreCorrente]+MIN_ARMA){//verifica carta incognita
            Utente->ipotesiCorretta[Utente->giocatoreCorrente]=false;//ipotesi errata

            if(Flag.vettoreCarteIncognita[2]!=Utente->sospettoIpotizzato[Utente->giocatoreCorrente]+MIN_SOSPETTO){//verifica carta incognita
                Utente->ipotesiCorretta[Utente->giocatoreCorrente]=false;//ipotesi errata
            }
        }
    }
    for(j=0; j<Flag.numeroGiocatori; j++){//setto a false tutti i flag carte giocatori trovate uguali a ipotesi
        for(k=0; k<TRE; k++){//ciclo da 0 a 3
            Flag.cartaTrovata[j][k]=false;//flag settato a false
        }
        Utente->ipotesiNonCorretta[j]=false;//inizializzo il flag a false
        Flag.counter2[j]=0;//azzero il contatore
    }
    if(Utente->ipotesiCorretta[Utente->giocatoreCorrente]==true){//ipotesi corretta
        printf("\nL' IPOTESI E' CORRETTA\nHai indovinato\n");

    }else if(Utente->ipotesiCorretta[Utente->giocatoreCorrente]==false){//ipotesi errata
        printf("\nL'IPOTESI E' ERRATA\n");

        //VERIFICA GIOCATORI
        for(j=0; j<Flag.numeroGiocatori; j++){//cicla il numero dei giocatori
            for(h=0; h<Flag.quoziente; h++){//ciclo da 0 a quoziente
                if(Flag.vettoreGiocatore[j][h]==Utente->stanzaIpotizzata[Utente->giocatoreCorrente]){//controllo carta giocatore/ipotesi

                    Flag.counter2[j]++;//incremento il contatore
                    Flag.cartaTrovata[j][STANZA]=true;//setto a true il flag carta trovata
                }
                if(Flag.vettoreGiocatore[j][h]==Utente->armaIpotizzata[Utente->giocatoreCorrente]+MIN_ARMA){//controllo carta giocatore/ipotesi

                    Flag.counter2[j]++;//incremento il contatore
                    Flag.cartaTrovata[j][ARMA]=true;//setto a true il flag carta trovata
                }
                if(Flag.vettoreGiocatore[j][h]==Utente->sospettoIpotizzato[Utente->giocatoreCorrente]+MIN_SOSPETTO){//controllo carta giocatore/ipotesi

                    Flag.counter2[j]++;//incremento il contatore
                    Flag.cartaTrovata[j][SOSPETTO]=true;//setto a true il flag carta trovata
                }
            }
        }
        for(j=0; j<Flag.numeroGiocatori; j++){//cicla il numero dei giocatori
            if(Flag.counter2[j]==0){//controlla il valore del flag contatore
                if((Flag.cartaTrovata[j][SOSPETTO]==false)&&(Flag.cartaTrovata[j][STANZA]==false)&&(Flag.cartaTrovata[j][ARMA]==false)){//condizione logica
                    Utente->ipotesiNonCorretta[j]=true;//flag ipotesi errata
                }
            }
        }
        for(j=0; j<Flag.numeroGiocatori; j++){//cicla il numero dei giocatori
            if(Flag.counter2[j]==1){//controlla il valore del flag contatore
               for(k=0; k<TRE; k++){//cicla la tipologia di carte
                    if(Flag.cartaTrovata[j][k]==true){//condizione logica carta trovata
                        printf("\n\nIl giocatore %s confuta l'ipotesi", Utente->nomeGiocatore[j]);
                        if(k==0){//arma
                            printf("\nARMA: %s", carteRecordArma[Utente->armaIpotizzata[Utente->giocatoreCorrente]].stringaCarte);
                        }else if(k==1){//sospetto
                            printf("\nSOSPETTO: %s", carteRecordSospetto[Utente->sospettoIpotizzato[Utente->giocatoreCorrente]].stringaCarte);
                        }else if(k==2){//stanza
                            printf("\nSTANZA: %s", carteRecordStanza[Utente->stanzaIpotizzata[Utente->giocatoreCorrente]].stringaCarte);
                        }
                    }
                }
            }
        }
        for(j=0; j<Flag.numeroGiocatori; j++){//cicla il numero dei giocatori
            if(Flag.counter2[j]==2){//controlla il valore del flag contatore
                if((Flag.cartaTrovata[j][ARMA]==true)&&(Flag.cartaTrovata[j][SOSPETTO]==true)){//condizione logica
                    do{
                        printf("\n\nIl giocatore %s ha due carte ipotizzate\nscegli quale mostrare", Utente->nomeGiocatore[j]);
                        printf("\n1)ARMA");
                        printf("\n2)SOSPETTO\n");
                        scanf("%d", &value);//acquisizione
                        getchar();

                        if(!((value==1)||(value==2))){//valore non valido
                            printf("\nERRORE valore inserito non valido\nripetere\n");
                        }
                    }while(!((value==1)||(value==2)));//cicla sinchè il valore inserito non è valido

                    switch(value){//controllo il valore inserito
                        case 1:
                            printf("\nARMA: %s", carteRecordArma[Utente->armaIpotizzata[Utente->giocatoreCorrente]].stringaCarte);
                            break;
                        case 2:
                            printf("\nSOSPETTO: %s", carteRecordSospetto[Utente->sospettoIpotizzato[Utente->giocatoreCorrente]].stringaCarte);
                            break;
                    }
                }
            }
        }
        for(j=0; j<Flag.numeroGiocatori; j++){//cicla il numero dei giocatori
            if(Flag.counter2[j]==2){//controlla il valore del flag contatore
                if((Flag.cartaTrovata[j][ARMA]==true)&&(Flag.cartaTrovata[j][STANZA]==true)){//condizione logica
                    do{
                        printf("\n\nIl giocatore %s ha due carte ipotizzate\nscegli quale mostrare", Utente->nomeGiocatore[j]);
                        printf("\n1)ARMA");
                        printf("\n2)STANZA\n");
                        scanf("%d", &value);//acquisizione
                        getchar();

                        if(!((value==1)||(value==2))){//valore non valido
                            printf("\nERRORE valore inserito non valido\nripetere\n");
                        }
                    }while(!((value==1)||(value==2)));//cicla sinchè il valore inserito non è valido

                    switch(value){//controllo il valore inserito
                        case 1:
                            printf("\nARMA: %s", carteRecordArma[Utente->armaIpotizzata[Utente->giocatoreCorrente]].stringaCarte);
                            break;
                        case 2:
                            printf("\nSTANZA: %s", carteRecordStanza[Utente->stanzaIpotizzata[Utente->giocatoreCorrente]].stringaCarte);
                            break;
                    }
                }
            }
        }
        for(j=0; j<Flag.numeroGiocatori; j++){//cicla il numero dei giocatori
            if(Flag.counter2[j]==2){//controlla il valore del flag contatore
                if((Flag.cartaTrovata[j][SOSPETTO]==true)&&(Flag.cartaTrovata[j][STANZA]==true)){//condizione logica
                    do{
                        printf("\n\nIl giocatore %s ha due carte ipotizzate\nscegli quale mostrare", Utente->nomeGiocatore[j]);
                        printf("\n1)SOSPETTO");
                        printf("\n2)STANZA\n");
                        scanf("%d", &value);//acquisizione
                        getchar();

                        if(!((value==1)||(value==2))){//valore non valido
                            printf("\nERRORE valore inserito non valido\nripetere\n");
                        }
                    }while(!((value==1)||(value==2)));//cicla sinchè il valore inserito non è valido

                    switch(value){//controllo il valore inserito
                        case 1:
                            printf("\nSOSPETTO: %s", carteRecordSospetto[Utente->sospettoIpotizzato[Utente->giocatoreCorrente]].stringaCarte);
                            break;
                        case 2:
                            printf("\nSTANZA: %s", carteRecordStanza[Utente->stanzaIpotizzata[Utente->giocatoreCorrente]].stringaCarte);
                            break;
                    }
                }
            }
        }
        for(j=0; j<Flag.numeroGiocatori; j++){//cicla il numero dei giocatori
            if(Flag.counter2[j]==3){//controlla il valore del flag contatore
                if((Flag.cartaTrovata[j][SOSPETTO]==true)&&(Flag.cartaTrovata[j][STANZA]==true)&&(Flag.cartaTrovata[j][ARMA]==true)){//condizione logica
                    do{
                        printf("\n\nIl giocatore %s ha due carte ipotizzate\nscegli quale mostrare", Utente->nomeGiocatore[j]);
                        printf("\n1)SOSPETTO");
                        printf("\n2)STANZA");
                        printf("\n3)ARMA\n");
                        scanf("%d", &value);//acquisizione
                        getchar();

                        if(!((value==1)||(value==2)||(value==3))){//valore non valido
                            printf("\nERRORE valore inserito non valido\nripetere\n");
                        }
                    }while(!((value==1)||(value==2)||(value==3)));//cicla sinchè il valore inserito non è valido

                    switch(value){//controllo il valore inserito
                        case 1:
                            printf("\nSOSPETTO: %s", carteRecordSospetto[Utente->sospettoIpotizzato[Utente->giocatoreCorrente]].stringaCarte);
                            break;
                        case 2:
                            printf("\nSTANZA: %s", carteRecordStanza[Utente->stanzaIpotizzata[Utente->giocatoreCorrente]].stringaCarte);
                            break;
                        case 3:
                            printf("\nARMA: %s", carteRecordArma[Utente->armaIpotizzata[Utente->giocatoreCorrente]].stringaCarte);
                            break;
                    }
                }
            }
        }
        if(Flag.numeroGiocatori==3){
            if((Utente->ipotesiNonCorretta[UTENTE1]==true)&&(Utente->ipotesiNonCorretta[UTENTE2]==true)&&
               (Utente->ipotesiNonCorretta[UTENTE3]==true)){

                printf("\nNessun giocatore confuta l'ipotesi\n");
            }
        }else if(Flag.numeroGiocatori==4){
            if((Utente->ipotesiNonCorretta[UTENTE1]==true)&&(Utente->ipotesiNonCorretta[UTENTE2]==true)&&
               (Utente->ipotesiNonCorretta[UTENTE3]==true)&&(Utente->ipotesiNonCorretta[UTENTE4]==true)){

                printf("\nNessun giocatore confuta l'ipotesi\n");
            }
        }else if(Flag.numeroGiocatori==5){
            if((Utente->ipotesiNonCorretta[UTENTE1]==true)&&(Utente->ipotesiNonCorretta[UTENTE2]==true)&&
               (Utente->ipotesiNonCorretta[UTENTE3]==true)&&(Utente->ipotesiNonCorretta[UTENTE4]==true)&&
               (Utente->ipotesiNonCorretta[UTENTE5]==true)){

                printf("\nNessun giocatore confuta l'ipotesi\n");
            }
        }else if(Flag.numeroGiocatori==6){
            if((Utente->ipotesiNonCorretta[UTENTE1]==true)&&(Utente->ipotesiNonCorretta[UTENTE2]==true)&&
               (Utente->ipotesiNonCorretta[UTENTE3]==true)&&(Utente->ipotesiNonCorretta[UTENTE4]==true)&&
               (Utente->ipotesiNonCorretta[UTENTE5]==true)&&(Utente->ipotesiNonCorretta[UTENTE6]==true)){

                printf("\nNessun giocatore confuta l'ipotesi\n");
            }
        }
    }
}
#endif // GESTIONEIPOTESI_H_INCLUDED
