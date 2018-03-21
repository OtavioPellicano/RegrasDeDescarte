#include "TrocaDeTecnologia.h"

namespace opmm {

TrocaDeTecnologia::TrocaDeTecnologia(const std::string &trocaDeRede)
{
    try {
        mTrocaDeRede = std::stoi(trocaDeRede);
    } catch (...) {
        setMedicaoValida(false);
        return;
    }

    if(mTrocaDeRede == 0)
        setMedicaoValida(true);
    else
        setMedicaoValida(false);

}

}
