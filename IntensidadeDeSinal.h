#ifndef INTENSIDADEDESINAL_H
#define INTENSIDADEDESINAL_H

#include "validade.h"
#include <string>
#include <iostream>

namespace opmm {

enum conexao{_3G, _4G};
/**
 * @brief The IntensidadeDeSinal class
 * Intensidade do sinal mínima detectada:
 * 3G: -102dBm
 * 4G: -106dBm
 *
 * range:
 * 3G – RSCP de -25 a -120dbm
 * 4G – RSRP de -44 a -140dbm
 */
class IntensidadeDeSinal: public Validade
{
public:
    IntensidadeDeSinal(const std::string &medicaoSinal, const conexao &tipoConexao);


private:
    double mMedicaoSinal;
};

}


#endif // INTENSIDADEDESINAL_H
