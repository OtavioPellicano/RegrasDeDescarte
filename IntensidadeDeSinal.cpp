#include "IntensidadeDeSinal.h"

namespace opmm {


IntensidadeDeSinal::IntensidadeDeSinal(const std::string &medicaoSinal, const conexao &tipoConexao)
{

    //Testando se o valor é numérico
    try {
        mMedicaoSinal = std::stod(medicaoSinal);
    } catch (...) {
        setMedicaoValida(false);
        return;
    }

    if(tipoConexao == _3G)
    {
        if (mMedicaoSinal >= -102 && mMedicaoSinal <= -25)
        {
            setMedicaoValida(true);
            return;
        }
        else
        {
            setMedicaoValida(false);
            return;
        }

    }
    else if(tipoConexao == _4G)
    {
        if (mMedicaoSinal >= -106 && mMedicaoSinal <= -44)
        {
            setMedicaoValida(true);
            return;
        }
        else
        {
            setMedicaoValida(false);
            return;
        }
    }
    else
    {
        std::cerr << "ERRO Intensidade de sinal" << std::endl;
    }

}


}

