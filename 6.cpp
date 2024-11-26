#include<iostream>
#include<queue>
using namespace std;

void findMinMax(const vector<int>& marks){

    if(marks.empty()){
        cout<<"no Marks to proceed";
        return;
    }

    priority_queue<int> maxHeap(marks.begin(),marks.end());

    priority_queue<int, vector<int>, greater<int>> minHeap (marks.begin(),marks.end());

    int minMarks = minHeap.top();
    int maxMarks = maxHeap.top();

    cout<<"Minimum Marks: "<<minMarks<<endl;
    cout<<"Maximum Marks: "<<maxMarks<<endl;

}

int main(){

    vector<int> marks;
    int n;
    cout<<"Enter the number of students:";
    cin>>n;

    cout<<"Enter tjhe marks of the students: ";
    for(int i = 0; i< n; i++){
        int mark;
        cin>>mark;
        marks.push_back(mark);
}

    findMinMax(marks);
    return 0;
}

