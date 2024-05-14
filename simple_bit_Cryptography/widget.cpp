#include "widget.h"
#include "ui_widget.h"

#include "cryptographychartobit.h"

//#define DEBUG

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mainTextHelp = ui->textEdit->toPlainText();
    ui->textEdit->setAcceptRichText(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_to_crypto_clicked()
{
    QString mainText;
    mainText = ui->textEdit->toPlainText();
    if (CryptographyCharToBit::checkerLetterForCrypto(mainText.toStdString()))
    {
        std::string mainTextEncrypt = CryptographyCharToBit::mEncrypt(mainText.toStdString());
        ui->textEdit->setText( mainText.fromStdString(mainTextEncrypt) );
    }
}

void Widget::on_pushButton_de_crypto_clicked()
{
    QString mainText;
    mainText = ui->textEdit->toPlainText();
    if (CryptographyCharToBit::checkerZerroForDeCrypto(mainText.toStdString()))
    {
        #ifdef DEBUG
                qDebug() << "ok"<< "\n" << mainText;
        #endif
        std::string mainTextDeCrypt = CryptographyCharToBit::mDecrypt(mainText.toStdString());
        QString mainTextDeCryptSrt = mainText.fromStdString(mainTextDeCrypt);
        ui->textEdit->setText( mainTextDeCryptSrt );
    }
}

void Widget::on_pushButton_help_clicked()
{
    ui->textEdit->setText( mainTextHelp  );
}
