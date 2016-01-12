#include "uthash.h"
#include <string.h>  
#include <stdlib.h>  
#include <stdio.h>   
#include <time.h>
#include "med.h"

int main() {
	FILE *f;
	Medicamento med;
	int z;
	int i;
	int randNum=0;
	f = fopen("BD.bin","wb");
	if (f == NULL) {
		printf("Can't open file medicamentos\n");
		exit(1);
	}

	for (z = 0; z<20000000;z++) {

		for (i=0;i<11;i++) {
			randNum = 26 * (rand() / (RAND_MAX + 1.0));
			randNum = randNum+97;
			med.nome[i]=(char) randNum;


		}
	
	med.stock=10;
	med.vendas=10000*(rand() / (RAND_MAX + 1.0));
	fwrite(&med, sizeof(Medicamento), 1, f);
	}


	fclose(f);

	return 0;
}






