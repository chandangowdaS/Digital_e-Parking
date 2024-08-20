#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int op;
    FILE* fptr;
    fptr=fopen("save.txt","r+");
    if(fptr==NULL){
        perror("fopen\n");
        return 0;
    }
    char arr[40];
    fread(arr,40,1,fptr);
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<setw(40)<<"Welcome to Parking"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    for(int i=0;i<40;i++){
        cout<<setw(2)<<i+1 << " is ";
        //printf("%d is ",i+1);
        if(arr[i]=='0')
            cout<< 'A' <<endl;
        else
            cout<< 'N' <<endl;
    }
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<"\n1. Entry\n2. Exit\nEnter your Choice: ";
    cin>>op;
    switch(op){
        case 1:
            for(int i=0;i<40;i++){
                if(arr[i]=='0'){
                    arr[i]='1';
                    cout<<"Parking alloted at "<< 1+i <<endl;
                    break;
                }
            }
        break;
        case 2:
            cout<<"Enter the parking slot to exit: ";
            int slot;
            cin>>slot;
            arr[slot-1]='0';
            cout<<"Slot "<<slot<<" is freed"<<endl;
            cout<<"Have a nice day"<<endl;
        break;
        default:cout<<"Enter proper Choice"<<endl;
    }
    rewind(fptr);
    fwrite(arr,40,1,fptr);
    fclose(fptr);
}