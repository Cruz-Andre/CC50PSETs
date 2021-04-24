/*******************************************************************************
 * beer.c - Exercício 1
 *
 * Set de Problemas Semana 2
 * Curso CC50 Introdução à Ciência da Computação de Harvard
 *
 * Canta a música 99 garrafas de cerveja de acordo com o número de garrafas
 *
 * Demonstra for loop.
 ******************************************************************************/

#include <stdio.h>
#include <cc50.h>

int
main(void)
{
    // Pergunta um Número ao Usuário e Verifica se o Digito é Maior que Zero
    printf("Quantas garrafas de cerveja? ");
    int n, i;
    do
    {
        n = GetInt();
        if (n < 1)
        {
            printf("Digite um número maior que 0 (zero) => ");
        }
    }
    while (n < 1);

    // Canta a Música de Acordo com o Número de Garrafas
    printf("\n");
    for(i = n; i > 0; i--)
        if (i > 2)
        {
            printf("%d garrafas de cerveja no muro, ", i);
            printf("bebo uma, jogo no lixo, ");
            printf("%d garrafas no muro...\n", i - 1);
        }    
        
        else if (i == 2)
        {
            printf("%d garrafas de cerveja no muro, ", i);
            printf("bebo uma, jogo no lixo, ");
            printf("%d garrafa no muro...\n", i - 1);
        }
    
        else
        {
            printf("%d garrafa de cerveja no muro, ", i);
            printf("bebo uma, jogo no lixo, ");
            printf("nenhuma garrafa no muro...\n\n");
        }
    
    return 0;    
}
