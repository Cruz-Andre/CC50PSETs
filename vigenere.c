/*******************************************************************************
 * vigenere.c - Exercício 3
 *
 * Set de Problemas Semana 2
 * Curso CC50 Introdução à Ciência da Computação de Harvard
 *
 * Criptografar um texto usando a cifra de Vigenere
 * Demonstração de Argumentos de Linha de Comando e String de Caracteres
 ******************************************************************************/

#include <cc50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, string argv[])
{
    // Teste se apenas 1 argumento é digitado e é alfabético
    if (argc != 2)
    {
        printf("\nDigite: ./vigenere e uma palavra \n\n");
        return 1;
    }
    for(int argumento = 0, tamanhoarg = strlen(argv[1]); argumento < tamanhoarg; argumento++)
        {
            if(!isalpha(argv[1][argumento]))
            {
                printf("\nDigite: ./vigenere e uma palavra (somente caractere alfabético) \n\n");
                return 1;
            }
        }

    // Pede ao usuário para digitar um texto que o programa irá criptografar
    printf("\nDigite um Texto para Criptografar: ");

    // Armazena o texto digitado na variável de nome 'texto' em uma 'string'
    string texto = GetString();
    printf("\nTexto Criptografado: "); 

    // Armazena cada caractere (do texto digitado) como um inteiro na variável 'letra'
    for(int letra = 0, chaveletra = 0, tamanhotexto = strlen(texto); letra < tamanhotexto; letra++)
    {
        // Modolo do comprimento da chave (o argumento digitado) pela variável 'chaveletra'
        chaveletra = chaveletra % strlen(argv[1]);
        
        // Verifica se os caracteres do texto digitado são alfabéticos
        if(isalpha(texto[letra]))
        {
        
            // Codificação do texto de acordo com a chave.
            if(isupper(texto[letra]) && isupper(argv[1][chaveletra]))
            {
                printf("%c", (((texto[letra] - 'A') + (argv[1][chaveletra] - 'A')) % 26) + 'A');
            }
            
            else if(isupper(texto[letra]) && islower(argv[1][chaveletra]))
            {
                printf("%c", (((texto[letra] - 'A') + (argv[1][chaveletra] - 'a')) % 26) + 'A');
            }
            
            else if(islower(texto[letra]) && isupper(argv[1][chaveletra]))
            {
                printf("%c", (((texto[letra] - 'a') + (argv[1][chaveletra] - 'A')) % 26) + 'a');
            }
            
            else if(islower(texto[letra]) && islower(argv[1][chaveletra]))
            {
                printf("%c", (((texto[letra] - 'a') + (argv[1][chaveletra] - 'a')) % 26) + 'a');
            }
            
            // Mantem o loop da chave enquanto há caractere do texto para ser codificado.
            chaveletra++;

        }
        // Mantém os outros caracteres que não são letras
        else
        {
            printf("%c", texto[letra]);
        }
    }
    printf("\n\n");
    return 0;
}
