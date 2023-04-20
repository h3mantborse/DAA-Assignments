#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

// Tree node for Huffman coding
struct TreeNode {
    char c;
    int freq;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char c, int freq) : c(c), freq(freq), left(nullptr), right(nullptr) {}
};

// Custom comparator for priority queue
struct NodeComparator {
    bool operator()(const TreeNode* a, const TreeNode* b) const {
        return a->freq > b->freq;
    }
};

// Function to build Huffman tree
TreeNode* buildHuffmanTree(unordered_map<char, int>& freqMap) {
    priority_queue<TreeNode*, vector<TreeNode*>, NodeComparator> pq;

    for (auto p : freqMap) {
        TreeNode* node = new TreeNode(p.first, p.second);
        pq.push(node);
    }

    while (pq.size() > 1) {
        TreeNode* left = pq.top();
        pq.pop();
        TreeNode* right = pq.top();
        pq.pop();

        TreeNode* newNode = new TreeNode('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    return pq.top();
}

// Function to generate Huffman codes
void generateHuffmanCodes(TreeNode* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (root == nullptr) {
        return;
    }

    if (root->c != '$') {
        huffmanCodes[root->c] = code;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

int main() {
    string input = "Hello, World!";
    unordered_map<char, int> freqMap;

    // Count frequencies of characters in input string
    for (char c : input) {
        freqMap[c]++;
    }

    TreeNode* root = buildHuffmanTree(freqMap);
    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    cout << "Huffman Codes:" << endl;
    for (auto p : huffmanCodes) {
        cout << p.first << ": " << p.second << endl;
    }

    return 0;
}
