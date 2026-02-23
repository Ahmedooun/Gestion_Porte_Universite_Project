//
// Created by ahmed on 15/10/2025.
//

#ifndef AP4A_PROJET_SCHEDULER_H
#define AP4A_PROJET_SCHEDULER_H

#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include <algorithm>
#include "Serveur.h"
#include "Personne.h"
#include "Badge.h"
#include "LecteurBadge.h"

// Structure d'une tentative d'accès
struct DemandeAcces {
    int heure;
    int minute;
    Personne* personne;
    Badge* badge;
    LecteurBadge* lecteur;
    bool resultat;
};

class Scheduler {

    std::vector<Personne*> personnes;
    std::vector<Badge*> badges;
    std::vector<LecteurBadge*> lecteurs;
    std::vector<DemandeAcces> historique;

    std::ofstream logAccesAutorises;
    std::ofstream logAccesRefuses;

    Serveur* serveur;
    std::mt19937 generateur;

    public:
        explicit Scheduler(Serveur* serveur);
        ~Scheduler();

        std::vector<DemandeAcces> getHistorique();

        void ajouterPersonne(Personne* p, Badge* b);
        void ajouterLecteur(LecteurBadge* l);

        // Simulation complète
        void simulationJournee(int heureDebut = 8, int heureFin = 20, int nbTentatives = 20);

    private:
        // Méthodes internes
        void enregistrerAcces();
        // Fonction utilitaire pour trier et afficher proprement
        void afficherHistoriqueTrie() const;
};

#endif //AP4A_PROJET_SCHEDULER_H