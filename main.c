#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX 100

typedef struct{
     char nome[MAX];
     char isbn[MAX];
     float preco;
     int score;
     char editora[MAX];
}Livro, *pLivro;

pLivro livro_aloc(int qtde){
    pLivro livros =(pLivro)malloc(qtde * sizeof(Livro));
    return livros;
 }
void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void livro_ler(pLivro livros, int qtde){
    for(int i=1;i<=qtde;i++){
        scanf("%[^\n]s ", livros[i].nome);
        limpar_buffer();
        scanf("%[^\n]s ", livros[i].isbn);
        limpar_buffer();
        scanf("%f ", &livros[i].preco);
        scanf("%d ", &livros[i].score);
        scanf("%[^\n]s ", livros[i].editora);
        limpar_buffer();  
    }
}
void livro_exibe(pLivro livros, int qtde){
     for(int i=1;i<=qtde;i++){
        printf("Livro %d:\n",i);
        printf("Nome: %s\n",livros[i].nome);
        printf("ISBN: %s\n",livros[i].isbn);
        printf("Preço: R$ %.2f\n",livros[i].preco);
        printf("Score: %d\n",livros[i].score);
        printf("Editora: %s\n",livros[i].editora);
        printf("\n");

     }
}
void livro_desaloca(pLivro livros){
     free(livros);
}

int main(){
  setlocale(LC_ALL,"Portuguese");

    int qtde;
    scanf("%d",&qtde);

    if(qtde == 0){
       printf("Sem livros");
    }else{   
      pLivros livros = livro_aloc(qtde);
         
      livro_ler(livros,qtde);
         
      livro_exibe(livros,qtde);
         
      livro_desaloca(livros);
    }    

    return 0;
}
