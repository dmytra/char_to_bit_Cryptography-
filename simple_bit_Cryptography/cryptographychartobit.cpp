#include "cryptographychartobit.h"
#include <QDebug>

using namespace std;

CryptographyCharToBit::CryptographyCharToBit(void) {}
CryptographyCharToBit::~CryptographyCharToBit(void) {}



bool CryptographyCharToBit::checkerZerro(std::string inText)
{
    for (int i = 0; i < static_cast<int>(inText.length()); i++)
    {
        QString mainText;
        qDebug() << QString::number(static_cast<int>(inText[i]));
        // std::cout << static_cast<int>(inText[i]);// stoi(inText[i], nullptr, 2);;
        if ( QString::number(static_cast<int>(inText[i])) == "48" || QString::number(static_cast<int>(inText[i])) == "49" )
        {
            //return true;
        }
        else
        {
            qDebug() << "false";
            return false;
        }
    }
    return true;
}

std::string CryptographyCharToBit::mCreateNumber(char inChar, int inLength)
{

    string oOutput = to_string(static_cast<int>(inChar));
    QString stoiOutput2 = QString::number( std::stoi (oOutput), 2);
        //qDebug() << stoiOutput2 ;

    string oZeroField = "";
    for (int i = 0; i < (8 - static_cast<int>(stoiOutput2.toStdString().length())); i++) {
        oZeroField = oZeroField + "0";
    }
    oOutput = stoiOutput2.toStdString();

    //std::cout << 8 - static_cast<int>(stoiOutput2.toStdString().length()) << "\n";
    //std::cout << oZeroField + oOutput<< "\n";

    return oZeroField + oOutput;
}

std::string CryptographyCharToBit::mCreateChar(std::string inNumber)
{
    string oOutput;
    oOutput += static_cast<char>(stoi(inNumber));
    return oOutput;
}

std::string CryptographyCharToBit::mEncrypt(std::string inText)
{
    string oOutput;
    for (int i = 0; i < static_cast<int>(inText.length()); i++) {
        oOutput += mCreateNumber(inText.at(i),LENGTH_OF_VALUE);
            //qDebug() << inText.at(i);
    }

    return oOutput;
}

std::string CryptographyCharToBit::mDecrypt(std::string inText)
{
    string oOutput;

    for (int i = 0; i < static_cast<int>(inText.length()); i = i + 8) {
        string iValue;
        for (int j = 0; j < 8; j++) {
            iValue = iValue + inText[i + j];
        }
        int num =   stoi(iValue, nullptr, 2);
        QString aa = QString::number(num);
        oOutput = oOutput + mCreateChar(aa.toStdString());
    }

    return oOutput;
}
