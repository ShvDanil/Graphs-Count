#pragma once

#include "defines.h"
#include "iostream"
#include "sstream"
#include "vector"

/**
 * Структура - матрица смежности.
 */
struct AdjacencyMatrix {
    // Матрица смежности (вектор векторов int32_t) с данными о наличии / отсутствии ребра между вершинами.
    std::vector<std::vector<int32_t>> adj_matrix{};

    /**
     * Подсчитывает максимальную длину слова - названия вершины.
     *
     * @param vertexes Названия вершин графа.
     * @return Максимальную длину слова.
     */
    static unsigned int GetMaxWordLength(std::vector<std::string>& vertexes) {
        unsigned int max_len = 0;

        for (const auto& vertex : vertexes) {
            if (vertex.length() > max_len) {
                max_len = vertex.length();
            }
        }

        return max_len;
    }

    /**
     * Печатает на экран данные матрицы смежности.
     *
     * @param vertexes Названия вершин графа.
     */
    void PrintAdjacencyMatrix(std::vector<std::string>& vertexes) {
        unsigned int max_vertex_len = GetMaxWordLength(vertexes);

        std::cout << std::string(max_vertex_len + 4, ' ');
        for (const auto& vertex : vertexes) {
            std::cout << MAGENTA << vertex
            << std::string(max_vertex_len - vertex.length() + 4, ' ') << RES_COL;
        }
        std::cout << "\n";

        for (auto i = 0; i < adj_matrix.size(); ++i) {
            std::cout << MAGENTA << vertexes[i]
            << std::string(max_vertex_len - vertexes[i].length() + 4, ' ') << RES_COL;
            for (int j : adj_matrix[i]) {
                std::cout << j << std::string(max_vertex_len + 3, ' ');
            }
            std::cout << "\n";
        }
    }
};
