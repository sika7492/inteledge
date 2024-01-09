#include<stdio.h>
#include"student.h"

int main(int argc,char* argv[]){
	struct student rec;
	FILE *fp;
	if(argc !=2){
		fprintf(stderr,"사용법: %s파일이름\n",argv[0]);
		return 1;
	}	//end of if argc 가 입력이 없을때
	fp=fopen(argv[1],"w");
	printf("%-9s %-7s %-4s\n","학번","이름","점수");
	while(scanf("%d %s %d",&rec.id,rec.name,&rec.score)==3)
		fprintf(fp,"%d %s %d ",rec.id,rec.name,rec.score);
	fclose(fp);
	return 0;
}
