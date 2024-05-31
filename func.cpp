#include "func.hpp"
#include <fstream>
#include <cstdint>
#include <ctime>

namespace AU
{
    void my_func(std::string filename)
    { 
    // ���������� ���� � ����� � ����
    uint32_t count = 1; // ���������� �������� ���������
    std::ifstream file_in(filename);
    std::string stroka;
    while (!file_in.eof())
    {
        std::getline(file_in, stroka);
        if (stroka != "")
    {
            count = atoi(stroka.substr(0, stroka.find('-')).c_str())+1; // ���� �������� int ����� ������ "-" � ��������� ������
    }
    file_in.close();
    std::ofstream file(filename, std::ios::app); // std::ios::app ��������, ��� �� ��������� ������ (����������) � ����� �����
    time_t curr_time = time(nullptr); // ��������� ����� ctime
    struct tm* now = localtime(&curr_time); // ����� ���������� � �������� ��������� � ���� (heap)
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