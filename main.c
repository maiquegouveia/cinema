#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>
#include "Bibliotecas.h"


	int verificarNome=0;
	int teste=0;
	int filmeValido=0,escolhaValida=0;
	int opcaoCadastro, opcaoRedefinir, opcaoIngresso;
    int opcaoMenuInicial=-1;
    int opcaoFilme;
    int opcao,opcao1, escolha;
    int i=0, i2=0, i3=-1,i7=-1,i8=0,i9=0,i11,vezes, q1;
    int verificacao;
    int variacao;
    int exclusao;
    int valorIngresso;
    int numero;
    int num=1;
    int guardarNumero;
    int option;
    int verSenha, verEmail=1, verNovoEmail;
    char filme1[]="O Incr�vel Maique";
    char filme2[]="A Volta dos Que N�o Foram";
    char filme3[]="Pneu Assassino";
    char filme4[]="As Aventuras de Jubileu";
    char filme5[]="O Magn�fico Valentin";
    char filme6[]="O Espetacular Pedro";
    char filme7[]="A Vit�ria dos Perdedores";
    char filme8[]="Furiosos e Velozes 38";
    char pergunta1[]="Qual � sua Cidade de Nascimento?";
    char pergunta2[]="Qual � o seu Animal Favorito?";
    char pergunta3[]="Qual � a sua Cor Favorita?";
    char verificarPergunta[100];
	int verPergunta;
	char filmeEscolha[25];
	char senhaVerificar[100];
	char verificacaoSenha[100],verificacaoEmail[100];
	int opcaoSeguranca=0;
    int verificarTamanho;
	FILE *arq;
struct salaCadeira{
	int valor;
    int numCadeiras;
    int codigo; /*<-- Quando um cliente escolher uma cadeira ela ficar� com o c�digo dele*/
    int numIngresso;
    int identificacaoSala;
    int identificacaoFilme;
};

struct sala{
    struct salaCadeira cadeiras[30];
};

struct filme{
	struct sala salas[20];
}filmes[8];

struct dadosCliente{
	int perguntaEscolhida;
	char respostaPergunta[100];
	char nomeCliente[50];
	char email[40];
	char senha[30];
	int verificarTamanhoNome;
	int totalPedido;
	int cod;
    int verificarTamanho;
}cliente[30];

void verificarEmailValido(int *verEmail, int *i3){
	int verificador=1;
	int qntVezes = 0;

	while(verificador!=0 && qntVezes<30){
		verificador=strcmp(cliente[qntVezes].email,verificacaoEmail);
		if(verificador!=0){
			qntVezes++;
		}
	}
	*verEmail = verificador;
	*i3 = qntVezes;
}

int criarEmail(){
	int verificador=1;
	int qntVezes = 0;

	while(verificador!=0 && qntVezes<30){
		verificador=strcmp(cliente[qntVezes].email,verificacaoEmail);
		if(verificador!=0){
			qntVezes++;
		}
	}
	return verificador;
}

void acessarConta(){
             do{
				verSenha=1;

      	 		printf("\nDigite o seu e-mail:\n");
 		 		gets(verificacaoEmail);
 		 		converterMaiusculo(verificacaoEmail);

		         printf("\nDigite sua senha:\n");
		 	     gets(verificacaoSenha);
		         printf("\n");


				// Aqui ser� feito a compara��o do Email da conta do cliente com o digitado pelo mesmo
				verificarEmailValido(&verEmail, &i3);

				// Caso ele tenha achado um email ele vai fazer a compara��o da senha digitada com a senha da conta encontrada
					if(verEmail==0){
						verSenha=strcmp(cliente[i3].senha, verificacaoSenha);

						if (verSenha==0){
					       	 printf("CONTA ENCONTRADA\n");
					       	 // Algumas vari�veis atribuidas para identifica��o do cliente ao longo do c�digo
					         verificacao = cliente[i3].cod;
					         verificarNome = i3;
					       	 opcaoMenuInicial=0;
					       	 guardarNumero=i3;
					       	 //

					    } else {
           					// Caso a senha digitada esteja incorreta mas o email esteja correto esse menu ser� exibido
       						printf("SENHA INCORRETA\n");

			       		do{
			       			printf("\n==============================\n");
					        printf(" 1 - Digitar Dados Novamente -\n");
					       	printf(" 2 - Esqueci Senha           -\n");
					       	printf(" 3 - Sair                    -\n");
					       	printf("------------------------------\n");
							printf("Escolha uma Op��o ->\n");
					        opcao1 = LimitarNumero();
							printf("\n");

							// Caso o cliente escolha a op��o 1 ele ter� que digitar seus dados novamente
						   	if(opcao1==1){
						   		opcao1=3;
					       		verEmail=1;
					       		verSenha=1;

							} else if(opcao1==2){
							// Caso a op��o 2 seja escolhida a pergunta de seguran�a escolhida pelo usu�rio ser� exibida e ele ter� que digitar a resposta

							if(cliente[i3].perguntaEscolhida==1){
							printf("\nQual � Sua Cidade de Nascimento?\n",cliente[i3].perguntaEscolhida);
							LimitarCaracteresResposta(verificarPergunta); // Limita a apenas letras
							converterMaiusculo(verificarPergunta);
							verPergunta = strcmp(cliente[i3].respostaPergunta,verificarPergunta);

						    } else if(cliente[i3].perguntaEscolhida==2){
						    printf("\nQual � seu Animal Favorito?\n",cliente[i3].perguntaEscolhida);
							LimitarCaracteresResposta(verificarPergunta);
							converterMaiusculo(verificarPergunta);
							verPergunta = strcmp(cliente[i3].respostaPergunta,verificarPergunta);

						    }else{
						    printf("\nQual sua Cor Favorita?\n",cliente[i3].perguntaEscolhida);
							LimitarCaracteresResposta(verificarPergunta);
							converterMaiusculo(verificarPergunta);
							verPergunta = strcmp(cliente[i3].respostaPergunta,verificarPergunta);
						    }
						if(verPergunta==0){
							printf("\nResposta v�lida.\n");
							// Caso ele digite a resposta certa ele ter� a op��o de mudar a senha da sua conta
							novaSenha(cliente[i3].senha);
							opcao1=3;
						} else {
							// Caso a resposta do cliente sej� inv�lida
							printf("\nResposta inv�lida.\n");
						}
					} else if (opcao1==3){
					//Caso a op��o 3 seja escolhida ele sair� do menu
			        	verEmail=0;
			       		verSenha=0;
			        	opcaoMenuInicial=-1;
		       		} else {
		       			printf("\nOp��o inv�lida.\n");
					}
		 	}while(opcao1!=3);
		 	opcao1=0;
		}

       } else {
		// Caso seja feita a verifica��o e o email digitado n�o esteja no sistema ele ter� a op��o de fazer o cadastro

       		printf("\nE-mail n�o cadastrado.\n");
       		do{
       			printf("\n=====================\n");
	       		printf(" 1 - Fazer Cadastro -\n");
	       		printf(" 2 - Sair           -\n");
	       		printf("---------------------\n");
	       		printf("Escolha uma Op��o ->\n");
				opcaoCadastro = LimitarNumero();
				printf("\n");

	   			if(opcaoCadastro==1){
                    i3=i7;
					i3++;
					i8=100+i3;

			    	printf("\nDigite o seu nome:\n");
			 		LimitarCaracteresNome(cliente[i3].nomeCliente);

					// Aqui ele escolher� uma pergunta de seguran�a caso ele esque�a a senha e precise trocar
			 		cliente[i3].perguntaEscolhida = perguntaResposta();

					// Aqui o cliente digitar� seu email e ser� feita a verifica��o se j� existe um igual no sistema
					do{
				 		printf("\nDigite o seu e-mail:\n");
				 		gets(verificacaoEmail);
				 		converterMaiusculo(verificacaoEmail);

						verEmail = criarEmail();

						if(verEmail!=0){

						// Se o E-Mail n�o estiver em uso ele vai seguir o processo de cadastro pedindo a senha
						senha(cliente[i3].senha);

						i7 = i3;
						strcpy(cliente[i3].email,verificacaoEmail);
						verificarNome = i3;

						// Aqui ser� atribu�da algumas vari�veis para identifica��o do cliente

				 	 	cliente[i3].cod=i8;
					 	converterMaiusculo(cliente[i3].nomeCliente);
					 	variacao=0;
					 	opcaoMenuInicial=0;
                        verificacao = cliente[i3].cod;
					 	opcaoCadastro=2;
					 	guardarNumero=i3;
					 	verEmail=0;
					 	//

					 	} else {
							printf("\nE-mail j� cadastrado no nosso sistema.\n");
						}
					} while (verEmail!=0);

				// Caso escolha a op��o 2 o cliente vai retornar pra o menu principal
				} else if(opcaoCadastro==2){
					verEmail=0;
					verEmail=0;
					printf("\nDesconectado.\n");

				// Caso o cliente digite uma op��o inv�lida
				} else {
					printf("\nOp��o inv�lida.\n");
				}

		}while(opcaoCadastro!=2);

		}

}while(verEmail!=0 && verSenha!=0);
}

void criarConta(){
    	i3=i7;
    	i3++;
	 	i8=100+i3;

    	printf("\nDigite o seu nome:\n");
 	 	LimitarCaracteresNome(cliente[i3].nomeCliente);
 		cliente[i3].perguntaEscolhida = perguntaResposta();

 	 	do{
	  		// Prosseguindo com o cadastro
			// Aqui o cliente digitar� o email
			printf("\n");
 			printf("\nDigite o seu e-mail:\n");
 			gets(verificacaoEmail);
 			converterMaiusculo(verificacaoEmail);

			// Aqui ser� feita a verifica��o se j� existe um E-Mail igual no sistema
		 	verEmail = criarEmail();
			// Caso o E-Mail n�o esteja cadastrado no sistema ainda
	 		if(verEmail!=0){
				// Aqui o cliente digitar� a senha para sua conta
				senha(cliente[i3].senha);
				strcpy(cliente[i3].email,verificacaoEmail); // Ser� salvo o E-Mail do cliente
				verificarNome=i3;

				// Caso o E-Mail esteja cadastrado no sistema
				} else {
					printf("\nE-mail j� existente.\n");
				}

			// Aqui est� finalizando o la�o de repeti��o do E-Mail
			} while (verEmail==0);
			// O cliente s� consegue sair do la�o de cria��o de conta, quando a conta for criada

			// Aqui ser� atribu�da vari�veis para identifica��o do cliente
 	 		cliente[i3].cod=i8;
	 		converterMaiusculo(cliente[i3].nomeCliente);
	 		variacao=0;
	 		opcaoMenuInicial=0;
	 		verificacao=0;
			i7=i3;
			//
}

void alterarResposta(){
	do{
	 	printf("\n--------------------------------------\n");
		printf("  Escolha uma pergunta de seguran�a  -\n");
		printf("======================================\n");
		printf(" 1 - Qual � sua cidade de nascimento? \n");
	 	printf(" 2 - Qual � seu Animal Favorito?      \n");
	 	printf(" 3 - Qual � sua cor favorita?         \n");
	 	printf(" 4 - Sair                             \n");
	 	printf("--------------------------------------\n");
		printf("Escolha uma Op��o ->\n");
	 	opcaoSeguranca=LimitarNumero();
		printf("\n");

	 	if(opcaoSeguranca>0 && opcaoSeguranca<4){
            cliente[i3].perguntaEscolhida=opcaoSeguranca;
	 		printf("\nResposta:\n");
			LimitarCaracteresPergunta(cliente[i3].respostaPergunta);
			converterMaiusculo(cliente[i3].respostaPergunta);
			printf("\n");
			printf("\nPergunta de Seguran�a alterada com sucesso.\n");

		 }	else if(opcaoSeguranca==4){
		 	opcaoSeguranca=1;
		 } else {
		 	opcaoSeguranca=0;
		 	printf("\n");
		 	printf("\nOp��o inv�lida.\n");
		 }
	} while (opcaoSeguranca==0);

}

int perguntaResposta(){
	do{
	 	printf("\n--------------------------------------\n");
		printf("  Escolha uma pergunta de seguran�a  -\n");
		printf("======================================\n");
		printf(" 1 - Qual � sua cidade de nascimento? \n");
	 	printf(" 2 - Qual � seu Animal Favorito?      \n");
	 	printf(" 3 - Qual � sua cor favorita?         \n");
	 	printf("--------------------------------------\n");
		printf("Escolha uma Op��o ->\n");
	 	opcaoSeguranca=LimitarNumero();
		printf("\n");

	 	if(opcaoSeguranca>0 && opcaoSeguranca<4){
	 		printf("\nResposta:\n");
			LimitarCaracteresPergunta(cliente[i3].respostaPergunta);
			converterMaiusculo(cliente[i3].respostaPergunta);
		} else {
			printf("\nOp��o inv�lida.\n");
		 	opcaoSeguranca=0;
		}
	} while (opcaoSeguranca==0);

	return opcaoSeguranca;
}

void escolherCadeira(){
	 do{
        // Aqui o cliente escolher� o filme que desejar
        // Temos 8 filmes diferentes
        // O nome de cada filme est� salvo em uma string

	            printf("\n--------------------------------------------\n");
	            printf("          Escolha o filme :                -\n");
	            printf("--------------------------------------------\n");
	            printf(" 1 - O Incr�vel Maique                     -\n");
	            printf(" 2 - A Volta dos Que N�o Foram             -\n");
	            printf(" 3 - Pneu Assassino                        -\n");
                printf(" 4 - As Aventuras de Jubileu               -\n");
                printf(" 5 - O Magn�fico Valentin                  -\n");
                printf(" 6 - O Espetacular Pedro                   -\n");
                printf(" 7 - A Vit�ria dos Perdedores              -\n");
                printf(" 8 - Furiosos e Velozes 38                 -\n");
	            printf("--------------------------------------------\n");
	            printf("Escolha uma Op��o ->\n");
	            opcaoFilme = LimitarNumero();

				// Aqui ser� verificado se o cliente digitou uma op��o v�lida
	            if((opcaoFilme >= 1) && (opcaoFilme <=8 )) {
	            	// filmeValido recebe 1 quando for digitado uma op��o v�lida
					filmeValido = 1;

				// Caso op��o inv�lida
				} else {
					// filmeValido recebe 0 e o la�o � repetido novamente
				    filmeValido=0;
					printf("\n\nOp��o inv�lida.\n");
				}

			// Aqui est� saindo do la�o de repeti��o
			// Apenas quando for um filme v�lido
		} while(filmeValido!=1);

				// Aqui a vari�vel string filmeEscolha vai receber o nome do filme escolhido anteriormente
				if(opcaoFilme==1){
		            	 strcpy(filmeEscolha,filme1);

					} else if(opcaoFilme==2){
						strcpy(filmeEscolha,filme2);

					} else if(opcaoFilme==3){
						strcpy(filmeEscolha,filme3);

					}else if (opcaoFilme==4){
					 strcpy(filmeEscolha,filme4);

					} else if(opcaoFilme==5){
						strcpy(filmeEscolha,filme5);

					} else if(opcaoFilme==6){
						strcpy(filmeEscolha,filme6);

					}else if(opcaoFilme==7){
						strcpy(filmeEscolha,filme7);

					} else if(opcaoFilme==8){
						strcpy(filmeEscolha,filme8);
					}

				do{
                        //aqui o cliente escolher� o dia, a sess�o e a sala
					printf("\n------------------------------------------------------------------------------------------------------------------------\n");
	                printf("\t\t\t\t-           Escolha a Sess�o :        -\n");
	                printf("------------------------------------------------------------------------------------------------------------------------\n");
	                printf("\t   -        QUI        -\t\t\t\t   -        SEX        -\t\n");
	                printf(" 1 - %s / 13:00 / SALA 1 -\t\t 6 - %s / 10:00 / SALA 6 -\t\n",filmeEscolha,filmeEscolha);
	                printf(" 2 - %s / 13:30 / SALA 2 -\t\t 7 - %s / 12:50 / SALA 2 -\t\n",filmeEscolha,filmeEscolha);
	                printf(" 3 - %s / 15:30 / SALA 2 -\t\t 8 - %s / 13:00 / SALA 9 -\t\n",filmeEscolha,filmeEscolha);
	                printf(" 4 - %s / 19:00 / SALA 3 -\t\t 9 - %s / 17:00 / SALA 1 -\t\n",filmeEscolha,filmeEscolha);
	                printf(" 5 - %s / 21:50 / SALA 4 -\t\t 10 - %s / 20:10 / SALA 5 -\t\n",filmeEscolha,filmeEscolha);
	                printf("------------------------------------------------------------------------------------------------------------------------\n");
                    printf("\t   -        SAB        -\t\t\t\t   -        DOM        -\t\n");
	                printf(" 11 - %s / 09:20 / SALA 4 -\t\t 16 - %s / 08:30 / SALA 3 -\t\n",filmeEscolha,filmeEscolha);
	                printf(" 12 - %s / 11:30 / SALA 9 -\t\t 17 - %s / 11:10 / SALA 1 -\t\n",filmeEscolha,filmeEscolha);
	                printf(" 13 - %s / 15:10 / SALA 3 -\t\t 18 - %s / 13:00 / SALA 7 -\t\n",filmeEscolha,filmeEscolha);
	                printf(" 14 - %s / 18:30 / SALA 5 -\t\t 19 - %s / 15:50 / SALA 8 -\t\n",filmeEscolha,filmeEscolha);
	                printf(" 15 - %s / 22:00 / SALA 5 -\t\t 20 - %s / 19:00 / SALA 2 -\t\n",filmeEscolha,filmeEscolha);
	                printf("------------------------------------------------------------------------------------------------------------------------\n");

	                printf("Escolha uma Op��o ->\n");
	                escolha = LimitarNumeroCadeiras();

					if((escolha>=1) && (escolha<=20)){
						escolhaValida=1;
					} else {
					    escolhaValida=0;
						printf("\nOp��o inv�lida.\n");
					}

				} while(escolhaValida!=1);

	                	if(escolha>=1 && escolha<=20){
	                		i2=escolha-1;
						}
	                    //nessa parte as cadeiras ser�o exibidas, somente ser�o exibidas as que tiverem com valor 0
	                    do{

                    // Qual tipo de ingresso o cliente deseja escolher MEIA ou INTEIRA
						 do{
						    printf("\n-------------------------------\n");
	                        printf(" Selecione o tipo do Ingresso -\n");
	                        printf("-------------------------------\n");
	                        printf(" 1- Meia       R$15,00        -\n");
	                        printf(" 2- Inteira    R$30,00        -\n");
	                        printf(" 3- Sair                      -\n");
							printf("-------------------------------\n");
		                    printf("Escolha uma Op��o ->\n");
opcaoIngresso = LimitarNumero();
		                    if((opcaoIngresso==1) || (opcaoIngresso==2)){
                            	teste=1;

							}else if(opcaoIngresso==3){
								teste=0;
							} else {
								printf("\nOp��o inv�lida.\n");
							}

		                } while(opcaoIngresso!=1 && opcaoIngresso!=2 && opcaoIngresso!=3);


					if(teste==1){

	                printf("\nEscolha a cadeira ou digite 0 para sair:\n");

	                for (i=0;i<30;i++){
                        if(i==5 || i==10 || i==15 || i==20 || i==25){
                        printf("\n");
	                }

	                if (filmes[opcaoFilme-1].salas[i2].cadeiras[i].codigo==0){


	                printf("  |%d|  ", filmes[opcaoFilme-1].salas[i2].cadeiras[i].numCadeiras);
	                if(i==0 || i==5){
                                printf(" ");
	               } else
	                if(i==1 || i==6 || i==2 || i==7 || i==3 || i==8){
                         printf(" ");
	                }


	                }else if(filmes[opcaoFilme-1].salas[i2].cadeiras[i].codigo!=0){
	                printf("        ");

	                }
	                }
	                    printf("\n\n\n\t|        tela        |\n");
	                    //aqui � onde o cliente escolhe as cadeiras
	                    escolha = LimitarNumeroCadeiras();
	                    printf("\n");

					 i=0;
	                while ((filmes[opcaoFilme-1].salas[i2].cadeiras[i].numCadeiras!=escolha) && (i<30)){
	                i++;

	                }
	                //Aqui ser� feita a checagem caso o cliente escolha uma cadeira indispon�vel

		                if ((filmes[opcaoFilme-1].salas[i2].cadeiras[i].numCadeiras==escolha) && (escolha>=1)&& (filmes[opcaoFilme-1].salas[i2].cadeiras[i].codigo==0)){
		                       // aqui a cadeira vai receber o valor 1 e n�o ser� exibida para um pr�ximo cliente


		                        //nessa parte aqui a cadeira recebe o c�digo do cliente, do filme, da sess�o e a numera��o do ingresso
								variacao++;
                                filmes[opcaoFilme-1].salas[i2].cadeiras[i].codigo=verificacao;
                                filmes[opcaoFilme-1].salas[i2].cadeiras[i].numIngresso=variacao;
                                filmes[opcaoFilme-1].salas[i2].cadeiras[i].identificacaoSala=i2;
                                filmes[opcaoFilme-1].salas[i2].cadeiras[i].identificacaoFilme=opcaoFilme-1;
                                if(opcaoIngresso==1){
// Nesta parte o ingresso vai receber  pre�o.
                                filmes[opcaoFilme-1].salas[i2].cadeiras[i].valor=15;
								}else{
	  							filmes[opcaoFilme-1].salas[i2].cadeiras[i].valor=30;
								}
								cliente[i3].totalPedido=cliente[i3].totalPedido + filmes[opcaoFilme-1].salas[i2].cadeiras[i].valor;
		                        printf("O assento escolhido foi: %d\n", filmes[opcaoFilme-1].salas[i2].cadeiras[i].numCadeiras);
		                        printf("\n");
		                        printf("Pedido finalizado.\n");
		                        printf("Deseja escolher mais uma cadeira?\n");
		                        printf("\n");
//caso a cadeira esteja inv�lida ou escolhida um destes if ser� acionado
		                } else if ((escolha<0) || (escolha>30)){
		                printf("Cadeira inv�lida.\n");
		                }else if( filmes[opcaoFilme-1].salas[i2].cadeiras[i].codigo!=0){
		                    printf("Cadeira j� escolhida.\n");
		                }
		            }

	                } while (teste!=0);
}

void visualizarPedido(){
	if(cliente[i3].totalPedido>0){

            num=1;
// essa � a parte onde o n�mero dos ingressos do cliente s�o organizados novamente
                for(i9=0;i9<8;i9++){
                for(i2=0;i2<20;i2++){
                for(i=0;i<30;i++){
                if (filmes[i9].salas[i2].cadeiras[i].codigo==verificacao){

                	filmes[i9].salas[i2].cadeiras[i].numIngresso=num++;

                }
			}
		}
	}
	// aqui todos os ingressos comprados pelo cliente ser�o exibidos para ele
            printf("\nEstes foram os ingressos comprados por voc�:\n");
            for(i11=0;i11<8;i11++){
            for(i2=0;i2<20;i2++){
            for(i=0;i<30;i++){

if(filmes[i11].salas[i2].cadeiras[i].codigo==verificacao){

// ap�s o ingresso passar pela verifica��o, ser� feita uma checagem por meio de "if's" para saber qual o filme, o dia, a sess�o e o pre�o do ingresso
if(filmes[i11].salas[i2].cadeiras[i].identificacaoFilme==0){
       				printf("\n\t|        Ingresso %d       |\n",filmes[i11].salas[i2].cadeiras[i].numIngresso);
                    printf("----------------------------------------------\n");
                    printf("\t   | %s |\n",filme1);

        } else if(filmes[i11].salas[i2].cadeiras[i].identificacaoFilme==1){

       				printf("\n\t|        Ingresso %d       |\n",filmes[i11].salas[i2].cadeiras[i].numIngresso);
                    printf("----------------------------------------------\n");
                    printf("\t   | %s |\n",filme2);

            	} else if(filmes[i11].salas[i2].cadeiras[i].identificacaoFilme==2){

       				printf("\n\t|        Ingresso %d       |\n",filmes[i11].salas[i2].cadeiras[i].numIngresso);
                    printf("----------------------------------------------\n");
                    printf("\t   | %s |\n",filme3);
                	}else if(filmes[i11].salas[i2].cadeiras[i].identificacaoFilme==3){

       				printf("\n\t|        Ingresso %d       |\n",filmes[i11].salas[i2].cadeiras[i].numIngresso);
                    printf("----------------------------------------------\n");
                    printf("\t   | %s |\n",filme4);
                	}else if(filmes[i11].salas[i2].cadeiras[i].identificacaoFilme==4){

       				printf("\n\t|        Ingresso %d       |\n",filmes[i11].salas[i2].cadeiras[i].numIngresso);
                    printf("----------------------------------------------\n");
                    printf("\t   | %s |\n",filme5);
                	}else if(filmes[i11].salas[i2].cadeiras[i].identificacaoFilme==5){

       				printf("\n\t|        Ingresso %d       |\n",filmes[i11].salas[i2].cadeiras[i].numIngresso);
                    printf("----------------------------------------------\n");
                    printf("\t   | %s |\n",filme6);
                	}else if(filmes[i11].salas[i2].cadeiras[i].identificacaoFilme==6){

       				printf("\n\t|        Ingresso %d       |\n",filmes[i11].salas[i2].cadeiras[i].numIngresso);
                    printf("----------------------------------------------\n");
                    printf("\t   | %s |\n",filme7);
                	}else if(filmes[i11].salas[i2].cadeiras[i].identificacaoFilme==7){

       				printf("\n\t|        Ingresso %d       |\n",filmes[i11].salas[i2].cadeiras[i].numIngresso);
                    printf("----------------------------------------------\n");
                    printf("\t   | %s |\n",filme8);
                	}

                    if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==0){
                    printf("----------------------------------------------");
                    printf("\n\t|         QUI          |\n");
                    printf("\n\t|   Sala 1 �s 13:00    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==1){
                    printf("----------------------------------------------");
                    printf("\n\t|         QUI          |\n");
                    printf("\n\t|   Sala 2 �s 13:30    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==2){
                    printf("----------------------------------------------");
                    printf("\n\t|         QUI          |\n");
                    printf("\n\t|   Sala 2 �s 15:30    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==3){
                    printf("----------------------------------------------");
                    printf("\n\t|         QUI          |\n");
                    printf("\n\t|   Sala 3 �s 19:00    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==4){
                    printf("----------------------------------------------");
                    printf("\n\t|         QUI          |\n");
                    printf("\n\t|   Sala 4 �s 21:50    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==5){
                    printf("----------------------------------------------");
                    printf("\n\t|         SEX          |\n");
                    printf("\n\t|   Sala 6 �s 10:00    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==6){
                    printf("----------------------------------------------");
                    printf("\n\t|         SEX          |\n");
                    printf("\n\t|   Sala 2 �s 12:50    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==7){
                    printf("----------------------------------------------");
                    printf("\n\t|         SEX          |\n");
                    printf("\n\t|   Sala 9 �s 13:00    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==8){
                    printf("----------------------------------------------");
                    printf("\n\t|         SEX          |\n");
                    printf("\n\t|   Sala 1 �s 17:00    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==9){
                    printf("----------------------------------------------");
                    printf("\n\t|         SEX          |\n");
                    printf("\n\t|   Sala 5 �s 20:10    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==10){
                    printf("----------------------------------------------");
                    printf("\n\t|         SAB          |\n");
                    printf("\n\t|   Sala 4 �s 09:20    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==11){
                    printf("----------------------------------------------");
                    printf("\n\t|         SAB          |\n");
                    printf("\n\t|   Sala 9 �s 11:30    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==12){
                    printf("----------------------------------------------");
                    printf("\n\t|         SAB          |\n");
                    printf("\n\t|   Sala 3 �s 15:10   |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==13){
                    printf("----------------------------------------------");
                    printf("\n\t|         SAB          |\n");
                    printf("\n\t|   Sala 5 �s 18:30    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==14){
                    printf("----------------------------------------------");
                    printf("\n\t|         SAB          |\n");
                    printf("\n\t|   Sala 5 �s 22:00    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==15){
                    printf("----------------------------------------------");
                    printf("\n\t|         DOM          |\n");
                    printf("\n\t|   Sala 3 �s 08:30   |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==16){
                    printf("----------------------------------------------");
                    printf("\n\t|         DOM          |\n");
                    printf("\n\t|   Sala 1 �s 11:10    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==17){
                    printf("----------------------------------------------");
                    printf("\n\t|   Sala 7 �s 13:00    |\n");
                    printf("\n\t|         DOM          |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==18){
                    printf("----------------------------------------------");
                    printf("\n\t|         DOM          |\n");
                    printf("\n\t|   Sala 8 �s 15:50    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==19){
                    printf("----------------------------------------------");
                    printf("\n\t|         DOM          |\n");
                    printf("\n\t|   Sala 2 �s 19:00    |\n");
                    }
                    printf("----------------------------------------------\n");
                    printf("\t| A Cadeira escolhida foi:|\n\t\t   |%d|\n", filmes[i11].salas[i2].cadeiras[i].numCadeiras);
                    printf("----------------------------------------------\n");
                    printf("\t|   Pre�o do Ingresso     |\n");
                    printf("\t\t| R$ %d |\n",filmes[i11].salas[i2].cadeiras[i].valor);



            }
}
            }
            }
            //caso o termine o loop e o programa n�o tenha achado nenhum ingresso com o nome do cliente ele exibira essa mensagem
	} else {
		printf("Nenhum dado computado.\n");
	}
}

void cancelarPedidos(){
 option=0;
			if(cliente[i3].totalPedido>0){

                    while(option!=2){

            num=1;
// essa � a parte onde o n�mero dos ingressos do cliente s�o organizados novamente
                for(i9=0;i9<8;i9++){
                for(i2=0;i2<20;i2++){
                for(i=0;i<30;i++){
                if (filmes[i9].salas[i2].cadeiras[i].codigo==verificacao){

                	filmes[i9].salas[i2].cadeiras[i].numIngresso=num++;

                }
			}
		}
	}
            for(i11=0;i11<8;i11++){
            for(i2=0;i2<20;i2++){
            for(i=0;i<30;i++){


          if(filmes[i11].salas[i2].cadeiras[i].codigo==verificacao){
//aqui ser� feita a checagem por meio de "if's" igual a fun��o anterior
				if(filmes[i11].salas[i2].cadeiras[i].identificacaoFilme==0){
       				printf("\n\t|        Ingresso %d       |\n",filmes[i11].salas[i2].cadeiras[i].numIngresso);
                    printf("----------------------------------------------\n");
                    printf("\t   | %s |\n",filme1);

        } else if(filmes[i11].salas[i2].cadeiras[i].identificacaoFilme==1){

       				printf("\n\t|        Ingresso %d       |\n",filmes[i11].salas[i2].cadeiras[i].numIngresso);
                    printf("----------------------------------------------\n");
                    printf("\t   | %s |\n",filme2);

            	} else if(filmes[i11].salas[i2].cadeiras[i].identificacaoFilme==2){

       				printf("\n\t|        Ingresso %d       |\n",filmes[i11].salas[i2].cadeiras[i].numIngresso);
                    printf("----------------------------------------------\n");
                    printf("\t   | %s |\n",filme3);
                	}else if(filmes[i11].salas[i2].cadeiras[i].identificacaoFilme==3){

       				printf("\n\t|        Ingresso %d       |\n",filmes[i11].salas[i2].cadeiras[i].numIngresso);
                    printf("----------------------------------------------\n");
                    printf("\t   | %s |\n",filme4);
                	}else if(filmes[i11].salas[i2].cadeiras[i].identificacaoFilme==4){

       				printf("\n\t|        Ingresso %d       |\n",filmes[i11].salas[i2].cadeiras[i].numIngresso);
                    printf("----------------------------------------------\n");
                    printf("\t   | %s |\n",filme5);
                	}else if(filmes[i11].salas[i2].cadeiras[i].identificacaoFilme==5){

       				printf("\n\t|        Ingresso %d       |\n",filmes[i11].salas[i2].cadeiras[i].numIngresso);
                    printf("----------------------------------------------\n");
                    printf("\t   | %s |\n",filme6);
                	}else if(filmes[i11].salas[i2].cadeiras[i].identificacaoFilme==6){

       				printf("\n\t|        Ingresso %d       |\n",filmes[i11].salas[i2].cadeiras[i].numIngresso);
                    printf("----------------------------------------------\n");
                    printf("\t   | %s |\n",filme7);
                	}else if(filmes[i11].salas[i2].cadeiras[i].identificacaoFilme==7){

       				printf("\n\t|        Ingresso %d       |\n",filmes[i11].salas[i2].cadeiras[i].numIngresso);
                    printf("----------------------------------------------\n");
                    printf("\t   | %s |\n",filme8);
                	}

                   if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==0){
                    printf("----------------------------------------------");
                    printf("\n\t|         QUI          |\n");
                    printf("\n\t|   Sala 1 �s 13:00    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==1){
                    printf("----------------------------------------------");
                    printf("\n\t|         QUI          |\n");
                    printf("\n\t|   Sala 2 �s 13:30    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==2){
                    printf("----------------------------------------------");
                    printf("\n\t|         QUI          |\n");
                    printf("\n\t|   Sala 2 �s 15:30    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==3){
                    printf("----------------------------------------------");
                    printf("\n\t|         QUI          |\n");
                    printf("\n\t|   Sala 3 �s 19:00    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==4){
                    printf("----------------------------------------------");
                    printf("\n\t|         QUI          |\n");
                    printf("\n\t|   Sala 4 �s 21:50    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==5){
                    printf("----------------------------------------------");
                    printf("\n\t|         SEX          |\n");
                    printf("\n\t|   Sala 6 �s 10:00    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==6){
                    printf("----------------------------------------------");
                    printf("\n\t|         SEX          |\n");
                    printf("\n\t|   Sala 2 �s 12:50    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==7){
                    printf("----------------------------------------------");
                    printf("\n\t|         SEX          |\n");
                    printf("\n\t|   Sala 9 �s 13:00    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==8){
                    printf("----------------------------------------------");
                    printf("\n\t|         SEX          |\n");
                    printf("\n\t|   Sala 1 �s 17:00    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==9){
                    printf("----------------------------------------------");
                    printf("\n\t|         SEX          |\n");
                    printf("\n\t|   Sala 5 �s 20:10    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==10){
                    printf("----------------------------------------------");
                    printf("\n\t|         SAB          |\n");
                    printf("\n\t|   Sala 4 �s 09:20    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==11){
                    printf("----------------------------------------------");
                    printf("\n\t|         SAB          |\n");
                    printf("\n\t|   Sala 9 �s 11:30    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==12){
                    printf("----------------------------------------------");
                    printf("\n\t|         SAB          |\n");
                    printf("\n\t|   Sala 3 �s 15:10   |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==13){
                    printf("----------------------------------------------");
                    printf("\n\t|         SAB          |\n");
                    printf("\n\t|   Sala 5 �s 18:30    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==14){
                    printf("----------------------------------------------");
                    printf("\n\t|         SAB          |\n");
                    printf("\n\t|   Sala 5 �s 22:00    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==15){
                    printf("----------------------------------------------");
                    printf("\n\t|         DOM          |\n");
                    printf("\n\t|   Sala 3 �s 08:30   |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==16){
                    printf("----------------------------------------------");
                    printf("\n\t|         DOM          |\n");
                    printf("\n\t|   Sala 1 �s 11:10    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==17){
                    printf("----------------------------------------------");
                    printf("\n\t|   Sala 7 �s 13:00    |\n");
                    printf("\n\t|         DOM          |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==18){
                    printf("----------------------------------------------");
                    printf("\n\t|         DOM          |\n");
                    printf("\n\t|   Sala 8 �s 15:50    |\n");
                    }else if(filmes[i11].salas[i2].cadeiras[i].identificacaoSala==19){
                    printf("----------------------------------------------");
                    printf("\n\t|         DOM          |\n");
                    printf("\n\t|   Sala 2 �s 19:00    |\n");
                    }
                    printf("----------------------------------------------\n");
                    printf("\t| A Cadeira escolhida foi:|\n\t\t   |%d|\n", filmes[i11].salas[i2].cadeiras[i].numCadeiras);
                    printf("----------------------------------------------\n");
                    printf("\t|   Pre�o do Ingresso     |\n");
                    printf("\t\t| R$ %d |\n",filmes[i11].salas[i2].cadeiras[i].valor);



            }
}
            }
            }
            //aqui o cliente ir� digitar a numera��o do ingresso que deseja excluir
				printf("\n");
				printf("Digite qual ingresso deseja excluir:\n");
				exclusao = LimitarNumeroCadeiras();
            for(i9=0;i9<8;i9++){
            for(i2=0;i2<20;i2++){
            for(i=0;i<30;i++){
				if ((filmes[i9].salas[i2].cadeiras[i].numIngresso==exclusao) && (filmes[i9].salas[i2].cadeiras[i].codigo==verificacao)){

      			filmes[i9].salas[i2].cadeiras[i].codigo=0;
      			filmes[i9].salas[i2].cadeiras[i].numIngresso=0;
      			cliente[i3].totalPedido= cliente[i3].totalPedido-filmes[i9].salas[i2].cadeiras[i].valor;
      			filmes[i9].salas[i2].cadeiras[i].valor=0;
                printf("\nIngresso %i foi cancelado.\n", exclusao);
                option=0;
                while(option!=1 && option!=2){
if(cliente[i3].totalPedido>0){
//aqui o cliente pode escolher continuar excluindo ingressos ou sair
   			printf("Deseja excluir outro ingresso?\n");
   			printf("\n|1 - Sim|\n");
   			printf("|2 - N�o|\n");
   			option = LimitarNumero();
   			i9=9;
   			i2=11;
   			i=31;
}else{
    //caso o cliente tenha excluido todos os seus ingressos essa mensagem ser� exibida
    printf("Voc� n�o possui mais ingressos\n");
option=2;
}
   			}

				}


				}
            }
 }

				num=1;
				//essa � a parte onde o n�mero dos ingressos s�o organizados novamente
                for(i9=0;i9<8;i9++){
                for(i2=0;i2<20;i2++){
                for(i=0;i<30;i++){
                if (filmes[i9].salas[i2].cadeiras[i].codigo==verificacao){

                	filmes[i9].salas[i2].cadeiras[i].numIngresso=num++;

                }
			}
		}
	}




                    }
	}else{
	    //caso o cliente n�o tenha comprado um ingresso ainda essa mensagem ser� exibida
		printf("\nNenhum dado computado.\n");
	}
}

void configurarConta(){
    do{
    //nessa parte o cliente pode alterar diversos dados de sua conta
            printf("\n------------------------------------\n");
    		printf("       Configura��es da Conta      -\n");
    		printf("====================================\n");
        	printf(" 1 - Alterar E-Mail                -\n");
			printf(" 2 - Alterar Senha                 -\n");
			printf(" 3 - Alterar Pergunta de Seguran�a -\n");
			printf(" 4 - Sair                          -\n");
			printf("------------------------------------\n");
			printf("Escolha uma Op��o ->\n");
			opcaoRedefinir = LimitarNumero();
			printf("\n");

			if(opcaoRedefinir==1){
                    /*caso o cliente escolha a primeira op��o
                    ele digitar� seu novo email e ser� feita a checagem
                    se j� existe no sistema um email igual.
                    */
				printf("\nDigite o seu novo e-mail:\n");
				gets(verificacaoEmail);
				converterMaiusculo(verificacaoEmail);

				verEmail = criarEmail();

//caso n�o seja encontrado nenhum email igual ele passou no teste e o email foi alterado
				if(verEmail!=0){
					printf("\nE-mail alterado com sucesso.\n");
					strcpy(cliente[i3].email,verificacaoEmail);
					//se ele reprovou no teste est� mensagem ser� exibida
				} else {
					printf("\nEste E-mail j� est� cadastrado em nosso sistema.\n");
				}
			} else if(opcaoRedefinir==2){
				novaSenha(cliente[i3].senha);
			} else if(opcaoRedefinir==3){
				alterarResposta();
			}else if(opcaoRedefinir==4){
			printf("Voltando\n");
			}else{
			printf("Op��o inv�lida!\n");
			}
}while(opcaoRedefinir!=4);
}
void verificarArquivoClientes(){


arq= fopen("DadosClientes.txt","r");
if (arq==NULL){
    printf("Nenhum arquivo foi encontrado com dados dos clientes!\n");
    for(i=0;i<30;i++){
    cliente[i].totalPedido=0;
    }
}else{
printf("O arquivo dos clientes foi aberto.\n");



     i=0;
     //caso chegue o final do arquivo a fun��o feof ir� verificar e sair� do loop
   while(!feof(arq)){
   fscanf(arq,"%d\n",&cliente[i].verificarTamanhoNome);
    fgets(cliente[i].nomeCliente,cliente[i].verificarTamanhoNome, arq);
     fscanf(arq,"%s\n",&cliente[i].email);
      fscanf(arq,"%s\n",&cliente[i].senha);
       fscanf(arq,"%d\n",&cliente[i].cod);
        fscanf(arq,"%d\n",&cliente[i].totalPedido);
         fscanf(arq,"%d\n",&cliente[i].perguntaEscolhida);
          fscanf(arq,"%d\n",&cliente[i].verificarTamanho);
           fgets(cliente[i].respostaPergunta,cliente[i].verificarTamanho, arq);
i++;
     }

      printf("Dados dos clientes computados com sucesso!\n");
}
 fclose(arq);
}

void verificarDadosFilmes(){
    int i10;
arq = fopen("DadosFilmes.txt","r");
if (arq==NULL){
        //caso nenhum arquivo seja encontrado todos os dados dos filmes, sess�es e cadeiras ser�o resetados
    printf("Nenhum arquivo foi encontrado com dados dos filmes!\n");
    for(i3=0;i3<8;i3++){
    for(i2=0;i2<20;i2++){
    for(i=0;i<30;i++){


	filmes[i3].salas[i2].cadeiras[i].codigo=0;
	filmes[i3].salas[i2].cadeiras[i].numIngresso=0;
 	filmes[i3].salas[i2].cadeiras[i].valor=0;
	filmes[i3].salas[i2].cadeiras[i].identificacaoSala=-1;
    filmes[i3].salas[i2].cadeiras[i].identificacaoFilme=-1;

}
}
}
}else{
printf("O arquivo dos filmes foi aberto.\n");

 for(i3=0;i3<8;i3++){
    for(i2=0;i2<20;i2++){
    for(i=0;i<30;i++){
     fscanf(arq,"%d ",&filmes[i3].salas[i2].cadeiras[i].numCadeiras);
	 fscanf(arq,"%d ",&filmes[i3].salas[i2].cadeiras[i].codigo);
	 fscanf(arq,"%d ",&filmes[i3].salas[i2].cadeiras[i].numIngresso);
 	 fscanf(arq,"%d ",&filmes[i3].salas[i2].cadeiras[i].valor);
	 fscanf(arq,"%d ",&filmes[i3].salas[i2].cadeiras[i].identificacaoSala);
    fscanf(arq,"%d ", &filmes[i3].salas[i2].cadeiras[i].identificacaoFilme);
         }
    }
        }
        fscanf(arq,"\n%d\n",&i10);
        printf("Dados dos filmes computados com sucesso!\n");
      i7=i10;
}
 fclose(arq);

}

void gravarDadosClientes(){
if((strlen(cliente[0].nomeCliente)== 0)){
    printf("Nenhum dado foi computado porque nenhum cliente foi cadastrado\n");
}else{
arq= fopen("DadosClientes.txt","w");

     for(i=0;i<30;i++){
         if (strlen(cliente[i].nomeCliente)!= 0){
  cliente[i].verificarTamanhoNome = strlen(cliente[i].nomeCliente)+1;
   fprintf(arq,"%d\n",cliente[i].verificarTamanhoNome);
    fprintf(arq,"%s\n",cliente[i].nomeCliente);
     fprintf(arq,"%s\n",cliente[i].email);
      fprintf(arq,"%s\n",cliente[i].senha);
       fprintf(arq,"%d\n",cliente[i].cod);
        fprintf(arq,"%d\n",cliente[i].totalPedido);
         fprintf(arq,"%d\n",cliente[i].perguntaEscolhida);
          cliente[i].verificarTamanho = strlen(cliente[i].respostaPergunta)+1;
           fprintf(arq,"%d\n",cliente[i].verificarTamanho);
            fprintf(arq,"%s\n",cliente[i].respostaPergunta);

         }

     }
     printf("Dados dos clientes salvos com sucesso\n");
     fclose(arq);
}
}

void gravarDadosFilmes(){
arq = fopen("DadosFilmes.txt","w");

  for(i3=0;i3<8;i3++){
    for(i2=0;i2<20;i2++){
    for(i=0;i<30;i++){
     fprintf(arq,"%d ",filmes[i3].salas[i2].cadeiras[i].numCadeiras);
	 fprintf(arq,"%d ",filmes[i3].salas[i2].cadeiras[i].codigo);
	 fprintf(arq,"%d ",filmes[i3].salas[i2].cadeiras[i].numIngresso);
 	 fprintf(arq,"%d ",filmes[i3].salas[i2].cadeiras[i].valor);
	 fprintf(arq,"%d ",filmes[i3].salas[i2].cadeiras[i].identificacaoSala);
    fprintf(arq,"%d ", filmes[i3].salas[i2].cadeiras[i].identificacaoFilme);
         }
    }
        }
        fprintf(arq,"%d\n",i7);
        printf("Dados dos filmes salvos com sucesso\n");

}

int main(){
	setlocale(LC_ALL,"Portuguese");


	for(i3=0;i3<8;i3++){
    for(i2=0;i2<20;i2++){
    for(i=0;i<30;i++){
    /*essa parte do c�digo vai dar numeros as cadeiras
    exemplo: cadeira 1, cadeira 2, etc...*/
 	filmes[i3].salas[i2].cadeiras[i].numCadeiras=i+1;

}
}
}

verificarArquivoClientes();
verificarDadosFilmes();

do {
 i3=i7;
 verificacao=0;

	 printf("\n-----------------------------------------------\n");
	 printf("          Bem-vindo(a) ao CinemaFlix          -\n");
	 printf("===============================================\n");
	 printf("      Voc� j� tem uma conta de acesso?        -\n");
	 printf("-----------------------------------------------\n");
	 printf(" 1 - Sim, quero acessar minha conta.          -\n");
	 printf(" 2 - N�o, quero criar uma conta.              -\n");
	 printf(" 3 - Encerrar                                 -\n");
	 printf("-----------------------------------------------\n");
	 printf("Escolha uma Op��o ->\n");
 	 opcao = LimitarNumero();
	 printf("\n");
	 system("cls");

	 switch(opcao){
	     case 3:
	 	printf("\nPrograma encerrado.\n");
	 	system("cls");
	 	break;

         case 1:
acessarConta();
system("cls");

             break;

         case 2:
    criarConta();
    system("cls");
            break;
         default:
            printf("\nOp��o Inv�lida\n");
	 }


    if((opcaoMenuInicial!=1) && (opcao==2)){
           verificacao=i8;
      }
		while(opcaoMenuInicial!=-1 && opcaoMenuInicial!=5){
                printf("\n-----------------------------------------------\n");
                printf(" Ol� %s!                                       \n",cliente[verificarNome].nomeCliente);
		        printf(" Bem-vindo(a) ao menu do cliente CinemaFlix.  -\n");
                printf("===============================================\n");
		        printf(" 1 - Comprar Ingresso                         -\n");
		        printf(" 2 - Visualizar Pedido                        -\n");
		        printf(" 3 - Cancelar Pedido                          -\n");
		        printf(" 4 - Configura��es da Conta                   -\n");
		        printf(" 5 - Sair                                     -\n");
		        printf("-----------------------------------------------\n");
		        printf("Escolha uma Op��o ->\n");
		        opcaoMenuInicial = LimitarNumero();
				printf("\n");
				system("cls");

		       // essa � a parte onde o n�mero dos ingressos s�o organizados novamente
                for(i9=0;i9<3;i9++){
                for(i2=0;i2<3;i2++){
                for(i=0;i<10;i++){
                if (filmes[i9].salas[i2].cadeiras[i].codigo==verificacao){

                	filmes[i9].salas[i2].cadeiras[i].numIngresso=num++;

                }
			}
		}
	}
switch (opcaoMenuInicial){
case 1:
  escolherCadeira();
  printf("\nPressione Enter para sair desta tela\n");
  LimitarCaracteresTela();
  system("cls");
    break;

    case 2:
         visualizarPedido();
         printf("\nPressione Enter para sair desta tela\n");
        LimitarCaracteresTela();
         system("cls");
        break;

    case 3:
       cancelarPedidos();
       printf("\nPressione Enter para sair desta tela\n");
       LimitarCaracteresTela();
       system("cls");
        break;

    case 4:
    		configurarConta();
    		printf("\nPressione Enter para sair desta tela\n");
           LimitarCaracteresTela();
    		system("cls");
        break;

    case 5:
        printf("\nDesconectado do menu de cliente.\n");
        break;

    default:
        printf("\nOp��o Inv�lida\n");
		}

		}
}while(opcao!=3);
gravarDadosClientes();
gravarDadosFilmes();

printf("\nPressione ENTER para finalizar o programa...\n");
LimitarCaracteresTela();
    return 0;
}

