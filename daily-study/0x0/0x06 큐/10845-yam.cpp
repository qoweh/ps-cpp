#include "../bits/stdc++.h"
using namespace std;

const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;

void push(int x){
  dat[tail++] = x;
}

void pop(){
  head++;
}

int front(){
  return dat[head];
}

int back(){
  return dat[tail - 1];
}

int main(void) {

}
