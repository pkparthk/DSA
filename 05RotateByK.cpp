#include <iostream>
using namespace std;
// Function to Reverse the array
void Reverse(int arr[], int start, int end)
{
    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
// Function to Rotate k elements to left
void Rotateeletoleft(int arr[], int n, int k)
{
    // Reverse first k elements
    Reverse(arr, 0, k - 1);
    // Reverse last n-k elements
    Reverse(arr, k, n - 1);
    // Reverse whole array
    Reverse(arr, 0, n - 1);
}
int main()
{
    int arr[100];
    int n, k;
    cout << "Enter the size of the array ";
    cin >> n;
    cout << "Enter the elements of the array ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the value of k for rotation";
    cin >> k;
    Rotateeletoleft(arr, n, k);
    cout << "After Rotating the k elements to left ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

// #include <iostream>
// using namespace std;
// void Reverse(int arr[], int start, int end)
// {
//     while (start <= end)
//     {
//         int temp = arr[start];
//         arr[start] = arr[end];
//         arr[end] = temp;
//         start++;
//         end--;
//     }
// }
// void Rotateeletoleft(int arr[], int n, int k)
// {
//     Reverse(arr, 0, k - 1);
//     Reverse(arr, k, n - 1);
//     Reverse(arr, 0, n - 1);
// }
// int main()
// {
//     int arr[100];
//     int n, k;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     cin >> k;
//     Rotateeletoleft(arr, n, k);
//     for (int i = 0; i < n; i++)
//         cout << arr[i] << " ";
//     cout << endl;
//     return 0;
// }