#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct {
    int codigo;
    char nome[30];
    int quantidade;
}Item;
 
int main(){
    int capacidade_maxima = 2;
    int total_intens_guardados = 0;
    printf("ESTOQUE\n");
    Item *estoque = (Item *)malloc(capacidade_maxima * sizeof(Item));
    if (estoque == NULL){
        printf("Sem memoria disponivel");
        return 1;
    }
    printf(("Estoque inicial criado com sucesso!"));
    estoque[0].codigo = 102;
    strcpy(estoque[0].nome, "Teclado");
    estoque[0].quantidade = 5;
    total_intens_guardados++;
    estoque[1].codigo = 103;
    strcpy(estoque[1].nome, "Mouse");
    estoque[1].quantidade = 12;
    total_intens_guardados++;
    printf("\nTotal de itens guardados: %d produtos.\n", total_intens_guardados);
    if (total_intens_guardados ==  capacidade_maxima){
        printf("Expandindo estoque");
        capacidade_maxima = capacidade_maxima * 2;
        Item *estoque_maior = (Item *)realloc(estoque, capacidade_maxima * sizeof(Item));
        if (estoque_maior == NULL){
            printf("Erro ao expandir");
            return 1;
        }
        estoque = estoque_maior;
        printf("A capacidade maxima pulou para %d espaços\n", capacidade_maxima);
    }
    estoque[2].codigo = 104;
    strcpy(estoque[2].nome, "Monitor");
    estoque[2].quantidade = 50;
    total_intens_guardados++;
    printf(" Produtos\n");
    for (int i = 0; i < total_intens_guardados; i ++){
        printf("Vagas %d -> Codigo %d | Produto %s | Qtd %d\n", i, estoque[i].codigo, estoque[i].nome, estoque[i].quantidade);
    }
    free(estoque);

    return 0;
}
