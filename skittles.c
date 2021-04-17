/****************************************************************************
 * Skittles.c
 *
 * Set de Problemas Semana 1 - Ciência da Computação 50
 *
 * André Cruz
 *
 * Demonstra o uso da Função 'rand' e o Loop 'do'
 ***************************************************************************/
 
#include <cc50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main(void)
{
    // Variaveis
    int n, soft;
    
    // Gerando Numero Aleatorio
    srand(time(NULL));

    // Escolhe Numero Aleatorio Entre [0, 1023]
    soft = rand() % 1023;

    // Apresentando o programa
    printf("Olá! Sou um pote de balas soft!\n");
    printf("Adivinhe quantas balas há dentro do pote\n");
    printf("Uma dica: Estou pensando em um número de 0 a 1023\n");
    // Loop usado Para Descobrir o Numero Aleatorio
    do
    {
        n = GetInt();
        if(n < 0)
        {
            printf("Número negativo não né! pombas!\n");
        }
        else if(n > 1023)
        {
            printf("Tu tá de brinqueishow with me? eu falei entre 0 e 1023\n");
        }
        else if(soft > n && soft >=0)
        {
            printf("One more time! UP UP UP\n");
        }
        else if(soft < n && soft >=0)
        {
            printf("One more time, don't stop the DOWN DOWN DOWN!\n");
        }
    }
    while(n != soft);
    printf("Acertô miseravi!\n");
}
