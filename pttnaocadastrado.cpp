#include "pttnaocadastrado.h"

namespace opmm {


PttNaoCadastrado::PttNaoCadastrado(const std::string &ptt, const std::vector<std::string> &pttsCadastados)
{
    if(std::find(pttsCadastados.begin(), pttsCadastados.end(), ptt) != pttsCadastados.end())
    {
        setMedicaoValida(true);
    }
    else
    {
        setMedicaoValida(false);
    }

}

PttNaoCadastrado::PttNaoCadastrado(const std::string &ptt, const std::unordered_map<std::string, std::string> &pttsCadastadosUf)
{
    if(pttsCadastadosUf.find(ptt) != pttsCadastadosUf.end())
    {
        setMedicaoValida(true);
    }
    else
    {
        setMedicaoValida(false);
    }
}


}
