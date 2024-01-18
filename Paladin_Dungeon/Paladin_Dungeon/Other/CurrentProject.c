//
//  CurrentProject.c
//  Paladin_Dungeon
//
//  Created by Арсентий Халимовский on 08.01.2024.
//

#include <stdio.h>

//void attack(character *attacker, character *target);
//void block(character *character);
//void heal(character *healer);
//void magic(character *caster, character *target);
//void useObject(character *user); // I need an inventory for it
//
//int main(int argc, char **argv) {
//
//    bool isAlive = true;
//    int roundCounter = 0;
//
//    character paladin = {"Hieronius", 10, 5, 100, 50, 80, 2, 100, 30, 0};
//    character goblin = {"goblin", 5, 0, 20, 0, 50, 1, 100, 0, 0};
//    character skeleton = {"skeleton", 7, 0, 25, 0, 55, 1, 100, 0, 0};
//    character ghoul = {"ghoul", 8, 0, 30, 0, 60, 1, 100, 0, 0};
//    character wolf = {"mad wolf", 9, 0, 35, 0, 65, 1, 100, 0, 0};
//    character ork = {"ork", 10, 0, 40, 0, 65, 1, 100, 0, 0};
//
//    character arrayOfCharacters[5] = {goblin, skeleton, ghoul, wolf, ork};
//
//    printf("Enter \'start' to start to game\n");
//
//    char start[5];
//    scanf("%s", start);
//
//    if (strcmp(start, "start") == 0) {
//        printf("Let's start the game\n");
//        isAlive = true;
//    } else {
//        printf("Let's try again\n");
//        exit(-1);
//    }
//
//    while (isAlive) {
//
//        char move[4]; // each iteration of the character array it's starts from here
//        char action[10]; // i can use one variable for all kinds of actions. It's working. I can just add a few of them or few of scanf methods if our paladin has move than one action per round
//
//        for (int i = 0; i < 6; i++) {
//
//            printf("Enter \"move\" to reach a new opponent\n");
//
//            scanf("%s", move);
//
//            if (strcmp(move, "move") == 0) {
//                printf("Prepare to battle, the enemy appeared!\n");
//            } else {
//                printf("Wrong command!\n");
//                exit(-1);
//            }
//
//            while (paladin.health > 0 && ((arrayOfCharacters + i)->health > 0)) {
//
//                printf("%d - round started\n", roundCounter);
//
//                printf("Enter \"attack\" to hit the enemy or \"heal\" to heal yourself\n");
//
//                scanf("%s", action);
//
//                if (strcmp(action, "attack") == 0) {
//                    printf("Successful hit!\n");
//                    attack(&paladin, arrayOfCharacters + i);
//
//                } else if (strcmp(action, "heal") == 0) {
//                    printf("Successful healing!\n");
//                    heal(&paladin);
//
//                } else if (strcmp(action, "magic") == 0) {
//                    printf("Successful casting!\n");
//                    magic(&paladin, arrayOfCharacters + i);
//                }
//                else {
//                    printf("wrong command\n");
//                    exit(-1);
//                }
//                attack(arrayOfCharacters + i, &paladin);
//
//                if (paladin.health < 1) {
//                    printf("You are dead\n");
//                    isAlive = false;
//                    break;
//                } else if ((arrayOfCharacters + i)->health < 1) {
//                    printf("%s has been slain\n", (arrayOfCharacters + i)->name);
//                    break;
//                }
//
//                roundCounter++;
//            }
//            sleep(2);
//            roundCounter = 0;
//        }
//        if (isAlive) {
//            printf("Victory!\n");
//            break;
//        } else {
//            printf("Game over!\n");
//            break;
//        }
//    }
//    return 0;
//}
//
//void attack(character *attacker, character *target) {
//    printf("%s hit's %s and makes %d damage\n", attacker->name, target->name, attacker->attack);
//    target->health = target->health - attacker->attack;
//    printf("%s now has %d points of health\n", target->name, target->health);
//    sleep(1);
//}
//
//void heal(character *healer) {
//    healer->mana = healer->mana - 10;
//    printf("%s heals himself for %d amount of health points and now have %d amount of health and %d amount of mana", healer->name, healer->spellPower, healer->health = healer->health + healer->spellPower, healer->mana);
//
//    sleep(1);
//}
//
//void magic(character *caster, character *target) {
//    caster->mana -= 10;
//    target->health -= 30;
//    printf("%s casts the spell of holy fire on %s and deals %d damage. Now %s has %d amount of mana and %s has %d amount of health\n", caster->name, target->name, 30, caster->name, caster->mana, target->name, target->health);
//    sleep(1);
//}

//void useObject(character *user) {
//    printf("%s used %s and restored / dealt / made an effect", user->name, user)
//}
