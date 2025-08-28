//imports
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
//prototypes for Functions
char *get_name(void);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
//prototypers for structs
//and objects
struct Advenurer;

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
  
  //@@@@@@@@//
  //important variables
  bool game_running = true;
  
  while (game_running)
  {
    //@@@@@@@@//
    //Greet the player and get 'usr_name'
    char *player = get_name();
    printf("~~~~~~~~~~~~~~~~~~~~~~~~ \n");

    
    
    
    
    free(player);
    break;
  }
  
  return 0;
}



//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Here are all the struct things
//such as the player, npc, mobs...
//and distructible obcjects..
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//this is the player..
//Holds player lever data, stats and other shit

struct Advenurer {
  //@@@@@@@@@@@@@@@@@@@@@@@@@
  //The player level stuff...
  int pl_Lv;
  int pl_Ep;
  int pl_Lv_drain;
  int pl_luck;
  //@@@@@@@@@@@@@@@@@@@@@@@@@
  //The player health stuff
  double pl_health;
  float pl_regen;
  float pl_he_decay;


};


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//All the functions
//i'll try to keep them alphibetical or some shit
//don't hold me to it though...
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



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