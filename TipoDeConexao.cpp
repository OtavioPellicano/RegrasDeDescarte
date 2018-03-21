#include "TipoDeConexao.h"

namespace opmm {

/**
 * @brief TipoDeConexao::TipoDeConexao
 * @param tipoConexao
 * Utilizar somente as medições do tipo de conexão 3G ou 4G.
 */

TipoDeConexao::TipoDeConexao(const std::string &tipoConexao)
{
    if(tipoConexao == "3G" || tipoConexao == "4G")
        setMedicaoValida(true);
    else
        setMedicaoValida(false);

}

}
