#pragma once

#include "iostream"

/// Разделение вывода данных.
void SeparateOutput();

/// Игнорирование и очистка дальнейшего ввода консоли.
void IgnoreAndClearFurtherIncorrectInput();

/// Печать информации о продолжении.
void PrintContinueMessage();

/// Печать информации об ошибке.
void PrintErrorMessage();

/// Печать информации об успехе.
void PrintSuccessMessage(std::string& message);

/// Печать подсказки.
void PrintHintMessage(const std::string& message);

/// Подтверждение продолжения выполнения операции.
void ConfirmContinueOperation();

/// Запрос на продолжение выполнения программы или завершение пользования ей.
std::string AskToContinueProgramExecution();
