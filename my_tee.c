#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main(){


const char *pathname = "Escritura.txt";
char a;


int fd = open(pathname, O_CREAT | O_WRONLY, 740 );

while (1){
a = read("\n:"  );
int w = write(fd, 'A', 4);

}

}
