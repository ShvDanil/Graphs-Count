#include "defines.h"
#include "inner_helper.h"
#include "iostream"

/**
 * Разделение вывода данных.
 */
void SeparateOutput() {
    std::cout << MAGENTA "\n— — — — — — — — — — — — — — — — — — — — — — — — — — — —\n" RES_COL;
}

/**
 * Игнорирование и очистка дальнейшего ввода консоли.
 */
void IgnoreAndClearFurtherIncorrectInput() {
    std::cin.clear();
    std::cin.ignore(256,'\n');
}

/**
 * Печать информации о продолжении.
 */
void PrintContinueMessage() {
    std::cout << GREEN "\n[CONTINUE]" MAGENTA "\t—>\t" RES_COL
                 "Напечатайте " GREEN "'yes'" RES_COL ", чтобы продолжить: ";
}

/**
 * Печать информации об ошибке.
 */
void PrintErrorMessage() {
    std::cout << RED "\n[ERROR]" MAGENTA "\t—>\t" RES_COL "Неверный ввод! Повторите "
                 "действие!\n";
}

/**
 * Печать информации об успехе.
 *
 * @param message Сообщение.
 */
void PrintSuccessMessage(std::string& message) {
    std::cout << "\n" << GREEN "[SUCCESS]" MAGENTA "\t—>\t" RES_COL " " << message;
}

/**
 * Печать подсказки.
 *
 * @param message Сообщение.
 */
void PrintHintMessage(const std::string& message) {
    std::cout << RED "[hint]" RES_COL MAGENTA "\t—>\t" GRAY << message << RES_COL "\n";
}

/**
 * Подтверждение продолжения выполнения операции.
 */
void ConfirmContinueOperation() {
    std::string continue_btn;

    // Сообщение об ошибке и запрос о повторе операции.
    while (true) {
        PrintContinueMessage();
        std::cin >> continue_btn;
        IgnoreAndClearFurtherIncorrectInput();
        if (continue_btn == "yes") {
            break;
        } else {
            PrintErrorMessage();
        }
    }
}

/**
 * Запрос на продолжение выполнения программы или завершение пользования ей.
 * @return Строка - ответ пользователя ("yes" / "no").
 */
std::string AskToContinueProgramExecution() {
    std::string continue_btn;

    while (true) {
        std::cout << GREEN "\n[CONTINUE_OR_END]" MAGENTA "\t—>\t"
                     GREEN "'yes'" MAGENTA " —> " RES_COL "продолжить пользование" MAGENTA "\t|\t" RES_COL
                     RED "'no'" MAGENTA " —> " RES_COL "завершить пользование: ";
        std::cin >> continue_btn;
        IgnoreAndClearFurtherIncorrectInput();
        if (continue_btn == "yes" || continue_btn == "no") {
            SeparateOutput();
            return continue_btn;
        } else {
            PrintErrorMessage();
        }
    }
}
