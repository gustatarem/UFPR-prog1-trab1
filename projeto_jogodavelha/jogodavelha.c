#include <stdio.h>
#include <stdlib.h>

// Tabuleiro
char tabuleiro[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

// Opção dos jogadores
char player_option[2];

// Verificação para se a jogada é ou não válida
int valid_play = 0;

// Dificuldade
int difficulty = 0;

// Coordenadas
int line = 0;
int column = 0;

// Vencedor
int winner = 0;

// Verifica se já há um vencedor
int is_winner = 0;

// Verifica se o jogo vai ser contra outro usuário
int local_game = 0;

// Menu do jogo
int menu() {
    int choice = 0;

    printf("Jogo da Velha\n");
    printf("Contra quem você vai jogar?\n");
    printf("1 - Amigo\n");
    printf("2 - Computador\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            return 1;
            break;
        case 2:
            printf("Qual a dificuldade do computador?\n");
            printf("1 - Fácil\n");
            printf("2 - Intermediário\n");
            printf("3 - Difícil\n");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    return 10;
                    break;
                case 2:
                    return 11;
                    break;
                case 3:
                    return 12;
                    break;
                default:
                    printf("Opção inexistente");
            }
        default:
            printf("Opção inexistente");
    }
}

void escolha_simb(char *jog1, char *jog2) {
    *jog1 = 'X';
    *jog2 = 'O';
}

void inicializa_velha() {
    printf("JOGO DA VELHA\n");
    for (int line = 0; line <= 2; line++) {
        for (int column = 0; column <= 2; column++) {
            printf("| %c |", tabuleiro[line][column]);
        }
        if (line != 2) {
            printf("\n---------------\n");
        }
        printf("\n");
    }
}

void escolhas_usuario() {
    printf("\nLinha: ");
    scanf("%d", &line);
    printf("Coluna: ");
    scanf("%d", &column);
}

int jogada_usuario(int lin, int col, char jog) {
    if (tabuleiro[lin][col] == ' ') {
        tabuleiro[lin][col] = jog;
        return 0;
    } else if (lin >= 3 || col >= 3) {
        printf("Fora do tabuleiro! Tente novamente!\n");
        return 1;
    } else {
        printf("Aqui já está preenchido, tente novamente!\n");
    }
    return 2;
}

int jogada_final(char jog) {
    if (tabuleiro[0][0] == jog && tabuleiro[2][2] == jog && tabuleiro[1][1] == ' ') {
        tabuleiro[1][1] = jog;
        return 1;
    } else if (tabuleiro[0][2] == jog && tabuleiro[2][0] == jog && tabuleiro[1][1] == ' ') {
        tabuleiro[1][1] = jog;
        return 1;
    } else if (tabuleiro[1][0] == jog && tabuleiro[1][1] == jog && tabuleiro[1][2] == ' ') {
        tabuleiro[1][2] = jog;
        return 1;
    } else if (tabuleiro[0][0] == jog && tabuleiro[0][1] == jog && tabuleiro[0][2] == ' ') {
        tabuleiro[0][2] = jog;
        return 1;
    } else if (tabuleiro[0][1] == jog && tabuleiro[0][2] == jog && tabuleiro[0][0] == ' ') {
        tabuleiro[0][0] = jog;
        return 1;
    } else if (tabuleiro[1][1] == jog && tabuleiro[1][2] == jog && tabuleiro[1][0] == ' ') {
        tabuleiro[1][0] = jog;
        return 1;
    } else if (tabuleiro[2][0] == jog && tabuleiro[2][1] == jog && tabuleiro[2][2] == ' ') {
        tabuleiro[2][2] = jog;
        return 1;
    } else if (tabuleiro[2][1] == jog && tabuleiro[2][2] == jog && tabuleiro[2][0] == ' ') {
        tabuleiro[2][0] = jog;
        return 1;
    } else if (tabuleiro[0][0] == jog && tabuleiro[1][0] == jog && tabuleiro[2][0] == ' ') {
        tabuleiro[2][0] = jog;
        return 1;
    } else if (tabuleiro[1][0] == jog && tabuleiro[2][0] == jog && tabuleiro[0][0] == ' ') {
        tabuleiro[0][0] = jog;
        return 1;
    } else if (tabuleiro[0][1] == jog && tabuleiro[1][1] == jog && tabuleiro[2][1] == ' ') {
        tabuleiro[2][1] = jog;
        return 1;
    } else if (tabuleiro[1][1] == jog && tabuleiro[2][1] == jog && tabuleiro[0][1] == ' ') {
        tabuleiro[0][1] = jog;
        return 1;
    } else if (tabuleiro[0][2] == jog && tabuleiro[1][2] == jog && tabuleiro[2][2] == ' ') {
        tabuleiro[2][2] = jog;
        return 1;
    } else if (tabuleiro[1][2] == jog && tabuleiro[2][2] == jog && tabuleiro[0][2] == ' ') {
        tabuleiro[0][2] = jog;
        return 1;
    } else if (tabuleiro[0][0] == jog && tabuleiro[0][2] == jog && tabuleiro[0][1] == ' ') {
        tabuleiro[0][1] = jog;
        return 1;
    } else if (tabuleiro[0][0] == jog && tabuleiro[2][0] == jog && tabuleiro[1][0] == ' ') {
        tabuleiro[1][0] = jog;
        return 1;
    } else if (tabuleiro[2][0] == jog && tabuleiro[2][2] == jog && tabuleiro[2][1] == ' ') {
        tabuleiro[2][1] = jog;
        return 1;
    } else if (tabuleiro[0][2] == jog && tabuleiro[2][2] == jog && tabuleiro[1][2] == ' ') {
        tabuleiro[1][2] = jog;
        return 1;
    }
}

void facil(char jog) {
    int computer_line;
    int computer_column;

    for (computer_line = 0; computer_line <= 2; computer_line++) {
        for (computer_column = 0; computer_column <= 2; computer_column++) {
            if (tabuleiro[computer_line][computer_column] == ' ') {
                tabuleiro[computer_line][computer_column] = jog;
                return;
            }
        }
    }
}

void intermediario(char jog) {
    int i = 0;

    is_winner = jogada_final(jog);
    if (is_winner == 1) {
        return;
    }

    int line_aux;
    int column_aux;

    for (; i == 0;) {
        line_aux = rand() % 3;
        column_aux = rand() % 3;
        if (tabuleiro[line_aux][column_aux] == ' ') {
            i = 1;
            tabuleiro[line_aux][column_aux] = jog;
        }
    }
}

void dificil(char jog) {
    // TODO: Implementar dificuldade DIFÍCIL
}

void jogada_computador(char jog, int nivel) {
    if (nivel == 1) {
        facil(jog);
    } else if (nivel == 2) {
        intermediario(jog);
    } else if (nivel == 3) {
        dificil(jog);
    }
}

int verifica_ganhador(char jog) {
    if (tabuleiro[0][0] == jog && tabuleiro[0][1] == jog && tabuleiro[0][2] == jog) {
        return 1;
    }
    if (tabuleiro[1][0] == jog && tabuleiro[1][1] == jog && tabuleiro[1][2] == jog) {
        return 1;
    }
    if (tabuleiro[2][0] == jog && tabuleiro[2][1] == jog && tabuleiro[2][2] == jog) {
        return 1;
    }
    if (tabuleiro[0][0] == jog && tabuleiro[1][0] == jog && tabuleiro[2][0] == jog) {
        return 1;
    }
    if (tabuleiro[0][1] == jog && tabuleiro[1][1] == jog && tabuleiro[2][1] == jog) {
        return 1;
    }
    if (tabuleiro[0][2] == jog && tabuleiro[1][2] == jog && tabuleiro[2][2] == jog) {
        return 1;
    }
    if (tabuleiro[0][0] == jog && tabuleiro[1][1] == jog && tabuleiro[2][2] == jog) {
        return 1;
    }
    if (tabuleiro[0][2] == jog && tabuleiro[1][1] == jog && tabuleiro[2][0] == jog) {
        return 1;
    }
}

// Main
int main() {
    int i = 0;
    i = menu();

    if (i >= 10) {
        switch (i) {
            case 10:
                printf("DIFICULDADE: FÁCIL\n");
                difficulty = 1;
                break;
            case 11:
                printf("DIFICULDADE: INTERMEDIÁRIO\n");
                difficulty = 2;
                break;
            case 12:
                printf("DIFICULDADE: DIFÍCIL\n");
                difficulty = 3;
                break;
        }
    } else {
        printf("JOGO LOCAL\n");
        local_game = 1;
    }

    printf("JOGO DA VELHA\n");
    printf("Com qual forma você vai jogar?\n");
    printf("1 - X\n");
    printf("2 - O\n");
    scanf("%d", &i);

    if (i == 1) {
        escolha_simb(&player_option[0], &player_option[1]);
    } else {
        escolha_simb(&player_option[1], &player_option[0]);
    }

    for (i = 0; i <= 8; i++) {
        system("clear");

        int player_index = i % 2;

        inicializa_velha();
        printf("Jogador %c, sua vez de jogar\n", player_option[player_index]);

        if (player_index == 0 || local_game == 1) {
            do {
                escolhas_usuario();
                valid_play = jogada_usuario(line - 1, column - 1, player_option[player_index]);
                if (valid_play != 0) {
                    printf("Jogada inválida, tente novamente...\n");
                    printf("Jogador %c, sua vez de jogar\n", player_option[player_index]);
                }
            } while (valid_play != 0);
        } else {
            jogada_computador(player_option[player_index], difficulty);
        }

        winner = verifica_ganhador(player_option[player_index]);

        if (winner == 1) {
            system("clear");
            inicializa_velha();
            printf("%c GANHOU!!!\n", player_option[player_index]);
            i = 10;
        }
    }
    if (i == 9) {
        printf("\nEMPATE! DEU VELHA!");
    }
}