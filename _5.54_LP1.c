/* ALUNO: THIAGO FELIPE VIANA DINIZ */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Biblioteca usada para evitar repeti��o na fun��o rand
#include <locale.h> // Usada em windows 1252

int aritimetico(){
	int operador;

	printf("Informe o n�mero correspondente ao Operador Aritm�tico desejado:\n");
	printf("1 - Adi��o\n");
	printf("2 - Subtra��o\n");
	printf("3 - Multiplica��o\n");
	printf("4 - Adi��o, Subtra��o e Multiplica��o\n");
	
	scanf("%d", &operador);
	if (operador != 1 && operador != 2 && operador != 3 && operador != 4){
		printf("Nenhum operador � correspondente a esse n�mero, digite novamente.\n");
		operador = aritimetico();
	}
	return operador;
}
int level(){ //Fun��o para mostrar ao estudante os n�veis de dificuldade
	long int nivel;
	printf("Informe o N�vel desejado:\n");
	printf("N�vel 1 - Contas entre 0-9\n");
	printf("N�vel 2 - Contas entre 0-99\n");
	printf("N�vel 3 - Contas entre 0-999\n");
	printf("N�vel 4 - Contas entre 0-9999\n");
	printf("N�vel 5 - Contas entre 0-99999\n");

	scanf("%ld", &nivel);
	printf("\nN�VEL %ld\n\n", nivel); 

	if (nivel == 1){
		nivel = 10;
	}else if (nivel == 2){
		nivel = 100;
	}else if (nivel == 3){
		nivel = 1000;
	}else if (nivel == 4){
		nivel = 10000;
	}else if (nivel == 5){
		nivel = 100000;
	}
	return nivel;
}
int pergunta(long int n1, long int n2, int tipo_pergunta,int aleatorio){ //Fun��o modificada para perguntar de acordo com o tipo de conta escolhida
	long int chute;

	if (tipo_pergunta == 1){
		printf("Quanto e %ld mais %ld?\n", n1, n2);
    	scanf("%ld", &chute);
	}else if (tipo_pergunta == 2){
		printf("Quanto e %ld menos %ld?\n", n1, n2);
    	scanf("%ld", &chute);
	}else if (tipo_pergunta == 3){
		printf("Quanto e %ld vezes %ld?\n", n1, n2);
    	scanf("%ld", &chute);
	}else if (tipo_pergunta == 4){

		switch(aleatorio){//Imprimir de acodo com o valor escolhido pela fun��o rand
			case 1:
				printf("Quanto e %ld mais %ld?\n", n1, n2);
    			scanf("%ld", &chute);
				break;
			case 2:
				printf("Quanto e %ld menos %ld?\n", n1, n2);
    			scanf("%ld", &chute);
				break;
			case 3:
				printf("Quanto e %ld vezes %ld?\n", n1, n2);
   			 	scanf("%ld", &chute);
				break;
			}
		}
	return chute;
}
void mensagem_acerto(){// Fun��o para escolher frase aleat�ria caso o estudante acerte a resposta
    int n;

    srand(time(NULL));

    n = 1 + rand() % 4;// Esolha de um n�mero entre 1 e 4
    
    switch(n){
        case 1:
        printf("Muito bom!\n");
        break;
        case 2:
        printf("Excelente!\n");
        break;
        case 3:
        printf("Bom trabalho!\n");
        break;
        case 4:
        printf("Continue assim!\n");
        break;
    }
}
void mensagem_erro(){// Fun��o para escolher frase aleat�ria caso o estudante erre a resposta
    int n;

    srand(time(NULL));

    n = 1 + rand() % 4;

    switch(n){
        case 1:
        printf("N�o. Tente novamente.\n");
        break;
        case 2:
        printf("Errado. Tente mais uma vez.\n");
        break;
        case 3:
        printf("N�o desista!\n");
        break;
        case 4:
        printf("N�o. Continue tentando.\n");
        break;
    }
}
int main(){
	setlocale(LC_ALL, "PORTUGUESE");

	long int num_1, num_2, resultado, resposta;
	int contador = 1, acertos = 0, erros = 0;
	int verificar, porcentagem, sinal, operador4 = 0;
	long int dificuldade;

	dificuldade = level();//Chamada da fun��o da escolha de n�vel

	sinal = aritimetico();//Chama a fun��o para definir o sinal que o estudante preferir

	while (contador < 10){// Repeti��o para limitar a quantidade de perguntas em 10
		srand(time(NULL));//Fun��o srand, deixando os valores de rand mais aleat�rios

		num_1 = rand() % dificuldade;//Fun��o rand para n�meros ale�torios
		num_2 = rand() % dificuldade;

		if (sinal == 1){//Condicional para definir de acordo com o sinal escolhido pelo estudante o resultado correto para compara��o
			resultado = num_1 + num_2;
		}else if (sinal == 2){
			resultado = num_1 - num_2;
		}else if (sinal == 3){
			resultado = num_1 * num_2;
		}else if (sinal == 4){
			operador4 = 1 + rand() % 3; //Fun��o rand usada para escolher um tipo de conta aleat�ria

			switch(operador4){
				case 1:
					resultado = num_1 + num_2;
					break;
				case 2:
					resultado = num_1 - num_2;
					break;
				case 3:
					resultado = num_1 * num_2;
					break;
			}
		}

		resposta = pergunta(num_1, num_2, sinal, operador4);//Chamada da fun��o com a pergunta e resposta do aluno
		
		if (resultado == resposta){
			mensagem_acerto();// Chama a fun��o para imprimir uma mensagem de acerto aleat�ria
			acertos = acertos + 1;//Acrescenta o valor de acertos do estudante
			contador++;//Sentinela de controle do contador
		}else{
			verificar = 0;//Variav�l para validar o acerto ou erro repetidos do estudante
			while (verificar == 0){
				mensagem_erro();// Chama a fun��o para imprimir uma mensagem de erro aleat�ria
				erros = erros + 1;//Acrescenta o valor de erros do estudante

				scanf("%ld", &resposta);// Escaneia a nova resposta do estudante

				verificar = erros_repetidos(resposta,resultado);//Chama uma fun��o para verifificar a nova resposta do estudante
				contador++;
				if (contador == 10){// Condicional para quebrar o while caso o contador chegue a 10
					break;
				}
			}
			if (verificar == 1){//Condicional para imprimir resposta caso o estudante tenha acertado a pergunta
				acertos = acertos + 1;
			}
		}
	}

	porcentagem = acertos * 10;//Calculo da porcentagem de acertos, por terem valores ate 10, a porcentagem � definida ao multiplica-lo por 10

	if (porcentagem >= 75){//Compara��o do valor da porcentagem 
		printf("\nParab�ns, voc� est� pronto, para o pr�ximo n�vel!\n");
	}else{
		printf("\nPor favor, pe�a ajuda a seu professor.\n");
	}
	system("pause"); // Pausa da fun��o para que seja iniciado novamente
	return main();//Retorno da pr�pria fun��o para nova pergunta
}