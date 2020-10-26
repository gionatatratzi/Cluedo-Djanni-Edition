# CluedoDjanniEdition
Progetto finale di programmazione 1: cluedo djanni edition

FUNZIONALITÀ BASE 20/30

Il gioco deve replicare il famoso gioco da tavolo CLUEDO, con alcune varianti come specificato nel
seguente documento.
Il gioco è ambientato nei locali del Palazzo delle Scienze e lo scopo dei giocatori (numero scelto
dall’utente da 3 a 6) è indagare sulla misteriosa uccisione del famoso gatto Djanni. I principali sospetti
sono stati fermati e identificati, anche le possibili armi del delitto sono state catalogate e depositate.
I vari giocatori durante il gioco dovranno formulare le ipotesi del delitto del tipo: il sospettato ha ucciso
Djanni nella stanza con l’arma e gli altri giocatori confuteranno o confermeranno tale ipotesi.
Vince il giocatore che per primo indovinerà la tripla: sospetto , stanza e arma .

1. ARMI:
Cavo di rete, Sparacoriandoli, Tastiera USB, Fumo della caldaia, Floppy disk 3.5, Calcinaccio
2. SOSPETTI:
A. Turing, G. F. Voronoj, J. V. Neumann, E. Dijkstra, M. Hamilton, G. M. Hopper,
3. STANZE
Lab. T, Lab. M, Batcaverna, SimAz, Aula Costa, Entrata, Parcheggio, Bagno, Giardino

Avviando una nuova partita, nella prima fase del gioco deve essere chiesto il numero di giocatori (da 3
a 6) e il nome di ognuno.
All’inizio del gioco ogni mazzo di carte viene dapprima rappresentato in un vettore statico di strutture
per poi essere caricato all’interno di una lista (verrà creata una lista per ogni mazzo). Successivamente
ogni lista deve essere mescolata e da ognuna di esse deve essere presa la prima carta e caricata
all’interno di un’altra lista contenente le carte incognite (un’arma, un sospetto e una stanza).
Le carte rimaste dovranno poi essere unite in un singolo mazzo (ovvero un’unica lista) che dovrà
essere mescolato nuovamente per poi distribuire le carte in modo uguale a tutti i giocatori. Eventuali
carte in più dovranno essere mostrate a tutti i giocatori.
Le carte di ogni giocatore devono essere memorizzate in una lista.

Ogni carta è rappresentata da una struttura contenente la tipologia della carta (definita tramite
enumerazione: ARMA=0, SOSPETTO=1, STANZA=2) e il nome della stessa sotto forma di stringa
(23+1 caratteri).
I giocatori devono essere posizionati random in una stanza del Palazzo e per muoversi possono
lanciare due dadi da sei. Il giocatore iniziale deve essere scelto casualmente, poi si seguirà l’ordine dei
giocatori inseriti in precedenza. I dati dei giocatori devono essere memorizzati in un’apposita struttura
e memorizzati in un array allocato dinamicamente.
Una volta iniziato il gioco, ad ogni turno si stamperà il numero del turno, il nome del giocatore corrente
e dove egli si trova all’interno del tabellone. In questo momento del gioco dovrà essere permesso al
giocatore di salvare la partita all’interno di un file binario (chiamato “partita.sav”).
Una volta stampate queste informazioni dovrà essere chiesto all’utente se voglia provare a indovinare
le incognite o se voglia spostarsi in un’altra stanza. Nel primo caso verrà data la possibilità di formulare
l’ipotesi. Tale ipotesi può essere fatta su TUTTI i sospetti, TUTTE le armi ma obbligatoriamente nella
stanza in cui si trova il giocatore. Richieste queste informazioni, dovranno essere controllate tutte le
carte dei giocatori restanti, un giocatore alla volta, per verificare l’ipotesi del giocatore.
Appena si trova una carta che non soddisfa tale ipotesi, si interromperà il controllo degli altri giocatori
e si dovrà stampare un messaggio del tipo “L’ipotesi è errata.” visibile a tutti i giocatori. Dovrà poi
essere visualizzata SOLO al giocatore corrente la carta che ha confutato l’ipotesi (si faccia in modo che
se il giocatore che confuta l’ipotesi ha più carte sia esso stesso a scegliere quale mostrare).

Nel caso in cui nessun giocatore confuti l’ipotesi il giocatore che ha indovinato la tripla dovrà ottenere
al prossimo turno di lancio due dadi con lo stesso valore. Questo serve per recarsi nella cantina dove
potrà terminare il gioco. Se non viene effettuato un lancio di dadi doppi il turno passa al giocatore
successivo che cercherà quindi di recarsi nella stanza dove è avvenuto il delitto, formulare l’ipotesi e
fare un lancio doppio prima del o dei giocatori avversari.
Nel caso in cui un giocatore formuli un’ipotesi contenente una delle sue carte, il programma dopo aver
controllato tutti i giocatori seguendo l’ordine di gioco stamperà lo stesso messaggio di ipotesi errata. In
questo modo sarà chiaro che il giocatore stia bluffando. Non dovrà però essere mostrata a nessuno la
carta che ha reso l’ipotesi errata.
Nel caso in cui il giocatore voglia spostarsi in un’altra stanza dovrà essere effettuato un lancio di due
dadi e sulla base del risultato e della posizione del giocatore dovranno essere mostrate le stanze in cui
può recarsi (potrebbe non essercene neanche una raggiungibile e in quel caso il turno passa al
giocatore successivo dopo aver comunque dato la possibilità al giocatore di formulare l’ipotesi). Tra
quelle raggiungibili l’utente sceglierà quella in cui recarsi e potrà formulare o meno la sua ipotesi.
Nel caso in cui venga caricata una partita esistente da un file binario (chiamato “partita.sav”) dovranno
essere ovviamente saltati i passaggi iniziali per proseguire direttamente con il turno di gioco.

FUNZIONALITÀ MEDIE 10/30

Per consegnare il progetto e ambire al voto massimo devono essere implementate le seguenti
funzionalità.
Il nome del file da caricare/salvare deve essere scelto dall’utente.
Creazione di un taccuino virtuale, ad ogni giocatore deve essere associato un taccuino contenente le
combinazioni di arma, sospetto e stanza già ipotizzate. Non ci sono specifiche stringenti, in linea di
massima deve essere possibile per il giocatore capire quali siano le armi, i sospetti o le stanze che non
possono essere presenti tra le incognite. Ogni taccuino deve essere memorizzato in una opportuna
struttura e deve essere uno per giocatore. Al momento del salvataggio tutti i taccuini virtuali dovranno
essere memorizzati su un file (binario o testuale) separato. Fare molta attenzione alla lettura, se il file
non esiste quando viene caricata la partita il gioco deve proseguire senza alcun problema creando da
zero tali taccuini.
Creazione di un logger che scriva su un file di testo tutti gli eventi della partita, ad esempio:

1. TURNO 6 Fabio ha lanciato i dati, ha fatto 5+3
2. TURNO 6 Fabio si è spostato il Laboratorio T
3. TURNO 6 Fabio ha detto che A. Turing ha ucciso Djanni in Laboratorio T con la Tastiera USB.
4. TURNO 6 Riccardo ha smentito l’ipotesi facendo vedere a Fabio la carta Laboratorio T.
5. TURNO 7 È il turno di Alessandro
6. TURNO 7 Alessandro ha lanciato i dadi, ha fatto 2+2

FUNZIONALITÀ AVANZATE 6/30

Per consegnare il progetto e ambire al bonus del progetto devono essere implementate le seguenti
funzionalità.
Dare la possibilità di eseguire la partita in modalità automatica, il tester dovrà solamente specificare il
numero di giocatori e la partità dovrà essere eseguita richiedendo ad ogni turno di salvare o meno la
partita. In questa modalità dovranno essere mostrati in chiaro tutti i dati della partita, le carte
distribuite, le incognite, le carte dei giocatori e le scelte delle ipotesi che dovranno essere fatte in
modo casuale ma seguendo comunque la logica del gioco. Ovvero tutti i giocatori, comandati dal
computer, dovranno cercare di vincere la partita.
Maggiore sarà la fedeltà dell’intelligenza artificiale rispetto al comportamento umano più alta sarà la
valutazione.
Dopo ogni partita aggiornare un file con le statistiche che permetta di stabilire il numero di volte che i
vari sospetti, le armi e le stanze siano stati tra le incognite. Visualizzare tale file prima di ogni nuova
partita.

STRUTTURA FILE DI SALVATAGGIO
1. un intero rappresentante il giocatore corrente un intero rappresentante il numero di turni
2. un intero rappresentante il numero di giocatori un blocco per giocatore, contenente:
3. una stringa del nome giocatore (24 char)
4. un intero rappresentante la stanza in cui si trova il giocatore
5. un intero di flag che indica se il giocatore ha formulato l’ipotesi corretta (0: no, 1: si)
6. un intero rappresentante il numero delle carte del giocatore
7. un blocco per ogni carta giocatore, contenente:
8. il tipo della carta (enum)
9. una stringa della frase riportata sulla carta (24 char)
10. un intero rappresentante le carte scoperte un blocco per ogni carta scoperta, contenente:
11. il tipo della carta (enum)
12. una stringa della frase riportata sulla carta (24 char)
13. un blocco per ogni carta incognita (3), contenente:
14. il tipo della carta (enum)
15. una stringa della frase riportata sulla carta (24 char)
