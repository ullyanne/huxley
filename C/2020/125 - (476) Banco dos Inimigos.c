#include <stdio.h>

struct rpg
{
    char nome[21];
    int id, level, vida, ataque, defesa;
};

int main()
{
    int x;

    scanf("%d", &x);

    struct rpg jogo[x];

    for(int i = 0; i < x; i++)
    {
        getchar();
        fgets(jogo[i].nome, 21, stdin);
        printf("Nome: %s", jogo[i].nome);

        scanf("%d%d%d%d%d", &jogo[i].id, &jogo[i].level, &jogo[i].vida, &jogo[i].ataque, &jogo[i].defesa);
        printf("ID: %d\nLevel: %d\nVida: %d\nAtaque: %d\nDefesa: %d\n", jogo[i].id, jogo[i].level, jogo[i].vida, jogo[i].ataque, jogo[i].defesa);
    }

    return 0;
}