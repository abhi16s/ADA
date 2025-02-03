#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int value;
    int weight;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(int W, int weight[], int price[], int n) {
    Item arr[n];
    
    for (int i = 0; i < n; i++) {
        arr[i].value = price[i];
        arr[i].weight = weight[i];
        arr[i].ratio = (double) price[i] / weight[i];
    }
    
    sort(arr, arr + n, compare);
    
    double maxValue = 0.0;
    
    for (int i = 0; i < n; i++) {
        if (W == 0) break;
        
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            maxValue += arr[i].value;
        } else {
            maxValue += arr[i].value * ((double) W / arr[i].weight);
            W = 0;
        }
    }
    return maxValue;
}

int main() {
    int W = 50;
    int weight[] = {10, 20, 30};
    int price[] = {60, 100, 120};
    int n = sizeof(weight) / sizeof(weight[0]);
    
    double result = fractionalKnapsack(W, weight, price, n);
    cout << "Maximum value = " << result << endl;
    
    return 0;
}
