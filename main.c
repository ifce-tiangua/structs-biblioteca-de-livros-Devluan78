#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX 100

struct Livro{
     char nome[MAX];
     char isbn[MAX];
     float preco;
     int score;
     char editora[MAX];
};
typedef struct Livro *pLivro;

pLivro livro_aloc(int qtde){
    pLivro livros =(pLivro)malloc(qtde * sizeof(struct Livro));
    return livros;
 }

void livro_ler(pLivro livros, int qtde)
{
    for (int i = 0; i < qtde; i++)
    {
         scanf(" %[^\n]", livros[i].nome);
         scanf(" %[^\n]", livros[i].isbn);
         scanf("%f", &livros[i].preco);
         scanf("%d", &livros[i].score);
         scanf(" %[^\n]", livros[i].editora);
    }
}
void livro_exibe(pLivro livros, int qtde){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    for(int i = 0; i < qtde; i++){
        printf("Livro %d:\n", i+1);
        printf("Nome: %s\n", livros[i].nome);
        printf("ISBN: %s\n", livros[i].isbn);
        printf("Preço: R$ %.2f\n", livros[i].preco);
        printf("Score: %d\n", livros[i].score);
        printf("Editora: %s\n", livros[i].editora);
        printf("\n"); 
    } 

}
void livro_desaloca(pLivro livros){
     free(livros);
}

int main(){

    int qtde;
    scanf("%d",&qtde);

    if(qtde == 0){
       printf("Sem livros\n");
       return 0;
    }else{   
      pLivro livros = livro_aloc(qtde);
         
      livro_ler(livros,qtde);
         
      livro_exibe(livros,qtde);
         
      livro_desaloca(livros);
    }    

    return 0;
}
