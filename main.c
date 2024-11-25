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
    for(int i=0;i<qtde;i++){
        fgets(livros[i].nome,MAX,stdin);
        limpar_buffer();
        fgets(livros[i].isbn,MAX,stdin);
        limpar_buffer();
        scanf("%f ", &livros[i].preco);
        scanf("%d ", &livros[i].score);
        fgets(livros[i].editora,MAX,stdin);
        limpar_buffer();  
    }
}
void livro_exibe(pLivro livros, int qtde){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    for(int i = 0; i < qtde; i++){
        printf("Livro %d:\n", i+1);
        printf("Nome: %s", livros[i].nome);
        printf("ISBN: %s", livros[i].isbn);
        printf("Preço: R$ %.2f\n", livros[i].preco);
        printf("Score: %d\n", livros[i].score);
        printf("Editora: %s\n", livros[i].editora);
        printf("\n"); 
    } 

}

}
void livro_desaloca(pLivro livros){
     free(livros);
}

int main(){

    int qtde;
    scanf("%d",&qtde);

    if(qtde == 0){
       printf("Sem livros");
    }else{   
      pLivro livros = livro_aloc(qtde);
         
      livro_ler(livros,qtde);
         
      livro_exibe(livros,qtde);
         
      livro_desaloca(livros);
    }    

    return 0;
}
