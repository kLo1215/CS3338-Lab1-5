/*
Name: Krystal Lo
Email: klo16@calstatela.edu
Course: CS 3112-01
Assignment 2
*/

#include <iostream>

// get user input for int num
int userN() {
     int n;
     std::cout << "Enter value for n: ";
     std::cin >> n;
     
     // if input is not an int, exit program
     if (std::cin.fail()) {
          exit(0);
     }

     // n greater than or equal to 0 is needed
     if (n <= 0) {
            std::cout << "Invalid response. Please enter a positive integer for n: ";
           std::cin >> n;
      }
    return n;
}

// print the array given
void printArray(int A[], int n) {
        for (int i = 0; i < n; ++i) {
            std::cout << A[i] << " ";
        }
}

// selection sort function
void selectionSort(int A[], int n) {
    // prints the original array before sorting
    std::cout << "Original Array: ";
    printArray(A, n);
    
    for (int j = 0; j < n - 1; j++) {
        int idx = j;
        for (int i = j + 1; i < n; i++) {
            if (A[i] < A[idx]) {
                idx = i;
            }
            if (idx != j) {
                std::swap(A[idx], A[j]);
            }
        }
    }

    // print sorted array
    std::cout << "\nSorted Array: ";
    printArray(A, n);
}

// insertion sort function based off given pseudocode
void insertionSort(int A[], int n) {
    // prints the original array before sorting
    std::cout << "Original Array: ";
    printArray(A, n);
    
    // pseudocode based it off as 1 being first index
    // in code, the first index starts with 0
    for (int j = 1; j < n; ++j) {
        int key = A[j];
        int i = j - 1;

        while ((i  >= 0) && (A[i] > key)) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
    // print sorted array
    std::cout << "\nSorted Array: ";
    printArray(A, n);
}

// ask user if they want to repeat program
// returns character to continue/end do-while loop in main
char repeat() {
     char r;
     std::cout << "\nWould you like to run the program again? (Y/N) ";
     std::cin >> r;
     if (toupper(r) == 'Y') {
          // used toupper to auto-capitalize any input given
          return 'Y';
     } else {
          if (toupper(r) != 'N') {
                std::cout << "Invalid response, ending program.";
                // will return 'N' if any other response is given
          }
          return 'N';
     }
}

int main() {
    int choice;

    do {
        // print menu for user
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "1. Selection Sort \n2. Insertion Sort \n3. Exit program" << std::endl;
        std::cin >> choice;

        int n = userN();
        int* A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = (rand() % 100) + 1;
        }

        switch(choice) {
            case 1:
                selectionSort(A, n);
                break;
            case 2:
                insertionSort(A, n);
                break;
            case 3:
                return 0;
        }
        delete[] A;
    } while (repeat() == 'Y');
    return 0;
}