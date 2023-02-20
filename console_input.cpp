#include "console_input.h"
#include "defines.h"
#include "graph.h"
#include "inner_helper.h"
#include "validator.h"

/**
 * Получает число вершин, введенных пользователем с консоли.
 *
 * @return Число вершин.
 */
int32_t GetVertexesAmountFromConsole() {
    std::cout << MAGENTA "\n[ВЕРШИНЫ]" RES_COL "\n";
    std::cout << "{~количество~}" MAGENTA " ——" GREEN ">>\t" RES_COL;

    int32_t amount;
    std::cin >> amount;

    // Сообщение об ошибке и запрос повтора ввода в случае некорректных данных.
    while (std::cin.fail() || amount <= 0 || amount > INT32_MAX) {
        PrintErrorMessage();
        IgnoreAndClearFurtherIncorrectInput();
        std::cout << "\n{~количество~}" MAGENTA " ——" GREEN ">>\t" RES_COL;
        std::cin >> amount;
    }
    IgnoreAndClearFurtherIncorrectInput();

    return amount;
}

/**
 * Получает вершины графа с консоли.
 *
 * @param graph Исходный граф.
 */
void TryGetGraphVertexesFromConsole(Graph& graph) {
    // Получение числа вершин в графе.
    int32_t vertexes_amount = GetVertexesAmountFromConsole();

    // Получение вершин графа.
    std::string vertex;
    for (auto i = 0; i < vertexes_amount; ++i) {
        std::cout << MAGENTA "\n[INFO]" << RES_COL "\tвсего вершин: " << vertexes_amount
                  << MAGENTA "\t|\t" RES_COL "осталось вершин: " << vertexes_amount - i << "\n";
        std::cout << "\n{~" << i + 1 << " вершина~}" MAGENTA " ——" GREEN ">>\t" RES_COL;
        std::cin >> vertex;
        std::string log_message;

        // Сообщение об ошибке и запрос повтора ввода в случае некорректных данных.
        while (!graph.vertexes.empty() && IsVertexInGraphVertexes(vertex, graph, log_message)) {
            IgnoreAndClearFurtherIncorrectInput();
            PrintErrorMessage();
            log_message = "в графе уже присутствует вершина " + vertex;
            PrintHintMessage(log_message);
            std::cout << "\n{~" << i + 1 << " вершина~}" MAGENTA " ——" GREEN ">>\t" RES_COL;
            std::cin >> vertex;
        }
        graph.vertexes.emplace_back(vertex);
        IgnoreAndClearFurtherIncorrectInput();
    }

    // Сообщение об успехе совершенной операции.
    std::string success_message = "Данные о вершинах " MAGENTA "успешно " RES_COL "получены!\n";
    PrintSuccessMessage(success_message);
}

/**
 * Получает число ребер, введенных пользователем с консоли.
 *
 * @param graph Исходный граф.
 * @param max_edges_available_amount Максимально доступное число ребер в графе.
 * @return Число ребер.
 */
int32_t GetEdgesAmountFromConsole(const Graph& graph, const unsigned long& max_edges_available_amount) {
    std::cout << MAGENTA "\n[РЕБРА]" RES_COL "\n";
    std::cout << "{~количество~}" MAGENTA " ——" GREEN ">>\t" RES_COL;

    int32_t amount;
    std::cin >> amount;

    // Сообщение об ошибке и запрос повтора ввода в случае некорректных данных.
    while (std::cin.fail() || amount < 0 || amount > max_edges_available_amount) {
        PrintErrorMessage();
        PrintHintMessage("количество ребер должно находиться в диапазоне от 0 до " +
                         std::to_string(max_edges_available_amount));
        IgnoreAndClearFurtherIncorrectInput();
        std::cout << "\n{~количество~}" MAGENTA " ——" GREEN ">>\t" RES_COL;
        std::cin >> amount;
    }
    IgnoreAndClearFurtherIncorrectInput();

    return amount;
}

/**
 * Получает ребра графа с консоли.
 *
 * @param graph Исходный граф.
 * @param max_amount Максимально доступное число ребер в графе.
 * @param graph_type Вид графа.
 * @param loops_usage Информация об использовании петель.
 */
void TryGetGraphEdgesFromConsole(Graph& graph, const unsigned long& max_amount,
                                 const std::string& graph_type, const std::string& loops_usage) {
    // Получение числа ребер графа.
    unsigned long edges_amount = GetEdgesAmountFromConsole(graph, max_amount);

    // Получение ребер графа.
    std::string vertex1, vertex2;
    for (auto i = 0; i < edges_amount; ++i) {
        std::cout <<  MAGENTA "\n[INFO]" << RES_COL "\tвсего ребер (пар вершин): " << edges_amount
                  << MAGENTA "\t|\t" RES_COL "осталось ребер (пар вершин): " << edges_amount - i << "\n";
        std::cout << "\n{~" << i + 1 << " пара вершин~}" MAGENTA " ——" GREEN ">>\t" RES_COL;

        std::cin >> vertex1 >> vertex2;
        // Сообщение об ошибке и запрос повтора ввода в случае некорректных данных.
        do {
            auto [are_vertexes_valid, validation_log_message] = AreVertexesValid(vertex1, vertex2,
                                                                                 graph, graph_type, loops_usage);
            if (!are_vertexes_valid) {
                IgnoreAndClearFurtherIncorrectInput();
                PrintErrorMessage();
                PrintHintMessage(validation_log_message);
                std::cout << "\n{~" << i + 1 << " пара вершин~}" MAGENTA " ——" GREEN ">>\t" RES_COL;
                std::cin >> vertex1 >> vertex2;
                continue;
            }
            break;
        } while (true);

        graph.edges.emplace_back(std::make_pair(vertex1, vertex2));
        IgnoreAndClearFurtherIncorrectInput();
    }

    // Сообщение об успехе совершенной операции.
    std::string success_message = "Данные о ребрах успешно получены!\n";
    PrintSuccessMessage(success_message);

    ConfirmContinueOperation();
}

/**
 * Основной метод получения исходных данных от пользователя с консоли.
 *
 * @param graph Исходный граф (изначально пустой).
 * @param graph_type Вид графа.
 * @param loops_usage Информация об использовании петель.
 * @return Исходный граф с информацией, полученной с консоли от пользователя.
 */
Graph GetDataFromConsole(Graph& graph, std::string& graph_type, std::string& loops_usage) {
    // Получение вершин.
    TryGetGraphVertexesFromConsole(graph);

    // Определение максимально доступного числа ребер.
    unsigned long max_edges_available_amount = GetMaxEdgesAvailableAmount(graph.vertexes.size(),
                                                                      graph_type, loops_usage);

    // Получение ребер.
    TryGetGraphEdgesFromConsole(graph, max_edges_available_amount, graph_type, loops_usage);

    return graph;
}
