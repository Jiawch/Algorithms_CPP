/*! Author: Jiawch
 *! Date: 2021-11-16
 * 哈希函数实现：初始化、插入、查找
 * 哈希函数采用除留余数法
 * 冲突解决采用开放地址法大线性探测再散列
 */


#include <iostream>
#include <vector>
#define MAX ~(1 << (sizeof(int) * 8 - 1))  // 1 左移取反

using namespace std;


// 初始化哈希表
void intiHashTable(vector<int> &hashTable, int length)
{
    for (int i = 0; i < length; i++)
    {
        hashTable[i] = MAX;
    }
}

// 哈希函数
int hashFunc(int key, int m)
{
    return key % m;
}

// 插入
int hashInsert(vector<int> &hashTable, int key, int length)
{
    int n = hashTable.size();

    int hashAddr = hashFunc(key, length);

    // 冲突
    while (hashTable[hashAddr] != MAX)
    {
        // 线性探测再散列
        hashAddr = (hashAddr + 1) % length;
        // 循环了一遍
        if (hashAddr == hashFunc(key, length))
        {
            return -1;
        }
    }

    hashTable[hashAddr] = key;
    return 0;
}

// 查找
int hashSearch(vector<int> hashTable, int key, int length)
{
    int hashAddr = hashFunc(key, length);

    // 冲突
    while (hashTable[hashAddr] != key)
    {
        // 线性探测再散列
        hashAddr = (hashAddr + 1) % length;
        //如果探测到下一个地址为空，还没有找到，或者循环找了一遍又回到最开始的hashAddr
        if (hashTable[hashAddr] == MAX || hashAddr == hashFunc(key, length))
        {
            return -1;
        }
    }

    return hashAddr;
}

int main()
{
    vector<int> a = {12,67,56,16,25,37,22,29,15,47,48,34};
    int n = a.size();
    cout << "哈希表待插入元素：";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;

    // 初始化
    int length = n;
    vector<int> hashTable(n);
    intiHashTable(hashTable, length);

    // 插入
    for (int i = 0; i < n; i++)
    {
        hashInsert(hashTable, a[i], length);
    }
    cout<<"哈希表：";
    for (int i = 0; i < length; i++)
    {
        cout << hashTable[i] << ' ';
    }
    cout << endl;

    // 查找
    vector<int> b = {12, 11, 10, 67, 34};
    for (int i = 0; i < b.size(); i++)
    {
        int hashAddr = hashSearch(hashTable, b[i], length);
        if (hashAddr != -1)  // 查找成功
        {
            cout << "hashTable[" << hashAddr << "] = " << hashTable[hashAddr] << endl; 
        }
        else
        {
            // cout << "hashTable[" << hashAddr << "] = " << hashTable[hashAddr];
            cout << "key {" << b[i] << "} not found!" << endl; 
        }
    }

}


/*
 * 哈希表待插入元素：12 67 56 16 25 37 22 29 15 47 48 34 
 * 哈希表：12 25 37 15 16 29 48 67 56 34 22 47 
 * hashTable[0] = 12
 * key {11} not found!
 * key {10} not found!
 * hashTable[7] = 67
 * hashTable[9] = 34
 */













