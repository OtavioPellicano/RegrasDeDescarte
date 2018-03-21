#ifndef PINGBACKDIVERGENTE_H
#define PINGBACKDIVERGENTE_H

#include "validade.h"
#include "ipv4_class/ipv4.h"
#include <vector>
#include <string>

namespace opmm {
/**
 * @brief The PingBackDivergente class
 * Para toda medição deve ser verificado se o IP do coletor corresponde
 * a prestadora. Caso seja identificada que a medição é de prestadora
 * diferente, a mesma é descartada do índice.
 */
class PingBackDivergente: public Validade
{
public:
    PingBackDivergente(string &ipColetor, std::vector<string> &cidrBitPrestadora);

private:
    unsigned long mUlIpColetor;
    unsigned long mUlCidrBitPrestadora;


    opmm::Ipv4 mIpv4Coletor;
    opmm::Ipv4 mCidrBitPrest;

};

}


#endif // PINGBACKDIVERGENTE_H
