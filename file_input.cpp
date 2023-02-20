#include "defines.h"
#include "file_input.h"
#include "fstream"
#include "graph.h"
#include "inner_helper.h"
#include "instructions.h"
#include "iostream"
#include "validator.h"

/**
 * Проверка на существование файла по указанному пользователем пути.
 *
 * @param path Путь к файлу.
 * @return true - если файл существует, false - если файл не существует.
 */
bool IsFilePathExist(const std::string& path) {
    if (FILE *file = fopen(path.c_str(), "r")) {
        fclose(file);
        return true;
    }

    return false;
}

/**
 * Получение пути к исходному файлу от пользователя.
 *
 * @return Строка - путь к файлу с данными.
 */
std::string GetFilePath() {
    std::string path;

    // Сообщение об ошибке и запрос повтора ввода в случае некорректных данных.
    while (true) {
        std::cout << MAGENTA " ——" GREEN ">>\t" RES_COL;
        std::cin >> path;
        IgnoreAndClearFurtherIncorrectInput();
        if (!IsFilePathExist(path)) {
            PrintErrorMessage();
            PrintHintMessage("не удалось найти / получить доступ к такому файлу");
            std::cout << "\n";
            continue;
        }
        // Проверка на соответствие расширению .txt.
        if (path.substr(path.find_last_of('.') + 1)  != "txt") {
            PrintErrorMessage();
            PrintHintMessage("файл должен иметь расширение '.txt'");
            std::cout << "\n";
            continue;
        }
        break;
    }

    return path;
}

/**
 * Получает число вершин, введенных пользователем с файла.
 *
 * @return Пара: результат операции (true / false) и число вершин.
 */
std::pair<bool, int32_t> GetVertexesAmountFromFile() {
    std::cout << MAGENTA "\n[ВЕРШИНЫ]" RES_COL "\n";
    std::cout << "{~количество~}" MAGENTA " ——" GREEN ">>\t" RES_COL;

    std::string amount_s;
    std::cin >> amount_s;
    IgnoreAndClearFurtherIncorrectInput();
    std::cout << amount_s << "\n";
    std::string log_message;
    // Попытка получить данные с файла.
    try {
        int32_t amount = std::stoi(amount_s);
        if (amount <= 0 || amount > INT32_MAX) {
            PrintErrorMessage();
            log_message = "аргумент находится не в диапазоне значений";
            PrintHintMessage(log_message);
            return std::make_pair(false, 0);
        }
    } catch (std::invalid_argument& e) {
        PrintErrorMessage();
        log_message = "ошибка на строке {1}: \t—>\t" + amount_s;
        PrintHintMessage(log_message);
        return std::make_pair(false, 0);
    } catch (...) {
        PrintErrorMessage();
        log_message = "ошибка при чтении данных из файла";
        PrintHintMessage(log_message);
        return std::make_pair(false, 0);
    }

    return std::make_pair(true, std::stoi(amount_s));
}

/**
 * Получает вершины графа с файла.
 *
 * @param graph Исходный граф.
 * @param file_path Путь к файлу.
 * @return Результат операции (true / false).
 */
bool TryGetGraphVertexesFromFile(Graph& graph, const std::string& file_path) {
    // Изменяем входной поток на поток исходного файла с данными.
    std::ifstream input_file(file_path);
    std::cin.rdbuf(input_file.rdbuf());
    // Получаем результат операции о числе вершин и число вершин.
    auto [amount_res, vertexes_amount] = GetVertexesAmountFromFile();
    if (!amount_res) {
        return false;
    }
    std::string log_message;
    std::string vertex;
    // Сообщение об ошибке в случае получения некорректных данных.
    for (auto i = 0; i < vertexes_amount; ++i) {
        std::cout << MAGENTA "\n[INFO]" << RES_COL "\tвсего вершин: " << vertexes_amount
                  << MAGENTA "\t|\t" RES_COL "осталось вершин: " << vertexes_amount - i << "\n";
        std::cout << "\n{~" << i + 1 << " вершина~}" MAGENTA " ——" GREEN ">>\t" RES_COL;
        std::cin >> vertex;
        IgnoreAndClearFurtherIncorrectInput();
        if (input_file.peek() == EOF) {
            PrintErrorMessage();
            log_message = "недостаточно входных данных";
            PrintHintMessage(log_message);
            return false;
        }
        std::cout << vertex << "\n";
        if (!graph.vertexes.empty() && IsVertexInGraphVertexes(vertex, graph, log_message)) {
            PrintErrorMessage();
            log_message = "в графе уже присутствует вершина " + vertex;
            PrintHintMessage(log_message);
            return false;
        }
        graph.vertexes.emplace_back(vertex);
    }
    // Сообщение об успехе совершенной операции.
    std::string success_message = "Данные о вершинах " MAGENTA "успешно " RES_COL "получены!\n";
    PrintSuccessMessage(success_message);

    return true;
}

/**
 * Получает число ребер c файла.
 *
 * @param graph Исходный граф.
 * @param max_edges_available_amount Максимально доступное число ребер в графе.
 * @return Пара: результат операции (true / false) и число ребер.
 */
std::pair<bool, int32_t> GetEdgesAmountFromFile(const Graph& graph,
                                                const unsigned long& max_edges_available_amount) {
    std::cout << MAGENTA "\n[РЕБРА]" RES_COL "\n";
    std::cout << "{~количество~}" MAGENTA " ——" GREEN ">>\t" RES_COL;

    std::string amount_s;
    std::cin >> amount_s;
    IgnoreAndClearFurtherIncorrectInput();
    std::cout << amount_s << "\n";
    std::string log_message;
    // Попытка получить данные с файла.
    try {
        int32_t amount = std::stoi(amount_s);
        if (amount < 0 || amount > max_edges_available_amount) {
            PrintErrorMessage();
            log_message = "количество ребер должно находиться в диапазоне от 0 до " +
                          std::to_string(max_edges_available_amount);
            PrintHintMessage(log_message);
            return std::make_pair(false, 0);
        }
    } catch (std::invalid_argument& e) {
        PrintErrorMessage();
        log_message = "ошибка на строке {" + std::to_string(graph.vertexes.size() + 2) + "}: \t—>\t"
                + amount_s;
        PrintHintMessage(log_message);
        return std::make_pair(false, 0);
    } catch (...) {
        PrintErrorMessage();
        log_message = "ошибка при чтении данных из файла";
        PrintHintMessage(log_message);
        return std::make_pair(false, 0);
    }

    return std::make_pair(true, std::stoi(amount_s));
}

/**
 * Получает ребра графа с файла.
 *
 * @param graph Исходный граф.
 * @param file_path Путь к файлу.
 * @param max_edges_available_amount Максимально доступное число ребер в графе.
 * @param graph_type Вид графа.
 * @param loops_usage Информация об использовании петель.
 * @return Результат операции (true / false).
 */
bool TryGetGraphEdgesFromFile(Graph& graph, const std::string& file_path,
                              const unsigned long& max_edges_available_amount,
                              const std::string& graph_type, const std::string& loops_usage) {
    // Изменяем входной поток на поток исходного файла с данными.
    std::ifstream input_file(file_path);
    // Сохраняем данные о предыдущем потоке (отвечает за консольный ввод / вывод).
    std::cin.rdbuf(input_file.rdbuf());
    std::string blank_str;
    for (auto i = 0; i < graph.vertexes.size() + 1; ++i) {
        std::cin >> blank_str;
        IgnoreAndClearFurtherIncorrectInput();
    }
    // Получаем результат операции о числе ребер и число ребер.
    auto [amount_res, edges_amount] = GetEdgesAmountFromFile(graph, max_edges_available_amount);
    if (!amount_res) {
        return false;
    }
    std::string vertex1, vertex2;
    // Сообщение об ошибке в случае некорректных данных.
    for (auto i = 0; i < edges_amount; ++i) {
        std::cout <<  MAGENTA "\n[INFO]" << RES_COL "\tвсего ребер (пар вершин): " << edges_amount
                  << MAGENTA "\t|\t" RES_COL "осталось ребер (пар вершин): " << edges_amount - i << "\n";
        std::cout << "\n{~" << i + 1 << " пара вершин~}" MAGENTA " ——" GREEN ">>\t" RES_COL;
        std::cin >> vertex1 >> vertex2;
        IgnoreAndClearFurtherIncorrectInput();
        if (input_file.peek() == EOF) {
            PrintErrorMessage();
            PrintHintMessage("недостаточно входных данных");
            return false;
        }
        std::cout << vertex1 << " " << vertex2 << "\n";
        auto [are_vertexes_valid, validation_log_message] = AreVertexesValid(vertex1, vertex2,
                                                                                 graph, graph_type, loops_usage);
        if (!are_vertexes_valid) {
            PrintErrorMessage();
            PrintHintMessage("ошибка в строке {" + std::to_string(graph.vertexes.size() + 3 + i)
                                                        + "}: " + validation_log_message);
            return false;
        }
        graph.edges.emplace_back(std::make_pair(vertex1, vertex2));
    }
    // Сообщение об успехе совершенной операции.
    std::string success_message = "Данные о ребрах успешно получены!\n";
    PrintSuccessMessage(success_message);
    return true;
}

/**
 * Основной метод получения исходных данных от пользователя с файла.
 *
 * @param graph Исходный граф (изначально пустой).
 * @param graph_type Вид графа.
 * @param loops_usage Информация об использовании петель.
 * @return Исходный граф с информацией, полученной из файла от пользователя.
 */
Graph GetDataFromFile(Graph& graph, std::string& graph_type, std::string& loops_usage) {
    std::string log_message;

    while (true) {
        // Запрос информации о пути к файлу с данными.
        PrintFilePathInfo();
        // Получение пути к файлу с данными.
        std::string file_path = GetFilePath();
        // Сохранение исходного буфера (отвечает за консольный ввод / вывод).
        std::streambuf *input_buffer = std::cin.rdbuf();
        // Получение вершин.
        if (!TryGetGraphVertexesFromFile(graph, file_path)) {
            // Если ошибка: сброс буфера к исходному и повторение операции.
            std::cin.rdbuf(input_buffer);
            graph.vertexes.clear();
            continue;
        }
        // Получение максимально доступного числа ребер.
        unsigned long max_edges_available_amount = GetMaxEdgesAvailableAmount(graph.vertexes.size(),
                                                                              graph_type, loops_usage);
        // Получение ребер.
        if (!TryGetGraphEdgesFromFile(graph, file_path, max_edges_available_amount, graph_type, loops_usage)) {
            // Если ошибка: сброс буфера к исходному и повторение операции.
            std::cin.rdbuf(input_buffer);
            graph.vertexes.clear();
            graph.edges.clear();
            continue;
        }
        std::cin.rdbuf(input_buffer);
        break;
    }
    ConfirmContinueOperation();

    return graph;
}
