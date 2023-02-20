#pragma once

#include "defines.h"
#include "vector"

/**
 * Структура - матрица инцидентности.
 */
struct IncidenceMatrix {
    // Матрица инцидентности (вектор векторов int32_t) с данными о ребрах.
    std::vector<std::vector<int32_t>> inc_matrix;

    /**
     * Подсчитывает максимальную длину слова - названия вершины (среди ребер).
     *
     * @param edges Вектор ребер (или пар вершин).
     * @return Максимальную длину слова.
     */
    static unsigned int GetMaxWordLength(std::vector<std::pair<std::string, std::string>>& edges) {
        unsigned int max_len = 0;

        for (const auto& edge : edges) {
            if (edge.first.length() + edge.second.length() > max_len) {
                max_len = edge.first.length() + edge.second.length();
            }
        }

        return max_len;
    }

    /**
     * Печатает на экран данные матрицы инцидентности.
     *
     * @param vertexes Вершины графа.
     * @param edges Ребра графа.
     */
    void PrintIncidenceMatrix(std::vector<std::string>& vertexes,
                              std::vector<std::pair<std::string, std::string>>& edges) {
        unsigned int max_vertex_len = GetMaxWordLength(edges);

        std::cout << std::string(max_vertex_len + 4, ' ');
        for (const auto& edge : edges) {
            std::cout << MAGENTA << edge.first << " " << edge.second << RES_COL
            << std::string(max_vertex_len - (edge.first.length() + edge.second.length()) + 4, ' ');
        }
        std::cout << "\n";

        for (auto i = 0; i < inc_matrix.size(); ++i) {
            std::cout << MAGENTA << vertexes[i]
            << std::string(max_vertex_len - vertexes[i].length() + 4, ' ') << RES_COL;
            for (int j : inc_matrix[i]) {
                if (std::to_string(j).length() == 2) {
                    std::cout << j << std::string(max_vertex_len + 3, ' ');
                } else {
                    std::cout << " " << j << std::string(max_vertex_len + 3, ' ');
                }
            }
            std::cout << "\n";
        }
    }
};
