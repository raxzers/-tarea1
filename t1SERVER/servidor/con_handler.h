//
// Created by gacova on 04/08/19.
//

#ifndef T1SERVER_CON_HANDLER_H
#define T1SERVER_CON_HANDLER_H


#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "../estructuras/list.h"
#include "../estructuras/BST.h"


using namespace boost::asio;
using ip::tcp;
using std::cout;
using std::endl;
/**
    *@brief  comunicador del server
    *
    * */
class con_handler: public boost::enable_shared_from_this<con_handler> {
public:
    /**
    *@brief  puntero compartido
    *
    * */
    typedef boost::shared_ptr<con_handler> pointer;
    /**
    *@brief  constructor que hereda  de sock
    *@param io_service servicio de entrada y salida
    * */
    con_handler(boost::asio::io_service& io_service): sock(io_service){}
    /**
    *@brief  puntero estatico
    *@param io_service servicio de entrada y salida
     * @return un puntero creado
    * */
    static pointer create(boost::asio::io_service& io_service);
    /**
    *@brief  crea la dirreccion el socket
     * @return el socket
    * */
    tcp::socket& socket();
    /**
    *@brief  metodo que recibe las peticiones de forma asincronica
    * */
    void start();
    /**
    *@brief  metodo que recibe las peticiones de forma asincronica
    * */
    void handle_read(const boost::system::error_code& err, size_t bytes_transferred);
    /**
    *@brief  metodo que manda los resultados al cliente
    * */
    void handle_write(const boost::system::error_code& err, size_t bytes_transferred);
    /**
    *@brief  metodo que realiza las acciones para el juego y los multiples juegos
    * */
    void operaciones();

private:
    template <typename T>
    /**
    *@brief  vector para la traduccion de los aarreglos de la posicion de la palbra en la matriz
     *
    * */
    std::vector<T> as_vector(boost::property_tree::ptree const& pt, boost::property_tree::ptree::key_type const& key);
    enum { max_length = 1024};
    /**
    *@brief  socket de entrada del servidor
     *
    * */
    tcp::socket sock;
    /**
    *@brief  string del mensaje de retorno
     *
    * */
    std::string message=" ";


    /**
    *@brief  string para la entrada del serial de json
     *
    * */
    std::string data;
    /**
    *@brief  sarbol de boost para leer el json
     *
    * */
    boost::property_tree::ptree genarbol(std::string arb);
    /**
    *@brief  metodo para realizar las acciones en la lista
     * @param arbol arbol donde especifica la accion a realizar
    * */
   void accionesLista(boost::property_tree::ptree& arbol);

    /**
     *@brief  metodo para realizar las acciones en el arbol
      * @param arbol arbol donde especifica la accion a realizar
     * */
    void accionesArbol(boost::property_tree::ptree& arbol);

};

#endif //T1SERVER_CON_HANDLER_H
