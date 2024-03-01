#include<bits/stdc++.h>

using namespace std;

#define pb push_back


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // include 1 time only

long long rand(long long l, long long r)
{
    long long k = uniform_int_distribution<long long>(l, r)(rng);
    return k;
}

template <typename T> class dearray
{
private:
    T* arr;
    int capacity;
    int current_size;
    int start;
    int end;
    int max(int x, int y)
    {
        if (x > y)
            return x;
        else
            return y;
    }
    int next_two_power(int value)
    {
        if (value == 0)
            return 1;
        int ans = 0, temp_value;
        temp_value = value;
        while (temp_value != 1)
        {
            temp_value = temp_value / 2;
            ans++;
        }
        ans = (1 << ans);
        if (ans < value)
            ans = ans * 2;
        return ans;
    }

public:
    dearray()
    {
        arr = new T[1];
        capacity = 1;
        current_size = 0;
        start = 1;
        end = 1;
    }
    dearray(int size)
    {
        capacity = next_two_power(size);
        current_size = size;
        start = (capacity - current_size + 1) / 2;
        end = (capacity - current_size + 1) / 2 + current_size;
        arr = new T[capacity];
        for (int i = start; i < end; i++)
        {
            arr[i] = 0;
        }
    }
    dearray(int size, T value)
    {
        capacity = next_two_power(size);
        current_size = size;
        start = (capacity - current_size + 1) / 2;
        end = (capacity - current_size + 1) / 2 + current_size;
        arr = new T[capacity];
        for (int i = start; i < end; i++)
        {
            arr[i] = value;
        }
    }
    ~ dearray()
    {
        delete [] arr;
    }
    void right_rotate()
    {
        T val = back();
        pop_back();
        push_front(val);
    }
    void left_rotate()
    {
        T val = front();
        pop_front();
        push_back(val);
    }
    void push_back(T value)
    {
        if (end == capacity)
        {
            capacity = capacity * 2;
            int new_start = (capacity - current_size + 1) / 2;
            int new_end = (capacity - current_size + 1) / 2 + current_size;
            T *new_arr = new T[capacity];
            for (int i = new_start, j = start; i < new_end && j < end; i++, j++)
            {
                new_arr[i] = arr[j];
            }
            start = new_start;
            end = new_end;
            arr = new_arr;
        }
        arr[end] = value;
        end++;
        current_size++;
    }
    void push_front(T value)
    {
        if (start == 0)
        {
            capacity = capacity * 2;
            int new_start = (capacity - current_size + 1) / 2;
            int new_end = (capacity - current_size + 1) / 2 + current_size;
            T *new_arr = new T[capacity];
            for (int i = new_start, j = start; i < new_end && j < end; i++, j++)
            {
                new_arr[i] = arr[j];
            }
            start = new_start;
            end = new_end;
            arr = new_arr;
        }
        start--;
        arr[start] = value;
        current_size++;
    }
    void pop_back()
    {
        if (start == end)
        {
            out_of_range("Dearray size is zero");
        }

        end--;
        current_size--;
    }
    void pop_front()
    {
        if (start == end)
        {
            throw out_of_range("Dearray size is zero");
        }

        start++;
        current_size--;
    }
    T back()
    {
        if (start == end)
        {
            throw out_of_range("Dearray size is zero");
        }

        return arr[end - 1];
    }
    T front()
    {
        if (start == end)
        {
            throw out_of_range("Dearray size is zero");
        }

        return arr[start];
    }
    int size()
    {
        return (end - start);
    }
    T& operator[](int i)
    {
        if (i < 0 || (i + start) > (end - 1))
        {
            throw out_of_range("Index out of range");
        }

        return arr[i + start];
    }
    void print()
    {
        cout << start << " " << end << " " << capacity << "\n";
        for (int i = 0; i < capacity; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        for (int i = start; i < end; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    dearray<int> a(10, 75);
    a.print();
    for (int i = 0; i < 20; i++)
    {
        int x = rand(1, 6);
        int y = rand(1, 100);
        if (x == 1 || x == 5)
        {
            cout << "push_back - " << y << "\n";
            a.push_back(y);
        }
        if (x == 2)
        {
            cout << "pop_back - " << "\n";
            a.pop_back();
        }
        if (x == 3 || x == 6)
        {
            cout << "push_front - " << y << "\n";
            a.push_front(y);
        }
        if (x == 4)
        {
            cout << "pop_front - " << "\n";
            a.pop_front();
        }
        a.print();
        for (int j = 0; j < a.size(); j++)
        {
            cout << a[j] << " ";
        }
        cout << "\n\n";
    }

    a[9] = 123;

    for (int j = 0; j < a.size(); j++)
    {
        cout << a[j] << " ";
    }
    cout << "\n\n";

    a.right_rotate();


    for (int j = 0; j < a.size(); j++)
    {
        cout << a[j] << " ";
    }
    cout << "\n\n";


    a.left_rotate();


    for (int j = 0; j < a.size(); j++)
    {
        cout << a[j] << " ";
    }
    cout << "\n\n";

    cout << a.size() << "\n";

    return 0;
}