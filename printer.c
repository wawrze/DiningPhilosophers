#include "printer.h"

// analysing this function can give you a headache
void print(const int *philosopher_states, const int *fork_states) {
    // forks positions: 0 - table, 1 - left plate, 2 - right plate
    // fork 0 - top-left
    // fork 1 - bottom-left
    // fork 2 - bottom
    // fork 3 - bottom-right
    // fork 4 - top-right

    // philosophers states: 0 - eating, 1 - thinking, 2 - waiting for right fork, 3 - waiting for left fork
    // philosopher 0 - top
    // philosopher 1 - left
    // philosopher 2 - right
    // philosopher 3 - bottom-left
    // philosopher 4 - bottom-right

    for (int i = 0;i < 100;i++) {
        printf("\n");
    }
    printf("                   ____\n");
    printf("                  /    \\\n");
    printf("                 /");
    if (fork_states[4] == 1) {
        printf("V");
    } else {
        printf(" ");
    }
    printf("    ");
    if (fork_states[0] == 2) {
        printf("V");
    } else {
        printf(" ");
    }
    printf("\\\n");
    printf("                | ");
    if (fork_states[4] == 1) {
        printf("|");
    } else {
        printf(" ");
    }
    printf(" ");
    switch (philosopher_states[0]) {
        case 0:
            printf("E ");
            break;
        case 1:
            printf("T ");
            break;
        case 2:
            printf("WR");
            break;
        case 3:
            printf("WL");
            break;
        default:
            printf("  ");
            break;
    }
    printf(" ");
    if (fork_states[0] == 2) {
        printf("|");
    } else {
        printf(" ");
    }
    printf(" |\n");
    printf("                 \\");
    if (fork_states[4] == 1) {
        printf("|");
    } else {
        printf(" ");
    }
    printf("    ");
    if (fork_states[0] == 2) {
        printf("|");
    } else {
        printf(" ");
    }
    printf("/\n");
    printf("        ");
    if (fork_states[4] == 0) {
        printf("\\");
    } else {
        printf(" ");
    }
    printf("         \\____/");
    if (fork_states[0] == 0) {
        printf("          /");
    }
    printf("\n         ");
    if (fork_states[4] == 0) {
        printf("\\_");
    } else {
        printf("  ");
    }
    if (fork_states[0] == 0) {
        printf("                     _/");
    }
    printf("\n   ____  ");
    if (fork_states[4] == 0) {
        printf("|");
    } else {
        printf(" ");
    }
    printf("                       ");
    if (fork_states[0] == 0) {
        printf("|");
    } else {
        printf(" ");
    }
    printf("  ____\n");
    printf("  /    \\                           /    \\\n");
    printf(" /");
    if (fork_states[4] == 2) {
        printf("V");
    } else {
        printf(" ");
    }
    printf("    ");
    if (fork_states[3] == 1) {
        printf("V");
    } else {
        printf(" ");
    }
    printf("\\                         /");
    if (fork_states[1] == 2) {
        printf("V");
    } else {
        printf(" ");
    }
    printf("    ");
    if (fork_states[0] == 1) {
        printf("V");
    } else {
        printf(" ");
    }
    printf("\\\n");
    printf("| ");
    if (fork_states[4] == 2) {
        printf("|");
    } else {
        printf(" ");
    }
    printf(" ");
    switch (philosopher_states[4]) {
        case 0:
            printf("E ");
            break;
        case 1:
            printf("T ");
            break;
        case 2:
            printf("WR");
            break;
        case 3:
            printf("WL");
            break;
        default:
            printf("  ");
            break;
    }
    printf(" ");
    if (fork_states[3] == 1) {
        printf("|");
    } else {
        printf(" ");
    }
    printf(" |                       | ");
    if (fork_states[1] == 2) {
        printf("|");
    } else {
        printf(" ");
    }
    printf(" ");
    switch (philosopher_states[1]) {
        case 0:
            printf("E ");
            break;
        case 1:
            printf("T ");
            break;
        case 2:
            printf("WR");
            break;
        case 3:
            printf("WL");
            break;
        default:
            printf("  ");
            break;
    }
    printf(" ");
    if (fork_states[0] == 1) {
        printf("|");
    } else {
        printf(" ");
    }
    printf(" |\n");
    printf(" \\");
    if (fork_states[4] == 2) {
        printf("|");
    } else {
        printf(" ");
    }
    printf("    ");
    if (fork_states[3] == 1) {
        printf("|");
    } else {
        printf(" ");
    }
    printf("/                         \\");
    if (fork_states[1] == 2) {
        printf("|");
    } else {
        printf(" ");
    }
    printf("    ");
    if (fork_states[0] == 1) {
        printf("|");
    } else {
        printf(" ");
    }
    printf("/\n");
    printf("  \\____/                           \\____/\n");
    printf("         ");
    if (fork_states[3] == 0) {
        printf("|_");
    } else {
        printf("  ");
    }
    if (fork_states[1] == 0) {
        printf("                     _|");
    }
    printf("\n        ");
    if (fork_states[3] == 0) {
        printf("/");
    } else {
        printf(" ");
    }
    if (fork_states[1] == 0) {
        printf("                         \\");
    }
    printf("\n       ");
    if (fork_states[3] == 0) {
        printf("/");
    } else {
        printf(" ");
    }
    printf("     ____         ____");
    if (fork_states[1] == 0) {
        printf("     \\");
    }
    printf("\n            /    \\       /    \\");

    printf("\n           /");
    if (fork_states[3] == 2) {
        printf("V");
    } else {
        printf(" ");
    }
    printf("    ");
    if (fork_states[2] == 1) {
        printf("V");
    } else {
        printf(" ");
    }
    printf("\\  ");
    if (fork_states[2] == 0) {
        printf("V");
    } else {
        printf(" ");
    }
    printf("  /");
    if (fork_states[2] == 2) {
        printf("V");
    } else {
        printf(" ");
    }
    printf("    ");
    if (fork_states[1] == 1) {
        printf("V");
    } else {
        printf(" ");
    }
    printf("\\\n");
    printf("          | ");
    if (fork_states[3] == 2) {
        printf("|");
    } else {
        printf(" ");
    }
    printf(" ");
    switch (philosopher_states[3]) {
        case 0:
            printf("E ");
            break;
        case 1:
            printf("T ");
            break;
        case 2:
            printf("WR");
            break;
        case 3:
            printf("WL");
            break;
        default:
            printf("  ");
            break;
    }
    printf(" ");
    if (fork_states[2] == 1) {
        printf("|");
    } else {
        printf(" ");
    }
    printf(" | ");
    if (fork_states[2] == 0) {
        printf("|");
    } else {
        printf(" ");
    }
    printf(" | ");
    if (fork_states[2] == 2) {
        printf("|");
    } else {
        printf(" ");
    }
    printf(" ");
    switch (philosopher_states[2]) {
        case 0:
            printf("E ");
            break;
        case 1:
            printf("T ");
            break;
        case 2:
            printf("WR");
            break;
        case 3:
            printf("WL");
            break;
        default:
            printf("  ");
            break;
    }
    printf(" ");
    if (fork_states[1] == 1) {
        printf("|");
    } else {
        printf(" ");
    }
    printf(" |\n");
    printf("           \\");
    if (fork_states[3] == 2) {
        printf("|");
    } else {
        printf(" ");
    }
    printf("    ");
    if (fork_states[2] == 1) {
        printf("|");
    } else {
        printf(" ");
    }
    printf("/  ");
    if (fork_states[2] == 0) {
        printf("|");
    } else {
        printf(" ");
    }
    printf("  \\");
    if (fork_states[2] == 2) {
        printf("|");
    } else {
        printf(" ");
    }
    printf("    ");
    if (fork_states[1] == 1) {
        printf("|");
    } else {
        printf(" ");
    }
    printf("/\n");
    printf("            \\____/       \\____/\n");
    printf("\nLEGEND:\n");
    printf("E - eating\n");
    printf("T - thinking\n");
    printf("WL - waiting for left fork\n");
    printf("WR - waiting for right fork\n");
}