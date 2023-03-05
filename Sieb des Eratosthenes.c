int main(){
    int a, i, j, k, o;
    int arr[250];
    for(i=1; i<250; i++){
        arr[i]=i;
    }
    j = 2;
    while(j<125){
        a = 2*j;
        do{
            arr[a] = 0;
            a += j;
        }while(a<250);
        do{
            j++;
        }while(arr[j]==0);
    }
    for(k=0; k<250; k++){
        if (arr[k]!=0){
            printf("Die %d. Primzahl ist %d\n", ++o, arr[k]);
        }
    }
}
