//libertar a memoria central utilizada 
void libertar() {
 Medicamento *tmp,*medic;

  HASH_ITER(hh, medicamentos, medic, tmp) {
    HASH_DEL(medicamentos,medic); 
    free(medic);            
  }
}
