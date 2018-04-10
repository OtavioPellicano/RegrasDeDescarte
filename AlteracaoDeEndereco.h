#ifndef ALTERACAODEENDERECO_H
#define ALTERACAODEENDERECO_H

#include "validade.h"
#include <vector>
#include <string>
#include <algorithm>
#include <QDate>

namespace opmm {

using std::vector;
using std::string;

/**
 * @brief The AlteracaoDeEndereco class
 * Regra de acordo com a escolha da prestadora:
 *
 * Opção A: Caso o endereço tenha sido marcado como alterado
 * na Validação de Voluntários, todas as medições do mês para
 * este voluntário serão invalidadas.
 *
 * Opção B: Será feita a comparação entre os rawdatas recebidos.
 * Ao identificar que houve mudança no CEP, o sistema descarta
 * somente as medições do dia.
 */
class AlteracaoDeEndereco: public Validade
{
public:
    //Opcao A
    AlteracaoDeEndereco(const string &deviceId, const vector<string> &deviceIdsEnderecoAlterado);

    //Opcao B
    AlteracaoDeEndereco(const string &deviceId, const vector<string> &deviceIdsEnderecoAlterado,
                        const QDate &dateDeviceId, const QDate &dateEnderecoAlterado);
};

}

#endif // ALTERACAODEENDERECO_H
