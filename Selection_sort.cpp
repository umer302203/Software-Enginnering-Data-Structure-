#include <iostream>
#include <utility> // swap function ke liye
using namespace std;

int main()
{
    // 1. Array, jise humein sort karna hai
    int arr[] = {5, 1, 4, 2, 8};
    int size = 5;

    // --- SELECTION SORT KA LOGIC ---

    // 2. Bahar wala loop har position ke liye chalta hai
    for (int i = 0; i < size - 1; i++)
    {

        // Farz karlein ke is position ke liye sab se chota element yehi hai
        int min_index = i;

        // 3. Andar wala loop baqi bachi array mein se sab se chota element dhoondta hai
        for (int j = i + 1; j < size; j++)
        {
            // Agar koi naya, aur bhi chota element mil jaye
            if (arr[j] < arr[min_index])
            {
                // to uska index save karlein
                min_index = j;
            }
        }

        // 4. Sab se chotay element ko is position (i) walay element se tabdeel (swap) kardein
        swap(arr[i], arr[min_index]);
    }

    // --- LOGIC KHATAM ---

    // 5. Aakhir mein, sorted array ko screen par dikhayein
    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
