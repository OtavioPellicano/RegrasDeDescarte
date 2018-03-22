#include "_3MedicoesValidas.h"


namespace opmm {

_3MedicoesValidas::_3MedicoesValidas(const vector<std::pair<std::string, QDate> > &deviceIdQDate)
{


    std::map<string, set<QDate>> mapDeviceCount;
    for(vector<pair<string, QDate> >::const_iterator itVec = deviceIdQDate.begin();
        itVec != deviceIdQDate.end(); ++itVec)
    {
        try {
            mapDeviceCount[itVec->first].insert(itVec->second);
        } catch (...) {
            throw;
        }
    }

    try {
        mDevicesIdValidos.reserve(deviceIdQDate.capacity());
    } catch (...) {
        throw;
    }
    for(std::map<string, set<QDate>>::iterator itMap = mapDeviceCount.begin();
        itMap != mapDeviceCount.end(); ++itMap)
    {
        if((itMap->second).size() >= 3)
        {
            mDevicesIdValidos.push_back(itMap->first);
        }
    }
    mDevicesIdValidos.shrink_to_fit();

}

vector<std::string> _3MedicoesValidas::devicesIdValidos() const
{
    return mDevicesIdValidos;
}

}
