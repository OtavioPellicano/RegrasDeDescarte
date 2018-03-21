#include "Duplicidades.h"

namespace opmm {

Duplicidades::Duplicidades(const vector<string> &pathsIn, const string &pathOut, const layout &tipoLayout)
    :mStrPathOut(pathOut)
{

    switch (tipoLayout) {
    case ABR:
        setPosDeviceId(0);
        setPosDateHora(1);
        break;
    case TGR:
        setPosDeviceId(5);
        setPosDateHora(0);
        break;
    case HDM:
        setPosDeviceId(6);
        setPosDateHora(0);
        break;
    case NETMETRICS:
        setPosDeviceId(0);
        setPosDateHora(16);
        break;
    case SEMIGLOBE:
        setPosDeviceId(17);
        setPosDateHora(3);
        break;
    default:
        while(1)
            cerr << "DUPLICIDADES - OPERADORA NAO IMPLEMENTADA!" << endl;
        break;
    }


    for(vector<string>::const_iterator itVec = pathsIn.begin(); itVec != pathsIn.end(); ++itVec)
    {

        cout << "Processando: " << *itVec << endl;
        mPathIn.open(*itVec);
        if(mPathIn.is_open())
        {
            while(getline(mPathIn, str))
            {

                try {
                    mMedicoesOut.insert(str);
                } catch (bad_alloc &e) {

                    cerr << "Ultrapassou o limite de medicoes para aplicar a regra Duplicidades\n" <<
                            "erro: " << e.what() << endl;
                    clog << "Descarregando Medidas..." << endl;
                    descarregarMedicoes(mMedicoesOut);
                }


            }

            mPathIn.close();
        }
        else
        {
            mPathsNaoProcessados.push_back(*itVec);
        }
    }

    if(mMedicoesOut.size() != 0)
    {
        clog << "Descarregando Medidas..." << endl;
        descarregarMedicoes(mMedicoesOut);
    }


}

vector<string> Duplicidades::pathsNaoProcessados() const
{
    return mPathsNaoProcessados;
}

void Duplicidades::setPathsNaoProcessados(const vector<string> &pathsNaoProcessados)
{
    mPathsNaoProcessados = pathsNaoProcessados;
}



unsigned short Duplicidades::posDateHora() const
{
    return mPosDateHora;
}

void Duplicidades::setPosDateHora(const unsigned short &posDateHora)
{
    mPosDateHora = posDateHora;
}

unsigned short Duplicidades::posDeviceId() const
{
    return mPosDeviceId;
}

void Duplicidades::setPosDeviceId(const unsigned short &posDeviceId)
{
    mPosDeviceId = posDeviceId;
}

void Duplicidades::descarregarMedicoes(unordered_set<string> &unSetMedicoes)
{
    ofstream arqOut;

    if (mFlagAppendFile)
    {
        arqOut.open(mStrPathOut, ios_base::out | ios_base::app);
    }
    else
    {
        arqOut.open(mStrPathOut);
        mFlagAppendFile = true;
    }

    if(arqOut.is_open())
    {

        for(unordered_set<string>::iterator itUnSet = unSetMedicoes.begin(); itUnSet != unSetMedicoes.end(); ++itUnSet)
        {
            arqOut << *itUnSet << endl;
        }

        arqOut.close();
    }
    else
    {
        cerr << "Regra Duplicidades - Medicoes NAO descarregadas!" << endl;
    }

    unSetMedicoes.clear();

}

}

