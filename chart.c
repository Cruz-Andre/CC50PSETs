/*******************************************************************************
 * chart.c - exercicio 3
 *
 * Set de Problemas Semana 1
 * Curso CC50 Introdução à Ciência da Computação de Harvard
 *
 * André Cruz
 *
 * Gera um gráfico de barras com tamanho máximo de 80 caracteres e proporcional
 * aos valores solicitados
 ******************************************************************************/

#include <cc50.h>
#include <stdio.h>

int
main(void)
{
    // Variáveis
    int mf, fm, ff, mm;

    // Loop 'do while' para garantir que o usuário digite o solicitado.
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
    
    // Calculo: somar os numeros, dividir cada um pelo total e multiplicar por 80
    // A multiplicação por 80 define o quantidade máxima de caracteres do gráfico.
    float soma = mf + fm + ff + mm;
    mf = (mf / soma) * 80;
    fm = (fm / soma) * 80;
    ff = (ff / soma) * 80;
    mm = (mm / soma) * 80;
    
    printf("\nQuem procura quem?\n");
    
    // Loop 'for' para colocar o gráfico de acordo com os calculos das linhas 69 a 73
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
