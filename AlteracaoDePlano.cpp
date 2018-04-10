#include "AlteracaoDePlano.h"

namespace opmm {

AlteracaoDePlano::AlteracaoDePlano(const std::string &deviceId, const vector<std::string> &deviceIdsPlanoAlterado)
    :AlteracaoDeEndereco(deviceId, deviceIdsPlanoAlterado)
{}

AlteracaoDePlano::AlteracaoDePlano(const std::string &deviceId, const vector<std::string> &deviceIdsPlanoAlterado,
                                   const QDate &dateDeviceId, const QDate &datePlanoAlterado)
    :AlteracaoDeEndereco(deviceId, deviceIdsPlanoAlterado, dateDeviceId, datePlanoAlterado)
{}

}
