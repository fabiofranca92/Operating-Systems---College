
void gravar(){
	FILE *file;
		
	if ( (file = fopen( "BD.bin", "wb+" )) == NULL ) {
	        perror("can't open: ");
	        exit(-1);
	}
//Este ciclo precorre todos os registos da HashTable gravando-os em ficheiro
	for(med=medicamentos; med != NULL; med=med->hh.next) {
	
		fwrite(med,sizeof(struct Medicamento),1,file);   
     
	}

}
