#include "StringUtils.h"

char *removeStringAccentuation(char *string){

    int i = 0;
    char c = string[i];

    // Percorre a string substituindo os caracteres acentuados por caracteres nao acentuados
    // e armazenando o resultado na string final
    while (string[i] != '\0')
    {
        // A acentuado
        if ((c == 'Ã') ||
            (c == 'Á') ||
            (c == 'Â') ||
            (c == 'À') ||
            (c == 'Ä')
        ) {
            string[i] = 'A';
        } else if (     // a acentuado
            (c == 'ã') ||
            (c == 'á') ||
            (c == 'â') ||
            (c == 'à') ||
            (c == 'ä')
        ) {
            string[i] = 'a';
        } else if (     // E acentuado
            (c == 'É') ||
            (c == 'È') ||
            (c == 'Ê') ||
            (c == 'Ë')
        ){
            string[i] = 'E';
        } else if (     // e acentuado
            (c == 'é') ||
            (c == 'è') ||
            (c == 'ê') ||
            (c == 'ë')
        ){
            string[i] = 'e';
        } else if (     // I acentuado
            (c == 'Í') ||
            (c == 'Ì') ||
            (c == 'Î') ||
            (c == 'Ï')
        ){
            string[i] = 'I';
        } else if (     // i acentuado
            (c == 'í') ||
            (c == 'ì') ||
            (c == 'î') ||
            (c == 'ï')
        ){
            string[i] = 'i';
        } else if (     // O acentuado
            (c == 'Ó') ||
            (c == 'Ò') ||
            (c == 'Ô') ||
            (c == 'Ö')
        ){
            string[i] = 'O';
        } else if (     // o acentuado
            (c == 'ó') ||
            (c == 'ò') ||
            (c == 'ô') ||
            (c == 'ö')
        ){
            string[i] = 'o';
        } else if (     // U acentuado
            (c == 'Ú') ||
            (c == 'Ù') ||
            (c == 'Û') ||
            (c == 'Ü')
        ){
            string[i] = 'U';
        } else if (     // u acentuado
            (c == 'ú') ||
            (c == 'ù') ||
            (c == 'û') ||
            (c == 'ü')
        ){
            string[i] = 'u';
        } else {
            string[i] = c;
        }
        i++;
        c = string[i];
    }
    string[i] = '\0';
    return string;
}
