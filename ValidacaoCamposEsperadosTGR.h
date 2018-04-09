#ifndef VALIDACAOCAMPOSESPERADOSTGR_H
#define VALIDACAOCAMPOSESPERADOSTGR_H

#include "validade.h"
#include <QStringList>

namespace opmm {

enum testeTGR {SCM_4_5, SCM_6_7, SCM_8, SCM_9};

/**
 * @brief The ValidacaoCamposEsperadosTGR class
 * O processo verifica se os tipos de dados esperados
 * nos registros correspondem ao layout definido para o rawdata.
 *
 * Validação padrão: Nessa etapa é verificada se os campos obrigatórios estão
 * preenchidos, se o tipo de campo é o esperado, se o valor informado está dentro
 * da variação esperada (min/max) e se o valor informado é valido.
 *
    * availSuccesses   (int)
    * avgRTT           (float)
    * dateTime         (YYYY-MM-DD HH:mm:ss)
    * deviceID         (str)
    * failures         (int)
    * jitter           (float)
    * macAddress       (str)
    * manufacturer     (str)      //Tabela de Assinantes
    * packetLoss       (float)
    * packetSent       (int)
    * softwareVersion  (str)
    * sourceIPAddress  (str)
    * successes        (int)
    * testPoint        (str)
 *
 * TGR: Para os RawData da TGR disponibilizados pela solução da TGR
 * além da validação padrão o processo também avalia se contém “#” nos
 * campos necessários a depender do tipo de evento
 * (disponibilidade, jitter, latência, perda de pacote e down/up).
 *
 */
class ValidacaoCamposEsperadosTGR: public Validade
{
public:
    ValidacaoCamposEsperadosTGR(const QString &medicao, const testeTGR &tipoTesteTGR);

private:
    bool cabecalhoValido(const QString &medicao);
    bool parametroValido(const QString &medicao);

private:
    int mAvailSuccesses;
    float mAvgRTT;
    QString mStrDateTime;   //("YYYY-MM-DD HH:mm:ss")
    float mJitter;
    float mPacketLoss;
    int mDown, mUp;

    QString mSep;
    testeTGR mTipoTesteTGR;
    QString mStrMed;



};

}


#endif // VALIDACAOCAMPOSESPERADOSTGR_H
