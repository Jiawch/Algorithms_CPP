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
 *! Date: 2021-11-01
 * Trie树：插入、查找
 */


struct TrieNode {
    char value;     // 键值
    bool is_end;    // 以该节点结尾，是否构成一个单词标志
    unordered_map<char, TrieNode*> child;  // 保存指向孩子节点的指针，用map而非vector是因为`map的find函数比较方便`

    TrieNode (char value) {
        value = value;
        is_end = false;
    }
};

void insert (TrieNode* root, string word) {
    TreeNode *p = root;
    int i = 0;
    int len = word.size()
    while (i < len) {
        // 字符已在树中 
        if (p->child.find(word[i]) != p->child.end()) {           
            if (i == len-1) (p->child[word[i]])->is_end = true; // 构成单词标志
            p = p->child[word[i]];
            i++;
        }
        // 如果字符不在树中，创建新的结点
        else {                                                    
            TrieNode *q = new TrieNode(word[i]);
            if (i == len-1) q->is_end = true;                   // 构成单词标志
            p->child[word[i]] = q;
            p = q;
        }
    }
}


bool search (TrieNode* root, string word) {
    TrieNode *p = root;
    int i = 0;
    int len = word.size();
    while (i < len) {
        // 当前词在树中没有匹配
        if (p->child.find(word[i]) == p->child.end()) {
            return false;
        }
        // 当前词在树中匹配
        else {
            p = p->child[word[i]];
            if (i == len-1) {       // 最后一个节点包含构成单词标志
                if (p->is_end == true)
                    return true;
                else
                    return false;
            }
        }
        i++;
    }

    return false;
}


bool startWith (TrieNode* root, string prefix) {
    TrieNode *p = root;
    int i = 0;
    int len = prefix.size();
    while (i < len) {
        // 当前词在树中没有匹配
        if (p->child.find(prefix[i]) == p->child.end()) {
            return false;
        }
        // 当前词在树中匹配
        else {
            p = p->child[prefix[i]];
        }
        i++;
    }
    // 如果前缀中所以单词都在树中，返回true
    return true;
}
