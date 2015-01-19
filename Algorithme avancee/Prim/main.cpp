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

    void test1()
    {
        CGraph graph;

        graph.add(5);
        graph.add(3, 5, 5);
        graph.add(6, 5, 6);
        graph.add(1, 6, 1);
        graph.add(4, 6, 3);
        graph.link(3, 6, 8);

        // Création du graphe de base

        outputResult(graph, "graphe1");

        // On sort un fichier représentant le graphe de base

        CGraph graphAfterPrim = graph.prim();

        // On sort un fichier représentant le graphe de base

        outputResult(graphAfterPrim, "prim1.result");

        std::cout << "Ultrametrique(5,4) = " << graphAfterPrim.ultraMetric(5,4) << std::endl;
    }

    void test2()
    {
        CGraph graph;

        graph.add(5);
        graph.add(8, 5, 5);
        graph.add(4, 8, 5);
        graph.add(2, 8, 6);
        graph.add(1, 2, 3);
        graph.link(1, 4, 15);
        graph.link(2, 8, 5);
        graph.link(2, 8, 10);

        // Création du graphe de base

        outputResult(graph, "graphe2");

        // On sort un fichier représentant le graphe de base

        CGraph graphAfterPrim = graph.prim();

        // On sort un fichier représentant le graphe de base

        outputResult(graphAfterPrim, "prim2.result");

        std::cout << "Ultrametrique(5,1) = " << graphAfterPrim.ultraMetric(5,1) << std::endl;
    }
}
int main() {
	test1();
	test2();
    std::cout << "Fini !" << std::endl;
    return 0;
}
