#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int fibonacci_recursiva(int n)
{
    if (n < 0 || n > 40)
    {
        printf("O número deve estar entre 0 e 40.\n");
        return -1;
    }

    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    // Chamada recursiva
    return fibonacci_recursiva(n - 1) + fibonacci_recursiva(n - 2);
}

long long int fibonacci_interativa(int n)
{
    long long int anterior = 0, atual = 1, temp;

    if (n < 0 || n > 40)
    {
        printf("O número deve estar entre 0 e 40.\n");
        return -1;
    }

    if (n == 0)
    {
        return 0;
    }

    for (int i = 1; i < n; i++)
    {
        temp = anterior + atual;
        anterior = atual;
        atual = temp;
    }

    return atual;
}

int main(int argc, char *argv[])
{
    int p1;

    long long int resultado;
    
    clock_t inicio, fim;
    double tempo;

    if (argc < 2)
    {
        printf("Uso: %s <numero>\n", argv[0]);
        return 1;
    }

    p1 = atoi(argv[1]);

    inicio = clock();

    for (int i = 0; i < 1000000; i++)
    {
        resultado = fibonacci_recursiva(p1);
    }

    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Recursivo: %d\n", resultado);
    printf("Tempo recursivo: %f segundos\n\n", tempo);

    inicio = clock();

    for (int i = 0; i < 1000000; i++)
    {
        resultado = fibonacci_interativa(p1);
    }

    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Interativo: %d\n", resultado);
    printf("Tempo interativo: %f segundos\n", tempo);

    return 0;
}