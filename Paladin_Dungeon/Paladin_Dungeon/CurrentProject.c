//
//  CurrentProject.c
//  Paladin_Dungeon
//
//  Created by Арсентий Халимовский on 08.01.2024.
//

#include <stdio.h>

//void attack(character *attacker, character *target);
//void block(character *character);
//
//int main(int argc, char **argv) {
//
//    bool isAlive;
//    int roundCounter = 0;
//
//    character paladin = {"Hieronius", 10, 5, 100, 50, 80, 2, 100};
//    character goblin = {"goblin", 5, 0, 20, 0, 50, 1, 100};
//    character skeleton = {"skeleton", 7, 0, 25, 0, 55, 1, 100};
//    character ghoul = {"ghoul", 8, 0, 30, 0, 60, 1, 100};
//    character wolf = {"mad wolf", 9, 0, 35, 0, 65, 1, 100};
//    character ork = {"ork", 10, 0, 40, 0, 65, 1, 100};
//
//    character arrayOfCharacters[6] = {paladin, goblin, skeleton, ghoul, wolf, ork};
//
//    printf("Enter \'Start' to start to game\n");
//
//    char start[5];
//    scanf("%s", start);
//
//    if (strcmp(start, "Start") == 0) {
//        printf("Let's start the game\n");
//        isAlive = true;
//    } else {
//        printf("Let's try again\n");
//        exit(-1);
//    }
//
////     while (isAlive) {
//
//    for (int i = 0; i < 6; i++) {
//
//        while (paladin.health > 0 && (*(arrayOfCharacters + i)->health > 0)) {
//
//            printf("%d - round started\n", roundCounter);
//
//            if (paladin.health < 0) {
//                printf("You are dead\n");
//                isAlive = false;
//            } else if (goblin.health < 0) {
//                printf("Goblin has been slain\n");
//                break;
//            }
//            attack(&paladin, &goblin);
//            attack(&goblin, &paladin);
//
//            roundCounter++;
//        }
//
//        roundCounter = 0;
//
//    }
//
//        // Now i should think and define how i should proceed the rounds and movements
//        // How about the while cycle until someone dead?
//
////     }
//    printf("Game over\n");
//    return 0;
//}
//
//void attack(character *attacker, character *target) {
//    printf("%s hit's %s and makes %d damage\n", attacker->name, target->name, attacker->attack);
//    target->health = target->health - attacker->attack;
//    printf("%s now has %d points of health\n", target->name, target->health);
//    sleep(1);
//}
