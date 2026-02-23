//
// Created by ahmed on 15/10/2025.
//

#ifndef AP4A_PROJET_ENSEIGNANT_H
#define AP4A_PROJET_ENSEIGNANT_H

#include "Personne.h"

class Enseignant : public Personne {
    public:
        Enseignant(const std::string& nom, int id);
        void afficherInfo() const override;
};

#endif //AP4A_PROJET_ENSEIGNANT_H