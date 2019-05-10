//PROBLEM: The remove function is not working the way it should. The logic seems right,
//         but I can't figure out why nothing's being removed 

void CardList::remove(const Card &c1){
  Node *n = head;
  Node *prev;
  if(n == NULL){
    return;
  }
  if(n->card == c1){
    head = n->next;
    delete n;
  }
  while(n->card != c1){
    prev = n;
    n = n->next;
  }
  prev->next = n->next;
  delete n;
}
