#include "_3MedicoesValidas.h"


namespace opmm {

_3MedicoesValidas::_3MedicoesValidas(const vector<std::pair<QString, QDate> > &deviceIdQDate)
{

    QHash<QString, QSet<QDate>> mapDeviceCount;
    for(vector<pair<QString, QDate> >::const_iterator itVec = deviceIdQDate.begin();
        itVec != deviceIdQDate.end(); ++itVec)
    {
        mapDeviceCount[itVec->first].insert(itVec->second);
    }

    try {
        mDevicesIdValidos.reserve(deviceIdQDate.capacity());
    } catch (...) {
        throw;
    }
    for(QHash<QString, QSet<QDate>>::iterator itMap = mapDeviceCount.begin();
        itMap != mapDeviceCount.end(); ++itMap)
    {
        if((itMap.value()).size() >= 3)
        {
            mDevicesIdValidos.push_back(itMap.key());
        }
    }
    mDevicesIdValidos.shrink_to_fit();

}

_3MedicoesValidas::_3MedicoesValidas(const vector<std::pair<std::string, QDate> > &deviceIdQDate)
{
    map<string, set<QDate>> mapDeviceCount;
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
        mDevicesIdValidosStdStr.reserve(deviceIdQDate.capacity());
    } catch (...) {
        throw;
    }
    for(map<string, set<QDate>>::iterator itMap = mapDeviceCount.begin();
        itMap != mapDeviceCount.end(); ++itMap)
    {
        if((itMap->second).size() >= 3)
        {
            mDevicesIdValidosStdStr.push_back(itMap->first);
        }
    }
    mDevicesIdValidosStdStr.shrink_to_fit();

}

vector<QString> _3MedicoesValidas::devicesIdValidos() const
{
    return mDevicesIdValidos;
}

vector<string> _3MedicoesValidas::devicesIdValidosStdStr() const
{
    return mDevicesIdValidosStdStr;
}


}
