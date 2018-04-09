#include "SuspensaoDeServico.h"

namespace opmm {

SuspensaoDeServico::SuspensaoDeServico(const std::string &deviceId, const QDate &dateDeviceId,
                                       const unordered_map<std::string, std::pair<QDate, QDate>> &mapDeviceIdPeriodoSuspensao)
{
    unordered_map<std::string, std::pair<QDate, QDate>>::const_iterator it;
    it = mapDeviceIdPeriodoSuspensao.find(deviceId);

    if(it != mapDeviceIdPeriodoSuspensao.end())
    {
        if(dateDeviceId >= it->second.first &&
                dateDeviceId <= it->second.second)
        {
            setMedicaoValida(false);
        }
        else
        {
            setMedicaoValida(true);
        }
    }
    else
    {
        setMedicaoValida(true);
    }

}

}

