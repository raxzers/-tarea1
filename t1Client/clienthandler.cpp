#include "clienthandler.h"

void clienthandler::send2Server(std::string dta) {
    boost::asio::io_service io_service;
    //socket creation
    tcp::socket socket(io_service);
    //connection
    socket.connect( tcp::endpoint( boost::asio::ip::address::from_string("127.0.0.1"), 2608 ));
    // request/message from client
    const string msg = dta;
    boost::system::error_code error;
    boost::asio::write( socket, boost::asio::buffer(msg), error );
    if( !error ) {
        cout << dta << endl;
    }
    else {
        cout << "send failed: " << error.message() << endl;
    }
    // getting response from server
    boost::asio::streambuf receive_buffer;
    boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
    if( error && error != boost::asio::error::eof ) {
        cout << "receive failed: " << error.message() << endl;
    }
    else {
        const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
        p =data;
        this->separarMensaje(p);
        cout << p << endl;



}}

    void clienthandler::setP(const string &p) {
        clienthandler::p = p;
    }

string clienthandler::getP() const {
     return p;

}

void clienthandler::separarMensaje(std::string info){

    using boost::property_tree::ptree;
    std::istringstream is (info);

    ptree pt2;

        this->propSev=pt2;




}
