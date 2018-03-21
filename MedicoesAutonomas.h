#ifndef MEDICOESAUTONOMAS_H
#define MEDICOESAUTONOMAS_H

#include <string>
#include "validade.h"

namespace opmm {

/**
 * @brief The MedicoesAutonomas class
 * Utilizar para índice somente os registros
 * gerados a partir de medições autônomas
 * Se o campo estiver com a palavra chave "Auto"
 * a medicao é valida
 * caso contrário é invalida
 */
class MedicoesAutonomas: public Validade
{
public:
    MedicoesAutonomas(const std::string &source);
};

}

#endif // MEDICOESAUTONOMAS_H
