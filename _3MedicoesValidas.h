#ifndef _3MEDICOESVALIDAS_H
#define _3MEDICOESVALIDAS_H

#include <string>
#include <QHash>
#include <QSet>
#include <vector>
#include <QDate>
#include <map>
#include <set>

namespace opmm {

using std::string;
using std::vector;
using std::pair;
using std::map;
using std::set;

/**
 * @brief The _3MedicoesValidas class
 * O indicador SCM9 deve possui ao menos 3 dias
 * de medições válidas na sua composição.
 */
class _3MedicoesValidas
{

public:
    _3MedicoesValidas(const vector<std::pair<QString, QDate> > &deviceIdQDate);
    _3MedicoesValidas(const vector<std::pair<string, QDate> > &deviceIdQDate);

    vector<QString> devicesIdValidos() const;

    vector<string> devicesIdValidosStdStr() const;

private:
    vector<QString> mDevicesIdValidos;

    vector<string> mDevicesIdValidosStdStr;
};

}


#endif // _3MEDICOESVALIDAS_H
