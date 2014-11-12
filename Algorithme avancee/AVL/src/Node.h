#ifndef __NODE_H__
#define __NODE_H__

#include <string>

class Node
{
private :
    unsigned m_key;
    unsigned m_h;
    Node* m_leftNode;
    Node* m_rightNode;
    Node* m_parent;
public :
    Node();
    Node(unsigned key);
    void setLeftNode(Node* node);
    void setRightNode(Node* node);
    void setParent(Node* node);
    void setKey(unsigned key);
    void setH(unsigned h);
    void updateH();
    std::string toString() const;
    unsigned getKey() const;
    unsigned getH() const;
    Node* getLeftNode() const;
    Node* getRightNode() const;
    Node* getParent() const;
    static int maxHeight(Node *p);
    static void display(Node *root, int level, int indentSpace);
};

#endif /* __NODE_H__ */
