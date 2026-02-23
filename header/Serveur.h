//
// Created by ahmed on 15/10/2025.
//

#ifndef AP4A_PROJET_SERVEUR_H
#define AP4A_PROJET_SERVEUR_H

#include <string>
#include <fstream>
#include <vector>
#include "Badge.h"
#include "LecteurBadge.h"
#include "NiveauSecurite.h"

class Serveur
{

    /*std::ofstream logAccesAutorises;
    std::ofstream logAccesRefuses;*/
    std::string nomServeur;

    public:
        // Constructeur et destructeur
        explicit Serveur(const std::string& nom);
        //~Serveur();

        // Méthode principale
        void demandeAcces(const Badge& badge, const LecteurBadge& lecteur);

        // Méthodes internes
        //void enregistrerAcces(const Badge& badge, const LecteurBadge& lecteur, bool autorise);
};

#endif //AP4A_PROJET_SERVEUR_H