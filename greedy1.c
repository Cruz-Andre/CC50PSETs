/*******************************************************************************
 * greedy1.c - Exercício 2
 *
 * Set de Problemas Semana 1 - CC50 Curso Ciência da Computação 50 de Harvard
 *
 * André Cruz
 *
 * Uso Condição Do While e Switch para escolher uma opção
 * Retorna a quantidade de moedas em um troco. Moedas de: 25¢, 10¢, 5¢, e 1¢
 ******************************************************************************/

#include <cc50.h>
#include <stdio.h>

int
main(void)
{
    // Uso Condição Do While e Switch para escolher uma opção
    int i;
    printf("Olá gostaria de comprar o Jornal YesterdaysNews? são só 0.25¢\n");
    do
    {
        printf("(1).Sim\n");
        printf("(2).Não\n");
        i = GetInt();
    }
    while ((i<1) || (i>2));
    
    switch (i)
    {
        case 1:
            printf("Obrigado! diriga-se ao caixa\n\n");
            break;
        case 2:
            printf("Obrigado! Volte Sempre\n");
            return(0);
    }
    // Variavel 'float' Para Numeros com Decimais e o Nome da Variavel.
    float troco;
    do
    {
    printf("Ok! Qual o valor do seu pagamento?\n");
    troco = GetFloat();
        if(troco <= 0.24)
        {
            printf("Digitou valor abaixo de 0.25¢?\n");
            printf("Digitou zero e/ou numero com virgula?\n");
            printf("Use separacao com ponto (.)\n\n");
        }
    }
    while(troco <= 0.24);
    
    troco = troco - 0.25;
    printf("Seu troco é de U$%.2f\n", troco);
    troco = troco * 100 + 0.0001;
    troco = (int) troco;
    int moeda;
    
    while (troco != 0)
    {
        if(troco >= 25)
        {
            troco = troco - 25; moeda++;
        }
        else if(troco >= 10)
        {
            troco = troco - 10; moeda++;
        }
        else if(troco >= 5)
        {
            troco = troco - 5; moeda++;
        }
        else if(troco >= 1)
        {
            troco = troco - 1; moeda++;
        }
    }

    printf("Aqui está sua(s) %.2d moeda(s)\n", moeda);
}
