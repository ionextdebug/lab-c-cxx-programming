#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
//#include <unistd.h>

int main()
{

    char server_message[256] = "socket message\n";

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*)& server_address, sizeof(server_address));
    listen(server_socket, 5);

    int client_sock;
    client_sock=accept(server_socket, NULL, NULL);
    send(client_sock, server_message, sizeof(server_message), 0);
    close(server_socket);

    return 0;
}