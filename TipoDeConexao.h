#ifndef TIPODECONEXAO_H
#define TIPODECONEXAO_H

#include <string>
#include "validade.h"

namespace opmm {

class TipoDeConexao: public Validade
{
public:
    TipoDeConexao(const std::string &tipoConexao);
};

}


#endif // TIPODECONEXAO_H
