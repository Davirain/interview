#include <iostream>

using namespace std;

int function(int data[], int length){
  int currentAxis;
  int currentNum = 0;
  for(int i = 0; i < length; i++){
    if(currentNum == 0){
      currentAxis = data[i];
      currentNum = 1;
    }
    else{
      if(currentAxis == data[i]) currentNum++;
      else currentNum--;
    }
  }
  return currentAxis;
}
int main(){
  int data[] = {0, 1, 2, 1, 1};
  int axis = function(data, 5);
  printf("%d\n", axis);
}