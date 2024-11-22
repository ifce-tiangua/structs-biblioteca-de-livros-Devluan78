#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
     char nome[100];
     char isbn[50];
     float preco;
     int score;
     char editora[100];
}Livro, *pLivro;

pLivro livro_aloc(int qtde){
    pLivro livros;
    livros = malloc(qtde * sizeof(Livro));
    return livros;
 }

void livro_ler(pLivro livros, int qtde){
    for(int i=1;i<=qtde;i++){
         getchar();
         fgets(livros[i].nome,100,stdin);
         fgets(livros[i].isbn,50,stdin);
         scanf("%f\n",&livros[i].preco);
         scanf("%d\n",&livros[i].score);
         getchar();
         fgets(livros[i].editora,100,stdin);
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
    pLivro livros;
    
    scanf("%d",&qtde);

    livros = livro_aloc(qtde);
    livro_ler(livros,qtde);
    livro_exibe(livros,qtde);
    livro_desaloca(livros);

    return 0;
}
