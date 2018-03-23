#ifndef VALIDACAOCAMPOSESPERADOSHDM_H
#define VALIDACAOCAMPOSESPERADOSHDM_H

#include <QStringList>
#include "validade.h"
#include <iostream>

namespace opmm {

enum arquivoHDM {SCM_4_5, SCM_6_7, SCM_8, SCM_9};

/**
 * @brief The ValidacaoCamposEsperadosHDM class
 * O processo verifica se os tipos de dados esperados
 * nos registros correspondem ao layout definido para o rawdata.
 *
 * Validação padrão: Nessa etapa é verificada se os campos obrigatórios estão
 * preenchidos, se o tipo de campo é o esperado, se o valor informado está dentro
 * da variação esperada (min/max) e se o valor informado é valido.
 *
 * availSuccesses   (int)
 * avgRTT           (int)
 * dateTime         (dd/mm/yyyy hh:mm:ss)
 * deviceID         (int)
 * failures         ()
 * jitter           (int)
 * macAddress       (str)
 * manufacturer     (str)
 * packetLoss       (int)
 * packetSent       (int)
 * softwareVersion  (str)
 * sourceIPAddress  (str)
 * successes        ()
 * testPoint        (str)
 */
class ValidacaoCamposEsperadosHDM : public Validade
{
public:
    ValidacaoCamposEsperadosHDM(const QString &medicao, const arquivoHDM &tipoArquivoHDM);

private:
    bool cabecalhoValido(const QString &medicao);

private:
    int mAvailSuccesses;
    int mAvgRTT;
    QString mStrDateTime;
    int mDeviceID;
    int mJitter;
    QString mMacAddress;
    QString mManufacturer;
    int mPacketLoss;
    int mPacketSent;
    QString mSoftwareVersion;
    QString mSourceIPAddress;
    QString mTestPoint;

    QStringList mParametros;

    QString mSep;
    arquivoHDM mTipoArquivoHDM;

};

}

#endif // VALIDACAOCAMPOSESPERADOSHDM_H
