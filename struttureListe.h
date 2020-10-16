#ifndef STRUTTURELISTE_H_INCLUDED
#define STRUTTURELISTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define DEBUG_MODE_ASSEGNAMENTO 0
#define DEBUG_MODE_MESCOLAMENTO 0
#define DEBUG_MODE_ASSEGNAMENTO2 0
#define DEBUG_MODE_MESCOLAMENTO2 0
#define DEBUG_MODE_INCOGNITA 0
#define DEBUG_MODE_GIOCATORI 0
#define DEBUG_MODE_DADO 0
#define DEBUG_MODE_IPOTESI 0
#define ZERO 0
#define UNO 1
#define DUE 2
#define TRE 3
#define SEI 6
#define NOVE 9
#define DICIASETTE 17
#define DICIOTTO 18
#define VENTI 20
#define VENTUNO 21
#define MAX_STR 24
#define MIN_ARMA 9
#define MAX_ARMA 14
#define MIN_STANZA 0
#define MAX_STANZA 8
#define MIN_SOSPETTO 15
#define MAX_SOSPETTO 20
#define MIN 0
#define MAX_SEI 6
#define MAX_OTTO 8
#define MAX_NOVE 9
#define MIN_DADO 1
#define MAX_DADO 6

typedef struct{//struttura vettore statico carte da gioco
    int Id;//numero identificativo
    int tipo;//tipo carta
    char stringaCarte[MAX_STR+1];//stringa carta da gioco
}CarteGioco;

struct listaCarteGiocatore1{//lista carte dei giocatori 1
    int Id;//numero identificativo
    struct listaCarteGiocatore1* next;//nodo successivo
};
typedef struct listaCarteGiocatore1 ListaCarteGiocatore1;

struct listaCarteGiocatore2{//lista carte dei giocatori 2
    int Id;//numero identificativo
    struct listaCarteGiocatore2* next;//nodo successivo
};
typedef struct listaCarteGiocatore2 ListaCarteGiocatore2;

struct listaCarteGiocatore3{//lista carte dei giocatori 3
    int Id;//numero identificativo
    struct listaCarteGiocatore3* next;//nodo successivo
};
typedef struct listaCarteGiocatore3 ListaCarteGiocatore3;

struct listaCarteGiocatore4{//lista carte dei giocatori 4
    int Id;//numero identificativo
    struct listaCarteGiocatore4* next;//nodo successivo
};
typedef struct listaCarteGiocatore4 ListaCarteGiocatore4;

struct listaCarteGiocatore5{//lista carte dei giocatori 5
    int Id;//numero identificativo
    struct listaCarteGiocatore5* next;//nodo successivo
};
typedef struct listaCarteGiocatore5 ListaCarteGiocatore5;

struct listaCarteGiocatore6{//lista carte dei giocatori 6
    int Id;//numero identificativo
    struct listaCarteGiocatore6* next;//nodo successivo
};
typedef struct listaCarteGiocatore6 ListaCarteGiocatore6;

struct listaArma{//lista carte da gioco assegnate
    int Id;//numero identificativo
    struct listaArma* next;//nodo successivo
};
typedef struct listaArma ListaArma;

struct listaSospetto{//lista carte da gioco assegnate
    int Id;//numero identificativo
    struct listaSospetto* next;//nodo successivo
};
typedef struct listaSospetto ListaSospetto;

struct listaStanza{//lista carte da gioco assegnate
    int Id;//numero identificativo
    struct listaStanza* next;//nodo successivo
};
typedef struct listaStanza ListaStanza;

struct listaCarteMescolate{//lista carte da gioco mescolate ed unite in un unico mazzo
    int Id;//numero identificativo
    struct listaCarteMescolate* next;//nodo successivo
};
typedef struct listaCarteMescolate ListaCarteMescolate;

struct listaCarteIncognita{//lista 3 carte incognita
    int Id;//numero identificativo
    struct listaCarteIncognita* next;//nodo successivo
};
typedef struct listaCarteIncognita ListaCarteIncognita;

typedef struct{//struttura flag
    int counter;//contatore
    int counter2[SEI];//contatore utente
    int random;//variabile random
    int vinto;//numero del giocatore che ha vinto
    int resto;//numero carte rimaste
    int quoziente;//numero carte di ciascun giocatore
    int vettoreAppoggio1[VENTUNO];//vettore appoggio da 3 mazzi mescolati a 21-3 carte
    int vettoreAppoggio2[DICIOTTO];//vettore appoggio da 18 carte a n liste giocatori
    int vettoreGiocatore[SEI][SEI];//flag carta giocatore
    int numeroGiocatori;//numero giocatori
    int vettoreCarteRimaste[TRE];//vettore che memorizza le carte rimaste dei giocatori
    int vettoreCarteIncognita[TRE];//vettore che memorizza le carte incognita
    _Bool cartaTrovata[SEI][TRE];//flag carta giocatore trovata uguale a ipotesi
    _Bool giocatoreVinto;//booleano per sapere se qualcuno ha vinto
    _Bool caricaPartita;//flag per sapere se sto caricando una partita
}Variabili;
Variabili Flag;

typedef struct{//struttura giocatori
    int stanzaGiocatore[SEI];//stanza in cui si trova il giocatore
    int numeroCarteGiocatore[SEI];//numero carte giocatore
    int turnoIniziale;//turno di inizio
    int numeroTurni;//numero di turno
    int giocatoreCorrente;//giocatore corrente
    int stanzaIpotizzata[SEI];//stanza ipotizzata
    int armaIpotizzata[SEI];//arma ipotizzata
    int sospettoIpotizzato[SEI];//sospetto ipotizzato
    int confuta[SEI][TRE];//giocatore che confuta l'ipotesi
    _Bool ipotesiCorretta[SEI];//formulazione ipotesi corretta
    _Bool ipotesiNonCorretta[SEI];
    char nomeGiocatore[SEI][MAX_STR+1];//nome giocatori
}GestioneGiocatori;
GestioneGiocatori *Utente;

typedef enum{ARMA, SOSPETTO, STANZA} Tipologia;//enumerazione tipologia carta
typedef enum{LAB_T, LAB_M, BAGNO, AULA_COSTA, GIARDINO, ENTRATA, PARCHEGGIO, SIMAZ, BATCAVERNA} TipoStanza;//enumerazione stanza
typedef enum{UTENTE1, UTENTE2, UTENTE3, UTENTE4, UTENTE5, UTENTE6} Utenza;//Utenti giocatori

ListaArma* listaArma=NULL;//puntatore lista arma
ListaSospetto* listaSospetto=NULL;//puntatore lista sospetto
ListaStanza* listaStanza=NULL;//puntatore lista stanza
ListaCarteMescolate* listaMescolate=NULL;//puntatore lista 18 carte mescolate
ListaCarteIncognita* listaIncognita=NULL;//puntatore lista incognita
ListaCarteGiocatore1* listaGiocatore1=NULL;//puntatore lista carte giocatore 1
ListaCarteGiocatore2* listaGiocatore2=NULL;//puntatore lista carte giocatore 2
ListaCarteGiocatore3* listaGiocatore3=NULL;//puntatore lista carte giocatore 3
ListaCarteGiocatore4* listaGiocatore4=NULL;//puntatore lista carte giocatore 4
ListaCarteGiocatore5* listaGiocatore5=NULL;//puntatore lista carte giocatore 5
ListaCarteGiocatore6* listaGiocatore6=NULL;//puntatore lista carte giocatore 6

#endif // STRUTTURELISTE_H_INCLUDED
