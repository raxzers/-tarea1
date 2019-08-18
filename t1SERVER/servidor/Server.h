//
// Created by gacova on 04/08/19.
//

#ifndef T1SERVER_SERVER_H
#define T1SERVER_SERVER_H


#include <boost/asio.hpp>
#include "con_handler.h"

using namespace boost::asio;
using ip::tcp;


class Server {
private:
    tcp::acceptor acceptor_;
    /**
     *
     *@brief  comienza a aceptar las peticiones del cliente o los clientes de forma asincronica
     * */
    void start_accept();
public:
    /**
     * hereda de aceptor obtiene el ioservice y el endpoit con la ip4 con el puerto de entrada
     *@brief  constructor para aceptar la connecion desde el cliente
     * @param io_service
     * */

    Server(boost::asio::io_service& io_service): acceptor_(io_service, tcp::endpoint(tcp::v4(), 2608)){
        start_accept();
    };

    /**
     *@brief  maneja la coneccion
     * @param connection puntero de la conexion
     * */
    void handle_accept(con_handler::pointer connection, const boost::system::error_code& err);
};


#endif //T1SERVER_SERVER_H
