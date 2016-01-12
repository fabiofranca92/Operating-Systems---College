void actualizar(char nome[15],int valor,int modo) {
	char n[15];
	strcpy(n,nome);
//HASH_FIND_STR(medicamentos,n,med); retorna um apontador (med) para a o registo da HashTable com a key "n";

		HASH_FIND_STR(medicamentos,n,med);
		if (med) {
//caso encontre podemos usar esse apontador para realizar as operações de actualização de stock
			if(modo==1){			
		    		med->stock = med->stock + valor;
			}else if(modo==2){
				int resto = valor-med->stock;
				med->stock = med->stock-valor;
				med->vendas = med->vendas + valor;
				if(med->stock < 0){
					med->stock = 0;
					printf("Stock Insuficiente, só foram entregues %i unidades ao cliente",resto);
				}
			}else{
				puts("Operação Inválida");
			}
		}else{
			printf("\nMedicamento inexistente\n");
		}

}
