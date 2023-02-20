#pragma once

#include "adjacency_list.h"
#include "adjacency_matrix.h"
#include "edges_list.h"
#include "incidence_matrix.h"
#include "list"
#include "map"
#include "string"
#include "vector"

/**
 * Вспомогательная структура - граф.
 */
struct Graph {
    // Вектор, содержащий информацию о вершинах графа (строки).
    std::vector<std::string> vertexes;
    // Вектор пар строк (вершины, образующие ребра).
    std::vector<std::pair<std::string, std::string>> edges;

    /**
     * Преобразование вспомогательного графа к виду матрицы смежности.
     *
     * @return Матрица смежности с данными о вершинах и ребрах графа.
     */
    AdjacencyMatrix TransformToAdjacencyMatrix() {
        auto adj_matrix = AdjacencyMatrix();

        adj_matrix.adj_matrix.resize(vertexes.size());
        // Заполнение матрицы смежности значениями 0 / 1.
        for (auto i = 0; i < vertexes.size(); ++i) {
            for (const auto& vertex : vertexes) {
                std::find(edges.begin(), edges.end(),std::make_pair(vertexes[i], vertex))
                        == edges.end()
                        ? adj_matrix.adj_matrix[i].emplace_back(0)
                        : adj_matrix.adj_matrix[i].emplace_back(1);
            }
        }

        return adj_matrix;
    }

    /**
     * Преобразование вспомогательного графа к виду матрицы инцидентности.
     *
     * @param graph_type Вид графа.
     * @return Матрица инцидентности с данными о вершинах и ребрах графа.
     */
    IncidenceMatrix TransformToIncidenceMatrix(const std::string& graph_type) {
        auto inc_matrix = IncidenceMatrix();

        inc_matrix.inc_matrix.resize(vertexes.size(), std::vector<int32_t>(edges.size()));
        // Заполнение матрицы инцидентности значениями -1 / 0 / 1.
        for (auto i = 0; i < vertexes.size(); ++i) {
            inc_matrix.inc_matrix[i].resize(edges.size());
            for (auto j = 0; j < edges.size(); ++j) {
                if (graph_type == "non-orgraph") {
                    if (vertexes[i] == edges[j].first || vertexes[i] == edges[j].second) {
                        inc_matrix.inc_matrix[i][j] = 1;
                    } else {
                        inc_matrix.inc_matrix[i][j] = 0;
                    }
                } else {
                    if (vertexes[i] == edges[j].first) {
                        inc_matrix.inc_matrix[i][j] = 1;
                    } else if (vertexes[i] == edges[j].second) {
                        inc_matrix.inc_matrix[i][j] = -1;
                    } else {
                        inc_matrix.inc_matrix[i][j] = 0;
                    }
                }
            }
        }

        return inc_matrix;
    }

    /**
     * Преобразование вспомогательного графа к виду списка смежности.
     *
     * @return Список смежности с данными о вершинах и ребрах графа.
     */
    AdjacencyList TransformToAdjacencyList() {
        auto adj_list = AdjacencyList();

        for (auto& vertex : vertexes) {
            adj_list.adj_list[vertex] = {};
        }
        for (auto& edge : edges) {
            adj_list.adj_list[edge.first].emplace(edge.second);
        }

        return adj_list;
    }

    /**
     * Преобразование вспомогательного графа к виду списка ребер.
     *
     * @return Список ребер с данными о ребрах графа.
     */
    EdgesList TransformToEdgesList() {
        auto edg_list = EdgesList();

        for (auto& edge : edges) {
            edg_list.edj_list.emplace_back(edge);
        }

        return edg_list;
    }
};
