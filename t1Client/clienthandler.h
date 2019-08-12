#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include <iostream>
#include <boost/asio.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>

using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;

class clienthandler
{
private:
    /**
     *@brief  string de entrada de datos
     * */
    std::string p;
public:
    /**
     *@brief  metodo para obtener el string de entrada
     * */
    std::__cxx11::string getP() const;

    /**
     *@brief  arbol de propiedades para donde se almacena la informacion recibida del servidor
     * */
    boost::property_tree::ptree propSev;
    /**
     *@brief  metodo para modificar el string de entrada
     * @return el string de entrada
     * */
    void setP(const string &p);
    /**
     *@brief  metodo para convertir el mensaje de un stream de entrada a xml y despues lo pasa al arbol de propiedades
     * @param info stirng donde recibe la informacion de entrada del servidor
     * */
    void separarMensaje(std::string info);
    /**
     *@brief  metodo para para el envio de informacion al servidor tipo sockets
     * @param dta info de salida al cliente hacia servidor
     * */
    void send2Server(std::string dta);
};

#endif // CLIENTHANDLER_H
