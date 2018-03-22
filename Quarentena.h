#ifndef QUARENTENA_H
#define QUARENTENA_H

#include "validade.h"

namespace opmm {

/**
 * @brief The Quarentena class
 * Para o teste de Download é feita a mediana entre
 * o valor do teste e o plano contratado por coletor por dia.
 * Se o resultado dessa conta estiver fora do intervalo aceitável,
 * o coletor é desconsiderado nas medições naquele dia. A velocidade
 * contratada é obtida pela Validação de Voluntários, onde:
 *
 * Se o resultado for menor que 10%, o coletor é considerado como
 * em quarentena naquele dia e essas medições são descartadas.
 */
class Quarentena : public Validade
{
public:
    Quarentena(const double &medianaDown, const double &downStream);
};

}


#endif // QUARENTENA_H
