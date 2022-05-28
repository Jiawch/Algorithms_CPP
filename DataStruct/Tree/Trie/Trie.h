/*! Author: qwchen
 *! Date: 2016-11-15
 * 字典树
 */

#ifndef Trie_
#define Trie_

#include <iostream>
#include <unordered_map>

using namespace std;

/*
 * 字典树的结点
 */
class TrieNode {
public:
    char value;  // 值
    bool isEnd;  // 是否为叶子
    unordered_map<char, TrieNode*> child; // 保存指向孩子结点的指针
    TrieNode() {
        value = '/';
        isEnd = false;
    }
};

/*
 * 字典树
 */
class Trie {
public:
    Trie();
    void insert(string word);       // 插入单词
    bool search(string word);       // 查找单词，当字典树中存在单词word时返回true
    bool startsWith(string prefix); // 判断树中是否存在以prefix开头的前缀

private:
    TrieNode* root;
};

Trie::Trie() {
        root = new TrieNode();
}

void Trie::insert(string word) {
    TrieNode* p = root;
    int len = word.size();
    for (int i = 0; i < len; i++){ // 逐步搜索word的每个字符
        // 如果字符已经在树中，顺着孩子结点往下查找
        if (p->child.find(word[i]) != p->child.end()) {
            // 将树中存储单词的最后一个字符的结点的isEnd设置为true
            if (i == len - 1) {
                (p->child[word[i]])->isEnd = true;
            }
            else {
                p = p->child[word[i]];
            }
        }
        // 如果字符不在树中，创建新的结点
        else {
            TrieNode* node = new TrieNode();
            node->value = word[i];
            // 将树中存储单词的最后一个字符的结点的isEnd设置为true
            if (i == len - 1) {
                node->isEnd = true;
            }
            p->child[word[i]] = node;
            p = node;
        }
    }
}
  
bool Trie::search(string word) {
    TrieNode* p = root;
    int len = word.size();
    for (int i = 0; i < len; i++) {
        // 如果单词中有字符不在树中，则树中不存在该单词
        if (p->child.find(word[i]) == p->child.end()) {
            return false;
        }
        else {
            if (i == len - 1) {
                // 整个单词在树中，树中才存在该单词
                if ((p->child[word[i]])->isEnd == true) {
                    return true;
                }
                else {
                    return false;
                }
            }
            p = p->child[word[i]];
        }
    }
    return false; // 如果树中存在该单词，但该单词只是前缀，即最后一个结点的isEnd为false，则返回false
}

    
bool Trie::startsWith(string prefix) {
    TrieNode* p = root;
    int len = prefix.size();
    for (int i = 0; i < len; i++) {
        // 如果前缀中有字符不在树中，则树中不存在该前缀
        if (p->child.find(prefix[i]) == p->child.end()){
            return false;
        }
        else {
            p = p->child[prefix[i]];
        }
    }
    return true; // 如果前缀中所以单词都在树中，返回true
}

#endif




/*! Author: Jiawch
 *! Date: 2021-11-16
 * Trie树(v2)：插入、查找
 */


#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// 字典树
struct TrieNode {
    char value;     // 键值
    bool isEnd;     // 构成单词标志
    unordered_map<char, TrieNode*> child;   // 保存指向孩子节点的指针，用map而非vector是因为`map的find函数比较方便`

    TrieNode(char value): value(value), isEnd(false) {}
};

// 插入
TrieNode* insert(TrieNode* root, string word)
{
    if (root == nullptr)
    {
        root = new TrieNode('/');
    }

    TrieNode *p = root;     // 指向当前节点
    int n = word.size();

    // 遍历word
    for (int i = 0; i < n; i++)
    {
        // 如果字符已经在树中，顺着孩子节点往下查找
        if (p->child.find(word[i]) != p->child.end())
        {
            p = p->child[word[i]];
        }
        // 如果字符不在树中，创建新节点
        else
        {
            p->child[word[i]] = new TrieNode(word[i]);
            p = p->child[word[i]];
        }

    }

    // 最后一个字符的节点isEnd置true。p与i的关系是：p代表的节点在i代表的节点的上一级
    p->isEnd = true;

    return root;
}

// 查找
bool search(TrieNode* root, string word)
{
    TrieNode *p = root;
    int n = word.size();

    for (int i = 0; i < n; i++)
    {
        // 如果字符已经在树中，顺着孩子节点往下查找
        if (p->child.find(word[i]) != p->child.end())
        {
            p = p->child[word[i]];
        }
        // 如果字符不在树中，返回false
        else
        {
            return false;
        }
    }

    // 构成单词
    if (p->isEnd == true)
    {
        return true;
    }
    // 不构成单词
    else
    {
        return false;
    }
}

// 以开头
bool startWith(TrieNode* root, string word)
{
    TrieNode *p = root;
    int n = word.size();

    for (int i = 0; i < n; i++)
    {
        if (p->child.find(word[i]) != p->child.end())
        {
            p = p->child[word[i]];
        }
        else
        {
            return false;
        }
    }

    return true;    
}



/*! Author: Jiawch
 *! Date: 2022-05-28
 * Trie树：插入、查找
 */

class TrieNode {
public:
    TrideNode(): isEnd(false), child(26, nullptr) {}
    
    void insert(string word) {
        TrieNode *node = this;
        for (auto c : word) {
            if (node->child[c - 'a'] == nullptr)    node->child[c - 'a'] = new TrieNode();
            node = node->child[c - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *node = this;
        for (auto c : word) {
            if (node->child[c - 'a'] == nullptr)    return false;
            node = node->child[c - 'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = this;
        for (auto c : prefix) {
            if (node->child[c - 'a'] == nullptr)    return false;
            node = node->child[c - 'a'];
        }
        return true;
    }
private:
    bool isEnd;
    vector<TrieNode*> child;
};

/**
 * Your TrieNode object will be instantiated and called as such:
 * TrieNode* obj = new TrieNode();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
