//William Ribeiro Cavalcante Ferreira, Ra:22007117.

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strcpry()
#include <time.h>   // clock()
#include <conio.h>  // getch()
#include <locale.h> //Poder usar acentuação e ç;

struct Cliente
{
    char nome[50];
    int conta[5];
    float saldo;
};

typedef struct Cliente cliente; // vetor da struct cliente

//Varíaveis

int movimento = 0;   // número de movimentação
int comparacoes = 0; //número de comparações

// Introdução das funções  que aparecerão no código pela frente

void insectionsort(cliente *c, int x);
void selectionsort(cliente *c, int x);
void menu(cliente *c, int x);
void imprime(cliente *c, int x);

int main()
{ // Local de início da execução de um programa
    cliente *vetor;
    int nclientes;
    

    printf("Escreva quantos Clientes possui:"); // Limite do ciclo ´for´ logo abaixo
    scanf("%d", &nclientes);

    vetor = (cliente *)malloc(nclientes * sizeof(cliente));

    for (int i = 0; i < nclientes; i++)
    {
        printf("Escreva um certo nome para o Cliente:\n"); // Especificar os nomes dos clientes
        fflush(stdin);
        gets(vetor[i].nome);

        printf("Escreva o numero do cliente:\n"); // Especificar os números dos clientes
        scanf("%d", &vetor[i].conta);
        printf("Escreva o saldo do cliente:\n"); // Especificar os saldos dos clientes
        scanf("%f", &vetor[i].saldo);
    }
}

// menu(leitura do´arquivo')

void menu(cliente *c, int x)
{   float t;
    int op = -1;
    do
    {

        system("cls");
        printf("A - Sair\n");
        printf("b - Seleção \n");
        printf("c - Inserção \n");
        printf("d - Imprimir clientes\n");
        printf("Escreva uma opção: \n");
        scanf("%i", &op);

        while (op != 0)
        {
            getchar();

            //Execução das informações do menu.
            if (op == 0)
            {

                printf("Programa terminado!");
                break;
            }
            else if (op == 1)
            {

                selectionsort(c, x);
                imprime(c, x);
                t = clock() - t;

                printf("tempo de execucao:%2.f\n", t);
                printf("comparacoes entre os saldos no selectionsort:%i\n", comparacoes);
                printf("movimentos entre os saldos no  selectionsort:%i\n\n", movimento);
                break;
            }
            else if (op == 2)
            {

                insectionsort(c, x);
                imprime(c, x);
                t = clock() - t;
                printf("tempo de execucao:%2.f\n", t);
                printf("comparacoes entre os saldos no inserctionsort:%i\n", comparacoes);
                printf("movimentos entre os saldos no  inserctionsort:%i\n\n", movimento);
                break;
            }
            else if (op == 3)
            {
                imprime(c, x);
                break;
            }
            else if (op == 4)
            {
                //sair;

                break;
            }
        }
    }
}

void insectionsort(cliente *c, int x)
{
    int i, j;
    cliente aux;
    i = 1;
    while (i < x)
    {
        aux = c[i];
        j = i;
        while (j > 0 && aux.saldo < c[i - j].saldo)
        {
            c[j] = c[j - 1];
            c[j] = aux;
            j--;
        }
        i++;
        comparacoes++;
    }
}

void selectionsort(cliente *c, int x)
{
    int i = 0, j, menor; //indice do vetor com menor saldo
    cliente troca;

    while (i < x - 1)
    {
        menor = i;
        j = i;
        while (j < x)
        {
            if (c[j].saldo < c[menor].saldo)
            {
                menor = j;
            }
            j++;
        }
        if (i != menor)
        {
            troca = c[i];
            c[i] = c[menor];
            c[menor] = troca;
        }
        i++;
        movimento++;
    }
}

void imprime(cliente *c, int x)
{ //decidir se será retirado

    int i = 0;

    printf("\n--------------Ordem Atual de Clientes:--------------\n\n");
    while (i < x)
    {
        printf("Nome:%sN° da Conta:%d\nSaldo:R$%.2f\n\n", c[i].nome, c[i].conta, c[i].saldo);
        i++;
    }
}


