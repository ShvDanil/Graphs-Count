#pragma once

#include "graph.h"

/// Получение числа вершин, введенных пользователем с консоли.
int32_t GetVertexesAmountFromConsole();

/// Получение вершин графа с консоли.
void TryGetGraphVertexesFromConsole(Graph& graph);

/// Получение числа ребер, введенных пользователем с консоли.
int32_t GetEdgesAmountFromConsole(const Graph& graph,
                                  const unsigned long& max_edges_available_amount);

/// Получение ребер графа с консоли.
void TryGetGraphEdgesFromConsole(Graph& graph, const unsigned long& max_amount,
                                 const std::string& graph_type, const std::string& loops_usage);

/// Основной метод получения исходных данных от пользователя с консоли.
Graph GetDataFromConsole(Graph& graph, std::string& graph_type, std::string& loops_usage);
