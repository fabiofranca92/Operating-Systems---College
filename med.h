typedef struct Medicamento{
	char nome[15];
	int stock;
	int vendas;
	UT_hash_handle hh;
}Medicamento; 


struct Medicamento *med, *tmp ,*medicamentos = NULL;
