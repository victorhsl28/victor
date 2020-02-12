#include "cripto.h"
#include "descripto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define MAX 4000

long long mdc(long long x, long long y) //calcular o mdc entre dois numeros
{
	if (y == 0)
	{
		return x;
	}
	else
	{
		return mdc(y, x % y);
	}
}

long long eh_primo(long long x) //verificar se um numero e primo
{
	long long i, counter = 0;
	for (i = 1; i <= x; i++)
	{
		if(x % i == 0)
		{
			counter++;
		}
	}
	if(counter == 2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void sugerir_e(long long phi, long long e) //caso o e fornecido pelo usuario nao seja relativamente primo ao phi, void sugere um e valido
{
	long long i, d = 0;
	srand(time(NULL));

	while(d < 5)
	{
		i = rand()%phi;
		if(mdc(phi, i) == 1)
		{
			printf("%llu\n", i);
			d++;
		}
	}
}

void chave_publica(long long p, long long q, long long e) //gerar a chave publica
{
	printf("Digite um par de numeros primos:\n");
	scanf("%llu %llu", &p, &q);
	long long n = p*q;
	long long phi = (p-1) * (q-1);
	if(eh_primo(p) == 1)
	{
		if(eh_primo(q) == 1)
		{
			if(n < 28)
			{
				printf("Esses numeros sao muito pequenos para o anel!\n"); //n menor que os 28 caracteres da tabela
				chave_publica(p, q, e);
			}
			else
			{

				printf("Digite um e\n");
				scanf("%llu", &e);
				while(mdc(phi, e) != 1)
				{
					printf("Esse numero nao e relativamente primo! Sugestoes:\n");
					sugerir_e(phi, e);
					scanf("%llu", &e);
				}

				FILE *chave = fopen("chave.txt", "a");
				fprintf(chave,"Chave publica: (%llu, %llu)", n, e);
				fclose(chave);
				printf("Chave publica: (%llu, %llu)\n", n, e);
			}
		}
		else
		{
			printf("O segundo numero nao e primo!\n");
			chave_publica(p, q, e);
		}
	}
	else
	{
		printf("O primeiro numero nao e primo!\n");
		chave_publica(p, q, e);
	}
}

void criptografar()
{
	printf("Digite a mensagem: \n");
	char lista_letra[MAX];
	fgets(lista_letra, MAX, stdin);
	printf("Digite a chave publica recebida previamente:\n");
	long long n, e;
	scanf("%llu %llu", &n, &e);
	processo_criptografico(lista_letra, n, e); //Processo separado em outra biblioteca
}

void descriptografar()
{
	printf("Digite os dois numeros primos e o e:\n");
	long long p, q, e;
	scanf("%llu %llu %llu", &p, &q, &e);
	processo_descriptografico(p, q, e); //Processo separado em outra biblioteca
}

int main()
{

	while(1)
	{

		//menu
		long long escolha, p, q, e;
		printf("---------------------------------------------------------\n");
		printf("Escolha uma opcao:\n");
		printf("1- Gerar Chave Publica 2- Encriptar 3- Descriptar 4- Sair\n");
		printf("---------------------------------------------------------\n");
		scanf("%llu", &escolha);
		getchar();

		//Gerar chave pública
		if(escolha == 1)
		{
			chave_publica(p, q, e);
		}
		//Encriptar
		else if(escolha == 2)
		{
			criptografar();
		}
		//Descriptografar
		else if(escolha == 3)
		{
			descriptografar();
		}
		else if(escolha == 4)
		{
			break;
		}
	}
	return 0;
}
