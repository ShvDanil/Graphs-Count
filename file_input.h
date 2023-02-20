#pragma once

#include "graph.h"

/// Проверка на существование файла.
bool IsFilePathExist(const std::string& path);

/// Получение пути к исходному файлу.
std::string GetFilePath();

/// Получение числа вершин с файла.
std::pair<bool, int32_t> GetVertexesAmountFromFile();

/// Получение вершин графа с файла.
bool TryGetGraphVertexesFromFile(Graph& graph, const std::string &file_path);

/// Получение числа ребер с файла.
std::pair<bool, int32_t> GetEdgesAmountFromFile(const Graph& graph,
                                                const unsigned long& max_edges_available_amount);

/// Получение ребер графа с файла.
bool TryGetGraphEdgesFromFile(Graph& graph, const std::string& file_path,
                              const unsigned long& max_edges_available_amount,
                              const std::string& graph_type, const std::string& loops_usage);

/// Основной метод получения исходных данных от пользователя с файла.
Graph GetDataFromFile(Graph& graph, std::string& graph_type, std::string& loops_usage);
