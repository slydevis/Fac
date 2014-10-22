#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <deque>

#include "Node.h"

using namespace std;

Node::Node()
{
    this->m_key = 0;
    this->m_h = 0;
    this->m_leftNode = NULL;
    this->m_rightNode = NULL;
}

Node::Node(unsigned key)
{
	this->m_key = key;
	this->m_h = 0;
	this->m_leftNode = NULL;
	this->m_rightNode = NULL;
}

















int Node::maxHeight(Node *p) {
	if (!p)
	  return 0;
	int leftHeight = maxHeight(p->getLeftNode());
	int rightHeight = maxHeight(p->getRightNode());
	return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}











void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<Node*>& nodesQueue) {
	deque<Node*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel / 2; i++) {
    cout << ((i == 0) ? setw(startLen-1) : setw(nodeSpaceLen-2)) << "" << ((*iter++) ? "/" : " ");
    cout << setw(2*branchLen+2) << "" << ((*iter++) ? "\\" : " ");
  }
  cout << endl;
}


string intToString(int val) {
  ostringstream ss;
  ss << val;
  return ss.str();
}

void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<Node*>& nodesQueue) {
	deque<Node*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    cout << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->getLeftNode()) ? setfill('_') : setfill(' '));
    cout << setw(branchLen+2) << ((*iter) ? intToString((*iter)->getKey()) : "");
    cout << ((*iter && (*iter)->getRightNode()) ? setfill('_') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
  }
  cout << endl;
}

void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<Node*>& nodesQueue) {
	deque<Node*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    cout << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << ((*iter) ? intToString((*iter)->getKey()) : "");
  }
  cout << endl;
}

void Node::display(Node *root, int level, int indentSpace) {
  int h = Node::maxHeight(root);
  int nodesInThisLevel = 1;

  int branchLen = 2*((int)pow(2.0,h)-1) - (3-level)*(int)pow(2.0,h-1);  // eq of the length of branch for each node of each level
  int nodeSpaceLen = 2 + (level+1)*(int)pow(2.0,h);  // distance between left neighbor node's right arm and right neighbor node's left arm
  int startLen = branchLen + (3-level) + indentSpace;  // starting space to the first node to print of each level (for the left most node of each level only)

  deque<Node*> nodesQueue;
  nodesQueue.push_back(root);
  for (int r = 1; r < h; r++) {
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue);
    branchLen = branchLen/2 - 1;
    nodeSpaceLen = nodeSpaceLen/2 + 1;
    startLen = branchLen + (3-level) + indentSpace;
    printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue);

    for (int i = 0; i < nodesInThisLevel; i++) {
      Node *currNode = nodesQueue.front();
      nodesQueue.pop_front();
      if (currNode) {
          nodesQueue.push_back(currNode->getLeftNode());
          nodesQueue.push_back(currNode->getRightNode());
      } else {
        nodesQueue.push_back(NULL);
        nodesQueue.push_back(NULL);
      }
    }
    nodesInThisLevel *= 2;
  }
  printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue);
  printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue);
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

std::string Node::toString() const
{
    std::ostringstream os;

    os 		<< "\n" << "Node : " << "{ m_key = "
    		<< m_key << ", m_h = " << m_h  << "}";

    if(m_leftNode != NULL)
    	os << "\nLeft Node : " << m_leftNode->toString();
    if(m_rightNode != NULL)
    	os << "\nRight Node : " << m_rightNode->toString();

    return os.str();
}
