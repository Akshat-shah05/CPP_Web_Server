#ifndef SimpleSocket_hpp
#define SimpleSocket_hpp

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

namespace HDE 
{
    class SimpleSocket
    {
        private:
            struct sockaddr_in address;
            int sock;
            int connection;
        public:
            SimpleSocket(int domain, int service, int protocol, int port, u_long interface);

        // Virutal function to connect to a network
        virtual int network_connection(int sock, struct sockaddr_in address) = 
            0;

        // Function to test socket and connection
        void test_connection(int);

        // getter functions for private
        struct sockaddr_in get_address();
        int get_sock();
        int get_connection();
    };
}

#endif /* SimpleSocket_hpp */e