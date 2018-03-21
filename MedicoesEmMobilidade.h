#ifndef MEDICOESEMMOBILIDADE_H
#define MEDICOESEMMOBILIDADE_H

#include <string>
#include "validade.h"

namespace opmm {

/**
 * @brief The MedicoesEmMobilidade class
 * Descartar medições em mobilidade (cellIdChanges igual a 1)
 */
class MedicoesEmMobilidade: public Validade
{
public:
    MedicoesEmMobilidade(const std::string &medicaoCellId);

private:
    int mMedicaoCellId;
};

}

#endif // MEDICOESEMMOBILIDADE_H
