#pragma once

#include "defines.h"
#include "iostream"
#include "map"
#include "set"

/**
 * Структура - список смежности.
 */
struct AdjacencyList {
    // Словарь, содержащий данные о вершинах (ключ) и смежных с ними ребрах (сет значений).
    std::map<std::string, std::set<std::string>> adj_list;

    /**
     * Печатает на экран данные списка смежности.
     */
    void PrintAdjacencyList() {
        for (const auto& [vertex, neighbours] : adj_list) {
            std::cout << MAGENTA << vertex << ":\t" RES_COL;
            if (neighbours.empty()) {
                std::cout << "данная вершина не соединена с другими!\n";
                continue;
            }
            for (const auto& v : neighbours) {
                std::cout << v << " ";
            }
            std::cout << "\n";
        }
    }
};
