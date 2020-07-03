#include <stdio.h>
#include <string.h>

struct usuarios
{
    int idade, amigos, fotos;
    char nome[51];
    char sexo, estadocivil;
};

int main()
{
    int n;
    int i;

    scanf("%d", &n);

    struct usuarios a[n];

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i].idade);
        printf("Idade: %d\n", a[i].idade);
        getchar();

        fgets(a[i].nome, 51, stdin);
        printf("Nome: %s", a[i].nome);

        scanf(" %c", &a[i].sexo);
        printf("Sexo: %c\n", a[i].sexo);

        scanf(" %c", &a[i].estadocivil);
        printf("Estado Civil: %c\n", a[i].estadocivil);
        
        scanf("%d", &a[i].amigos);
        printf("Numero de amigos: %d\n", a[i].amigos);

        scanf("%d", &a[i].fotos);
        printf("Numero de fotos: %d\n\n", a[i].fotos);

    }

    return 0;
}