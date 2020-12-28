/* Autor: Darío Marcos Casalé
 * Fecha de la última revisión: 14-12-2020
 * Resumen: Librería genérica de sockets
 */
#ifndef SOCK_H
#define SOCK_H

#include <cstring>
#include <strings.h>
#include <iostream>
#include <unistd.h>

class Socket {

	private:
		// dirección IP y puerto al que se enlaza el socket
		std::string ip_addr; 
		int port;

		// descriptor de fichero asociado al socket
		int sock_fd;
	public:

		// Constructores
		// Constructor que especifica IP del equipo con el que vamos
		// a conectar, y el puerto a través del que se hará la comunicación
		Socket(const std::string& ip_addr, const int port);

		// Constructor que especifica únicamente el puerto de escucha
		// (para servidores)
		Socket(const int port);

		// Funciones del servidor

		// Encapsulación de la llamada bind()
		// Pre: El socket se ha creado e inicializado anteriormente
		// Post: enlaza el socket al puerto especificado y devuelve
		// 		 true en caso de ejecución correcta
		bool Bind();

		// Encapsulación de la llamada listen()
		// Pre: El socket está enlazado a un puerto
		// Post: Pone en escucha en el puerto al que está enlazado,
		//		 y devuelve el valor de la llamada a listen(). Permitirá 
		//		 aceptar como mucho <m> conexiones a la vez.
		int Listen(const int m);

		// Encapsulación de la llamada accept()
		// Pre: El socket está escuchando en un puerto
		// Post: Acepta una conexión entrante, y en caso de hacerlo
		//		 correctamente, devuelve el descriptor de fichero asociado
		//		 al socket del equipo conectado. En caso contrario devuelve un
		//		 un valor negativo.
		int Accept();

		// Encapsulación de la llamada connect()
		// Pre: El socket se ha creado correctamente
		// Post: Si el socket se ha conectado correctamente al otro extremo,
		//		 devuelve el descriptor de fichero asociado a dicha comunicación,
		//		 y en caso contrario devuelve un valor negativo.
		int Connect();

		// Encapsulación de la llamada send()
		// Pre: El socket se ha creado y hay al menos una conexión activa
		// Post: Devuelve el número de bytes enviados, o bien 0 si
		//		 la comunicación termina o -1 si hay errores.
		ssize_t Send(const int fd, char* buf);

		// Encapsulación de la llamada recv()
		// Pre: El socket se ha creado y hay al menos una conexión activa
		// Post: Devuelve el número de bytes recibidos, o bien 0 si
		//		 la comunicación termina o -1 si hay errores.
		ssize_t Recv(const int fd, char* buf, const int B_LEN);
		
		// Encapsulación de la llamada send()
		// Pre: El socket se ha creado y hay al menos una conexión activa
		// Post: Devuelve el número de bytes enviados, o bien 0 si
		//		 la comunicación termina o -1 si hay errores.
		ssize_t Send(const int fd, const std::string buf);
		
		// Encapsulación de la llamada recv()
		// Pre: El socket se ha creado y hay al menos una conexión activa
		// Post: Devuelve el número de bytes recibidos, o bien 0 si
		//		 la comunicación termina o -1 si hay errores.
		ssize_t Recv(const int fd, std::string& buf, const int B_LEN);

		// Encapsulación de la llamada close()
		// Pre: El socket se ha creado y hay al menos una conexión activa
		// Post: Cierra la conexión con el socket cuyo descriptor es el del parámetro fd.
		bool Close(const int fd);
		
};

#endif
  