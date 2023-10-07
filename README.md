# Programacao-Paralela-Distribuida

Rascunho:
OPenMP

O OpenMP é uma API de programação MultiThread de memória compartilhada utilizada para paralelização de códigos nas linguagens C, C++ e Fortran.
Nos cenários desse repostiório estarei aplicando alguns principais recursos da API do OpenMP para demonstrar a paralelização e consequentemente 
otimização o desempenho do mesmo.

Motivação:
Rotineiramente quando programamos não utilizamos todo o poder computacional que temos em nossas máquinas. Isso geralmente ocorre por executamos 
nossos códigos de forma sequencial e sob uma única thread, deixado de ter uma permformance melhor.

Estaremos paralelizando código "serializados".
O mesmo código que é utilizado na versão serial é também utilizado na versão paralela.

```
#include <omp.h>
#pragma ommp parallel
#pragma omp parallel for
#pragma omp sections
#pragma omp Sigle
#pragma omp private
#pragma omp master
```
CLI commmand compile:
``-gcc -o file_name file_name.c -fopenmp``
``./file_name``
