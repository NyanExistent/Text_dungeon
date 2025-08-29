//imports
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//heres the weapons template
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

struct Weapons
{
  float dmg;
  int durabillity;
  float crt_dmg;
  float crt_chance;
  

};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Here are all the struct things
//such as the player, npc, mobs...
//and distructible obcjects..
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


struct Creature {
  //@@@@@@@@@@@@@@@@@@@@@@@@@
  //The level stuff...
  int Lv;
  int Ep;
  int Lv_drain;
  int gold; //just gunna shove this here...
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
  //@@@@@@@@@@@@@@@@@@@@@@@@@
  //The health stuff
  double health_mx;
  double health;
  float hp_reg;
  float hp_decay;
  double temp_hp;
  int armor;
  
  //Weapon in use
  struct Weapons *weapon;

};


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
//prototypes for Functions
//Very important note:
//allways put the functions below the structures
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//

char *get_name(void);   //gets the  player's name
bool inititive(int pl_dex, int mon_dex);
void stat_list(struct Creature player); //prints the player's stat list
int stat_set(int stat_points, struct Creature *player); // lets player sel the stat to inc


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
  
  while (true)
  {
    //@@@@@@@@//
    //Greet the player and get 'usr_name'
    char *plr_name = get_name();
    printf("~~~~~~~~~~~~~~~~~~~~~~~~ \n");


    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //Declare the main player
    struct Creature player;

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
    int pl_stat_pts = 10;

    for (int i = pl_stat_pts; i > 0; i--)
    {
      printf("You have %d stat paint left \n", i);
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
      //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
      //prints the player's stats
      stat_list(player);
      //@@@@@@@@@@@@@@@@@@@@
      //select a stat, and increment it
      stat_set(pl_stat_pts, &player);
    }
    //@@@@@@@@@@@@@@@@
    //print stats again so player can see
    stat_list(player);

    //init player health so the loop can start
    player.health_mx = player.con + player.Lv + 1;
    player.health =  player.health_mx;


    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //The main loop i think...
    //and use rand to get them be more random
    //also init weapons in the loop so they get updated as the player does
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    while (player.health > 0)
    { 


      //@@@@@@@@@@@@@@@@#############@@@@@@@@@@@@@@@@@@@@@
      //Random number
      srand(time(NULL));
      int rnjesus = (rand() % (2 - -2 + 1)) + 0;
      
      //#######################@@@@@@@@@@@@@@@@@##########
      //#######@@@@@@@@@@@@@@#############@@@@@@@@@@@@@@@@
      //INIT WEOPONS HERE
    
      struct Weapons fist = {
        .dmg = 0,
        .durabillity = 10,
        .crt_chance = 95,
        //crt dmg go into the creature
    
      };
      
      struct Weapons pl_fist = {
        .dmg = 0,
        .durabillity = 10,
        .crt_chance = 95,
        //crt dmg go into the creature
    
      };

      //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
      //refresh player max health
      player.health_mx = player.con + player.Lv + 1;
      player.hp_reg = player.con + player.luck + player.Lv;

      //we will do armor here too...
      player.armor = player.luck + player.dex;
      
      //and weapon...
      player.weapon = &pl_fist;
      pl_fist.dmg += player.str;
      pl_fist.crt_dmg += pl_fist.dmg * 2;

  
      
      
      //#######################@@@@@@@@@@@@@@@@@##########
      //#######@@@@@@@@@@@@@@#############@@@@@@@@@@@@@@@@
      //INIT MONSTERS HERE
      srand(time(NULL));

      struct Creature goblin = {

        //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
        //Goblin level, Exp, and gold
        .Lv = player.Lv,
        .Ep = (rand() % (50 - player.luck * goblin.Lv + 1)) + 0,
        .gold = (rand() % (50 - player.luck + 1)) + 0,

        //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
        //Goblin Stats
        .str = 2 + goblin.Lv,
        .con = 3 + goblin.Lv,
        .dex = 2 + goblin.Lv,
        .smarts = 1 + goblin.Lv, 
        .wis = 0 + goblin.Lv,
        .cha = 0 + goblin.Lv,
        .luck = 2 + goblin.Lv,

        //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
        //Goblin health and regen
        .health_mx = goblin.con + goblin.Lv,
        .health = goblin.health_mx,

        .weapon = &fist
  

      };

      //init goblin weapons
      fist.dmg += goblin.str;
      fist.crt_dmg += fist.dmg * 2;

      //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
      //Battle loop
      //refresh the goblin and player health
      //cmp dex to see who goes first
      //fight
      bool playerFirst = inititive(player.dex, goblin.dex);

      while (true)
      { 
        printf("Player Health: %lf \n", player.health);
        printf("Goblin Health: %lf \n", goblin.health);

        //see who goes first
        if (playerFirst == true) //player going first
        { 
          printf("player first \n");
          goblin.health = goblin.health - player.weapon->dmg; //sb dmg from hp
          printf("Goblin Health: %lf \n", goblin.health);

        } else if (playerFirst == false) // goblin goes first
        {
          printf("goblin first \n");
          player.health = player.health - goblin.weapon->dmg;
          printf("Player Health: %lf \n", player.health);
        }

        if (player.health < 1)
        {
          printf("YOU DIED \n");
          printf("Player Health: %lf \n", player.health);
          break;
        }else if (goblin.health < 1)
        {
          printf("GOBLIN SLAIN! \n");
          player.Lv += 1;
          stat_list(player);
          stat_set(1, &player);
          break;
        }

        if (playerFirst == true) {
          playerFirst = false;
        } else if (playerFirst == false)
        {
          playerFirst = true;
        }

        player.health =+ player.hp_reg;
        
        
        
        
      }


  
    }
    

    
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

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//compare dextarity to see who goes first

bool inititive(int pl_dex, int mon_dex) {
  
  bool playerFirst = NULL;
  //flip coin if dex is Equal
  if (pl_dex == mon_dex)
  {
    //random num 1-2
    srand(time(NULL));
    int coin = (rand() % (2 - 1 + 1)) + 1;

    if (coin == 1) //if one player goes first
    {
      playerFirst = true;     
    } else if (coin == 2) //if 2 monster goes first
    {
      playerFirst = false;
    } else printf("ERROR: FAILED TO FLIP CON :(");
  } else if (pl_dex > mon_dex)
  {
    playerFirst = true;
  } else if (pl_dex < mon_dex)
  {
    playerFirst = false;
  } else printf("ERROR: How the hell did you manage this????");

  return playerFirst;

}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//This simply prints the stat options
//i think we'll just have to brute force it...
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

void stat_list(struct Creature player) {

  printf("MAIN STATS: \n");
  printf("Str: %d\n", player.str);
  printf("Con: %d\n", player.con);
  printf("Dex: %d\n", player.dex);
  printf("Int: %d\n", player.smarts);
  printf("Wis: %d\n", player.wis);
  printf("Cha: %d\n", player.cha);
  printf("Luck: %d\n", player.luck);

}; 

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//this lets the player assign stat points
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

int stat_set(int stat_points, struct Creature *player) {

  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  //msg
  printf("Stat to increase: \n");
  printf("~~~~~~~~~~~~~~~~~~~~ \n");

  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  //allocates memory to 'sel'
  char *sel = (char *)malloc(sizeof(char) * 10);

  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  //loops until 'sel' is a valid string
  //then increments the selected stat by one
  //and breaks
  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  while (true)
  {
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //Get usr input, Str, Con, __  
    fgets(sel, 10 , stdin);

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //removes the newline
    //so sel can be cmp'ed
    size_t len = strlen(sel);
    if (len > 0 && sel[len - 1] == '\n') {
        sel[len - 1] = '\0';
    }

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //loops through 'sel'
    //and sets each chat to lowercase
    for (int i = 0; sel[i] != '\0'; i++) {
      sel[i] = tolower(sel[i]);
    }

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //increments the selected stat by one

    if (strcmp(sel, "str") == 0) 
    {
      player->str++;
      break;
    } else if (strcmp(sel, "con") == 0) 
    {
      player->con++;
      break;
    } else if (strcmp(sel, "dex") == 0) 
    {
      player->dex++;
      break;
    } else if (strcmp(sel, "int") == 0) 
    {
      player->smarts++;
      break;
    } else if (strcmp(sel, "wis") == 0) 
    {
      player->wis++;
      break;
    } else if (strcmp(sel, "cha") == 0) 
    {
      player->cha++; 
      break;
    } else if (strcmp(sel, "luck") == 0) 
    {
      player->luck++;
      break;
    }
  }

  free(sel);
}