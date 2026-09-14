#include <iostream>
void sortArray(int& arr[], int size){
    for (int i = 0;i<size; ++i){
        if (arr[i+1]<arr[i]){
            int t = arr[i+1];
            arr[i+1] = arr[i];
            arr[i] = t;
            std::cout<<arr[i]<<",";
            

        }

    }
    
}
 int main(){

    int arr[5] = {3,1,2,4,5};
    sortArray(arr, 5);

    return 0;
 }