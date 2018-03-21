#ifndef VALIDACAODATETIME_H
#define VALIDACAODATETIME_H

#include "validade.h"
#include <string>
#include <QDate>
#include <iostream>

using namespace std;

namespace opmm {
/**
 * @brief The ValidacaoDateTime class
 * Recebo a medição normalizada e verifico
 * se pertence ao range de analise
 */
class ValidacaoDateTime : public Validade
{
public:

    ValidacaoDateTime(const QDate &dateTime, const int &anoRef, const int &mesRef);

};

}


#endif // VALIDACAODATETIME_H
