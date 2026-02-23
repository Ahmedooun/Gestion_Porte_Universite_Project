//
// Created by ahmed on 15/10/2025.
//

#ifndef AP4A_PROJET_LECTEURBADGE_H
#define AP4A_PROJET_LECTEURBADGE_H

#include <string>
#include <iostream>
#include "Badge.h"
#include "NiveauSecurite.h"

class LecteurBadge
{
    std::string idLecteur;        // Identifiant du lecteur
    std::string localisation;     // Lieu : "Bâtiment A", "Salle 203", etc.
    NiveauSecurite niveauRequis;  // Niveau d’accès minimal pour entrer

    public:
        // Constructeur
        LecteurBadge(const std::string& id, const std::string& loc, NiveauSecurite niveau);

        // Getters
        std::string getIdLecteur() const;
        std::string getLocalisation() const;
        NiveauSecurite getNiveauRequis() const;

        // Vérification d’un badge (test simple sans serveur)
        //bool verifierAcces(const Badge& badge) const;

        //friend std::ostream& operator<<(std::ostream& os, const LecteurBadge& lecteur);
};

#endif //AP4A_PROJET_LECTEURBADGE_H