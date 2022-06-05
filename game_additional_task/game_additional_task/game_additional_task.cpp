#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

struct ACTOR {
    std::string name;
    int health;
    int armor;
    int damage;
    int x;
    int y;
    bool is_dead;
};

void show(char field[][20], std::vector<ACTOR> Enemy, ACTOR personage);
void step_enemy(char field[][20], std::vector<ACTOR> &Enemy);
bool win(std::vector<ACTOR>& Enemy);
void attack(char field[][20], std::vector<ACTOR>& Enemy, ACTOR personage);

int main()
{   
    srand(time(0));

    ACTOR personage;
    std::cout << "Enter name personage: ";
    std::cin >> personage.name;
    std::cout << "Enter the amount of health of the character: ";
    std::cin >> personage.health;
    std::cout << "Enter the amount of armor of the character: ";
    std::cin >> personage.armor;
    std::cout << "Enter the amount of damage of the character: ";
    std::cin >> personage.damage;
    personage.x = (rand() % 20);
    personage.y = (rand() % 20);
    personage.is_dead = false;

    std::vector<ACTOR> Enemy;
    for (int i = 0; i < 5; ++i) {
        ACTOR enemy;
        enemy.name = "Enemy#" + std::to_string(i + 1);
        enemy.health = rand() % 101 + 50;
        enemy.armor = rand() % 51;
        enemy.damage = rand() % 16 + 15;
        enemy.x = (rand() % 20);
        enemy.y = (rand() % 20);
        enemy.is_dead = false;
        Enemy.push_back(enemy);
    }

    char field[20][20];
    show(field, Enemy, personage);

    while (win(Enemy))
    {
        std::cout << "x: " << personage.x << " " << "y: " << personage.y << "\n";
        std::cout << "Enter command: ";
        char command;
        std::cin >> command;

        if (command == 'w') {
            personage.y -= 1;
        }
        else if (command == 's') {
            personage.y += 1;
        }
        else if (command == 'd') {
            personage.x += 1;
        }
        else if (command == 'a') {
            personage.x -= 1;
        }
        attack(field, Enemy, personage);
        step_enemy(field, Enemy);
        show(field, Enemy, personage);
    }
}

// Показ поля с игроками
void show(char field[][20], std::vector<ACTOR> Enemy, ACTOR personage) {
    // Заполнение поля точками
    for (int y = 0; y < 20; ++y) {
        for (int x = 0; x < 20; ++x) {
            field[y][x] = '.';
        }
    }
    // Добавление на поле врагов
    for (int i = 0; i < Enemy.size(); ++i) {
        for (int y = 0; y < 20; ++y) {
            for (int x = 0; x < 20; ++x) {
                if (Enemy[i].y == y && Enemy[i].x == x && Enemy[i].is_dead != true) {
                    field[y][x] = 'E';
                }
            }
        }
    }
    // Добавление на поле героя
    for (int y = 0; y < 20; ++y) {
        for (int x = 0; x < 20; ++x) {
            if (personage.y == y && personage.x == x) {
                field[y][x] = 'P';
            }
        }
    }
    //Вывод поля на экран
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            std::cout << field[i][j];
        }
        std::cout << "\n";
    }
}

// Ход врагов
void step_enemy(char field[][20], std::vector<ACTOR> &Enemy) {
    for (int i = 0; i < Enemy.size(); ++i) {
        int temporary_variable = rand() % 2;
        if (temporary_variable == 0) {
            temporary_variable = rand() % 3 - 1;
            Enemy[i].x += temporary_variable;
        }
        else {
            temporary_variable = rand() % 3 - 1;
            Enemy[i].y += temporary_variable;
        }
    }
}

void attack(char field[][20], std::vector<ACTOR> &Enemy, ACTOR personage) {
    for (int i = 0; i < 5; ++i) {
        for (int y = 0; y < 20; ++y) {
            for (int x = 0; x < 20; ++x) {
                if (Enemy[i].x == personage.x and Enemy[i].y == personage.y) {
                    Enemy[i].is_dead = true;
                }
            }
        }
    }
}

bool win(std::vector<ACTOR>& Enemy) {
    bool result = true;
    for (int i = 0; i < 5; ++i) {
        if (Enemy[i].is_dead == true) {
            result = false;
            break;
        }
    }
    return result;
}