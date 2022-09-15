
void converterMaiusculo(char caractere1[]){
//os caracteres que entrarem aqui ser�o transformados em maiusculo
	strupr(caractere1);
}

int LimitarNumero(){
	char numeroDigitado[2];//armazenar� o que foi digitado
    char c; // armazenar� cada caractere digitado
    int i=0;
	int numero=0;
	do
	{
       c=getch();//pegar� o caractere digitado pelo usu�rio
	   if (isdigit(c)!=0 && i<1){ // a fun��o isdigit ir� verificar se � um n�mero
          numeroDigitado[i] = c;//se for armazenar� o n�mero na vari�vel
          i++;
          printf ("%c", c);//mostra o n�mero digitado pelo us�ario

	   } else if (c==8&&i){// se o cliente apertar o backspace e houver um n�mero digitado
          numeroDigitado[i]='\0';
          i--;
          printf("\b \b");//ele ser� apagado da tela pelo \b \b
       }
    }while(c!=13);//sa�ra do loop quando o usu�rio digitar enter

	numeroDigitado[i]='\0';
    numero = atoi(numeroDigitado);// a fun��o atoi transforma um numero caractere em um inteiro

	return numero;// e � retornado o n�mero digitado
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
    char c;//armazena cada caractere digitado pelo usu�rio
    int i=0;//vari�vel para controlar o �ndice do vetor de caracteres

	do
	{
       c=getch();//captura o caractere digitado pelo usu�rio
	   if (isalpha(c)!=0 || c==32)//se for uma letra
	   {
          caractereDigitado[i] = c;//armazena no vetor de caracteres
          i++;//incrementa o �ndice do vetor de caracteres
          printf ("%c", c);//exibe o caractere digitado
       }
       else if(c==8&&i)//se for pressionada a tecla BACKSPACE e houver caracteres j� digitados
       {
		  caractereDigitado[i]='\0';//o �ndice atual do vetor de caracteres recebe a termina��o da string
          i--;//o �ndice do vetor de caracteres � decrementado
          printf("\b \b");//o caractere digitado � apagado da tela
       }
    }while(c!=13);//o loop vai ser executado at� que a tecla pressionada seja o ENTER (c�digo 13 na tabela ASCII)

    caractereDigitado[i]='\0';//o �ndice atual do vetor de caracteres recebe a termina��o da string
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
if(caractereDigitado[i-1]==32){//se a palavra escrita tiver terminado com um espa�o o programa retira o espa�o
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
    //s� permite o usu�rio digitar enter

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
		// Aqui o cliente digitar� a senha para sua conta
 		printf("\nDigite sua senha:\n");
 	 	gets(senha1);

	 	printf("\nDigite sua senha novamente:\n");
	 	gets(senha2);

		// Aqui ser� verificado se o cliente digitou as duas senhas iguais
		verificador=strcmp(senha1, senha2);

		if(verificador!=0){
			printf("\nAS SENHAS N�O CONFEREM! DIGITE NOVAMENTE\n");

		}else{
			// Caso a conta seja criado
			printf("\nConta criada com sucesso!\n");
			strcpy(senha,senha2);
		}

	// Aqui est� finalizando o la�o de repeti��o da senha
	}while(verificador!=0);
}

void novaSenha(char senha[]){
	int verificador = 1;
	char senha1[100];
	char senha2[100];

	do{
		// Aqui o cliente digitar� sua nova senha
 		printf("\nDigite sua nova senha:\n");
 	 	gets(senha1);

	 	printf("\nDigite sua nova senha novamente:\n");
	 	gets(senha2);

		// Aqui ser� verificado se o cliente digitou as duas senhas iguais
		verificador=strcmp(senha1, senha2);

		if(verificador!=0){
			printf("\nAS SENHAS N�O CONFEREM! DIGITE NOVAMENTE\n");

		}else{
			strcpy(senha,senha2);
			printf("\nSenha alterada com sucesso!\n");
		}

	// Aqui est� finalizando o la�o de repeti��o da senha
	}while(verificador!=0);
}


