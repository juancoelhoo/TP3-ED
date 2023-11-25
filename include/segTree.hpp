#include <iostream>
#include "../include/matrix.hpp"

#define MOD 100000000

using namespace std;

class segTree {
    private:
        Matrix* Tree; // Árvore de segmentação
        int maxNodes;

    public:
        Matrix* transforms;

        segTree(unsigned int n);

        ~segTree();

        // Função para multiplicar duas matrizes
        Matrix multiply_matrices(const Matrix matrix1, const Matrix matrix2);

        // Função para construir a árvore de segmentação
        void build(int node, int start, int end);

        // Função para atualizar uma transformação
        void update(int node, int start, int end, int idx, const Matrix newValue);
            

        // Função para realizar uma consulta
        Matrix query(int node, int start, int end, int left, int right);

};