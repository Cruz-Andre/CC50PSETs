/*******************************************************************************
 * greedy.c - Exercício 2
 *
 * Set de Problemas Semana 1 - CC50 Curso Ciência da Computação 50 de Harvard
 *
 * André Cruz
 *
 * Retorna a quantidade de moedas em um troco. Moedas de: 25¢, 10¢, 5¢, e 1¢
 ******************************************************************************/

#include <cc50.h>
#include <stdio.h>

int
main(void)
{
    // Variavel 'float' Para Numeros com Decimais e o Nome da Variavel.
    float troco;
    printf("Quanto devo de troco?\n");
    do{
        
        // Variavel 'troco' e a Funcao 'GetFloat' Para Armazernar o Valor em 'troco'
        troco = GetFloat();
        
        // Condicao 'if' Para Verificar se Digitou um Numero Real Racional Positivo
        if(troco <= 0)
        {
            printf("Digitou zero e/ou numero com virgula? tente de novo!\n");
            printf("Para numeros decimais digite a separacao com ponto (.)\n");
        }
      }
    while(troco <= 0);
    
    // Multiplicar o Valor de 'troco' por 100 para depois passar para um numero Real Inteiro.
    troco = troco * 100 + 0.0001;
    printf("%.10f <---Calculo do 'float' arredondado\n", troco);
    troco = (int) troco;
    int moeda;
    
    // Condicoes 'while', 'if' 'else' e 'incremento' Para Calcular a Quantidade de Moedas que o 'troco' Possuí
    while (troco != 0)
    {
        if(troco >= 25)
        {
            troco = troco - 25;
            moeda++;
        }
        else if(troco >= 10)
        {
            troco = troco - 10;
            moeda++;
        }
        else if(troco >= 5)
        {
            troco = troco - 5;
            moeda++;
        }
        else if(troco >= 1)
        {
            troco = troco - 1;
            moeda++;
        }
    }

    printf("%.2d <---Numero de moedas\n", moeda);
}
