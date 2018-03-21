#include "MedicoesAutonomas.h"

namespace opmm {

MedicoesAutonomas::MedicoesAutonomas(const std::string &source)
{
    if(source == "Auto")
        setMedicaoValida(true);
    else
        setMedicaoValida(false);

}

}
