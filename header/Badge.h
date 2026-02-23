//
// Created by ahmed on 15/10/2025.
//

#ifndef AP4A_PROJET_BADGE_H
#define AP4A_PROJET_BADGE_H

#include <string>
#include <iostream>
#include "Personne.h"

class Badge
{
        int idBadge;
        Personne* proprietaire;   // Association vers une Personne
        bool actif;               // true si le badge est valide

    public:
        // Constructeur
        Badge(int idBadge, Personne* proprietaire, bool actif = true);

        // Getters
        int getIdBadge() const;
        Personne* getProprietaire() const;
        bool estActif() const;

        // Méthodes utilitaires
        void desactiver();
        void activer();
        NiveauSecurite getNiveauSecurite() const;
        std::string getNomProprietaire() const;

        //friend std::ostream& operator<<(std::ostream& os, const Badge& badge);
};

#endif //AP4A_PROJET_BADGE_H