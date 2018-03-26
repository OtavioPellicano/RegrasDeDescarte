#include "ValidacaoCamposEsperadosTGR.h"

namespace opmm {

ValidacaoCamposEsperadosTGR::ValidacaoCamposEsperadosTGR(const QString &medicao, const testeTGR &tipoTesteTGR)
    :mSep(";"), mTipoTesteTGR(tipoTesteTGR)
{
    setMedicaoValida(parametroValido(medicao) || cabecalhoValido(medicao));
}

bool ValidacaoCamposEsperadosTGR::cabecalhoValido(const QString &medicao)
{
    if(medicao.split(mSep).size() != 80)
        return false;
    return true;
}

bool ValidacaoCamposEsperadosTGR::parametroValido(const QString &medicao)
{


    return true;
}

}
