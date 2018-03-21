#ifndef UFSEMPLANOAMOSTRAL_H
#define UFSEMPLANOAMOSTRAL_H


#include "validade.h"
#include <string>
#include <vector>
#include <algorithm>

namespace opmm {

/**
 * @brief The UfSemPlanoAmostral class
 * Quando uma medição estiver alocada para uma UF que não possui plano amostral.
 */
class UfSemPlanoAmostral: public Validade
{
public:
    UfSemPlanoAmostral(const std::string &uf, const std::vector<std::string> &planoAmostral);
};

}



#endif // UFSEMPLANOAMOSTRAL_H
