#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete conj;
    delete ui;
}


void MainWindow::on_pushButton_gerar_clicked()
{
    try {
        if (ui->lineEdit_inputTamanho->text().toInt() <= 0){
            throw QString("Tamanho invalido, precisa ser um numero maior que 0");
        }
        conj = new Pedro::Conjunto(ui->lineEdit_inputTamanho->text().toInt());
        ui->textEdit_outputDados->setText(conj->getConjunto());
    }catch(QString &erro){
        QMessageBox::critical(this,"Erro", erro);
    }
    catch (std::bad_alloc &e) {
        QMessageBox::critical(this,"Erro", "Nao foi possivel alocar memoria");
    }
}


void MainWindow::on_pushButton_buscar_clicked()
{
    try {
        if (!conj){
            throw QString("Conjunto nao criado");
        }
        ui->textEdit_outputResultado->setText(conj->buscarValor(ui->lineEdit_inputValor->text().toInt()));
    } catch (QString &e) {
        QMessageBox::critical(this,"Erro", e);
    }
}

