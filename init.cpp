#include <algorithm>
#include <cstdlib>
#include<iostream>
#include <array>

const int GAME_WIDTH = 5;
const int GAME_HEIGHT = 5;

bool isAlive(bool arrayTest[GAME_HEIGHT][GAME_WIDTH], int y, int x){
  int alive = 0;

  // Test left
  if(x>0 && arrayTest[y][x-1]) alive++;
  // Test right
  if(x<GAME_WIDTH && arrayTest[y][x+1]) alive++;
  // Test top
  if(y>0 && arrayTest[y-1][x]) alive++;
  // Test bottom
  if(y<GAME_HEIGHT && arrayTest[y+1][x]) alive++;

  // Test topLeft
  if(x>0 && y>0 && arrayTest[y-1][x-1]) alive++;
  // Test topRight
  if(x<GAME_WIDTH && y>0 && arrayTest[y-1][x+1]) alive++;
  // Test bottomLeft
  if(x>0 && y<GAME_HEIGHT && arrayTest[y+1][x-1]) alive++;
  // Test bottomRight
  if(x<GAME_WIDTH && y<GAME_HEIGHT && arrayTest[y+1][x+1]) alive++;

  // Print Value
  std::cout << "Count = " << alive << "\n";
  std::cout << "Array[" << y << "][" << x << "]";

  // Die if < 2
  if(arrayTest[y][x] && alive < 2) return false;
  // Alive if 2 or 3
  if(arrayTest[y][x] && (alive == 2 || alive == 3)) return true;
  // Die if > 3
  if(alive > 3)return false;
  // Born if dead and 3 alive
  if(!arrayTest[y][x] && alive == 3) return true;

  return false;
}

// Display function
void displayGame(bool arrayTest[GAME_HEIGHT][GAME_WIDTH]){
  for(int y=0; y<GAME_HEIGHT; ++y){
    for(int x=0; x<GAME_WIDTH; ++x){
      if(arrayTest[y][x])
        std::cout << "⬛";
      else
        std::cout << "⬜";
    }
    std::cout<<"\n";
  }
}

int main()
{
  bool display[GAME_HEIGHT][GAME_WIDTH];
  bool swap[GAME_HEIGHT][GAME_WIDTH];

  // Fill array with False
  for (int i = 0; i < GAME_HEIGHT; ++i) {
    for (int j = 0; j < GAME_WIDTH; ++j) {
      display[i][j] = false;
    }
  }

  int w;
  int h;

  // Get the system time.
   unsigned seed = time(0);

   // Seed the random number generator.
   srand(seed);

  for(int n=0; n<10; n++){
    w = rand() % GAME_WIDTH;
    h = rand() % GAME_HEIGHT;
    //std::cout << w << " w\n";
    //std::cout << h << " h\n";
    //std::cout << "-----------------\n";
    display[h][w] = true;
  }

  // Display arrayTest
  displayGame(display);

  // Conway Test
  for(int i=0; i<GAME_HEIGHT; i++){
    for(int j=0; j<GAME_WIDTH; j++){
      swap[i][j] = isAlive(display, i, j);
    }
  }

  std::cout << "The new graph is: \n";
  displayGame(swap);

  return 0;
}
