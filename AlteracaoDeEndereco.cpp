#include "AlteracaoDeEndereco.h"

namespace opmm {

AlteracaoDeEndereco::AlteracaoDeEndereco(const std::string &deviceId, const vector<std::string> &deviceIdsEnderecoAlterado)
{
    if(std::find(deviceIdsEnderecoAlterado.begin(), deviceIdsEnderecoAlterado.end(), deviceId) != deviceIdsEnderecoAlterado.end())
        setMedicaoValida(false);
    else
        setMedicaoValida(true);
}

AlteracaoDeEndereco::AlteracaoDeEndereco(const std::string &deviceId, const vector<std::string> &deviceIdsEnderecoAlterado,
                                         const QDate &dateDeviceId, const QDate &dateEnderecoAlterado)
{
    if(std::find(deviceIdsEnderecoAlterado.begin(), deviceIdsEnderecoAlterado.end(), deviceId)
            != deviceIdsEnderecoAlterado.end())
        if(dateDeviceId == dateEnderecoAlterado)
            setMedicaoValida(false);
        else
            setMedicaoValida(true);
    else
        setMedicaoValida(true);
}

}
