//
// Created by ahmed on 15/10/2025.
//

#include "../header/Serveur.h"
#include "../header/Scheduler.h"
#include <iostream>
#include <ctime>

Serveur::Serveur(const std::string& nom) : nomServeur(nom) {
    // Ouverture des fichiers logs
    /*logAccesAutorises.open("../logs/acces_autorises.log", std::ios::app);
    logAccesRefuses.open("../logs/acces_refuses.log", std::ios::app);

    if (!logAccesAutorises || !logAccesRefuses) {
        std::cerr << "Erreur : impossible d'ouvrir les fichiers de log." << std::endl;
    }*/
}

/*Serveur::~Serveur() {
    logAccesAutorises.close();
    logAccesRefuses.close();
}*/

void Serveur::demandeAcces(const Badge& badge, const LecteurBadge& lecteur) {
    bool autorise = false;

    if (!badge.estActif()) {
        std::cout << "Err : Badge inactif pour " << badge.getNomProprietaire() << std::endl;
    } else {
        // Comparaison des niveaux de sécurité
        if (static_cast<int>(badge.getNiveauSecurite()) >= static_cast<int>(lecteur.getNiveauRequis()))
        {
            autorise = true;
        }/*
            std::cout << "OK : [SERVEUR] Acces autorise : "
                      << badge.getNomProprietaire()
                      << " -> " << lecteur.getLocalisation() << std::endl;
        } else {
            std::cout << "NON : [SERVEUR] Acces refuse (niveau insuffisant) : "
                      << badge.getNomProprietaire()
                      << " -> " << lecteur.getLocalisation() << std::endl;
        }*/
    }

    // Enregistrement dans les logs
    //enregistrerAcces(badge, lecteur, autorise);
}

/*void Serveur::enregistrerAcces(const Badge& badge, const LecteurBadge& lecteur, bool autorise) {
    // Heure actuelle
    std::time_t now = std::time(nullptr);
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
    }
}*/