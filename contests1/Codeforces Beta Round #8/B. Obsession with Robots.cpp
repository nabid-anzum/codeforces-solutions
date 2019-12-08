#include <iostream>
#include <map>
 
int main(){
  int x=200,y=200;
  std::map<int,int>M{{x<<16|y,1}};
  for(char c;std::cin>>c;){
    ++M[x+1<<16|y];
    ++M[x-1<<16|y];
    ++M[x<<16|y+1];
    ++M[x<<16|y-1];
    c=='R'?++x:c=='L'?--x:c=='U'?++y:--y;
    if(M[x<<16|y]>1)return std::cout<<"BUG\n",0;
  }
  std::cout<<"OK\n";
}
