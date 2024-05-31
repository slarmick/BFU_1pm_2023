#include "func.hpp"
#include <fstream>
#include <cstdint>
#include <ctime>

namespace AU
{
    void my_func(std::string filename)
    { 
    // записывает дату и время в файл
    uint32_t count = 1; // количество запусков программы
    std::ifstream file_in(filename);
    std::string stroka;
    while (!file_in.eof())
    {
        std::getline(file_in, stroka);
        if (stroka != "")
    {
            count = atoi(stroka.substr(0, stroka.find('-')).c_str())+1; // ищем значение int перед первым "-" в последней строке
    }
    file_in.close();
    std::ofstream file(filename, std::ios::app); // std::ios::app означает, что мы добавляем данные (приложения) в конец файла
    time_t curr_time = time(nullptr); // проводить время ctime
    struct tm* now = localtime(&curr_time); // время приведения в действие структуры в куче (heap)
    if (stroka != "") file << std::endl;
    file << count << '-'
    << now->tm_year + 1900 << '-'
    << now->tm_mon + 1 << '-'
    << now->tm_mday << '-'
    << now->tm_hour << '-'
    << now->tm_min << '-'
    << now->tm_sec << std::endl;
}
}