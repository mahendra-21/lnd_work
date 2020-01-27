#include<stdio.h> 

int max_min(unsigned int,unsigned int); 
int main(void) 
{ 
    unsigned int a, b; 
    scanf("%u %u",&a,&b); 
    max_min(a,b); 

    return 0; 
} 

int max_min(unsigned int a,unsigned int b) 
{ 
    int i; 
    for(i=31;i>=0;i--){ 
        if((a>>i)==(b>>i)){ 
            if(i==0){ 
                printf("Both are equal\n"); 
            } 
        } else{ 
            if((a>>i)&1==1){ 
                printf("Maximum is %u\nMinimum is %u\n",a,b); 
                break; 
            } else { 
                printf("Maximum is %u\nMinimum is %u\n",b,a); 
                break; 
            } 
        } 
    } 
} 
