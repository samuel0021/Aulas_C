#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <strings.h>
#include <stdlib.h>

#define MAX_USERS 100
#define MAX_LENGTH 50

const char userADM[10] = "samuel0021", senhaADM[10] = "123456";

// variáveis de login
//char user[10] = "", senha[10] = "";

// usuários
char users[MAX_USERS][MAX_LENGTH];
char passwords[MAX_USERS][MAX_LENGTH];
int totalUsers = 0;

// variáveis de cadastro
//char cadUser[10] = "", cadSenha[10] = "", confirmaSenha[10] = "";

// variáveis de controle
int validacao, continuar;

int main(){
    setlocale(LC_ALL, "");

    int opcao;

    do{
        opcao = 1;
        printf("\n           - - - Menu - - -       \n");

        printf("\nEscolha a tela: \n");
        printf("\n(1) - Login \n(2) - Cadastro \n(3) - Usuários");
        printf("\n\nResposta: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                system("cls");
                login();
            break;

            case 2:
                system("cls");
                cadastro();
            break;

            case 3:
                system("cls");
                showUsers();
            break;

            default:
                printf("\nOpção inválida!");
                printf("\n\nPressione qualquer tecla para tentar novamente");
                getch();
                system("cls");
            break;
        }

    }while(opcao != 1 && opcao != 2);
}

int login(){
    char user[MAX_LENGTH], pass[MAX_LENGTH];
    validacao = 0;

    do{
        printf("\n      - - - Tela de Login - - -       \n");

        printf("\n - Digite seu usuário: ");
        scanf("%s", &user);
        printf("\n - Digite sua senha: ");
        scanf("%s", &pass);

        printf("\n\n%s %s", user, pass);

        for(int i = 0; i < totalUsers; i++){
            if(strcmp(users[i], user) == 0 && strcmp(passwords[i], pass) == 0){
                printf("\n\nCertin vai la\n");
                validacao = 1;

                vaiPraOnde();
                break;
            }
        }

            do{
                printf("\n\nUsuário ou senha incorretos!\n");
                printf("\nDeseja tentar novamente?\n");
                printf("\n(1) - Sim \n(0) - Não\n\n");
                printf("Resposta: ");
                scanf("%d", &continuar);
                //getch();

                switch(continuar){
                    case 1:
                        system("cls");
                    break;

                    case 0:
                        printf("\nPrograma encerrado!\n");
                        exit(0);
                    break;

                    default:
                        printf("\nOpção inválida!");
                        printf("\n\nPressione qualquer tecla para tentar novamente");
                        getch();
                        system("cls");
                        //login();
                    break;
                }
            }while(continuar != 1 && continuar != 0);
        //}
    }while(validacao == 0);
}

int cadastro(){
    char user[MAX_LENGTH], pass[MAX_LENGTH], confirmPass[MAX_LENGTH];

    validacao = 0;

    do{
        printf("\n      - - - Tela de Cadastro - - -       \n");

        printf("\n - Digite seu usuário: ");
        scanf("%s", &user);
        printf("\n - Digite sua senha: ");
        scanf("%s", &pass);
        printf("\n - Confirme sua senha: ");
        scanf("%s", &confirmPass);

        if(strcmp(pass, confirmPass) == 0){
            strcpy(users[totalUsers], user);
            strcpy(passwords[totalUsers], pass);

            totalUsers++;

            printf("\n\nUsuário e senha cadastrados com sucesso!\n");

            validacao = 1;

            vaiPraOnde();
        }
        else{
            do{
                printf("\n\nUsuário ou senha incorretos!\n");
                printf("\nDeseja tentar novamente?\n");
                printf("\n(1) - Sim \n(2) - Não\n\n");
                printf("Resposta: ");
                scanf("%d", &continuar);

                switch(continuar){
                    case 1:
                        system("cls");
                    break;

                    case 2:
                        system("cls");
                        vaiPraOnde();
                    break;

                    default:
                        printf("\nOpção inválida!");
                        printf("\n\nPressione qualquer tecla para tentar novamente");
                        getch();
                        system("cls");
                    break;
                }
            }while(continuar != 1 && continuar != 0);
        }
    }while(validacao == 0);
}

int vaiPraOnde(){

    int vaiPraLa;

    do{
        printf("\n------------------------\n\n");
        printf("Vai pra onde agora?");
        printf("\n\n(1) - Login \n(2) - Cadastro \n(3) - Usuários \n(4) - Sair");
        printf("\n\nResposta: ");
        scanf("%d", &vaiPraLa);

        switch(vaiPraLa){
            case 1:
                system("cls");
                login();
            break;

            case 2:
                system("cls");
                cadastro();
            break;

            case 3:
                system("cls");
                showUsers();
            break;

            case 4:
                printf("\nPrograma encerrado!\n");
                exit(0);
            break;

            default:
                printf("\nOpção inválida!");
                printf("\n\nPressione qualquer tecla para tentar novamente");
                getch();
                system("cls");
            break;
        }
    }while(vaiPraLa != 1 && vaiPraLa != 2 && vaiPraLa != 3);
}

int showUsers(){
    printf("\n      - - - Usuários - - -       \n\n");

    for(int i = 0; i < totalUsers; i++){
        printf("\nUsuário: %s - Senha: %s \n", users[i], passwords[i]);
    }

    vaiPraOnde();
}
