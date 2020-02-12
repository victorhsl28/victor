#ifndef criptografa
#define criptografa
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 4000

long long int exponenciacao_modular(long long int base, long long int expoente, long long int modulo) //funcao para calcular a exponenciacao modular atraves do resto
{
   long long int counter = 1;
   while(expoente > 0)
   {
      counter = ((counter * base) % modulo);
      expoente--;
   }
   return counter;
}

void processo_criptografico(char lista_letra[], long long n, long long e)
{
	long long i;
	int counter = 0;
	int lista_numero[MAX];
	printf("Mensagem criptografada: ");
	for(i = 0; i < strlen(lista_letra); i++) //calcular o equivalente cifrado de cada letra de acordo com a tabela
	{
		if(lista_letra[i] == 'A')
		{
			printf("%llu ", exponenciacao_modular(2, e, n));
			lista_numero[counter] = exponenciacao_modular(2, e, n);
			counter++;
		}
		if(lista_letra[i] == 'B')
		{
			printf("%llu ", exponenciacao_modular(3, e, n));
			lista_numero[counter] = exponenciacao_modular(3, e, n);
			counter++;
		}
		if(lista_letra[i] == 'C')
		{
			printf("%llu ", exponenciacao_modular(4, e, n));
			lista_numero[counter] = exponenciacao_modular(4, e, n);
			counter++;
		}
		if(lista_letra[i] == 'D')
		{
			printf("%llu ", exponenciacao_modular(5, e, n));
			lista_numero[counter] = exponenciacao_modular(5, e, n);
			counter++;
		}
		if(lista_letra[i] == 'E')
		{
			printf("%llu ", exponenciacao_modular(6, e, n));
			lista_numero[counter] = exponenciacao_modular(6, e, n);
			counter++;
		}
		if(lista_letra[i] == 'F')
		{
			printf("%llu ", exponenciacao_modular(7, e, n));
			lista_numero[counter] = exponenciacao_modular(7, e, n);
			counter++;
		}
		if(lista_letra[i] == 'G')
		{
			printf("%llu ", exponenciacao_modular(8, e, n));
			lista_numero[counter] = exponenciacao_modular(8, e, n);
			counter++;
		}
		if(lista_letra[i] == 'H')
		{
			printf("%llu ", exponenciacao_modular(9, e, n));
			lista_numero[counter] = exponenciacao_modular(9, e, n);
			counter++;
		}
		if(lista_letra[i] == 'I')
		{
			printf("%llu ", exponenciacao_modular(10, e, n));
			lista_numero[counter] = exponenciacao_modular(10, e, n);
			counter++;
		}
		if(lista_letra[i] == 'J')
		{
			printf("%llu ", exponenciacao_modular(11, e, n));
			lista_numero[counter] = exponenciacao_modular(11, e, n);
			counter++;
		}
		if(lista_letra[i] == 'K')
		{
			printf("%llu ", exponenciacao_modular(12, e, n));
			lista_numero[counter] = exponenciacao_modular(12, e, n);
			counter++;
		}
		if(lista_letra[i] == 'L')
		{
			printf("%llu ", exponenciacao_modular(13, e, n));
			lista_numero[counter] = exponenciacao_modular(13, e, n);
			counter++;
		}
		if(lista_letra[i] == 'M')
		{
			printf("%llu ", exponenciacao_modular(14, e, n));
			lista_numero[counter] = exponenciacao_modular(14, e, n);
			counter++;
		}
		if(lista_letra[i] == 'N')
		{
			printf("%llu ", exponenciacao_modular(15, e, n));
			lista_numero[counter] = exponenciacao_modular(15, e, n);
			counter++;
		}
		if(lista_letra[i] == 'O')
		{
			printf("%llu ", exponenciacao_modular(16, e, n));
			lista_numero[counter] = exponenciacao_modular(16, e, n);
			counter++;
		}
		if(lista_letra[i] == 'P')
		{
			printf("%llu ", exponenciacao_modular(17, e, n));
			lista_numero[counter] = exponenciacao_modular(17, e, n);
			counter++;
		}
		if(lista_letra[i] == 'Q')
		{
			printf("%llu ", exponenciacao_modular(18, e, n));
			lista_numero[counter] = exponenciacao_modular(18, e, n);
			counter++;
		}
		if(lista_letra[i] == 'R')
		{
			printf("%llu ", exponenciacao_modular(19, e, n));
			lista_numero[counter] = exponenciacao_modular(19, e, n);
			counter++;
		}
		if(lista_letra[i] == 'S')
		{
			printf("%llu ", exponenciacao_modular(20, e, n));
			lista_numero[counter] = exponenciacao_modular(20, e, n);
			counter++;
		}
		if(lista_letra[i] == 'T')
		{
			printf("%llu ", exponenciacao_modular(21, e, n));
			lista_numero[counter] = exponenciacao_modular(21, e, n);
			counter++;
		}
		if(lista_letra[i] == 'U')
		{
			printf("%llu ", exponenciacao_modular(22, e, n));
			lista_numero[counter] = exponenciacao_modular(22, e, n);
			counter++;
		}
		if(lista_letra[i] == 'V')
		{
			printf("%llu ", exponenciacao_modular(23, e, n));
			lista_numero[counter] = exponenciacao_modular(23, e, n);
			counter++;
		}
		if(lista_letra[i] == 'W')
		{
			printf("%llu ", exponenciacao_modular(24, e, n));
			lista_numero[counter] = exponenciacao_modular(24, e, n);
			counter++;
		}
		if(lista_letra[i] == 'X')
		{
			printf("%llu ", exponenciacao_modular(25, e, n));
			lista_numero[counter] = exponenciacao_modular(25, e, n);
			counter++;
		}
		if(lista_letra[i] == 'Y')
		{
			printf("%llu ", exponenciacao_modular(26, e, n));
			lista_numero[counter] = exponenciacao_modular(26, e, n);
			counter++;
		}
		if(lista_letra[i] == 'Z')
		{
			printf("%llu ", exponenciacao_modular(27, e, n));
			lista_numero[counter] = exponenciacao_modular(27, e, n);
			counter++;
		}
		if(lista_letra[i] == ' ')
		{
			printf("%llu ", exponenciacao_modular(28, e, n));
			lista_numero[counter] = exponenciacao_modular(28, e, n);
			counter++;
		}
	}
	int j;
	FILE *mensagem_criptografada = fopen("msg_criptografada.txt", "a");
	for(j = 0; j < counter; j++)
	{
		if(j == (counter - 1))
		{
			fprintf(mensagem_criptografada,"%d", lista_numero[j]);
		}
		else
		{ 
			fprintf(mensagem_criptografada,"%d ", lista_numero[j]);
		}
	}
	pclose(mensagem_criptografada);
	printf("\n");
}

#endif
