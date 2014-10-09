#include <iostream>
#include "Node.h"

Node::Node()
{
    this->m_key = 0;
    this->m_h = 0;
    this->m_leftNode = NULL;
    this->m_rightNode = NULL;
}

void Node::setLeftNode(Node* node)
{
    m_leftNode = node;
}

void Node::setRightNode(Node* node)
{
    m_rightNode = node;
}

void Node::setKey(unsigned key)
{
    m_key = key;
}

void Node::setH(unsigned h)
{
    m_h = h;
}

unsigned Node::getKey() const
{
    return m_key;
}

unsigned Node::getH() const
{
    return m_h;
}

Node* Node::getLeftNode() const
{
    return m_leftNode;
}

Node* Node::getRightNode() const
{
    return m_rightNode;
}

void Node::display() const
{
}
}
