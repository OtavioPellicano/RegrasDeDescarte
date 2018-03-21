#include "LimiteDeVelocidade.h"

namespace opmm {

LimiteDeVelocidade::LimiteDeVelocidade(const std::string &mediana, const std::string &stream)
{
    try {
        mStream = std::stod(stream);
        mMediana = std::stod(mediana);
    } catch (...) {
        setMedicaoValida(false);
        return;
    }

    if((mMediana / mStream) > 1)
    {
        mMediana = mStream;
    }

    setMedicaoValida(true);

}

double LimiteDeVelocidade::mediana() const
{
    return mMediana;
}


}

