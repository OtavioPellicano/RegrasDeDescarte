#include "UfCepDivergentes.h"

namespace opmm {

UfCepDivergentes::UfCepDivergentes(const std::string &cep, const std::string &uf, std::unordered_map<std::string, std::string> &tabelaCepUfRef)
{
    if(tabelaCepUfRef.find(cep) != tabelaCepUfRef.end())
    {
        if(tabelaCepUfRef[cep] == uf)
        {
            setMedicaoValida(true);
        }
        else
        {
            setMedicaoValida(false);
        }
    }
    else
    {
        setMedicaoValida(false);
    }
}

}
