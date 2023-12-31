#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
	// Cálculo de quantos numeros primos entre 1 e N.
	
	unsigned long n = 99999;
	unsigned long aux = 2;

	unsigned long primes = 0;
	//Escalonamento dinamico: cada thread executa uma iteração (fcfs)
	#pragma omp parallel for firstprivate(aux) reduction(+:primes) schedule(dynamic)
	for (unsigned long i = 2; i < n; i++) {
		
		while (aux < i) {
			if (i % aux == 0) break;
			aux++;
		}
		
		if (aux == i) primes++;

		aux = 2;	
	}

	printf("%lu primos entre 1 e %lu\n",primes,n);

	return 0;
}