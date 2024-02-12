#ifndef model_h
#define model_h

#include <stdio.h>

typedef struct Hero {
    char name[100];
    int minDamage;
    int maxDamage;
    int accuracy;
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
} Hero;

typedef struct {
    int strength;
    int intellect;
    int vitality;
    int agility;
} Attributes;

typedef struct {
    int armorPenetration;
    int spellPower;
    int criticalStrike;
    int armor;
    int weaponDamage;
} Effects;

typedef struct {
    char name[100];
    int minDamage;
    int maxDamage;
    int accuracy;
    int defence;
    int health;
    int experiencePerKill;
} Enemy;

typedef struct {
    int capacity;
    char *inventory;
    int weight;
} Storage;

typedef struct {
    char *healingSpell;
    char *defensiveSpell;
    char *attackSpell;
    char *meditationSpeel;
} Spells;

typedef struct {
    char *attack;
    char *block;
    char *charge;
    char *parry;
} Skills;

typedef struct {
    char *open;
    char *move;
    char *use;
} Actions;

#endif /* model_h */
