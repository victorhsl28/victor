#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define MAX 1000

long long int calc_M(long long int c, long long int d, long long int n)
{
   long long int counter = 1;
   while(d > 0)
   {
      counter *= c;
      counter %= n;
      d--;
   }
   return counter;
}

long long calc_inverso(long long p, long long q, long long e)
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

long long equivalente_cifrado(long long m, long long e, long long n)
{
	return fmod(pow(m, e), n);
}

long long mdc(long long x, long long y)
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

long long eh_primo(long long x)
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

void sugerir_e(long long phi, long long e)
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

void chave_publica(long long p, long long q, long long e)
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
				printf("Esses numeros sao muito pequenos para o anel!\n");
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
	int lista_m[MAX];
	int counter = 0;
	fgets(lista_letra, MAX, stdin);

	printf("Digite a chave publica recebida previamente:\n");

	long long n, e;
	scanf("%llu %llu", &n, &e);

	printf("Mensagem criptografada: ");
	long long i;

	for(i = 0; i < strlen(lista_letra); i++)
	{
		if(lista_letra[i] == 'A')
		{
			printf("%llu ", equivalente_cifrado(2, e, n));
			lista_m[counter] = equivalente_cifrado(2, e, n);
			counter++;
		}
		if(lista_letra[i] == 'B')
		{
			printf("%llu ", equivalente_cifrado(3, e, n));
			lista_m[counter] = equivalente_cifrado(3, e, n);
			counter++;
		}
		if(lista_letra[i] == 'C')
		{
			printf("%llu ", equivalente_cifrado(4, e, n));
			lista_m[counter] = equivalente_cifrado(4, e, n);
			counter++;
		}
		if(lista_letra[i] == 'D')
		{
			printf("%llu ", equivalente_cifrado(5, e, n));
			lista_m[counter] = equivalente_cifrado(5, e, n);
			counter++;
		}
		if(lista_letra[i] == 'E')
		{
			printf("%llu ", equivalente_cifrado(6, e, n));
			lista_m[counter] = equivalente_cifrado(6, e, n);
			counter++;
		}
		if(lista_letra[i] == 'F')
		{
			printf("%llu ", equivalente_cifrado(7, e, n));
			lista_m[counter] = equivalente_cifrado(7, e, n);
			counter++;
		}
		if(lista_letra[i] == 'G')
		{
			printf("%llu ", equivalente_cifrado(8, e, n));
			lista_m[counter] = equivalente_cifrado(8, e, n);
			counter++;
		}
		if(lista_letra[i] == 'H')
		{
			printf("%llu ", equivalente_cifrado(9, e, n));
			lista_m[counter] = equivalente_cifrado(9, e, n);
			counter++;
		}
		if(lista_letra[i] == 'I')
		{
			printf("%llu ", equivalente_cifrado(10, e, n));
			lista_m[counter] = equivalente_cifrado(10, e, n);
			counter++;
		}
		if(lista_letra[i] == 'J')
		{
			printf("%llu ", equivalente_cifrado(11, e, n));
			lista_m[counter] = equivalente_cifrado(11, e, n);
			counter++;
		}
		if(lista_letra[i] == 'K')
		{
			printf("%llu ", equivalente_cifrado(12, e, n));
			lista_m[counter] = equivalente_cifrado(12, e, n);
			counter++;
		}
		if(lista_letra[i] == 'L')
		{
			printf("%llu ", equivalente_cifrado(13, e, n));
			lista_m[counter] = equivalente_cifrado(13, e, n);
			counter++;
		}
		if(lista_letra[i] == 'M')
		{
			printf("%llu ", equivalente_cifrado(14, e, n));
			lista_m[counter] = equivalente_cifrado(14, e, n);
			counter++;
		}
		if(lista_letra[i] == 'N')
		{
			printf("%llu ", equivalente_cifrado(15, e, n));
			lista_m[counter] = equivalente_cifrado(15, e, n);
			counter++;
		}
		if(lista_letra[i] == 'O')
		{
			printf("%llu ", equivalente_cifrado(16, e, n));
			lista_m[counter] = equivalente_cifrado(16, e, n);
			counter++;
		}
		if(lista_letra[i] == 'P')
		{
			printf("%llu ", equivalente_cifrado(17, e, n));
			lista_m[counter] = equivalente_cifrado(17, e, n);
			counter++;
		}
		if(lista_letra[i] == 'Q')
		{
			printf("%llu ", equivalente_cifrado(18, e, n));
			lista_m[counter] = equivalente_cifrado(18, e, n);
			counter++;
		}
		if(lista_letra[i] == 'R')
		{
			printf("%llu ", equivalente_cifrado(19, e, n));
			lista_m[counter] = equivalente_cifrado(19, e, n);
			counter++;
		}
		if(lista_letra[i] == 'S')
		{
			printf("%llu ", equivalente_cifrado(20, e, n));
			lista_m[counter] = equivalente_cifrado(20, e, n);
			counter++;
		}
		if(lista_letra[i] == 'T')
		{
			printf("%llu ", equivalente_cifrado(21, e, n));
			lista_m[counter] = equivalente_cifrado(21, e, n);
			counter++;
		}
		if(lista_letra[i] == 'U')
		{
			printf("%llu ", equivalente_cifrado(22, e, n));
			lista_m[counter] = equivalente_cifrado(22, e, n);
			counter++;
		}
		if(lista_letra[i] == 'V')
		{
			printf("%llu ", equivalente_cifrado(23, e, n));
			lista_m[counter] = equivalente_cifrado(23, e, n);
			counter++;
		}
		if(lista_letra[i] == 'W')
		{
			printf("%llu ", equivalente_cifrado(24, e, n));
			lista_m[counter] = equivalente_cifrado(24, e, n);
			counter++;
		}
		if(lista_letra[i] == 'X')
		{
			printf("%llu ", equivalente_cifrado(25, e, n));
			lista_m[counter] = equivalente_cifrado(25, e, n);
			counter++;
		}
		if(lista_letra[i] == 'Y')
		{
			printf("%llu ", equivalente_cifrado(26, e, n));
			lista_m[counter] = equivalente_cifrado(26, e, n);
			counter++;
		}
		if(lista_letra[i] == 'Z')
		{
			printf("%llu ", equivalente_cifrado(27, e, n));
			lista_m[counter] = equivalente_cifrado(27, e, n);
			counter++;
		}
		if(lista_letra[i] == ' ')
		{
			printf("%llu ", equivalente_cifrado(28, e, n));
			lista_m[counter] = equivalente_cifrado(28, e, n);
			counter++;
		}
	}
		int j;
		FILE *mensagem_criptografada = fopen("msg_criptografada.txt", "a");
		for(j = 0; j < counter; j++)
		{
			if(j == (counter - 1))
			{
				fprintf(mensagem_criptografada,"%d", lista_m[j]);
			}
			else
			{ 
				fprintf(mensagem_criptografada,"%d ", lista_m[j]);
			}
		}
		fclose(mensagem_criptografada);
		printf("\n");
}

void descriptografar()
{
		printf("Digite os dois numeros primos e o e:\n");
		char x;
		long long p, q, e;
		scanf("%llu %llu %llu", &p, &q, &e);
		getchar();
		long long d = calc_inverso(p, q, e);
		FILE *msg_descriptografada = fopen("msg_descriptografada.txt", "a");
		FILE *arquivo;
		char nome_do_arquivo[MAX];
		printf("Digite o nome do arquivo para descriptografar!\n");

		scanf("%s", nome_do_arquivo);
		arquivo = fopen(nome_do_arquivo, "r");
		if(arquivo == NULL)
		{
			printf("Arquivo nao encontrado!\n");
			descriptografar();
		}
		else
		{
			while(!feof(arquivo))
			{
				long long c;
				fscanf(arquivo, "%llu%c", &c, &x);
				long long n = p*q;
				long long int m = calc_M(c, d, n);
				
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
							fprintf(msg_descriptografada,"%c", 'Y');
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
				fclose(arquivo);
				fclose(msg_descriptografada);
				printf("\n");
	}
}

void menu()
{
	long long escolha, p, q, e;
	printf("--------------------------------------------------------------\n");
	printf("Escolha uma opcao:\n");
	printf("1- Gerar Chave Publica 2- Encriptar 3- Descriptografar 4- Sair\n");
	printf("--------------------------------------------------------------\n");
	scanf("%llu", &escolha);
	getchar();

	//Gerar chave pública
	if(escolha == 1)
	{
		chave_publica(p, q, e);
	}
	//Encriptar
	if(escolha == 2)
	{
		criptografar();
	}
	//Descriptografar
	if(escolha == 3)
	{
		descriptografar();
	}
}

int main()
{

	while(1)
	{

		//menu
		long long escolha, p, q, e;
		printf("--------------------------------------------------------------\n");
		printf("Escolha uma opcao:\n");
		printf("1- Gerar Chave Publica 2- Encriptar 3- Descriptografar 4- Sair\n");
		printf("--------------------------------------------------------------\n");
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
