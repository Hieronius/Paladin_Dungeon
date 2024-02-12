#ifndef functions_h
#define functions_h

void attackEnemy(Hero *attacker, Enemy *target);
void attackHero(Enemy *attacker, Hero *target);
void block(Hero *character);
void heal(Hero *healer);
void magic(Hero *caster, Enemy *target);
void useObject(Hero *user); // I need an inventory for it
void startGame(bool *isAlive);
void moveToEnemy(char hotKey);
void getLevel(Hero *hero);
void enableRawMode(void);
void disableRawMode(void);
Enemy getEnemy(Enemy *array);
Hero getHero(void);

#endif /* functions_h */
