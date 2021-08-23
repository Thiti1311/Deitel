/* ALUNO: THIAGO FELIPE VIANA DINIZ */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Biblioteca usada para evitar repetição na função rand
#include <locale.h> // Usada em windows 1252

int level(){ //Função para mostrar ao estudante os níveis de dificuldade
	long int nivel;
	printf("Informe o Nível desejado:\n");
	printf("Nível 1 - Contas entre 0-9\n");
	printf("Nível 2 - Contas entre 0-99\n");
	printf("Nível 3 - Contas entre 0-999\n");
	printf("Nível 4 - Contas entre 0-9999\n");
	printf("Nível 5 - Contas entre 0-99999\n");

	scanf("%ld", &nivel);
	printf("\nNÍVEL %ld\n\n", nivel); 

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
int pergunta(int n1, int n2){ //Função para receber a resposta do estudante
	int chute;

	printf("Quanto e %d vezes %d?\n", n1, n2);
    scanf("%d", &chute);
	
	return chute;
}
int erros_repetidos(int resposta2, int resultado2){//Função de verificação de erros
	int zero_um;
	
	if (resposta2 == resultado2){
		zero_um = 1;
	}else{
		zero_um = 0;
	}
	return zero_um;
}
void mensagem_acerto(){// Função para escolher frase aleatória caso o estudante acerte a resposta
    int n;

    srand(time(NULL));

    n = 1 + rand() % 4;// Esolha de um número entre 1 e 4
    
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
void mensagem_erro(){// Função para escolher frase aleatória caso o estudante erre a resposta
    int n;

    srand(time(NULL));

    n = 1 + rand() % 4;

    switch(n){
        case 1:
        printf("Não. Tente novamente.\n");
        break;
        case 2:
        printf("Errado. Tente mais uma vez.\n");
        break;
        case 3:
        printf("Não desista!\n");
        break;
        case 4:
        printf("Não. Continue tentando.\n");
        break;
    }
}
int main(){
	long int num_1, num_2, resultado, resposta;
	int contador = 0, acertos = 0, erros = 0;
	int verificar, porcentagem;
	long int dificuldade;

	dificuldade = level();//Chamada da função da escolha de nível

	while (contador < 10){// Repetição para limitar a quantidade de perguntas em 10
		srand(time(NULL));//Função srand, deixando os valores de rand mais aleatórios

		num_1 = rand() % dificuldade;//Função rand para números aleátorios
		num_2 = rand() % dificuldade;

		resultado = num_1 * num_2;//Paramentro para comparar a resposta correta com a resposta do aluno

		resposta = pergunta(num_1, num_2);//Chamada da função com a pergunta e resposta do aluno
		
		if (resultado == resposta){
			mensagem_acerto();// Chama a função para imprimir uma mensagem de acerto aleatória
			acertos = acertos + 1;//Acrescenta o valor de acertos do estudante
			contador++;//Sentinela de controle do contador
		}else{
			verificar = 0;//Variavél para validar o acerto ou erro repetidos do estudante
			while (verificar == 0){
				mensagem_erro();// Chama a função para imprimir uma mensagem de erro aleatória
				erros = erros + 1;//Acrescenta o valor de erros do estudante

				scanf("%ld", &resposta);// Escaneia a nova resposta do estudante

				verificar = erros_repetidos(resposta,resultado);//Chama uma função para verifificar a nova resposta do estudante
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

	porcentagem = acertos * 10;//Calculo da porcentagem de acertos, por terem valores ate 10, a porcentagem é definida ao multiplica-lo por 10

	if (porcentagem >= 75){//Comparação do valor da porcentagem 
		printf("\nParabèns, você está pronto, para o próximo nível!\n");
	}else{
		printf("\nPor favor, peça ajuda a seu professor.\n");
	}
	system("pause"); // Pausa da função para que seja iniciado novamente
	return main();//Retorno da própria função para nova pergunta
}