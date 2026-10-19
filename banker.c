#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,r;
    printf("Enter process");
    scanf("%d",&n);
    printf("enter resource");
    scanf("%d",&r);
    int max[n][r],alloc[n][r],need[n][r];
    int totalresource[r],ava[r];
    int finish[n],safe[n];
    for(int i=0;i<n;i++){
        finish[i]=0;
    }
    printf("Enter requirement");
    for(int i=0;i<n;i++){
        for(int j=0;j<r;j++){
            scanf("%d",&max[i][j]);
        }
    }
    printf("enter allocated matrix");
    for(int i=0;i<n;i++){
        for(int j=0;j<r;j++){
            scanf("%d",&alloc[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    for(int j=0;j<r;j++){
        scanf("%d",&totalresource[j]);
    }
    for(int j=0;j<r;j++){
        int alloctedsum=0;
        for(int i=0;i<n;i++){
            alloctedsum += alloc[i][j];
        }
        ava[j]= totalresource[j]- alloctedsum;
    }
    int count=0;
    while(count<n){
        int found=0;
        for(int i=0;i<n;i++){
            if(finish[i]==0){
                int possible=1;
                for(int j=0;j<r;j++){
                    if(need[i][j]>ava[j]){
                        possible=0;
                        break;
                    }
                }
                if(possible){
                    for(int j=0;j<r;j++){
                        ava[j]+= alloc[i][j];
                    }
                    safe[count++] = i;
                    finish[i]=1;
                    found=1;
                }
            }
        }
        if(found==0){
            printf("system not in safe state");
            return 0;
        }
    }
    printf("Safe seq");
    for(int i=0;i<n;i++){
        printf("P%d",safe[i]);
    }
    
}