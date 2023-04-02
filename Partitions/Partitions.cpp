#include <iostream>

using namespace std;
bool isPrime(int k) {
    if (k <= 1)
        return false;
    for (int i = 2; i < k; i++)
        if (k % i == 0)
            return false;

    return true;
}

int Partition(int prime[], int result[], int index, int suma, int k, int n, int id)
{

    if (suma == 0) {
        //if (result[0] != k) return 0;
        int su = 0;
        for (int i = 0; i <= n / 2; i++)
        {
            su = su + result[i];
            if (result[i] > 0 && su <= n) {
                cout << result[i];
                if (su < n) cout << "+";
            }
        }
        cout << endl;
        return 0;
    }
    if (index > n / 2 || suma < 0)
    {


        return 0;
    }


    for (int i = k / 2; i >= id; i--)
    {
        int s;

        s = prime[i];

        result[index] = s;

        if (result[0] == k) Partition(prime, result, index + 1, suma - s, k, n, i);

    }

    return 0;
}
int main()
{
    int l;
    int n;
    int k;
    cin >> l;
    int it = 0;
    int* primes;
    int* result;
    while (it < l) {
        cin >> n;
        cin >> k;

        primes = new int[k / 2 + 1];
        result = new int[n / 2 + 1];


        for (int i = 0; i < k / 2 + 1; i++)
        {
            primes[i] = 0;
        }

        for (int i = 0; i < n / 2 + 1; i++)
        {
            result[i] = 0;
        }
        int temp = k;
        int i = 0;
        while (temp >= 2) {
            if (isPrime(temp)) {
                primes[i] = temp;
                i++;
            }
            temp--;
        }


        Partition(primes, result, 0, n, k, n, 0);
        it++;

        delete[]primes;
        delete[]result;
    }

}