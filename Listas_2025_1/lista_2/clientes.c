#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 1000
#define TAM_LINHA 256
/*
    Fiz três funções a parte, para mostrar outra possibilidade de logica..
    1.merge_versin_luquinhas
    2.imprimirTodosClientes
    3.buscarClientePorId -> Com busca binária pós ordenação com base no id

    Complexidade das funções adicionais
        com ordenação: O((n * log2(n)) + log2(n))
        sem ordenação: O(n) no pior caso
        O(n) < O((n * log2(n)) + log2(n))
        Porém a vantagem é se a função de busca for utilizada varias e varias vezes em partes diferentes do codigo.
            Considerando Q' como o numero de Querys (consultas)
            O(Q' * n) > O(Q' * log2(n));
            O(n) > O(log2(n))
        ...
*/
typedef struct {
    int id;
    char nome[100];
    char email[100];
    int idade;
} Cliente;
// Prototipos - Ordem(top down)
// -----------------------------------------------------------------------------------
void carregarClientes(const char *, Cliente *, int *);
void merge_version_luquinhas(Cliente *, int, int);
Cliente *buscarClientePorId(Cliente *, int, int);
void imprimirCliente(Cliente);
void removerCliente(Cliente *, int *, int);
void imprimirTodosClientes(Cliente *, int);
void alterarDadosCliente(Cliente *, char *, char *, int);
// -----------------------------------------------------------------------------------
void carregarClientes(const char *nomeArquivo, Cliente clientes[], int *quantidade) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        *quantidade = 0;
        return;
    }

    char linha[TAM_LINHA];
    *quantidade = 0;

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (*quantidade >= MAX_CLIENTES) {
            printf("Limite máximo de clientes atingido.\n");
            break;
        }

        linha[strcspn(linha, "\n")] = '\0';

        // Separar os dados por ";"
        char *token = strtok(linha, ";");
        if (token == NULL) continue;
        clientes[*quantidade].id = atoi(token);

        token = strtok(NULL, ";");
        if (token == NULL) continue;
        strncpy(clientes[*quantidade].nome, token, sizeof(clientes[*quantidade].nome));
        clientes[*quantidade].nome[sizeof(clientes[*quantidade].nome) - 1] = '\0';

        token = strtok(NULL, ";");
        if (token == NULL) continue;
        strncpy(clientes[*quantidade].email, token, sizeof(clientes[*quantidade].email));
        clientes[*quantidade].email[sizeof(clientes[*quantidade].email) - 1] = '\0';

        token = strtok(NULL, ";");
        if (token == NULL) continue;
        clientes[*quantidade].idade = atoi(token);

        (*quantidade)++;
    }

    fclose(arquivo);
}
// -----------------------------------------------------------------------------------
/*
    void merge_version_luquinhas(Cliente *cliente, int left, int right) {
        if (left >= right) return;
        int middle = left + ((right - left) >> 1);
        merge_version_luquinhas(cliente, left, middle), merge_version_luquinhas(cliente, middle + 1, right);

        int n = middle - left + 1, m = right - middle;

        int prefix[n], sufix[m];

        for (int i = left;i <= right;++i) {
            if (i <= middle) prefix[i - left] = cliente[i].id;
            else sufix[i - (middle + 1)] = cliente[i].id;
        }

        int i = 0, j = 0, k = left;
        while(i < n || j < m) {
            if (j == m || (prefix[i] < sufix[j] && i < n)) cliente[k++].id = prefix[i++];
            else cliente[k++].id = sufix[j++];
        }
    }
*/
// -----------------------------------------------------------------------------------
Cliente *buscarClientePorId(Cliente *cliente, int quantidade, int id) {
    Cliente *beginPtr = cliente, *endPtr = cliente + quantidade;
    while ((beginPtr != endPtr) && ((beginPtr++)->id != id));
    return ((--beginPtr)->id == id) ? beginPtr : NULL; 
}
// -----------------------------------------------------------------------------------
/*
    Cliente *buscarClientePorId(Cliente *cliente, int quantidade, int id) {
        int left = 0, right = quantidade - 1;
        while (right - left >= 0) {
            int middle = left + ((right - left) >> 1);
            if (cliente[middle].id == id) return cliente + middle;
            if (cliente[middle].id > id) right = middle - 1;
            else left = middle + 1;
        }
        return NULL; 
    }
*/
// -----------------------------------------------------------------------------------
void imprimirCliente(Cliente cliente) {
    printf("Nome: %s Email: %s ID: %d Idade: %d\n", cliente.nome, cliente.email, cliente.id, cliente.idade);
}
// -----------------------------------------------------------------------------------
void removerCliente(Cliente *cliente, int *quantidade, int id) {

    Cliente *x = buscarClientePorId(cliente, *quantidade , id);

    if (!x) {
        printf("Ocorreu um erro!\n");
        exit(0);
    }

    Cliente *beginPtr = x, *middlePtr = x + 1, *endPtr = cliente + (*quantidade);

    while (middlePtr != endPtr) {
        beginPtr->id = middlePtr->id;
        strcpy(beginPtr->email, middlePtr->email);
        strcpy(beginPtr->nome, middlePtr->nome); 
        beginPtr->idade = middlePtr->idade;
        ++beginPtr, ++middlePtr; 
    }

    (*quantidade)--;

}
// -----------------------------------------------------------------------------------
void imprimirTodosClientes(Cliente *cliente, int quantidade) {
    for (int i = 0;i < quantidade;++i)
        printf("Nome: %s Email: %s ID: %d Idade: %d\n", cliente[i].nome, cliente[i].email, cliente[i].id, cliente[i].idade);
}
// -----------------------------------------------------------------------------------
void alterarDadosCliente(Cliente *cliente, char *_nome, char *_email, int _idade) {
    if (cliente) {
        strcpy(cliente->email, _email);
        strcpy(cliente->nome, _nome);
        cliente->idade = _idade;
    }
    return;
}
// -----------------------------------------------------------------------------------
char *reading() {
    int c = 0, curr = 0; 
    char *string = malloc(sizeof(char) * (TAM_LINHA + 1));
    if (!string) {
        printf("Ocorreu um erro!\n");
        exit(1);
    }
    while (curr < TAM_LINHA && (c = getchar()) != '\n' && c != EOF) string[curr++] = (char)c;
    string[curr] = '\0';
    return string;
}
// -----------------------------------------------------------------------------------
void salvarClientes(const char *nomeArquivo, Cliente clientes[], int quantidade) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo %s para escrita.\n", nomeArquivo);
        exit(1);
    }

    for (int i = 0; i < quantidade;++i)
        fprintf(arquivo, "%d;%s;%s;%d\n", clientes[i].id, clientes[i].nome, clientes[i].email, clientes[i].idade);
    
    fclose(arquivo);
    printf("Dados dos clientes salvos com sucesso em %s\n", nomeArquivo);
}
// -----------------------------------------------------------------------------------
int main() {
    Cliente clientes[MAX_CLIENTES];
    int quantidade = 0;
    int opcao, id, idade;
    char *nome, *email;

    carregarClientes("clientes.txt", clientes, &quantidade);

    for(;;) {
        //-----------------------------------------------
        printf("1. Imprimir todos os clientes\n");
        printf("2. Buscar cliente por ID\n");
        printf("3. Remover cliente por ID\n");
        printf("4. Alterar dados de um cliente\n");
        printf("5. Salvar e sair\n");
        //-----------------------------------------------
        printf("Escolha uma opção: \n");

        char *entrada = reading();
        opcao = atoi(entrada);
        free(entrada);

        switch (opcao) {
            case 1:
                imprimirTodosClientes(clientes, quantidade);
                break;
            case 2:
                printf("Digite o ID do cliente a ser buscado: ");
                entrada = reading();
                id = atoi(entrada);
                free(entrada);
                Cliente *cliente = buscarClientePorId(clientes, quantidade, id);
                if (cliente)
                    imprimirCliente(*cliente);
                else
                    printf("Cliente não encontrado.\n");
                break;
            case 3:
                printf("Digite o ID do cliente a ser removido: ");
                entrada = reading();
                id = atoi(entrada);
                free(entrada);
                removerCliente(clientes, &quantidade, id);
                printf("Cliente removido com sucesso.\n");
                break;
            case 4: 
                printf("Digite o ID do cliente a ser alterado: ");
                entrada = reading();
                id = atoi(entrada);
                free(entrada);
                printf("Digite o novo nome: ");
                nome = reading();
                printf("Digite o novo email: ");
                email = reading();
                printf("Digite a nova idade: ");
                entrada = reading();
                idade = atoi(entrada);
                free(entrada);
                Cliente *clienteAlterado = buscarClientePorId(clientes, quantidade, id);
                if (clienteAlterado) {
                    alterarDadosCliente(clienteAlterado, nome, email, idade);
                    printf("Dados do cliente alterados com sucesso.\n");
                } else
                    printf("Cliente não encontrado.\n");
                free(nome);  
                free(email);
                break;
            case 5:
                salvarClientes("clientes.txt", clientes, quantidade);
                return 0;
            default: 
                break;
        }
    }
    return 0;
}
