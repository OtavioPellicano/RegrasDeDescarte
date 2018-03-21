#include "pingbackdivergente.h"

namespace opmm {

PingBackDivergente::PingBackDivergente(std::string &ipColetor, std::vector<std::string> &cidrBitPrestadora)
{

    try {
        mIpv4Coletor.setup(ipColetor);
    }
    catch (...) {
        setMedicaoValida(false);
        return;
    }

    for(std::vector<std::string>::iterator itVec = cidrBitPrestadora.begin();
        itVec != cidrBitPrestadora.end(); ++itVec)
    {
        try {
            mCidrBitPrest.setup(*itVec);
        }
        catch (...) {
            setMedicaoValida(false);
            return;
        }

        if(mIpv4Coletor.ulBroadCast() < mCidrBitPrest.ulBroadCast() &&
                mIpv4Coletor.ulBroadCast() > mCidrBitPrest.ulNetwork())
        {
            setMedicaoValida(true);
            return;
        }

    }
    setMedicaoValida(false);
    return;

}


}
