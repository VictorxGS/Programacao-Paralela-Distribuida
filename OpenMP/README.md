# OPenMP
Frequentemente ao programar não exploramos totalmente o potencial computacional de nossas máquinas. Isso acontece porque muitas vezes executamos 
nossos códigos de maneira sequencial, sob uma única thread. O que resulta em subutilização de recursos e consequentemente obtendo um desempenho 
inferior devido a recursos unitilizados.

O OpenMP é uma API de programação MultiThread de memória compartilhada utilizada para paralelização de códigos nas linguagens C, C++ e Fortran.
A mesma nos possibilita manter a estrutura sequencial do código, minimizando a necessidade de grandes modificações para introduzir paralelismo 
em áreas com maior demanda de processamento. Nos cenários desse repostiório estarei aplicando alguns principais recursos da API do OpenMP na 
linguagem C para demonstrar a paralelização e o potencial de otimização no desempenho do código. 

***GetStart***

``-gcc -o file_name file_name.c -fopenmp``

``./file_name (input)``

```
#include <omp.h>
#pragma ommp parallel
#pragma omp parallel for
#pragma omp sections
#pragma omp Sigle
#pragma omp private
#pragma omp master
```

