#ifndef TASK_H_
#define TASK_H_

#include <stdint.h>
#include <iostream>

#define MAX_KOM_SIZE 255

enum Type {generic, internal, external};
enum Status {Active, Inactive, Infinity};
class Task
{
    private:
        uint8_t ID;
        char com[MAX_KOM_SIZE];
        unsigned ttl;
        Status status;
        Type type;
    public:
        bool AddTask(const Task);
        Task CreateTask(std::string com);
        Task *FindTask(std::string com, Task * ptr,int len);
        void ShowTask() const;
        void ShowTasks(const Task,const int num) const;
        void ShowTTL() const;
        void DeleteTask(Task *ttr, Task *ttm, uint8_t reg_size);
};
class Register
{
    private:
        
    public: 
        void ShowRegisters(const Task * reg, int num) const;
        Task TRG[255];
};
void ShowMenu();
#endif