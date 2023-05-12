// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  countOp = 0;
  first = nullptr;
}

void Train::addCage(bool light) {
  Cage* add = new Cage;
  add->light = light;
  if (nullptr == first) {
    first = add;
    first->next = first;
    first->prev = first;
  } else {
    add->next = first;
    add->prev = first->prev;
    first->prev = add;
    add->prev->next = add;
  }
}

int Train::getLength() {
  Cage* cage = first;
  cage->light = true;
  int count = 1;
  while(cage) {
    cage = cage->next;
    if (cage->light == false) {
      count++;
      countOp++;
    }
    if (cage->light == true) {
      cage->light = false;
      CountOp++;
      for (int i = count; i > 0; i--) {
        cage = cage->prev;
        countOp++;
      }
      if (cage->light == false) {
        return k;
      } else {
        k = 1;
      }
    }
  }
}

int Train::getOpCount() {
  return countOp;
}
