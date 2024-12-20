#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main( int argc, char *argv[] ){


if ( argc == 2 ){ //Si ho has posat correctament, crea un arxiu
	int fd = open( argv[1], O_CREAT | O_WRONLY, 0744 );
if ( fd == -1 ){ //Comprova errors a l'hora de crear l'arxiu
	perror("Error al crear l'arxiu");
	exit(-1);
}


while (1){ //El bucle amb 1 dura fins que es faci un break
	char a[1];
	ssize_t t = read( 0, a, 1 );
	if ( t== -1 ){ //Missatge error al llegir teclat
		perror("Error en la lectura"); 
        	exit(-1);
	}
	ssize_t w = write( fd, a, 1 );
	if ( w == -1 ){ //Missatge error al escriure en l'arxiu
		perror("Error en la escriptura");
                exit(-1);
        }

}
}
}
