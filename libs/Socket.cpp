/* Autor: Darío Marcos Casalé
 * Fecha de la última revisión: 14-12-2020
 * Resumen: Implementación de una librería genérica de sockets
 */
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <Socket.hpp>

using namespace std;

Socket::Socket(const string& addr, const int port) : ip_addr(addr), port(port) {
	sock_fd = socket(AF_INET, SOCK_STREAM, 0); // comunicación IPv4 con TCP
}
Socket::Socket(const int port) : ip_addr("localhost"), port(port) {}

bool Socket::Bind() 
{
	// estructura de dirección del servidor
	struct sockaddr_in srv_info;

	srv_info.sin_family = AF_INET;
	srv_info.sin_port = htons(port);
	srv_info.sin_addr.s_addr = INADDR_ANY; // coloca IP automática

	bzero(&(srv_info.sin_zero), 8);

	return bind(sock_fd, (struct sockaddr *) &srv_info, sizeof(struct sockaddr)) >= 0;

}

int Socket::Listen(const int m) 
{
	return listen(sock_fd, m);
}

int Socket::Accept() 
{
	struct sockaddr_in cli_info;
	socklen_t sin_size = sizeof(struct sockaddr_in);

	// rellena información sobre el cliente
	return accept(sock_fd, (struct sockaddr *) &cli_info, &sin_size);
}

int Socket::Connect() 
{
	struct hostent* host_info;
	struct sockaddr_in srv_info;

	// obtener dirección servidor
	host_info = gethostbyname(ip_addr.c_str());
	if ( host_info == nullptr ) {
		cerr << "Error al obtener la dirección del servidor." << endl;
		return -1;
	}

	srv_info.sin_family = AF_INET;
	srv_info.sin_port = htons(port);
	srv_info.sin_addr = *((struct in_addr *)host_info->h_addr); // coloca IP automática
	bzero(&(srv_info.sin_zero), 8);

	return connect(sock_fd, (struct sockaddr *)&srv_info, sizeof(struct sockaddr));
}

ssize_t Socket::Send(const int fd, char* buf) 
{
	
}

ssize_t Socket::Send(const int fd, std::string& buf) 
{
	
}

ssize_t Socket::Recv(const int fd, char* buf, const int B_LEN) 
{
	
}

ssize_t Socket::Recv(const int fd, std::string& buf, const int B_LEN) 
{
	
}

bool Socket::Close(const int fd) 
{
	return close(fd);
}
