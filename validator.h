#pragma once

#include "graph.h"
#include "string"

/// Получение максимально доступного числа ребер.
unsigned long GetMaxEdgesAvailableAmount(unsigned long vertexes_amount, std::string& graph_type,
                                         std::string& loops_usage);

/// Проверка наличия вершины в графе.
bool IsVertexInGraphVertexes(const std::string& vertex, const Graph& graph, std::string& log_message);

/// Проверка пары вершин на условие петли.
bool IsVertexPairLoop(const std::pair<std::string, std::string>& vertexes, std::string& log_message);

/// Проверка наличия пары вершин в графе.
bool IsVertexPairInGraphEdges(const std::pair<std::string, std::string>& vertexes, const Graph& graph,
                              std::string& log_message);

/// Проверка валидности пары вершин.
std::pair<bool, std::string> AreVertexesValid(const std::string& vertex1, const std::string& vertex2,
                                              const Graph& graph, const std::string& graph_type,
                                              const std::string& loops_usage);
