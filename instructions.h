#pragma once

/// Приветствие пользователя.
void GreetUser();

/// Печать информации о проекте.
void PrintProjectInfo();

/// Печать информации о виде графа.
void PrintGraphTypeInfo();

/// Печать информации о наличии / отсутствии петель в графе.
void PrintLoopsUsageInfo();

/// Печать информации о виде представления графа.
void PrintStorageFormatInfo();

/// Печать информации о типе ввода данных.
void PrintInputFormatInfo();

/// Печать информации о формате входных данных.
void PrintInputExample();

/// Уведомление пользователя о начале ввода данных.
void NotifyAboutInputStart(const std::string& input_type, const std::string& graph_type,
                           const std::string& loops_usage);

/// Печать информации об абсолютном пути к файлу с исходными данными.
void PrintFilePathInfo();

/// Уведомление пользователя о виде представления графа в памяти.
void NotifyStorageOutputStart(const std::string& input_type, const std::string& graph_type,
                              const std::string& loops_usage, const std::string& storage_type);

/// Печать информации о доступном пользователю функционале.
void PrintAvailableFunctionality();

/// Печать информации о новом типе представления графа в памяти.
void PrintNewGraphRepresentationInfo();

/// Уведомление пользователя о завершении доступного функционала.
void NotifyAboutAvailableFunctionalityEnd();

/// Прощание с пользователем.
void FarewellUser();
