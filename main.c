#include <stdio.h>

/*
 * EJ 11 : Defina una función que convierte una cadena de caracteres, pasada por referencia, a mayúsculas, a excepción de la primera letra de cada palabra, que debe estar en minúsculas.
 */

#define MAX 50

void convertir(char cadena[]);

void convertir(char cadena[MAX])
{
    int i = 0;
    for (i = 0; *(cadena + i) != '\0'; i++)
    {
        if (*(cadena + i) >= 'A' && *(cadena + i) <= 'Z') // Si el caracter es una letra mayúscula
        {
            if (i == 0) // i=0 , primer caracter es mayuscula lo convierto a minuscula (no tiene espacio adelante por ser primer caracter)
                cadena[0] = cadena[0] + 32; // Lo convierte a minúscula

            if (*(cadena + i - 1) == 32)  // Si es Mayuscula y el caracter anterior es un espacio
                *(cadena + i) = *(cadena + i) + 32; // Lo convierte a minúscula
        }
        else if (*(cadena + i) >= 'a' && *(cadena + i) <= 'z')   // Si el caracter es una letra minúscula
        {
            if (i != 0)   // Si i=0 es el primer caracter y es minuscula no lo convierto , si i!=0 , entonces si lo convierto a mayuscula
            {
                if (*(cadena + i - 1) != 32)  // Y ademas el anterior caracter no es un espacio
                    *(cadena + i) = *(cadena + i) - 32; // Lo convierte a mayúscula
            } // En caso de que el anterior caracter sea un espacio la deja en minuscula
        }
    }
}

int main()
{
    char cadena[MAX];
    printf("Ingrese una cadena de caracteres en minuscula y se transformara en mayuscula : \n");
    gets(cadena);
    printf("Texto Original : %s",cadena);
    convertir(cadena);
    printf("\nTexto Modificado : %s",cadena);
    return 0;
}
