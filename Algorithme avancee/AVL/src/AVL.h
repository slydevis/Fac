#ifndef __AVL_H__
#define __AVL_H__

#include <vector>
#include "Node.h"

class AVLTree
{
private :
    void swapinessNode(Node * currentNode);
public :
    Node* m_root;

    AVLTree();
    void add(unsigned key);
    void add(Node* node);
    void deleteNode(unsigned key);
    void display() const;
    std::string toString() const;
    void balanceTree(Node* currentNode);

};
#endif /* __AVL_H__ */
