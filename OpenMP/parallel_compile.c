#include <stdio.h>
#include <omp.h>

int main(int argc, char** argv) {

    // Controle de quantidades de Threads utilizadas pelo programa.
    // Por função:   
    omp_set_num_threads(3);

    // Por Variável de Ambienten (cli):
    // >> export OMP_NUM_THREADS = 3

    /* Para manter a integridade de execução, caso o programa 
       seja compilado sem chamada ao OpenMP e não ocorra o crash!
       Utilizamos o #if _OPENMP e #endif para proteger e evitar a execução  de 
       chamada da função do OpenMP. */
    int thread_id = 0;  
    
    #pragma omp parallel
    {   
        #if _OPENMP
            thread_id = omp_get_thread_num();
        #endif

        printf("Thread Id: %d\n" ,thread_id);
    }

    /* Caso o programa fosse executado sem referencia ao OpenMP "-fopenmp" e 
       sem a proteção do #if _OPENMP, a compilaçãoseria interrompida. 
       Devido a faltanda referencia da função:
       undefined reference to 'omp_get_thread_num' 
       
       Executar:  
       >> gcc -o protect_comp protect_comp.c
       >> ./protect_comp
    */
	
	return 0;
}
