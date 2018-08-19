#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "quazip/quazip/073/JlCompress.h"
#include "QMessageBox"
#include "QDesktopServices"
#include "QUrl"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_zip_clicked()
{
bool ok = JlCompress::compressFile("C:/Users/Lucas/Desktop/test.zip", "C:/Users/Lucas/Desktop/test.txt");
if (ok)
{
    QMessageBox::information(this, "Zipped", "File has been zipped!");
    QDesktopServices::openUrl(QUrl("file:///C:/Users/Lucas/Desktop"));
}
else
{
    QMessageBox::information(this, "Fail", "Could not zip file");
}
}

void MainWindow::on_unzip_clicked()
{
QStringList list = JlCompress::extractDir("C:/Users/Lucas/Desktop/test.zip", "C:/Users/Lucas/Desktop/test");
bool ok = !list.isEmpty();
if (ok)
{
    QMessageBox::information(this, "Extracted", "File has been extracted!");
    QDesktopServices::openUrl(QUrl("file:///C:/Users/Lucas/Desktop/test"));
}
else
{
    QMessageBox::information(this, "Fail", "Could not unzip file");
}
}
