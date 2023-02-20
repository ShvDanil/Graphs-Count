#include "validator.h"

/**
 * Получение максимально доступного числа ребер.
 *
 * @param vertexes_amount Число вершин.
 * @param graph_type Вид графа.
 * @param loops_usage Наличие / отсутствие петель.
 * @return Максимально доступное число ребер.
 */
unsigned long GetMaxEdgesAvailableAmount(unsigned long vertexes_amount, std::string& graph_type,
                                   std::string& loops_usage) {
    if (graph_type == "non-orgraph") {
        return loops_usage == "no-use"
                ? (vertexes_amount * (vertexes_amount - 1)) / 2
                : (vertexes_amount * (vertexes_amount + 1)) / 2;
    } else {
        return loops_usage == "no-use"
                ? vertexes_amount * (vertexes_amount - 1)
                : vertexes_amount * vertexes_amount;
    }
}

/**
 * Проверка наличия вершины в графе.
 *
 * @param vertex Вершина, название которой необходимо проверить.
 * @param graph Исходный граф с данными.
 * @param log_message Сообщение с результатом операции.
 * @return Результат проверки (true - вершина присутствует, false - вершина отсутствует).
 */
bool IsVertexInGraphVertexes(const std::string& vertex, const Graph& graph, std::string& log_message) {
    if (std::find(graph.vertexes.begin(), graph.vertexes.end(), vertex) == graph.vertexes.end()) {
        log_message = "в графе отсутствует вершина " + vertex;
        return false;
    }

    return true;
}

/**
 * Проверка пары вершин на условие петли.
 *
 * @param vertexes Пара вершин.
 * @param log_message Сообщение с результатом операции.
 * @return Результат проверки (true - пара вершин петля, false - пара вершин не петля).
 */
bool IsVertexPairLoop(const std::pair<std::string, std::string>& vertexes, std::string& log_message) {
    if (vertexes.first == vertexes.second) {
        log_message = "выбран граф без петель, поэтому вершины должны отличаться";
        return false;
    }

    return true;
}

/**
 * Проверка наличия пары вершин в графе.
 *
 * @param vertexes Пара вершин.
 * @param graph Исходный граф.
 * @param log_message Сообщение с результатом операции.
 * @return Результат проверки (true - пара вершин присутствует, false - пара вершин отсутствует).
 */
bool IsVertexPairInGraphEdges(const std::pair<std::string, std::string>& vertexes, const Graph& graph,
                              std::string& log_message) {
    if (std::find(graph.edges.begin(), graph.edges.end(), vertexes) != graph.edges.end()) {
        log_message = "в графе отсутствуют кратные ребра, каждое ребро уникально";
        return false;
    }

    return true;
}

/**
 * Проверка валидности пары вершин.
 *
 * @param vertex1 Вершина №1.
 * @param vertex2 Вершина №2.
 * @param graph Исходный граф.
 * @param graph_type Вид графа.
 * @param loops_usage Наличие / отсутствие петель.
 * @return Пару (результат операции: true - валидная пара, false - не валидная;
 * строка - сообщение с результатом операции).
 */
std::pair<bool, std::string> AreVertexesValid(const std::string& vertex1, const std::string& vertex2,
                                              const Graph& graph, const std::string& graph_type,
                                              const std::string& loops_usage) {
    std::string log_message = "valid";
    // Проверка валидности каждой из полученных вершин.
    if (!IsVertexInGraphVertexes(vertex1, graph, log_message)) {
        return std::make_pair(false, log_message);
    }
    if (!IsVertexInGraphVertexes(vertex2, graph, log_message)) {
        return std::make_pair(false, log_message);
    }

    std::pair<std::string, std::string> vertexes_pair_1 = std::make_pair(vertex1, vertex2);
    std::pair<std::string, std::string> vertexes_pair_2 = std::make_pair(vertex2, vertex1);

    if (graph_type == "non-orgraph") {
        if (loops_usage == "no-use") {
            if (!IsVertexPairLoop(vertexes_pair_1, log_message)) {
                return std::make_pair(false, log_message);
            }
        }
        if (!IsVertexPairInGraphEdges(vertexes_pair_1, graph, log_message)) {
            return std::make_pair(false, log_message);
        }
        if (!IsVertexPairInGraphEdges(vertexes_pair_2, graph, log_message)) {
            return std::make_pair(false, log_message);
        }
    } else {
        if (loops_usage == "no-use") {
            if (!IsVertexPairLoop(vertexes_pair_1, log_message)) {
                return std::make_pair(false, log_message);
            }
        }
        if (!IsVertexPairInGraphEdges(vertexes_pair_1, graph, log_message)) {
            return std::make_pair(false, log_message);
        }
    }

    return std::make_pair(true, log_message);
}
