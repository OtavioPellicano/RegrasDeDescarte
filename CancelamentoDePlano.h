#ifndef CANCELAMENTODEPLANO_H
#define CANCELAMENTODEPLANO_H

#include "SuspensaoDeServico.h"

namespace opmm {

/**
 * @brief The CancelamentoDePlano class
 * Caso o voluntário tenha cancelado seu plano,
 * a data do cancelamento estará discriminada no arquivo e,
 * a partir de tal data, as medições serão invalidadas.
 */
class CancelamentoDePlano: public SuspensaoDeServico
{
public:
    CancelamentoDePlano(const std::string &deviceId, const QDate &dateDeviceId,
                        const unordered_map<std::string, std::pair<QDate, QDate>> &mapDeviceIdPeriodoCancelamento);
};

}


#endif // CANCELAMENTODEPLANO_H
