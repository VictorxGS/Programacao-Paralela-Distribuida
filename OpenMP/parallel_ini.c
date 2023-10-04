#include <stdio.h>
#include <omp.h>

int main(int argc, char** argv) {

    printf("Trecho Mono-thread\n");
    printf("Thread Id: %d\n" ,omp_get_thread_num());
    
    // Zona Paralelizada - Pragma omp parallel
    printf("Trecho Multi-thread - Inicio da zona de paralelizacao\n");
    #pragma omp parallel 
    {
        // imprime a quantidade de Threads utilizadas na Paralelização.
        printf("Thread Id: %d\n" ,omp_get_thread_num());
        // Por default o programa gerecia uma thread por núcleo (core) do processador.
    }
    printf("Trecho Multi-thread - Fim da zona de paralelizacao\n");

    printf("Trecho Mono-thread\n");
    printf("Thread Id: %d\n" ,omp_get_thread_num());
	
	return 0;
}