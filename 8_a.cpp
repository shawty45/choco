#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& credits, int left , int mid, int right){

    int n1 = mid - left +1;
    int n2 = right - mid;

    vector<int> leftArray(n1),rightArray(n2);

    for(int i = 0; i<n1 ; i++){
        leftArray[i] = credits[left+i];
    }
    for(int j = 0 ; j<n2 ;j++){
        rightArray[j] = credits[mid+1+j];
    }

    int i=0 , j=0 , k=left;

    while(i<n1 && j<n2){
        if(leftArray[i]<= rightArray[j]){
            credits[k++] = leftArray[i++];
        }
        else{
            credits[k++] = rightArray[j++];
        }
    }

    while(i<n1){
        credits[k++] = leftArray[i++];
    }
    while(j<n2){
        credits[k++] = rightArray[j++];
    }

}

void mergeSort(vector<int>& credits, int left, int right){

    if(left<right){

        int mid = (left+right)/2;

        mergeSort(credits,left,mid);

        mergeSort(credits,mid+1,right);

        merge(credits,left,mid,right);
    }
}

int main(){

    int n;
    cout<<"Enter the Number of Students: ";
    cin>>n;

    vector<int> credits(n);
    cout<<"Enter the marks of the students: ";
    for(int i= 0; i<n ;i++){
      cin>>credits[i];
    }

    mergeSort(credits,0,n-1);

    cout<<"Sorted credits --";
    for(int credit : credits){
        cout<<credit<<" ";
    }
    cout<<endl;

    return 0;
}