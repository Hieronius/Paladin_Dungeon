#include "libraries.h"

#define ARRAY_SIZE 5

// MARK: Current task N1 - implementation of accuracy rating and adding this new mechanics to the attack/spells functions

int main(int argc, char **argv) {
    
    enableRawMode(); // allows to avoid pressing "Enter" button to get input hotkeys
    
    bool isAlive = true;
    int currentStage = 1; // current game level
    int enemiesPerLevel = ARRAY_SIZE;
    
    Hero paladin = getHero();
    
    Enemy goblin = {"Goblin", 5, 10, 75, 0, 20, 5};
    Enemy skeleton = {"Skeleton", 7, 12, 75, 0, 25, 10};
    Enemy ghoul = {"Ghoul", 10, 15, 75, 0, 30, 15};
    Enemy wolf = {"Mad Wolf", 12, 17, 75, 0, 35, 20};
    Enemy ork = {"Ork", 15, 20, 75, 0, 40, 25};

    Enemy arrayOfCharacters[ARRAY_SIZE] = {goblin, skeleton, ghoul, wolf, ork};
    
    // MARK: - Game starts here
    
    startGame(&isAlive);

    // can be implemented in custom func "void gameLoop (bool *isAlive)"
    while (isAlive) {
        
        printf("%d level has begun\n", currentStage);
        
        int roundCounter = 0;

        char move = '\0'; // each iteration of the character array it's starts from here
        
        char action; // i can use one variable for all kinds of actions. It's working. I can just add a few of them or few of scanf methods if our paladin has move than one action per round
        
        Enemy enemy; // there we should use our random function to generate a new enemy and pass to the while cycle

        for (int i = 0; i < enemiesPerLevel; i++) { // amount of rooms to explore
            
            moveToEnemy(move);
            enemy = getEnemy(arrayOfCharacters);

            while (paladin.currentHealth > 0 && (&enemy.health > 0)) {
                
                printf("%s%d%s - round started\n", YELLOW, roundCounter, WHITE);
                
                printf("Enter %s\"A/a\"%s to hit the enemy, %s\"H/h\"%s to heal yourself or %s\"S/s\"%s to cast a spell\n", YELLOW, WHITE, YELLOW, WHITE, YELLOW, WHITE);
                
                action = getchar();

                while (action != 'A' && action != 'a' &&
                       action != 'H' && action != 'h' &&
                       action != 'S' && action != 's') {
                    
                    printf("try again\n");
                    action = getchar();
                }
                
                if (action == 'A' || action == 'a') {
                    attackEnemy(&paladin, &enemy);

                } else if (action == 'H' || action == 'h') {
                    printf("Successful healing!\n");
                    heal(&paladin);

                } else if (action == 'S' || action == 's') {
                    useSpell(&paladin, &enemy);

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
            currentStage += 1;
            enemiesPerLevel += 5;
            paladin.currentHealth = paladin.maxHealth;
            paladin.currentMana = paladin.maxMana;
            paladin.currentEnergy = paladin.maxEnergy;
            paladin.currentStamina = paladin.currentStamina;

        } else {
            printf("%sGame over!%s\n", RED, WHITE);
            break;
        }
    }
    disableRawMode(); // removes the effect of enableRawMode()
    return 0;
}

// MARK: - Functions

Hero getHero(void) {
    Hero paladin = {
        "Hieronius", // char name[100];
        100,         // int minAttack;
        100,         // int maxAttack;
        50,          // int spellPower;
        75,          // int accuracy;
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
        printf("Let's try again\n");
        start = getchar();
    }
    printf("Let's start the game\n");
    *isAlive = true;
    // sleep(1);
}

void moveToEnemy(char hotKey) {
    printf("Enter %s\"M/m\"%s to move to a new opponent\n", YELLOW, WHITE);
    hotKey = getchar();
    
    while (hotKey != 'M' && hotKey != 'm') {
        printf("Let's try again\n");
        hotKey = getchar();
    }
    
    printf("Prepare to battle, the enemy...\n");
    // sleep(1);
}

int calculateHitChance(int accuracy) {
    return (rand() % 100) < accuracy;
}

int calculateDamage(int minDamage, int maxDamage) {
    return (rand() % (maxDamage - minDamage + 1) + minDamage);
}

void attackEnemy(Hero *attacker, Enemy *target) {
    // sleep(1);
    srand(time(NULL));
    
    if (calculateHitChance(attacker->accuracy)) {
        printf("Successful hit!\n");
        int damageDealt = calculateDamage(attacker->minDamage, attacker->maxDamage);
        printf("%s strikes %s and makes %s%d%s damage\n", attacker->name, target->name, RED, damageDealt, WHITE);
        target->health = target->health - damageDealt;
        printf("%s now has %s%d%s points of health\n", target->name, RED, target->health, WHITE);
    } else {
        printf("%s %smissed!%s\n", attacker->name, RED, WHITE);
    }
    
}

void attackHero(Enemy *attacker, Hero *target) {
    // sleep(1);
    srand(time(NULL));
    
    if (calculateHitChance(attacker->accuracy)) {
        int damageDealt = calculateDamage(attacker->minDamage, attacker->maxDamage);
        printf("%s strikes %s and makes %s%d%s damage\n", attacker->name, target->name, RED, damageDealt, WHITE);
        target->currentHealth = target->currentHealth - damageDealt;
        printf("%s now has %s%d%s points of health\n", target->name, RED, target->currentHealth, WHITE);
    } else {
        printf("The %s %smissed!%s\n", attacker->name, RED, WHITE);
    }
}

void heal(Hero *healer) {
    // sleep(1);
    healer->currentMana -= 10;
    healer->currentHealth += healer->spellPower;
    printf("%s heals himself for %s%d%s health points and now have %s%d%s amount of health and %s%d%s points     of mana\n", healer->name, GREEN, 30, WHITE, GREEN, healer->currentHealth, WHITE, CYAN, healer->currentMana, WHITE);
}

void useSpell(Hero *caster, Enemy *target) {
    // sleep(1);
    srand(time(NULL));
    
    caster->currentMana -= 10;
    
    if (calculateHitChance(caster->accuracy)) {
        target->health -= caster->spellPower;
        printf("Successful casting!\n");
        printf("%s casts the spell of holy fire on %s and deals %s%d%s damage. Now %s has %s%d%s amount of mana and %s has %s%d%s amount of health\n", caster->name, target->name, BLUE, 30, WHITE,  caster->name, CYAN, caster->currentMana, WHITE,  target->name, RED, target->health, WHITE);
    } else {
        printf("%s %smissed!%s\n", caster->name, RED, WHITE);
    }
}

Enemy getEnemy(Enemy *array) {
    // sleep(1);
    int n;
    time_t t;
    srand((unsigned)time(&t)); // this constructions is working but i still can't get it
    n = rand() % 5;
    printf("%s appears on the horizon!\n", (array + n)->name);
    return *(array + n);
}

void getLevel(Hero *hero) {
    hero->currentExperience = 0;
    hero->minDamage += 2;
    hero->maxDamage += 2;
    hero->spellPower += 3;
    hero->accuracy += 1;
    hero->maxHealth += 20;
    hero->currentHealth = hero->maxHealth;
    hero->maxMana += 10;
    hero->currentMana = hero->maxMana;
    hero->maxEnergy += 10;
    hero->currentEnergy = hero->maxEnergy;
    hero->maxStamina += 10;
    hero->currentStamina = hero->maxStamina;
    hero->currentMentalHealth = hero->maxMentalHealth;
    hero->currentLevel += 1;
    hero->experienceForLevel += 20;
    printf("LevelUp! Hero has %s%d%s level!\n", YELLOW, hero->currentLevel, WHITE);
}

// Function to enable non-blocking input
void enableRawMode() {
    struct termios raw;
    tcgetattr(STDIN_FILENO, &raw);
    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

// Function to disable non-blocking input
void disableRawMode() {
    struct termios raw;
    tcgetattr(STDIN_FILENO, &raw);
    raw.c_lflag |= (ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}
