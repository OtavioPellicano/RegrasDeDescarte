#ifndef CELLIDNAOENCONTRADO_H
#define CELLIDNAOENCONTRADO_H

#include "validade.h"

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

namespace opmm {

/**
 * @brief The CellIdNaoEncontrado class
 * Serão descartadas as medições recebidas que o
 * CellId não seja localizado na base do CGI
 * Tenho que buscar o CGI na base CGI, Se nao existir,
 * é para descartar
 *
 */
class CellIdNaoEncontrado: public Validade
{
public:
    CellIdNaoEncontrado(const std::string &cellId, const std::vector<std::string> &cellsIdBaseCGI);
    CellIdNaoEncontrado(const std::string &cgi, const std::unordered_map<std::string, std::string> &mapCgiUf);

private:

};

}


#endif // CELLIDNAOENCONTRADO_H
