#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int fatorial_recursiva(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * fatorial_recursiva(n - 1);
}

long long int fatorial_interativa(int n)
{
    long long int resultado = 1;

    for (; n > 0; n--)
    {
        resultado *= n;
    }

    return resultado;
}

int main(int argc, char *argv[])
{
    int p1;

    long long int resultado;

    clock_t inicio, fim;
    double tempo;

    if (argc < 2)
    {
        printf("Informe um número.\n");
        return 1;
    }

    p1 = atoi(argv[1]);

    inicio = clock();

    for (int i = 0; i < 1000000; i++)
    {
        resultado = fatorial_recursiva(p1);
    }

    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Recursivo: %lld\n", resultado);
    printf("Tempo recursivo: %.6f segundos\n\n", tempo);

    inicio = clock();

    for (int i = 0; i < 1000000; i++)
    {
        resultado = fatorial_interativa(p1);
    }

    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Interativo: %lld\n", resultado);
    printf("Tempo interativo: %.6f segundos\n", tempo);

    return 0;
}