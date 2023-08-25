#include <iostream>
#include <locale.h>

using namespace std;

const int SIZE = 5;  // Размер игрового поля

class Player {
public:
    int x, y;  // Координата X игрока

    Player(int startX, int startY) {
        x = startX;
        y = startY;
    }
};

class Maze {
public:
    char cells[SIZE][SIZE];  // Массив клеток лабиринта

    Maze() {
        // Инициализация лабиринта
        for (int i = 0; i < SIZE; i++) for (int j = 0; j < SIZE; j++) cells[i][j] = '.';

        // Размещение стен
        cells[1][1] = '#';
        cells[1][2] = '#';
        cells[2][2] = '#';
        cells[3][2] = '#';
        cells[3][3] = '#';
        cells[3][4] = '#';
    }

    void printMaze(Player& player) {
        cout << "=== Лабиринт ===" << endl;

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (i == player.y && j == player.x) cout << 'P';  // Позиция игрока
                else cout << cells[i][j];
                cout << ' ';
            }
            cout << std::endl;
        }
        cout << "============" << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Maze maze;
    Player player(0, 0);  // Начальные координаты игрока

    while (true) {
        maze.printMaze(player);

        char move;
        cout << "Управление (w/a/s/d): ";
        cin >> move;

        // Обработка перемещений
        switch (move) {
        case 'w':
            if (player.y > 0 && maze.cells[player.y - 1][player.x] != '#') player.y--;
            break;
        case 'a':
            if (player.x > 0 && maze.cells[player.y][player.x - 1] != '#') player.x--;
            break;
        case 's':
            if (player.y < SIZE - 1 && maze.cells[player.y + 1][player.x] != '#') player.y++;   
            break;
        case 'd':
            if (player.x < SIZE - 1 && maze.cells[player.y][player.x + 1] != '#') player.x++;          
            break;
        case 'q': 
            return 0;  // Выход из игры
        default:
            cout << "Недопустимый ход!" << endl;
            break;
        }
    }
}

