#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "clienthandler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_listInsert_clicked();

    void on_listEdit_clicked();

    void on_listGetValuePos_clicked();

    void on_listDelete_clicked();

    void on_arbInsert_clicked();

    void on_arbDelet_clicked();

private:
    Ui::MainWindow *ui;
    /**
    *@brief arbol para el envio de informacion
    *
    **/
    boost::property_tree::ptree arbol;
    /**
        *@brief metodo para crea el mensaje json
        *@param arbol arbol de propiedades
    **/
    void genStr2Ser(boost::property_tree::ptree arbol);
    /**
        *@brief instancia de conexion con el servidor
        *
    **/
    clienthandler cl;
};

#endif // MAINWINDOW_H
