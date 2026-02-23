//
// Created by ahmed on 15/10/2025.
//

#include "../header/Scheduler.h"
#include <iostream>
#include <iomanip> // pour setw et setfill

Scheduler::Scheduler(Serveur* serveur)
    : serveur(serveur) {
    generateur.seed(static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count()));
    logAccesAutorises.open("../logs/acces_autorises.log", std::ios::app);
    logAccesRefuses.open("../logs/acces_refuses.log", std::ios::app);

    if (!logAccesAutorises || !logAccesRefuses) {
        std::cerr << "Erreur : impossible d'ouvrir les fichiers de log." << std::endl;
    }
}

Scheduler::~Scheduler() {
    logAccesAutorises.close();
    logAccesRefuses.close();
}


std::vector<DemandeAcces> Scheduler::getHistorique(){return historique;}

void Scheduler::ajouterPersonne(Personne* p, Badge* b) {
    personnes.push_back(p);
    badges.push_back(b);
}

void Scheduler::ajouterLecteur(LecteurBadge* l) {
    lecteurs.push_back(l);
}

void Scheduler::simulationJournee(int heureDebut, int heureFin, int nbTentatives) {
    if (personnes.empty() || badges.empty() || lecteurs.empty()) {
        std::cerr << "Erreur : données incompletes pour la simulation !" << std::endl;
        return;
    }

    std::uniform_int_distribution<> distPersonne(0, static_cast<int>(personnes.size() - 1));
    std::uniform_int_distribution<> distLecteur(0, static_cast<int>(lecteurs.size() - 1));
    std::uniform_int_distribution<> distHeure(heureDebut, heureFin);
    std::uniform_int_distribution<> distMinute(0, 59);

    historique.clear();

    for (int i = 0; i < nbTentatives; ++i) {
        int indexPersonne = distPersonne(generateur);
        int indexLecteur = distLecteur(generateur);
        int heure = distHeure(generateur);
        int minute = distMinute(generateur);

        Personne* p = personnes[indexPersonne];
        Badge* b = badges[indexPersonne];
        LecteurBadge* l = lecteurs[indexLecteur];

        bool resultat = false;
        if (b->estActif() &&
            static_cast<int>(b->getNiveauSecurite()) >= static_cast<int>(l->getNiveauRequis())) {
            resultat = true;
        }

        // Appel serveur (écrit dans les logs, pas d'affichage direct ici)
        serveur->demandeAcces(*b, *l);

        // Enregistre la tentative dans l’historique
        historique.push_back({heure, minute, p, b, l, resultat});

        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }

    enregistrerAcces();
    // Une fois la journée terminée, affichage unique
    afficherHistoriqueTrie();
}

void Scheduler::enregistrerAcces () {
    if (historique.empty()) {
        std::cout << "Aucune demande d'acces enregistree." << std::endl;
        return;
    }

    // Tri des événements par heure, puis minute
    std::vector<DemandeAcces> tri = historique;
    std::sort(tri.begin(), tri.end(), [](const DemandeAcces& a, const DemandeAcces& b) {
        if (a.heure == b.heure)
            return a.minute < b.minute;
        return a.heure < b.heure;
    });

    for (const auto& d : tri) {
        std::ofstream& fichier = d.resultat ? logAccesAutorises : logAccesRefuses;
        if (fichier) {
            std::ostringstream heureStr;
            heureStr << std::setw(2) << std::setfill('0') << d.heure << "h"
                     << std::setw(2) << std::setfill('0') << d.minute;

            fichier << "[" << heureStr.str() << "] "
                << (d.resultat ? "Autorise : " : "Refuse : ")
                << d.personne->getNom()
                << " (Badge " << d.badge->getIdBadge() << ")"
                << " -> " << d.lecteur->getLocalisation()
                << " [NiveauBadge=" << static_cast<int>(d.badge->getNiveauSecurite())
                << ", NiveauRequis=" << static_cast<int>(d.lecteur->getNiveauRequis()) << "]"
                << std::endl;
        }
    }
    // Heure actuelle
    /*std::time_t now = std::time(nullptr);
    std::string heure = std::ctime(&now);
    heure.pop_back(); // Supprimer le \n à la fin

    std::ofstream& fichier = autorise ? logAccesAutorises : logAccesRefuses;
    if (fichier) {
        fichier << "[" << heure << "] "
                << (autorise ? "Autorise : " : "Refuse : ")
                << badge.getNomProprietaire()
                << " (Badge " << badge.getIdBadge() << ")"
                << " -> " << lecteur.getLocalisation()
                << " [NiveauBadge=" << static_cast<int>(badge.getNiveauSecurite())
                << ", NiveauRequis=" << static_cast<int>(lecteur.getNiveauRequis()) << "]"
                << std::endl;
    }*/
}

void Scheduler::afficherHistoriqueTrie() const {
    if (historique.empty()) {
        std::cout << "Aucune demande d'acces enregistree." << std::endl;
        return;
    }

    // Tri des événements par heure, puis minute
    std::vector<DemandeAcces> tri = historique;
    std::sort(tri.begin(), tri.end(), [](const DemandeAcces& a, const DemandeAcces& b) {
        if (a.heure == b.heure)
            return a.minute < b.minute;
        return a.heure < b.heure;
    });

    std::cout << "\n===== JOURNEE DE SIMULATION =====\n";
    std::cout << std::left << std::setw(10) << "Heure"
              << std::setw(20) << "Personne"
              << std::setw(25) << "Lieu"
              << std::setw(15) << "Resultat" << std::endl;
    std::cout << std::string(70, '-') << std::endl;

    for (const auto& d : tri) {
        std::ostringstream heureStr;
        heureStr << std::setw(2) << std::setfill('0') << d.heure << "h"
                 << std::setw(2) << std::setfill('0') << d.minute;

        std::cout << std::left << std::setw(10) << heureStr.str()
                  << std::setw(20) << d.personne->getNom()
                  << std::setw(25) << d.lecteur->getLocalisation()
                  << (d.resultat ? "OK : Autorise" : "NO : Refuse")
                  << std::endl;
    }

    std::cout << std::string(70, '-') << std::endl;
    std::cout << "Total des tentatives : " << tri.size() << std::endl;
}
