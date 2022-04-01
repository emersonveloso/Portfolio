#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int questionario()
{
    int soma=0;
    char opcao;
    printf("Tem febre (S/N)? ");
    scanf("%c", &opcao);
    fflush(stdin);
    if (opcao == 'S' || opcao == 's')
    {
        soma = soma + 5;
    }
    printf("Tem dor de cabeça (S/N)? ");
    scanf("%c", &opcao);
    fflush(stdin);
    if (opcao == 'S' || opcao == 's')
    {
        soma = soma + 1;
    }
    printf("Tem secreção nasal ou espirros (S/N)? ");
    scanf("%c", &opcao);
    fflush(stdin);
    if (opcao == 'S' || opcao == 's')
    {
        soma = soma + 1;
    }
    printf("Tem dor/irritação na garganta (S/N)? ");
    scanf("%c", &opcao);
    fflush(stdin);
    if (opcao == 'S' || opcao == 's')
    {
        soma = soma + 1;
    }
    printf("Tem tosse seca (S/N)? ");
    scanf("%c", &opcao);
    fflush(stdin);
    if (opcao == 'S' || opcao == 's')
    {
        soma = soma + 3;
    }
    printf("Tem dificuldade respiratória (S/N)? ");
    scanf("%c", &opcao);
    fflush(stdin);
    if (opcao == 'S' || opcao == 's')
    {
        soma = soma + 10;
    }
    printf("Tem dores no corpo (S/N)? ");
    scanf("%c", &opcao);
    fflush(stdin);
    if (opcao == 'S' || opcao == 's')
    {
        soma = soma + 1;
    }
    printf("Tem diarréia (S/N)? ");
    scanf("%c", &opcao);
    fflush(stdin);
    if (opcao == 'S' || opcao == 's')
    {
        soma = soma + 1;
    }
    printf("Esteve em contato, nos últimos 14 dias, com um caso diagnosticado com COVID-19 (S/N)? ");
    scanf("%c", &opcao);
    fflush(stdin);
    if (opcao == 'S' || opcao == 's')
    {
        soma = soma + 10;
    }
    printf("Esteve em locais com grande aglomeração (S/N)? ");
    scanf("%c", &opcao);
    fflush(stdin);
    if (opcao == 'S' || opcao == 's')
    {
        soma = soma + 3;
    }    
    return(soma);       
}
void Salvaemarquivo(cpf, nome, sexo, idade, pontuacao){
    FILE *arquivo;
    arquivo = fopen("Paciente.txt", "a");
    fprintf(arquivo, "%s", "\n\nDados do paciente\n");
    fprintf(arquivo, "%s", "\nCPF: ");
    fprintf(arquivo, "%s", cpf);
    fprintf(arquivo, "%s", "\nNome: ");
    fprintf(arquivo, "%s", nome);
    fprintf(arquivo, "%s", "\nSexo: ");
    fprintf(arquivo, "%s", sexo);
    fprintf(arquivo, "%s", "\nIdade: ");
    fprintf(arquivo, "%d", idade);
    fprintf(arquivo, "%s", "\n\tPontuação obtida do paciente: ");
    fprintf(arquivo, "%d", pontuacao);
    fclose(arquivo);
}
int main(){
    setlocale(LC_ALL, "Portuguese");
    int idade, opcao, total;
    char cpf[15], nome[30], sexo[10];
    opcao = 0;
    while (opcao != 2)
    {
        printf("1 - Cadastrar \n2 - Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);
        if (opcao == 1)
        {
            system("cls");
            printf("Informe seu CPF: ");
            gets(cpf);
            fflush(stdin);
            printf("\nSeu nome: ");
            gets(nome);
            fflush(stdin);
            printf("\nSexo: ");
            gets(sexo);
            fflush(stdin);
            printf("\nIdade: ");
            scanf("%d", &idade);
            fflush(stdin);
            system("cls");
            total = questionario();
            system("cls");
            if (total == 0 || total <= 9)
            {
                printf("Risco baixo! Encaminhe para a sua ala correspondente\n");
                system("pause");
                system("cls");
            }
            else
            {
                if (total >= 10 && total <= 19)
                {
                    printf("Risco medio! Encaminhe para a sua ala correspondente\n");
                    system("pause");
                    system("cls");
                }
                else
                {
                    printf("Risco alto! Encaminhe para a ala de tratamento de COVID-19\n");
                    system("pause");
                    system("cls");
                }
            } 
            Salvaemarquivo(cpf, nome, sexo, idade, total);           
        }
    }
    return(0);
}