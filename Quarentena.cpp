#include "Quarentena.h"

namespace opmm {

Quarentena::Quarentena(const double &medianaDown, const double &downStream)
{
    if(medianaDown/downStream < 0.1)
    {
        setMedicaoValida(false);
    }
    else
    {
        setMedicaoValida(true);
    }
}

}

