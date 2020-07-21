#include <stdio.h>

#include "utils.h"
#include "administrador.h"

// Procedimento principal do módulo de administração.
LISTA* menu_administrador(LISTA *lista)
{
	int escolha;

	do {
		
		limpar();	
		printf("--------------------------------------------------\n");
		printf(" Quem Quer Ser Milionário :: Administrador\n");
		
		printf("\n Menu:");
		
		printf("\n\t0 - Sair");
		printf("\n\t1 - Listar todas as perguntas");
		printf("\n\t2 - Acrescentar uma nova pergunta");
		printf("\n\t3 - Alterar uma pergunta");
		printf("\n\t4 - Remover uma pergunta");
		printf("\n\t5 - Gravar alterações");
		
		printf("\n\n Escolha: ");
		scanf("%d", &escolha);
		fflush(stdin);
		
		switch(escolha)
		{
			case 0: break;
			case 1: menu_listar_perguntas(lista); break;
			case 2: lista = menu_acrescentar_pergunta(lista); break;
			case 3: break;
			case 4: break;
			case 5: break;
		}
	
	} while(escolha != 0);
	
	return lista;
}

// Procedimento que permite listar todas as perguntas da lista.
void menu_listar_perguntas(LISTA *lista)
{
	
	limpar();	
	printf("--------------------------------------------------\n");
	printf(" Quem Quer Ser Milionário :: Administrador\n");
		
	printf("\n Lista de perguntas:");
	
	while(lista)
	{
		printf("\n[%d] %s", lista->pergunta.id, lista->pergunta.texto);
		
		lista = lista->proxima;
	}
	
	pausa();
	
	
}

// Procedimento que permite a inserção de uma nova pergunta.
LISTA* menu_acrescentar_pergunta(LISTA *lista)
{
	PERGUNTA p;
	char letra;
	int i, cat;
	
	limpar();	
	printf("--------------------------------------------------\n");
	printf(" Quem Quer Ser Milionário :: Administrador\n");
	
	printf("\n Nova pergunta:");
	
	do {
		
		printf("\n\n\tCategoria [");
		
		for(i = 0; i < CATEGORIAS; i++)
			printf("%d - %s%s", i+1, categorias[i], (i==CATEGORIAS-1)?"":", ");
		
		printf("]: ");
		scanf("%d", &cat);
		fflush(stdin);
		
	} while(cat < 0 || cat >= CATEGORIAS);
	
	p.id = -1;
	p.categoria = cat - 1;
	
	printf("\tTexto da pergunta: ");
	gets(p.texto);
	
	printf("\tAlínea A: ");
	gets(p.alineaA);
	printf("\tAlínea B: ");
	gets(p.alineaB);
	printf("\tAlínea C: ");
	gets(p.alineaC);
	printf("\tAlínea D: ");
	gets(p.alineaD);
	
	do {
		printf("\tQual a alínea correta (a, b, c ou d)? ");
		scanf("%c", &letra);
		fflush(stdin);
	} while (letra < 'a' || letra > 'd');
	
	p.correta = (int) (letra - 'a');
	
	return inserir_nova_pergunta(lista, p);
	
}
