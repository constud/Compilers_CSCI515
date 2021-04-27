//Version 1.1

//L - swap left and center cards
//R - swap right and center cards
//E - swap edge cards
#include<iostream>
#include<cstdlib>

//dealer seed num_moves
int main(int argc, char* argv[])
{
  if(argc!=3)
  {
    std::cout << "Usage: " << argv[0] << " rand_seed num_moves\n";
    exit(1);
  }
  int seed=strtol(argv[1],0,10);
  srand(seed);
  int num_moves=strtol(argv[2],0,10);

  std::cout << argv[2];
  while(num_moves--)
  {
    switch(rand()%3)
    {
      case 0:
        std::cout << 'L';
        break;
      case 1:
        std::cout << 'R';
        break;
      case 2:
        std::cout << 'E';
        break;
    }
  }
}
