#include "ValidacaoCamposEsperadosHDM.h"

namespace opmm {

ValidacaoCamposEsperadosHDM::ValidacaoCamposEsperadosHDM(const QString &medicao, const arquivoHDM &tipoArquivoHDM)
    :mSep(","), mTipoArquivoHDM(tipoArquivoHDM)
{
    setMedicaoValida(parametroValido(medicao) || cabecalhoValido(medicao));
}

bool ValidacaoCamposEsperadosHDM::cabecalhoValido(const QString &medicao) throw(QString)
{

    switch (mTipoArquivoHDM) {
    case SCM_4_5:

        mParametros = medicao.split(mSep);
        if(mParametros.size() != 48)
            return false;

        if(medicao == "Execution Date,State,Location,Station,DSLAM,BRAS,ID,Terminal,Serial Number,MACADDRESS,IPADDRESS,Firmware,Manufacture,Model,Rack,Shelf,Slot,Port,Profile,Test Status,Policy Status,In Traffic,Ping Test Result,Test Server,Data Block Size,Average Response Time,Minimum response Time,Maximum response Time,Number of Repetitions,Success Count,Failure Count,Download Test Result,BOM Download,EOM Download,Test Bytes Received,Total Bytes Received,Upload Test Result,Test File Length,BOM Upload,EOM Upload,Total Bytes Sent,Latency (ms),Jitter (ms),Packet Loss,Download Config,Upload Config,Test Download (kbps),TestUpload (kbps)\n")
            return true;
        else
            return false;

        break;
    case SCM_6_7:

        mParametros = medicao.split(mSep);
        if(mParametros.size() != 28)
            return false;

        if(medicao == "Execution Date,State,Location,Station,DSLAM,BRAS,ID,Terminal,Serial Number,MACADDRESS,IPADDRESS,Firmware,Manufacture,Model,Rack,Shelf,Slot,Port,Profile,Host,Test ID,Timeout,DataBlockSize,Average Response Time,Maximum response Time,Minimum response Time,Jitter (ms)\n")
            return true;
        else
            return false;

        break;
    case SCM_8:

        mParametros = medicao.split(mSep);
        if(mParametros.size() != 19)
            return false;

        if(medicao == "Execution Date,State,Location,Station,DSLAM,BRAS,ID,Terminal,Serial Number,MACADDRESS,IPADDRESS,Firmware,Manufacture,Model,Rack,Shelf,Slot,Port,Profile,Host,Test ID,Number of Repetitions,Failure Count,Success Count\n")
            return true;
        else
            return false;

        break;
    case SCM_9:

        mParametros = medicao.split(mSep);
        if(mParametros.size() != 13)
            return false;

        if(medicao == "Execution Date, Prev Execution Date,State,Location,Station,DSLAM,BRAS,ID,Terminal,Serial Number,MACADDRESS,IPADDRESS,Firmware,Manufacture,Model,Rack,Shelf,Slot,Port,Profile,Test ID,Uptime,Previous Uptime\n")
            return true;
        else
            return false;
        break;
    default:
        throw QString("Tipo de layout invalido!");
        break;
    }

}

bool ValidacaoCamposEsperadosHDM::parametroValido(const QString &medicao)
{
    bool ok[6];
    mAvailSuccesses = medicao.split(mSep)[29].toInt(ok);
    mAvgRTT = medicao.split(mSep)[25].toInt(ok + 1);
    mDeviceID = medicao.split(mSep)[6].toInt(ok + 2);
    mJitter = medicao.split(mSep)[42].toInt(ok + 3);
    mPacketLoss = medicao.split(mSep)[30].toInt(ok + 4);
    mPacketSent = medicao.split(mSep)[29].toInt(ok + 5);

    for(size_t i = 0; i < 6; ++i)
        if(!*(ok+i))
            return false;

    mStrDateTime = medicao.split(mSep)[0];

    if(mStrDateTime.size() != 19)
        return false;

    if(!(mStrDateTime[4] == '-' && mStrDateTime[7] == '-' &&
            mStrDateTime[13] == ':' && mStrDateTime[16] == ':'))
        return false;

    return true;
}

}
