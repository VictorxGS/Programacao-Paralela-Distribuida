# Programacao-Paralela-Distribuida

Rascunho:

Inicializando repositório de estudos de OpenMP.

O OpenMP é uma API de programação MultiThread de memória compartilhada.

As linguagen suportadas por essa Api são o Fortan, C e C++.
Nos cenários desse repositório esterei utilizando o a Linguagem C.

Estaremos paralelizando código "serializados".
O mesmo código que é utilizado na versão serial é também utilizado na versão paralela.

Fazer include de: #include <omp.h>

-gcc -o arq arq.c -fopenmp
./arq
