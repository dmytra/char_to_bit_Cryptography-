#include "cryptographychartobit.h"
#include <QDebug>
#include <QMessageBox>

#define DEBUG

using namespace std;

CryptographyCharToBit::CryptographyCharToBit(void) {}
CryptographyCharToBit::~CryptographyCharToBit(void) {}

bool CryptographyCharToBit::checkerLetterForCrypto(std::string inText)
{
    QString latinLower = "abcdefghijklmnopqrstuvwxyz";
    //QString cyrillicLower("абвгдеёжзийклмнопрстуфхцчшщъыьэюя");
    QString latinUpper = latinLower.toUpper();
    //QString cyrillicUpper = cyrillicLower.toUpper();
    QString specSymbols = "!\"#$%&'()*+,-./:;<=>?@[\]^_`{|}~"; // NOT in specSymbols: ±£’
    QString number = "1234567890";
    QString resStr = "";
    resStr += latinLower + latinUpper + specSymbols + number;

    bool flagRes = false;
    for (int i = 0; i < static_cast<int>(inText.length()); i++)
    {
        for (int j= 0; j < resStr.size(); j++)
        {
            if ( resStr[j] == inText[i] )
            {
                flagRes = true;
                break;
            }
        }
    if (!flagRes)
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("WARNING!!!\n For CRIPTING:\n\nOnly small & UPPER LETTER:\n abcdefghijklmnopqrstuvwxyz\n\n SPEC symbol:\n !\"#$%&'()*+,-./:;<=>?@[\]^_`{|}~ \n\n Digit: \n1234567890 ");
        msgBox.exec();

        return false;
    }

    }
    return true;
}

bool CryptographyCharToBit::checkerZerroForDeCrypto(std::string inText)
{
    for (int i = 0; i < static_cast<int>(inText.length()); i++)
    {
        QString mainText;
        #ifdef DEBUG
                qDebug() << QString::number(static_cast<int>(inText[i]));
                std::cout << static_cast<int>(inText[i]);// stoi(inText[i], nullptr, 2);
        #endif
        if ( (QString::number(static_cast<int>(inText[i])) != "48") && (QString::number(static_cast<int>(inText[i])) != "49") )
        {
        #ifdef DEBUG
                    qDebug() << "false";
        #endif
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText("WARNING!!!\n For DECRIPTING:\nOnly 1 or 0 number!\nWITHOUT SPACE ' '\nand other symbol!");
            msgBox.exec();

            return false;
        }
    }
    return true;
}

std::string CryptographyCharToBit::mCreateNumber(char inChar, int inLength)
{
    string oOutput = to_string(static_cast<int>(inChar));
    QString stoiOutput2 = QString::number( std::stoi (oOutput), 2);
    #ifdef DEBUG
        qDebug() << stoiOutput2 ;
    #endif

    string oZeroField = "";
    for (int i = 0; i < (8 - static_cast<int>(stoiOutput2.toStdString().length())); i++) {
        oZeroField = oZeroField + "0";
    }
    oOutput = stoiOutput2.toStdString();

    #ifdef DEBUG
        std::cout << 8 - static_cast<int>(stoiOutput2.toStdString().length()) << "\n";
        std::cout << oZeroField + oOutput<< "\n";
    #endif

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
    #ifdef DEBUG
        qDebug() << inText.at(i);
    #endif
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
