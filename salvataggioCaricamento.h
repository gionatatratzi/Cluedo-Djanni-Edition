#ifndef SALVATAGGIOCARICAMENTO_H_INCLUDED
#define SALVATAGGIOCARICAMENTO_H_INCLUDED

void salvataggioPartita(void){
    FILE *save=NULL;//puntatore al file di salvataggio
    char nomeFile[MAX_STR+1]="partita.sav";//nome file salvataggio

    save=fopen(nomeFile, "wb");//apertura file salvataggio

    //utenti giocatori
    fwrite(&Utente->giocatoreCorrente, sizeof(int), 1, save);
    fwrite(&Utente->numeroTurni, sizeof(int), 1, save);

    //flag giocatori
    fwrite(&Flag.numeroGiocatori, sizeof(int), 1, save);
    fwrite(Flag.vettoreAppoggio1, sizeof(int), VENTUNO, save);
    fwrite(Flag.vettoreAppoggio2, sizeof(int), DICIOTTO, save);

    //salvataggio giocatori
    fwrite(Utente->nomeGiocatore, sizeof(char), Flag.numeroGiocatori*(MAX_STR+1), save);
    fwrite(Utente->stanzaGiocatore, sizeof(int), Flag.numeroGiocatori, save);
    fwrite(Utente->ipotesiCorretta, sizeof(_Bool), Flag.numeroGiocatori, save);

    fclose(save);//chiusura file salvataggio
}
void caricamentoPartita(void){
    FILE *load=NULL;//puntatore al file di caricamento
    char nomeFile[MAX_STR+1]="partita.sav";//nome file caricamento

    load=fopen(nomeFile, "rb");//apertura file caricamento

    //utenti giocatori
    fread(&Utente->giocatoreCorrente, sizeof(int), 1, load);
    fread(&Utente->numeroTurni, sizeof(int), 1, load);

    //flag giocatori
    fread(&Flag.numeroGiocatori, sizeof(int), 1, load);
    fread(Flag.vettoreAppoggio1, sizeof(int), VENTUNO, load);
    fread(Flag.vettoreAppoggio2, sizeof(int), DICIOTTO, load);

    //caricamento giocatori
    fread(Utente->nomeGiocatore, sizeof(char), Flag.numeroGiocatori*(MAX_STR+1), load);
    fread(Utente->stanzaGiocatore, sizeof(int), Flag.numeroGiocatori, load);
    fread(Utente->ipotesiCorretta, sizeof(_Bool), Flag.numeroGiocatori, load);

    fclose(load);//chiusura file caricamento
}
#endif // SALVATAGGIOCARICAMENTO_H_INCLUDED
