#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main(){

int c1,c2;
int posicio = 0;

const char *pathname = "Escritura.txt";
const char *pathname2 = "Escritura.txt";


int f1 = open(pathname, "r", 740 );
if (f1 == NULL){
	perror("Error obrint l'arxiu 1");
	return -1;
}


int f2 = open(pathname2, "r", 740 );
if (f2 == NULL){
        perror("Error obrint l'arxiu 2");
        return -1;
}



while(c1 !EOF || c2!EOF || iguals){ //EOF detecta quan l'arxiu ha arribat al final

	c1 = fgetc(f1); //La funció fgetc llegeix el seguent caràcter de l'arxiu
	c2 = fgetc(f2);


	posicio ++;
	
	if (c1 == EOF && c2 == EOX){
		printf("Son iguals");
		
	}


	if ( c1 == EOF  )



}


}
