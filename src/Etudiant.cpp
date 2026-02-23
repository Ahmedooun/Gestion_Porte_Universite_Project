//
// Created by ahmed on 15/10/2025.
//

#include "../header/Etudiant.h"
#include <iostream>

Etudiant::Etudiant(const std::string& nom, int id)
    : Personne(nom, id, NiveauSecurite::ETUDIANT) {} // Niveau de sécurité 1

void Etudiant::afficherInfo() const {
    std::cout << "[Etudiant] Nom : " << nom
              << " | ID : " << id
              << " | Niveau de securite : " << niveauToString(niveauSecurite)
              << std::endl;
}