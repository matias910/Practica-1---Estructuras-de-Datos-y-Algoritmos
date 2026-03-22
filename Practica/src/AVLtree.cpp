//
// Created by matias on 3/21/26.
//

#include "AVLtree.h"
#include <algorithm>

AVLTree::AVLTree() : root_(nullptr), nodeCount_(0) {}

AVLTree::~AVLTree() { destroy(root_); }

void AVLTree::destroy(AVLNode* node) {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

void AVLTree::insert(const std::string& key) {
    root_ = insert(root_, key);
}

void AVLTree::inorder(std::vector<std::string>& result) const {
    result.reserve(nodeCount_);
    inorder(root_, result);
}

size_t AVLTree::memoryUsage() const {
    return nodeCount_ * (sizeof(AVLNode) + 32);
}

int AVLTree::height(AVLNode* node) const {
    return node ? node->height : 0;
}

int AVLTree::balanceFactor(AVLNode* node) const {
    return node ? height(node->left) - height(node->right) : 0;
}

void AVLTree::updateHeight(AVLNode* node) {
    node->height = 1 + std::max(height(node->left), height(node->right));
}

AVLNode* AVLTree::rotateRight(AVLNode* y) {
    AVLNode* x  = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left  = T2;

    updateHeight(y);
    updateHeight(x);
    return x;
}

AVLNode* AVLTree::rotateLeft(AVLNode* x) {
    AVLNode* y  = x->right;
    AVLNode* T2 = y->left;

    y->left  = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);
    return y;
}

AVLNode* AVLTree::balance(AVLNode* node) {
    updateHeight(node);
    int bf = balanceFactor(node);

    if (bf > 1) {
        if (balanceFactor(node->left) < 0)
            node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (bf < -1) {
        if (balanceFactor(node->right) > 0)
            node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

AVLNode* AVLTree::insert(AVLNode* node, const std::string& key) {
    if (!node) {
        ++nodeCount_;
        return new AVLNode(key);
    }
    if (key < node->key)
        node->left  = insert(node->left,  key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // duplicate, ignore

    return balance(node);
}

void AVLTree::inorder(AVLNode* node, std::vector<std::string>& result) const {
    if (!node) return;
    inorder(node->left,  result);
    result.push_back(node->key);
    inorder(node->right, result);
}
