#ifndef LIMITACAOPORFRANQUIA_H
#define LIMITACAOPORFRANQUIA_H

#include "Regras/SuspensaoDeServico.h"

namespace opmm {

/**
 * @brief The LimitacaoPorFranquia class
 * Caso o voluntário tenha atingido o valor da sua franquia,
 * as datas de início e fim em que a velocidade permaneceu reduzida
 * estarão discriminadas no arquivo e tal intervalo deverá ter suas
 * medições invalidadas para este voluntário.
 *
 */
class LimitacaoPorFranquia: public SuspensaoDeServico
{
public:
    LimitacaoPorFranquia(const string &deviceId, const QDate &dateDeviceId,
                         const unordered_map<string, std::pair<QDate, QDate>> &mapDeviceIdPeriodoLimitacao);
};

}


#endif // LIMITACAOPORFRANQUIA_H
