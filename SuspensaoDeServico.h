#ifndef SUSPENSAODESERVICO_H
#define SUSPENSAODESERVICO_H

#include "validade.h"
#include <string>
#include <QDate>
#include <unordered_map>

namespace opmm {

using std::string;
using std::unordered_map;

/**
 * @brief The SuspensaoDeServico class
 * Caso o voluntário tenha sofrido alguma suspensão no
 * seu serviço por qualquer motivo, as datas de início e fim
 * em que a velocidade permaneceu suspensa estarão discriminadas
 * no arquivo e tal intervalo deverá ter suas medições invalidadas
 * para este voluntário.
 *
 */
class SuspensaoDeServico: public Validade
{
public:
    SuspensaoDeServico(const string &deviceId, const QDate &dateDeviceId,
                       const unordered_map<string, std::pair<QDate, QDate>> &mapDeviceIdPeriodoSuspensao);
};

}


#endif // SUSPENSAODESERVICO_H
