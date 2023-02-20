#include "graph.h"
#include "graph_info_helper.h"
#include "inner_helper.h"
#include "instructions.h"
#include "iostream"

/**
 * Основная точка входа и запуска консольного приложения.
 *
 * @return Успешное завершение работы программы.
 */
int main() {
    // Если у вас Windows, раскомментируйте строку ниже.
//    std::system("chcp 65001");

    // Приветствие пользователя консольного приложение.
    GreetUser();
    // Краткая информация о данном консольном приложении.

    PrintProjectInfo();
    // Основные процессы работы консольного приложения.

    while (true) {
        // Получение вида графа.
        PrintGraphTypeInfo();
        std::string graph_type = GetGraphType();

        // Получение информации об использовании петель.
        PrintLoopsUsageInfo();
        std::string loops_usage = GetLoopsUsage();

        // Получение типа представления графа.
        PrintStorageFormatInfo();
        std::string storage_type = GetStorageType();

        // Получение типа ввода данных.
        PrintInputFormatInfo();
        std::string input_type = GetInputType();

        // Пример формата входных данных.
        PrintInputExample();

        // Получение данных согласно выбранному графу и варианту ввода данных.
        NotifyAboutInputStart(input_type, graph_type, loops_usage);
        Graph graph = GetSourceData(graph_type, loops_usage, input_type);

        // Печать данных о графе согласно выбранному типу представления графа.
        NotifyStorageOutputStart(input_type, graph_type, loops_usage, storage_type);
        PrintGraphRepresentationInMemory(graph, storage_type, graph_type);

        // Описание доступного функционала и выбор функции для работы с графами.
        PrintAvailableFunctionality();
        int32_t function = GetFunctionalityNumberToExecute();
        switch (function) {
            case 1:
                PrintVertexesDegree(graph, graph_type);
                break;
            case 2:
                PrintEdgesAmount(graph);
                break;
            case 3:
                std::string new_storage_type = GetNewStorageType(storage_type);
                NotifyStorageOutputStart(input_type, graph_type, loops_usage, new_storage_type);
                PrintGraphRepresentationInMemory(graph, new_storage_type, graph_type);
                break;
        }

        // Сообщение об окончании основного доступного функционала.
        NotifyAboutAvailableFunctionalityEnd();

        // Продолжение / окончание пользования приложением.
        std::string continue_button = AskToContinueProgramExecution();
        if (continue_button == "no") {
            FarewellUser();
            break;
        }
    }

    return 0;
}
