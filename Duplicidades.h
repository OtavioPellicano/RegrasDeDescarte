#ifndef DUPLICIDADES_H
#define DUPLICIDADES_H


#include <unordered_set>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "validade.h"


using namespace std;

namespace opmm {

/**
 * @brief The Duplicidades class
 * Descarte de registros duplicados.
 * São considerados duplicados os registros
 * com a mesma data e hora para o mesmo coletor.
 */
class Duplicidades
{
public:
    Duplicidades(const vector<string> &pathsIn,const string &pathOut, const layout &tipoLayout);

    vector<string> pathsNaoProcessados() const;

private:

    unsigned short posDeviceId() const;
    void setPosDeviceId(const unsigned short &posDeviceId);

    unsigned short posDateHora() const;
    void setPosDateHora(const unsigned short &posDateHora);

    void setPathsNaoProcessados(const vector<string> &pathsNaoProcessados);

    void descarregarMedicoes(unordered_set<string> &unSetMedicoes);


private:
    vector<string> mPathsNaoProcessados;
    vector<string> mVecChaves;
    //vector<string> mMedicoesOut;
    unordered_set<string> mMedicoesOut;

    ifstream mPathIn;

    string mStrPathOut;

    unsigned short mPosDeviceId;
    unsigned short mPosDateHora;

    string mChave;

    bool mFlagAppendFile = false;

    string str;

};

}


#endif // DUPLICIDADES_H
