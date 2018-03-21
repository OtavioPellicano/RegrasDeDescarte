#ifndef TROCADETECNOLOGIA_H
#define TROCADETECNOLOGIA_H

#include "validade.h"
#include <string>

namespace opmm {

/**
 * @brief The TrocaDeTecnologia class
 * As medições que passaram por tecnologias
 * diferentes até serem concluídas deverão ser descartadas
 * network_type_changed != 0 deve ser descartado
 */
class TrocaDeTecnologia: public Validade
{
public:
    TrocaDeTecnologia(const std::string &trocaDeRede);

private:
    int mTrocaDeRede;
};


}


#endif // TROCADETECNOLOGIA_H
