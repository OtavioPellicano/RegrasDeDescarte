#ifndef LIMITEDEVELOCIDADE_H
#define LIMITEDEVELOCIDADE_H

#include "validade.h"
#include "string"
namespace opmm {

/**
 * @brief The LimiteDeVelocidade class
 * Medianas com valor acima da contratada devem
 * ser convertidas para o valor contratado,
 * dessa forma o novo valor será usado para o cálculo dos índices.
 * Os Coletores que sofrerem essa ação serão exibidas em relatório específico.
 * CÁLCULO FEITO EM CIMA DAS MEDIANAS!
 */
class LimiteDeVelocidade : public Validade
{
public:
    LimiteDeVelocidade(const std::string &mediana, const std::string &stream);

    double mediana() const;

private:
    double mMediana;
    double mStream;

};

}


#endif // LIMITEDEVELOCIDADE_H
