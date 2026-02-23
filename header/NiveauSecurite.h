//
// Created by ahmed on 15/10/2025.
//

#ifndef AP4A_PROJET_NIVEAUSECURITE_H
#define AP4A_PROJET_NIVEAUSECURITE_H

#include <string>

// Enum class : évite les conversions implicites avec int
enum class NiveauSecurite {
    ETUDIANT = 1,
    ENSEIGNANT = 2,
    SECURITE = 3
};

// Fonction utilitaire pour convertir un niveau en texte lisible
inline std::string niveauToString(NiveauSecurite niveau) {
    switch (niveau) {
    case NiveauSecurite::ETUDIANT:
        return "Etudiant (Niveau 1)";
    case NiveauSecurite::ENSEIGNANT:
        return "Enseignant (Niveau 2)";
    case NiveauSecurite::SECURITE:
        return "Securite (Niveau 3)";
    default:
        return "Inconnu";
    }
}

#endif //AP4A_PROJET_NIVEAUSECURITE_H