//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Constante
#define TAM 200

//Variaveis globais
int indice = 0;

//Struct que armazena os campos do cadastro
typedef struct cadastro {
		int codigo;
		char titulo [30];
		char desc [40];
		int ano;
		int status;
		char nomeGerente [60];
		char area[30];
		float orcamento;
		char dataF [30];
}cadastro;

//Prototipos das funcaoes
int menuProjetos (int *opc);
void cadProjetos(cadastro project[TAM]);
int menuExibir (int *opc2);
void exibirTodos(cadastro exibir[TAM]);
void statusAfazer(cadastro status[TAM]);
void statusFazendo(cadastro status[TAM]);
void statusConcluido(cadastro status[TAM]);
void buscaNome(cadastro nome[TAM]);
void ordenaAno(cadastro trocA[TAM]);

//Funcao Main
int main (){
	setlocale(LC_ALL, "Portuguese");
	cadastro projetos [TAM];	
	int opcao, opcao2;
	do{
		system("cls");
		switch (menuProjetos(&opcao)){
			case 1:
				system("cls");
				cadProjetos(projetos);
				break;
			case 2:
				do{
					system("cls");	
					switch(menuExibir(&opcao2)){
						case 1:					
							system("cls");
							exibirTodos(projetos);
							system("pause");
							break;
						case 2:
							system("cls");
							statusAfazer(projetos);
							system("pause");
							break;
						case 3:
							system("cls");
						    statusFazendo(projetos);
							system("pause");
							break;
						case 4:
							system("cls");
							statusConcluido(projetos);
							system("pause");
							break;
						case 5:
							system("cls");
							buscaNome(projetos);
							system("pause");
							break;
						case 6:
							system("cls");
							ordenaAno(projetos);
							break;
						case 0:
							opcao2 = 0;
							break;
						default:
							printf("Op��o inv�lida! Tente novamente!\n\n");
							system("pause");
							break;
					}
				}while(opcao2 != 0);
				break;
			case 0:
				printf("Programa finalizado, At� logo!");
				opcao = 0;
				break;
			default:
				printf("Op��o inv�lida! Tente novamente!\n\n");
				system("pause");
				break;
		}
	}while(opcao != 0);
	return 0;
}

//Funcao menu principal 
int menuProjetos (int *opc){
system("color 0B");
printf("\
+---------------------------------------+\n\
|-------------MENU PROJETOS-------------|\n\
+---------------------------------------+\n\
%c 1] Para cadastrar novo projeto.\n\
%c 2] Op��es para exibir projetos cadastrados.\n\
%c 0] Para sair.\n\
%c: ", 16, 16, 16, 16);
scanf ("%d", opc);
fflush(stdin);
return *opc;
}

//Funcao de cadastro
void cadProjetos(cadastro project[TAM]){
system("color 03");
printf("\
+------------------------------------------------------------+\n\
|----------INFORME OS DADOS DE CADASTRO DO PROJETO-----------|\n\
+------------------------------------------------------------+\n");
printf("\t\t%cCadastre at� 200 projetos%c\n\n", 16, 17);
	char opcao;
	do{
		if(indice == TAM){
			printf("Limite de cadastro atingido!\n");
			system("pause");
			break;	
		}
		printf("C�digo do cadastro: *%d\n", indice+1);
		project[indice].codigo = indice+1;
		fflush(stdin);
	 	printf("Informe o nome do projeto: ");
		fgets(project[indice].titulo, 30, stdin);
		fflush(stdin);
		printf("Descri��o breve para o projeto: ");
		fgets(project[indice].desc, 40, stdin);
		fflush(stdin);
		printf("Informe o nome do gerente de projetos respons�vel: ");
		fgets(project[indice].nomeGerente, 60, stdin);
		fflush(stdin);
		printf("Informe a �rea de atua��o do projeto: ");
		fgets(project[indice].area, 30, stdin);
		fflush(stdin);
		printf("Informe o ano do projeto: ");
		scanf("%d", &project[indice].ano);
		fflush(stdin);
		printf("Informe a data prevista para o final do projeto (DD/MM/AAAA): ");
		fgets(project[indice].dataF, 30, stdin);
		project[indice].dataF[strcspn(project[indice].dataF, "\n")] = 0; //percorre toda string at� encontrar "\n", atribui o valor "0"(NULL), para n�o pular linha automaticamnete usando fgets.  
		fflush(stdin);
		printf("Informe o or�amento do projeto: ");
		scanf("%f", &project[indice].orcamento);
		fflush(stdin);
		do{
			printf("Escolha o Status do projeto [1]A fazer  [2]Fazendo   [3]Conclu�do: ");
			scanf("%d", &project[indice].status);
			fflush(stdin);
			if(project[indice].status != 1 && project[indice].status != 2 && project[indice].status != 3){
				printf("Op��o inv�lida!\n");
			}
		}while(project[indice].status != 1 && project[indice].status != 2 && project[indice].status != 3);
		printf("*Projeto cadastrado com sucesso!*\n");
		indice++;
		printf("\n");
		if(indice < TAM){
			do{
				printf("Cadastrar novo projeto? [S]/[N]: ");
				scanf("%c", &opcao);
				fflush(stdin);
			}while(opcao != 's' && opcao != 'S' && opcao != 'n' && opcao != 'N');
		}else{
			printf("\n\n----------------------------------\n");
			printf("Limite de %d cadastros atingido!\n", indice);
			printf("----------------------------------\n\n");
			system("pause");
		}
		printf("\n");
	}while(opcao != 'n' && opcao != 'N' && indice < TAM);
}

//Funcao Menu Exibir
int menuExibir (int *opc2){
system("color 0B");
printf("\
+--------------------------------------------+\n\
|-------------MENU EXIBIR PROJETOS-----------|\n\
+--------------------------------------------+\n\
%c 1] Para exibir todos os projetos cadastrados.\n\
%c 2] Projetos com Status: A fazer.\n\
%c 3] Projetos com Status: Fazendo.\n\
%c 4] Projetos com Status: Conclu�do.\n\
%c 5] Buscar projetos pelo nome do gerente respons�vel.\n\
%c 6] Ordenar projetos por ano crescente.\n\
%c 0] Para voltar ao Menu Principal.\n\
%c: ", 16, 16, 16, 16, 16, 16, 16, 16);
scanf ("%d", opc2);
fflush(stdin);
return *opc2;
}

//Funcao Exibir
void exibirTodos(cadastro exibir[TAM]){
	system("color 0A");
	printf("|---------TODOS OS PROJETOS CADASTRADOS---------|\n");
	int i=0;
	if(indice >= 1){
		while(i < indice){
			printf("C�digo: *%d\n", exibir[i].codigo);
			printf("T�tulo: %s", exibir[i].titulo);
			printf("Descri��o breve: %s", exibir[i].desc);
			printf("Gerente respons�vel: %s", exibir[i].nomeGerente);
			printf("�rea de atua��o: %s", exibir[i].area);
			printf("Ano: %d\n", exibir[i].ano);
			printf("Data final prevista: %s\n", exibir[i].dataF);
			printf("Or�amento: %.2f\n", exibir[i].orcamento);
			if(exibir[i].status == 1){
				printf("Status: A fazer\n");
			}else{
				if(exibir[i].status == 2){
					printf("Status: Fazendo\n");	
				}else{
					if(exibir[i].status == 3){
						printf("Status: Coclu�do\n");
					}
				}
			}
			i++;
	   		printf("\n");
		}
	}else{
		printf("\n**Nenhum projeto cadastrado!**\n\n");
	}
 
}

//Fun��o listar cadastros por status a fazer
void statusAfazer(cadastro status[TAM]){
	system("color 04");
	printf("|-----------Projetos com Status A Fazer----------|\n");
	int i=0;
	if(indice>=1){
		while(i < indice){
			if(status[i].status == 1){
				printf("C�digo: *%d\n", status[i].codigo);
				printf("T�tulo: %s", status[i].titulo);
				printf("Descri��o breve: %s", status[i].desc);
				printf("Gerente respons�vel: %s", status[i].nomeGerente);
				printf("�rea de atua��o: %s", status[i].area);
				printf("Ano: %d\n", status[i].ano);
				printf("Data final prevista: %s\n", status[i].dataF);
				printf("Or�amento: %.2f\n", status[i].orcamento);
				printf("Status: A fazer\n");
				printf("\n");
			}
			i++;
		}
	}else{
		printf("\n**Nenhum projeto cadastrado com Status: A fazer!**\n\n");
	}
	
}

//Fun��o listar cadastros por status fazendo
void statusFazendo(cadastro status[TAM]){
	system("color 06");
	printf("|-----------Projetos com Status Fazendo----------|\n");
	int i=0;
	if(indice>=1){
		while(i < indice){
			if(status[i].status == 2){
				printf("C�digo: *%d\n", status[i].codigo);
				printf("T�tulo: %s", status[i].titulo);
				printf("Descri��o breve: %s", status[i].desc);
				printf("Gerente respons�vel: %s", status[i].nomeGerente);
				printf("�rea de atua��o: %s", status[i].area);
				printf("Ano: %d\n", status[i].ano);
				printf("Data final prevista: %s\n", status[i].dataF);
				printf("Or�amento: %.2f\n", status[i].orcamento);
				printf("Status: Fazendo\n");
				printf("\n");
			}
			i++;
		}
	}else{
		printf("\n**Nenhum projeto cadastrado com Status: Fazendo!**\n\n");
	}
	
}

//Fun��o listar cadastros por status concluido
void statusConcluido(cadastro status[TAM]){
	system("color 02");
	printf("|-----------Projetos com Status Conclu�do----------|\n");
	int i=0;
	if(indice>=1){
		while(i < indice){
			if(status[i].status == 3){
				printf("C�digo: *%d\n", status[i].codigo);
				printf("T�tulo: %s", status[i].titulo);
				printf("Descri��o breve: %s", status[i].desc);
				printf("Gerente respons�vel: %s", status[i].nomeGerente);
				printf("�rea de atua��o: %s", status[i].area);
				printf("Ano: %d\n", status[i].ano);
				printf("Data final prevista: %s\n", status[i].dataF);
				printf("Or�amento: %.2f\n", status[i].orcamento);
				printf("Status: Conclu�do\n");
				printf("\n");
			}
			i++;
		}
	}else{
		printf("\n**Nenhum projeto cadastrado com Status: Conclu�do!**\n\n");
	}
	
}

//Fun��o listar cadastros por nome do gerente responsavel
void buscaNome(cadastro busca[TAM]){
	char nome[60];
	int i, acha;
	system("color 0F");
	printf("|-----------Projetos pelo nome do gerente respons�vel----------|\n");
	fflush(stdin);
	printf("\nInforme o nome do gerente respons�vel pelo projeto(id�ntico ao cadastrado): ");
	fgets(nome, 60, stdin);
	acha=0;
	i=0;
	while(i < indice){
		if(strcmp(busca[i].nomeGerente, nome)==0){
			printf("\n");	
			printf("Gerente respons�vel: %s", busca[i].nomeGerente);
			printf("C�digo: *%d\n", busca[i].codigo);
			printf("T�tulo: %s", busca[i].titulo);
			printf("Descri��o breve: %s", busca[i].desc);
			printf("�rea de atua��o: %s", busca[i].area);
			printf("Ano: %d\n", busca[i].ano);
			printf("Data final prevista: %s\n", busca[i].dataF);
			printf("Or�amento: %.2f\n", busca[i].orcamento);
			if(busca[i].status == 1){
				printf("Status: A fazer\n");
			}else{
				if(busca[i].status == 2){
					printf("Status: Fazendo\n");	
				}else{
					if(busca[i].status == 3){
						printf("Status: Coclu�do\n");
					}
				}
			}
			acha = i+1;
			printf("\n");
		}
		i++;
	}
	if(acha == 0){
		printf("\nNenhum projeto encontrado com o nome do gerente *%s\n", nome);
	}
}

//Fun��o ordenar cadastro por ano crescente
void ordenaAno(cadastro trocA[TAM]){
	int i, j;
	cadastro troca;
	for(i=0; i<indice-1; i++){
		for(j=i+1; j<indice; j++){
			if(trocA[i].ano > trocA[j].ano){
				troca = trocA[i];
				trocA[i] = trocA[j];
				trocA[j] = troca;
			}
		}
	}
	system("color 0F");
	printf("|-----------Projetos ordenados por ano crescente----------|\n");
	if(trocA[i].ano == 0){
		printf("\nNenhum projeto cadastrado!\n\n");
		system("pause");
	}else{
		for(i=0; i<indice; i++){
			printf("Ano: %d\n", trocA[i].ano);
			printf("C�digo: *%d\n", trocA[i].codigo);
			printf("T�tulo: %s", trocA[i].titulo);
			printf("Descri��o breve: %s", trocA[i].desc);
			printf("�rea de atua��o: %s", trocA[i].area);
			printf("Gerente respons�vel: %s", trocA[i].nomeGerente);
			printf("Data final prevista: %s\n", trocA[i].dataF);
			printf("Or�amento: %.2f\n", trocA[i].orcamento);
			if(trocA[i].status == 1){
				printf("Status: A fazer\n");
			}else{
				if(trocA[i].status == 2){
					printf("Status: Fazendo\n");	
				}else{
					if(trocA[i].status == 3){
						printf("Status: Coclu�do\n");
					}
				}
			}
			printf("\n");
		}
		system("pause");
	}
	for(i=0; i<indice-1; i++){
		for(j=i+1; j<indice; j++){
			if(trocA[i].codigo > trocA[j].codigo){
				troca = trocA[i];
				trocA[i] = trocA[j];
				trocA[j] = troca;
			}
		}
	}
	
}
