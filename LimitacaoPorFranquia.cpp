#include "LimitacaoPorFranquia.h"

namespace opmm {

LimitacaoPorFranquia::LimitacaoPorFranquia(const std::string &deviceId, const QDate &dateDeviceId, const unordered_map<std::string, std::pair<QDate, QDate> > &mapDeviceIdPeriodoLimitacao)
    :SuspensaoDeServico(deviceId, dateDeviceId, mapDeviceIdPeriodoLimitacao)
{}

}
