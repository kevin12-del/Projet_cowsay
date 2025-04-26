// newcow.c (version avec -e/--eyes)
#include <stdio.h>
#include <string.h>

void affiche_vache(const char *eyes) {
    // Eyes doit être exactement 2 caractères
    char e1 = eyes[0];
    char e2 = eyes[1];

    printf(" \\   ^__^\n");
    printf("  \\  (%c%c)\\_______\n", e1, e2);
    printf("     (__)\\       )\\/\n");
    printf("         ||----w |\n");
    printf("         ||     ||\n");
}

int main(int argc, char *argv[]) {
    const char *eyes = "oo"; // Valeur par défaut
    // Parcours des arguments
    for (int i = 1; i < argc; i++) {
        if ((strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--eyes") == 0) && i + 1 < argc) {
            if (strlen(argv[i+1]) == 2) {
                eyes = argv[i+1];
            } else {
                fprintf(stderr, "Erreur: les yeux doivent être 2 caractères.\n");
                return 1;
            }
            i++;
        }
    }
    affiche_vache(eyes);
    return 0;
}