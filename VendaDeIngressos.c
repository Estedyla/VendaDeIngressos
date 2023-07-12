#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct ingresso
{
    char nome[100]; 
    char cpf[12]; 
    int anoDeNascimento;
};

int main()
{
    setlocale(LC_ALL, "Portuguese");
    struct ingresso lista[100]; 
    int op, numIngressos = 0;
    
    do
    {  /*Criacao do menu*/
        printf("1 - Vender ingresso\n");
        printf("2 - Listar ingressos Vendidos\n");
        printf("3 - Validar ingressos\n");
        printf("4 - Sair do Programa\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &op);
        fflush(stdin);
        
        if (op == 1)
        {
            system("clear");
            
            printf("Digite o nome do comprador: ");
            scanf(" %[^\n]s", lista[numIngressos].nome);
            fflush(stdin);
            
            printf("Digite o CPF do comprador: ");
            scanf(" %[^\n]s", lista[numIngressos].cpf);
            
            printf("Digite o ano de nascimento do comprador: ");
            scanf("%d", &lista[numIngressos].anoDeNascimento);
            fflush(stdin);
            
            numIngressos++;
            
            printf("Ingresso vendido com sucesso!\n");
        }
        else if (op == 2)
        {
            system("clear");
            
            printf("Listagem de ingressos vendidos:\n");
            
            for (int i = 0; i < numIngressos; i++)
            {
                printf("Nome: %s\n", lista[i].nome);
                printf("CPF: %s\n", lista[i].cpf);
                printf("Ano de Nascimento: %d\n", lista[i].anoDeNascimento);
                printf("===============================\n");
            }
        }
        else if (op == 3)
        {
            system("clear");
            
            char cpfBusca[12];
            int encontrado = 0;
            
            printf("Digite o CPF para validar o ingresso: ");
            scanf(" %[^\n]s", cpfBusca);
            
            for (int i = 0; i < numIngressos; i++)
            {
                if (strcmp(lista[i].cpf, cpfBusca) == 0)
                {
                    printf("Ingresso válido!\n");
                    printf("Nome: %s\n", lista[i].nome);
                    printf("CPF: %s\n", lista[i].cpf);
                    printf("Ano de Nascimento: %d\n", lista[i].anoDeNascimento);
                    encontrado = 1;
                    break;
                }
            }
            
            if (!encontrado)
            {
                printf("Ingresso inválido. CPF não encontrado.\n");
            }
        }
    } while (op != 4);

    return 0;
}
