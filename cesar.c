/*******************************************************************************
 * cesar.c - Exercício 2
 *
 * Set de Problemas Semana 2
 * Curso CC50 Introdução à Ciência da Computação de Harvard
 *
 * Criptografar um texto usando a cifra de César
 * Demonstração de Argumentos de Linha de Comando e String de Caracteres
 ******************************************************************************/

#include <cc50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char *argv[])
{
    // Testa se foi digitado apenas 1 argumento e é um número inteiro positivo
    if (argc == 2 && isdigit(*argv[1]))
    {
        // Pega o argumento digitado e transforma em um inteiro e armazena na variável 'chave' do tipo 'int'
        int chave = atoi (argv[1]);

        // Pede ao usuário para digitar um texto que o programa irá criptografar
        printf("\nDigite um Texto para Criptografar: ");

        // Armazena o texto digitado na variável de nome 'texto' do tipo 'char'
        char* texto = GetString();
        printf("\nTexto Criptografado: ");

        // Pega cada caractere digitado no texto e adiciona cada uma na variável 'letra' do tipo 'int'
        for(int letra = 0, tamanhotexto = strlen(texto); letra < tamanhotexto; letra++)
        {

            // Roda cada letra em Maiúsculas de acordo com o número digitado no argumento
            if(isupper(texto[letra]))
            {
                printf("%c", (((texto[letra] + chave) - 65) % 26) + 65);
            }

            // Roda cada letra em Minúsculas de acordo com o número digitado no argumento
            else if(islower(texto[letra]))
            {
                printf("%c", (((texto[letra] + chave) - 97) % 26) + 97);
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

    else
    {
        printf("\nDigite: ./caesar e um Número Inteiro Positivo\n\n");
        return 1;
    }
}
