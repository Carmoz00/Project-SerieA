# Project-SerieA

**Autore:** Carmelo Panepinto

**Descrizione:**  
Questo progetto è un simulatore del campionato di Serie A 2023/2024, sviluppato in C++ con Embarcadero. Il programma sfrutta statistiche e probabilità matematiche per simulare in modo verosimile le partite e il prosieguo del campionato, gestendo squadre, giocatori, formazioni, statistiche individuali e di squadra (goal, assist, risultati, classifica) e calendario delle giornate.

## Funzionalità Principali

- **Gestione Squadre e Giocatori:**  
  - Definizione di classi `Giocatore` e `Squadra` con attributi come nome, ruolo, valore, condizioni fisiche, e statistiche (goal, assist, partite giocate).
  - Aggiornamento e visualizzazione delle informazioni individuali dei giocatori.
  - Calcolo e scelta della formazione titolare in base ai ruoli e alle valutazioni dei giocatori.

- **Calendario e Simulazione Partite:**  
  - Generazione del calendario di incontri (in casa e in trasferta) per le 38 giornate di campionato.
  - Simulazione della partita tra due squadre basata su probabilità definite dalle medie delle statistiche reparti (attacco, centrocampo, difesa, portieri).
  - Aggiornamento del punteggio, risultati e statistiche (goal fatti, goal subiti) in base all'esito di ogni partita.

- **Classifiche e Statistiche:**  
  - Calcolo e ordinamento della classifica generale delle squadre in base ai punti ottenuti.
  - Classifica individuale dei marcatori e degli assist, visualizzabili a schermo.
  - Modalità di visualizzazione personalizzabili: informazioni complete (con formazione, marcatori, assist), parziali o nessuna informazione durante le partite.

## Requisiti

- **Compilatore C++:**  
  Il progetto è stato sviluppato, compilato ed eseguito con Embarcadero. È possibile anche utilizzare altri compilatori conformi allo standard C++.
  
- **Ambiente:**  
  Windows (consigliato per Embarcadero), Linux o macOS.

## Istruzioni di Compilazione

### Utilizzo di Embarcadero

Apri il progetto nell'IDE Embarcadero e segui le istruzioni standard per la compilazione all'interno dell'ambiente.

### Utilizzo di GCC (opzionale)

Se preferisci compilare da riga di comando, ad esempio in ambiente Unix-like, puoi utilizzare un comando simile a questo:

```bash
g++ -o Project_SerieA main.cpp -std=c++11 -Wall -Wextra
```
# Istruzioni di Esecuzione

Una volta compilato il progetto, esegui il programma. Ad esempio, se lo hai compilato con GCC:

```bash
./Project_SerieA
```

Il programma mostrerà a video:
- Le istruzioni iniziali.
- Le opzioni per visualizzare le informazioni sulle partite (modalità complete, parziali o senza informazioni).
- La possibilità di interagire per visualizzare statistiche e classifica durante il campionato.

---

## Struttura del Codice

### Classi Principali

#### **Giocatore**
Gestisce i dati e le statistiche individuali:
- Nome, ruolo, valore.
- Condizione fisica.
- Partite giocate, goal e assist.

#### **Squadra**
Contiene:
- Un vettore di giocatori.
- La formazione.
- Le medie delle valutazioni per reparto.
- Le statistiche di squadra (punteggio, risultati, goal fatti/subiti).

Include metodi per:
- Aggiornare la formazione.
- Determinare i titolari.
- Visualizzare le informazioni.

#### **Campionato**
Gestisce:
- L'insieme delle squadre.
- Il calendario delle giornate.
- Le classifiche (generale, marcatori, assist).
- La simulazione delle partite.

---

### Logica di Simulazione

La funzione `partita()` simula una partita tra due squadre. Durante la simulazione:
- Calcola probabilità e statistiche per aggiornare goal, assist e risultato finale.
- Aggiorna i punteggi delle squadre.
- Stampa le informazioni in base alla modalità selezionata.

---

### Interazione con l'Utente

Nel `main()`, l'utente può scegliere come interagire con il simulatore:

1. **Visualizzare informazioni**:
   - Delle squadre.
   - Dei giocatori.

2. **Consultare classifiche**:
   - Generale.
   - Marcatori.
   - Assist.

3. **Simulare**:
   - Giornata per giornata.
   - Direttamente l'intero campionato.

---

## Possibili Miglioramenti

### Ottimizzazione della Simulazione
Migliorare i calcoli delle probabilità per rendere la simulazione ancora più verosimile.

### Gestione delle Informazioni
Integrare una modalità grafica o un'interfaccia utente più intuitiva per la visualizzazione dei risultati.

### Espansione delle Statistiche
Aggiungere ulteriori funzionalità analitiche, come:
- Grafici di performance.
- Report pre/post partita.

---

## Note Finali

Il progetto è stato realizzato con un forte focus sulla simulazione realistica del campionato utilizzando concetti matematici e probabilistici, combinati con la gestione completa delle squadre e dei giocatori in un ambiente orientato agli oggetti.

Se riscontri problemi o hai suggerimenti, sentiti libero di aprire una issue nel repository.
