#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main(){
	
	
	for(int i = 0; i < 1000; i ++){
		int x = rand() % 19 + 1;
		cout << x;
		cout << " ";
	}
}