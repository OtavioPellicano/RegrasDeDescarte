#include "CellIdNaoEncontrado.h"

namespace opmm {

CellIdNaoEncontrado::CellIdNaoEncontrado(const std::string &cellId, const std::vector<std::string> &cellsIdBaseCGI)
{
    if(std::find(cellsIdBaseCGI.begin(), cellsIdBaseCGI.end(), cellId) != cellsIdBaseCGI.end())
        setMedicaoValida(true);
    else
        setMedicaoValida(false);

}

CellIdNaoEncontrado::CellIdNaoEncontrado(const std::string &cgi, const std::unordered_map<std::string, std::string> &mapCgiUf)
{
    if(mapCgiUf.find(cgi) != mapCgiUf.end())
    {
        setMedicaoValida(true);
    }
    else
    {
        setMedicaoValida(false);
    }



}

}
