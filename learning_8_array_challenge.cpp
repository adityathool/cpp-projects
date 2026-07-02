#include <iostream>


int calculate_max(int arr[],int size){
    int max_value = arr[0];
    for (int i =0;i<size;++i){
        if (arr[i]>max_value){
            max_value = arr[i];
        }
    }
    std::cout<<"the maximum marrks in the given data is "<<max_value<<"\n";
    return 0;
}

int array_sorter(int arr[], int size){
    for(int i = 0;i<size;++i){
        if (arr[i+1]<arr[i]){
            arr[i]=arr[i+1];

        }
        std::cout<<arr[i]<<" ";
        
    }
return 0;

}
int main(){
    std::cout<<"max value calculator\n aray sorter";
    // int marks[] = {20,34,405,4,45,6,4,53,43,4,34,3,4};
    // int total_marks= std::size(marks);
    // calculate_max(marks, total_marks);

    int jumbled_array[]= {1,2,3,2,3,5,3,7,3,6,7};
    int length = std::size(jumbled_array);
    array_sorter(jumbled_array, length);
    return 0;
}