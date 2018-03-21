#include "UfSemPlanoAmostral.h"

namespace opmm {

UfSemPlanoAmostral::UfSemPlanoAmostral(const std::string &uf, const std::vector<std::string> &planoAmostral)
{
    if(std::find(planoAmostral.begin(), planoAmostral.end(), uf) != planoAmostral.end())
        setMedicaoValida(true);
    else
        setMedicaoValida(false);
}

}
