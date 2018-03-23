#include "ValidacaoCamposEsperadosHDM.h"

namespace opmm {

ValidacaoCamposEsperadosHDM::ValidacaoCamposEsperadosHDM(const QString &medicao, const arquivoHDM &tipoArquivoHDM)
    :mSep(","), mTipoArquivoHDM(tipoArquivoHDM)
{

    setMedicaoValida(cabecalhoValido(medicao));

}

bool ValidacaoCamposEsperadosHDM::cabecalhoValido(const QString &medicao)
{

    switch (mTipoArquivoHDM) {
    case SCM_4_5:

        mParametros = medicao.split(mSep);
        if(mParametros.size() != 48)
            return false;

        if(medicao == "Execution Date,State,Location,Station,DSLAM,BRAS,ID,Terminal,Serial Number,MACADDRESS,IPADDRESS,Firmware,Manufacture,Model,Rack,Shelf,Slot,Port,Profile,Test Status,Policy Status,In Traffic,Ping Test Result,Test Server,Data Block Size,Average Response Time,Minimum response Time,Maximum response Time,Number of Repetitions,Success Count,Failure Count,Download Test Result,BOM Download,EOM Download,Test Bytes Received,Total Bytes Received,Upload Test Result,Test File Length,BOM Upload,EOM Upload,Total Bytes Sent,Latency (ms),Jitter (ms),Packet Loss,Download Config,Upload Config,Test Download (kbps),TestUpload (kbps)")
            return true;
        else
            return false;

        break;
    case SCM_6_7:

        mParametros = medicao.split(mSep);
        if(mParametros.size() != 28)
            return false;

        if(medicao == "Execution Date,State,Location,Station,DSLAM,BRAS,ID,Terminal,Serial Number,MACADDRESS,IPADDRESS,Firmware,Manufacture,Model,Rack,Shelf,Slot,Port,Profile,Host,Test ID,Timeout,DataBlockSize,Average Response Time,Maximum response Time,Minimum response Time,Jitter (ms)")
            return true;
        else
            return false;

        break;
    case SCM_8:

        mParametros = medicao.split(mSep);
        if(mParametros.size() != 19)
            return false;

        if(medicao == "Execution Date,State,Location,Station,DSLAM,BRAS,ID,Terminal,Serial Number,MACADDRESS,IPADDRESS,Firmware,Manufacture,Model,Rack,Shelf,Slot,Port,Profile,Host,Test ID,Number of Repetitions,Failure Count,Success Count")
            return true;
        else
            return false;

        break;
    case SCM_9:

        mParametros = medicao.split(mSep);
        if(mParametros.size() != 13)
            return false;

        if(medicao == "Execution Date, Prev Execution Date,State,Location,Station,DSLAM,BRAS,ID,Terminal,Serial Number,MACADDRESS,IPADDRESS,Firmware,Manufacture,Model,Rack,Shelf,Slot,Port,Profile,Test ID,Uptime,Previous Uptime")
            return true;
        else
            return false;
        break;
    default:
        while(1)
            std::cerr << "Erro" << std::endl;
        break;
    }




}

}
