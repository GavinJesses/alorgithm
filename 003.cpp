#include <bits/stdc++.h>
#include <string>
#include <memory>
using namespace std;
string encodedTree;
struct Node
{
    char data;
    shared_ptr<Node> left;
    shared_ptr<Node> right;

    Node(char d) : data(d), left(nullptr), right(nullptr) {}
    Node() : data('\0'), left(nullptr), right(nullptr) {}
};

shared_ptr<Node> rebuildHuffmanTree(const string &s, int &indexx)
{
    if (indexx >= s.length())
        return nullptr;

    if (s[indexx] == '1')
    {
        indexx++;              // 跳过'1'
        char ch = s[indexx++]; // 读取字符
        return make_shared<Node>(ch);
    }
    else if (s[indexx] == '0')
    {
        indexx++; // 跳过'0'
        auto node = make_shared<Node>();
        node->left = rebuildHuffmanTree(s, indexx);
        node->right = rebuildHuffmanTree(s, indexx);
        return node;
    }
    return nullptr;
}

// 辅助函数：打印树结构（前序遍历）
void printTree(const shared_ptr<Node> &root, string prefix = "")
{
    if (!root)
        return;

    if (root->data != '\0')
    {
        cout << prefix << "Leaf: " << root->data << endl;
    }
    else
    {
        cout << prefix << "Internal Node" << endl;
    }
    printTree(root->left, prefix + "  ");
    printTree(root->right, prefix + "  ");
}
string hexToBinary(const string& hexStr) {
    static const string hexMap[] = {
        "0000", "0001", "0010", "0011",
        "0100", "0101", "0110", "0111",
        "1000", "1001", "1010", "1011",
        "1100", "1101", "1110", "1111"
    };
    string res;
    for (auto &c : hexStr) {
        if (isdigit(c)) res += hexMap[c - '0'];
        else res += hexMap[tolower(c) - 'a' + 10];
    }
    return res;
}

string judge_Huffman(string s, shared_ptr<Node> root)
{
    if (s.empty())
        return s;

    if (s[0] != 'H')
        return s;

    if (s.size() > 1 && s[0] == 'H' && s[1] == 'H')
        return s.substr(1);

    if (s[0] == 'H' && (s.size() - 1) % 2 == 0)
    {
        int zero = stoi(s.substr(s.size() - 2, 2));
        string _16 = s.substr(1, s.size() - 3);
        string _2 = hexToBinary(_16);
        if (zero >= 0 && _2.size() > zero)
            _2 = _2.substr(0, _2.size() - zero);
        shared_ptr<Node> it = root;
        string res = "";
        int i = 0;
        while (i < _2.size())
        {
            if (it != nullptr && it->data == '\0')
            {
                if (_2[i] == '0')
                    it = it->left;
                else
                    it = it->right;
                i++;
            }
            else
            {
                if (it != nullptr)
                    res += it->data;

                it = root;
            }
        }
        if (it != nullptr && it->data != '\0')
            res += it->data;
        return res;
    }
    return s;
}
int main()
{
    int s, d;
    cin >> s >> d;
    vector<pair<string, string>> v;
    v.push_back({"", ""});
    for (int i = 0; i < s; i++)
    {
        string name;
        string value;
        cin >> name >> value;
        v.push_back({name, value});
    }
    cin >> encodedTree;
    int indexx = 0;
    auto root = rebuildHuffmanTree(encodedTree, indexx);


    int n;
    cin >> n;
    while (n--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int i;
            cin >> i;
            cout << v[i].first << ": " << v[i].second << endl;
        }
        else if (op == 2)
        {
            int i;
            cin >> i;
            if (!i)
            {
                string k, vv;
                cin >> k >> vv;
                k = judge_Huffman(k, root);
                vv = judge_Huffman(vv, root);
                cout << k << ": " << vv << endl;
                v.insert(v.begin() + s+1, {k, vv});
            }
            else
            {
                string vv;
                cin >> vv;
                vv = judge_Huffman(vv, root);
                cout << v[i].first << ": " << vv << endl;
                v.insert(v.begin() + s+1, {v[i].first, vv});
            }
        }
        else
        {
            int i;
            cin >> i;
            if (!i)
            {
                string k, vv;
                cin >> k >> vv;
                k = judge_Huffman(k, root);
                vv = judge_Huffman(vv, root);
                cout << k << ": " << vv << endl;
                // v.insert(v.begin() + s, {k, vv});
            }
            else
            {
                string vv;
                cin >> vv;
                vv = judge_Huffman(vv, root);
                cout << v[i].first << ": " << vv << endl;
                // v.insert(v.begin() + s, {v[i].first, vv});
            }
        }
    }
    // cout << "Rebuilt Huffman Tree:" << endl;
    // printTree(root);

    return 0;
}
