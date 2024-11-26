#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item{

    int value;
    int weight;
};

bool compare(Item a, Item b){

    double ratioA = (double)a.value/a.weight;
    double ratioB = (double)b.value/b.weight;

    return ratioA>ratioB;
    
}

double knapsack(vector<Item>& items, int capacity){

    sort(items.begin(),items.end(),compare);

    double totalValue = 0.0;

    for(const auto& item : items){

        if(capacity > item.weight){

            totalValue += item.value;
            capacity -= item.weight;
        }else{
            totalValue += item.value * ((double)capacity/item.weight);
            break;
        }

    }
    return totalValue;
}

int main(){

    int n, capacity;
    cout<<"Enter number of the items: ";
    cin>>n;

    vector<Item> items(n);
    cout<<"Enter the value and weight of the item(value weight) : ";
    for(int i = 0; i<n; i++){
        cin>>items[i].value>>items[i].weight;

    }

    cout<<"Enter the capacity of the knapsack: ";
    cin>>capacity;

    double maxValue = knapsack(items,capacity);
    cout<<"Maximum value in the Knapsack: "<<maxValue<<endl;

    return 0;

}