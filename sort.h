

//ascendente
/*int vendas_sort(struct Medicamento *a, struct Medicamento *b){
    	return (a->vendas - b->vendas);
}
*/

//decrescente
int vendas_sort(struct Medicamento *a, struct Medicamento *b) {
    if (a->vendas == b->vendas) return 0;
    return (a->vendas < b->vendas) ? 1 : -1;
}

//função que imprime "quantidade" de linhas pretendidas para ficheiro
void imprimir(int quantidade ,FILE *f){
	int i = 0;
	for(med=medicamentos; med != NULL; med=(struct Medicamento*)(med->hh.next)) {
		
		if(i<=quantidade){
	       	fprintf(f,"Nome : %s\t Nr de Vendas %i\n", med->nome, med->vendas);
		}
	i++;
	}
}

void sort(int quantidade) {
	FILE *filetop;
	if ( (filetop = fopen( "Top", "w" )) == NULL ) {
		printf("Ficheiro Indisponível ");
	}
//função associada ao modo de ordenação "vendas_sort" que ordena a HashTable
	HASH_SORT(medicamentos,vendas_sort);
	
	imprimir(quantidade,filetop);
	printf("Foi criado um ficheiro como o top %i com sucesso",quantidade );
	fclose(filetop);
}
