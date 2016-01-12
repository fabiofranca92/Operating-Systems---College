void remover(char nome[15]) {
	char n[15];
	strcpy(n,nome);
	HASH_FIND_STR(medicamentos,n,med);
	if(med){	
//HASH_DEL(medicamentos,med); função que apaga a informação associada ao apontador devolvido pelo HASH_FIND_STR(medicamentos,n,med);
		HASH_DEL(medicamentos,med);		
	}else{
		printf("\nMedicamento inexistente\n");
		
	}	
}
