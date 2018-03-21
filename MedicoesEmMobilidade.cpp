#include "MedicoesEmMobilidade.h"

namespace opmm {

MedicoesEmMobilidade::MedicoesEmMobilidade(const std::string &medicaoCellId)
{
    try {
        mMedicaoCellId = std::stoi(medicaoCellId);
    } catch (...) {
        setMedicaoValida(false);
        return;
    }

    if(mMedicaoCellId == 1)
    {
        setMedicaoValida(false);
        return;
    }
    else
    {
        setMedicaoValida(true);
        return;
    }

}


}
