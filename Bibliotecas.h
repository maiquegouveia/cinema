
void converterMaiusculo(char caractere1[]){
//os caracteres que entrarem aqui serão transformados em maiusculo
	strupr(caractere1);
}

int LimitarNumero(){
	char numeroDigitado[2];//armazenará o que foi digitado
    char c; // armazenará cada caractere digitado
    int i=0;
	int numero=0;
	do
	{
       c=getch();//pegará o caractere digitado pelo usuário
	   if (isdigit(c)!=0 && i<1){ // a função isdigit irá verificar se é um número
          numeroDigitado[i] = c;//se for armazenará o número na variável
          i++;
          printf ("%c", c);//mostra o número digitado pelo usúario

	   } else if (c==8&&i){// se o cliente apertar o backspace e houver um número digitado
          numeroDigitado[i]='\0';
          i--;
          printf("\b \b");//ele será apagado da tela pelo \b \b
       }
    }while(c!=13);//saíra do loop quando o usuário digitar enter

	numeroDigitado[i]='\0';
    numero = atoi(numeroDigitado);// a função atoi transforma um numero caractere em um inteiro

	return numero;// e é retornado o número digitado
}

int LimitarNumeroCadeiras(){
	char numeroDigitado[2];
    char c;
    int i=0;
	int numero=0;
	do
	{
       c=getch();
	   if (isdigit(c)!=0 && i<2){
          numeroDigitado[i] = c;
          i++;
          printf ("%c", c);

	   } else if (c==8&&i){
          numeroDigitado[i]='\0';
          i--;
          printf("\b \b");
       }
    }while(c!=13);

	numeroDigitado[i]='\0';
    numero = atoi(numeroDigitado);

	return numero;
}

void LimitarCaracteresNome(char nomeCliente[]){
	char caractereDigitado[50];
    char c;//armazena cada caractere digitado pelo usuário
    int i=0;//variável para controlar o índice do vetor de caracteres

	do
	{
       c=getch();//captura o caractere digitado pelo usuário
	   if (isalpha(c)!=0 || c==32)//se for uma letra
	   {
          caractereDigitado[i] = c;//armazena no vetor de caracteres
          i++;//incrementa o índice do vetor de caracteres
          printf ("%c", c);//exibe o caractere digitado
       }
       else if(c==8&&i)//se for pressionada a tecla BACKSPACE e houver caracteres já digitados
       {
		  caractereDigitado[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string
          i--;//o índice do vetor de caracteres é decrementado
          printf("\b \b");//o caractere digitado é apagado da tela
       }
    }while(c!=13);//o loop vai ser executado até que a tecla pressionada seja o ENTER (código 13 na tabela ASCII)

    caractereDigitado[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string
	strcpy(nomeCliente,caractereDigitado);
}

void LimitarCaracteresPergunta(char pergunta[]){

	char caractereDigitado[50];
    char c;
    int i=0;

	do
	{
       c=getch();
	   if (isalpha(c)!=0 || c==32)
	   {
          caractereDigitado[i] = c;
          i++;
          printf ("%c", c);
       }
       else if(c==8&&i)
       {
		caractereDigitado[i]='\0';
          i--;
          printf("\b \b");
       }
    }while(c!=13);
if(caractereDigitado[i-1]==32){//se a palavra escrita tiver terminado com um espaço o programa retira o espaço
caractereDigitado[i-1]='\0';
}else{
   caractereDigitado[i]='\0';
}
   strcpy(pergunta,caractereDigitado);
}

void LimitarCaracteresResposta(char verificarPergunta[]){

	char caractereDigitado[50];
    char c;
    int i=0;

	do
	{
       c=getch();
	   if (isalpha(c)!=0 || c==32)
	   {
         caractereDigitado[i] = c;
          i++;
          printf ("%c", c);
       }
       else if(c==8&&i)
       {
		caractereDigitado[i]='\0';
          i--;
          printf("\b \b");
       }
    }while(c!=13);

   if(caractereDigitado[i-1]==32){
caractereDigitado[i-1]='\0';
}else{
   caractereDigitado[i]='\0';
}
   strcpy(verificarPergunta,caractereDigitado);
}


void LimitarCaracteresTela(){
    //só permite o usuário digitar enter

	char caractereDigitado[1];
    char c;
    int i=0;

	do
	{
       c=getch();
	   if (isalpha(c)!=0 && c==13)
	   {
         caractereDigitado[i] = c;
          i++;
       }
    }while(c!=13);
}

void senha(char senha[]){
	int verificador = 1;
	char senha1[100];
	char senha2[100];

	do{
		// Aqui o cliente digitará a senha para sua conta
 		printf("\nDigite sua senha:\n");
 	 	gets(senha1);

	 	printf("\nDigite sua senha novamente:\n");
	 	gets(senha2);

		// Aqui será verificado se o cliente digitou as duas senhas iguais
		verificador=strcmp(senha1, senha2);

		if(verificador!=0){
			printf("\nAS SENHAS NÃO CONFEREM! DIGITE NOVAMENTE\n");

		}else{
			// Caso a conta seja criado
			printf("\nConta criada com sucesso!\n");
			strcpy(senha,senha2);
		}

	// Aqui está finalizando o laço de repetição da senha
	}while(verificador!=0);
}

void novaSenha(char senha[]){
	int verificador = 1;
	char senha1[100];
	char senha2[100];

	do{
		// Aqui o cliente digitará sua nova senha
 		printf("\nDigite sua nova senha:\n");
 	 	gets(senha1);

	 	printf("\nDigite sua nova senha novamente:\n");
	 	gets(senha2);

		// Aqui será verificado se o cliente digitou as duas senhas iguais
		verificador=strcmp(senha1, senha2);

		if(verificador!=0){
			printf("\nAS SENHAS NÃO CONFEREM! DIGITE NOVAMENTE\n");

		}else{
			strcpy(senha,senha2);
			printf("\nSenha alterada com sucesso!\n");
		}

	// Aqui está finalizando o laço de repetição da senha
	}while(verificador!=0);
}


