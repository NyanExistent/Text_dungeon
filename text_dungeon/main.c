//imports
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
//prototypes for Functions
char *get_name(void);

//
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Here are all the struct things
//such as the player, npc, mobs...
//and distructible obcjects..
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//This is the base struct for entites
//used for everything from player to snails 
//or some shit like that

struct Creature {
  //@@@@@@@@@@@@@@@@@@@@@@@@@
  //The level stuff...
  int Lv;
  int Ep;
  int Lv_drain;
  //@@@@@@@@@@@@@@@@@@@@@@@@@
  //The health stuff
  double health;
  float hp_reg;
  float hp_decay;
  double temp_hp;
  //@@@@@@@@@@@@@@@@@@@@@@@@@
  //stats
  int str;
  int con;
  int dex;
  int smarts;
  int wis;
  int cha;
  int luck;
  //@@@@@@@@@@@@@@@@@@@@@@@@@@
};


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//Fuck you person reading my fucking code!
//this is my shit i can comment as i like UwU
//Good luck figuring out How this shit works
//cuz i don't fuckin know~
//jk jk lvu

//@@@@@@@@@@@@@@@@@@//
//This will a text rpg ran in a terminal
//with rolls of dice and shit
//@@@@@@@@@@@@@@@@@@//
int main() {

  bool game_running = true;
  
  while (game_running)
  {
    //@@@@@@@@//
    //Greet the player and get 'usr_name'
    char *plr_name = get_name();
    printf("~~~~~~~~~~~~~~~~~~~~~~~~ \n");


    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //Declare the main player
    //then its lv stuff
    struct Creature player;
    
    player.Lv = 0;
    player.Ep = 0;
    player.Lv_drain = 0;
    player.luck = 0;
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //Set stats to zero so they can be used
    player.str = 0;
    player.con = 0;
    player.dex = 0;
    player.smarts = 0;
    player.wis = 0;
    player.cha = 0;
    player.luck = 0;

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //here we need the player to declare 
    //thier stats, which will effect everything
    int pl_stat_pts = 5;

    for (int i = pl_stat_pts; i > 0; i--)
    {
    printf("You have %d stat paint left \n", pl_stat_pts);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
    stat_list();

    }
    


    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    
    free(plr_name);
    break;
  }
  
  return 0;
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//All the functions
//i'll try to keep them alphibetical or some shit
//don't hold me to it though...
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//this simply gets the player name
char *get_name(void) {
  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  //FunTui looking shit :3
  printf("Welcome to text Dungeon! \n");
  printf("^^^^^^^^^^^^^^^^^^^^^^^^ \n");
  printf("What's your name? \n");

  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  //get the fucking name ->
  //(We really dont need it though...)
  //Heres some notes en shit cuz im still learning
  //char *usr_name = (char *)malloc(sizeof(char) * 30);
  //makes a pointer to some space, like a bocs or somthin
  //then when we use the pointer it puts the data into the box
  //with is returned to a pointer... i think... idfk
  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  char *usr_name = (char *)malloc(sizeof(char) * 30);

  fgets(usr_name, sizeof(usr_name), stdin);
  return usr_name;
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//This simply prints the stat options
//i think we'll just have to brute force it...
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

void stat_list() {

  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  //list the stat options 
  //get length of 'stat_list'
  char *stat_list[] = {"str", "con", "dex", "int",
    "wis", "cha", "luck"};
  int stat_ls_len = sizeof(stat_list);

  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  //
  printf("MAIN STATS: \n");
  for (int i = 0; i < stat_ls_len; i++)
  {
    printf("%s \n", stat_list[i]);
  }
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//this lets the player assign stat points
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

int stat_set(int stat_points, struct Creature player) {

  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  //list the stat options 
  //get length of 'stat_list'
  char *stat_list[] = {"str", "con", "dex", "int",
    "wis", "cha", "luck"};
   int stat_ls_len = sizeof(stat_list);

  printf("Plese decare your stats! \n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~ \n");
  
  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  //
  printf("MAIN STATS: \n");
  for (int i = 0; i < stat_ls_len; i++)
  {
    printf("%s \n", stat_list[i]);
  }
  printf("Stat to increase: ");

}