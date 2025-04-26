// wildcow.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Efface l'écran
void update() {
    printf("\033[H\033[J");
}

// Positionne le curseur en (x,y)
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

// Affiche la vache à la position pos, avec animation de la langue
void affiche_vache(int pos, int frame) {
    // Dessin statique de la vache
    const char *lines[] = {
        " \\   ^__^",
        "  \\  (oo)\\_______",
        "     (__)\\       )\\/\\",
        "         ||----w |",
        "         ||     ||"
    };
    // Affichage ligne par ligne
    for(int i = 0; i < 5; i++) {
        gotoxy(pos, i + 1);
        printf("%s\n", lines[i]);
    }
    // Animation de la langue ou œil
    if(frame % 2 == 0) {
        gotoxy(pos + 6, 3);
        printf("\\\n");  // langue vers la gauche
    } else {
        gotoxy(pos + 7, 3);
        printf("/\n");   // langue vers la droite
    }
}

int main() {
    int pos = 1, dir = 1;
    int frame = 0;
    // Boucle d'animation (50 frames)
    while(frame < 50) {
        update();
        affiche_vache(pos, frame);
        usleep(200000); // 0.2 seconde
        pos += dir;
        if(pos > 40 || pos < 1) dir = -dir; // rebond
        frame++;
    }
    return 0;
}