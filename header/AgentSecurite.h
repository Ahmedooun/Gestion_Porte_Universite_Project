//
// Created by ahmed on 15/10/2025.
//

#ifndef AP4A_PROJET_AGENTSECURITE_H
#define AP4A_PROJET_AGENTSECURITE_H

#include "Personne.h"

class AgentSecurite : public Personne {
    public:
        AgentSecurite(const std::string& nom, int id);
        void afficherInfo() const override;
};

#endif //AP4A_PROJET_AGENTSECURITE_H