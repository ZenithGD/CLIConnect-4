#include <iostream>
#include <Socket.hpp>

using namespace std;

const int BUF_LEN = 1024;

int main(int argc, char* argv[]) {

	Socket sock_srv(atoi(argv[1]));
	string buffer;

	if ( !sock_srv.Bind() ) {
		cerr << "Error en bind: " << strerror(errno) << endl;
		return -1;
	}

	if ( sock_srv.Listen(10) < 0 ) {
		cerr << "Error en listen: " << strerror(errno) << endl;
		return -1;
	}
	
	int fd_cli = sock_srv.Accept();
	if ( fd_cli < 0 )
	{
		cerr << "Error en accept: " << strerror(errno) << endl;
		return -1;
	}

	int rd_bytes = sock_srv.Recv(fd_cli, buffer, BUF_LEN);

	if ( rd_bytes < 0 ) {
		cerr << "Error de recepción " << strerror(errno) << endl;
		return 1;
	}
	cout << buffer << endl;

	if ( sock_srv.Send(fd_cli, "Hello client! I got you!") < 0 ) {
		cerr << "Error en el envío: " << strerror(errno) << endl;
		return 1;
	}

	cout << "Hello client! I got you!" << endl;
	
	sock_srv.Close(fd_cli);
}