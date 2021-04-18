/******************************************************************************
 * chart.c - exercicio 3
 *
 * Set de Problemas Semana 1 - Ciência da Computação 50
 *
 * André Cruz
 *
 * Gera um grafico de barras com tamanho proporcional aos valores solicitados
 *****************************************************************************/

#include <cc50.h>
#include <stdio.h>

int
main(void)
{

    int mf, fm, ff, mm;

    do
    {
        printf("Digite um número inteiro positivo para M procurando F: ");
        mf = GetInt();
        if(mf < 0)
        {
            printf("Digitou valor negativo ou com decimal? Digite novamente\n\n");
        }
    }
    while(mf < 0);

    do
    {
        printf("Digite um número inteiro positivo para F procurando M: ");
        fm = GetInt();
        if(fm < 0)
        {
            printf("Digitou valor negativo ou com decimal? Digite novamente\n\n");
        }
    }
    while(fm < 0);
    
    do
    {
        printf("Digite um número inteiro positivo para F procurando F: ");
        ff = GetInt();
        if(ff < 0)
        {
            printf("Digitou valor negativo ou com decimal? Digite novamente\n\n");
        }
    }
    while(ff < 0);
    
    do
    {
        printf("Digite um número inteiro positivo para M procurando M: ");
        mm = GetInt();
        if(mm < 0)
        {
            printf("Digitou valor negativo ou com decimal? Digite novamente\n\n");
        }
    }
    while(mm < 0);
    
    float soma = mf + fm + ff + mm;
    mf = (mf / soma) * 80;
    fm = (fm / soma) * 80;
    ff = (ff / soma) * 80;
    mm = (mm / soma) * 80;
    
    printf("\nQuem procura quem?\n");
    
    printf("\n M procurando F: \n");
        for(int i = 0; i < mf ; i++)
        {
            printf("#");
        }
    
    printf("\n F procurando M: \n");
        for(int i = 0; i < fm ; i++)
        {
            printf("#");
        }
    
    printf("\n F procurando F: \n");
        for(int i = 0; i < ff ; i++)
        {
            printf("#");
        }
    
    printf("\n M procurando M: \n");
        for(int i = 0; i < mm ; i++)
        {
            printf("#");
        }
    printf("\n");  
}
