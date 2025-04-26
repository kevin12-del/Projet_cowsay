// reading_cow.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Efface l'écran
void update() {
    printf("\033[H\033[J");
}

// Affiche une bulle de texte autour de msg
void affiche_bulle(const char *msg, const char *next) {
    int len = strlen(msg);
    // Dessus de la bulle
    printf(" ");
    for(int i = 0; i < len + 2; i++) printf("_");
    printf("\n");
    // Ligne du message
    printf("< %s >\n", msg);
    // Bas de la bulle
    printf(" ");
    for(int i = 0; i < len + 2; i++) printf("-");
    printf("\n");

    printf(" \\   ^__^\n");
        printf("  \\  (oo)\\_______\n");
        printf("     (__)\\       )\\/\n");
        printf("       %s  ||----w |\n", next);
        printf("         ||     ||\n");

}



int main(int argc, char *argv[]) {
    FILE *fp = stdin;
    if(argc > 1) {
        fp = fopen(argv[1], "r");
        if(!fp) {
            perror("fopen");
            return 1;
        }
    }
    char buffer[1024] = {0};
    char buffer1[1024] = {0};
    char ch;
    char next[2] = {0};

    // Lecture caractère par caractère
    while((ch = fgetc(fp)) != EOF) {
        size_t len = strlen(buffer);
        if(len < sizeof(buffer) - 1) {
            buffer[len] = ch;
            buffer[len + 1] = '\0';
        }

        if (len > 0) {
            buffer1[0] = ' ';
            for (int i = 0; i < len; i++) {
                buffer1[i + 1] = buffer[i];
            }
            buffer1[len + 2] = '\0'; // Finir proprement
            next[0] = buffer[len];
        } else {
            buffer1[0] = '\0';
            next[0] = ' ';
        }
        next[1] = '\0'; // Finir next aussi

        update();
        affiche_bulle(buffer1, next);
        sleep(1); // pause 1 seconde
    }


    if(fp != stdin) fclose(fp);
    return 0;
}