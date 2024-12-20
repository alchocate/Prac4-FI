#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[] ){

ssize_t c1,c2;
char buffer1,buffer2;
int posicio = 0; //Declararem variables per contar posició i linia
int linia = 1;

int f1 = open( argv[1], O_RDONLY, 744 ); //Abre archivo 1
if (f1 == -1){ //Si la lectura de l'arxiu 1 falla, dona un missatge d'error
	perror("Error obrint l'arxiu 1");
	exit(-1);
}


int f2 = open( argv[2], O_RDONLY, 744 ); //Abre archivo 2
if (f2 == -1){ //Missatge d'error per l'arxiu 2
        perror("Error obrint l'arxiu 2");
	exit(-1);
}



while(1){

	c1 = read( f1, &buffer1, 1);
	c2 = read( f2, &buffer2, 1);


	posicio ++;
	
	
	if (c1 > 0 && c2 > 0) { //Si un arxiu arriba al final, retornarà 0 
		if (buffer1 == '\n' && buffer2 == '\n'){ //Si hi ha salt de línia
			linia++; //Incrementarà en 1 la línia
		}


		if (buffer1 != buffer2) { //Si mentre no han arribar al final, tenen una lletra diferent
                printf("Son diferents a la posició %d, a la linea %d\n", posicio,linia); //Ho imprimirà i s'en sortirà
                break;
            }
        } else if (c1 == 0 && c2 == 0) { //Si els dos han arribat al final a l'hora sense tenir diferencies
            printf("Són iguals\n"); //Els arxius són iguals
            break;
        } else if (c1 == 0 || c2 == 0) { //Si s'ha acabat de llegir i l'altre no:
            printf("Tenen diferent longitud, són diferents\n"); //Seràn diferents per longitud
            break;
        }

}
}
