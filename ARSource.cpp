/** Christopher Steinmuller 
Adventure using the Mace Engine v 4.2 (aborted)
Shuriken Engine 1.0
version 1.24
Fixed error in Monster AI
Working on Henchman
Aborted 12-08-2006
due to: Not worth rebuilding
restarted 12-11-2006
due to: Glaive engine 1.0 nonfunctioning
Attempting to use the Shuriken 1.1 engine
*/

#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
//include "Adventurereborn.h"
#include "Adventurereborn.cpp"
using namespace std;


/*
Structs

 struct minion //Ally data//
 {
     int hs,
     hd,
     hsd,
     hhp,
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

*/

/*
Main
**/


int main() 
{
    //system("CLS");
   // system("color 31");
     ifstream infile;
     ifstream indata;
     ifstream mfile;
     ofstream outfile;  
     outfile.open("Scores.doc"); //Score file//
     infile.open("Gameinfo.data"); // spells \ attacks//
     mfile.open("Monsters.data"); //monsters//
     indata.open("Henchmen.data"); //Ally data, not really used//
     minion hench;
     monsterfile MM[size];
     player hero;
     hero.gp=0;
     char direction,    
     dec; 
     int j = 0; 
     bool minions = false,
     alive = true;
     cout<<"Welcome to Adventure Reborn \n"
     <<"Rated E for everyone \n";  
     loadingchar (infile, hero);
     loadingmon (mfile, MM);
     infile.close();
    // system("CLS");
     cohort(indata, hench);
     cout<<"Please input your first name \n";
     cin>>hero.yname;  
   //  system("CLS"); 
     hero.lvl = 1;
     hero.xp = 0;
     hero.pack.potion[1] = 1;
     hero.lxp = 300;
     cout<<"And now your last name. \n";
     cin>>hero.lname;    
   //  system("CLS");
     cout<<" Your gender, M for male, F for female \n";
     cin>>hero.gender;
 //    system("CLS");
     classes(hero);
   //  system("PAUSE");
  //   system("CLS");
     cout<<" You have arrived at the entrance of a cave, in search of treasure. \n"; 
     cout<<"Your stats are: \n hp: "<<hero.hp<<" / "<<hero.xhp<<" \n weapon: "
     <<hero.pack.wep<<" \n damage with weapon: "<<hero.ad<<" \n armor:"<<hero.pack.armor
     <<" \n spell: "<<hero.spell[0]<<" \n spell damage: "<<hero.sd[0]<<"\n level: "<<hero.lvl<<" \n";
   //  system("CLS");
  //   system("PAUSE");
     cout<<" You stand in a swamp, with the castle to the North-East, and a path through"
     <<" the swamp to the north. Which direction do you go? Press N for" 
     <<" the path and E for the front door. \n";
     cin>>direction;
  //   system("PAUSE");
  //   system("CLS");
   //  system("PAUSE");
     if ((direction == 'n')||(direction == 'N'))
     {
     cout<<"You work your way through thick mud to a small pond, along the ruined"
     <<" wall, bubbles come toward you and a "<<MM[0].mname<<" attacks you!!!!";
     alive = fight(hero, MM[0]);
     }
     else if ((direction == 'e')||(direction == 'E'))
     {
     cout<<"You work your way towards the castle but as you near the "
     <<" wall, bubbles come toward you in a pond and a "<<MM[0].mname<<" attacks you!!!!";
      alive = fight(hero, MM[0]);
  //    system("PAUSE");
   //   system("CLS");
      }
      if (alive == false)
      {
      death();
      }
      else if (alive == true)
      {
      repair(hero);   
 //    system("PAUSE");
     cout<<"You see a ruined door and enter, indside are 6"<<MM[1].mname<<"s"
     <<"and 3 "<<MM[2].mname<<"s. You draw your trusty "<<hero.pack.wep;
     alive = fight(hero, MM[1]);
   //   system("PAUSE");
   //      system("CLS");
         if (alive == false)
      {
      death();
      }
      else if (alive == true)
         {
         cout<<" You are victorius, and the monsters lie dead at your feet"
         <<" A further scan of the room indicates that there is a small"
         <<" guard house. Inside is a bag containing a corked bottle"
         <<" That contains a mystic blueish-white fluid, recognizable as a potion"
         <<" of healing.";
     //    system("PAUSE");
         hero.pack.potion[1] = hero.pack.potion[1] +1;
         repair(hero);
         cout<<" Upon exiting the guard house, you hear a clattering noise, "
         <<"peeking your head out of the door, you see another"<<MM[1].mname
         <<" It looks up at you and pulls out its"<<MM[1].mwep;
         alive = fight(hero, MM[1]);
          if (alive == false)
      {
      death();
      }
      else if (alive == true)
          {
             repair(hero);
         //    system("PAUSE");
          //   system("CLS");
             cout<<" Now, you find the mechanism that activates the door,"
             <<" After pulling the lever, the huge stone door to the tower"
             <<" slowly rises to about 20 feet above ground level"
             <<"inside, another "<<MM[1].mname<<" attacks you, catching you unawares";
             alive = fight(hero, MM[1]);
          if (alive == false)
      {
      death();
      }
      else if (alive == true)
          {
             repair(hero);
      //       system("PAUSE");
     //        system("CLS");
             cout<<" After defeating the "<<MM[1].mname<<" you look around. \n"
             <<" You are in a corridor, about 20 feet tall by 10 feet wide, and"
             <<" it turns a corner about 40 feet a head of you. whith a homnoid"
             <<" Shillote in front of you \n";
      //       system("PAUSE");
             cout<<" If you try to talk to the shape, press T, if you want to"
             <<" advance down the corridor without disturbing it, press A \n"; 
             cin>>dec;
        //     system("PAUSE");
             if ((dec == 'T')||(dec == 't'))
             {
                 cout<<"It doesn't answer..., and you walk by cautisusly. \n";
            //     system("PAUSE");
           //      system("CLS");
             }
             else if ((dec == 'A')||(dec == 'a'))
             {  
                cout<<"Oh no... a "<<MM[2].mname<<"!! \n";
                 alive = fight(hero, MM[2]);
          if (alive == false)
      {
      death();
      }
      else if (alive == true)
          {
         //     system("PAUSE");
        //      system("CLS");
                     repair(hero);
               //      system ("PAUSE");      
                     if  (hero.ch == 2)
                     {
                     hero.pack.armor = "suit of plate mail";
                     hero.dr = 4;
                     }
                     else if (hero.ch == 1)
                     {
                     hero.pack.armor = "chain mail shirt";
                     hero.dr = 2;
                     }
                     cout<<" In a wooden chest around the corner you find a "
                     <<hero.pack.armor;
                     }                          
              }
              if (alive == false)
      {
      death();
      }
      else if (alive == true)
              {
                     repair(hero);
               //      system("PAUSE");
                //     system("CLS");
              cout<<" \n The tunnel expands  into a full fledged corridor, and"
              <<" You are attacked by a "<<MM[2].mname<<" Which was standing in the expanded"
              <<" corridor, dragging its feet.";
              alive = fight(hero, MM[2]);
          if (alive == false)
      {
      death();
      }
      else if (alive == true)
          {
           //   system("PAUSE");
          //    system("CLS");
              repair(hero);
              cout<<"You pick your way through the tunnel till you come to a door, unfortuntely \n"
              <<"it is guarded... \n";
          //    system("PAUSE");
          //    system("CLS");
              cout<<" you draw your now rusty "<<hero.pack.wep<<" and see a ";
              cout<<MM[3].mname<<"!! \n";
               alive = fight(hero, MM[3]);
          if (alive == false)
      {
      death();
      }
      else if (alive == true)
          {
                    repair(hero);
                //    system ("PAUSE");     
                //    system("CLS");                         
                    cout<<"You crawl down the tunnel on your knees and enconter"
                    <<" a treasure chest, opening it you find a... \n";
                    hero.pack.wep = "flaming "+hero.pack.wep;
                    hero.ad = hero.ad + 3;
                    //system("PAUSE");
                  //  system("CLS");
                    cout<<hero.pack.wep<<" \n"
                    <<"Uh, oh... a "
                    <<MM[4].mname<<"!! \n";
                    alive = fight(hero, MM[4]);
          if (alive == false)
      {
      death();
      }
      else if (alive == true)
          {
          //    system("PAUSE");
           //   system("CLS");
                        repair(hero);
                   //     system ("PAUSE");
                   //     system("CLS");
                        cout<<" \n You continue down the hallway untill you arrive at"
                        <<" dark, steel, door, sabout 20 feet tall, a "<<MM[3].mname<<" stands guard.";
                        alive = fight(hero, MM[3]);
                        if (alive == false)
      {
      death();
      }
      else if (alive == true)
          {
//              system("PAUSE");
        //      system("CLS");
                        repair(hero);
                   //     system ("PAUSE");
                   //     system("CLS");
                        cout<<" \n you open the door and there, sitting on the "
                        <<" standing in he middle of the room is a "<<MM[5].mname<<" \n";                     
                      //  system("PAUSE");
                        alive = fight(hero, MM[5]);
                        if (alive == false)
      {
      death();
      }
      else if (alive == true)
          {
             // system("PAUSE");
             //       system("CLS");
                    cout<<"On the body of the"<<MM[5].mname<<" you find a key that"
                    <<" fits a door behind him. You open the door and suprise a "
                    <<MM[4].mname<<" It groans and charges";
                    alive = fight(hero, MM[4]);
                        if (alive == false)
      {
      death();
      
      }
      else if (alive == true)
          {
              cout<<"Another "<<MM[4].mname<<" comes from behind it! \n";
             alive = fight(hero, MM[4]);
                        if (alive == false)
      {
      death();
      }
      else if (alive == true)
          {
              cout<<" \n And yet another!!!!";
              alive = fight(hero, MM[4]);
                        if (alive == false)
      {
      death();
      }
      else if (alive == true)
          {
              cout<<" \n And once again, another!!!!";
               alive = fight(hero, MM[4]);
      if (alive == false)
      {
      death();
      }
      else if (alive == true)
          {
          //    system("CLS");
              cout<<"You Win \n";         
              }
              }
              
          }
                    }
                            }
                        }
                   }
                   }        
                   } 
                   }      
                  }
              }
              }    
         } 
      //   system("PAUSE");
      //   system("CLS");
    credits(outfile, hero);
    indata.close();
    mfile.close();
    outfile.close();
  //  system("PAUSE");    
    return 0;
}

