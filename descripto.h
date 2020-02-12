#include "cripto.h"
#ifndef descriptografa
#define descriptografa
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 4000

long long calc_inverso(long long p, long long q, long long e) //calcular o inverso modular
{
	long long i;
	long long phi = (p-1)*(q-1);
	for(i = 1; i < phi; i++)
	{
		if(fmod(i*e, phi) == 1)
		{
			return i;
		}
	}
}


void processo_descriptografico(long long p, long long q, long long e)
{
	long long d = calc_inverso(p, q, e);
	char x;
	FILE *msg_descriptografada = fopen("msg_descriptografada.txt", "a");
	FILE *arquivo;
	char nome_do_arquivo[MAX];
	printf("Digite o nome do arquivo para descriptografar!\n");

	scanf("%s", nome_do_arquivo);
	arquivo = fopen(nome_do_arquivo, "r");
	if(arquivo == NULL)
	{
		printf("Arquivo nao encontrado!\n");
		processo_descriptografico(p, q, e);
	}
	else
	{
		while(!feof(arquivo))
		{
			long long c;
			fscanf(arquivo, "%llu%c", &c, &x);
			long long n = p*q;
			long long int m = exponenciacao_modular(c, d, n); //encontrar o m
	
			if(m == 2)
			{
				printf("A");
				fprintf(msg_descriptografada,"%c", 'A');
			}
			if(m == 3)
			{
				printf("B");
				fprintf(msg_descriptografada,"%c", 'B');
			}
			if(m == 4)
			{
				printf("C");
				fprintf(msg_descriptografada,"%c", 'C');
			}
			if(m == 5)
			{
				printf("D");
				fprintf(msg_descriptografada,"%c", 'D');
			}
			if(m == 6)
			{
				printf("E");
				fprintf(msg_descriptografada,"%c", 'E');
			}
			if(m == 7)
			{
				printf("F");
				fprintf(msg_descriptografada,"%c", 'F');
			}
			if(m == 8)
			{
				printf("G");
				fprintf(msg_descriptografada,"%c", 'G');
			}
			if(m == 9)
			{
				printf("H");
				fprintf(msg_descriptografada,"%c", 'H');
			}
			if(m == 10)
			{
				printf("I");
				fprintf(msg_descriptografada,"%c", 'I');
			}
			if(m == 11)
			{
				printf("J");
				fprintf(msg_descriptografada,"%c", 'J');
			}
			if(m == 12)
			{
				printf("K");
				fprintf(msg_descriptografada,"%c", 'K');
			}
			if(m == 13)
			{
				printf("L");
				fprintf(msg_descriptografada,"%c", 'L');
			}
			if(m == 14)
			{
				printf("M");
				fprintf(msg_descriptografada,"%c", 'M');
			}
			if(m == 15)
			{
				printf("N");
				fprintf(msg_descriptografada,"%c", 'N');
			}
			if(m == 16)
			{
				printf("O");
				fprintf(msg_descriptografada,"%c", 'O');
			}
			if(m == 17)
			{
				printf("P");
				fprintf(msg_descriptografada,"%c", 'P');
			}
			if(m == 18)
			{
				printf("Q");
				fprintf(msg_descriptografada,"%c", 'Q');
			}
			if(m == 19)
			{
				printf("R");
				fprintf(msg_descriptografada,"%c", 'R');
			}
			if(m == 20)
			{
				printf("S");
				fprintf(msg_descriptografada,"%c", 'S');
			}
			if(m == 21)
			{
				printf("T");
				fprintf(msg_descriptografada,"%c", 'T');
			}
			if(m == 22)
			{
				printf("U");
				fprintf(msg_descriptografada,"%c", 'U');
			}
			if(m == 23)
			{
				printf("V");
				fprintf(msg_descriptografada,"%c", 'V');
			}
			if(m == 24)
			{
				printf("W");
				fprintf(msg_descriptografada,"%c", 'W');
			}
			if(m == 25)
			{
				printf("X");
				fprintf(msg_descriptografada,"%c", 'X');
			}
			if(m == 26)
			{
				printf("Y");
				fprintf(msg_descriptografada,"%c", 'Y');
			}
			if(m == 27)
			{
				printf("Z");
				fprintf(msg_descriptografada,"%c", 'Z');
			}
			if(m == 28)
			{
				printf(" ");
				fprintf(msg_descriptografada,"%c", ' ');
			}
		}
		//fclose(arquivo);
		fclose(msg_descriptografada);
		printf("\n");
	}
}

#endif
