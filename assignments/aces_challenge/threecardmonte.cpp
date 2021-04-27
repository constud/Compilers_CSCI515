char threecardmonte(long count, const char* moves)
{
  int card = 2;

  for(int i = 0; i < count; i++){
    if(card == 1 ){
      if(moves[i] == 'L')
        card = 2;
      else if(moves[i] == 'E')
        card = 3;
    }
    else if(card == 2){
      if(moves[i] == 'L')
        card = 1;
      else if(moves[i] == 'R')
        card = 3;
    }
    else{
      if(moves[i] == 'E')
        card = 1;
      else if(moves[i] == 'R')
        card = 2;
    }
  }

  if(card == 1)
    return 'L';
  else if(card == 2)
    return 'C';
  else
    return 'R';
 /* switch(card){
    case 1:
      return 'L';
      break;
    case 2:
      return 'C';
      break;
    case 3:
      return 'R';
      break;
  }*/

  return 'X';
}
