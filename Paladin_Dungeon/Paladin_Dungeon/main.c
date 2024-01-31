#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ncurses.h>
#include "model.h"
#include <unistd.h>
#include <time.h>
#include <termios.h>


#define GREEN "\x1b[32m"
#define BLACK "\x1b[30m"
#define RED "\x1b[31m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define YELLOW "\x1b[33m"
#define WHITE "\x1b[0m"
#define SOUND "\a"

#define ARRAY_SIZE 5

void attackEnemy(hero *attacker, enemy *target);
void attackHero(enemy *attacker, hero *target);
void block(hero *character);
void heal(hero *healer);
void magic(hero *caster, enemy *target);
void useObject(hero *user); // I need an inventory for it
void startGame(bool *isAlive);
void moveToEnemy(char hotKey);
void getLevel(hero *hero);
enemy getEnemy(enemy *array);
hero getHero(void);

// Function to enable non-blocking input
void enableRawMode() {
    struct termios raw;
    tcgetattr(STDIN_FILENO, &raw);
    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

// Function to disable raw mode
void disableRawMode() {
    struct termios raw;
    tcgetattr(STDIN_FILENO, &raw);
    raw.c_lflag |= (ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}



int main(int argc, char **argv) {
    
    enableRawMode(); // allows to avoid pressing "Enter" button to get input hotkeys
    
    bool isAlive = true;
    int currentStage = 1; // current game level
    int enemiesPerLevel = 5;
    
    int temp = 10; // without this variable "enemiesPerLevel" is always 0 inside the while loop
    
    hero paladin = getHero();
    
    enemy goblin = {"Goblin", 5, 0, 20, 5};
    enemy skeleton = {"Skeleton", 7, 0, 25, 10};
    enemy ghoul = {"Ghoul", 8, 0, 30, 15};
    enemy wolf = {"Mad Wolf", 9, 0, 35, 20};
    enemy ork = {"Ork", 10, 0, 40, 25};
    
    enemy arrayOfCharacters[ARRAY_SIZE] = {goblin, skeleton, ghoul, wolf, ork};
    
    startGame(&isAlive);

    while (isAlive) {
        
        printf("%d level has begun\n", currentStage);
        
        int roundCounter = 0;

        char move; // each iteration of the character array it's starts from here
        
        char action; // i can use one variable for all kinds of actions. It's working. I can just add a few of them or few of scanf methods if our paladin has move than one action per round
        
        enemy enemy; // there we should use our random function to generate a new enemy and pass to the while cycle

        for (int i = 0; i < enemiesPerLevel; i++) { // amount of rooms to explore
            
            moveToEnemy(move);
            enemy = getEnemy(arrayOfCharacters);

            while (paladin.currentHealth > 0 && (&enemy.health > 0)) {
                
                printf("%s%d%s - round started\n", YELLOW, roundCounter, WHITE);
                
                printf("Enter %s\"A/a\"%s to hit the enemy, %s\"H/h\"%s to heal yourself or %s\"M/m\"%s to cast a spell\n", YELLOW, WHITE, YELLOW, WHITE, YELLOW, WHITE);
                
                action = getchar();
                // action = getch();
                while (action != 'A' && action != 'a' &&
                       action != 'H' && action != 'h' &&
                       action != 'M' && action != 'm') {
                    
                    // scanf("%c", &action);
                    printf("try again\n");
                    action = getchar();
                }
                
                if (action == 'A' || action == 'a') {
                    printf("Successful hit!\n");
                    attackEnemy(&paladin, &enemy);
                    // system("/bin/stty cooked");
                    // scanf("%c", &action); // remove /n from getchar()

                } else if (action == 'H' || action == 'h') {
                    printf("Successful healing!\n");
                    heal(&paladin);
                    // system("/bin/stty cooked");
                    // scanf("%c", &action); // remove /n from getchar()

                } else if (action == 'M' || action == 'm') {
                    printf("Successful casting!\n");
                    // system("/bin/stty cooked");
                    magic(&paladin, &enemy);
                    // scanf("%c", &action); // remove /n from getchar()

                } else {
                    printf("wrong command\n");
                    exit(-1);
                }
                attackHero(&enemy, &paladin);

                if (paladin.currentHealth < 1) {
                    printf("%sYou are dead%s\n", RED, WHITE);
                    isAlive = false;
                    break;
                    
                } else if (enemy.health < 1) {
                    printf("%s has been slain\n", enemy.name);
                    paladin.currentExperience += enemy.experiencePerKill;
                    printf("%s gained %s%d%s amount of experience and now has %s%d%s of experience points\n", paladin.name, YELLOW, enemy.experiencePerKill, WHITE, YELLOW, paladin.currentExperience, WHITE);
                    
                    if (paladin.currentExperience >= paladin.experienceForLevel) {
                        getLevel(&paladin);
                    }
                    break;
                }
                roundCounter++;
            }
            // sleep(2);
            roundCounter = 0;
        }
        if (isAlive) {
            printf("%sStage %d has been cleared!%s\n", YELLOW, currentStage, WHITE);
            // printf("Enter any character and press \"Enter\" to start a new stage\n"); // should be fixed
            currentStage += 1;
            enemiesPerLevel += 5;
//             scanf("%c", &action); // avoid /n for action variable
        } else {
            printf("%sGame over!%s\n", RED, WHITE);
            break;
        }
    }
    disableRawMode(); // removes the effect of enableRawMode()
    return 0;
}

hero getHero(void) {
    hero paladin = {
        "Hieronius", // char name[100];
        100,         // int minAttack;
        100,         // int maxAttack;
        100,         // int defence;
        1000,        // int currentHealth;
        1000,        // int maxHealth;
        500,         // int currentMana;
        500,         // int maxMana;
        200,         // int currentEnergy; - cost per hit or spell
        200,         // int maxEnergy;
        300,         // int currentStamina; // actions per round
        300,         // int maxStamina;
        100,         // int currentMentalHealth;
        100,         // int maxMentalHealth;
        1,           // int currentLevel;
        0,           // int currentExperience;
        100          // int experienceForLevel;
    };
    return paladin;
}

void startGame(bool *isAlive) {
    printf("Enter %s'S/s'%s to start the game\n", YELLOW, WHITE);
    char start;
    start = getchar();
    
    while (start != 'S' && start != 's') {
        // scanf("%c", &start);
        printf("Let's try again\n");
        start = getchar();
    }
    printf("Let's start the game\n");
    *isAlive = true;
    // scanf("%c", &start);
    // system("/bin/stty cooked");
    // sleep(1);
}

void moveToEnemy(char hotKey) {
    printf("Enter %s\"M/m\"%s to move to a new opponent\n", YELLOW, WHITE);
    hotKey = getchar();
    
    while (hotKey != 'M' && hotKey != 'm') {
        // scanf("%c", &hotKey);
        printf("Let's try again\n");
        hotKey = getchar();
    }
    
    printf("Prepare to battle, the enemy...\n");
    // scanf("%c", &hotKey); // remove \n from the getchar() func
    // system("/bin/stty cooked");
    // sleep(1);
}

void attackEnemy(hero *attacker, enemy *target) {
    // sleep(1);
    printf("%s strikes %s and makes %s%d%s damage\n", attacker->name, target->name, RED, attacker->minDamage, WHITE);
    target->health = target->health - attacker->minDamage;
    printf("%s now has %s%d%s points of health\n", target->name, RED, target->health, WHITE);
}

void attackHero(enemy *attacker, hero *target) {
    // sleep(1);
    printf("%s strikes %s and makes %s%d%s damage\n", attacker->name, target->name, RED, attacker->attack, WHITE);
    target->currentHealth = target->currentHealth - attacker->attack;
    printf("%s now has %s%d%s points of health\n", target->name, RED, target->currentHealth, WHITE);
}

void heal(hero *healer) {
    // sleep(1);
    healer->currentMana -= 10;
    healer->currentHealth += 30;
    printf("%s heals himself for %s%d%s health points and now have %s%d%s amount of health and %s%d%s points     of mana\n", healer->name, GREEN, 30, WHITE, GREEN, healer->currentHealth, WHITE, CYAN, healer->currentMana, WHITE);
}

void magic(hero *caster, enemy *target) {
    // sleep(1);
    caster->currentMana -= 10;
    target->health -= 30;
    printf("%s casts the spell of holy fire on %s and deals %s%d%s damage. Now %s has %s%d%s amount of mana and %s has %s%d%s amount of health\n", caster->name, target->name, BLUE, 30, WHITE,  caster->name, CYAN, caster->currentMana, WHITE,  target->name, RED, target->health, WHITE);
}

enemy getEnemy(enemy *array) {
    // sleep(1);
    int n;
    time_t t;
    srand((unsigned)time(&t)); // this constructions is working but i still can't get it
    n = rand() % 5;
    printf("%s appears on the horizon!\n", (array + n)->name);
    return *(array + n);
}

void getLevel(hero *hero) {
    hero->currentExperience = 0;
    hero->minDamage += 2;
    hero->maxDamage += 2;
    hero->maxHealth += 20;
    hero->currentHealth = hero->maxHealth;
    hero->maxMana += 10;
    hero->currentMana = hero->maxMana;
    hero->maxEnergy += 10;
    hero->currentEnergy = hero->maxEnergy;
    hero->maxStamina += 10;
    hero->currentStamina = hero->maxStamina;
    hero->currentLevel += 1;
    hero->experienceForLevel += 20;
    printf("LevelUp! Hero has %s%d%s level!\n", YELLOW, hero->currentLevel, WHITE);
}



