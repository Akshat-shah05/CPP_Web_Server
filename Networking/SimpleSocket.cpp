#include "SimpleSocket.hpp"

// Default constructor

HDE::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface)
{
    // Defined the structure of the address
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);

    // Create the connection
    sock = socket(domain, service, protocol); // return of the socket function
    test_connection(sock); // test 

    // Establish Network Connection
    connection = network_connection(sock, address);
    test_connection(connection); // test

    // Bind - Only called on the server side code : Connect function is on the client side
}

// Virtual Function to test connection

void HDE::SimpleSocket::test_connection(int item_to_test)
{
    // Confirms that the socket or connection has been established or returns exit code
    if (item_to_test < 0) 
    {
        perror("Connection Failed");
        exit(EXIT_FAILURE);
    };
}

// Getter Functions for address, sock and connection

struct sockaddr_in HDE::SimpleSocket::get_address() 
{
    return address;
}

int HDE::SimpleSocket::get_sock()
{
    return sock;
}

int HDE::SimpleSocket::get_connection()
{
    return connection;
}