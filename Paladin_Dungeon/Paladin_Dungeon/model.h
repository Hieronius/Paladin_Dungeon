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
    int mentalHealth;
    int spellPower;
    int currentExperience;
    int experiencePerLevel;
    int experiencePerKill;
} character;

typedef struct {
    char name[100];
    int minAttack;
    int maxAttack;
    int defence;
    int currentHealth;
    int maxHealth;
    int currentMana;
    int maxMana;
    int currentEnergy; // cost per hit or spell
    int maxEnergy;
    int currentStamina; // amount of actions to choose per round
    int maxStamina;
    int currentMentalHealth;
    int maxMentalHealth;
    int spellPower; // should be placed to the attributes;
    int currentLevel;
    int currentExperience;
    int experienceForLevel;
} hero;

typedef struct {
    char name[100];
    int attack;
    int defence;
    int health;
    int experiencePerKill;
} enemy;

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
