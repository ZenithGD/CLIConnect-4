#include <iostream>
#include <Socket.hpp>

using namespace std;

const int BUF_LEN = 1024;

int main(int argc, char* argv[]) {

	Socket sock_srv(argv[1], atoi(argv[2]));
	string buffer;

	int fd_srv = sock_srv.Connect();
	if ( fd_srv < 0 )
	{
		cerr << "Error en connect: " << strerror(errno)<< endl;
		return -1;
	}

	if ( sock_srv.Send(fd_srv, "Hello server!") < 0 ) {
		cerr << "Error en el envío: " << strerror(errno)<< endl;
		return 1;
	}

	cout << "Hello server!" << endl;
	
	if ( sock_srv.Recv(fd_srv, buffer, BUF_LEN) < 0 ) {
		cerr << "Error en la recepción: " << strerror(errno) << endl;
		return 1;
	}

	cout << buffer << endl;

	sock_srv.Close(fd_srv);
}