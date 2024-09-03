#include<time.h>
#include<stdio.h>
// clock ,clock(),clock_persec
#include<unistd.h>
//sllep()

int b_search(int num[],int left,int right,int key){
	int middle=0;
	while(left<=right){
		middle=left + (right-left)/2;
		if(num[middle]==key){return middle;
		}
		if(num[middle]>key){
			return b_search(num,left,middle-1,key);
		}
		else{
			return b_search(num,middle+1,right,key);
		}
	}
	return -1;
}
int main() {
	double timespent=0.0;
	clock_t begin=clock();
	int size=0,key=0,found=0;
	printf("enter size of array:");
	scanf("%d",&size);
	int num[size];
	printf("enter elements of array in asencding order:\n");
	for(int i=0;i<size;i++){
		scanf("%d",&num[i]);
	}
	printf("enter the serach elemet");
	scanf("%d",&key);
	found=b_search(num,0,size-1,key);
	if(found==-1){
		printf("element not found\n");
	}
	else{
		printf("element found at index %d\n",found+1);
	}
	clock_t end=clock();
	timespent=timespent + (double(end - begin)/CLOCKS_PER_SEC);
	printf("%f seconds",timespent);
}
