#pragma once

#include "graph.h"
#include "iostream"

/// Определение вида графа.
std::string GetGraphType();

/// Получение информации об использовании петель.
std::string GetLoopsUsage();

/// Получение информации о типе представления графа в памяти.
std::string GetStorageType();

/// Получение информации о типе ввода данных.
std::string GetInputType();

/// Получение исходных данных от пользователя и запись их в граф.
Graph GetSourceData(std::string& graph_type, std::string& loops_usage, std::string& input_type);

/// Получение описания полученного графа.
std::string GetChosenGraphDescription(const std::string& input_type, const std::string& graph_type,
                                      const std::string& loops_usage);

/// Вывод представления графа.
void PrintGraphRepresentationInMemory(Graph& graph, const std::string& storage_type,
                                      const std::string& graph_type);

/// Получение пункта функционала, который необходимо выполнить.
int32_t GetFunctionalityNumberToExecute();

/// Печать степени графа.
void PrintVertexesDegree(const Graph& graph, const std::string& graph_type);

/// Печать количества ребер графа.
void PrintEdgesAmount(const Graph& graph);

/// Получение нового типа представления графа.
std::string GetNewStorageType(const std::string& old_storage_type);
