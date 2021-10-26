//définition de plein de trucs
#include <stdio.h>
#define NBL 6
#define NBC 7
int c,l;
int choice;
char game[NBL][NBC];
char x;
int AccountRound = 1;
int next;
char token[] = "ox";
int player = 0; // Joueur 1 = 0, Joueur 2 =1
int good = 0;

//de belles couleurs :)))))))
void red(){
  printf("\033[1;31m");
}
void yellow(){
  printf("\033[1;33m");
}
void white(){
  printf("\033[0;37m");
}
void reset(){
  printf("\033[0m");
}

//fonction initialisant le tab
void InitTab(){
  for (l=0; l<NBL; l++){
      for (c=0; c<NBC; c++){
	game[l][c]='.';
    }
  }
}

//empty le journal d'entrée
void flushstdin() {
  int c;
  while((c = getchar()) != '\n' && c != EOF);}

//def de la fonction affichant le tab
void PrintTab(){
  printf("\n");
  printf("+ - - - - - - - + \n");
  for (l=0; l<NBL; l++){
    printf("|");
    for (c=0; c<NBC; c++){
  printf(" %c", game[l][c]);
    }
  printf(" |\n");
  }
  printf("+ 1-2-3-4-5-6-7 + \n");
}

//Fonction permettant d'empiler les jetons 
int Verif() {
  int exit = 0;
  next = 0;
  while (exit != 1 && next < 5) {
    if (game[next][choice] == '.') {
      next ++;
      exit = 0;
    }
    if (game[next][choice] == 'x' || game[next][choice] == 'o') {
	if (next == 0) {
	  red();
	  printf("\nCette colonne est pleine...\n");
	  reset();
	  exit ++;
	  player=!player;
	  AccountRound--;
	  return 0;
	}
	else {
	  next --;
	  exit ++;
	  return 1;
	}
    }
  }
}

//fonction pour choisir

void choose(){
  int verifyerror;
  printf("%d", verifyerror);

int choose(){
  int scanerror;
  printf("\n");
  while (AccountRound < 42) {
    int good = 0;
    PrintTab();
    yellow();
    printf("\nVotre chiffre: ");
    reset();
    scanerror=scanf("%d", &choice);
    choice--;
    if (choice <= -1, choice >= 7){
    if (scanerror==0){
      flushstdin();
      red();
      printf("\nCe n'est pas un chiffre :(\n");
      reset();
      continue;
    }
    if (choice <= -1 || choice >= 7){
      red();
      printf("\nVeuillez mettre un chiffre entre 1 et 7");
      reset();
      choose();
    }
    good = Verif();
    if (good = 1) {
      game[next][choice]= token[player];
      player = !player;
      AccountRound++;
    }
  }
}

//fonction principale avec le tableau et le choix
int main(void){
  InitTab();
  yellow();
  printf("\nVeuillez choisir un chiffre correspondant à une colonne \n");
  reset();
  choose();
}
