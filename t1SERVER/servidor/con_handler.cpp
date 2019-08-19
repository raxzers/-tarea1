//
// Created by gacova on 04/08/19.
//

#include "con_handler.h"

list l1;
BST bst1;

con_handler::pointer con_handler::create(boost::asio::io_service &io_service) {
    return pointer(new con_handler(io_service));
}

tcp::socket &con_handler::socket() {
    return sock;
}

void con_handler::start() {
    char dato[max_length];


    sock.async_read_some(
            boost::asio::buffer(dato, max_length),
            boost::bind(&con_handler::handle_read,
                        shared_from_this(),
                        boost::asio::placeholders::error,
                        boost::asio::placeholders::bytes_transferred));


    std::string raw="";
    raw =dato;
    //std::cout << dato<< std::endl;
    int ps = raw.find("}");
    this->data = raw.substr(0,ps+1);
    std::cout << this->data<< std::endl;
    dato[0] = '\0';
    operaciones();



    sock.async_write_some(
            boost::asio::buffer(this->message, max_length),
            boost::bind(&con_handler::handle_write,
                        shared_from_this(),
                        boost::asio::placeholders::error,
                        boost::asio::placeholders::bytes_transferred));

}

void con_handler::handle_read(const boost::system::error_code &err, size_t bytes_transferred) {
    if (!err) {

    } else {
        std::cerr << "error: " << err.message() << std::endl;
        //sock.close();
    }
}

void con_handler::handle_write(const boost::system::error_code &err, size_t bytes_transferred) {
    if (!err) {

    } else {
        std::cerr << "error: " << err.message() << endl;
        // sock.close();
    }
}

void con_handler::operaciones() {
     boost::property_tree::ptree arbolP =genarbol(this->data);
     if(arbolP.get<std::string>("id")=="lista"){

         accionesLista(arbolP);
     }
     else if(arbolP.get<std::string>("id")=="arbol"){
         std::cout << "entra a acciones"<< std::endl;
         accionesArbol(arbolP);
     }



}



template<typename T>
std::vector<T> con_handler::as_vector(boost::property_tree::ptree const &pt, const boost::property_tree::ptree::key_type &key) {
    std::vector<T> r;
    for (auto& item : pt.get_child(key))
        r.push_back(item.second.get_value<T>());
    return r;
}

boost::property_tree::ptree con_handler::genarbol(std::string arb) {
    using boost::property_tree::ptree;
    std::istringstream is (arb);

    ptree pt2;



    read_json(is,pt2);





    return pt2;
}

void con_handler::accionesLista(boost::property_tree::ptree &arbol) {
    if(arbol.get<std::string>("accion")=="insertar"){
        l1.insert_start(arbol.get<int>("valor"));

    }
    else if(arbol.get<std::string>("accion")=="editar"){
        l1.change_value(arbol.get<int>("pos"),arbol.get<int>("valor"));
    }
    else if(arbol.get<std::string>("accion")=="obtener"){
        message= std::to_string(l1.getPosi(arbol.get<int>("pos")));
    }
    else if(arbol.get<std::string>("accion")=="eliminar"){
        l1.delete_first();

    }
    l1.display();
}

void con_handler::accionesArbol(boost::property_tree::ptree &arbol) {

    if(arbol.get<std::string>("accion")=="insertar"){
        bst1.insert(arbol.get<int>("valor"));
        bst1.display();
    }
    else if(arbol.get<std::string>("accion")=="eliminar"){
        bst1.del(arbol.get<int>("valor"));
        bst1.display();
    }
};






