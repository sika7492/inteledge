#include<stdio.h>

int main(){
	int i;
	int j;
	int k;
	for( i =0;i<4;i++){
		for(j=4;j>(i);j--){
			printf(" ");
		}	//end of for j
		for(k=0;k<(2*i)+1;k++){
			printf("*");
		}
		printf("\n");
	
	}//end of for i
			
}//end of main


