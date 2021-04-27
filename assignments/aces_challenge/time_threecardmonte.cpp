#include<ctime>
#include<cassert>
#include<cstdio>
#include<string>
#include<iostream>
char threecardmonte(long count, const char* moves);

int main(int argc, char *argv[])
{
  long num_actions;
  char action;


  std::cin >> num_actions;
  assert(std::cin.good());
  assert(num_actions>0);

  std::string str(num_actions,'\0');
  std::cin >> str;
  assert(str.length()==num_actions);

  const char* memory=str.c_str();
  std::cout << "Start...";
  clock_t diff, start = clock();
  char final_location=threecardmonte(num_actions, memory);
  diff = clock() - start;
  std::cout << "End\n";
  int msec = diff * 1000 / CLOCKS_PER_SEC;
  printf("Time: %01d.%03d, Ace Location=%c\n", msec/1000, msec%1000, final_location);
}
