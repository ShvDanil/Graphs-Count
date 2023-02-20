#include "adjacency_list.h"
#include "adjacency_matrix.h"
#include "console_input.h"
#include "defines.h"
#include "edges_list.h"
#include "file_input.h"
#include "graph.h"
#include "graph_info_helper.h"
#include "incidence_matrix.h"
#include "inner_helper.h"
#include "instructions.h"

/**
 * Определение вида графа (ориентированный / неориентированный).
 *
 * @return Строка - вид графа ("orgraph" / "non-orgraph").
 */
std::string GetGraphType() {
    std::string graph_type;
    std::string rus_graph_type;

    // Сообщение об ошибке и запрос повтора ввода в случае некорректных данных.
    while (true) {
        std::cout << GREEN "\n[GRAPH_TYPE]" MAGENTA "\t—>\t" RES_COL "Введите необходимый вид графа "
                     "(цифра — " MAGENTA "'1-2' " RES_COL " / тип ввода данных — " MAGENTA
                     "'..orgraph..'" RES_COL "): ";
        std::cin >> graph_type;
        IgnoreAndClearFurtherIncorrectInput();
        if (graph_type == "orgraph" || graph_type == "1") {
            graph_type = "orgraph";
            rus_graph_type = "ориентированного графа";
        } else if (graph_type == "non-orgraph" || graph_type == "2") {
            graph_type = "non-orgraph";
            rus_graph_type = "неориентированного графа";
        } else {
            PrintErrorMessage();
            continue;
        }
        break;
    }

    // Сообщение об успехе совершенной операции, запрос на продолжение выполнения операций.
    std::string success_message = "Функционал программы будет реализован для " MAGENTA +
            rus_graph_type + RES_COL ".\n";
    PrintSuccessMessage(success_message);
    ConfirmContinueOperation();
    SeparateOutput();

    return graph_type;
}

/**
 * Получение информации об использовании петель.
 *
 * @return Строка - наличие / отсутствие петель ("use" / "no-use").
 */
std::string GetLoopsUsage() {
    std::string loops_usage;
    std::string rus_loops_usage;

    // Сообщение об ошибке и запрос повтора ввода в случае некорректных данных.
    while (true) {
        std::cout << GREEN "\n[LOOPS_USAGE]" MAGENTA "\t—>\t" RES_COL "Введите информацию о наличии "
                     "/ отсутствии петель (" MAGENTA "'ye'" RES_COL " / " MAGENTA "'no'" RES_COL "): ";
        std::cin >> loops_usage;
        IgnoreAndClearFurtherIncorrectInput();
        if (loops_usage == "ye" || loops_usage == "1") {
            loops_usage = "use";
            rus_loops_usage = "c петлями";
        } else if (loops_usage == "no" || loops_usage == "2") {
            loops_usage = "no-use";
            rus_loops_usage = "без петель";
        } else {
            PrintErrorMessage();
            continue;
        }
        break;
    }

    // Сообщение об успехе совершенной операции, запрос на продолжение выполнения операций.
    std::string success_message = "Будет использован граф " MAGENTA +
                                  rus_loops_usage + RES_COL ".\n";
    PrintSuccessMessage(success_message);
    ConfirmContinueOperation();
    SeparateOutput();

    return loops_usage;
}

/**
 * Получение информации о типе представления графа в памяти компьютера.
 *
 * @return Строка - представление графа в памяти ("adj_matrix" / "inc_matrix" / "adj_list" / "edg_list").
 */
std::string GetStorageType() {
    std::string storage_type;
    std::string rus_storage_name;

    // Сообщение об ошибке и запрос повтора ввода в случае некорректных данных.
    while (true) {
        std::cout << GREEN "\n[STORAGE_FORMAT]" MAGENTA "\t—>\t" RES_COL "Введите необходимый "
                     "формат (цифра — " MAGENTA " '1-4' " RES_COL " / тип хранения — " MAGENTA
                     "'..adj_list..'" RES_COL "): ";
        std::cin >> storage_type;
        IgnoreAndClearFurtherIncorrectInput();
        if (storage_type == "adj_matrix" || storage_type == "1") {
            rus_storage_name = "матрицы смежности";
            storage_type = "adj_matrix";
        } else if (storage_type == "inc_matrix" || storage_type == "2") {
            rus_storage_name = "матрицы инцидентности";
            storage_type = "inc_matrix";
        } else if (storage_type == "adj_list" || storage_type == "3") {
            rus_storage_name = "списка смежности";
            storage_type = "adj_list";
        } else if (storage_type == "edg_list" || storage_type == "4") {
            rus_storage_name = "списка ребер";
            storage_type = "edg_list";
        } else {
            PrintErrorMessage();
            continue;
        }
        break;
    }

    // Сообщение об успехе совершенной операции, запрос на продолжение выполнения операций.
    std::string success_message = "Данные будут храниться в виде " MAGENTA + rus_storage_name +
            RES_COL ". Функционал программы позволяет изменять тип представления графа.\n";
    PrintSuccessMessage(success_message);
    ConfirmContinueOperation();
    SeparateOutput();

    return storage_type;
}

/**
 * Получение информации о типе ввода данных.
 *
 * @return Строка - тип ввода данных ("console" / "file").
 */
std::string GetInputType() {
    std::string input_type;
    std::string rus_input_name;

    // Сообщение об ошибке и запрос повтора ввода в случае некорректных данных.
    while (true) {
        std::cout << GREEN "\n[INPUT_FORMAT]" MAGENTA "\t—>\t" RES_COL "Введите необходимый "
                     "формат (цифра — " MAGENTA "'1-2' " RES_COL " / тип ввода данных — "
                     MAGENTA "'..console..'" RES_COL "): ";
        std::cin >> input_type;
        IgnoreAndClearFurtherIncorrectInput();
        if (input_type == "console" || input_type == "1") {
            input_type = "console";
            rus_input_name = "консоли";
        } else if (input_type == "file" || input_type == "2") {
            input_type = "file";
            rus_input_name = "файла";
        } else {
            PrintErrorMessage();
            continue;
        }
        break;
    }

    // Сообщение об успехе совершенной операции, запрос на продолжение выполнения операций.
    std::string success_message = "Данные будут получены из " MAGENTA + rus_input_name + RES_COL ".\n";
    PrintSuccessMessage(success_message);
    ConfirmContinueOperation();
    SeparateOutput();

    return input_type;
}

/**
 * Получение исходных данных от пользователя и запись их в граф.
 *
 * @param graph_type Вид графа.
 * @param loops_usage Наличие / отсутствие петель.
 * @param input_type Тип ввода данных.
 * @return Граф с данными.
 */
Graph GetSourceData(std::string& graph_type, std::string& loops_usage, std::string& input_type) {
    auto graph = Graph();

    // Получение данных в граф в зависимости от типа ввода данных.
    if (input_type == "console") {
        graph = GetDataFromConsole(graph, graph_type, loops_usage);
    } else {
        graph = GetDataFromFile(graph, graph_type, loops_usage);
    }

    return graph;
}

/**
 * Получение описания полученного графа.
 *
 * @param input_type Тип ввода данных.
 * @param graph_type Вид графа.
 * @param loops_usage Наличие / отсутствие петель.
 * @return Строка - описание полученного графа.
 */
std::string GetChosenGraphDescription(const std::string& input_type, const std::string& graph_type,
                                      const std::string& loops_usage) {
    std::string res = input_type == "console" ? MAGENTA "консоли " : MAGENTA "файла ";
    res += RES_COL "для " MAGENTA;

    if (graph_type == "non-orgraph") {
        res += "неориентированного графа ";
        res += loops_usage == "no-use" ? "без петель" : "c петлями";
    } else {
        res += "ориентированного графа ";
        res += loops_usage == "no-use" ?  "без петель" : "c петлями";
    }

    return res;
}

/**
 * Вывод представления графа (зависит от выбора пользователя).
 *
 * @param graph Исходный граф.
 * @param storage_type Тип представления данных в памяти компьютера.
 * @param graph_type Вид графа.
 */
void PrintGraphRepresentationInMemory(Graph& graph, const std::string& storage_type,
                                      const std::string& graph_type) {
    if (storage_type == "adj_matrix") {
        AdjacencyMatrix adj_matrix = graph.TransformToAdjacencyMatrix();
        adj_matrix.PrintAdjacencyMatrix(graph.vertexes);
    } else if (storage_type == "inc_matrix") {
        IncidenceMatrix inc_matrix = graph.TransformToIncidenceMatrix(graph_type);
        inc_matrix.PrintIncidenceMatrix(graph.vertexes, graph.edges);
    } else if (storage_type == "adj_list") {
        AdjacencyList adj_list = graph.TransformToAdjacencyList();
        adj_list.PrintAdjacencyList();
    } else {
        EdgesList edj_list = graph.TransformToEdgesList();
        edj_list.PrintEdgesList();
    }
    ConfirmContinueOperation();
    SeparateOutput();
}

/**
 * Получение пункта функционала, который необходимо выполнить.
 *
 * @return Число - пункт функционала, выбранный пользователем (1 / 2 / 3).
 */
int32_t GetFunctionalityNumberToExecute() {
    int32_t function;

    // Сообщение об ошибке и запрос повтора ввода в случае некорректных данных.
    while (true) {
        std::cout << GREEN "\n[AVAILABLE_FUNCTIONS]" MAGENTA "\t—>\t" RES_COL "Введите необходимый "
                     "формат (цифра — " MAGENTA "'1-3'" RES_COL "): ";
        std::cin >> function;
        IgnoreAndClearFurtherIncorrectInput();
        if (function >= 1 && function <= 3) {
            std::string success_message = std::to_string(function) + " функция будет выполнена.\n";
            PrintSuccessMessage(success_message);
            ConfirmContinueOperation();
            SeparateOutput();
            return function;
        } else {
            PrintErrorMessage();
            continue;
        }
    }
}

/**
 * Печать степени графа.
 *
 * @param graph Исходный граф.
 * @param graph_type Вид графа.
 */
void PrintVertexesDegree(const Graph& graph, const std::string& graph_type) {
    std::cout << GREEN "\n[VERTEXES_DEGREE]" MAGENTA "\t—>\t" RES_COL "Подсчет степеней /"
                                                                      " полустепеней графа:\n\n";
    if (graph_type == "non-orgraph") {
        for (const auto& vertex : graph.vertexes) {
            std::cout << MAGENTA << "'" << vertex << "'" RES_COL " степень" MAGENTA ": " RES_COL;
            int32_t amount = 0;
            for (const auto& edge : graph.edges) {
                if (vertex == edge.first || vertex == edge.second) {
                    amount = edge.first == edge.second ? amount + 2 : amount + 1;
                }
            }
            std::cout << amount << "\n";
        }
    } else {
        for (const auto& vertex : graph.vertexes) {
            std::cout << MAGENTA << "'" << vertex << "'" RES_COL " полустепени" MAGENTA ":\n" RES_COL;
            int32_t amount_in = 0, amount_out = 0;
            for (const auto& edge : graph.edges) {
                if (vertex == edge.first) {
                    ++amount_out;
                }
                if (vertex == edge.second) {
                    ++amount_in;
                }
            }
            std::cout << "захода: " << amount_in << GREEN "\t<" MAGENTA "——" GREEN ">\t" RES_COL
            "исхода: " << amount_out << "\n";
        }
    }
    SeparateOutput();
}

/**
 * Печать количества ребер графа.
 *
 * @param graph Исходный граф.
 */
void PrintEdgesAmount(const Graph& graph) {
    std::cout << GREEN "\n[EDGES_AMOUNT]" MAGENTA "\t—>\t" RES_COL "Подсчет количества ребер / дуг:\n\n";
    std::cout << MAGENTA "\t——>\t" RES_COL << graph.edges.size() << "\n";
    SeparateOutput();
}

/**
 * Получение нового типа представления графа в памяти компьютера.
 *
 * @param old_storage_type Исходный тип представления графа.
 * @return Строка - новый вид представления графа.
 */
std::string GetNewStorageType(const std::string& old_storage_type) {
    PrintNewGraphRepresentationInfo();

    std::string new_storage_type;
    // Сообщение об ошибке и запрос повтора ввода в случае некорректных данных.
    while (true) {
        std::cout << "\nВведите необходимый формат (цифра — " MAGENTA " '1-4' " RES_COL " / тип "
                      "хранения — " MAGENTA "'..adj_list..'" RES_COL "): ";
        std::cin >> new_storage_type;
        IgnoreAndClearFurtherIncorrectInput();
        if (new_storage_type == "1") {
            new_storage_type = "adj_matrix";
        } else if (new_storage_type == "2") {
            new_storage_type = "inc_matrix";
        } else if (new_storage_type == "3") {
            new_storage_type = "adj_list";
        } else if (new_storage_type == "4") {
            new_storage_type = "edg_list";
        }
        if (old_storage_type == new_storage_type) {
            PrintErrorMessage();
            PrintHintMessage("текущий и новый форматы представления графа совпадают!");
        } else if (new_storage_type != "adj_matrix" && new_storage_type != "inc_matrix" &&
                    new_storage_type != "adj_list" && new_storage_type != "edg_list") {
            PrintErrorMessage();
        } else {
            return new_storage_type;
        }
    }
}
