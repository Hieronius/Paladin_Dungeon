//
//  model.h
//  Paladin_Dungeon
//
//  Created by Арсентий Халимовский on 06.01.2024.
//

#ifndef model_h
#define model_h

#include <stdio.h>

typedef struct {
    char name[100];
    int attack;
    int defence;
    int health;
    int mana;
    int energy; // cost per hit or spell
    int stamina; // amount of actions to choose per round
    int mental;
    int spellPower;
} character;

typedef struct {
    int capacity;
    char *inventory;
    int weight;
} storage;

typedef struct {
    char *healingSpell;
    char *defensiveSpell;
    char *attackSpell;
    char *meditationSpeel;
} spells;

typedef struct {
    char *attack;
    char *block;
    char *charge;
    char *parry;
} skills;

typedef struct {
    char *open;
    char *move;
    char *use;
} actions;

#endif /* model_h */
