#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
	for(i = 1; i < (p-1)*(q-1); i++)
	{
		if(fmod(i*e, (p-1)*(q-1)) == 1)
		{
			return i;
		}
	}
}

long long equivalente_cifrado(long long m, long long e, long long n)
{
	long long resto = fmod(pow(m, e), n);
	return resto;
}

long long mdc(long long x, long long y)
{
	if (y == 0)
	{
		return x;
	}
	else
	{
		return mdc(y,x % y);
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

void sugerir_e(long long multiplicacao, long long e)
{
	long long i, d = 0;
	for(i = 2; d < 5; i++)
	{
		if(mdc(multiplicacao, i) == 1)
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
	if(eh_primo(p) == 1 && eh_primo(q) == 1)
	{
		if(p*q < 28)
		{
			printf("Esses numeros sao muito pequenos para o anel!\n");
		}
		else
		{

			printf("Digite um e\n");
			scanf("%llu", &e);
			while(mdc((p-1) * (q-1), e) != 1)
			{
				printf("Esse numero nao e relativamente primo! Sugestoes:\n");
				sugerir_e((p-1) * (q-1), e);
				scanf("%llu", &e);
			}

			FILE *chave = fopen("chave.txt", "a");
			fprintf(chave,"Chave publica: (%llu, %llu)", p*q, e);
			fclose(chave);
			printf("Chave publica: (%llu, %llu)\n", p*q, e);
		}
	}
}

void criptografar()
{
	printf("Digite a mensagem: \n");
	char lista[MAX];
	int lista_numero[MAX];
	int counter = 0;
	fgets(lista, MAX, stdin);

	printf("Digite a chave publica recebida previamente:\n");

	long long n_lido, e_lido;
	scanf("%llu %llu", &n_lido, &e_lido);

	printf("Mensagem criptografada: ");
	long long i;

	for(i = 0; i < strlen(lista); i++)
	{
		if(lista[i] == 'A')
		{
			printf("%llu ", equivalente_cifrado(2, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(2, e_lido, n_lido);
			counter++;
		}
		if(lista[i] == 'B')
		{
			printf("%llu ", equivalente_cifrado(3, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(3, e_lido, n_lido);
			counter++;
		}
		if(lista[i] == 'C')
		{
			printf("%llu ", equivalente_cifrado(4, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(4, e_lido, n_lido);
			counter++;
		}
		if(lista[i] == 'D')
		{
			printf("%llu ", equivalente_cifrado(5, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(5, e_lido, n_lido);
			counter++;
		}
		if(lista[i] == 'E')
		{
			printf("%llu ", equivalente_cifrado(6, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(6, e_lido, n_lido);
			counter++;
		}
		if(lista[i] == 'F')
		{
			printf("%llu ", equivalente_cifrado(7, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(7, e_lido, n_lido);
			counter++;
		}
		if(lista[i] == 'G')
		{
			printf("%llu ", equivalente_cifrado(8, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(8, e_lido, n_lido);
			counter++;
		}
		if(lista[i] == 'H')
		{
			printf("%llu ", equivalente_cifrado(9, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(9, e_lido, n_lido);
			counter++;
		}
		if(lista[i] == 'I')
		{
			printf("%llu ", equivalente_cifrado(10, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(10, e_lido, n_lido);
			counter++;
		}
		if(lista[i] == 'J')
		{
			printf("%llu ", equivalente_cifrado(11, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(11, e_lido, n_lido);
			counter++;
		}
		if(lista[i] == 'K')
		{
			printf("%llu ", equivalente_cifrado(12, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(12, e_lido, n_lido);
			counter++;
		}
		if(lista[i] == 'L')
		{
			printf("%llu ", equivalente_cifrado(13, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(13, e_lido, n_lido);
			counter++;
		}
		if(lista[i] == 'M')
		{
			printf("%llu ", equivalente_cifrado(14, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(14, e_lido, n_lido);
			counter++;
		}
		if(lista[i] == 'N')
		{
			printf("%llu ", equivalente_cifrado(15, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(15, e_lido, n_lido);
			counter++;
		}
		if(lista[i] == 'O')
		{
			printf("%llu ", equivalente_cifrado(16, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(16, e_lido, n_lido);
			counter++;
		}
		if(lista[i] == 'P')
		{
			printf("%llu ", equivalente_cifrado(17, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(17, e_lido, n_lido);
			counter++;
		}
		if(lista[i] == 'Q')
		{
			printf("%llu ", equivalente_cifrado(18, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(18, e_lido, n_lido);
			counter++;
		}
		if(lista[i] == 'R')
		{
			printf("%llu ", equivalente_cifrado(19, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(19, e_lido, n_lido);
			counter++;
		}
		if(lista[i] == 'S')
		{
			printf("%llu ", equivalente_cifrado(20, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(20, e_lido, n_lido);
			counter++;
		}
		if(lista[i] == 'T')
		{
			printf("%llu ", equivalente_cifrado(21, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(21, e_lido, n_lido);
			counter++;
		}
		if(lista[i] == 'U')
		{
			printf("%llu ", equivalente_cifrado(22, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(22, e_lido, n_lido);
			counter++;
		}
		if(lista[i] == 'V')
		{
			printf("%llu ", equivalente_cifrado(23, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(23, e_lido, n_lido);
			counter++;
		}
		if(lista[i] == 'W')
		{
			printf("%llu ", equivalente_cifrado(24, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(24, e_lido, n_lido);
			counter++;
		}
		if(lista[i] == 'X')
		{
			printf("%llu ", equivalente_cifrado(25, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(25, e_lido, n_lido);
			counter++;
		}
		if(lista[i] == 'Y')
		{
			printf("%llu ", equivalente_cifrado(26, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(26, e_lido, n_lido);
			counter++;
		}
		if(lista[i] == 'Z')
		{
			printf("%llu ", equivalente_cifrado(27, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(27, e_lido, n_lido);
			counter++;
		}
		if(lista[i] == ' ')
		{
			printf("%llu ", equivalente_cifrado(28, e_lido, n_lido));
			lista_numero[counter] = equivalente_cifrado(28, e_lido, n_lido);
			counter++;
		}
	}
		int j;
		FILE *mensagem = fopen("mensagem.txt", "a");
		for(j = 0; j < counter; j++)
		{
			if(j == (counter - 1))
			{
				fprintf(mensagem,"%d", lista_numero[j]);
			}
			else
			{ 
				fprintf(mensagem,"%d ", lista_numero[j]);
			}
		}
		fclose(mensagem);
		printf("\n");
}

void desencriptar()
{
	printf("Digite os dois numeros primos e o e:\n");
		char x;
		long long primo_um, primo_dois, e_dois;
		scanf("%llu %llu %llu", &primo_um, &primo_dois, &e_dois);
		getchar();
		long long d = calc_inverso(primo_um, primo_dois, e_dois);
		FILE *descrip = fopen("descrip.txt", "a");
		FILE *arquivo;
		char nome_do_arquivo[MAX];
		printf("Digite o nome do arquivo para descriptografar!\n");

		scanf("%s", nome_do_arquivo);
		arquivo = fopen(nome_do_arquivo, "r");
		int i;
		while(!feof(arquivo))
		{
			long long c;
			fscanf(arquivo, "%llu%c", &c, &x);
			long long int numero = calc_M(c, d, primo_um*primo_dois);
			
					if(numero == 2)
					{
						printf("A");
						fprintf(descrip,"%c", 'A');
					}
					if(numero == 3)
					{
						printf("B");
						fprintf(descrip,"%c", 'B');
					}
					if(numero == 4)
					{
						printf("C");
						fprintf(descrip,"%c", 'C');
					}
					if(numero == 5)
					{
						printf("D");
						fprintf(descrip,"%c", 'D');
					}
					if(numero == 6)
					{
						printf("E");
						fprintf(descrip,"%c", 'E');
					}
					if(numero == 7)
					{
						printf("F");
						fprintf(descrip,"%c", 'F');
					}
					if(numero == 8)
					{
						printf("G");
						fprintf(descrip,"%c", 'G');
					}
					if(numero == 9)
					{
						printf("H");
						fprintf(descrip,"%c", 'H');
					}
					if(numero == 10)
					{
						printf("I");
						fprintf(descrip,"%c", 'I');
					}
					if(numero == 11)
					{
						printf("J");
						fprintf(descrip,"%c", 'J');
					}
					if(numero == 12)
					{
						printf("K");
						fprintf(descrip,"%c", 'K');
					}
					if(numero == 13)
					{
						printf("L");
						fprintf(descrip,"%c", 'L');
					}
					if(numero == 14)
					{
						printf("M");
						fprintf(descrip,"%c", 'M');
					}
					if(numero == 15)
					{
						printf("N");
						fprintf(descrip,"%c", 'N');
					}
					if(numero == 16)
					{
						printf("O");
						fprintf(descrip,"%c", 'O');
					}
					if(numero == 17)
					{
						printf("P");
						fprintf(descrip,"%c", 'P');
					}
					if(numero == 18)
					{
						printf("Q");
						fprintf(descrip,"%c", 'Q');
					}
					if(numero == 19)
					{
						printf("R");
						fprintf(descrip,"%c", 'R');
					}
					if(numero == 20)
					{
						printf("S");
						fprintf(descrip,"%c", 'S');
					}
					if(numero == 21)
					{
						printf("T");
						fprintf(descrip,"%c", 'T');
					}
					if(numero == 22)
					{
						printf("U");
						fprintf(descrip,"%c", 'Y');
					}
					if(numero == 23)
					{
						printf("V");
						fprintf(descrip,"%c", 'V');
					}
					if(numero == 24)
					{
						printf("W");
						fprintf(descrip,"%c", 'W');
					}
					if(numero == 25)
					{
						printf("X");
						fprintf(descrip,"%c", 'X');
					}
					if(numero == 26)
					{
						printf("Y");
						fprintf(descrip,"%c", 'Y');
					}
					if(numero == 27)
					{
						printf("Z");
						fprintf(descrip,"%c", 'Z');
					}
					if(numero == 28)
					{
						printf(" ");
						fprintf(descrip,"%c", ' ');
					}
		}
			fclose(arquivo);
			fclose(descrip);
			printf("\n");
}

void menu()
{
	long long escolha, p, q, e;
	printf("-------------------------------------------------------\n");
	printf("Escolha uma opcao:\n");
	printf("1- Gerar chave publica 2- Encriptar 3- Desencriptar\n");
	printf("-------------------------------------------------------\n");
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
	//Desencriptar
	if(escolha == 3)
	{
		desencriptar();
	}
}

int main()
{

	while(1)
	{

		//menu
		long long escolha, p, q, e;
		printf("-----------------------------------------------------------\n");
		printf("Escolha uma opcao:\n");
		printf("1- Gerar chave publica 2- Encriptar 3- Desencriptar 4- Sair\n");
		printf("-----------------------------------------------------------\n");
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
		//Desencriptar
		else if(escolha == 3)
		{
			desencriptar();
		}
		else if(escolha == 4)
		{
			break;
		}
	}
	return 0;
}
