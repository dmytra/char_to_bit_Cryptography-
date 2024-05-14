#ifndef CRYPTOGRAPHYCHARTOBIT_H
#define CRYPTOGRAPHYCHARTOBIT_H

#define LENGTH_OF_VALUE 4

#include <iostream>
#include <chrono>
#include <string>

class CryptographyCharToBit
{     
public:
    CryptographyCharToBit(void);
    ~CryptographyCharToBit(void);

    static std::string mEncrypt(std::string inText);
    static std::string mDecrypt(std::string inText);

    static bool checkerZerro(std::string inText);

private:
    static std::string mCreateNumber(char inChar,int inLength);
    static std::string mCreateChar(std::string inNumber);
};

#endif // CRYPTOGRAPHYCHARTOBIT_H
