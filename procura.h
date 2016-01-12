void procurar (char nome[15]) {
	
	char n[15];
	strcpy(n,nome);
	HASH_FIND_STR(medicamentos,n,med);
//HASH_FIND_STR(medicamentos,n,med); retorna apontador para o registo do medicamento com a chave "n"
	if (med) {
		printf("\nNome: %s\t Stock: %i\t Vendas: %i\n\n", med->nome, med->stock, med->vendas );

				
	}else{
		printf("\nMedicamento Inexistente\n");}

}
