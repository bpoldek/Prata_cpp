#ifndef TASK_H_
#define TASK_H_

#include <stdint.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <functional>

#define MAX_KOM_SIZE 255

enum Type {generic, internal, external};
enum Status {Active, Inactive, Infinity};
class Register;
class Task
{
    private:
        uint8_t id;
        char com[MAX_KOM_SIZE];
        unsigned ttl;
        Status status;
        Type type;
        uint8_t indx;
    public:
        Task CreateTask(std::string com);
        void ShowTask() const;
        Task *FindTask(std::string com, Task * ptr,int len);
        friend class Register;
};
class Register
{
    private:
        std::vector<Task> reg;
        std::vector<Task> reg_ttl_sort;
    public:
        void AddTask(std::string in_str);
        void ShowRegisters();
        Task *FindTask(std::string com); 
        void DeleteTask(std::string com);
        void FindShow(Task * to_show);
        void SortTTL();
        friend class Task;
};
void ShowMenu();
#endif