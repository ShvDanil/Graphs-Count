#include "defines.h"
#include "graph_info_helper.h"
#include "inner_helper.h"
#include "instructions.h"
#include "iostream"

/**
 * Приветствие пользователя в консольном приложении.
 */
void GreetUser() {
    std::cout << GREEN "[GREETING]" MAGENTA "\t—>\t" RES_COL "Здравствуйте! Вы в консольном "
                "приложении " MAGENTA "'Работа с графами'" << RES_COL ".\nПредлагаю ознакомиться "
                "с краткой информацией о проекте (более подробную можно найти в файле readme.txt) "
                "и начать пользоваться приложением!" << "\n";
    ConfirmContinueOperation();
    SeparateOutput();
}

/**
 * Печать информации о проекте.
 */
void PrintProjectInfo() {
    std::cout << GREEN "\n[PROJECT_INFO]" MAGENTA "\t—>\t" RES_COL "Данное консольное приложение "
                "обеспечивает возможность работы с ориентированными и неориентированными "
                "невзвешенными графами без кратных ребер и петель. Граф может быть представлен "
                "четырьмя различными способами в памяти компьютера. Более того, вы можете "
                "воспользоваться некоторым функционалом, описывающим свойства введенного графа.\n";
    ConfirmContinueOperation();
    SeparateOutput();
}

/**
 * Печать информации о виде графа.
 */
void PrintGraphTypeInfo() {
    std::cout << GREEN "\n[GRAPH_TYPE_INFO]" MAGENTA "\t—>\t" RES_COL "В первую очередь необходимо "
                 "определиться с видом графа." MAGENTA "\nДоступны " RES_COL "2 варианта:\n" MAGENTA
                 "\t1) " RES_COL "orgraph " MAGENTA "->" RES_COL " ориентированный граф" MAGENTA";"
                 RES_COL "\n" MAGENTA "\t2) " RES_COL "non-orgraph " MAGENTA "->" RES_COL
                 " неориентированный граф" MAGENTA"." RES_COL "\n";
}

/**
 * Печать информации о наличии / отсутствии петель в графе.
 */
void PrintLoopsUsageInfo() {
    std::cout << GREEN "\n[LOOPS_USAGE_INFO]" MAGENTA "\t—>\t" RES_COL "Также необходимо указать "
                 "наличие / отсутствие петель в графе." MAGENTA "\nДоступны " RES_COL "2 варианта:\n"
                 MAGENTA "\t1) " RES_COL "ye " MAGENTA "->" RES_COL " граф с петлями" MAGENTA";"
                 RES_COL "\n" MAGENTA "\t2) " RES_COL "no " MAGENTA "->" RES_COL " граф без петель"
                 MAGENTA"." RES_COL "\n";
}

/**
 * Печать информации о виде представления графа в памяти компьютера.
 */
void PrintStorageFormatInfo() {
    std::cout << GREEN "\n[STORAGE_FORMAT_INFO]" MAGENTA "\t—>\t" RES_COL "Далее, прежде чем выбрать "
                 "формат ввода, вам предлагается выбрать тип представления графа." MAGENTA
                 "\nДоступны " RES_COL "следующие 4 варианта:\n"
                 MAGENTA "\t1) " RES_COL "adj_matrix " MAGENTA "->" RES_COL " матрица смежности"
                 MAGENTA";" RES_COL "\n"
                 MAGENTA "\t2) " RES_COL "inc_matrix " MAGENTA "->" RES_COL " матрица инцидентности"
                 MAGENTA";" RES_COL "\n"
                 MAGENTA "\t3) " RES_COL "adj_list " MAGENTA "->" RES_COL " список смежности"
                 MAGENTA";" RES_COL "\n"
                 MAGENTA "\t4) " RES_COL "edg_list " MAGENTA  "->" RES_COL " cписок ребер"
                 MAGENTA"." RES_COL "\n";
}

/**
 * Печать информации о типе ввода данных.
 */
void PrintInputFormatInfo() {
    std::cout << GREEN "\n[INPUT_FORMAT_INFO]" MAGENTA "\t—>\t" RES_COL "Теперь необходимо указать "
                 "тип ввода данных." MAGENTA "\nДоступны " RES_COL "2 варианта:\n" MAGENTA "\t1) "
                 RES_COL "console " MAGENTA "->" RES_COL " ввод данных с консоли" MAGENTA";" RES_COL
                 "\n" MAGENTA "\t2) " RES_COL "file " MAGENTA "->" RES_COL " ввод данных с файла"
                 MAGENTA"." RES_COL "\n";
}

/**
 * Печать информации о формате входных данных.
 */
void PrintInputExample() {
    std::cout << GREEN "\n[INPUT_EXAMPLE]" MAGENTA "\t—>\t" RES_COL "Ниже представлена информация "
                 "о формате входных данных.\n"
                 MAGENTA " ——" GREEN ">>\t" RES_COL "3" MAGENTA "\t|\t" RES_COL
                 "количество n вершин графа;\n"
                 MAGENTA " ——" GREEN ">>\t" RES_COL "a" MAGENTA "\t|\t" RES_COL
                 "n строк: вершины графа (в каждой строке по одной вершине);\n"
                 MAGENTA " ——" GREEN ">>\t" RES_COL "b" MAGENTA "\t|\t" RES_COL "...\n"
                 MAGENTA " ——" GREEN ">>\t" RES_COL "c" MAGENTA "\t|\t" RES_COL "...\n"
                 MAGENTA " ——" GREEN ">>\t" RES_COL "3" MAGENTA "\t|\t" RES_COL "количество m "
                 "ребер графа;\n"
                 MAGENTA " ——" GREEN ">>\t" RES_COL "a b" MAGENTA "\t|\t" RES_COL
                 "m строк: пары вершин, соединяющих ребра;\n"
                 MAGENTA " ——" GREEN ">>\t" RES_COL "b c" MAGENTA "\t|\t" RES_COL "...\n"
                 MAGENTA " ——" GREEN ">>\t" RES_COL "c a" MAGENTA "\t|\t" RES_COL "...\n";
    SeparateOutput();
}

/**
 * Уведомление пользователя о начале ввода данных.
 *
 * @param input_type Тип ввода данных.
 * @param graph_type Вид графа.
 * @param loops_usage Наличие / отсутствие петель.
 */
void NotifyAboutInputStart(const std::string& input_type, const std::string& graph_type,
                           const std::string& loops_usage) {
    std::cout << GREEN "\n[";
    for (const auto& ch : input_type) {
        std::cout << static_cast<char>(ch - 'a' + 'A');
    }
    std::cout << "_INPUT]" RES_COL MAGENTA "\t—>\t" RES_COL "Ввод исходных данных с " MAGENTA;
    std::cout << GetChosenGraphDescription(input_type, graph_type, loops_usage);
    std::cout << RES_COL ".\n";
}

/**
 * Печать информации об абсолютном пути к файлу с исходными данными.
 */
void PrintFilePathInfo() {
    std::cout << GREEN "\n[FILE_PATH_INFO]" MAGENTA "\t—>\t" RES_COL "Введите абсолютный путь к файлу.\n";
}

/**
 * Уведомление пользователя о виде представления графа в памяти.
 *
 * @param input_type Тип ввода данных.
 * @param graph_type Вид графа.
 * @param loops_usage Наличие / отсутствие петель.
 * @param storage_type Тип представления графа в памяти.
 */
void NotifyStorageOutputStart(const std::string& input_type, const std::string& graph_type,
                              const std::string& loops_usage, const std::string& storage_type) {
    std::cout << GREEN "\n[GRAPH_IN_STORAGE_OUTPUT]" RES_COL MAGENTA "\t—>\t" RES_COL
                       "Ниже представлены полученные данные из ";
    std::cout << GetChosenGraphDescription(input_type, graph_type, loops_usage);
    std::cout << RES_COL ".\n" MAGENTA "\n{";

    if (storage_type == "adj_matrix") {
        std::cout << "МАТРИЦА СМЕЖНОСТИ";
    } else if (storage_type == "inc_matrix") {
        std::cout << "МАТРИЦА ИНЦИДЕНТНОСТИ";
    } else if (storage_type == "adj_list") {
        std::cout << "СПИСОК СМЕЖНОСТИ";
    } else {
        std::cout << "СПИСОК РЕБЕР";
    }
    std::cout << MAGENTA "}\n" RES_COL;
}

/**
 * Печать информации о доступном пользователю функционале.
 */
void PrintAvailableFunctionality() {
    std::cout << GREEN "\n[AVAILABLE_FUNCTIONS_INFO]" RES_COL MAGENTA "\t—>\t" RES_COL
                 "Ниже представлена информация об" MAGENTA " основных доступных функциях " RES_COL
                 "для работы с графом:" MAGENTA "\nДоступны " RES_COL "следующие 3 варианта:\n"
                 MAGENTA "\t1) " RES_COL "подсчет степеней вершин для неориентированного графа и "
                 "полустепеней вершин для ориентированного графа" MAGENTA";" RES_COL "\n"
                 MAGENTA "\t2) " RES_COL "подсчет количества ребер (для неориентированного) / дуг "
                 "(для ориентированного) графа" MAGENTA";" RES_COL "\n"
                 MAGENTA "\t3) " RES_COL "вывод графа в другом представлении" MAGENTA"." RES_COL "\n";
}

/**
 * Печать информации о новом типе представления графа в памяти.
 */
void PrintNewGraphRepresentationInfo() {
    std::cout << GREEN "\n[NEW_GRAPH_REPRESENTATION]" MAGENTA "\t—>\tДоступны " RES_COL "следующие"
                 " 4 варианта представления графа:\n"
                 MAGENTA "\t1) " RES_COL "adj_matrix " MAGENTA "->" RES_COL " матрица смежности"
                 MAGENTA";" RES_COL "\n"
                 MAGENTA "\t2) " RES_COL "inc_matrix " MAGENTA "->" RES_COL " матрица инцидентности"
                 MAGENTA";" RES_COL "\n"
                 MAGENTA "\t3) " RES_COL "adj_list " MAGENTA "->" RES_COL " список смежности"
                 MAGENTA";" RES_COL "\n"
                 MAGENTA "\t4) " RES_COL "edg_list " MAGENTA  "->" RES_COL " cписок ребер"
                 MAGENTA"." RES_COL "\n";
}

/**
 * Уведомление пользователя о завершении доступного функционала.
 */
void NotifyAboutAvailableFunctionalityEnd() {
    std::cout << GREEN "\n[END_OF_MAIN_FUNCTIONALITY]" MAGENTA "\t—>\t" RES_COL "На этом все доступные функции"
                RES_COL " завершены!\n";
}

/**
 * Прощание с пользователем.
 */
void FarewellUser() {
    std::cout << GREEN "\n[FAREWELL]" MAGENTA "\t—>\t" RES_COL "До скорых встреч, дорогой пользователь!\n";
    std::cout << "\n" << ".   　　八八\n"
                 ".　　︹/　#\\︹\n"
                 ".　'ーe　e;ー'\n"
                 ".　　|。。#）\n"
                 ".　　\\＿／|\n"
                 ".　　　|＃|\n"
                 ".　　　|　|\n"
                 ".　　　)＃(\n"
                 ".　　／＃ ‘,＼\n"
                 ".　（　＾ ＃, ＼\n"
                 ".　　\\＃||　/　　）\n"
                 ".　　 \\# ||　/^(　/\n"
                 ". 　　 )｜ ) | ｜＼\\\n"
                 ".　  （＿)(__)（(＿\\ ";
}
