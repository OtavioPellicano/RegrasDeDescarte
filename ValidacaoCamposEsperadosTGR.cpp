#include "ValidacaoCamposEsperadosTGR.h"

namespace opmm {

ValidacaoCamposEsperadosTGR::ValidacaoCamposEsperadosTGR(const QString &medicao, const testeTGR &tipoTesteTGR)
    :mSep(";"), mTipoTesteTGR(tipoTesteTGR)
{
    setMedicaoValida(parametroValido(medicao) || cabecalhoValido(medicao));
}

bool ValidacaoCamposEsperadosTGR::cabecalhoValido(const QString &medicao)
{

    mStrMed = medicao;
    mStrMed = mStrMed.remove("\"");
    mStrMed = mStrMed.remove("\r");
    mStrMed = mStrMed.remove("\n");
    if(mStrMed.split(mSep).size() == 80)
    {
        if(mStrMed == "data;versao;enderecoipservidor;portaservidor;enderecoipcliente;maccliente;numbytesup;numbytesdown;numpacotes;tamanhopacotertt;tamanhopacotevazaodownudp;tamanhopacotevazaoupudp;numrequisicoesparalelas;intervalodisponibilidade;intervalomedicoes;latenciamedia;latenciamedia_crosstrafficup;latenciamedia_crosstrafficdown;latenciamedia_tinicio;latenciamedia_tfim;jittermedia;jittermedia_crosstrafficup;jittermedia_crosstrafficdown;jittermedia_tinicio;jittermedia_tfim;vazaodownmediatcp;vazaodownmediatcp_crosstrafficup;vazaodownmediatcp_crosstrafficdown;vazaodownmediatcp_tinicio;vazaodownmediatcp_tfim;vazaodownmediaudp;vazaodownmediaudp_crosstrafficup;vazaodownmediaudp_crosstrafficdown;vazaodownmediaudp_tinicio;vazaodownmediaudp_tfim;vazaoupmediatcp;vazaoupmediatcp_crosstrafficup;vazaoupmediatcp_crosstrafficdown;vazaoupmediatcp_tinicio;vazaoupmediatcp_tfim;vazaoupmediaudp;vazaoupmediaudp_crosstrafficup;vazaoupmediaudp_crosstrafficdown;vazaoupmediaudp_tinicio;vazaoupmediaudp_tfim;perdatotalrtt;perdatotalrtt_crosstrafficup;perdatotalrtt_crosstrafficdown;perdatotalrtt_tinicio;perdatotalrtt_tfim;perdatotalvazaodownudp;perdatotalvazaodownudp_crosstrafficup;perdatotalvazaodownudp_crosstrafficdown;perdatotalvazaodownudp_tinicio;perdatotalvazaodownudp_tfim;amostraslatencia;amostraslatencia_crosstrafficup;amostraslatencia_crosstrafficdown;amostrasjitter;amostrasjitter_crosstrafficup;amostrasjitter_crosstrafficdown;dns_crosstrafficup;dns_crosstrafficdown;temporesposta_www-google-com;temporesposta_www-outlook-com;temporesposta_www-gmail-com;temporesposta_www-facebook-com;temporesposta_www-uol-com-br;temporesposta_www-globo-com;temporesposta_www-netflix-com;temporesposta_www-youtube-com;disponibilidade;tipodeacesso;filename;traceroute_crosstrafficup;traceroute_crosstrafficdown;traceroute_returned_hostnames;traceroute_returned_ips;traceroute_response_time;traceroute_packets_per_hop")
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool ValidacaoCamposEsperadosTGR::parametroValido(const QString &medicao)
{

    mStrMed = medicao;
    mStrMed = mStrMed.remove("\"");

    bool ok[4];

    mAvailSuccesses = mStrMed.split(mSep)[71].toInt(ok);
    mAvgRTT = mStrMed.split(mSep)[15].toFloat(ok + 1);
    mJitter = mStrMed.split(mSep)[20].toFloat(ok + 2);
    mPacketLoss = mStrMed.split(mSep)[45].toFloat(ok + 3);

    if(ok[0] && ok[1] && ok[2] && ok[3])
    {
        return true;
    }

    return false;
}

}
