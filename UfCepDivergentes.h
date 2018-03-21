#ifndef UFCEPDIVERGENTES_H
#define UFCEPDIVERGENTES_H

#include <string>
#include <unordered_map>
#include "validade.h"

namespace opmm {

/**
 * @brief The UfCepDivergentes class
 * Para a prestadora que envia o CEP e UF no próprio rawdata,
 * serão descartadas as que o CEP informado não corresponde a
 * UF também informada no rawdata.
 */
class UfCepDivergentes : public Validade
{
public:
    UfCepDivergentes(const std::string &cep, const std::string &uf,
                     std::unordered_map<std::string, std::string> &tabelaCepUfRef);
};

}


#endif // UFCEPDIVERGENTES_H
