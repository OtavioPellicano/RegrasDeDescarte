#include "ValidacaoDateTime.h"

namespace opmm {


ValidacaoDateTime::ValidacaoDateTime(const QDate &dateTime, const int &anoRef, const int &mesRef)
{
    if(dateTime.month() == mesRef && dateTime.year() == anoRef)
    {
        setMedicaoValida(true);
    }
    else
    {
        setMedicaoValida(false);
    }

}

}

