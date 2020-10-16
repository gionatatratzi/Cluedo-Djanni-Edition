#ifndef SUBROUTINELISTE_H_INCLUDED
#define SUBROUTINELISTE_H_INCLUDED

ListaArma* allocazioneArma(CarteGioco carteRecordArma[SEI], ListaArma* listaArma){//subroutine allocazione arma
    if(Flag.counter<SEI){//condizione "contatore minore di 6
        listaArma=(ListaArma*)malloc(sizeof(ListaArma));//allocazione dinamica lista arma
        if(listaArma==NULL) exit(-1);//verifica se l'allocazione è andata a buon fine

        listaArma->Id=carteRecordArma[Flag.counter].Id;//caricamento del record sulla lista
        #if DEBUG_MODE_ASSEGNAMENTO==1
            printf("n: %d\tId: %d\n", Flag.counter, listaArma->Id);
        #endif // DEBUG_MODE_ASSEGNAMENTO
        Flag.counter++;//incremento il contatore
        allocazioneArma(carteRecordArma, listaArma);//invocazione ricorsiva
    }
    return listaArma;//valore di ritorno
}
ListaSospetto* allocazioneSospetto(CarteGioco carteRecordSospetto[SEI], ListaSospetto* listaSospetto){
    if(Flag.counter<SEI){//condizione "contatore minore di 6
        listaSospetto=(ListaSospetto*)malloc(sizeof(ListaSospetto));//allocazione dinamica lista sospetto
        if(listaSospetto==NULL) exit(-1);//verifica se l'allocazione è andata a buon fine

        listaSospetto->Id=carteRecordSospetto[Flag.counter].Id;//caricamento del record sulla lista
        #if DEBUG_MODE_ASSEGNAMENTO==1
            printf("n: %d\tId: %d\n", Flag.counter, listaSospetto->Id);
        #endif // DEBUG_MODE_ASSEGNAMENTO
        Flag.counter++;//incremento il contatore
        allocazioneSospetto(carteRecordSospetto, listaSospetto);//invocazione ricorsiva
   }
   return listaSospetto;//valore di ritorno
}
ListaStanza* allocazioneStanza(CarteGioco carteRecordStanza[NOVE], ListaStanza* listaStanza){
    if(Flag.counter<NOVE){//condizione "contatore minore di 9
        listaStanza=(ListaStanza*)malloc(sizeof(ListaStanza));//allocazione dinamica lista stanza
        if(listaStanza==NULL) exit(-1);//verifica se l'allocazione è andata a buon fine

        listaStanza->Id=carteRecordStanza[Flag.counter].Id;//caricamento del record sulla lista
        #if DEBUG_MODE_ASSEGNAMENTO==1
            printf("n: %d\tId: %d\n", Flag.counter, listaStanza->Id);
        #endif // DEBUG_MODE_ASSEGNAMENTO
        Flag.counter++;//incremento il contatore
        allocazioneStanza(carteRecordStanza, listaStanza);//invocazione ricorsiva
    }
    return listaStanza;//valore di ritorno
}
ListaArma* mescolamentoCarteArma(ListaArma* listaArma){//subroutine mescolamento carte arma
    int h;//variabile indice
    int vectorArma[SEI]={0};//vettore d'appoggio settato a zero

    for(h=1; h<=SEI; h++){//cicla per h da 1 a 6 incluso
        do{
            Flag.random=MIN+rand()%(MAX_SEI-MIN+1);//generazione casuale
        }while(vectorArma[Flag.random]!=0);//cicla sinchè il vettore non è pieno

        vectorArma[Flag.random]=h;//il vettore prende il valore di h
        listaArma->Id=Flag.random+MIN_ARMA;//assegnamento valore random
        Flag.vettoreAppoggio1[h+MIN_ARMA-UNO]=Flag.random+MIN_ARMA;//assegnamento valore random a vettore appoggio

        #if DEBUG_MODE_ASSEGNAMENTO==1
            printf("n: %d\tId: %d\n", h-1, listaArma->Id);
        #endif // DEBUG_MODE_ASSEGNAMENTO
    }
    return listaArma;//valore restituito
}
ListaSospetto* mescolamentoCarteSospetto(ListaSospetto* listaSospetto){//subroutine mescolamento carte sospetto
    int h;//variabile indice
    int vectorSospetto[SEI]={0};//vettore d'appoggio settato a zero

    for(h=1; h<=SEI; h++){//cicla per h da 1 a 6 incluso
        do{
            Flag.random=MIN+rand()%(MAX_SEI-MIN+1);//generazione casuale
        }while(vectorSospetto[Flag.random]!=0);//cicla sinchè il vettore non è pieno

        vectorSospetto[Flag.random]=h;//il vettore prende il valore di h
        listaSospetto->Id=Flag.random+MIN_SOSPETTO;//assegnamento valore random
        Flag.vettoreAppoggio1[h+MIN_SOSPETTO-UNO]=Flag.random+MIN_SOSPETTO;//assegnamento valore random a vettore appoggio

        #if DEBUG_MODE_ASSEGNAMENTO==1
            printf("n: %d\tId: %d\n", h-1, listaSospetto->Id);
        #endif // DEBUG_MODE_ASSEGNAMENTO
    }
    return listaSospetto;//valore restituito
}
ListaStanza* mescolamentoCarteStanza(ListaStanza* listaStanza){//subroutine mescolamento carte stanza
    int h;//variabile indice
    int vectorStanza[NOVE]={0};//vettore d'appoggio settato a zero

    for(h=1; h<=NOVE; h++){//cicla per h da 1 a 9 incluso
        do{
            Flag.random=MIN+rand()%(MAX_NOVE-MIN+1);//generazione casuale
        }while(vectorStanza[Flag.random]!=0);//cicla sinchè il vettore non è pieno

        vectorStanza[Flag.random]=h;//il vettore prende il valore di h
        listaStanza->Id=Flag.random;//assegnamento valore random
        Flag.vettoreAppoggio1[h-1]=Flag.random;//assegnamento valore random a vettore appoggio

        #if DEBUG_MODE_ASSEGNAMENTO==1
            printf("n: %d\tId: %d\n", h-1, listaStanza->Id);
        #endif // DEBUG_MODE_ASSEGNAMENTO
    }
    return listaStanza;//valore restituito
}
ListaCarteMescolate* allocazioneMescolateStanza(ListaCarteMescolate* listaMescolate){

    if(Flag.counter<MAX_STANZA){//controllo se 0 è minore di 8
        listaMescolate=(ListaCarteMescolate*)malloc(sizeof(ListaCarteMescolate));//allocazione dinamica mazzo 18 carte
        if(listaMescolate==NULL) exit(-1);//verifica se l'allocazione è andata a buon fine

        listaMescolate->Id=Flag.vettoreAppoggio1[Flag.counter+1];//caricamento stanza nella lista
        #if DEBUG_MODE_ASSEGNAMENTO2==1
            printf("\nn: %d\tId: %d", Flag.counter+1, listaMescolate->Id);
        #endif // DEBUG_MODE_ASSEGNAMENTO
        Flag.counter++;//incremento il contatore
        allocazioneMescolateStanza(listaMescolate);//invocazione ricorsiva
    }
    return listaMescolate;//valore di ritorno
}
ListaCarteMescolate* allocazioneMescolateArma(ListaCarteMescolate* listaMescolate){

    if(Flag.counter<MAX_ARMA){//controllo se 9 è minore di 14
        listaMescolate=(ListaCarteMescolate*)malloc(sizeof(ListaCarteMescolate));//allocazione dinamica mazzo 18 carte
        if(listaMescolate==NULL) exit(-1);//verifica se l'allocazione è andata a buon fine

        listaMescolate->Id=Flag.vettoreAppoggio1[Flag.counter+1];
        #if DEBUG_MODE_ASSEGNAMENTO2==1
            printf("\nn: %d\tId: %d", Flag.counter, listaMescolate->Id);
        #endif // DEBUG_MODE_ASSEGNAMENTO
        Flag.counter++;//incremento il contatore
        allocazioneMescolateArma(listaMescolate);
    }
    return listaMescolate;//valore di ritorno
}
ListaCarteMescolate* allocazioneMescolateSospetto(ListaCarteMescolate* listaMescolate){

    if(Flag.counter<MAX_SOSPETTO){//controllo se 15 è minore di 20
        listaMescolate=(ListaCarteMescolate*)malloc(sizeof(ListaCarteMescolate));//allocazione dinamica mazzo 18 carte
        if(listaMescolate==NULL) exit(-1);//verifica se l'allocazione è andata a buon fine

        listaMescolate->Id=Flag.vettoreAppoggio1[Flag.counter+1];
        #if DEBUG_MODE_ASSEGNAMENTO2==1
            printf("\nn: %d\tId: %d", Flag.counter-1, listaMescolate->Id);
        #endif // DEBUG_MODE_ASSEGNAMENTO
        Flag.counter++;//incremento il contatore
        allocazioneMescolateSospetto(listaMescolate);
    }
    return listaMescolate;//valore di ritorno
}
ListaCarteMescolate* mescolateFinale(ListaCarteMescolate* listaMescolate){
    int h;//variabile indice
    int vectorFinale[VENTUNO]={0};//vettore d'appoggio settato a zero

    for(h=1; h<=DICIOTTO; h++){//cicla per h da 1 a 18 incluso
        do{
            Flag.random=MIN+rand()%(VENTI-MIN+1);//generazione casuale
        }while(vectorFinale[Flag.random]!=0);//cicla sinchè il vettore non è pieno

        if(!((Flag.vettoreCarteIncognita[0]==Flag.random)||(Flag.vettoreCarteIncognita[1]==Flag.random)||
            (Flag.vettoreCarteIncognita[2]==Flag.random))){//controllo random diverso da incognita

            vectorFinale[Flag.random]=h;//il vettore prende il valore di h
            listaMescolate->Id=Flag.random;//assegnamento valore random
            Flag.vettoreAppoggio2[h-1]=Flag.random;//assegnamento valore random a vettore appoggio

            #if DEBUG_MODE_ASSEGNAMENTO==1
                printf("\nn: %d\tId: %d", h, listaMescolate->Id);
            #endif // DEBUG_MODE_ASSEGNAMENTO
        }
        if((Flag.vettoreCarteIncognita[0]==Flag.random)||(Flag.vettoreCarteIncognita[1]==Flag.random)||
            (Flag.vettoreCarteIncognita[2]==Flag.random)){//se random uguale incognita decremento l'indice h
            h--;//decremento il contatore
        }
    }
    return listaMescolate;//valore restituito
}
ListaCarteGiocatore1* mazzoGiocatore1(int quoziente, ListaCarteGiocatore1* listaGiocatore1){

    if(Flag.counter<quoziente){//controllo se il contatore è minore del quoziente=18carte/numero_giocarori
        listaGiocatore1=(ListaCarteGiocatore1*)malloc(sizeof(ListaCarteGiocatore1));//allocazione dinamica mazzo carte giocatore
        if(listaGiocatore1==NULL) exit(-1);//verifica se l'allocazione è andata a buon fine

        listaGiocatore1->Id=Flag.vettoreAppoggio2[Flag.counter];//caricamento carta giocatore n-esimo
        Flag.vettoreGiocatore[UTENTE1][Flag.counter]=Flag.vettoreAppoggio2[Flag.counter];

        #if DEBUG_MODE_GIOCATORI==1
            printf("\nn: %d\tId: %d", Flag.counter+1, listaGiocatore1->Id);
        #endif // DEBUG_MODE_GIOCATORI
        Flag.counter++;//incremento il contatore
        mazzoGiocatore1(quoziente, listaGiocatore1);
    }
    return listaGiocatore1;
}
ListaCarteGiocatore2* mazzoGiocatore2(int quoziente, ListaCarteGiocatore2* listaGiocatore2){
    if(Flag.counter<quoziente){//controllo se il contatore è minore del quoziente=18carte/numero_giocarori
        listaGiocatore2=(ListaCarteGiocatore2*)malloc(sizeof(ListaCarteGiocatore2));//allocazione dinamica mazzo carte giocatore
        if(listaGiocatore2==NULL) exit(-1);//verifica se l'allocazione è andata a buon fine

        listaGiocatore2->Id=Flag.vettoreAppoggio2[Flag.counter+quoziente];//caricamento carta giocatore n-esimo
        Flag.vettoreGiocatore[UTENTE2][Flag.counter]=Flag.vettoreAppoggio2[Flag.counter+quoziente];

        #if DEBUG_MODE_GIOCATORI==1
            printf("\nn: %d\tId: %d", Flag.counter+1, listaGiocatore2->Id);
        #endif // DEBUG_MODE_GIOCATORI
        Flag.counter++;//incremento il contatore
        mazzoGiocatore2(quoziente, listaGiocatore2);
    }
    return listaGiocatore2;
}
ListaCarteGiocatore3* mazzoGiocatore3(int quoziente, ListaCarteGiocatore3* listaGiocatore3){

    if(Flag.counter<quoziente){//controllo se il contatore è minore del quoziente=18carte/numero_giocarori
        listaGiocatore3=(ListaCarteGiocatore3*)malloc(sizeof(ListaCarteGiocatore3));//allocazione dinamica mazzo carte giocatore
        if(listaGiocatore3==NULL) exit(-1);//verifica se l'allocazione è andata a buon fine

        listaGiocatore3->Id=Flag.vettoreAppoggio2[Flag.counter+(quoziente*2)];//caricamento carta giocatore n-esimo
        Flag.vettoreGiocatore[UTENTE3][Flag.counter]=Flag.vettoreAppoggio2[Flag.counter+(quoziente*2)];

        #if DEBUG_MODE_GIOCATORI==1
            printf("\nn: %d\tId: %d", Flag.counter+1, listaGiocatore3->Id);
        #endif // DEBUG_MODE_GIOCATORI
        Flag.counter++;//incremento il contatore
        mazzoGiocatore3(quoziente, listaGiocatore3);
    }
    return listaGiocatore3;
}
ListaCarteGiocatore4* mazzoGiocatore4(int quoziente, ListaCarteGiocatore4* listaGiocatore4){

    if(Flag.counter<quoziente){//controllo se il contatore è minore del quoziente=18carte/numero_giocarori
        listaGiocatore4=(ListaCarteGiocatore4*)malloc(sizeof(ListaCarteGiocatore4));//allocazione dinamica mazzo carte giocatore
        if(listaGiocatore4==NULL) exit(-1);//verifica se l'allocazione è andata a buon fine

        listaGiocatore4->Id=Flag.vettoreAppoggio2[Flag.counter+(quoziente*3)];//caricamento carta giocatore n-esimo
        Flag.vettoreGiocatore[UTENTE4][Flag.counter]=Flag.vettoreAppoggio2[Flag.counter+(quoziente*3)];

        #if DEBUG_MODE_GIOCATORI==1
            printf("\nn: %d\tId: %d", Flag.counter+1, listaGiocatore4->Id);
        #endif // DEBUG_MODE_GIOCATORI
        Flag.counter++;//incremento il contatore
        mazzoGiocatore4(quoziente, listaGiocatore4);
    }
    return listaGiocatore4;
}
ListaCarteGiocatore5* mazzoGiocatore5(int quoziente, ListaCarteGiocatore5* listaGiocatore5){

    if(Flag.counter<quoziente){//controllo se il contatore è minore del quoziente=18carte/numero_giocarori
        listaGiocatore5=(ListaCarteGiocatore5*)malloc(sizeof(ListaCarteGiocatore5));//allocazione dinamica mazzo carte giocatore
        if(listaGiocatore5==NULL) exit(-1);//verifica se l'allocazione è andata a buon fine

        listaGiocatore5->Id=Flag.vettoreAppoggio2[Flag.counter+(quoziente*4)];//caricamento carta giocatore n-esimo
        Flag.vettoreGiocatore[UTENTE5][Flag.counter]=Flag.vettoreAppoggio2[Flag.counter+(quoziente*4)];

        #if DEBUG_MODE_GIOCATORI==1
            printf("\nn: %d\tId: %d", Flag.counter+1, listaGiocatore5->Id);
        #endif // DEBUG_MODE_GIOCATORI
        Flag.counter++;//incremento il contatore
        mazzoGiocatore5(quoziente, listaGiocatore5);
    }
    return listaGiocatore5;
}
ListaCarteGiocatore6* mazzoGiocatore6(int quoziente, ListaCarteGiocatore6* listaGiocatore6){

    if(Flag.counter<quoziente){//controllo se il contatore è minore del quoziente=18carte/numero_giocarori
        listaGiocatore6=(ListaCarteGiocatore6*)malloc(sizeof(ListaCarteGiocatore6));//allocazione dinamica mazzo carte giocatore
        if(listaGiocatore6==NULL) exit(-1);//verifica se l'allocazione è andata a buon fine

        listaGiocatore6->Id=Flag.vettoreAppoggio2[Flag.counter+(quoziente*5)];//caricamento carta giocatore n-esimo
        Flag.vettoreGiocatore[UTENTE6][Flag.counter]=Flag.vettoreAppoggio2[Flag.counter+(quoziente*5)];

        #if DEBUG_MODE_GIOCATORI==1
            printf("\nn: %d\tId: %d", Flag.counter+1, listaGiocatore6->Id);
        #endif // DEBUG_MODE_GIOCATORI
        Flag.counter++;//incremento il contatore
        mazzoGiocatore6(quoziente, listaGiocatore6);
    }
    return listaGiocatore6;
}
#endif // SUBROUTINELISTE_H_INCLUDED
