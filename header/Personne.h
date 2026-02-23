//
// Created by ahmed on 15/10/2025.
//

#ifndef AP4A_PROJET_PERSONNE_H
#define AP4A_PROJET_PERSONNE_H

#include <string>
#include <iostream>

#include "NiveauSecurite.h"


class Personne
{
    protected:
        std::string nom;
        int id;
        NiveauSecurite niveauSecurite;

    public:
        Personne(const std::string& nom, int id, NiveauSecurite niveau);

        virtual ~Personne();

        std::string getNom() const;
        int getId() const;
        NiveauSecurite getNiveauSecurite() const;

        virtual void afficherInfo() const = 0;
};

#endif //AP4A_PROJET_PERSONNE_H