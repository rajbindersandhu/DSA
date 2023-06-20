// To find  two uniques number which are comming int series only one time, wheras others are repwatin 2 times.
// To solve the question first I used xor to all elements on the array.
// then recievd answer contins xor result of the two unique vales, to seprate them.
// First find the first set bit from right
// then separted all the array element which have set bit at same position and xor them with xor result got in first step.
// this way recieved the first number out of 2

#include<iostream>
using namespace std;

int main(){
  int arr[] = {1,5,5,6,2,6};
  int xorRes = 0;
  int size = sizeof(arr)/sizeof(arr[0]);
  for(int i=0;i<size;i++){
    xorRes = xorRes ^ arr[i];
  }
  int setBitPos = 0;
  int temp = xorRes;
  while(temp != 0){
    if((temp&1) == 1){
      cout << "set bit found" <<endl;
      break;
    }
    setBitPos++;
    temp = (temp>>1);
  }
cout << setBitPos <<endl;
  temp = xorRes;
  int num1 = 0;
  for(int i=0;i<size;i++){
    int temp1 = arr[i]>>setBitPos;
    if((temp1 & 1) == 0){
      num1 = num1 ^ arr[i];
    }
  }
  cout << "First number is "<<num1 <<endl;
  cout << "Second number is "<<(xorRes^num1);
}