#include <iostream>
#include "Node.h"
#include "AVL.h"

using namespace std;

int main() {

/*    Node racine;
    Node fils1;
    Node fils2;
    Node fils3;
    Node fils4;
    Node fils5;
    Node fils6;
    Node fils7;

    racine.setKey(32);
    fils1.setKey(23);
    racine.setLeftNode(&fils1);
    fils2.setKey(51);
    racine.setRightNode(&fils2);
    fils3.setKey(21);
    fils1.setLeftNode(&fils3);
    fils4.setKey(24);
    fils1.setRightNode(&fils4);
    fils5.setKey(17);
    fils3.setLeftNode(&fils5);
    fils6.setKey(59);
    fils2.setRightNode(&fils6);

    // Test affichage : Le resultat qu'on doit avoir pour le deuxième test

    AVLTree treeTest;

    treeTest.add(&racine);
    treeTest.add(&fils1);
    treeTest.add(&fils2);
    treeTest.add(&fils3);
    treeTest.add(&fils4);
    treeTest.add(&fils5);
    treeTest.add(&fils6);

    treeTest.display();*/

/*
 * Résultat à avoir pour le réequilibrage

* 		_44_
       /    \
  	  32     51
 */
    AVLTree tree;

    tree.add(51);
    tree.add(44);
    tree.add(32);
/*    tree.add(26);
    tree.add(17);
    tree.add(59);
    tree.add(23);
    tree.add(21);
    tree.add(24); */

    tree.balanceTree(tree.m_root);
    tree.display();
//    tree.deleteNode(26);
//	tree.deleteNode(44);

	std::cout << " \nFin !!" << std::endl;
    return 0;
}
