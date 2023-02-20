#pragma once

#include "defines.h"
#include "list"
#include "iostream"

/**
 * Структура - список ребер.
 */
struct EdgesList {
    // Лист, содержащий пары строк (ребер).
    std::list<std::pair<std::string, std::string>> edj_list;

    /**
     * Печатает на экран данные списка ребер.
     */
    void PrintEdgesList() {
        for (const auto& edges_pair : edj_list) {
            std::cout << edges_pair.first << GREEN " <" MAGENTA << "——" GREEN "> " RES_COL
                        << edges_pair.second << "\n";
        }
    }
};
