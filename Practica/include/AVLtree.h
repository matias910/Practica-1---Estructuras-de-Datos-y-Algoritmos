//
// Created by matias on 3/21/26.
//

#ifndef PRACTICA_1_ESTRUCTURAS_DE_DATOS_Y_ALGORITMOS_AVLTREE_H
#define PRACTICA_1_ESTRUCTURAS_DE_DATOS_Y_ALGORITMOS_AVLTREE_H

#pragma once
#include <string>
#include <vector>

struct AVLNode {
    std::string key;
    AVLNode*    left;
    AVLNode*    right;
    int         height;

    explicit AVLNode(const std::string& k)
        : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
public:
    AVLTree();
    ~AVLTree();

    void   insert(const std::string& key);
    void   inorder(std::vector<std::string>& result) const;
    size_t memoryUsage() const;

private:
    AVLNode* root_;
    size_t   nodeCount_;

    AVLNode* insert(AVLNode* node, const std::string& key);
    void     inorder(AVLNode* node, std::vector<std::string>& result) const;
    void     destroy(AVLNode* node);

    int      height(AVLNode* node) const;
    int      balanceFactor(AVLNode* node) const;
    void     updateHeight(AVLNode* node);

    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* x);
    AVLNode* balance(AVLNode* node);
};


#endif //PRACTICA_1_ESTRUCTURAS_DE_DATOS_Y_ALGORITMOS_AVLTREE_H