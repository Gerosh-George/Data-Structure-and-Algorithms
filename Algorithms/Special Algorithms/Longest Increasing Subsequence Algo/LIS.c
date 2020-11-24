#include<stdio.h>
#define INPUT_LENGTH 14

int length[INPUT_LENGTH];
int sub[INPUT_LENGTH];
int max_len;

void init(){
    for(int i=0;i<INPUT_LENGTH;i++){
        length[i]=1;
        sub[i]=-1;
    }
}

int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}

void lis(int arr[],int i){
   if(i==INPUT_LENGTH){
       return;
   }
   else{
        for (int j = 0; j < i; j++)
        {
            if(arr[j]>=arr[i])
            continue;
            else{
                int temp=length[i];
                length[i]=max(length[i],length[j]+1);
                if(length[i]==(length[j]+1) && temp!=length[i])
                //if(length[i]==(length[j]+1))
                sub[i]=j;
            }
        }
    }
   
   lis(arr,i+1);
}

int max_in_length(){
    int max=0;
    int index=-1;
    for(int i=0;i<INPUT_LENGTH;i++){
        if(length[i]>max){
            max=length[i];
            index=i;
        }
    }
    max_len=max;
    return index;
}

void display(int arr[]){
    int i=max_in_length();
    int lis_array[max_len];
    int k=max_len-1;
    lis_array[k]=arr[i];
    while(i!=-1){
        i=sub[i];
        k=k-1;
        lis_array[k]=arr[i];
    }

    for(int i=0;i<max_len;i++){
        printf("%d ",lis_array[i]);
    }
}

void display_array(int arr[]){
    //printf("\n");
    for(int i=0;i<14;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    init();

    //int input[INPUT_LENGTH]={0, 4, 12, 2, 10, 6, 9, 13, 3, 11, 7, 15};
    //answer: 0 2 6 9 11 15
    int input[INPUT_LENGTH]={0, 5, 2, 1, 4, 7, 6, 5, 14, 16, 3, 7, 8, 9};

    lis(input,1); 
    
    printf("Input: ");
    display_array(input);
    printf("\n");
    printf("Output: ");
    display(input);  
   

}