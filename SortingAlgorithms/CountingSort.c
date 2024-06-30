#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// returns largest element in an array
int max(int nums[], int n) 
{
        int max_num = nums[0];
        for (int i = 1; i < n; i++) {
               if (nums[i] > max_num)
                        max_num = nums[i];
        }

        return max_num;
}


// Time complexity O(n + k)
// Space complexity O(n + k)
// n => size of array of sorted numbers
// k => size of temp array
void countingSort(int nums[], int n)
{
        // this will store the sorted numbers
        int *sortedArray = malloc(sizeof(int) * n);
        if (!sortedArray) {
                fprintf(stderr, "lol buy more ram\n");
                exit(1);
        }
        
        // temporary array
        int temp_size = max(nums, n);
        int *temp = malloc(sizeof(int) * temp_size);
        if (!temp) {
                fprintf(stderr, "lol buy more ram\n");
                exit(1);
        }
        
        // set the entire values of array to 0
        memset(temp, 0, temp_size);

        // count the frequencies in original array
        for (int i = 0; i < n; i++) {
                temp[nums[i]]++;
        }

        // prefix sum
        for (int i = 1; i <= temp_size; i++) {
                temp[i] += temp[i - 1];
        }
        
        // finds the correct position for each element in original array
        for (int i = n - 1; i >= 0; i--) {
                sortedArray[temp[nums[i]] - 1] = nums[i];
                temp[nums[i]]--;
        }

        // assign the sorted array to original array
        for (int i = 0; i < n; i++) {
                nums[i] = sortedArray[i];
        }
}

void print_array(int nums[], int n)
{
       for (int i = 0; i < n; i++) {
                printf("%d ", nums[i]);
        } 
        printf("\n");
}

int main() 
{
        srand(time(NULL));
        int nums[MAX];
        int size = rand() % 10 + 1; // returns an value from 1 to 10

        for (int i = 0; i < size; i++) {
                nums[i] = rand() % 6; // numbers from 0 to 5
        }

        print_array(nums, size);
        countingSort(nums, size);
        print_array(nums, size);

        return 0;
}
