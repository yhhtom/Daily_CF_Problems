#include <iostream>
using namespace std;

template <class T>
class MyArray
{
private:
    T *pAddress;
    int mSize;
    int mCapacity;

public:
    MyArray(int capacity)
    {
        this->mCapacity = capacity;
        mSize = 0;
        pAddress = new T[capacity];
    }
    MyArray(const MyArray &a)
    {
        this->mCapacity = a.mCapacity;
        this->mSize = a.mSize;
        this->pAddress = new T[a.mCapacity];
        for (int i = 0; i < a.mSize; i++)
        {
            this->pAddress[i] = a.pAddress[i];
        }
    }
    ~MyArray()
    {
        delete[] pAddress;
    }
    void pushBack(const T &val)
    {
        if (this->mSize == this->mCapacity)
        {
            cout << "Inserting new value failed: the array is full.\n";
            return;
        }
        this->pAddress[mSize] = val;
        this->mSize++;
    }
    T getMax()
    {
        T res = this->pAddress[0];
        for (int i = 0; i < this->mSize; i++)
        {
            if (this->pAddress[i] > res)
            {
                res = this->pAddress[i];
            }
        }
        return res;
    }
    MyArray &operator=(const MyArray &a)
    {
        this->mCapacity = a.mCapacity;
        this->mSize = a.mSize;
        this->pAddress = new T[a.mCapacity];
        for (int i = 0; i < a.mSize; i++)
        {
            this->pAddress[i] = a.pAddress[i];
        }
        return *this;
    }
    T &operator[](int index)
    {
        return this->pAddress[index];
    }
};
class MyClassInt
{
private:
    int val;

public:
    MyClassInt()
    {
        this->val = 0;
    }
    MyClassInt(int v)
    {
        this->val = v;
    }
    MyClassInt &operator=(const MyClassInt &o)
    {
        this->val = o.val;
        return *this;
    }
    friend ostream &operator<<(ostream &os, const MyClassInt &my);
    bool operator>(const MyClassInt &o)
    {
        return this->val > o.val;
    }
};
ostream &operator<<(ostream &os, const MyClassInt &my)
{
    cout << my.val;
    return os;
}
class MyClassArr
{
private:
    MyArray<int> *mArray;
    int Len;

public:
    MyClassArr()
    {
        mArray = NULL;
        Len = 0;
    }
    MyClassArr(int arr[], int l)
    {
        this->Len = l;
        this->mArray = new MyArray<int>(l);
        for (int i = 0; i < l; i++)
        {
            this->mArray->pushBack(arr[i]);
        }
    }
    MyClassArr(const MyClassArr &a)
    {
        this->Len = a.Len;
        this->mArray = new MyArray<int>(a.Len);
        for (int i = 0; i < this->Len; i++)
        {
            this->mArray->pushBack((*a.mArray)[i]);
        }
    }
    MyClassArr &operator=(const MyClassArr &a)
    {
        this->Len = a.Len;
        this->mArray = a.mArray;
        return *this;
    }
    friend ostream &operator<<(ostream &os, const MyClassArr &my);
    bool operator>(const MyClassArr &o)
    {
        for (int i = 0; i < this->Len && i < o.Len; i++)
        {
            if ((*this->mArray)[i] > (*o.mArray)[i])
            {
                return true;
            }
            else if ((*o.mArray)[i] > (*this->mArray)[i])
            {
                return false;
            }
        }
        return this->Len > o.Len;
    }
};
ostream &operator<<(ostream &os, const MyClassArr &my)
{
    for (int i = 0; i < my.Len; i++)
    {
        cout << (*my.mArray)[i] << ' ';
    }
    cout << '\n';
    return os;
}
int main()
{
    cout << "Input the amount of variables to store in the MyClassArr array:\n";
    int s;
    cin >> s;
    MyArray<MyClassArr> my(5);
    for (int i = 1; i <= s; i++)
    {
        cout << "Input the size of MyArray " << i << ":\n";
        int t;
        cin >> t;
        int *tempv = new int[t];
        cout << "Input array " << i << ":\n";
        for (int i = 0; i < t; i++)
        {
            cin >> tempv[i];
        }
        // cout<<t<<endl;
        MyClassArr temp(tempv, t);
        my.pushBack(temp);
    }
    cout << "The max value of the array is: " << my.getMax() << '\n';

    return 0;
}