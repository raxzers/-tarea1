#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_listInsert_clicked()
{
    arbol.put("id","lista");
    arbol.put("accion","insertar");
    arbol.put("valor",ui->insertCampo->text().toInt());
    genStr2Ser(arbol);
    ui->insertCampo->clear();
}

void MainWindow::on_listEdit_clicked()
{
    arbol.put("id","lista");
    arbol.put("accion","editar");
    arbol.put("valor",ui->numCampED->text().toInt());
    arbol.put("pos",ui->posCampEd->text().toInt());
    genStr2Ser(arbol);
    ui->posCampEd->clear();
    ui->numCampED->clear();
}

void MainWindow::on_listGetValuePos_clicked()
{
    ui->txtpos->clear();
    arbol.put("id","lista");
    arbol.put("accion","obtener");
    arbol.put("pos",ui->posCampObt->text().toInt());
    genStr2Ser(arbol);
    ui->posCampObt->clear();
    ui->txtpos->setText(QString::fromStdString(cl.getP()));
}

void MainWindow::on_listDelete_clicked()
{
    arbol.put("id","lista");
    arbol.put("accion","eliminar");
    genStr2Ser(arbol);

}

void MainWindow::on_arbInsert_clicked()
{
    arbol.put("id","arbol");
    arbol.put("accion","insertar");
    arbol.put("valor",ui->campARBIns->text().toInt());
    genStr2Ser(arbol);
    ui->campARBIns->clear();
}

void MainWindow::on_arbDelet_clicked()
{
    arbol.put("id","arbol");
    arbol.put("accion","eliminar");
    arbol.put("valor",ui->campARBDel->text().toInt());
    genStr2Ser(arbol);
    ui->campARBDel->clear();
}

void MainWindow::genStr2Ser(boost::property_tree::ptree arbol)
{
    std::ostringstream buf;
    write_json (buf, arbol, false);
    std::string json = buf.str();
    cl.send2Server(json);
}
