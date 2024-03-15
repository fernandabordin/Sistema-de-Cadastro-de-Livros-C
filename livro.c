#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <time.h>

// Fernanda Bordin  RA: 23163885-2  ADSIS2B

struct Biblioteca{
    char nomeLivro[50];
    char nomeEditora[50];
    char nomeAutores[50];
    int codigo;
}

main() {
    setlocale(LC_ALL, "Portuguese");

    srand(time(NULL));

    struct Biblioteca Cadastro[5];
    char select;
    int count = 0;
    int quantCadastrada = 0;
    int numCodigo = 100;
    while(1) {
        printf("************* MENU *************\n");
        printf(" \n");
        printf("Digite: \n");
        printf(" \n");
        printf("1- Cadastrar um novo livro\n");
        printf("2- Mostrar livros cadastrados\n");
        printf("0- Encerrar o programa\n");
        printf("\n");
        printf("********************************\n");
        
        select = getch();
        system("cls");

        switch(select) {
            case '1':
                for(count = quantCadastrada; count < 5; count++) {
                   
                    printf("Digite o nome da obra: \n");
                    scanf("%s", Cadastro[count].nomeLivro);
                    printf("\n");
                    fflush(stdin);
                    if(strcmp(Cadastro[count].nomeLivro, "0") == 0) {
                        break;
                    }

                    printf("Digite o nome da editora: \n");
                    scanf("%s", Cadastro[count].nomeEditora);
                    printf("\n");
                    fflush(stdin);

                    if(strcmp(Cadastro[count].nomeEditora, "0") == 0) {
                        break;
                    }

                    printf("Digite o nome dos autores: \n");
                    scanf("%s", Cadastro[count].nomeAutores);
                    printf("\n");
                    printf("********************************\n");
                    printf("\n");
                    fflush(stdin);

                    if(strcmp(Cadastro[count].nomeAutores, "0") == 0) {
                        break;
                    }
                    quantCadastrada++;
                    Cadastro[count].codigo = (rand() % 899) + numCodigo;
                }
                if (count == 5) {
                    printf("Sistema de cadastro lotado. Não é possível armazenar mais informações! \n");
                }
                break;
            
            case '2':
                if (quantCadastrada == 0) {
                    printf("Lista vazia! \n \n \n");
                } else {
                    for (count = 0; count < quantCadastrada; count++) {
                        if (Cadastro[count].nomeLivro != NULL && Cadastro[count].nomeEditora != NULL && Cadastro[count].nomeAutores) {
                            printf("Codigo: %i \n", Cadastro[count].codigo);
                            printf("Livro: %s \n", Cadastro[count].nomeLivro);
                            printf("Autor: %s \n", Cadastro[count].nomeAutores);
                            printf("Editora: %s \n", Cadastro[count].nomeEditora);
                            printf("\n");
                        }
                    }
                }
                break;

            case '0':
                printf("Volte sempre!!! \n");    
                    exit(0);
                    break;    
            default:
                printf("Opção inválida! \n \n \n");
                break;
        }
    }
}
