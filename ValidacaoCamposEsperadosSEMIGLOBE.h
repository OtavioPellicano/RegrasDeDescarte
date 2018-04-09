#ifndef VALIDACAOCAMPOSESPERADOSSEMIGLOBE_H
#define VALIDACAOCAMPOSESPERADOSSEMIGLOBE_H

#include "validade.h"

namespace opmm {

/**
 * @brief The ValidacaoCamposEsperadosHDM class
 * O processo verifica se os tipos de dados esperados
 * nos registros correspondem ao layout definido para o rawdata.
 *
 * Validação padrão: Nessa etapa é verificada se os campos obrigatórios estão
 * preenchidos, se o tipo de campo é o esperado, se o valor informado está dentro
 * da variação esperada (min/max) e se o valor informado é valido.
 *
 * availSuccesses   (str)
 * avgRTT           ()
 * dateTime         ()
 * deviceID         ()
 * failures         ()
 * jitter           ()
 * macAddress       ()
 * manufacturer     ()
 * packetLoss       ()
 * packetSent       ()
 * softwareVersion  ()
 * sourceIPAddress  ()
 * successes        ()
 * testPoint        ()
 */
class ValidacaoCamposEsperadosSEMIGLOBE: public Validade
{
public:
    ValidacaoCamposEsperadosSEMIGLOBE();
};

}

#endif // VALIDACAOCAMPOSESPERADOSSEMIGLOBE_H
