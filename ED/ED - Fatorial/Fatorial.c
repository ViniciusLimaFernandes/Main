#include<stdio.h>;

int numFat(int n){
    if(n == 1) return 1;
    return numFat(n-1)*n;
}

int main(){
    
}