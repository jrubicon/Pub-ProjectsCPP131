int recursivelessthan(SNode *ptr, int compare){
int num;
  if (ptr == nullptr){
    if(ptr->data < compare)
      return 1;
    else
      return 0;
  }
  num = recursivelessthan(ptr->next, compare);
    if(ptr->data < compare)
      return num+1;
    else
      return num+0;
}



//difficult without additional parameter
//Dynamic variable to solve issue?
int recursivelessthanForward(SNode *ptr, int compare){
int num;
  if (ptr == nullptr){
      return num;
  }
    if(ptr->data < compare)
      num+=1;
    else
      num+=0;
return recursivelessthanForward(ptr->next, compare);
}
