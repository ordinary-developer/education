#include <iostream>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

using SOCKET = int;

int main() {
    addrinfo hints{};
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    addrinfo* servinfo{};
    getaddrinfo("www.google.com", "80", &hints, &servinfo);

    SOCKET sockfd {
        socket(servinfo->ai_family, 
               servinfo->ai_socktype, 
               servinfo->ai_protocol) };

    int connectionResult{ connect(sockfd,
                                  servinfo->ai_addr, 
                                  servinfo->ai_addrlen) };
    if (-1 == connectionResult) 
        std::cout << "[FAIL] - connection failed" << std::endl;
    else
        std::cout << "[OK] - connection successful" << std::endl;

    freeaddrinfo(servinfo);
                                  
    return 0;
}
