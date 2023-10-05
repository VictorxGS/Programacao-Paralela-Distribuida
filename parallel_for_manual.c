#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>


void inicializa(int **v, int size) {
  (*v) = (int *) malloc(sizeof(int)*size);
  for (int i = 0; i < size; i++) {
    (*v)[i] = rand() % 10000;
  }
}

float square(int x){
  int k = 0;
  while(k < 5000) k++;
  return sqrt(x);  
}

void imprime_vetor(int **v, int size){
	for (int i = 0; i < size; i++) {
        printf("Vetor[%d] = %d\n", i, (*v)[i]);
    }
}

int main(int argc, char **argv) {
	srand(time(NULL));
	
	int *vetor;
	int size = 1000000;
	
	inicializa(&vetor, size);

	printf("Dividindo a carga de trabalho entre 4 Threads.");

	#pragma omp parallel num_threads(4)
	{
		int threads = omp_get_num_threads();
		int thread_num = omp_get_thread_num();

		// Divisão do trabalho
		int local_init, local_end, chunk;
		chunk = size / threads;
		local_init = thread_num * chunk;
		local_end = (thread_num+1) * chunk;
		if ((threads-1) == thread_num) local_end = size;
		
		// Calcula cada thread responsável por seu bloco de memória
		for (int i = local_init; i < local_end; i++) {
			vetor[i] = square(vetor[i]);
		} 
	}

	return 0;
}