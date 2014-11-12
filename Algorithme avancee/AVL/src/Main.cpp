#include <iostream>
#include <cstdlib> // system()
#include <fstream> // ofstream

#include "AVL.h"

using namespace std;

string outputFileName = "result";

void unbalancedRight(AVLTree &avl ) // Ok
{
/*         |-----5-----|
*      |---3---|       7
* |----2       4
* 1
*/
    avl.clear();
    avl.add( 5 );
    avl.add( 3 );
    avl.add( 7 );
    avl.add( 2 );
    avl.add( 4 );
    avl.add( 1 );
}

//void unbalancedRightIntern( TreeAVL<int> & avl )
//{
///* |-------10------|
//* |-------5-------| 15
//* 1 |---7
//* 6
//*/
//avl.clear();
//avl.insert( 10 );
//avl.insert( 5 );
//avl.insert( 15 );
//avl.insert( 1 );
//avl.insert( 7 );
//avl.insert( 6 );
//}
//void unbalancedRight2( TreeAVL<int> & avl )
//{
///* |---5---|
//* |---3 9
//* |----2
//* 1
//*/
//avl.clear();
//avl.insert( 5 );
//avl.insert( 3 );
//avl.insert( 9 );
//avl.insert( 2 );
//avl.insert( 1 );
//}

// Pas ok
void unbalancedLeft(AVLTree &avl)
{
    avl.clear();
    avl.add(5);
    avl.add(3);
    avl.add(7);
    avl.add(8);
    avl.add(9);
}

//void unbalancedLeftIntern( TreeAVL<int> & avl )
//{
///* |-------10------|
//* 5 |----15----|
//* |--12 20
//* 11
//*/
//avl.clear();
//avl.insert( 10 );
//avl.insert( 5 );
//avl.insert( 15 );
//avl.insert( 12 );
//avl.insert( 20 );
//avl.insert( 11 );
//}
//void randomFill( int nb, int min, int max, TreeAVL<int> & avl )
//{
//avl.clear();
//srand( time( NULL ) );
//int a = 0;
//for( int i = 0; i < nb; ++i )
//{
//a = rand()%(max-min) + min;
//avl.insert( a );
//}
//}


void outputResult(AVLTree tree) {

    string fileName = outputFileName + ".dot";
    ofstream os(fileName.c_str(), ios::out);

    os << "digraph G { " << "\n";
    os << tree.toString();
    os << "\n}";

    os.close();

    string command = "dot -Tpdf " + outputFileName + ".dot -o " + outputFileName + ".pdf";
    system(command.c_str());
}

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

    AVLTree tree;

    tree.add(51);
    tree.add(44);
    tree.add(32);

//    std::cout << tree.isBalance() << std::endl;

    tree.add(26);

//    std::cout << tree.isBalance() << std::endl;

    tree.add(17);

//    std::cout << tree.isBalance() << std::endl;

    tree.add(59);

//    std::cout << tree.isBalance() << std::endl;

    tree.add(23);

 //   std::cout << tree.isBalance() << std::endl;

    tree.add(21);

//    std::cout << tree.isBalance() << std::endl;

    tree.add(24);

    //std::cout << "Unbalanced Right Test : " << std::endl;

    //unbalancedRight(tree);
    tree.display();

    //std::cout << "Unbalanced Left Test : " << std::endl;

    //unbalancedLeft(tree);
    // tree.display();

    // tree.balanceTree(tree.m_root);

//  tree.deleteNode(26);
//  tree.deleteNode(44);

    outputResult(tree);

    return 0;
}
