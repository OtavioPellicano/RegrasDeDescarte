#ifndef _3MEDICOESVALIDAS_H
#define _3MEDICOESVALIDAS_H

#include <string>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <QDate>
#include <map>

namespace opmm {

using std::string;
using std::unordered_map;
using std::set;
using std::unordered_set;
using std::vector;
using std::pair;

class _3MedicoesValidas
{

public:
    _3MedicoesValidas(const vector<pair<string, QDate> > &deviceIdQDate);

    //posso usar vetor
    vector<string> devicesIdValidos() const;

private:
    vector<string> mDevicesIdValidos;
};

}


#endif // _3MEDICOESVALIDAS_H
