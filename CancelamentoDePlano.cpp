#include "CancelamentoDePlano.h"

namespace opmm {

CancelamentoDePlano::CancelamentoDePlano(const std::string &deviceId, const QDate &dateDeviceId,
                                         const unordered_map<std::string, std::pair<QDate, QDate> > &mapDeviceIdPeriodoCancelamento)
    :SuspensaoDeServico(deviceId, dateDeviceId, mapDeviceIdPeriodoCancelamento)
{}

}

