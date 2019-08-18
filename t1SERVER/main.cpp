#include <iostream>
#include <boost/asio.hpp>
#include "servidor/Server.h"

using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;

int main() {
    try
    {
        cout <<"servidor iniciado"<< std::endl;


        boost::asio::io_service io_service;
        Server server(io_service);

        io_service.run();
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << endl;
    }

}