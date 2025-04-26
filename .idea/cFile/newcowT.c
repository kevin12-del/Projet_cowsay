// newcowT.c (version avec --tail)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void affiche_vache(const char *eyes, int tail) {
    char e1 = eyes[0], e2 = eyes[1];

    printf(" \\   ^__^\n");
    printf("  \\  (%c%c)\\_______\n", e1, e2);
    printf("     (__)\\       )\\/\n");
    printf("         ||----w |");
    // Allonger la queue
    for (int i = 0; i < tail; i++) {
        printf("-");
    }
    printf("\n");
    printf("         ||     ||\n");
}

int main(int argc, char *argv[]) {
    const char *eyes = "oo";
    int tail = 0;

    for (int i = 1; i < argc; i++) {
        if ((strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--eyes") == 0) && i + 1 < argc) {
            if (strlen(argv[i+1]) == 2) eyes = argv[i+1];
            else { fprintf(stderr, "Yeux : 2 caractères\n"); return 1; }
            i++;
        } else if ((strcmp(argv[i], "--tail") == 0) && i + 1 < argc) {
            tail = atoi(argv[i+1]);
            if (tail < 0) tail = 0;
            i++;
        }
    }
    affiche_vache(eyes, tail);
    return 0;
}