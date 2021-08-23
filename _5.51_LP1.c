/* ALUNO: THIAGO FELIPE VIANA DINIZ */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Biblioteca usada para evitar repetição na função rand
#include <locale.h> // Usada em windows 1252

int pergunta(int n1, int n2){ //Função para receber a resposta do estudante
	int chute;

	printf("Quanto e %d vezes %d?\n", n1, n2);
    scanf("%d", &chute);
	
	return chute;
}
int erros_repetidos(int resposta2, int resultado2){ //Função de verificação de erros
	int zero_um;
	
	if (resposta2 == resultado2){
		zero_um = 1;
	}else{
		zero_um = 0;
	}
	return zero_um;
}
void mensagem_acerto(){ // Função para escolher frase aleatória caso o estudante acerte a resposta
    int n;

    srand(time(NULL));

    n = 1 + rand() % 4; // Esolha de um número entre 1 e 4
    
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

    n = 1 + rand() % 4; // Esolha de um número entre 1 e 4

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
	setlocale(LC_ALL, "PORTUGUESE");

	int num_1, num_2, resultado, resposta;
	int verificar;

	srand(time(NULL)); //Função srand, deixando os valores de rand mais aleatórios

    num_1 = rand() % 10;//Função rand para números aleátorios
    num_2 = rand() % 10; 

    resultado = num_1 * num_2;//Paramentro para comparar a resposta correta com a resposta do aluno

	resposta = pergunta(num_1, num_2);//Chamada da função com a pergunta e resposta do aluno

	if (resultado == resposta){
        mensagem_acerto(); // Chama a função para imprimir uma mensagem de acerto aleatória
    }else{
        verificar = 0;//Variavél para validar o acerto ou erro repetidos do estudante
		while (verificar == 0){
			mensagem_erro(); // Chama a função para imprimir uma mensagem de erro aleatória
			scanf("%d", &resposta); // Escaneia a nova resposta do estudante

			verificar = erros_repetidos(resposta,resultado);//Chama uma função para verifificar a nova resposta do estudante
		}
		if (verificar == 1){//Condicional para imprimir resposta caso o estudante tenha acertado a pergunta
        	mensagem_acerto();
		}
    }
    system("pause"); // Pausa da função para que seja iniciado novamente
	return main();//Retorno da própria função para nova pergunta
}