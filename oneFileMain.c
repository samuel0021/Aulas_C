
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <locale.h>

#define TAMANHO_NOME_USUARIO 20
#define TAMANHO_SENHA 20
#define TAMANHO_NOME_PRODUTO 50
#define MAX_USUARIOS 10
#define MAX_PRODUTOS 50

#define USER_ADM "adm"
#define SENHA_ADM "123"

struct clientes {
    char nome[50], cpf[12], cel[12];
};

typedef struct {
    char nome_usuario[TAMANHO_NOME_USUARIO];
    char senha_usuario[TAMANHO_SENHA];
} Usuario;

typedef struct {
    char nome_produto[TAMANHO_NOME_PRODUTO];
    int quantidade_produto;
    float preco_produto;
} Produto;

typedef struct clientes clientes;

Usuario lista_usuarios[MAX_USUARIOS];
Produto lista_produtos[MAX_PRODUTOS];
int total_usuarios = 0;
int total_produtos = 0;

clientes *lista = NULL;
int qtd = 0;

// FUNÇÕES

/* FUNÇÕES NO ARQUIVO:
    cadClientes()
    exibeClientes()
    menuAdm()
    menuGeral()
    telaCaixa()
    telaClientes()
    telaInicial()
    telaUsuarios()
    descontoTotal()
    descontoProduto()
    exibeProdutos()
    limpaTela()
*/

// LIMPA TELA (limpa a tela)
void limpaTela(){
    system("cls");
}

float descontoTotal(int i, float valorProdutos[], float totalSemDesc){
    float descontoPercentual, valorDesconto, valorFinal;

    do{
        exibeProdutos(i, valorProdutos, totalSemDesc);

        printf("\nTotal sem desconto: R$ %.2f\n", totalSemDesc);
        printf("\nDigite a porcentagem do desconto: ");
        scanf("%f", &descontoPercentual);

        if(descontoPercentual < 0 || descontoPercentual > 100){
            limpaTela();
            printf("***O valor do desconto deve estar entre 1 e 100!\n");
            printf("\n-------------------------------------------------\n");
        }
    }
    while(descontoPercentual <= 0 || descontoPercentual > 100);

    valorFinal = totalSemDesc - (totalSemDesc * descontoPercentual / 100);
    valorDesconto = totalSemDesc - valorFinal;

    limpaTela();

    printf("\nTotal sem desconto: R$ %.2f\n", totalSemDesc);
    printf("\n          Desconto: %.f%%", descontoPercentual);
    printf("\n  Valor descontado: R$ %.2f\n", valorDesconto);
    printf("\nTotal com desconto: R$ %.2f\n", valorFinal);

    return valorFinal;
}

// DESCONTO PRODUTO (aplica desconto apenas no produto escolhido)
float descontoProduto(float preco, float desconto){
    return preco * (1 - desconto / 100);
}


float telaCaixa(){
    float valorProdutos[100], total = 0, desconto;
    char op;
    int i = 0;

    do{
        exibeProdutos(i, valorProdutos, total);

        printf("\nDigite o valor do %dº produto: R$ ", i+1);
        scanf("%f", &valorProdutos[i]);

        total += valorProdutos[i];
        i++;

        limpaTela();

        exibeProdutos(i, valorProdutos, total);

        printf("\nAdicionar mais um produto? (S/N)\n");
        printf(" - Escolha: ");
        fflush(stdin);
        scanf("%c", &op);

        op = tolower(op);

        limpaTela();
    }
    while(op == 's' || op == '1');

    exibeProdutos(i, valorProdutos, total);

    printf("\nAdicionar desconto ao valor total? (S/N)?");
    printf("\n - Escolha: ");
    fflush(stdin);
    scanf("%c", &op);

    limpaTela();

    if(op == 's'){
        total = descontoTotal(i, valorProdutos, total);
    }
    else{
        exibeProdutos(i, valorProdutos, total);
    }

    printf("\n\nCompra finalizada");
    printf("\n\nAperte qualquer tecla para continuar");
    getch();
    limpaTela();

    return total;
}

// MENU ADM

void menuAdm(){
    int op;

    while(1){
        printf("\n\n\t --- Menu ADM ---\n\n");
        printf("  1. Usuários\n");
        printf("  2. Produtos\n");
        printf("  3. Clientes\n");
        printf("  4. Caixa\n");
        printf("  5. Estoque\n\n");
        printf("\n  6. Trocar usuário\n");
        printf("  0. Sair\n");
        printf("\n  - Escolha: ");
        fflush(stdin);
        scanf("%d", &op);

        switch(op){
            case 1:
                limpaTela();
                telaUsuarios();
            break;

            case 2:
                limpaTela();
                telaProdutos();
            break;

            case 3:
                limpaTela();
                telaClientes();
            break;

            case 4:
                limpaTela();
                telaCaixa();
            break;

            case 5:
                limpaTela();
                //estoque();
            break;

            case 6:
                limpaTela();
                login_usuario();
            break;

            case 0:
                limpaTela();
                printf("\n\nPrograma encerrado\n\n\n");
                exit(0);
            break;

            default:
                printf("\n\nOpção inválida! Aperte qualquer tecla para tentar novamente");
                getch();
                limpaTela();
            break;
        }
    }
}



void telaUsuarios(){
    int op;

    while(1){
        printf("\n\n\t --- Usuários ---\n\n");
        printf("  1. Registrar Usuário\n");
        printf("  2. Lista de Usuários\n\n");
        printf("  0. Voltar\n");
        printf("\n  - Escolha: ");
        fflush(stdin);
        scanf("%d", &op);

        switch(op){
            case 1:
                limpaTela();
                registrar_usuario();
            break;

            case 2:
                limpaTela();
                listarUsuarios();
            break;

            case 0:
                limpaTela();
                return;
            break;

            default:
                printf("\n\nOpção inválida! Aperte qualquer tecla para tentar novamente");
                getch();
                limpaTela();
            break;
        }
    }
}

// MENU PRINCIPAL
void telaInicial(){
    incluirAdm();

    int op;

    while(1){
        printf("\n\n\t --- Início ---\n\n");
        printf("  1. Login\n");
        printf("  0. Sair\n");
        printf("\n  - Escolha: ");
        fflush(stdin);
        scanf("%d", &op);

        switch(op){
            case 1:
                limpaTela();
                login_usuario();
            break;

            case 0:
                limpaTela();
                printf("\n\nPrograma encerrado\n\n\n");
                exit(0);
            break;

            default:
                printf("Opção inválida! Aperte qualquer tecla para tentar novamente");
                getch();
                limpaTela();
            break;
        }
    }
}

// CADASTRO DE CLIENTES (cadastra os clientes)
// chamada: cadClientes(&lista, &qtd);
void cadClientes(clientes **lista, int *qtd) {
    char continuar;

    do {
        *lista = realloc(*lista, (*qtd + 1) * sizeof(clientes));

        if (*lista == NULL) {
            printf("Erro ao alocar memória!\n");
            exit(1);
        }

        printf("\n\t --- Cadastro de Clientes ---\n");

        printf("\nNome completo: ");
        scanf(" %49[^\n]s", (*lista)[*qtd].nome);
        fflush(stdin);

        printf("\nCPF(apenas números): ");
        scanf("%11s", (*lista)[*qtd].cpf);
        fflush(stdin);

        printf("\nCelular com DDD(apenas números): ");
        scanf("%11s", (*lista)[*qtd].cel);
        fflush(stdin);

        (*qtd)++;

        limpaTela();

        printf("\n\tCliente cadastrado com sucesso!");

        printf("\n\nDeseja cadastrar outro cliente? (S/N)");
        printf("\n - Escolha: ");
        scanf(" %c", &continuar);

        continuar = tolower(continuar);

        limpaTela();

    } while (continuar == 's');
}

// EXIBE CLIENTES (exibe os clientes)
// chamada: exibeClientes(lista, qtd);
void exibeClientes(const clientes *lista, int qtd) {
    printf("\n\t    --- Clientes ---\n");

    if(qtd <= 0){
        printf("\nNenhum cliente cadastrado\n");
    }

    for (int i = 0; i < qtd; i++) {
        printf("\n--------------- Cliente %d ---------------\n\n", i + 1);
        printf("\t   Nome: %s\n", lista[i].nome);
        printf("\t    CPF: %.3s.%.3s.%.3s-%.2s\n", lista[i].cpf, lista[i].cpf + 3, lista[i].cpf + 6, lista[i].cpf + 9);
        printf("\tCelular: (%.2s) %.1s%.4s-%.4s\n", lista[i].cel, lista[i].cel + 2, lista[i].cel + 3, lista[i].cel + 7);
    }
    printf("\n-----------------------------------------\n");

    printf("\n  Aperte qualquer tecla para voltar");
    getch();
    limpaTela();
}

void removerClientes(clientes **lista, int *qtd) {
    int num, op;

    if(*qtd == 0) {
        printf("\n\t    --- Clientes ---\n");
        printf("\nNenhum cliente cadastrado\n");
        printf("\nAperte qualquer tecla para voltar.\n");
        getch();
        limpaTela();
        return;
    }

    printf("\n\t --- Clientes ---\n");

    for (int i = 0; i < *qtd; i++) {
        printf("\n  - Cliente %d: %s\n", i + 1, (*lista)[i].nome);
    }

    printf("\nDigite o número do cliente que deseja remover: ");
    scanf("%d", &num);

    if (num < 1 || num > *qtd) {
        printf("\nCliente não existente\n");
        printf("\nAperte qualquer tecla para voltar.\n");
        getch();
        limpaTela();
        return;
    }

    printf("\nCliente %s será removido\n\nDeseja continuar?\n", (*lista)[num - 1].nome);
    printf("\n  1. Sim\n  2. Não\n\n");
    printf("  - Escolha: ");
    scanf("%d", &op);

    if(op == 2){
        limpaTela();
        return;
    }

    for(int i = num - 1; i < *qtd - 1; i++) {
        (*lista)[i] = (*lista)[i + 1];
    }

    *qtd--;
    *lista = realloc(*lista, (*qtd) * sizeof(clientes));

    if (*lista == NULL && *qtd > 0) {
        printf("Erro ao alocar memória após a remoção!\n");
        exit(1);
    }

    limpaTela();
    printf("\nCliente removido!\n");
    printf("\nAperte qualquer tecla para voltar.\n");
    getch();
    limpaTela();
}


void telaClientes(){
    int op;

    while(1){
        printf("\n\n\t --- Clientes ---\n\n");
        printf("  1. Cadastrar Clientes\n");
        printf("  2. Exibir Clientes\n");
        printf("  3. Remover Clientes\n\n");
        printf("  0. Voltar\n");
        printf("\n  - Escolha: ");
        fflush(stdin);
        scanf("%d", &op);

        switch(op){
            case 1:
                limpaTela();
                cadClientes(&lista, &qtd);
            break;

            case 2:
                limpaTela();
                exibeClientes(lista, qtd);
            break;

            case 3:
                limpaTela();
                removerClientes(&lista, &qtd);
            break;

            case 0:
                limpaTela();
                return;
            break;

            default:
                printf("\nOpção inválida! Aperte qualquer tecla para tentar novamente");
                getch();
                limpaTela();
            break;
        }
    }
}

// EXIBE PRODUTOS (exibe os produtos)
void exibeProdutos(int i, float valorProdutos[], float total){
    for(int j = 0; j < i; j++){
        printf("\n\tProduto %d: R$ %.2f", j + 1, valorProdutos[j]);
    }

    if(i > 0) printf("\n\t\t-");

    printf("\n\t  Total: R$ %.2f \n", total);
    printf("\n----------------------------------\n");
}

// MÓDULO CAIXA DESCONTO (calcula o desconto total da compra)

void menuGeral(){
    int op;

    while(1){
        printf("\n\n\t --- Menu ---\n\n");
        printf("  1. Produtos\n");
        printf("  2. Clientes\n");
        printf("  3. Caixa\n");
        printf("  4. Estoque\n\n");
        printf("  5. Trocar usuário\n");
        printf("  0. Sair\n");
        printf("\n  - Escolha: ");
        fflush(stdin);
        scanf("%d", &op);

        switch(op){
            case 1:
                limpaTela();
                telaProdutos();
            break;

            case 2:
                limpaTela();
                telaClientes();
            break;

            case 3:
                limpaTela();
                telaCaixa();
            break;

            case 4:
                limpaTela();
                //estoque();
            break;

            case 5:
                limpaTela();
                login_usuario();
            break;

            case 0:
                limpaTela();
                printf("\n\nPrograma encerrado\n\n\n");
                exit(0);
            break;

            default:
                printf("\n\nOpção inválida! Aperte qualquer tecla para tentar novamente");
                getch();
                limpaTela();
            break;
        }
    }
}

// SOMA PRODUTOS (soma os produtos)




void incluirAdm(){
    strcpy(lista_usuarios[0].nome_usuario, USER_ADM);
    strcpy(lista_usuarios[0].senha_usuario, SENHA_ADM);

    total_usuarios++;
}


/// ---------- FUNCOES PRODUTOS ----------

void listar_produtos() {
    limpaTela();
    printf("\n\t--- Lista de Produtos ---\n\n");
    if (total_produtos == 0) {
        printf("\nNenhum produto no estoque.\n");
        return;
    }

    for (int i = 0; i < total_produtos; i++) {
        float preco = lista_produtos[i].preco_produto;
        int inteiro = (int)preco;
        int centavos = (int)((preco - inteiro) * 100);
        printf("Produto: %s | Quantidade: %d | Preço: R$ %d,%02d\n",
               lista_produtos[i].nome_produto, lista_produtos[i].quantidade_produto, inteiro, centavos);
    }

    printf("\nAperte qualquer tecla para voltar");
    getch();
    limpaTela();
}


void limpar_buffer() {
    while (getchar() != '\n');
}


void substituir_virgula_por_ponto(char *string) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == ',') {
            string[i] = '.';
        }
    }
}


void adicionar_produto() {
    if (total_produtos >= MAX_PRODUTOS) {
        printf("\nEstoque cheio! Não é possível adicionar mais produtos.\n");
        return;
    }

    char nome_produto[TAMANHO_NOME_PRODUTO];
    int quantidade_produto;
    char preco_str[20];
    float preco_produto;

    printf("\n\t --- Adicionar Produto ---\n\n");
    printf("Nome do produto: ");
    scanf(" %[^\n]", nome_produto);

    printf("Quantidade: ");
    scanf("%d", &quantidade_produto);

    limpar_buffer();

    printf("Preço: ");
    scanf("%s", preco_str);
    substituir_virgula_por_ponto(preco_str);
    preco_produto = atof(preco_str);

    strncpy(lista_produtos[total_produtos].nome_produto, nome_produto, TAMANHO_NOME_PRODUTO - 1);
    lista_produtos[total_produtos].nome_produto[TAMANHO_NOME_PRODUTO - 1] = '\0';  // Terminação nula
    lista_produtos[total_produtos].quantidade_produto = quantidade_produto;
    lista_produtos[total_produtos].preco_produto = preco_produto;
    total_produtos++;

    limpaTela();

    printf("\nProduto adicionado com sucesso!\n");
}


void remover_produto() {
    listar_produtos();
    char nome_produto[TAMANHO_NOME_PRODUTO];

    printf("\n\t --- Remover Produto ---\n\n");
    printf("Nome do produto: ");
    scanf(" %[^\n]", nome_produto);

    for (int i = 0; i < total_produtos; i++) {
        if (strcmp(lista_produtos[i].nome_produto, nome_produto) == 0) {
            for (int j = i; j < total_produtos - 1; j++) {
                lista_produtos[j] = lista_produtos[j + 1];
            }
            total_produtos--;

            limpaTela();

            printf("\nProduto removido com sucesso!\n");
            return;
        }
    }
    limpaTela();

    printf("\nProduto não encontrado.\n");
}


int obter_opcao_menu() {
    int opcao;
    while (1) {
        printf("Escolha uma opção: ");
        if (scanf("%d", &opcao) == 1) {
            limpar_buffer();
            limpaTela();
            return opcao;
        } else {
            limpaTela();
            printf("Entrada inválida! Tente novamente.\n");
            limpar_buffer();
        }
    }
}


void telaProdutos() {
    int opcao;

    while(1){
        printf("\n\n\t --- Produtos ---\n\n");
        printf("1. Adicionar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Remover Produto\n\n");
        printf("0. Voltar\n\n");

        opcao = obter_opcao_menu();

        switch (opcao) {
            case 1:
                limpaTela();
                adicionar_produto();
                break;
            case 2:
                limpaTela();
                listar_produtos();
                break;
            case 3:
                limpaTela();
                remover_produto();
                break;
            case 0:
                limpaTela();
                return;
            break;

            default:
                limpaTela();
                printf("\nOpção inválida! Tente novamente.\n");
        }
    }
}

// ---------- FUNCOES USUARIO ----------

void registrar_usuario() {
    char nome_usuario[TAMANHO_NOME_USUARIO];
    char senha_usuario[TAMANHO_SENHA];

    printf("\n\n\t --- Registro de Usuário ---\n\n");
    printf("Digite o nome de usuário: ");
    scanf(" %[^\n]", nome_usuario);
    printf("          Digite a senha: ");
    scanf(" %[^\n]", senha_usuario);

    adicionar_usuario(nome_usuario, senha_usuario);
}

int verificar_usuario_existente(const char *nome_usuario) {
    for (int i = 0; i < total_usuarios; i++) {
        if (strcmp(lista_usuarios[i].nome_usuario, nome_usuario) == 0) {
            return 1;
        }
    }
    return 0;
}

void listarUsuarios(){
    printf("\n\n\t --- Usuários ---\n\n");
    printf("Total de usuários cadastrados: %d\n", total_usuarios + 1);

    for(int i = 0; i < total_usuarios; i++){
        printf("%d - %s\n", i + 1, lista_usuarios[i].nome_usuario);
    }

    printf("\n\nAperte qualquer tecla para voltar");
    getch();
    limpaTela();
    return;
}


void adicionar_usuario(const char *nome_usuario, const char *senha_usuario) {
    if (verificar_usuario_existente(nome_usuario)) {
        limpaTela();

        printf("\nErro: Nome de usuário já existe. Tente outro.\n");
        return;
    }

    if (total_usuarios >= MAX_USUARIOS) {
        limpaTela();

        printf("\nNúmero máximo de usuários atingido.\n");
        return;
    }

    strncpy(lista_usuarios[total_usuarios].nome_usuario, nome_usuario, TAMANHO_NOME_USUARIO - 1);
    lista_usuarios[total_usuarios].nome_usuario[TAMANHO_NOME_USUARIO - 1] = '\0';
    strncpy(lista_usuarios[total_usuarios].senha_usuario, senha_usuario, TAMANHO_SENHA - 1);
    lista_usuarios[total_usuarios].senha_usuario[TAMANHO_SENHA - 1] = '\0';
    total_usuarios++;

    limpaTela();

    printf("\nUsuário registrado com sucesso!\n");
}


int autenticar(const char *nome_usuario, const char *senha_usuario) {
    for (int i = 0; i < total_usuarios; i++) {
        if (strcmp(lista_usuarios[i].nome_usuario, nome_usuario) == 0 &&
            strcmp(lista_usuarios[i].senha_usuario, senha_usuario) == 0) {
            return 1;
        }
    }
    return 0;
}



void login_usuario() {
    char nome_usuario[TAMANHO_NOME_USUARIO];
    char senha_usuario[TAMANHO_SENHA];

    printf("\n\n\t --- Login ---\n\n");
    printf("Nome de usuário: ");
    scanf(" %[^\n]", nome_usuario);
    printf("          Senha: ");
    scanf(" %[^\n]", senha_usuario);

    if(strcmp(USER_ADM, nome_usuario) == 0 && strcmp(SENHA_ADM, senha_usuario) == 0){
        limpaTela();
        printf("Login bem-sucedido! Bem-vindo(a), ADM");
        menuAdm();
    }

    if (autenticar(nome_usuario, senha_usuario)) {
        limpaTela();
        printf("Login bem-sucedido! Bem-vindo(a), %s!", nome_usuario);
        menuGeral();
    } else {
        printf("\nNome de usuário ou senha incorretos.\n");
        printf("\n\nAperte qualquer tecla para voltar");
        getch();
        limpaTela();
    }
}


void tela_boas_vindas() {
    printf("\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t****************************************\n");
    printf("\t\t\t\t*                                      *\n");
    printf("\t\t\t\t*          BEM-VINDO AO MERCADO        *\n");
    printf("\t\t\t\t*                                      *\n");
    printf("\t\t\t\t****************************************\n");
}




int main(){
    setlocale(LC_ALL, "");

    tela_boas_vindas();
    Sleep(1000);
    limpaTela();

    telaInicial();

    return 0;
}


