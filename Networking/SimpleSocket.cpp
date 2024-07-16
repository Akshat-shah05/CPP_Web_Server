#include "SimpleSocket.hpp"

HDE::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface)
{
    // Defined the structure of the address
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);

    // Create the connection
    sock = socket(domain, service, protocol); // return of the socket function
    connection = network_connection();

    // Bind - Only called on the server side code : Connect function is on the client side
    

}