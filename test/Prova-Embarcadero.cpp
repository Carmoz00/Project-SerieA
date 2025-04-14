//Autore: Carmelo Panepinto - Simulatore Calcio Serie A 2023/2024
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <math.h>
#include <algorithm>
#include <random>
#include <ctime>
#include <set>
#include <numeric>
#define N_GIOCATORI 25
#define N_SQUADRE 20
#define N_TITOLARI 11
#define N_GIORNATE 38

using namespace std;

class Giocatore {

    private:
        string nome;
        float valore;
        string ruolo;
        string squadra;

    public:
        int condizioneFisica = 10;
        int partiteGiocate = 0;
        int goal = 0;
        int assist  = 0;

    //Metodi
        //Costruttore
    Giocatore(string newNome, float newValore, string newRuolo, string newSquadra) {
        nome=newNome;
        valore=newValore;
        ruolo=newRuolo;
        squadra=newSquadra;
    }

        //GETTER E SETTER
    string getNome() const{
        return nome;
    }
    void setNome(string newNome){
        nome=newNome;
        cout<<endl<<"-- Nome modificato! --"<<endl<<endl;
    }

    float getValore() const{
        return valore;
    }
    void setValore(float newValore){
        valore=newValore;
        cout<<endl<<"-- Valore modificata! --"<<endl<<endl;
    }

    string getRuolo() const{
        return ruolo;
    }
    void setRuolo(string newRuolo){
        ruolo=newRuolo;
        cout<<endl<<"-- Ruolo modificato! --"<<endl<<endl;
    }
    
    string getSquadra() const{
        return squadra;
    }

    void setSquadra(string newSquadra){
        squadra=newSquadra;
        cout<<endl<<"-- Squadra modificata --"<<endl<<endl;
    }
    
    void aggiornaGiocatore(string newNome, float newValore, string newRuolo, string newSquadra) {
        nome=newNome;
        valore=newValore;
        ruolo=newRuolo;
        squadra=newSquadra;

        cout<<endl<<"-- Giocatore "<<newNome<<" aggiornato! --"<<endl<<endl;
    }

    void infoGiocatore(){
        cout<<endl;
        cout<<"--- Informazioni sul giocatore:" << endl;
        cout<<"Nome: "<<nome<<endl<<"Valore: "<<valore<<endl<<"Ruolo: "<<ruolo<<endl<<"Squadra: "<<squadra<<endl;
        cout<<"Condizione Fisica: "<<condizioneFisica<<endl<<"Partite Giocate: "<<partiteGiocate<<endl<<"Goal: "<<goal<<endl<<"Assist: "<<assist<<endl;
        cout<<endl<<endl;
    }
};

class Squadra {

    private:
        string squadraNome;
        vector <Giocatore> squadra; 
        array <int, 3> formazione;

    public:
        bool infoComplete = false;
        bool infoParziali = false;
        bool noInfo = false;
        array <int, N_TITOLARI> titolari;
        float mediaPortieri = 0;
        float mediaDifensori = 0;
        float mediaCentrocampisti = 0;
        float mediaAttaccanti = 0;
        mutable int punteggio = 0;
        int partiteGiocate=0;
        int risultati[3]={0, 0, 0}; //vittorie, pareggi, sconfitte
        int goalFatti=0;
        int goalSubiti=0;

    //----Metodi----

    Squadra(string nome) : squadraNome(nome){};

    void getGiocatore(string nomeSquadra, string nomeGiocatore){
        for (int i=0; i<squadra.size(); i++){
            if (squadraNome == nomeSquadra){

            }
        }
    }

    void infoGiocatore(int index){
        squadra[index].infoGiocatore();
    }

    void infoGiocatore(string newNome){
        for (int i=0; i<squadra.size(); i++){
            if (squadra[i].getNome() == newNome){
                squadra[i].infoGiocatore();
            }
        }
    }

    void aggiornaGiocatore(int index, string newNome, float newValore, string newRuolo, string newSquadra){
        squadra[index].aggiornaGiocatore(newNome, newValore, newRuolo, newSquadra);
    }

    Giocatore& getGiocatore(int indiceGiocatore) {
            return squadra.at(indiceGiocatore);
        }

    Giocatore& getGiocatore(string nomeGiocatore) {
            for (int i = 0; i < squadra.size(); i++) {
                if (squadra[i].getNome() == nomeGiocatore) {
                    return squadra[i];
                }
            }
            throw invalid_argument("Giocatore non trovato");
        }

    int getPunteggio() const{
        return punteggio;
    }

    void setPunteggio(int newPunteggio){
        punteggio=newPunteggio;
    }

    void calcolaFormazione() {
        array<int, 3> defaultFormazione = {4, 3, 3}; // formazione di default
        array<array<int, 3>, 7> formazioniPossibili = {{
            {3, 4, 3}, {3, 5, 2}, {4, 3, 3}, {4, 4, 2}, {4, 5, 1}, {5, 3, 2}, {5, 4, 1}
        }};
        
        float accValutazioneDifensori = 0;
        float accValutazioneCentrocampisti = 0;
        float accValutazioneAttaccanti = 0;
        int numeroDifensori = 0;
        int numeroCentrocampisti = 0;
        int numeroAttaccanti = 0;
        float valutazioneMediaDifensori = 0;
        float valutazioneMediaCentrocampisti = 0;
        float valutazioneMediaAttaccanti = 0;

        for (int i = 0; i < squadra.size(); i++) {
            if (squadra[i].getRuolo() == "Difensore") {
                accValutazioneDifensori += (squadra[i].getValore() + squadra[i].condizioneFisica);
                numeroDifensori++;
            } else if (squadra[i].getRuolo() == "Centrocampista") {
                accValutazioneCentrocampisti += (squadra[i].getValore() + squadra[i].condizioneFisica);
                numeroCentrocampisti++;
            } else if (squadra[i].getRuolo() == "Attaccante") {
                accValutazioneAttaccanti += (squadra[i].getValore() + squadra[i].condizioneFisica);
                numeroAttaccanti++;
            }
        }

        if (numeroDifensori > 0) valutazioneMediaDifensori = accValutazioneDifensori / numeroDifensori;
        if (numeroCentrocampisti > 0) valutazioneMediaCentrocampisti = accValutazioneCentrocampisti / numeroCentrocampisti;
        if (numeroAttaccanti > 0) valutazioneMediaAttaccanti = accValutazioneAttaccanti / numeroAttaccanti;

        array<float, 7> valutazioniFormazioni;
        for (int i = 0; i < formazioniPossibili.size(); i++) {
            int difensori = formazioniPossibili[i][0];
            int centrocampisti = formazioniPossibili[i][1];
            int attaccanti = formazioniPossibili[i][2];

            if (difensori <= numeroDifensori && centrocampisti <= numeroCentrocampisti && attaccanti <= numeroAttaccanti) {
                float valutazioneMediaFormazione =
                    (valutazioneMediaDifensori * difensori +
                    valutazioneMediaCentrocampisti * centrocampisti +
                    valutazioneMediaAttaccanti * attaccanti) /
                    (difensori + centrocampisti + attaccanti);
                valutazioniFormazioni[i] = valutazioneMediaFormazione;
            } else {
                valutazioniFormazioni[i] = 0; // formazione non valida se mancano giocatori
            }
        }

        int indiceMiglioreFormazione = 0;
        float miglioreValutazione = valutazioniFormazioni[0];
        for (int i = 1; i < valutazioniFormazioni.size(); i++) {
            if (valutazioniFormazioni[i] > miglioreValutazione) {
                miglioreValutazione = valutazioniFormazioni[i];
                indiceMiglioreFormazione = i;
            }
        }

        formazione = formazioniPossibili[indiceMiglioreFormazione];
    }

    string getsquadraNome() const{
        return squadraNome;
    }
     int size() const {
            return squadra.size();
        }
    void setsquadraNome(string newSquadraNome){
        squadraNome=newSquadraNome;
        cout<<endl<<"-- Nome squadra modificato --"<<endl<<endl;
    }

    array<int, 3> getFormazione() const{
        array<int, 3> newFormazione;
        for (int i=0; i<3; i++){
            newFormazione[i]=formazione[i];
        }
        return newFormazione;
    }

    void composizioneTitolari(array<int, 3> formazione) {
        

        int temp;
        int numDifensori = formazione[0];
        int numCentrocampisti = formazione[1];
        int numAttaccanti = formazione[2];
        float valutazione1 = 0;
        float valutazione2 = 0;
        // Portieri
        vector<int> tempPortieri;
        for (int i = 0; i < squadra.size(); i++) {
            if (squadra[i].getRuolo() == "Portiere" && squadra[i].condizioneFisica > 0) {
                tempPortieri.push_back(i);
            }
        }
        sort(tempPortieri.begin(), tempPortieri.end(), [&](int a, int b) {
            return (squadra[a].getValore() + squadra[a].condizioneFisica) > (squadra[b].getValore() + squadra[b].condizioneFisica);
        });

        // Difensori
        vector<int> tempDifensori;
        for (int i = 0; i < squadra.size(); i++) {
            if (squadra[i].getRuolo() == "Difensore" && squadra[i].condizioneFisica > 0) {
                tempDifensori.push_back(i);
            }
        }
        sort(tempDifensori.begin(), tempDifensori.end(), [&](int a, int b) {
            return (squadra[a].getValore() + squadra[a].condizioneFisica) > (squadra[b].getValore() + squadra[b].condizioneFisica);
        });

        // Centrocampisti
        vector<int> tempCentrocampisti;
        for (int i = 0; i < squadra.size(); i++) {
            if (squadra[i].getRuolo() == "Centrocampista" && squadra[i].condizioneFisica > 0) {
                tempCentrocampisti.push_back(i);
            }
        }
        sort(tempCentrocampisti.begin(), tempCentrocampisti.end(), [&](int a, int b) {
            return (squadra[a].getValore() + squadra[a].condizioneFisica) > (squadra[b].getValore() + squadra[b].condizioneFisica);
        });

        // Attaccanti
        vector<int> tempAttaccanti;
        for (int i = 0; i < squadra.size(); i++) {
            if (squadra[i].getRuolo() == "Attaccante" && squadra[i].condizioneFisica > 0) {
                tempAttaccanti.push_back(i);
            }
        }
        sort(tempAttaccanti.begin(), tempAttaccanti.end(), [&](int a, int b) {
            return (squadra[a].getValore() + squadra[a].condizioneFisica) > (squadra[b].getValore() + squadra[b].condizioneFisica);
        });

        // Inserimento titolari in array titolari
        if (!tempPortieri.empty()) {
            titolari[0] = tempPortieri[0];
        }
        for (int i = 0; i < numDifensori; i++) {
            if (i < tempDifensori.size()) {
                titolari[i + 1] = tempDifensori[i];
            }
        }
        for (int i = 0; i < numCentrocampisti; i++) {
            if (i < tempCentrocampisti.size()) {
                titolari[i + 1 + numDifensori] = tempCentrocampisti[i];
            }
        }
        for (int i = 0; i < numAttaccanti; i++) {
            if (i < tempAttaccanti.size()) {
                titolari[i + 1 + numDifensori + numCentrocampisti] = tempAttaccanti[i];
            }
        }

        partiteGiocate++; // aumento partite giocate della squadra

        // aggiornamento statistiche
        set<int> titolariSet(titolari.begin(), titolari.end());
        for (int i = 0; i < squadra.size(); i++) {
            if (titolariSet.find(i) != titolariSet.end()) { // titolari
                squadra[i].partiteGiocate++;
                squadra[i].condizioneFisica = max(0, squadra[i].condizioneFisica - 2);
            } else { // non titolari
                squadra[i].condizioneFisica = min(10, squadra[i].condizioneFisica + 3);
            }
        }
        
        // Stampa titolari
        if (infoComplete) {
            cout << endl;
            cout << "Formazione titolare per la squadra " << squadraNome << ": " << endl;
            cout << "---------- Formazione: " << formazione[0] << "-" << formazione[1] << "-" << formazione[2] << " ----------" << endl;
            cout << "Portiere: " << squadra[titolari[0]].getNome() << endl;
            cout << "Difensori: ";
            for (int i = 1; i < numDifensori + 1; i++) {
                cout << squadra[titolari[i]].getNome();
                if (i < numDifensori) {
                    cout << ", ";
                } else {
                    cout << "." << endl;
                }
            }
            cout << "Centrocampisti: ";
            for (int i = 1 + numDifensori; i < numDifensori + numCentrocampisti + 1; i++) {
                cout << squadra[titolari[i]].getNome();
                if (i < numDifensori + numCentrocampisti) {
                    cout << ", ";
                } else {
                    cout << "." << endl;
                }
            }
            cout << "Attaccanti: ";
            for (int i = 1 + numDifensori + numCentrocampisti; i < numDifensori + numCentrocampisti + numAttaccanti + 1; i++) {
                cout << squadra[titolari[i]].getNome();
                if (i < numDifensori + numCentrocampisti + numAttaccanti) {
                    cout << ", ";
                } else {
                    cout << "." << endl;
                }
            }
            cout << endl << endl;
        }
        else if (infoParziali) {
            cout << endl;
            //cout << "Formazione titolare per la squadra " << squadraNome << ": "<< formazione[0] << "-" << formazione[1] << "-" << formazione[2] <<endl;
        }
        else if (noInfo) cout<<endl;
    }
    
    void azzeraTitolari(){
        titolari = {0};
    }

    void medieValutazioni() {
        int numPortieri = 0, numDifensori = 0, numCentrocampisti = 0, numAttaccanti = 0;
        double sommaPortieri = 0, sommaDifensori = 0, sommaCentrocampisti = 0, sommaAttaccanti = 0;

        for (int i = 0; i < N_TITOLARI; i++) {
            string ruolo = squadra[titolari[i]].getRuolo();
            double valore = squadra[titolari[i]].getValore();

            //---Somma valutazioni per ruolo---
            if (ruolo == "Portiere") {
                sommaPortieri += valore;
                numPortieri++;
            } else if (ruolo == "Difensore") {
                sommaDifensori += valore;
                numDifensori++;
            } else if (ruolo == "Centrocampista") {
                sommaCentrocampisti += valore;
                numCentrocampisti++;
            } else if (ruolo == "Attaccante") {
                sommaAttaccanti += valore;
                numAttaccanti++;
            }
        }

        //---Media valutazioni per ruolo---
        mediaPortieri = (numPortieri > 0) ? sommaPortieri / numPortieri : 0; // assegna il valore calcolato all'attributo della classe
        mediaDifensori = (numDifensori > 0) ? sommaDifensori / numDifensori : 0; // assegna il valore calcolato all'attributo della classe
        mediaCentrocampisti = (numCentrocampisti > 0) ? sommaCentrocampisti / numCentrocampisti : 0; // assegna il valore calcolato all'attributo della classe
        mediaAttaccanti = (numAttaccanti > 0) ? sommaAttaccanti / numAttaccanti : 0; // assegna il valore calcolato all'attributo della classe
        /*
        //---Stampa media valutazioni per ruolo---
        cout << "Media valutazioni per ruolo:" << endl;
        cout << "Portieri: " << mediaPortieri << endl;
        cout << "Difensori: " << mediaDifensori << endl;
        cout << "Centrocampisti: " << mediaCentrocampisti << endl;
        cout << "Attaccanti: " << mediaAttaccanti << endl;
        */
    }

    void aggiungiGiocatore(string newNome, float newValore, string newRuolo, string newSquadra) {
        squadra.push_back(Giocatore(newNome, newValore, newRuolo, newSquadra));
        cout<<endl<<"-- Giocatore "<<newNome<<" ["<<newRuolo<<"]"<<" aggiunto alla squadra --> "<<squadraNome<<"! --"<<endl<<endl;
    }

    void aggiungiGiocatore(const Giocatore& giocatore) {
        squadra.push_back(giocatore);
    }

    void rimuoviGiocatore(int index) {
        cout<<endl<<"-- Giocatore "<<squadra[index].getNome()<< " rimosso! --"<<endl<<endl;
        squadra.erase(squadra.begin()+index);
    }

    void infoSquadra() const{
        cout<<endl;
        cout<<"Informazioni sulla squadra["<< getsquadraNome()<<"]:" << endl;
        cout<<"Nome: "<<squadraNome<<endl<<"Punteggio: "<<punteggio<<endl<<"Partite Giocate: "<<partiteGiocate<<endl<<"Vittorie: "<<risultati[0]<<endl<<"Pareggi: "<<risultati[1]<<endl<<"Sconfitte: "<<risultati[2]<<endl<<"Goal fatti: "<<goalFatti<<endl<<"Goal subiti: "<<endl;
        cout<<"Lista giocatori: "<<endl<<endl;
		for (int i=0; i<squadra.size(); i++){
            cout<<i+1<<". "<<squadra[i].getNome()<<endl;
        }
        cout<<endl<<endl;
    }
};



class Campionato {

    private:
        vector <Squadra> squadre;
        vector <int> classifica = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

    public:
        //----Attributi----
        int giornataCorrente = 0;
        vector <string> classificaMarcatoriNomi;
        vector <int> classificaMarcatori;
        vector <string> classificaAssistNomi;
        vector <int> classificaAssist;
        vector<vector<int>> calendarioCasa;
        vector<vector<int>> calendarioTrasferta;
        bool infoComplete = false;
        bool infoParziali = false;
        bool noInfo = false;
        //----Metodi----

        void calcolaCalendario() {
            calendarioCasa.resize(N_GIORNATE, vector<int>(N_SQUADRE / 2, -1));
            calendarioTrasferta.resize(N_GIORNATE, vector<int>(N_SQUADRE / 2, -1));
            vector<int> indiceSquadreCalendario(N_SQUADRE);
            
            // Riempie il vettore con i valori da 0 a 19
            iota(indiceSquadreCalendario.begin(), indiceSquadreCalendario.end(), 0);

            // Seme per generatore casuale di numero (cosa richiesta dal metodo shuffle)
            random_device rd;
            mt19937 g(rd());

            for (int i = 0; i < N_GIORNATE / 2; i++) {
                shuffle(indiceSquadreCalendario.begin(), indiceSquadreCalendario.end(), g);

                for (int j = 0; j < N_SQUADRE / 2; j++) {
                    calendarioCasa[i][j] = indiceSquadreCalendario[j];
                    calendarioTrasferta[i][j] = indiceSquadreCalendario[N_SQUADRE - 1 - j];
                }
            }

            // Genera il calendario di ritorno
            for (int i = N_GIORNATE / 2; i < N_GIORNATE; i++) {
                for (int j = 0; j < N_SQUADRE / 2; j++) {
                    calendarioCasa[i][j] = calendarioTrasferta[i - N_GIORNATE / 2][j];
                    calendarioTrasferta[i][j] = calendarioCasa[i - N_GIORNATE / 2][j];
                }
            }
        }

        void inizializzaSquadre() {
            cout<<"Inizializzazione squadre campionato..."<<endl;
            squadre.emplace_back("Atalanta"); // squadra 0
            squadre.emplace_back("Bologna"); // squadra 1
            squadre.emplace_back("Cagliari"); // squadra 2
            squadre.emplace_back("Empoli"); // squadra 3
            squadre.emplace_back("Fiorentina"); // squadra 4
            squadre.emplace_back("Frosinone"); // squadra 5
            squadre.emplace_back("Genoa"); // squadra 6
            squadre.emplace_back("HellasVerona"); // squadra 7
            squadre.emplace_back("Inter"); // squadra 8
            squadre.emplace_back("Juventus"); // squadra 9
            squadre.emplace_back("Lazio"); // squadra 10
            squadre.emplace_back("Lecce"); // squadra 11
            squadre.emplace_back("Milan"); // squadra 12
            squadre.emplace_back("Monza"); // squadra 13
            squadre.emplace_back("Napoli"); // squadra 14
            squadre.emplace_back("Roma"); // squadra 15
            squadre.emplace_back("Salernitana"); // squadra 16 
            squadre.emplace_back("Sassuolo"); // squadra 17
            squadre.emplace_back("Torino"); // squadra 18
            squadre.emplace_back("Udinese"); // squadra 19

            // Aggiungi giocatori a ciascuna squadra
            //---Squadra Atalanta---
                // Portieri
                squadre[0].aggiungiGiocatore(Giocatore("Musso", 7.0, "Portiere", "Atalanta"));
                squadre[0].aggiungiGiocatore(Giocatore("Carnesecchi", 6.5, "Portiere", "Atalanta"));
                squadre[0].aggiungiGiocatore(Giocatore("Rossi", 3.0, "Portiere", "Atalanta"));
                squadre[0].aggiungiGiocatore(Giocatore("Vismara", 1.0, "Portiere", "Atalanta"));

                // Difensori
                squadre[0].aggiungiGiocatore(Giocatore("Kolasinac", 6.8, "Difensore", "Atalanta"));
                squadre[0].aggiungiGiocatore(Giocatore("Scalvini", 6.7, "Difensore", "Atalanta"));
                squadre[0].aggiungiGiocatore(Giocatore("Zappacosta", 6.7, "Difensore", "Atalanta"));
                squadre[0].aggiungiGiocatore(Giocatore("Djimsiti", 6.4, "Difensore", "Atalanta"));
                squadre[0].aggiungiGiocatore(Giocatore("Holm", 6.4, "Difensore", "Atalanta"));
                squadre[0].aggiungiGiocatore(Giocatore("Ruggeri", 6.0, "Difensore", "Atalanta"));
                squadre[0].aggiungiGiocatore(Giocatore("Hateboer", 5.8, "Difensore", "Atalanta"));
                squadre[0].aggiungiGiocatore(Giocatore("Toloi", 5.4, "Difensore", "Atalanta"));

                // Centrocampisti
                squadre[0].aggiungiGiocatore(Giocatore("Koopmeiners", 9.8, "Centrocampista", "Atalanta"));
                squadre[0].aggiungiGiocatore(Giocatore("DeKeteleare", 7.0, "Centrocampista", "Atalanta"));
                squadre[0].aggiungiGiocatore(Giocatore("Pasalic", 6.9, "Centrocampista", "Atalanta"));
                squadre[0].aggiungiGiocatore(Giocatore("EdersonJ", 6.5, "Centrocampista", "Atalanta"));
                squadre[0].aggiungiGiocatore(Giocatore("Miranchuk", 6.5, "Centrocampista", "Atalanta"));
                squadre[0].aggiungiGiocatore(Giocatore("DeRoon", 6.0, "Centrocampista", "Atalanta"));
                squadre[0].aggiungiGiocatore(Giocatore("Adopo", 3.3, "Centrocampista", "Atalanta"));
                squadre[0].aggiungiGiocatore(Giocatore("Corinovis", 2.7, "Centrocampista", "Atalanta"));

                // Attaccanti
                squadre[0].aggiungiGiocatore(Giocatore("Lookman", 7.0, "Attaccante", "Atalanta"));
                squadre[0].aggiungiGiocatore(Giocatore("Scamacca", 6.8, "Attaccante", "Atalanta"));
                squadre[0].aggiungiGiocatore(Giocatore("ElBilalToure", 5.4, "Attaccante", "Atalanta"));
                squadre[0].aggiungiGiocatore(Giocatore("DeNipoti", 4.0, "Attaccante", "Atalanta"));
                squadre[0].aggiungiGiocatore(Giocatore("CisseM", 4.0, "Attaccante", "Atalanta"));

            //---Squadra Bologna---
                // Portieri
                squadre[1].aggiungiGiocatore(Giocatore("Skorupski", 7.8, "Portiere", "Bologna"));
                squadre[1].aggiungiGiocatore(Giocatore("RavagliaF", 5.5, "Portiere", "Bologna"));
                squadre[1].aggiungiGiocatore(Giocatore("Bagnolini", 1.9, "Portiere", "Bologna"));

                // Difensori
                squadre[1].aggiungiGiocatore(Giocatore("Posh", 7.0, "Difensore", "Bologna"));
                squadre[1].aggiungiGiocatore(Giocatore("Beukema", 6.3, "Difensore", "Bologna"));
                squadre[1].aggiungiGiocatore(Giocatore("Kristiansen", 6.3, "Difensore", "Bologna"));
                squadre[1].aggiungiGiocatore(Giocatore("Lucumi", 6.0, "Difensore", "Bologna"));
                squadre[1].aggiungiGiocatore(Giocatore("Calafiori", 6.0, "Difensore", "Bologna"));
                squadre[1].aggiungiGiocatore(Giocatore("Lykogiannis", 5.7, "Difensore", "Bologna"));
                squadre[1].aggiungiGiocatore(Giocatore("DeSilvestri", 5.3, "Difensore", "Bologna"));
                squadre[1].aggiungiGiocatore(Giocatore("Soumaoro", 2.7, "Difensore", "Bologna"));

                // Centrocampisti
                squadre[1].aggiungiGiocatore(Giocatore("Orsolini", 8.0, "Centrocampista", "Bologna"));
                squadre[1].aggiungiGiocatore(Giocatore("Ferguson", 7.9, "Centrocampista", "Bologna"));
                squadre[1].aggiungiGiocatore(Giocatore("Fabbian", 6.7, "Centrocampista", "Bologna"));
                squadre[1].aggiungiGiocatore(Giocatore("Freuler", 6.3, "Centrocampista", "Bologna"));
                squadre[1].aggiungiGiocatore(Giocatore("Saelemaekers", 6.0, "Centrocampista", "Bologna"));
                squadre[1].aggiungiGiocatore(Giocatore("Aebischer", 5.7, "Centrocampista", "Bologna"));
                squadre[1].aggiungiGiocatore(Giocatore("Ndoye", 5.3, "Centrocampista", "Bologna"));
                squadre[1].aggiungiGiocatore(Giocatore("Karlsson", 4.3, "Centrocampista", "Bologna"));

                // Attaccanti
                squadre[1].aggiungiGiocatore(Giocatore("Zirkzee", 7.3, "Attaccante", "Bologna"));
                squadre[1].aggiungiGiocatore(Giocatore("Odgaard", 6.1, "Attaccante", "Bologna"));
                squadre[1].aggiungiGiocatore(Giocatore("CastroS", 5.4, "Attaccante", "Bologna"));
                squadre[1].aggiungiGiocatore(Giocatore("MoroN", 4.0, "Attaccante", "Bologna"));
                
            //---Squadra Cagliari---
                // Portieri
                squadre[2].aggiungiGiocatore(Giocatore("Scuffet", 6.3, "Portiere", "Cagliari"));
                squadre[2].aggiungiGiocatore(Giocatore("Radunovic", 5.5, "Portiere", "Cagliari"));
                squadre[2].aggiungiGiocatore(Giocatore("Aresti", 2.9, "Portiere", "Cagliari"));

                // Difensori
                squadre[2].aggiungiGiocatore(Giocatore("Dossena", 6.3, "Difensore", "Cagliari"));
                squadre[2].aggiungiGiocatore(Giocatore("Zappa", 6.0, "Difensore", "Cagliari"));
                squadre[2].aggiungiGiocatore(Giocatore("Augello", 6.0, "Difensore", "Cagliari"));
                squadre[2].aggiungiGiocatore(Giocatore("Azzi", 5.6, "Difensore", "Cagliari"));
                squadre[2].aggiungiGiocatore(Giocatore("Mina", 5.2, "Difensore", "Cagliari"));
                squadre[2].aggiungiGiocatore(Giocatore("Wietska", 5.2, "Difensore", "Cagliari"));
                squadre[2].aggiungiGiocatore(Giocatore("DiPardo", 4.8, "Difensore", "Cagliari"));
                squadre[2].aggiungiGiocatore(Giocatore("Obert", 4.7, "Difensore", "Cagliari"));

                // Centrocampisti
                squadre[2].aggiungiGiocatore(Giocatore("Nandez", 6.2, "Centrocampista", "Cagliari"));
                squadre[2].aggiungiGiocatore(Giocatore("Gaetano", 6.2, "Centrocampista", "Cagliari"));
                squadre[2].aggiungiGiocatore(Giocatore("Jankto", 6.0, "Centrocampista", "Cagliari"));
                squadre[2].aggiungiGiocatore(Giocatore("Oristanio", 6.0, "Centrocampista", "Cagliari"));
                squadre[2].aggiungiGiocatore(Giocatore("Viola", 5.9, "Centrocampista", "Cagliari"));
                squadre[2].aggiungiGiocatore(Giocatore("Prati", 5.8, "Centrocampista", "Cagliari"));
                squadre[2].aggiungiGiocatore(Giocatore("Makoumbou", 5.2, "Centrocampista", "Cagliari"));
                squadre[2].aggiungiGiocatore(Giocatore("Mancosu", 4.3, "Centrocampista", "Cagliari"));

                // Attaccanti
                squadre[2].aggiungiGiocatore(Giocatore("Luvumbo", 5.9, "Attaccante", "Cagliari"));
                squadre[2].aggiungiGiocatore(Giocatore("Lapadula", 5.5, "Attaccante", "Cagliari"));
                squadre[2].aggiungiGiocatore(Giocatore("Pavoletti", 5.5, "Attaccante", "Cagliari"));
                squadre[2].aggiungiGiocatore(Giocatore("Petagna", 5.3, "Attaccante", "Cagliari"));
                squadre[2].aggiungiGiocatore(Giocatore("Shomurodov", 4.8, "Attaccante", "Cagliari"));

            
            //---Squadra Empoli---
                // Portieri
                squadre[3].aggiungiGiocatore(Giocatore("Caprile", 6.6, "Portiere", "Empoli"));
                squadre[3].aggiungiGiocatore(Giocatore("Berisha", 5.8, "Portiere", "Empoli"));
                squadre[3].aggiungiGiocatore(Giocatore("Perisan", 3.9, "Portiere", "Empoli"));
                squadre[3].aggiungiGiocatore(Giocatore("Stubljar", 3.2, "Portiere", "Empoli"));

                // Difensori
                squadre[3].aggiungiGiocatore(Giocatore("Luperto", 6.4, "Difensore", "Empoli"));
                squadre[3].aggiungiGiocatore(Giocatore("Ebuehi", 6.0, "Difensore", "Empoli"));
                squadre[3].aggiungiGiocatore(Giocatore("Bereszynski", 5.8, "Difensore", "Empoli"));
                squadre[3].aggiungiGiocatore(Giocatore("Ismajli", 5.0, "Difensore", "Empoli"));
                squadre[3].aggiungiGiocatore(Giocatore("BastoniS", 5.0, "Difensore", "Empoli"));
                squadre[3].aggiungiGiocatore(Giocatore("Walukiewicz", 4.7, "Difensore", "Empoli"));
                squadre[3].aggiungiGiocatore(Giocatore("Cacace", 4.0, "Difensore", "Empoli"));
                squadre[3].aggiungiGiocatore(Giocatore("Pezzella", 3.2, "Difensore", "Empoli"));

                // Centrocampisti
                squadre[3].aggiungiGiocatore(Giocatore("MarinR", 5.9, "Centrocampista", "Empoli"));
                squadre[3].aggiungiGiocatore(Giocatore("Fazzini", 5.8, "Centrocampista", "Empoli"));
                squadre[3].aggiungiGiocatore(Giocatore("Grassi", 5.8, "Centrocampista", "Empoli"));
                squadre[3].aggiungiGiocatore(Giocatore("Zurkowski", 5.9, "Centrocampista", "Empoli"));
                squadre[3].aggiungiGiocatore(Giocatore("Kovalenko", 5.3, "Centrocampista", "Empoli"));
                squadre[3].aggiungiGiocatore(Giocatore("Maleh", 5.0, "Centrocampista", "Empoli"));
                squadre[3].aggiungiGiocatore(Giocatore("Gyasi", 4.8, "Centrocampista", "Empoli"));
                squadre[3].aggiungiGiocatore(Giocatore("Belardinelli", 4.3, "Centrocampista", "Empoli"));

                // Attaccanti
                squadre[3].aggiungiGiocatore(Giocatore("Cambiaghi", 6.3, "Attaccante", "Empoli"));
                squadre[3].aggiungiGiocatore(Giocatore("Niang", 5.8, "Attaccante", "Empoli"));
                squadre[3].aggiungiGiocatore(Giocatore("Caputo", 5.4, "Attaccante", "Empoli"));
                squadre[3].aggiungiGiocatore(Giocatore("Cancellieri", 5.4, "Attaccante", "Empoli"));
                squadre[3].aggiungiGiocatore(Giocatore("Destro", 4.8, "Attaccante", "Empoli"));

            
            //---Squadra Fiorentina---
                // Portieri
                squadre[4].aggiungiGiocatore(Giocatore("Terracciano", 7.5, "Portiere", "Fiorentina"));
                squadre[4].aggiungiGiocatore(Giocatore("Christensen", 5.5, "Portiere", "Fiorentina"));
                squadre[4].aggiungiGiocatore(Giocatore("Martinelli", 3.9, "Portiere", "Fiorentina"));

                // Difensori
                squadre[4].aggiungiGiocatore(Giocatore("Kayode", 6.2, "Difensore", "Fiorentina"));
                squadre[4].aggiungiGiocatore(Giocatore("Biraghi", 6.0, "Difensore", "Fiorentina"));
                squadre[4].aggiungiGiocatore(Giocatore("Milenkovic", 6.0, "Difensore", "Fiorentina"));
                squadre[4].aggiungiGiocatore(Giocatore("Ranieri", 6.0, "Difensore", "Fiorentina"));
                squadre[4].aggiungiGiocatore(Giocatore("M_Quarta", 6.0, "Difensore", "Fiorentina"));
                squadre[4].aggiungiGiocatore(Giocatore("Parisi", 5.8, "Difensore", "Fiorentina"));
                squadre[4].aggiungiGiocatore(Giocatore("Faraoni", 5.6, "Difensore", "Fiorentina"));
                squadre[4].aggiungiGiocatore(Giocatore("Dodo", 5.4, "Difensore", "Fiorentina"));

                // Centrocampisti
                squadre[4].aggiungiGiocatore(Giocatore("Bonaventura", 7.0, "Centrocampista", "Fiorentina"));
                squadre[4].aggiungiGiocatore(Giocatore("Mandragora", 6.6, "Centrocampista", "Fiorentina"));
                squadre[4].aggiungiGiocatore(Giocatore("Duncan", 6.0, "Centrocampista", "Fiorentina"));
                squadre[4].aggiungiGiocatore(Giocatore("Barak", 6.0, "Centrocampista", "Fiorentina"));
                squadre[4].aggiungiGiocatore(Giocatore("Arthur", 6.0, "Centrocampista", "Fiorentina"));
                squadre[4].aggiungiGiocatore(Giocatore("Ikone", 5.8, "Centrocampista", "Fiorentina"));
                squadre[4].aggiungiGiocatore(Giocatore("LopeZ_M", 5.7, "Centrocampista", "Fiorentina"));
                squadre[4].aggiungiGiocatore(Giocatore("Sottil", 5.0, "Centrocampista", "Fiorentina"));

                // Attaccanti
                squadre[4].aggiungiGiocatore(Giocatore("GonzalezN", 6.5, "Attaccante", "Fiorentina"));
                squadre[4].aggiungiGiocatore(Giocatore("Beltran", 6.5, "Attaccante", "Fiorentina"));
                squadre[4].aggiungiGiocatore(Giocatore("Belotti", 6.1, "Attaccante", "Fiorentina"));
                squadre[4].aggiungiGiocatore(Giocatore("Kouame", 6.0, "Attaccante", "Fiorentina"));
                squadre[4].aggiungiGiocatore(Giocatore("Nzola", 5.8, "Attaccante", "Fiorentina"));


            //---Squadra Frosinone---
                // Portieri
                squadre[5].aggiungiGiocatore(Giocatore("Turati", 6.5, "Portiere", "Frosinone"));
                squadre[5].aggiungiGiocatore(Giocatore("Cerofolini", 4.5, "Portiere", "Frosinone"));
                squadre[5].aggiungiGiocatore(Giocatore("Frattali", 2.9, "Portiere", "Frosinone"));

                // Difensori
                squadre[5].aggiungiGiocatore(Giocatore("Lirola", 6.0, "Difensore", "Frosinone"));
                squadre[5].aggiungiGiocatore(Giocatore("Zortea", 5.9, "Difensore", "Frosinone"));
                squadre[5].aggiungiGiocatore(Giocatore("Marchizza", 5.8, "Difensore", "Frosinone"));
                squadre[5].aggiungiGiocatore(Giocatore("Monterisi", 5.7, "Difensore", "Frosinone"));
                squadre[5].aggiungiGiocatore(Giocatore("Okoli", 5.3, "Difensore", "Frosinone"));
                squadre[5].aggiungiGiocatore(Giocatore("Valeri", 4.9, "Difensore", "Frosinone"));
                squadre[5].aggiungiGiocatore(Giocatore("Bonifazi", 4.4, "Difensore", "Frosinone"));
                squadre[5].aggiungiGiocatore(Giocatore("Oyono", 4.4, "Difensore", "Frosinone"));

                // Centrocampisti
                squadre[5].aggiungiGiocatore(Giocatore("Soule", 8.1, "Centrocampista", "Frosinone"));
                squadre[5].aggiungiGiocatore(Giocatore("Mazzitelli", 6.6, "Centrocampista", "Frosinone"));
                squadre[5].aggiungiGiocatore(Giocatore("Brescianini", 6.4, "Centrocampista", "Frosinone"));
                squadre[5].aggiungiGiocatore(Giocatore("Harroui", 5.8, "Centrocampista", "Frosinone"));
                squadre[5].aggiungiGiocatore(Giocatore("Barrenechea", 5.7, "Centrocampista", "Frosinone"));
                squadre[5].aggiungiGiocatore(Giocatore("Reinier", 5.6, "Centrocampista", "Frosinone"));
                squadre[5].aggiungiGiocatore(Giocatore("Gelli", 5.2, "Centrocampista", "Frosinone"));
                squadre[5].aggiungiGiocatore(Giocatore("Garritano", 4.3, "Centrocampista", "Frosinone"));

                // Attaccanti
                squadre[5].aggiungiGiocatore(Giocatore("KaioJorge", 5.9, "Attaccante", "Frosinone"));
                squadre[5].aggiungiGiocatore(Giocatore("Caso", 6.1, "Attaccante", "Frosinone"));
                squadre[5].aggiungiGiocatore(Giocatore("Cheddira", 6.0, "Attaccante", "Frosinone"));
                squadre[5].aggiungiGiocatore(Giocatore("Baez", 5.7, "Attaccante", "Frosinone"));
                squadre[5].aggiungiGiocatore(Giocatore("Cuni", 5.6, "Attaccante", "Frosinone"));


            //---Squadra Genoa---
                // Portieri
                squadre[6].aggiungiGiocatore(Giocatore("MartinezJ", 7.0, "Portiere", "Genoa"));
                squadre[6].aggiungiGiocatore(Giocatore("Leali", 3.5, "Portiere", "Genoa"));
                squadre[6].aggiungiGiocatore(Giocatore("Sommariva", 2.9, "Portiere", "Genoa"));
                squadre[6].aggiungiGiocatore(Giocatore("Stolz", 2.6, "Portiere", "Genoa"));

                // Difensori
                squadre[6].aggiungiGiocatore(Giocatore("Bani", 6.4, "Difensore", "Genoa"));
                squadre[6].aggiungiGiocatore(Giocatore("Vasquez", 6.2, "Difensore", "Genoa"));
                squadre[6].aggiungiGiocatore(Giocatore("Savelli", 5.9, "Difensore", "Genoa"));
                squadre[6].aggiungiGiocatore(Giocatore("DeWinter", 5.9, "Difensore", "Genoa"));
                squadre[6].aggiungiGiocatore(Giocatore("Martin", 5.3, "Difensore", "Genoa"));
                squadre[6].aggiungiGiocatore(Giocatore("Spence", 4.9, "Difensore", "Genoa"));
                squadre[6].aggiungiGiocatore(Giocatore("Haps", 4.8, "Difensore", "Genoa"));
                squadre[6].aggiungiGiocatore(Giocatore("Vogliacco", 4.7, "Difensore", "Genoa"));

                // Centrocampisti
                squadre[6].aggiungiGiocatore(Giocatore("Malinovskyi", 7.1, "Centrocampista", "Genoa"));
                squadre[6].aggiungiGiocatore(Giocatore("Badelj", 6.1, "Centrocampista", "Genoa"));
                squadre[6].aggiungiGiocatore(Giocatore("Messias", 6.1, "Centrocampista", "Genoa"));
                squadre[6].aggiungiGiocatore(Giocatore("Frendrup", 6.0, "Centrocampista", "Genoa"));
                squadre[6].aggiungiGiocatore(Giocatore("Strootman", 6.0, "Centrocampista", "Genoa"));
                squadre[6].aggiungiGiocatore(Giocatore("Thorsby", 5.3, "Centrocampista", "Genoa"));
                squadre[6].aggiungiGiocatore(Giocatore("Bohinen", 4.9, "Centrocampista", "Genoa"));
                squadre[6].aggiungiGiocatore(Giocatore("Matturro", 1.3, "Centrocampista", "Genoa"));

                // Attaccanti
                squadre[6].aggiungiGiocatore(Giocatore("Gudmundsson", 7.8, "Attaccante", "Genoa"));
                squadre[6].aggiungiGiocatore(Giocatore("Retegui", 7.0, "Attaccante", "Genoa"));
                squadre[6].aggiungiGiocatore(Giocatore("Vitinha", 5.6, "Attaccante", "Genoa"));
                squadre[6].aggiungiGiocatore(Giocatore("Ekuban", 5.4, "Attaccante", "Genoa"));
                squadre[6].aggiungiGiocatore(Giocatore("Ankeye", 2.8, "Attaccante", "Genoa"));


            //---Squadra Hellas Verona---
                // Portieri
                squadre[7].aggiungiGiocatore(Giocatore("Montipo", 7.5, "Portiere", "HellasVerona"));
                squadre[7].aggiungiGiocatore(Giocatore("Perilli", 2.5, "Portiere", "HellasVerona"));
                squadre[7].aggiungiGiocatore(Giocatore("BerardiA", 1.9, "Portiere", "HellasVerona"));

                // Difensori
                squadre[7].aggiungiGiocatore(Giocatore("Magnani", 6.0, "Difensore", "HellasVerona"));
                squadre[7].aggiungiGiocatore(Giocatore("Dawidowicz", 5.7, "Difensore", "HellasVerona"));
                squadre[7].aggiungiGiocatore(Giocatore("Coppola_D", 4.3, "Difensore", "HellasVerona"));
                squadre[7].aggiungiGiocatore(Giocatore("Vinagre", 4.0, "Difensore", "HellasVerona"));
                squadre[7].aggiungiGiocatore(Giocatore("Centoze", 3.6, "Difensore", "HellasVerona"));
                squadre[7].aggiungiGiocatore(Giocatore("Cabal", 2.7, "Difensore", "HellasVerona"));
                squadre[7].aggiungiGiocatore(Giocatore("Popovic", 2.0, "Difensore", "HellasVerona"));
                squadre[7].aggiungiGiocatore(Giocatore("Charlys", 2.2, "Difensore", "HellasVerona"));

                // Centrocampisti
                squadre[7].aggiungiGiocatore(Giocatore("Suslov", 6.5, "Centrocampista", "HellasVerona"));
                squadre[7].aggiungiGiocatore(Giocatore("Folorunsho", 6.3, "Centrocampista", "HellasVerona"));
                squadre[7].aggiungiGiocatore(Giocatore("Duda", 6.0, "Centrocampista", "HellasVerona"));
                squadre[7].aggiungiGiocatore(Giocatore("Lazovic", 5.9, "Centrocampista", "HellasVerona"));
                squadre[7].aggiungiGiocatore(Giocatore("Serdar", 5.9, "Centrocampista", "HellasVerona"));
                squadre[7].aggiungiGiocatore(Giocatore("Tchatchoua", 5.8, "Centrocampista", "HellasVerona"));
                squadre[7].aggiungiGiocatore(Giocatore("DaniSilva", 3.2, "Centrocampista", "HellasVerona"));
                squadre[7].aggiungiGiocatore(Giocatore("Joselito", 2.3, "Centrocampista", "HellasVerona"));

                // Attaccanti
                squadre[7].aggiungiGiocatore(Giocatore("Henry", 5.7, "Attaccante", "HellasVerona"));
                squadre[7].aggiungiGiocatore(Giocatore("Swiderski", 5.5, "Attaccante", "HellasVerona"));
                squadre[7].aggiungiGiocatore(Giocatore("Bonazzoli", 5.3, "Attaccante", "HellasVerona"));
                squadre[7].aggiungiGiocatore(Giocatore("Noslin", 5.0, "Attaccante", "HellasVerona"));
                squadre[7].aggiungiGiocatore(Giocatore("CruzJ", 3.8, "Attaccante", "HellasVerona"));

            //---Squadra Inter---
                // Portieri
                squadre[8].aggiungiGiocatore(Giocatore("Sommer", 9.2, "Portiere", "Inter"));
                squadre[8].aggiungiGiocatore(Giocatore("Audero", 3.5, "Portiere", "Inter"));
                squadre[8].aggiungiGiocatore(Giocatore("DiGennaro", 2.9, "Portiere", "Inter"));

                // Difensori
                squadre[8].aggiungiGiocatore(Giocatore("DiMarco", 9.0, "Difensore", "Inter"));
                squadre[8].aggiungiGiocatore(Giocatore("Pavard", 8.0, "Difensore", "Inter"));
                squadre[8].aggiungiGiocatore(Giocatore("Bastoni", 8.0, "Difensore", "Inter"));
                squadre[8].aggiungiGiocatore(Giocatore("Acerbi", 7.4, "Difensore", "Inter"));
                squadre[8].aggiungiGiocatore(Giocatore("CarlosAugusto", 7.4, "Difensore", "Inter"));
                squadre[8].aggiungiGiocatore(Giocatore("Dumfries", 7.1, "Difensore", "Inter"));
                squadre[8].aggiungiGiocatore(Giocatore("Darmian", 6.3, "Difensore", "Inter"));
                squadre[8].aggiungiGiocatore(Giocatore("DeVrij", 6.1, "Difensore", "Inter"));

                // Centrocampisti
                squadre[8].aggiungiGiocatore(Giocatore("Barella", 9.0, "Centrocampista", "Inter"));
                squadre[8].aggiungiGiocatore(Giocatore("Calhanoglu", 8.8, "Centrocampista", "Inter"));
                squadre[8].aggiungiGiocatore(Giocatore("Mkhitaryan", 8.1, "Centrocampista", "Inter"));
                squadre[8].aggiungiGiocatore(Giocatore("Frattesi", 8.0, "Centrocampista", "Inter"));
                squadre[8].aggiungiGiocatore(Giocatore("Asllani", 6.2, "Centrocampista", "Inter"));
                squadre[8].aggiungiGiocatore(Giocatore("Klaassen", 5.8, "Centrocampista", "Inter"));
                squadre[8].aggiungiGiocatore(Giocatore("Sensi", 3.2, "Centrocampista", "Inter"));
                squadre[8].aggiungiGiocatore(Giocatore("Buchanan", 2.3, "Centrocampista", "Inter"));

                // Attaccanti
                squadre[8].aggiungiGiocatore(Giocatore("Lautaro", 9.9, "Attaccante", "Inter"));
                squadre[8].aggiungiGiocatore(Giocatore("Thuram", 8.7, "Attaccante", "Inter"));
                squadre[8].aggiungiGiocatore(Giocatore("Arnautovic", 7.4, "Attaccante", "Inter"));
                squadre[8].aggiungiGiocatore(Giocatore("Sanchez", 6.2, "Attaccante", "Inter"));
                squadre[8].aggiungiGiocatore(Giocatore("Akinsanmiro", 2.8, "Attaccante", "Inter"));

            //---Squadra Juventus---
                // Portieri
                squadre[9].aggiungiGiocatore(Giocatore("Szczesny", 9.3, "Portiere", "Juventus"));
                squadre[9].aggiungiGiocatore(Giocatore("Perin", 6.5, "Portiere", "Juventus"));
                squadre[9].aggiungiGiocatore(Giocatore("Pinsoglio", 2.9, "Portiere", "Juventus"));

                // Difensori
                squadre[9].aggiungiGiocatore(Giocatore("Bremer", 8.1, "Difensore", "Juventus"));
                squadre[9].aggiungiGiocatore(Giocatore("Danilo", 7.9, "Difensore", "Juventus"));
                squadre[9].aggiungiGiocatore(Giocatore("Gatti", 6.9, "Difensore", "Juventus"));
                squadre[9].aggiungiGiocatore(Giocatore("Cambiaso", 6.8, "Difensore", "Juventus"));
                squadre[9].aggiungiGiocatore(Giocatore("Rugani", 5.9, "Difensore", "Juventus"));
                squadre[9].aggiungiGiocatore(Giocatore("Weah", 5.9, "Difensore", "Juventus"));
                squadre[9].aggiungiGiocatore(Giocatore("AlexSandro", 4.0, "Difensore", "Juventus"));
                squadre[9].aggiungiGiocatore(Giocatore("Djalo", 3.2, "Difensore", "Juventus"));

                // Centrocampisti
                squadre[9].aggiungiGiocatore(Giocatore("Chiesa", 8.8, "Centrocampista", "Juventus"));
                squadre[9].aggiungiGiocatore(Giocatore("Rabiot", 8.1, "Centrocampista", "Juventus"));
                squadre[9].aggiungiGiocatore(Giocatore("McKennie", 7.1, "Centrocampista", "Juventus"));
                squadre[9].aggiungiGiocatore(Giocatore("Kostic", 6.9, "Centrocampista", "Juventus"));
                squadre[9].aggiungiGiocatore(Giocatore("Locatelli", 6.0, "Centrocampista", "Juventus"));
                squadre[9].aggiungiGiocatore(Giocatore("IlingJunior", 6.0, "Centrocampista", "Juventus"));
                squadre[9].aggiungiGiocatore(Giocatore("Alcaraz", 5.9, "Centrocampista", "Juventus"));
                squadre[9].aggiungiGiocatore(Giocatore("Miretti", 5.8, "Centrocampista", "Juventus"));

                // Attaccanti
                squadre[9].aggiungiGiocatore(Giocatore("Vlahovic", 9.0, "Attaccante", "Juventus"));
                squadre[9].aggiungiGiocatore(Giocatore("Yildiz", 6.8, "Attaccante", "Juventus"));
                squadre[9].aggiungiGiocatore(Giocatore("Milik", 5.9, "Attaccante", "Juventus"));
                squadre[9].aggiungiGiocatore(Giocatore("Kean", 5.9, "Attaccante", "Juventus"));
                squadre[9].aggiungiGiocatore(Giocatore("CerriL", 2.8, "Attaccante", "Juventus"));

            
            //---Squadra Lazio---
                // Portieri
                squadre[10].aggiungiGiocatore(Giocatore("Provedel", 8.5, "Portiere", "Lazio"));
                squadre[10].aggiungiGiocatore(Giocatore("Sepe", 4.5, "Portiere", "Lazio"));
                squadre[10].aggiungiGiocatore(Giocatore("Mandas", 1.9, "Portiere", "Lazio"));

                // Difensori
                squadre[10].aggiungiGiocatore(Giocatore("Romagnoli", 6.0, "Difensore", "Lazio"));
                squadre[10].aggiungiGiocatore(Giocatore("Lazzari", 5.9, "Difensore", "Lazio"));
                squadre[10].aggiungiGiocatore(Giocatore("Patric", 5.9, "Difensore", "Lazio"));
                squadre[10].aggiungiGiocatore(Giocatore("Marusic", 5.8, "Difensore", "Lazio"));
                squadre[10].aggiungiGiocatore(Giocatore("Casale", 5.7, "Difensore", "Lazio"));
                squadre[10].aggiungiGiocatore(Giocatore("PellegriniLu", 5.7, "Difensore", "Lazio"));
                squadre[10].aggiungiGiocatore(Giocatore("Gila", 5.7, "Difensore", "Lazio"));
                squadre[10].aggiungiGiocatore(Giocatore("Hysaj", 4.2, "Difensore", "Lazio"));

                // Centrocampisti
                squadre[10].aggiungiGiocatore(Giocatore("LuisAlberto", 8.9, "Centrocampista", "Lazio"));
                squadre[10].aggiungiGiocatore(Giocatore("FelipeAnderson", 8.8, "Centrocampista", "Lazio"));
                squadre[10].aggiungiGiocatore(Giocatore("Zaccagni", 8.7, "Centrocampista", "Lazio"));
                squadre[10].aggiungiGiocatore(Giocatore("Isaksen", 6.6, "Centrocampista", "Lazio"));
                squadre[10].aggiungiGiocatore(Giocatore("Guendouzi", 6.1, "Centrocampista", "Lazio"));
                squadre[10].aggiungiGiocatore(Giocatore("Vecino", 6.0, "Centrocampista", "Lazio"));
                squadre[10].aggiungiGiocatore(Giocatore("Rovella", 5.9, "Centrocampista", "Lazio"));
                squadre[10].aggiungiGiocatore(Giocatore("Kamada", 5.9, "Centrocampista", "Lazio"));

                // Attaccanti
                squadre[10].aggiungiGiocatore(Giocatore("Immobile", 7.9, "Attaccante", "Lazio"));
                squadre[10].aggiungiGiocatore(Giocatore("Castellanos", 6.3, "Attaccante", "Lazio"));
                squadre[10].aggiungiGiocatore(Giocatore("PedroR", 5.9, "Attaccante", "Lazio"));
                squadre[10].aggiungiGiocatore(Giocatore("GonzalezD", 3.0, "Attaccante", "Lazio"));
                squadre[10].aggiungiGiocatore(Giocatore("FernandesS", 2.8, "Attaccante", "Lazio"));

            //---Squadra Lecce---
                // Portieri
                squadre[11].aggiungiGiocatore(Giocatore("Falcone", 7.9, "Portiere", "Lecce"));
                squadre[11].aggiungiGiocatore(Giocatore("Brancolini", 2.5, "Portiere", "Lecce"));
                squadre[11].aggiungiGiocatore(Giocatore("Borbei", 1.9, "Portiere", "Lecce"));

                // Difensori
                squadre[11].aggiungiGiocatore(Giocatore("Gallo", 6.1, "Difensore", "Lecce"));
                squadre[11].aggiungiGiocatore(Giocatore("Gendrey", 6.1, "Difensore", "Lecce"));
                squadre[11].aggiungiGiocatore(Giocatore("Pongracic", 6.0, "Difensore", "Lecce"));
                squadre[11].aggiungiGiocatore(Giocatore("Baschirotto", 5.9, "Difensore", "Lecce"));
                squadre[11].aggiungiGiocatore(Giocatore("Dorgu", 5.0, "Difensore", "Lecce"));
                squadre[11].aggiungiGiocatore(Giocatore("Venuti", 4.0, "Difensore", "Lecce"));
                squadre[11].aggiungiGiocatore(Giocatore("Touba", 3.9, "Difensore", "Lecce"));
                squadre[11].aggiungiGiocatore(Giocatore("Dermaku", 3.2, "Difensore", "Lecce"));

                // Centrocampisti
                squadre[11].aggiungiGiocatore(Giocatore("Ramadani", 5.9, "Centrocampista", "Lecce"));
                squadre[11].aggiungiGiocatore(Giocatore("GonzalezJ", 5.7, "Centrocampista", "Lecce"));
                squadre[11].aggiungiGiocatore(Giocatore("Blin", 5.6, "Centrocampista", "Lecce"));
                squadre[11].aggiungiGiocatore(Giocatore("Kaba", 5.4, "Centrocampista", "Lecce"));
                squadre[11].aggiungiGiocatore(Giocatore("Rafia", 5.3, "Centrocampista", "Lecce"));
                squadre[11].aggiungiGiocatore(Giocatore("Samek", 5.2, "Centrocampista", "Lecce"));
                squadre[11].aggiungiGiocatore(Giocatore("BerishaM", 2.2, "Centrocampista", "Lecce"));
                squadre[11].aggiungiGiocatore(Giocatore("Burnete", 1.3, "Centrocampista", "Lecce"));

                // Attaccanti
                squadre[11].aggiungiGiocatore(Giocatore("Oudin", 6.3, "Attaccante", "Lecce"));
                squadre[11].aggiungiGiocatore(Giocatore("Piccoli", 6.0, "Attaccante", "Lecce"));
                squadre[11].aggiungiGiocatore(Giocatore("Banda", 6.0, "Attaccante", "Lecce"));
                squadre[11].aggiungiGiocatore(Giocatore("Krstovic", 6.0, "Attaccante", "Lecce"));
                squadre[11].aggiungiGiocatore(Giocatore("Almqvist", 5.9, "Attaccante", "Lecce"));

            //---Milan---
                // Portieri
                squadre[12].aggiungiGiocatore(Giocatore("Maignan", 9.2, "Portiere", "Milan"));
                squadre[12].aggiungiGiocatore(Giocatore("Sportiello", 3.5, "Portiere", "Milan"));
                squadre[12].aggiungiGiocatore(Giocatore("Mirante", 2.9, "Portiere", "Milan"));
                squadre[12].aggiungiGiocatore(Giocatore("Nava", 1.6, "Portiere", "Milan"));

                // Difensori
                squadre[12].aggiungiGiocatore(Giocatore("TheoHernandez", 9.5, "Difensore", "Milan"));
                squadre[12].aggiungiGiocatore(Giocatore("Calabria", 6.3, "Difensore", "Milan"));
                squadre[12].aggiungiGiocatore(Giocatore("Tomori", 6.3, "Difensore", "Milan"));
                squadre[12].aggiungiGiocatore(Giocatore("Kalulu", 6.0, "Difensore", "Milan"));
                squadre[12].aggiungiGiocatore(Giocatore("Kjaer", 5.9, "Difensore", "Milan"));
                squadre[12].aggiungiGiocatore(Giocatore("Thiaw", 5.9, "Difensore", "Milan"));
                squadre[12].aggiungiGiocatore(Giocatore("Florenzi", 5.9, "Difensore", "Milan"));
                squadre[12].aggiungiGiocatore(Giocatore("Gabbia", 4.2, "Difensore", "Milan"));

                // Centrocampisti
                squadre[12].aggiungiGiocatore(Giocatore("Pulisic", 9.6, "Centrocampista", "Milan"));
                squadre[12].aggiungiGiocatore(Giocatore("Loftus-Cheek", 7.1, "Centrocampista", "Milan"));
                squadre[12].aggiungiGiocatore(Giocatore("Reijnders", 6.9, "Centrocampista", "Milan"));
                squadre[12].aggiungiGiocatore(Giocatore("Chukwueze", 6.9, "Centrocampista", "Milan"));
                squadre[12].aggiungiGiocatore(Giocatore("Bennacer", 6.0, "Centrocampista", "Milan"));
                squadre[12].aggiungiGiocatore(Giocatore("Musah", 6.0, "Centrocampista", "Milan"));
                squadre[12].aggiungiGiocatore(Giocatore("Adli", 5.9, "Centrocampista", "Milan"));
                squadre[12].aggiungiGiocatore(Giocatore("Pobega", 5.3, "Centrocampista", "Milan"));

                // Attaccanti
                squadre[12].aggiungiGiocatore(Giocatore("Leao", 9.5, "Attaccante", "Milan"));
                squadre[12].aggiungiGiocatore(Giocatore("Giroud", 8.2, "Attaccante", "Milan"));
                squadre[12].aggiungiGiocatore(Giocatore("Okafor", 6.4, "Attaccante", "Milan"));
                squadre[12].aggiungiGiocatore(Giocatore("Jovic", 5.9, "Attaccante", "Milan"));
                squadre[12].aggiungiGiocatore(Giocatore("Camarda", 3.8, "Attaccante", "Milan"));

            //---Monza---
                // Portieri
                squadre[13].aggiungiGiocatore(Giocatore("DiGregorio", 8.0, "Portiere", "Monza"));
                squadre[13].aggiungiGiocatore(Giocatore("Sorrentino", 3.5, "Portiere", "Monza"));
                squadre[13].aggiungiGiocatore(Giocatore("Gori", 2.9, "Portiere", "Monza"));

                // Difensori
                squadre[13].aggiungiGiocatore(Giocatore("Birindelli", 6.1, "Difensore", "Monza"));
                squadre[13].aggiungiGiocatore(Giocatore("Caldirola", 6.0, "Difensore", "Monza"));
                squadre[13].aggiungiGiocatore(Giocatore("Izzo", 6.0, "Difensore", "Monza"));
                squadre[13].aggiungiGiocatore(Giocatore("Mari", 6.0, "Difensore", "Monza"));
                squadre[13].aggiungiGiocatore(Giocatore("CarboniA", 5.9, "Difensore", "Monza"));
                squadre[13].aggiungiGiocatore(Giocatore("Kyriakopoulos", 5.8, "Difensore", "Monza"));
                squadre[13].aggiungiGiocatore(Giocatore("D'ambrioso", 5.8, "Difensore", "Monza"));
                squadre[13].aggiungiGiocatore(Giocatore("Pereira", 3.2, "Difensore", "Monza"));

                // Centrocampisti
                squadre[13].aggiungiGiocatore(Giocatore("Pessina", 7.3, "Centrocampista", "Monza"));
                squadre[13].aggiungiGiocatore(Giocatore("Colpani", 8.0, "Centrocampista", "Monza"));
                squadre[13].aggiungiGiocatore(Giocatore("MaldiniD", 6.2, "Centrocampista", "Monza"));
                squadre[13].aggiungiGiocatore(Giocatore("CarboniV", 6.1, "Centrocampista", "Monza"));
                squadre[13].aggiungiGiocatore(Giocatore("Ciurria", 6.0, "Centrocampista", "Monza"));
                squadre[13].aggiungiGiocatore(Giocatore("Gagliardini", 6.0, "Centrocampista", "Monza"));
                squadre[13].aggiungiGiocatore(Giocatore("Bondo", 5.9, "Centrocampista", "Monza"));
                squadre[13].aggiungiGiocatore(Giocatore("Vignato", 5.9, "Centrocampista", "Monza"));

                // Attaccanti
                squadre[13].aggiungiGiocatore(Giocatore("Djuric", 5.9, "Attaccante", "Monza"));
                squadre[13].aggiungiGiocatore(Giocatore("Colombo", 5.9, "Attaccante", "Monza"));
                squadre[13].aggiungiGiocatore(Giocatore("Caprari", 5.9, "Attaccante", "Monza"));
                squadre[13].aggiungiGiocatore(Giocatore("Mota", 5.9, "Attaccante", "Monza"));
                squadre[13].aggiungiGiocatore(Giocatore("Zerbin", 4.8, "Attaccante", "Monza"));

            //---Napoli---
                // Portieri
                squadre[14].aggiungiGiocatore(Giocatore("Meret", 7.8, "Portiere", "Napoli"));
                squadre[14].aggiungiGiocatore(Giocatore("Gollini", 5.5, "Portiere", "Napoli"));
                squadre[14].aggiungiGiocatore(Giocatore("Contini", 3.9, "Portiere", "Napoli"));
                squadre[14].aggiungiGiocatore(Giocatore("Idasiak", 2.6, "Portiere", "Napoli"));

                // Difensori
                squadre[14].aggiungiGiocatore(Giocatore("DiLorenzo", 8.7, "Difensore", "Napoli"));
                squadre[14].aggiungiGiocatore(Giocatore("Rrahmani", 6.3, "Difensore", "Napoli"));
                squadre[14].aggiungiGiocatore(Giocatore("MarioRui", 6.1, "Difensore", "Napoli"));
                squadre[14].aggiungiGiocatore(Giocatore("Mazzocchi", 6.0, "Difensore", "Napoli"));
                squadre[14].aggiungiGiocatore(Giocatore("MathiasOlivera", 5.9, "Difensore", "Napoli"));
                squadre[14].aggiungiGiocatore(Giocatore("Natan", 5.9, "Difensore", "Napoli"));
                squadre[14].aggiungiGiocatore(Giocatore("JuanJesus", 5.6, "Difensore", "Napoli"));
                squadre[14].aggiungiGiocatore(Giocatore("Ostigard", 5.2, "Difensore", "Napoli"));

                // Centrocampisti
                squadre[14].aggiungiGiocatore(Giocatore("Politano", 7.5, "Centrocampista", "Napoli"));
                squadre[14].aggiungiGiocatore(Giocatore("Zielinski", 6.5, "Centrocampista", "Napoli"));
                squadre[14].aggiungiGiocatore(Giocatore("Lobotka", 6.1, "Centrocampista", "Napoli"));
                squadre[14].aggiungiGiocatore(Giocatore("Anguissa", 6.0, "Centrocampista", "Napoli"));
                squadre[14].aggiungiGiocatore(Giocatore("Traore", 5.8, "Centrocampista", "Napoli"));
                squadre[14].aggiungiGiocatore(Giocatore("Cajuste", 5.6, "Centrocampista", "Napoli"));
                squadre[14].aggiungiGiocatore(Giocatore("Dendoncker", 4.3, "Centrocampista", "Napoli"));
                squadre[14].aggiungiGiocatore(Giocatore("Demme", 3.3, "Centrocampista", "Napoli"));

                // Attaccanti
                squadre[14].aggiungiGiocatore(Giocatore("Osimhen", 9.0, "Attaccante", "Napoli"));
                squadre[14].aggiungiGiocatore(Giocatore("Kvaratskhelia", 8.5, "Attaccante", "Napoli"));
                squadre[14].aggiungiGiocatore(Giocatore("Ngonge", 6.4, "Attaccante", "Napoli"));
                squadre[14].aggiungiGiocatore(Giocatore("Raspadori", 7.0, "Attaccante", "Napoli"));
                squadre[14].aggiungiGiocatore(Giocatore("Lindstrom", 5.8, "Attaccante", "Napoli"));

            //---Roma---
                // Portieri
                squadre[15].aggiungiGiocatore(Giocatore("RuiPatricio", 7.5, "Portiere", "Roma"));
                squadre[15].aggiungiGiocatore(Giocatore("Svilar", 6.5, "Portiere", "Roma"));
                squadre[15].aggiungiGiocatore(Giocatore("Boer", 1.9, "Portiere", "Roma"));

                // Difensori
                squadre[15].aggiungiGiocatore(Giocatore("Mancini", 7.0, "Difensore", "Roma"));
                squadre[15].aggiungiGiocatore(Giocatore("Ndicka", 6.2, "Difensore", "Roma"));
                squadre[15].aggiungiGiocatore(Giocatore("LlorenteD", 6.1, "Difensore", "Roma"));
                squadre[15].aggiungiGiocatore(Giocatore("Spinazzola", 6.0, "Difensore", "Roma"));
                squadre[15].aggiungiGiocatore(Giocatore("Karsdorp", 6.0, "Difensore", "Roma"));
                squadre[15].aggiungiGiocatore(Giocatore("Angelino", 6.0, "Difensore", "Roma"));
                squadre[15].aggiungiGiocatore(Giocatore("Smalling", 5.9, "Difensore", "Roma"));
                squadre[15].aggiungiGiocatore(Giocatore("Kristensen", 5.7, "Difensore", "Roma"));

                // Centrocampisti
                squadre[15].aggiungiGiocatore(Giocatore("Pellegrini", 8.5, "Centrocampista", "Roma"));
                squadre[15].aggiungiGiocatore(Giocatore("Paredes", 6.4, "Centrocampista", "Roma"));
                squadre[15].aggiungiGiocatore(Giocatore("Cristante", 6.2, "Centrocampista", "Roma"));
                squadre[15].aggiungiGiocatore(Giocatore("Baldanzi", 6.0, "Centrocampista", "Roma"));
                squadre[15].aggiungiGiocatore(Giocatore("Aouar", 6.0, "Centrocampista", "Roma"));
                squadre[15].aggiungiGiocatore(Giocatore("Bove", 5.9, "Centrocampista", "Roma"));
                squadre[15].aggiungiGiocatore(Giocatore("RenatoSanches", 5.8, "Centrocampista", "Roma"));
                squadre[15].aggiungiGiocatore(Giocatore("Pagano", 3.3, "Centrocampista", "Roma"));

                // Attaccanti
                squadre[15].aggiungiGiocatore(Giocatore("Dybala", 8.5, "Attaccante", "Roma"));
                squadre[15].aggiungiGiocatore(Giocatore("Lukaku", 9.0, "Attaccante", "Roma"));
                squadre[15].aggiungiGiocatore(Giocatore("ElShaarawy", 6.4, "Attaccante", "Roma"));
                squadre[15].aggiungiGiocatore(Giocatore("Azmoun", 6.0, "Attaccante", "Roma"));
                squadre[15].aggiungiGiocatore(Giocatore("Abraham", 2.8, "Attaccante", "Roma"));

            //---Salernitana---
                // Portieri
                squadre[16].aggiungiGiocatore(Giocatore("Ochoa", 6.5, "Portiere", "Salernitana"));
                squadre[16].aggiungiGiocatore(Giocatore("Costil", 5.5, "Portiere", "Salernitana"));
                squadre[16].aggiungiGiocatore(Giocatore("Fiorillo", 2.9, "Portiere", "Salernitana"));
                // Difensori
                squadre[16].aggiungiGiocatore(Giocatore("Zanoli", 5.6, "Difensore", "Salernitana"));
                squadre[16].aggiungiGiocatore(Giocatore("Fazio", 5.3, "Difensore", "Salernitana"));
                squadre[16].aggiungiGiocatore(Giocatore("Boateng", 5.3, "Difensore", "Salernitana"));
                squadre[16].aggiungiGiocatore(Giocatore("Bradaric", 5.0, "Difensore", "Salernitana"));
                squadre[16].aggiungiGiocatore(Giocatore("Pierozzi", 5.0, "Difensore", "Salernitana"));
                squadre[16].aggiungiGiocatore(Giocatore("Pirola", 4.7, "Difensore", "Salernitana"));
                squadre[16].aggiungiGiocatore(Giocatore("Manolas", 4.5, "Difensore", "Salernitana"));
                squadre[16].aggiungiGiocatore(Giocatore("Sambia", 3.2, "Difensore", "Salernitana"));
                // Centrocampisti
                squadre[16].aggiungiGiocatore(Giocatore("Candreva", 8.5, "Centrocampista", "Salernitana"));
                squadre[16].aggiungiGiocatore(Giocatore("Kastanos", 6.3, "Centrocampista", "Salernitana"));
                squadre[16].aggiungiGiocatore(Giocatore("Coulibaly", 6.0, "Centrocampista", "Salernitana"));
                squadre[16].aggiungiGiocatore(Giocatore("Maggiore", 6.0, "Centrocampista", "Salernitana"));
                squadre[16].aggiungiGiocatore(Giocatore("Martegani", 5.6, "Centrocampista", "Salernitana"));
                squadre[16].aggiungiGiocatore(Giocatore("Legowski", 5.3, "Centrocampista", "Salernitana"));
                squadre[16].aggiungiGiocatore(Giocatore("Basic", 3.2, "Centrocampista", "Salernitana"));
                squadre[16].aggiungiGiocatore(Giocatore("Vignato", 3.3, "Centrocampista", "Salernitana"));
                // Attaccanti
                squadre[16].aggiungiGiocatore(Giocatore("Dia", 7.1, "Attaccante", "Salernitana"));
                squadre[16].aggiungiGiocatore(Giocatore("Tchaouna", 6.0, "Attaccante", "Salernitana"));
                squadre[16].aggiungiGiocatore(Giocatore("Simy", 4.4, "Attaccante", "Salernitana"));
                squadre[16].aggiungiGiocatore(Giocatore("Weissmann", 4.0, "Attaccante", "Salernitana"));
                squadre[16].aggiungiGiocatore(Giocatore("Ikwuemesi", 3.8, "Attaccante", "Salernitana"));

            //---Sassuolo---
                // Portieri
                squadre[17].aggiungiGiocatore(Giocatore("Consigli", 7.1, "Portiere", "Sassuolo"));
                squadre[17].aggiungiGiocatore(Giocatore("Cragno", 5.5, "Portiere", "Sassuolo"));
                squadre[17].aggiungiGiocatore(Giocatore("Pegolo", 2.9, "Portiere", "Sassuolo"));

                // Difensori
                squadre[17].aggiungiGiocatore(Giocatore("Toljan", 5.9, "Difensore", "Sassuolo"));
                squadre[17].aggiungiGiocatore(Giocatore("Pedersen", 5.9, "Difensore", "Sassuolo"));
                squadre[17].aggiungiGiocatore(Giocatore("Doig", 5.8, "Difensore", "Sassuolo"));
                squadre[17].aggiungiGiocatore(Giocatore("Erlic", 5.5, "Difensore", "Sassuolo"));
                squadre[17].aggiungiGiocatore(Giocatore("Viti", 5.0, "Difensore", "Sassuolo"));
                squadre[17].aggiungiGiocatore(Giocatore("Ferrari", 4.7, "Difensore", "Sassuolo"));
                squadre[17].aggiungiGiocatore(Giocatore("Kumbulla", 4.0, "Difensore", "Sassuolo"));
                squadre[17].aggiungiGiocatore(Giocatore("Tressoldi", 3.2, "Difensore", "Sassuolo"));

                // Centrocampisti
                squadre[17].aggiungiGiocatore(Giocatore("Thorstvedt", 6.7, "Centrocampista", "Sassuolo"));
                squadre[17].aggiungiGiocatore(Giocatore("Bajrami", 6.0, "Centrocampista", "Sassuolo"));
                squadre[17].aggiungiGiocatore(Giocatore("HenriqueM", 6.0, "Centrocampista", "Sassuolo"));
                squadre[17].aggiungiGiocatore(Giocatore("VolpatoC", 5.8, "Centrocampista", "Sassuolo"));
                squadre[17].aggiungiGiocatore(Giocatore("Boloca", 5.6, "Centrocampista", "Sassuolo"));
                squadre[17].aggiungiGiocatore(Giocatore("Castillejo", 5.3, "Centrocampista", "Sassuolo"));
                squadre[17].aggiungiGiocatore(Giocatore("Racic", 4.2, "Centrocampista", "Sassuolo"));
                squadre[17].aggiungiGiocatore(Giocatore("Lipani", 3.3, "Centrocampista", "Sassuolo"));

                // Attaccanti
                squadre[17].aggiungiGiocatore(Giocatore("Berardi", 9.0, "Attaccante", "Sassuolo"));
                squadre[17].aggiungiGiocatore(Giocatore("Pinamonti", 7.0, "Attaccante", "Sassuolo"));
                squadre[17].aggiungiGiocatore(Giocatore("Lauriente", 6.9, "Attaccante", "Sassuolo"));
                squadre[17].aggiungiGiocatore(Giocatore("Mulattieri", 5.0, "Attaccante", "Sassuolo"));
                squadre[17].aggiungiGiocatore(Giocatore("Defrel", 2.8, "Attaccante", "Sassuolo"));

            //---Torino---
                // Portieri
                squadre[18].aggiungiGiocatore(Giocatore("Milinkovic-Savic", 8.5, "Portiere", "Torino"));
                squadre[18].aggiungiGiocatore(Giocatore("Popa", 2.5, "Portiere", "Torino"));
                squadre[18].aggiungiGiocatore(Giocatore("Gemello", 1.9, "Portiere", "Torino"));
                squadre[18].aggiungiGiocatore(Giocatore("Fiorenza", 1.6, "Portiere", "Torino"));

                // Difensori
                squadre[18].aggiungiGiocatore(Giocatore("Bellanova", 7.9, "Difensore", "Torino"));
                squadre[18].aggiungiGiocatore(Giocatore("Buongiorno", 7.4, "Difensore", "Torino"));
                squadre[18].aggiungiGiocatore(Giocatore("Vojvoda", 6.2, "Difensore", "Torino"));
                squadre[18].aggiungiGiocatore(Giocatore("RodriguezR", 6.0, "Difensore", "Torino"));
                squadre[18].aggiungiGiocatore(Giocatore("Lazaro", 5.9, "Difensore", "Torino"));
                squadre[18].aggiungiGiocatore(Giocatore("Shuurs", 5.7, "Difensore", "Torino"));
                squadre[18].aggiungiGiocatore(Giocatore("Masina", 5.5, "Difensore", "Torino"));
                squadre[18].aggiungiGiocatore(Giocatore("Lovato", 5.0, "Difensore", "Torino"));

                // Centrocampisti
                squadre[18].aggiungiGiocatore(Giocatore("Ilic", 6.9, "Centrocampista", "Torino"));
                squadre[18].aggiungiGiocatore(Giocatore("Vlasic", 6.9, "Centrocampista", "Torino"));
                squadre[18].aggiungiGiocatore(Giocatore("Ricci", 6.2, "Centrocampista", "Torino"));
                squadre[18].aggiungiGiocatore(Giocatore("Linetty", 5.9, "Centrocampista", "Torino"));
                squadre[18].aggiungiGiocatore(Giocatore("Gineitis", 5.0, "Centrocampista", "Torino"));
                squadre[18].aggiungiGiocatore(Giocatore("Tameze", 5.0, "Centrocampista", "Torino"));
                squadre[18].aggiungiGiocatore(Giocatore("Ciammaglichella", 4.2, "Centrocampista", "Torino"));
                squadre[18].aggiungiGiocatore(Giocatore("Sazonov", 3.3, "Centrocampista", "Torino"));

                // Attaccanti
                squadre[18].aggiungiGiocatore(Giocatore("Zapata", 8.3, "Attaccante", "Torino"));
                squadre[18].aggiungiGiocatore(Giocatore("Sanabria", 6.9, "Attaccante", "Torino"));
                squadre[18].aggiungiGiocatore(Giocatore("Pellegri", 5.4, "Attaccante", "Torino"));
                squadre[18].aggiungiGiocatore(Giocatore("Okereke", 4.0, "Attaccante", "Torino"));
                squadre[18].aggiungiGiocatore(Giocatore("Kabic", 3.8, "Attaccante", "Torino"));

            //---Udinese---
                // Portieri
                squadre[19].aggiungiGiocatore(Giocatore("Okoye", 6.0, "Portiere", "Udinese"));
                squadre[19].aggiungiGiocatore(Giocatore("Silvestri", 5.9, "Portiere", "Udinese"));
                squadre[19].aggiungiGiocatore(Giocatore("Padelli", 1.9, "Portiere", "Udinese"));

                // Difensori
                squadre[19].aggiungiGiocatore(Giocatore("Kamara", 6.3, "Difensore", "Udinese"));
                squadre[19].aggiungiGiocatore(Giocatore("PerezN", 6.0, "Difensore", "Udinese"));
                squadre[19].aggiungiGiocatore(Giocatore("Bijol", 5.9, "Difensore", "Udinese"));
                squadre[19].aggiungiGiocatore(Giocatore("Kabasele", 5.9, "Difensore", "Udinese"));
                squadre[19].aggiungiGiocatore(Giocatore("Ehizibue", 5.5, "Difensore", "Udinese"));
                squadre[19].aggiungiGiocatore(Giocatore("Zemura", 5.3, "Difensore", "Udinese"));
                squadre[19].aggiungiGiocatore(Giocatore("Ebosele", 5.0, "Difensore", "Udinese"));
                squadre[19].aggiungiGiocatore(Giocatore("Ferreira", 3.2, "Difensore", "Udinese"));

                // Centrocampisti
                squadre[19].aggiungiGiocatore(Giocatore("Samardzic", 7.0, "Centrocampista", "Udinese"));
                squadre[19].aggiungiGiocatore(Giocatore("Lovric", 6.3, "Centrocampista", "Udinese"));
                squadre[19].aggiungiGiocatore(Giocatore("Pereyra", 6.2, "Centrocampista", "Udinese"));
                squadre[19].aggiungiGiocatore(Giocatore("Walace", 6.0, "Centrocampista", "Udinese"));
                squadre[19].aggiungiGiocatore(Giocatore("Payero", 5.6, "Centrocampista", "Udinese"));
                squadre[19].aggiungiGiocatore(Giocatore("Zarraga", 4.3, "Centrocampista", "Udinese"));
                squadre[19].aggiungiGiocatore(Giocatore("Brenner", 3.2, "Centrocampista", "Udinese"));
                squadre[19].aggiungiGiocatore(Giocatore("Ebosse", 2.3, "Centrocampista", "Udinese"));

                // Attaccanti
                squadre[19].aggiungiGiocatore(Giocatore("Lucca", 6.9, "Attaccante", "Udinese"));
                squadre[19].aggiungiGiocatore(Giocatore("Thauvin", 6.3, "Attaccante", "Udinese"));
                squadre[19].aggiungiGiocatore(Giocatore("Success", 6.0, "Attaccante", "Udinese"));
                squadre[19].aggiungiGiocatore(Giocatore("Deulofeu", 5.8, "Attaccante", "Udinese"));
                squadre[19].aggiungiGiocatore(Giocatore("Davis", 3.8, "Attaccante", "Udinese"));


            cout<<"Inizializzazione squadre campionato completata!"<<endl;

            cout<<"Calcolo calendario..."<<endl;
            calcolaCalendario();
            cout<<"Calendario calcolato!"<<endl;
        }

       

        Giocatore& getGiocatoreClass(int indiceSquadra, int indiceGiocatore) {
            return squadre.at(indiceSquadra).getGiocatore(indiceGiocatore);
        }
        void aggiungiSquadra(const Squadra& squadra) {
            squadre.push_back(squadra);
        }

        const Squadra& getSquadra(int index) {
            return squadre.at(index);
        }

        const Squadra& getSquadra(string nomeSquadra) {
            for (const Squadra& squadra : squadre) {
                if (squadra.getsquadraNome() == nomeSquadra) {
                    return squadra;
                }
            }
            throw runtime_error("Squadra non trovata");
        }

        void calcoloClassifica(){
            sort(classifica.begin(), classifica.end(), [this](int a, int b) {
                return this->squadre[a].punteggio > this->squadre[b].punteggio;
            });
        }

        void calcolaClassificaMarcatori() {
            struct Marcatore {
                string nome;
                int goal;

                bool operator<(const Marcatore& other) const {
                    return goal > other.goal; // Ordinamento decrescente
                }
            };

            vector<Marcatore> classificaMarcatori;

            for (int i = 0; i < N_SQUADRE; i++) {
                for (int j = 0; j < squadre[i].size(); j++) {
                    Marcatore m;
                    m.nome = squadre[i].getGiocatore(j).getNome();
                    m.goal = squadre[i].getGiocatore(j).goal;
                    classificaMarcatori.push_back(m);
                }
            }

            // Ordina la classifica dei marcatori
            sort(classificaMarcatori.begin(), classificaMarcatori.end());

            // Seleziona i primi 10 marcatori
            if (classificaMarcatori.size() > 10) {
                classificaMarcatori.resize(10);
            }

            // Stampa la classifica dei marcatori
            cout << "Classifica Marcatori:" << endl;
            for (const auto& marcatore : classificaMarcatori) {
                cout << marcatore.nome << ": " << marcatore.goal << " goal" << endl;
            }
        }

        void calcolaClassificaAssist() {
            struct Assistman {
                string nome;
                int assist;

                bool operator<(const Assistman& other) const {
                    return assist > other.assist; // Ordinamento decrescente
                }
            };

            vector<Assistman> classificaAssist;

            for (int i = 0; i < N_SQUADRE; i++) {
                for (int j = 0; j < squadre[i].size(); j++) {
                    Assistman a;
                    a.nome = squadre[i].getGiocatore(j).getNome();
                    a.assist = squadre[i].getGiocatore(j).assist;
                    classificaAssist.push_back(a);
                }
            }

            // Ordina la classifica degli assist
            sort(classificaAssist.begin(), classificaAssist.end());

            // Seleziona i primi 10 assistenti
            if (classificaAssist.size() > 10) {
                classificaAssist.resize(10);
            }

            // Stampa la classifica degli assistenti
            cout << "Classifica Assist:" << endl;
            for (const auto& assistente : classificaAssist) {
                cout << assistente.nome << ": " << assistente.assist << " assist" << endl;
            }
        }

        void stampaClassifica(){
            cout<<"Classifica:"<<endl<<endl;
            for (int i=0; i<squadre.size(); i++){
                cout<<i+1<<". "<<squadre[classifica[i]].getsquadraNome()<<" ("<<squadre[classifica[i]].punteggio<<" Pt) ;"<<endl;
            }
        }
        void partita(int a, int b) {

            // Impostazioni per outuput
            if (infoComplete) {
                    squadre[a].infoComplete = true;
                    squadre[a].infoParziali = false;
                    squadre[a].noInfo = false;
                    squadre[b].infoComplete = true;
                    squadre[b].infoParziali = false;
                    squadre[b].noInfo = false;
                    cout << "----------------- Partita tra le squadre: -----------------" << endl <<"                   ---" << squadre[a].getsquadraNome() << " e " << squadre[b].getsquadraNome() <<"---"<< endl<<endl;

            }
            else if (infoParziali) {
                squadre[a].infoComplete = false;
                squadre[a].infoParziali = true;
                squadre[a].noInfo = false;
                squadre[b].infoComplete = false;
                squadre[b].infoParziali = true;
                squadre[b].noInfo = false;
            }
            else if (noInfo) {
                squadre[a].infoComplete = false;
                squadre[a].infoParziali = false;
                squadre[a].noInfo = true;
                squadre[b].infoComplete = false;
                squadre[b].infoParziali = false;
                squadre[b].noInfo = true;
            }


            // Composizione titolari, calcolo medie valutazioni per reparto, aggiornamento statistiche
            squadre[a].calcolaFormazione();
            squadre[a].composizioneTitolari(squadre[a].getFormazione());
            squadre[a].medieValutazioni();


            squadre[b].calcolaFormazione();
            squadre[b].composizioneTitolari(squadre[b].getFormazione());
            squadre[b].medieValutazioni();


            int goal_SquadraA = 0;
            float chanceGoalA = 0;
            int goal_SquadraB = 0;
            float chanceGoalB = 0;
            int counterOutputAssistA=0;
            int counterOutputAssistB=0;
            vector<int> marcatoriA;
            vector<int> marcatoriB;
            vector<int> assistA;
            vector<int> assistB;
            vector<int> minutaggioGoalA;
            vector<int> minutaggioGoalB;
            float temp;
            float goalReparto;
            int marcatore;
            int sommaTemporanea = 0;
            srand(time(0));  // Inizializza il generatore di numeri casuali

            for (int i = 0; i < 90; i++) {
                // Calcolo della probabilità di goal per la squadra A
                chanceGoalA = ((rand() % 100) / (10.0 + ((goal_SquadraA) / (rand() % 4 + 1))) +
                            (squadre[a].mediaAttaccanti + (squadre[a].mediaCentrocampisti / 2)) / 4 -
                            (squadre[b].mediaDifensori + (squadre[b].mediaCentrocampisti + squadre[b].mediaPortieri) / 4) / 4) / 10.0;
                if (chanceGoalA >= 0.97) { // Verifica se si verifica un goal
                    //cout << "Goal " << squadre[a].getsquadraNome() << "!";
                    goal_SquadraA += 1;
                    squadre[a].goalFatti ++;
                    squadre[b].goalSubiti ++;
                    minutaggioGoalA.push_back(i);
                    // Calcola il valore di temp per goalReparto
                    temp = ((squadre[a].mediaDifensori / 3) + (squadre[a].mediaCentrocampisti / 2) + squadre[a].mediaAttaccanti);
                    goalReparto = rand() % int(temp);
                    temp = 0;
                    sommaTemporanea = 0;
                    // Goal reparto attaccanti
                    if (goalReparto <= squadre[a].mediaAttaccanti) {
                        for (int j = 0; j < squadre[a].getFormazione()[2]; j++) {
                            sommaTemporanea += squadre[a].getGiocatore(squadre[a].titolari[N_TITOLARI-j-1]).getValore();
                        }
                        marcatore = rand() % int(sommaTemporanea);
                        //scelta del marcatore
                        for (int j = 0; j < squadre[a].getFormazione()[2]; j++) {
                            sommaTemporanea -= squadre[a].getGiocatore(squadre[a].titolari[N_TITOLARI-j-1]).getValore();
                            if (marcatore >= sommaTemporanea) {
                                //cout<<" -> "<<squadre[a].getGiocatore(squadre[a].titolari[N_TITOLARI-j-1]).getNome();
                                squadre[a].getGiocatore(squadre[a].titolari[N_TITOLARI-j-1]).goal++;
                                marcatoriA.push_back(squadre[a].titolari[N_TITOLARI-j-1]);
                                //scelta assistman
                                temp=rand()%2;
                                if (temp==1) {
                                    temp=(rand()%9)+1;
                                    if (temp!=N_TITOLARI-j-1) {
                                        //cout<<"(assist "<<squadre[a].getGiocatore(squadre[a].titolari[temp]).getNome()<<") "<<i<<"'"<<endl;
                                        squadre[a].getGiocatore(squadre[a].titolari[temp]).assist++;
                                        assistA.push_back(squadre[a].titolari[temp]);
                                    }
                                }
                                else {
                                        assistA.push_back(0);
                                        //cout<<" "<<i<<"'"<<endl;
                                    }
                                break;
                            }
                        }
                    }
                    // Goal reparto centrocampisti
                    else if (goalReparto > squadre[a].mediaAttaccanti && goalReparto <= (squadre[a].mediaAttaccanti + (squadre[a].mediaCentrocampisti / 2))) {
                        for (int j = 0; j < squadre[a].getFormazione()[1]; j++) {
                            sommaTemporanea += squadre[a].getGiocatore(squadre[a].titolari[squadre[a].getFormazione()[0]+squadre[a].getFormazione()[1]-j]).getValore();
                        }
                        marcatore = rand() % int(sommaTemporanea);
                        //scelta del marcatore
                        for (int j = 0; j < squadre[a].getFormazione()[1]; j++) {
                            sommaTemporanea -= squadre[a].getGiocatore(squadre[a].titolari[squadre[a].getFormazione()[0]+squadre[a].getFormazione()[1]-j]).getValore();
                            if (marcatore >= sommaTemporanea) {
                                //cout<<" -> "<<squadre[a].getGiocatore(squadre[a].titolari[N_TITOLARI-squadre[a].getFormazione()[2]-j-1]).getNome();
                                squadre[a].getGiocatore(squadre[a].titolari[N_TITOLARI-squadre[a].getFormazione()[2]-j-1]).goal++;
                                marcatoriA.push_back(squadre[a].titolari[N_TITOLARI-squadre[a].getFormazione()[2]-j-1]);
                                temp=rand()%2;
                                if (temp==1) {
                                    temp=(rand()%9)+1;
                                    if (temp!=N_TITOLARI-squadre[a].getFormazione()[2]-j-1) {
                                        //cout<<"(assist "<<squadre[a].getGiocatore(squadre[a].titolari[temp]).getNome()<<") "<<i<<"'"<<endl;
                                        squadre[a].getGiocatore(squadre[a].titolari[temp]).assist++;
                                        assistA.push_back(squadre[a].titolari[temp]);
                                    }
                                }
                                else {
                                        assistA.push_back(0);
                                        //cout<<" "<<i<<"'"<<endl;
                                    }
                                break;
                            }
                        }
                    }
                    // Goal reparto difensori
                    else if (goalReparto >= (squadre[a].mediaAttaccanti + (squadre[a].mediaCentrocampisti / 2))){
                        for (int j = 0; j < squadre[a].getFormazione()[0]; j++) {
                            sommaTemporanea += squadre[a].getGiocatore(squadre[a].titolari[squadre[a].getFormazione()[0]-j]).getValore();

                        }
                        marcatore = rand() % int(sommaTemporanea);
                        //scelta del marcatore
                        for (int j = 0; j < squadre[a].getFormazione()[0]; j++) {
                            sommaTemporanea -= squadre[a].getGiocatore(squadre[a].titolari[squadre[a].getFormazione()[0]-j]).getValore();
                            if (marcatore >= sommaTemporanea) {
                                //cout<<" -> "<<squadre[a].getGiocatore(squadre[a].titolari[N_TITOLARI-squadre[a].getFormazione()[2]-squadre[a].getFormazione()[1]-j-1]).getNome();
                                squadre[a].getGiocatore(squadre[a].titolari[N_TITOLARI-squadre[a].getFormazione()[2]-squadre[a].getFormazione()[1]-j-1]).goal++;
                                marcatoriA.push_back(squadre[a].titolari[N_TITOLARI-squadre[a].getFormazione()[2]-squadre[a].getFormazione()[1]-j-1]);
                                //scelta assistman
                                temp=rand()%2;
                                if (temp==1) {
                                    temp=(rand()%9)+1;
                                    if (temp!=N_TITOLARI-squadre[a].getFormazione()[2]-squadre[a].getFormazione()[1]-j-1) {
                                        //cout<<"(assist "<<squadre[a].getGiocatore(squadre[a].titolari[temp]).getNome()<<") "<<i<<"'"<<endl;
                                        squadre[a].getGiocatore(squadre[a].titolari[temp]).assist++;
                                        assistA.push_back(squadre[a].titolari[temp]);
                                    }
                                }
                                else {
                                        assistA.push_back(0);
                                        //cout<<" "<<i<<"'"<<endl;
                                    }
                                break;
                            }
                        }
                    }
                    //else cout<<("Goal reparto out of range")<<endl;
                }

                // Calcolo della probabilità di goal per la squadra B (simile a quello per la squadra A)
                chanceGoalB = ((rand() % 100) / (10.0 + ((goal_SquadraB) / (rand() % 4 + 1))) +
                            (squadre[b].mediaAttaccanti + (squadre[b].mediaCentrocampisti / 2)) / 4 -
                            (squadre[a].mediaDifensori + (squadre[a].mediaCentrocampisti + squadre[a].mediaPortieri) / 4) / 4) / 10.0;
                            
                if (chanceGoalB >= 0.97) { // Verifica se si verifica un goal
                    //cout << "Goal " << squadre[b].getsquadraNome() << "!";
                    goal_SquadraB += 1;
                    squadre[b].goalFatti ++;
                    squadre[a].goalSubiti ++;
                    minutaggioGoalB.push_back(i);
                    // Calcola il valore di temp per goalReparto
                    temp = ((squadre[b].mediaDifensori / 3) + (squadre[b].mediaCentrocampisti / 2) + squadre[b].mediaAttaccanti);
                    goalReparto = rand() % int(temp);
                    temp = 0;
                    sommaTemporanea = 0;
                    // Goal reparto attaccanti
                    if (goalReparto <= squadre[b].mediaAttaccanti) {
                        for (int j = 0; j < squadre[b].getFormazione()[2]; j++) {
                            sommaTemporanea += squadre[b].getGiocatore(squadre[b].titolari[N_TITOLARI-j-1]).getValore();
                        }
                        marcatore = rand() % int(sommaTemporanea);
                        //scelta del marcatore
                        for (int j = 0; j < squadre[b].getFormazione()[2]; j++) {
                                sommaTemporanea -= squadre[b].getGiocatore(squadre[b].titolari[N_TITOLARI-j-1]).getValore();
                                if (marcatore >= sommaTemporanea) {
                                    //cout<<" -> "<<squadre[b].getGiocatore(squadre[b].titolari[N_TITOLARI-j-1]).getNome();
                                    squadre[b].getGiocatore(squadre[b].titolari[N_TITOLARI-j-1]).goal++;
                                    marcatoriB.push_back(squadre[b].titolari[N_TITOLARI-j-1]);
                                    //scelta assistman
                                    temp=rand()%2;
                                    if (temp==1) {
                                        temp=(rand()%9)+1;
                                        if (temp!=N_TITOLARI-j-1) {
                                            //cout<<"(assist "<<squadre[b].getGiocatore(squadre[b].titolari[temp]).getNome()<<") "<<i<<"'"<<endl;
                                            squadre[b].getGiocatore(squadre[b].titolari[temp]).assist++;
                                            assistB.push_back(squadre[b].titolari[temp]);
                                        }
                                    }
                                    else {
                                        assistB.push_back(0);
                                        //cout<<" "<<i<<"'"<<endl;
                                    }
                                    break;
                                }
                        }
                    }
                    // Goal reparto centrocampisti
                    else if (goalReparto > squadre[b].mediaAttaccanti && goalReparto <= (squadre[b].mediaAttaccanti + squadre[b].mediaCentrocampisti / 2)) {
                        for (int j = 0; j < squadre[b].getFormazione()[1]; j++) {
                            sommaTemporanea += squadre[b].getGiocatore(squadre[b].titolari[squadre[b].getFormazione()[0]+squadre[b].getFormazione()[1]-j]).getValore();
                        }
                        marcatore = rand() % int(sommaTemporanea);
                        //scelta del marcatore
                        for (int j = 0; j < squadre[b].getFormazione()[1]; j++) {
                            sommaTemporanea -= squadre[b].getGiocatore(squadre[b].titolari[squadre[b].getFormazione()[0]+squadre[b].getFormazione()[1]-j]).getValore();
                            if (marcatore >= sommaTemporanea) {
                                //cout<<" -> "<<squadre[b].getGiocatore(squadre[b].titolari[N_TITOLARI-squadre[b].getFormazione()[2]-j-1]).getNome();
                                squadre[b].getGiocatore(squadre[b].titolari[N_TITOLARI-squadre[b].getFormazione()[2]-j-1]).goal++;
                                marcatoriB.push_back(squadre[b].titolari[N_TITOLARI-squadre[b].getFormazione()[2]-j-1]);
                                //scelta assistman
                                temp=rand()%2;
                                if (temp==1) {
                                    temp=(rand()%9)+1;
                                    if (temp!=N_TITOLARI-squadre[b].getFormazione()[2]-j-1) {
                                        //cout<<"(assist "<<squadre[b].getGiocatore(squadre[b].titolari[temp]).getNome()<<") "<<i<<"'"<<endl;
                                        squadre[b].getGiocatore(squadre[b].titolari[temp]).assist++;
                                        assistB.push_back(squadre[b].titolari[temp]);
                                    }
                                }
                                else {
                                        assistB.push_back(0);
                                        //cout<<" "<<i<<"'"<<endl;
                                    }
                                break;
                            }
                        }
                    }
                    // Goal reparto difensori
                    else {
                        for (int j = 0; j < squadre[b].getFormazione()[0]; j++) {
                            sommaTemporanea += squadre[b].getGiocatore(squadre[b].getFormazione()[0]-j).getValore();
                        }
                        marcatore = rand() % int(sommaTemporanea);
                        for (int j = 0; j < squadre[b].getFormazione()[0]; j++) {
                            sommaTemporanea -= squadre[b].getGiocatore(squadre[b].getFormazione()[0]-j).getValore();
                            if (marcatore >= sommaTemporanea) {
                                //cout<<" -> "<<squadre[b].getGiocatore(squadre[b].titolari[N_TITOLARI-squadre[b].getFormazione()[2]-squadre[b].getFormazione()[1]-j-1]).getNome();
                                squadre[b].getGiocatore(squadre[b].titolari[N_TITOLARI-squadre[b].getFormazione()[2]-squadre[b].getFormazione()[1]-j-1]).goal++;
                                marcatoriB.push_back(squadre[b].titolari[N_TITOLARI-squadre[b].getFormazione()[2]-squadre[b].getFormazione()[1]-j-1]);
                                //scelta assistman
                                temp=rand()%2;
                                if (temp==1) {
                                    temp=(rand()%9)+1;
                                    if (temp!=N_TITOLARI-squadre[b].getFormazione()[2]-squadre[b].getFormazione()[1]-j-1) {
                                        //cout<<"(assist "<<squadre[b].getGiocatore(squadre[b].titolari[temp]).getNome()<<") "<<i<<"'"<<endl;
                                        squadre[b].getGiocatore(squadre[b].titolari[temp]).assist++;
                                        assistB.push_back(squadre[b].titolari[temp]);
                                    }
                                }
                                else {
                                        assistB.push_back(0);
                                        //cout<<" "<<i<<"'"<<endl;
                                    }
                                break;
                            }
                        }
                    }
                }

            }
            //calcolo risultato finale
            // Vittoria Squadra A
            if (goal_SquadraA > goal_SquadraB) {
                squadre[a].punteggio+=3;
                squadre[a].risultati[0]++;
                squadre[b].risultati[2]++;
            // Vittoria Squadra B
            } else if (goal_SquadraA < goal_SquadraB) {
                squadre[b].punteggio+=3;
                squadre[b].risultati[0]++;
                squadre[a].risultati[2]++;
            // Pareggio
            } else {
                squadre[a].punteggio++;
                squadre[a].risultati[1]++;
                squadre[b].punteggio++;
                squadre[b].risultati[1]++;
            }

            if (infoComplete) {
                squadre[a].infoComplete = true;
                squadre[a].infoParziali = false;
                squadre[a].noInfo = false;
                squadre[b].infoComplete = true;
                squadre[b].infoParziali = false;
                squadre[b].noInfo = false;

                counterOutputAssistA = 0;
                counterOutputAssistB = 0;
                // Stampa del risultato finale
                cout << "Risultato finale: " << squadre[a].getsquadraNome() << " " << goal_SquadraA << " - " << goal_SquadraB << " " << squadre[b].getsquadraNome() << endl;

                // Stampa dei marcatori per la squadra A
                cout << "Marcatori " << squadre[a].getsquadraNome() << ": ";
                for (int i = 0; i < marcatoriA.size(); i++) {
                    cout << squadre[a].getGiocatore(marcatoriA[i]).getNome() << " " << minutaggioGoalA[i] << "'";
                    if (counterOutputAssistA < assistA.size() && assistA[counterOutputAssistA] != 0) {
                        cout << " (assist: " << squadre[a].getGiocatore(assistA[counterOutputAssistA]).getNome() << ") - ";
                        counterOutputAssistA++;
                    } else {
                        cout << " - ";
                    }
                }
                cout << endl;

                // Stampa dei marcatori per la squadra B
                cout << "Marcatori " << squadre[b].getsquadraNome() << ": ";
                for (int i = 0; i < marcatoriB.size(); i++) {
                    cout << squadre[b].getGiocatore(marcatoriB[i]).getNome() << " " << minutaggioGoalB[i] << "'";
                    if (counterOutputAssistB < assistB.size() && assistB[counterOutputAssistB] != 0) {
                        cout << " (assist: " << squadre[b].getGiocatore(assistB[counterOutputAssistB]).getNome() << ") - ";
                        counterOutputAssistB++;
                    } else {
                        cout << " - ";
                    }
                }
                cout<<endl<<"------------------------------------------------------"<<endl<<endl;
            }
            else if (infoParziali) {
                squadre[a].infoParziali = true;
                squadre[a].infoComplete = false;
                squadre[b].noInfo = false;
                squadre[b].infoComplete = false;
                squadre[b].infoParziali = true;
                squadre[b].noInfo = false;
                cout << squadre[a].getsquadraNome() << " " << goal_SquadraA << " - " << goal_SquadraB << " " << squadre[b].getsquadraNome() << endl;
            }

            else if (noInfo) {
                squadre[a].noInfo = true;
                squadre[a].infoParziali = false;
                squadre[a].infoComplete = false;
                squadre[b].noInfo = true;
                squadre[b].infoParziali = false;
                squadre[b].infoComplete = false;
                cout << endl;
            }

            squadre[a].azzeraTitolari();
            squadre[b].azzeraTitolari();
            marcatoriA.clear();
            marcatoriB.clear();
            assistA.clear();
            assistB.clear();
            minutaggioGoalA.clear();
            minutaggioGoalB.clear();

        }

};


int main () {
    srand(time(NULL));
    bool simulaCampionato = false; // Variabile per indicare se è stata selezionata l'opzione 7
    bool infoComplete = false;
    bool infoParziali = false;
    bool noInfo = false;
    int scelta;
    int scelta2;
    string scelta3;
    string scelta4;
    int scelta5;
    cout<<"Benvenuti in Project Serie A!"<<endl;
    cout<<"Project Serie A e' un simulatore del campionato che si basa su statistiche e probabilita' matematiche,"<<endl;
    cout<<"che mira a compiere una simulazione verosimile del reale campionato di Serie A."<<endl<<endl;
    cout<<"Per continuare, premi qualiasi tasto";
    cin.get();
    cout<<endl;
    //inizializzazione campionato, squadre e calendario
    Campionato campionato;
    campionato.inizializzaSquadre();
    cout<<"Squadre inizializzate e calendario calcolato."<<endl;
    cout<<"Per continuare, premi qualiasi tasto"<<endl<<endl;
    cin.get();
    cout<<"Prima di iniziare, come vuoi che ti vengano mostrate le informazioni sulla partita?"<<endl;
    cout<<"1. Complete: Per ogni partita, ti verra' mostrata la formazione titolare di ogni squadra e il risultato con marcatori;"<<endl;
    cout<<"2. Parziali: Viene visualizzato solo il modulo e il risultato della partita;"<<endl;
    cout<<"3. Nessuna: nessuna informazione eccetto la classifica, per una modalita' piu' veloce e dinamica;"<<endl;
    cout<<"Scelta: ";
    cin>>scelta;
    cout<<endl;
    if (scelta==1) {
        cout<<"Hai scelto Informazioni complete."<<endl;
        infoComplete = true;
        campionato.infoComplete = true;
        campionato.infoParziali = false;
        campionato.noInfo = false;
    }
    else if (scelta==2) {
        cout<<"Hai scelto Informazioni parziali."<<endl;
        infoParziali = true;
        campionato.infoParziali = true;
        campionato.infoComplete = false;
        campionato.noInfo = false;
    }
    else if (scelta==3) {
        cout<<"Hai scelto no informazioni."<<endl;
        noInfo = true;
        campionato.noInfo = true;
        campionato.infoComplete = false;
        campionato.infoParziali = false;
    }
    cout<<endl;
    cout<<"E' tutto pronto per iniziare la simulazione! Per iniziare, premi qualiasi tasto";
    cin.get();
    cout<<endl;
    for (int i=0; i<N_GIORNATE; i++) {
        campionato.giornataCorrente++;
        cout<<"----------------------GIORNATA "<<campionato.giornataCorrente<<"-----------------------"<<endl;
        for (int j = 0; j < N_SQUADRE / 2; j++) {
            //calcolo incontri casa-trasferta
            int squadraCasa = campionato.calendarioCasa[i][j];
            int squadraTrasferta = campionato.calendarioTrasferta[i][j];
            //simulazione partita
            campionato.partita(squadraCasa, squadraTrasferta);
            //fine simulazione partita
        }
        cout<<"----------------------FINE GIORNATA "<<i+1<<"-----------------------"<<endl;
        campionato.calcoloClassifica();
        campionato.stampaClassifica();
        cout<<endl<<endl;
        if (scelta!=7) {
            do{
                cout<<"Per continuare, scegli una delle seguenti funzioni:"<<endl<<endl;
                cout<<"0. Cambiare modalita' informazioni"<<endl;
                cout<<"1. Info squadra"<<endl;
                cout<<"2. Info Giocatore"<<endl;
                cout<<"3. Classifica marcatori"<<endl;
                cout<<"4. Classifica assist"<<endl;
                cout<<"5. Classifica generale"<<endl;
                cout<<"6. Continua con la prossima giornata"<<endl;
                cout<<"7. Simula direttamente l'intero campionato"<<endl;
                cout<<"8. Esci dal programma"<<endl;
                cout<<"Scelta: ";
                cin>>scelta;
                cout<<endl;
                switch(scelta){
                    case 0:
                        cout<<"Come vuoi che ti vengano mostrate le informazioni sulla partita?"<<endl;
                        cout<<"1. Complete: Per ogni partita, ti verra' mostrata la formazione titolare di ogni squadra e il risultato con marcatori;"<<endl;
                        cout<<"2. Parziali: Viene visualizzato solo il modulo e il risultato della partita;"<<endl;
                        cout<<"3. Nessuna: nessuna informazione eccetto la classifica, per una modalita' più veloce e dinamica;"<<endl;
                        cout<<"Scelta: ";
                        cin>>scelta;
                        cout<<endl;
                        if (scelta==1) {
                            cout<<"Hai scelto Informazioni complete."<<endl;
                            infoComplete = true;
                            campionato.infoComplete = true;
                            campionato.infoParziali = false;
                            campionato.noInfo = false;
                        }
                        else if (scelta==2) {
                            cout<<"Hai scelto Informazioni parziali."<<endl;
                            infoParziali = true;
                            campionato.infoParziali = true;
                            campionato.infoComplete = false;
                            campionato.noInfo = false;
                        }
                        else if (scelta==3) {
                            cout<<"Hai scelto no informazioni."<<endl;
                            noInfo = true;
                            campionato.infoComplete = false;
                            campionato.infoParziali = false;
                        }
                        break;
                    case 1:
                        cout<<"Quale squadra vuoi vedere? (Digitare nome squadra): ";
                        cin>>scelta3;
                        cout<<endl;
                        campionato.getSquadra(scelta3).infoSquadra();
                        cout<<endl;
                        break;
                    case 2:
                        cout<<"Inserisci l'indice della squadre del giocatore desiderato: ";
                        cin>>scelta2;
                        cout<<endl;
                        cout<<"Inserisci l'indice del giocatore desiderato: ";
                        cin>>scelta5;
                        cout<<endl;
                        campionato.getGiocatoreClass(scelta2, scelta5).infoGiocatore();
                        cout<<endl;
                        break;
                    case 3:
                        campionato.calcolaClassificaMarcatori();
                        cout<<endl;
                        break;
                    case 4:
                        campionato.calcolaClassificaAssist();
                        cout<<endl;
                        break;
                    case 5:
                        campionato.stampaClassifica();
                        cout<<endl;
                        break;
                    case 6:
                        cout<<"Continuo alla prossima giornata..."<<endl;
                        break;
                    case 7:
                        cout<<"Simulazione intero campionato: "<<endl;
                        simulaCampionato = true;
                        break;
                    case 8:
                        cout<<"--Simulazione interrotta. Arrivederci!--"<<endl;
                        return 0;
                        break;
                    default:
                        cout << "Scelta non valida. Riprova." << endl;
                }
            } while(scelta != 6 && !simulaCampionato && scelta != 8);
            if (simulaCampionato) {
                for (int i = campionato.giornataCorrente; i < N_GIORNATE; i++) {
                    for (int j = 0; j < N_SQUADRE / 2; j++) {
                        // Calcolo incontri casa-trasferta e simulazione partita
                        int squadraCasa = campionato.calendarioCasa[i][j];
                        int squadraTrasferta = campionato.calendarioTrasferta[i][j];
                        campionato.partita(squadraCasa, squadraTrasferta);
                    }
                    // Fine giornata e aggiornamento classifica
                    cout << "----------------------FINE GIORNATA " << i + 1 << "-----------------------" << endl;
                    campionato.calcoloClassifica();
                    campionato.stampaClassifica();
                    cout << endl << endl;
                }
                do{
                    cout<<"Per continuare, scegli una delle seguenti funzioni:"<<endl<<endl;
                    cout<<"1. Info squadra"<<endl;
                    cout<<"2. Info Giocatore"<<endl;
                    cout<<"3. Classifica marcatori"<<endl;
                    cout<<"4. Classifica assist"<<endl;
                    cout<<"5. Classifica generale"<<endl;
                    cout<<"6. Esci dal programma"<<endl;
                    cout<<"Scelta: ";
                    cin>>scelta;
                    cout<<endl;
                    switch(scelta){
                        case 1:
                            cout<<"Quale squadra vuoi vedere? (Digitare nome squadra): ";
                            cin>>scelta3;
                            cout<<endl;
                            campionato.getSquadra(scelta3).infoSquadra();
                            cout<<endl;
                            break;
                        case 2:
                            cout<<"Inserisci l'indice della squadre del giocatore desiderato: ";
                            cin>>scelta2;
                            cout<<endl;
                            cout<<"Inserisci l'indice del giocatore desiderato: ";
                            cin>>scelta5;
                            cout<<endl;
                            campionato.getGiocatoreClass(scelta2, scelta5).infoGiocatore();
                            cout<<endl;
                            break;
                        case 3:
                            campionato.calcolaClassificaMarcatori();
                            cout<<endl;
                            break;
                        case 4:
                            campionato.calcolaClassificaAssist();
                            cout<<endl;
                            break;
                        case 5:
                            campionato.stampaClassifica();
                            cout<<endl;
                            break;
                        case 6:
                            cout<<"--Simulazione interrotta. Arrivederci!--"<<endl;
                            return 0;
                            break;
                        default:
                            cout << "Scelta non valida. Riprova." << endl;
                    }
                } while(scelta != 6);
                break;
            }
        }
    }
    
    return 0;
}

/*
    //calcolo classifica
    campionato.calcoloClassifica();
    campionato.stampaClassifica();

    //prendere info giocatore
    campionato.getGiocatoreClass(8, 19).infoGiocatore();
    campionato.getGiocatoreClass(9, 19).infoGiocatore();

    //prendere info squadra
    campionato.getSquadra(9).infoSquadra();
    campionato.getSquadra(rand()%20).infoSquadra();

    //cambiare punteggio nel main
    campionato.getSquadra(9).punteggio = 3; 



    Juventus.infoGiocatore(0);
    Juventus[0].infoGiocatore();
    Squadra Juventus("Juventus");
        campionato.aggiungiSquadra(Juventus);

        Juventus.aggiungiGiocatore("Vlahovic", 8.5, "Attaccante", "Juventus");

        campionato->aggiungiSquadra(Squadra("Juventus"));
        campionato->getSquadre(0).aggiungiGiocatore("Messi", 10.0, "Centrocampista", "Juventus");
        campionato->getSquadre(0).infoSquadra();

        campionato->squadre[0].infoSquadra();
        
        squadra->infoSquadra();
        squadra->infoGiocatore("Vlahovic");
        squadra->setFormazione({4,3,3});
        squadra->composizioneTitolari(squadra->getFormazione());
        squadra->medieValutazioni();


    // Portieri
    squadra->aggiungiGiocatore("Szczesny", 8.0, "Portiere", "Juventus");
    squadra->aggiungiGiocatore("Perin", 6.0, "Portiere", "Juventus");
    squadra->aggiungiGiocatore("Pinsoglio", 4.0, "Portiere", "Juventus");
    squadra->aggiungiGiocatore("Garofani", 2.5, "Portiere", "Juventus");

    // Difensori
    squadra->aggiungiGiocatore("Cambiaso", 7.0, "Difensore", "Juventus");
    squadra->aggiungiGiocatore("Danilo", 7.2, "Difensore", "Juventus");
    squadra->aggiungiGiocatore("A. Sandro", 5.5, "Difensore", "Juventus");
    squadra->aggiungiGiocatore("Bremer", 8.6, "Difensore", "Juventus");
    squadra->aggiungiGiocatore("Gatti", 6.8, "Difensore", "Juventus");
    squadra->aggiungiGiocatore("De Sciglio", 5.0, "Difensore", "Juventus");
    squadra->aggiungiGiocatore("Rugani", 6.5, "Difensore", "Juventus");
    squadra->aggiungiGiocatore("Weah", 6.0, "Difensore", "Juventus");

    // Centrocampisti
    squadra->aggiungiGiocatore("Locatelli", 6.5, "Centrocampista", "Juventus");
    squadra->aggiungiGiocatore("Rabiot", 7.8, "Centrocampista", "Juventus");
    squadra->aggiungiGiocatore("McKennie", 6.2, "Centrocampista", "Juventus");
    squadra->aggiungiGiocatore("Kostic", 6.5, "Centrocampista", "Juventus");
    squadra->aggiungiGiocatore("Miretti", 6.0, "Centrocampista", "Juventus");
    squadra->aggiungiGiocatore("Fagioli", 7.0, "Centrocampista", "Juventus");
    squadra->aggiungiGiocatore("Pogba", 5.9, "Centrocampista", "Juventus");
    squadra->aggiungiGiocatore("Alcaraz", 6.0, "Centrocampista", "Juventus");

    // Attaccanti
    squadra->aggiungiGiocatore("Vlahovic", 8.5, "Attaccante", "Juventus");
    squadra->aggiungiGiocatore("Chiesa", 8.0, "Attaccante", "Juventus");
    squadra->aggiungiGiocatore("Kean", 6.0, "Attaccante", "Juventus");
    squadra->aggiungiGiocatore("Milik", 6.5, "Attaccante", "Juventus");
    squadra->aggiungiGiocatore("Soule'", 6.8, "Attaccante", "Juventus");
    */