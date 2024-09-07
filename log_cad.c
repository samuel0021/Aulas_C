#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <strings.h>
#include <stdlib.h>

const char userADM[10] = "samuel0021", senhaADM[10] = "123456";

// variáveis de login
char user[10] = "", senha[10] = "";

// variáveis de cadastro
char cadUser[10] = "", cadSenha[10] = "", confirmaSenha[10] = "";

// variáveis de controle
int validacao, continuar;

int main(){
    setlocale(LC_ALL, "");

    int opcao;

    do{
        opcao = 1;
        printf("\n           - - - Menu - - -       \n");

        printf("\nEscolha a tela: \n");
        printf("\n(1) - Login \n(2) - Cadastro");
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

    validacao = 0;

    do{
        printf("\n      - - - Tela de Login - - -       \n");

        printf("\n - Digite seu usuário: ");
        scanf("%s", &user);
        printf("\n - Digite sua senha: ");
        scanf("%s", &senha);

        printf("\n\n%s %s", user, senha);

        if(strcmp(userADM, user) == 0 && strcmp(senhaADM, senha) == 0){

            printf("\n\nCertin vai la\n");
            validacao = 1;

            vaiPraOnde();
        }
        else{
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
        }
    }while(validacao == 0);
}

int cadastro(){

    validacao = 0;

    do{
        printf("\n      - - - Tela de Cadastro - - -       \n");

        printf("\n - Digite seu usuário: ");
        scanf("%s", &cadUser);
        printf("\n - Digite sua senha: ");
        scanf("%s", &cadSenha);
        printf("\n - Confirme sua senha: ");
        scanf("%s", &confirmaSenha);

        if(strcmp(cadSenha, confirmaSenha) == 0){
            printf("\n\nUsuário e senha cadastrados com sucesso!\n");
            validacao = 1;

            vaiPraOnde();
        }
        else{
            do{
                printf("\n\nUsuário ou senha incorretos!\n");
                printf("\nDeseja tentar novamente?\n");
                printf("\n(1) - Sim \n(0) - Não\n\n");
                printf("Resposta: ");
                scanf("%d", &continuar);

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
        printf("\n\n(1) - Login \n(2) - Cadastro \n(3) - Sair");
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
