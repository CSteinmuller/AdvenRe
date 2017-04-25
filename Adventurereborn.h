#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
/*
Header file for Adventure Reborn.
This file contains protoypes of all the functions and structures
used in Adventure Reborn and the Shuriken engine.
**/

using namespace std;

const int size = 25;

/*
Structs
**/
struct inventory;

struct minion;

struct monsterfile;

struct player;



/*
Functions
**/
void loadingchar (ifstream& infile, player& hero);

void loadingmon (ifstream& mfile, monsterfile MM[size]);

void cohort (ifstream& indata, minion& hench);
 
bool fight(player& hero, monsterfile MM);

bool melee (bool warrior, int& ad, char attack[2][25], int cad);

void mana (int& pom,int xs,int& cspl);

void display (inventory& pack);
 
void combat (player& hero, monsterfile MM);

void explvl (player& hero, monsterfile MM);  

bool Henchman (minion& hench, player hero, monsterfile MM);

void total (int mgp, int& gp, int xp);

void classes (player& hero);

void credits(ofstream& outfile, player& hero);

void death();

void repair(player& hero);

