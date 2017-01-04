#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
	uint8_t num,res,tmp;
	printf("enter the number");
	scanf("%u",&num);
	printf("Num: %u\n",num);
	tmp=num;
	tmp=tmp<<1;
	printf("tmp<<1: %u\n",tmp);
	tmp=tmp&0b10101010;
	printf("tmp&0b10101010: %u\n",tmp);

	num=num>>1;
	printf("num>>1: %u\n",num);
	num=num&0b01010101;
	printf("num&0b01010101: %u\n",num);

	res=num & tmp;
	printf("switched number: %u\n",res);

	return 0;
}	
