#ifndef __AVL_H__
#define __AVL_H__

#include <vector>
#include "Node.h"

class AVLTree
{
private :
    bool isBalanceRec(Node* currentNode) const;
public :
    Node* m_root;

    AVLTree();
    void add(unsigned key);
    void add(Node* node);
    bool contain(unsigned key) const;
    void clear();
    void deleteNode(unsigned key);
    void display() const;
    void updateH();
    std::string toString() const;
    void balanceTree(Node* currentNode);
    void leftRotation(Node* currentNode);
    void rightRotation(Node* currentNode);
    bool isBalance() const;
};
#endif /* __AVL_H__ */
