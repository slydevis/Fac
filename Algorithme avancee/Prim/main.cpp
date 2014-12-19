#include <iostream>
#include <stdlib.h>
#include <fstream> // ofstream()

#include "CGraph.h"

using namespace std;

namespace {
    void outputResult(CGraph graph, string outputFileName) {

        string fileName = outputFileName + ".dot";
        ofstream os(fileName.c_str(), ios::out);

        os << "graph G { " << "\n";
        os << graph.toString();
        os << "\n}";

        os.close();

        string command = "dot -Tpdf " + outputFileName + ".dot -o " + outputFileName + ".pdf";
        system(command.c_str());
    }
}
int main() {
    CGraph graph;

    graph.add(5);
    graph.add(3, 5, 5);
    graph.add(6, 5, 6);
    graph.add(8, 5, 7);
    graph.add(1, 6, 1);
    graph.add(4, 6, 3);
    graph.link(4, 8, 2);
    graph.link(3, 6, 8);

    // Création du graphe de base

    outputResult(graph, "graphe");

    // On sort un fichier représentant le graphe de base

    CGraph graphAfterPrim = graph.prim();
    // std::cout << "graph prim = " << graphAfterPrim.toString() << endl;

    // On sort un fichier représentant le graphe de base

    outputResult(graphAfterPrim, "prim.result");

    std::cout << "Fini !" << std::endl;
    return 0;
}
