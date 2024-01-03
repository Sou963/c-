#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

struct HuffmanNode {
    char data;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char c, int freq) : data(c), frequency(freq), left(nullptr), right(nullptr) {}
};

struct CompareNodes {
    bool operator()(HuffmanNode* const& lhs, HuffmanNode* const& rhs) {
        return lhs->frequency > rhs->frequency;
    }
};

void generateHuffmanCodes(const std::unordered_map<char, int>& frequencies) {
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, CompareNodes> minHeap;

    // Create a leaf node for each character and push it to the priority queue
    for (const auto& entry : frequencies) {
        minHeap.push(new HuffmanNode(entry.first, entry.second));
    }

    // Build the Huffman tree
    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.top();
        minHeap.pop();

        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        HuffmanNode* internalNode = new HuffmanNode('$', left->frequency + right->frequency);
        internalNode->left = left;
        internalNode->right = right;

        minHeap.push(internalNode);
    }

    // Traverse the Huffman tree to generate codes
    std::unordered_map<char, std::string> huffmanCodes;
    std::string currentCode;
    HuffmanNode* root = minHeap.top();

    // Helper function to recursively generate codes
    auto generateCodes = [&](HuffmanNode* node, const std::string& code) {
        if (node) {
            if (node->data != '$') {
                huffmanCodes[node->data] = code;
            }
            generateCodes(node->left, code + "0");
            generateCodes(node->right, code + "1");
        }
    };

    generateCodes(root, currentCode);

    // Output the Huffman codes
    std::cout << "Huffman Codes:\n";
    for (const auto& entry : huffmanCodes) {
        std::cout << "'" << entry.first << "': '" << entry.second << "'\n";
    }

    // Clean up allocated memory
    delete root;
}

int main() {
    std::unordered_map<char, int> frequencies = {{'a', 5}, {'b', 9}, {'c', 12}, {'d', 13}, {'e', 16}, {'f', 45}};

    generateHuffmanCodes(frequencies);

    return 0;
}
