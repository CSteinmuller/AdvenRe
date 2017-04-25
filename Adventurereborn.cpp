

#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include "adventurereborn.cpp"
         
//Implementation file//
using namespace std;
/*
Structs
*/
 struct minion //Ally data//
 {
     int hs,
     hhp,
     hd,
     hsd,
     hdr;  
     string hspell,
     hwep,
     hname;
};

struct monsterfile //monster data//
{
  char mname[size], 
  mwep[size],
  mspell[size];
  int msd,
  ms,
  mxp,
  mhp,
  md,
  mgp;       
};

struct inventory //inventory//
{
     int potion[2];
     string wep,
     armor;
};  

struct player //player data//
{
     string yname,
     lname,
     chclass; 
     char gender,
     spell[10][25],     
     attack[2][25];
     int hp,
     cad,     
     spellcost[25],
     ch,
     gp,  
     xhp,
     xp,
     lxp,
     dr,
     xs,
     ad,
     sd[25],
     cspl,  
     lvl; 
     inventory pack;
     bool warrior,
     caster;  
};




/*
Functions
*/

/**
This function loads all the attack forms and spell data,
*/
void loadingchar (ifstream& infile, player& hero)
 {
      int j = 0;
      if (!infile)
     {
         cerr<<"Could not open file: Gameinfo.data";
         system("CLS");
         system("PAUSE");
         exit(0);
      }
      while (j < 2)
      {
          infile.getline(hero.attack[j], 24, '\n');
          j++;
      }
      j =0;
     while (j < 6)
     {
         cout<<"loading spells \n";
         system("CLS");
         infile>>hero.sd[j]>>hero.spellcost[j];
         infile.getline(hero.spell[j], size-1, '\n');
         j++;
     }
     j = 0;
}
/**
This function loads monster data
*/ 
 
void loadingmon (ifstream& mfile, monsterfile MM[size])
{
           int j = 0;
           if (!mfile)
     {
         cerr<<"Could not open file: Monsters.data";
         system("CLS");
         system("PAUSE");
         exit(0);
      }
            while (!mfile.eof())
     {
          mfile>>MM[j].mhp>>MM[j].md;
          mfile.getline(MM[j].mname, size-1, '\n');
          mfile>>MM[j].mgp>>MM[j].mxp;
          mfile.getline(MM[j].mwep, size-1, '\n');
          mfile>>MM[j].msd>>MM[j].ms;
          mfile.getline(MM[j].mspell, size-1, '\n');
          j++;
          cout<<" Loading monsters"<<j<<"\n";
          system("CLS");
     }
}
/**
This function chooses the attack form used during the attack
*/               
bool melee (bool warrior, int& ad, char attack[2][25], int cad)  
{
     int dec;
     if (warrior == true)
     {
         cout<<" Select one of the combat attacks"
         <<"\n Press one for "<<attack[0]
         <<"\n Press two for "<<attack[1];
         cin>>dec;
         if (dec == 2)
         {
              ad == 1000000000; 
              return  true;     
          }
          else
          {
              ad = cad;
              return  false;
          }
     }        
 } 
 
 /**
 This function runs combat and houses the 
 rather pitiful monster AI
 */
void combat (player& hero, monsterfile MM)
{
    int cad;
    char dec;  
    int spl;
    bool coup = false;
    while (MM.mhp > 0)
    {
        if (hero.caster == true)
        {
        cout<<"If you want to attack the "<<MM.mname<<" with your "<<hero.pack.wep
        <<" press S, If you want to try to destroy it a  spell press A \n";
        cin>>dec;
        if ((dec == 'S')||(dec == 's'))
        {
            cout<<"You swing your "<<hero.pack.wep<<" at the "<<MM.mname<<" and you hit... \n";
            MM.mhp = MM.mhp -hero.ad;
        }
        else if ((dec == 'A')||(dec == 'a'))
        {
            cout<<"You may cast one of the following spells"
            <<" \n press 1 to cast"<<hero.spell[1]
            <<" \n press 2 to cast"<<hero.spell[2]
            <<" \n press 3 to cast"<<hero.spell[3]
            <<" \n press 4 to cast"<<hero.spell[4]
            <<" \n";
            cin>>spl;
            
            
            cout<<" you release pent up magic energy in a "<<hero.spell[spl]<<" spell...\n";
            MM.mhp = MM.mhp-hero.sd[spl];
            hero.cspl = hero.cspl - hero.spellcost[spl];
        }
        }
        else if (hero.caster == false)
        {
             cad = hero.ad;
             coup = melee(hero.warrior, hero.ad, hero.attack, hero.cad);
             if (coup == true)
             {           
             if (MM.ms == 0) 
             {  
             cout<<"The "<<MM.mname<<" hits you with its "<<MM.mwep<<"... \n";
             if (hero.dr > MM.md)
             {
                 MM.md = 0;
             }
             else if ((hero.dr < MM.md)||(hero.dr == MM.md))
             {
                 hero.hp = hero.hp -(MM.md - hero.dr);
             }
             }
             }
             else if (coup == false)
             {
                  cout<<"You swing your "<<hero.pack.wep<<" at the "<<MM.mname<<" and you hit... \n";
            MM.mhp = MM.mhp -hero.ad;
            }
        if (MM.ms == 0)
        {
            cout<<"The "<<MM.mname<<" hits you with its "<<MM.mwep<<"... \n";
             if (hero.dr > MM.md)
             {
                 MM.md = 0;
             }
             else if ((hero.dr < MM.md)||(hero.dr == MM.md))
             {
                 hero.hp = hero.hp -(MM.md - hero.dr);
             }
        }      
        else if (MM.ms > 0)
        {
             MM.ms = MM.ms - 1;
             cout<<"The "<<MM.mname<<" casts "<<MM.mspell;
             hero.hp = hero.hp - MM.msd;
             }
             cout<<"you have"<<hero.hp<<"hit points remaining\n";
             if (hero.hp > 0)   
             {
            cout<<"You swing your "<<hero.pack.wep<<" at the "<<MM.mname<<" and you hit... \n";
            MM.mhp = MM.mhp -hero.ad;
            hero.ad = cad;
            }
        }
         if (hero.hp < 1)
         {
            MM.mhp = 0;  
            death();
            }
            
         }      
} 

/**
This function handles the process of leveling up
*/
void explvl (player& hero, monsterfile MM)
{ 
    cout<<" \n You defeated the " <<MM.mname<<", but you only have "<<hero.hp<<" hit points left. \n";
    hero.xp = hero.xp + MM.mxp;
    if ((hero.xp == hero.lxp)||(hero.xp > hero.lxp))
    {
       hero.lvl = hero.lvl + 1;
             if (hero.caster == true)
             {
             hero.ad = hero.ad + 1;  
             hero.xs = hero.xs +1;
             hero.cspl = hero.xs;
             hero.xhp = hero.xhp + 2;
             }
             else if (hero.caster == false)
             {
             hero.ad = hero.ad + 2;
             hero.xhp = hero.xhp + 5;
             hero.xs = 0;
             hero.cspl = 0;
             }
             hero.lxp = hero.lxp * 3;
             hero.hp = hero.xhp;
    }
    total(MM.mgp, hero.gp, MM.mxp);
    cout<<"Your stats are: \n hp: "<<hero.hp<<" \n weapon: "<<hero.pack.wep<<" \n damage with weapon: "
    <<hero.ad<<" \n armor:"<<hero.pack.armor<<" \n   mana: "
    <<hero.cspl<<" / "<<hero.xs<<"\n level: "<<hero.lvl<<" \n";
}  
   
/** 
This function houses the point totaler
*/  
void total (int mgp, int& gp, int mxp)
{
     gp = gp + mgp + mxp;
}

/**
This is possibly redundent
This function runs combat and leveling up, it
also determines if the hero is still alive
*/
bool fight(player& hero, monsterfile MM)
 {
     combat(hero, MM);
     if (hero.hp > 0)
     {
     explvl(hero, MM);
     return true;
     }
     else
     {
         return false;
         }
}

/**
This function isn't used
It runs the pathetic ally AI
It also runs the monster AI, and determines if the 
ally is alive or not
*/
bool Henchman (minion& hench, player hero, monsterfile MM)
{
     if (MM.mhp > 0)
        {
             if (MM.ms == 0) 
             {  
             cout<<"The "<<MM.mname<<" hits you with its "<<MM.mwep<<"... \n";
             if (hench.hdr > MM.md)
             {
                 MM.md = 0;
             }
             else if ((hench.hdr < MM.md)||(hench.hdr == MM.md))
             {
                 hench.hhp = hench.hhp -(MM.md - hench.hdr);
             }
             }
        else if (MM.ms > 0)
        {
             MM.ms = MM.ms - 1;
             cout<<"The "<<MM.mname<<" casts "<<MM.mspell;
             hench.hhp = hench.hhp - MM.msd;
             }
             }
     if (hench.hhp >  0)
     {
     return true;
     }
     else if (hench.hhp < 1)
     {
          return false;
          }
     }
     
/**
This function is redundent
It prints the credits
*/
void credits(ofstream& outfile, player& hero)
{
     system("CLS");
     outfile<<"Name:"<<hero.yname<<" "<<hero.lname<<" Class:"<<hero.chclass<<" Point total: "<<hero.gp;
     cout<<" \n See Adventure Reborn II: The Invasion,"
      <<" coming soon to a store near you!!!";
     system("PAUSE");
     system("CLS");
     cout<<"Programmed by: Christopher Steinmuller \n Engine: Shuriken v1.1 \n"
     <<"size 800KB. \n";
} 

/**
Also redundent,
It changes text color for the end of the 
game if the hero dies.
*/
void death()
{
     system("CLS");
     system("color 04");
     cout<<"You are such a loser for dying";
     }
     
/**
This function is used but never implemented
It loads all data relevent to allys
*/
void cohort (ifstream& indata, minion& hench)
 {
         indata>>hench.hhp>>hench.hd>>hench.hname>>hench.hdr>>hench.hwep
         >>hench.hs>>hench.hsd>>hench.hspell;
         cout<<"Loading Cohorts...";
         system("CLS");
         }


/**
This function loads class information
and loads the charcters basic stats
*/
void classes (player& hero)
{
    cout<<" And now your character class: pick from:"
     <<" \n wizard or warrior, type in 1 for spell caster, 2 for warrior \n";
     cin>>hero.ch;
     system("CLS");
     if (hero.ch == 2)
     {
          if ((hero.gender == 'm')||(hero.gender== 'M')) 
          {
          hero.chclass = "knight";
          }
          else if ((hero.gender == 'f')||(hero.gender == 'F'))
          {
          hero.chclass = "Amazon";
          }
          hero.pack.wep = "battleaxe";
          hero.xhp = 20;
          hero.ad = 13;
          hero.pack.armor = "chain mail shirt";
          hero.dr = 2;
          hero.warrior = true;
          hero.pack.potion[2] = 0;
          hero.caster = false;
      } 
      else if (hero.ch == 1)
      {
          if ((hero.gender == 'm')||(hero.gender== 'M')) 
          {
          hero.chclass = "wizard";
          }
          else if ((hero.gender == 'f')||(hero.gender == 'F'))
          {
          hero.chclass = "sorceress";
          }
          hero.pack.wep = "dagger";
          hero.xhp = 8;
          hero.ad = 6;
          hero.pack.armor = "leather jerkin";
          hero.dr = 1;
          hero.pack.potion[2] = 1;
          hero.warrior = false;
          hero.caster = true;
      }
      else
      {
          if ((hero.gender == 'm')||(hero.gender== 'M')) 
          {
          hero.chclass = "Slimeface";
          }
          else if ((hero.gender == 'f')||(hero.gender == 'F'))
          {
          hero.chclass = "fool";
          }
          hero.pack.wep = "spoon";
          hero.xhp = 2;
          hero.ad= 1;
          hero.pack.armor = "none";
          hero.dr = 0;
          hero.pack.potion[2] = 0;
          hero.warrior = false;
          hero.caster = false;
          }
     hero.hp = hero.xhp;  
     if (hero.caster == true)
     {
     hero.xs = 4;
     hero.cspl = hero.xs;
     }
     else if (hero.caster = false)
     {
          hero.xs = 0;
          hero.cspl = hero.xs; 
     system("CLS");
     } 
}

/**
This function runs the use of maintnence potions
*/
void repair(player& hero)
{
 char medic,
 dec;
     if ((hero.pack.potion[1] > 0)&&(hero.hp < hero.xhp))
     {
         cout<<"You may use a potion of healing to heal yourself, will you?";
         cin>>medic;
         if ((medic == 'Y')||(medic == 'y'))
         {
             hero.pack.potion[1] = hero.pack.potion[1] -1;
             hero.hp = hero.xhp;
         }
     }
     if ((hero.pack.potion[2] > 0)&&(hero.cspl < hero.xs))   
     {
      cout<<" Do you wish to replenish your magic using a "
      <<"potion of mana ?  y/n \n";  
      cin>>dec;
      if (dec == 'y')
      {
          hero.pack.potion[2] = hero.pack.potion[2] - 1;
          hero.cspl = hero.xs;
          }
          }
}
