#include<iostream>
#include<fstream>
#include<cstring>
#include<string>

using namespace std;

class creature
{
	public:
	creature()
	{
		hp = 0;
		chp  = 0;
		wep = "none";
		damage = 0;
		spell = "none";
		sdamage = 0;
		xp = 0;
		gp = 0;
	}
private:
int hp;
int chp;
string wep;
int damage;
string spell;
int sdamage;
int xp;
int gp;
};
