#include <iostream>
#include <string>

using namespace std;

int globalNum;

string findMostOccurringString(const string& str1, const string& str2, char c, int& count) {
    int count_str1 = 0, count_str2 = 0;

    for (char ch : str1) {
        if (ch == c)
            count_str1++;
    }
    for (char ch : str2) {
        if (ch == c)
            count_str2++;
    }

    if (count_str1 > count_str2) {
        count = count_str1;
        return str1;
    } else if (count_str2 > count_str1) {
        count = count_str2;
        return str2;
    } else {
        count = count_str1;
        return "";
    }
}


void convertString(string& str, int& digitCount) {
    for (char& ch : str) {
        if (isdigit(ch)) {
            digitCount++;
        } else if (islower(ch)) {
            ch = toupper(ch);
        } else if (isupper(ch)) {
            ch = tolower(ch);
        }
    }
}


template<typename T>
T findLargestSumPair(T a, T b, T c) {
    T sum_ab = a + b;
    T sum_bc = b + c;
    T sum_ac = a + c;
    T largest_sum = sum_ab;

    if (sum_bc > largest_sum) {
        largest_sum = sum_bc;
    }

    if (sum_ac > largest_sum) {
        largest_sum = sum_ac;
    }

    return largest_sum;
}

void findMinMax(int arr[], int size, int& min, int& max) {
    min = arr[0];
    max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
}

template <typename T>
T& swapValues(T& a, T& b) {
    if (a < b) {
        swap(a, b);
    }
    return a;
}

template <typename T, size_t N>
void swapArrays(T (&arr1)[N], T (&arr2)[N]) {
    for (size_t i = 0; i < N; ++i) {
        swap(arr1[i], arr2[i]);
    }
}

template <typename T, size_t N>
void printArray(T (&arr)[N]) {
    for (size_t i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    cout<<"PROBLEM 1"<<endl;
    int localNum;
    cin>>globalNum>>localNum;
    int remainder = globalNum % localNum;
    cout<<remainder<<endl;

    cout<<"PROBLEM 2"<<endl;
    string str1, str2;
    char c;
    
    cout << "Enter the first string: ";
    getline(cin, str1);
    
    cout << "Enter the second string: ";
    getline(cin, str2);
    
    cout << "Enter the character to search: ";
    cin >> c;
    
    int count;
    string result = findMostOccurringString(str1, str2, c, count);
    
    if (result.empty()) {
        cout << "Not found." << endl;
    } else {
        cout << "The string \"" << result << "\" contains the character '" << c << "' most times (" << count << " times)." << endl;
    }
    

    cout<<"PROBLEM 3"<<endl;
    string str_p3;
    int digitCount = 0;
    
    while (true) {
        getline(cin, str_p3);
    
        if (!str_p3.empty() && str_p3.back() == 'x') {
            str_p3.pop_back();
    
            convertString(str_p3, digitCount);
    
            cout << str_p3;
            cout << " contains " << digitCount << " digits." << endl;
    
            break;
        } else {
            cout << "String does not end with 'x'. Please try again." << endl;
        }
    }

    cout<<"PROBLEM 4"<<endl;
    int choice_type;
    cin >> choice_type;

    switch (choice_type) {
        case 1:
            int x,y,z;
            cin>>x>>y>>z;
            cout<<findLargestSumPair(x,y,z)<<endl;
                break;
        case 2:{
            const int size = 7;
            int arr[size];
            for (int i = 0; i < size; ++i) {
                cin >> arr[i];
            }
            int min, max;
            findMinMax(arr, size, min, max);
            cout << "Min: " << min << " Max: " << max << endl;
            break;
        }
        default:
            cout << "Invalid choice." << endl;
    }

    cout<<"PROBLEM 5"<<endl;
    cout << "Enter two values to swap: ";
    int a, b;
    cin >> a >> b;
    cout << "Larger value after swapping: " << swapValues(a, b) << endl;

    const size_t arraySize = 5;
    int arr1[arraySize], arr2[arraySize];
    cout << "Enter " << arraySize << " elements for the first array: ";
    for (size_t i = 0; i < arraySize; ++i) {
        cin >> arr1[i];
    }
    cout << "Enter " << arraySize << " elements for the second array: ";
    for (size_t i = 0; i < arraySize; ++i) {
        cin >> arr2[i];
    }

    cout << "Before swapping:\n";
    printArray(arr1);
    printArray(arr2);
    swapArrays(arr1, arr2);
    cout << "After swapping:\n";
    printArray(arr1);
    printArray(arr2);

    return 0;
}