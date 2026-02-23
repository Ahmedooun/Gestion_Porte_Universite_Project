//
// Created by ahmed on 15/10/2025.
//

#ifndef AP4A_PROJET_ETUDIANT_H
#define AP4A_PROJET_ETUDIANT_H

#include "Badge.h"
#include "Personne.h"


class Etudiant : public Personne {
    public:
        Etudiant(const std::string& nom, int id);
        void afficherInfo() const override;
};

#endif //AP4A_PROJET_ETUDIANT_H