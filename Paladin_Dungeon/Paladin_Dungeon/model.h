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
    int minDamage;
    int maxDamage;
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
    int currentLevel;
    int currentExperience;
    int experienceForLevel;
} hero;

typedef struct {
    int strength;
    int intellect;
    int vitality;
    int agility;
} attributes;

typedef struct {
    int armorPenetration;
    int spellPower;
    int criticalStrike;
    int armor;
    int weaponDamage;
} effects;

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
