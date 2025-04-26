// tamagoshi_cow.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// États de la vache
typedef enum { BYEBYELIFE = 0, LIFESUCKS = 1, LIFEROCKS = 2 } State;

// Variables globales
int stock = 5;    // Réserve initiale
int fitness = 5;  // Santé initiale
int duration = 0; // Durée de vie

// Fonction pour effacer l'écran
void update() {
    printf("\033[H\033[J");
}

// Affichage de la vache selon l'état
void affiche_vache(State state) {
    switch(state) {
        case LIFEROCKS:
            printf(" \\   ^__^    (en pleine forme)\n");
            break;
        case LIFESUCKS:
            printf(" \\   -__-    (mal en point)\n");
            break;
        case BYEBYELIFE:
            printf(" \\   x__x    (rip)\n");
            break;
    }
    printf("  \\  (oo)\\_______\n");
    printf("     (__)\\       )\\/\n");
    printf("         ||----w |\n");
    printf("         ||     ||\n");
}

// Met à jour 'fitness' en fonction de lunchfood et digestion aléatoire [-3,0]
void update_fitness(int lunchfood) {
    int digestion = (rand() % 4) - 3;  // 0, -1, -2, -3
    fitness = fitness + lunchfood + digestion;
    if (fitness < 0) fitness = 0;
    if (fitness > 10) fitness = 10;
}

// Met à jour 'stock' en fonction de lunchfood et crop aléatoire [-3,3]
void update_stock(int lunchfood) {
    int crop = (rand() % 7) - 3;  // -3 .. +3
    stock = stock - lunchfood + crop;
    if (stock < 0) stock = 0;
    if (stock > 10) stock = 10;
}

int main() {
    srand((unsigned)time(NULL)); // Initialisation RNG

    State state = LIFEROCKS;

    do {
        update();
        // Déterminer l'état selon 'fitness'
        if (fitness >= 4 && fitness <= 6) {
            state = LIFEROCKS;
        } else {
            state = LIFESUCKS;
        }
        // Si extrême, la vie s'achève
        if (fitness == 0 || fitness == 10) {
            state = BYEBYELIFE;
            break;
        }

        // Affichage
        affiche_vache(state);
        printf("Stock: %d \n", stock );
        printf("Durée: %d\n", duration);
        printf("Quantité de nourriture à donner (0 à %d) : ", stock);


        int lunchfood;
        scanf("%d", &lunchfood);
        if (lunchfood < 0) lunchfood = 0;
        if (lunchfood > stock) lunchfood = stock;

        // Mise à jour des variables
        update_fitness(lunchfood);
        update_stock(lunchfood);

        duration++;
    } while (state != BYEBYELIFE);

    // Fin du jeu
    update();
    affiche_vache(BYEBYELIFE);
    printf("Game Over! Durée de vie: %d étapes\n", duration);
    return 0;
}