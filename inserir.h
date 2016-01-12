
void inserir(char name[15], int stock){
	FILE *file;
	srand( (unsigned)time(NULL) );
	if ( (file = fopen( "BD.bin", "ab+" )) == NULL ) {
	        perror("can't open: ");
	        exit(-1);
	}
//HASH_FIND_STR(medicamentos,name,med);	verificar se já existe medicamento com a chave "name";
		HASH_FIND_STR(medicamentos,name,med);	
		if(med==NULL){
			Medicamento *med=(struct Medicamento*)malloc(sizeof(struct Medicamento));
			strcpy(med->nome,name);
			med->stock = stock;
			med->vendas =0 ;
//Para que a string contida na estrutura se torne na chave unica
                        HASH_ADD_STR( medicamentos, nome, med);
		}else{
			printf("\nMedicamento já existe\n");
		}
	
}
