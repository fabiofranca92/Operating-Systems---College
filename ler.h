int ler(){
	Medicamento m;
	Medicamento *med = NULL;
	char n[15];
	FILE *file;
	int i=0;
	int j=0;

	if ( (file = fopen( "BD.bin", "rb" )) == NULL ) {
		printf("Ficheiro Indisponível ");
	}
	
	while(fread(&m,sizeof(m),1,file) == 1){
		i++;
    	}
	
	for(j=0 ; j<i;j++){
//percorre as estruturas no ficheiro		
		fseek(file,sizeof(struct Medicamento)*(j),SEEK_SET);   	
		fread(&m,sizeof(struct Medicamento),1,file);
		Medicamento *med=(struct Medicamento*)malloc(sizeof(struct Medicamento));
		med->stock = m.stock;
		med->vendas= m.vendas;
		strcpy(med->nome,m.nome);
		//printf("Nome : %s\t Stock %i\n", med->nome, med->stock);
		HASH_ADD_STR(medicamentos, nome, med);
//HASH_ADD_STR(medicamentos, nome, med); adiciona a informação alocada no "med" à Hash Table
	
	}
	fclose(file);
}
