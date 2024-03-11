#include<iostream>
using namespace std;

int main(){
    int *p,size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    p = new int[size];
    if(p==NULL){
        cout<<"Memory not available";
        exit(1);
    }
    for(int i=0;i<size;i++){
        cout<<"Enter the element: ";
        cin>>p[i];
    }
    cout<<"The elements are: ";
    for(int i=0;i<size;i++){
        cout<<p[i]<<" ";
    }
    delete []p;
    return 0;
}