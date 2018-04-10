#ifndef ALTERACAODEPLANO_H
#define ALTERACAODEPLANO_H

#include "AlteracaoDeEndereco.h"

namespace opmm {

/**
 * @brief The AlteracaoDePlano class
 * Regra de acordo com a escolha da prestadora:
 *
 * Opção A: Caso o plano tenha sido marcado como alterado na
 * Validação de Voluntários, todas as medições do mês para
 * este voluntário serão invalidadas.
 *
 * Opção B: Será feita através da comparação entre os rawdatas.
 * Ao identificar que houve mudança da velocidade de Download ou
 * Upload, o sistema descarta somente as medições do dia.
 *
 */
class AlteracaoDePlano: public AlteracaoDeEndereco
{
public:
    //Opcao A
    AlteracaoDePlano(const string &deviceId, const vector<string> &deviceIdsPlanoAlterado);

    //Opcao B
    AlteracaoDePlano(const string &deviceId, const vector<string> &deviceIdsPlanoAlterado,
                     const QDate &dateDeviceId, const QDate &datePlanoAlterado);

};

}


#endif // ALTERACAODEPLANO_H
