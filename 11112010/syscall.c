#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>

main() {

    int leer;
    printf("Inicia Proceso\n");
    int num = fork();
        switch(num)
	{
		case -1: 
			perror("Error en proceso\n");
			break;
		case 0: 
		    printf("Proceso hijo y creo archivo\n");
			int archivo = creat("Archivonewa2", 0600);
            write(archivo, "1", 1);
			break;
		
		default: 
			printf("Soy el padre\n");
			wait(0);
			printf("hijo terminado.\n");
			close(archivo);
			archivo= open("Archivonewa2",O_RDONLY);
			char dato;
			leer= read(archivo,&dato,1);
			printf("Leido el número %d\n", leer);
			close(archivo);
			break;
	}
           
}
