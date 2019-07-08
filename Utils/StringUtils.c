#include <StringUtils.h>

char *removeStringAcentuation(char *string){
    int i = 0;
    char c = string[i];
    char *stringNotAccented;

    // Percorre a string substituindo os caracteres acentuados por caracteres nao acentuados
    // e armazenando o resultado na string final
    while (c != '\0')
    {
        // A acentuado
        if ((c == 'Ã') || 
            (c == 'Á') || 
            (c == 'Â') || 
            (c == 'À') || 
            (c == 'Ä') 
        ) {
            stringNotAccented[i] = 'A';
        } else if (     // a acentuado
            (c == 'ã') || 
            (c == 'á') || 
            (c == 'â') || 
            (c == 'à') || 
            (c == 'ä') 
        ) {
            stringNotAccented[i] = 'a';
        } else if (     // E acentuado
            (c == 'É') ||
            (c == 'È') ||
            (c == 'Ê') ||
            (c == 'Ë')
        ){
            stringNotAccented = 'E';
        } else if (     // e acentuado
            (c == 'é') ||
            (c == 'è') ||
            (c == 'ê') ||
            (c == 'ë')
        ){
            stringNotAccented = 'e';
        } else if (     // I acentuado
            (c == 'Í') ||
            (c == 'Ì') ||
            (c == 'Î') ||
            (c == 'Ï')
        ){
            stringNotAccented = 'I';
        } else if (     // i acentuado
            (c == 'í') ||
            (c == 'ì') ||
            (c == 'î') ||
            (c == 'ï')
        ){
            stringNotAccented = 'i';
        } else if (     // O acentuado
            (c == 'Ó') ||
            (c == 'Ò') ||
            (c == 'Ô') ||
            (c == 'Ö')
        ){
            stringNotAccented = 'O';
        } else if (     // o acentuado
            (c == 'ó') ||
            (c == 'ò') ||
            (c == 'ô') ||
            (c == 'ö')
        ){
            stringNotAccented = 'o';
        } else if (     // U acentuado
            (c == 'Ú') ||
            (c == 'Ù') ||
            (c == 'Û') ||
            (c == 'Ü')
        ){
            stringNotAccented = 'U';
        } else if (     // u acentuado
            (c == 'ú') ||
            (c == 'ù') ||
            (c == 'û') ||
            (c == 'ü')
        ){
            stringNotAccented = 'u';
        } else {
            stringNotAccented = c;
        }
        i++;
    }
    stringNotAccented[i] = '\0';
}