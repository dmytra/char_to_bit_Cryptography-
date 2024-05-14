#include "widget.h"
#include "ui_widget.h"

#include "cryptographychartobit.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mainTextHelp = ui->textEdit->toPlainText();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_to_crypto_clicked()
{
    QString mainText;
    mainText = ui->textEdit->toPlainText();
    //ui->textEdit
    std::string mainTextEncrypt = CryptographyCharToBit::mEncrypt(mainText.toStdString());
    ui->textEdit->setText( mainText.fromStdString(mainTextEncrypt) );
}

void Widget::on_pushButton_de_crypto_clicked()
{
    QString mainText2;
    mainText2 = ui->textEdit->toPlainText();
    if (CryptographyCharToBit::checkerZerro(mainText2.toStdString()))
    {
        qDebug() << "ok"<< "\n" << mainText2;
        std::string mainTextDeCrypt = CryptographyCharToBit::mDecrypt(mainText2.toStdString());
        QString mainTextDeCryptSrt = mainText2.fromStdString(mainTextDeCrypt);
        ui->textEdit->setText( mainTextDeCryptSrt );
    }
}

void Widget::on_pushButton_help_clicked()
{
    ui->textEdit->setText( mainTextHelp  );
}

