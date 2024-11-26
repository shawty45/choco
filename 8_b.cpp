#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct Student{
    string name;
    int credits;
};

int partition(vector<Student>& students, int low, int high){

    int pivot = students[high].credits;
    int i = low-1;

    for(int j = low; j<high; j++){
        if(students[j].credits > pivot){
            i++;
            swap(students[i],students[j]);
        }
    }

    swap(students[i+1],students[high]);
    return i+1;
}

void quickSort(vector<Student>& students, int low , int high){
    if(low < high){
        int pi = partition(students,low,high);

        quickSort(students, low ,pi-1);
        quickSort(students,pi+1,high);
    }
}

void displayTopStudents(const vector<Student>& students){

    cout<<"Top 3 students: "<<endl;
    int count = min(3,static_cast<int>(students.size()));
    for(int i =0; i<count; i++ ){
        cout<<i+1 <<". "<<students[i].name<<". "<<students[i].credits<<"credits"<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter the number of the students: ";
    cin>>n;

   vector<Student> students(n);

    cout<<"Enter student name and credits received ";
    for(int i = 0; i< n; i++){

        cout<<"Name: ";
        cin>>students[i].name;
        cout<<"Credits: ";
        cin>>students[i].credits;

    }

    quickSort(students,0,n-1);

    displayTopStudents(students);



    return 0;
}