
#include "task.h"

void ShowMenu()
{
    using std::cout;
    using std::endl;
    cout<<"Wybierz operacje: \n";
    cout<<"1. Dodaj Task.\n";
    cout<<"2. Usun Task.\n";
    cout<<"3. Znalezeieni taska\n";
    cout<<"4. Wyswietl Taski po TTL.\n";
    cout<<"5. Wyswietl Taski chronologicznie. \n";
}
Task Task::CreateTask(std::string com)
{
    Task newTask;
    int id_pos;
    int ttl_pos_start, ttl_pos_end, ttl_size;
    int com_start, com_end, com_size; 
    char task_id_str[4];
    char task_ttl_str[5];
    char * str_ptr = newTask.com;
    //przypisanie id do obiektu
    
   /* if(com.find("ID = ")>1)
    {
        com_id_pos = com.find("ID = ");
        com_id_pos  += 5;
    }
    else if(com.find("ID=")>1)
    {
        com_id_pos = com.find("ID=");
        com_id_pos  += 3;
    }
    else */

    id_pos = com.find("ID = ");
    id_pos  += 7;
    com.copy(task_id_str,2,id_pos);
    newTask.ID = std::stoi(task_id_str,nullptr,16);

    if(newTask.ID >= 0 && newTask.ID <= 15)
        newTask.type = generic;
    else if(newTask.ID >= 16 && newTask.ID <= 127)
        newTask.type = internal;
    else if(newTask.ID >= 128 && newTask.ID <= 255)
        newTask.type = external;

    //przypisanie komunikatu do obiektu

    com_start = com.find_first_of('"');
    com_end = com.find_last_of('"');
    if((com_start > 0) && (com_end>0))
    {
        com_size = com_end - com_start;
        com.copy(newTask.com, com_size+1,com_start);
        newTask.com[com_size+1] = '\0';
    }

    //przypisanie ttl do obiektu
    ttl_pos_start = com.find("TTL = ");
    ttl_pos_end = com.find("ms");

    if((ttl_pos_start>0) && (ttl_pos_end>0))
    {
        ttl_pos_start  += 6;
        ttl_size = ttl_pos_end - ttl_pos_start;
        com.copy(task_ttl_str,ttl_size,ttl_pos_start);
        newTask.ttl = std::stoi(task_ttl_str,nullptr);
    }
    if(newTask.ttl==0)
    {
        newTask.status = Infinity;
    }
    else if(newTask.ttl<0)
        newTask.status = Active;

    return newTask;
}
void Task::DeleteTask(Task *ttr, Task *ttm, uint8_t reg_size)
{
    
    ID='\0';

    for (size_t i = 0; i < 255; i++)
    {
        com[i]='\0';
    }
    ttl = '\0';
}
void Task::ShowTask() const
{
    char *stat;
    char *typ;
    //printf("%-7s %-50s %-10s %5s %5s\n","ID","Command","TTL [ms]","Status","Type");
    switch (status)
    {
    case 0:
        stat = "Active";
        break;
    case 1:
        stat = "Inactive";
        break;
    case 2:
        stat ="Infinity";
    }
    switch (type)
    {
    case 0:
        typ = "Generic";
        break;
    case 1:
        typ = "Internal";
        break;
    case 2:
        typ ="External";
    }

    printf("0x%-5x %-50s %-10d %-8s %-5s\n", ID, com ,ttl, stat, typ);
}
bool Task::AddTask(const Task)
{

}
void Register::ShowRegisters(const Task * reg, int num) const
{

    printf("%-7s %-50s %-10s %-8s %-5s\n","ID","Command","TTL [ms]","Status","Type");
    for(size_t i = 0; i < num; i++)
    {
        reg->ShowTask();
        reg++;
    }
}
Task *Task::FindTask(std::string com, Task * ptr, int len)
{
    char com_to_int[2];
    uint8_t *id_ptr;
    //id_ptr =&ptr.ID;
    uint8_t id ,id_pos;
    id_pos = com.find("x");
    id_pos  += 1;
    com.copy(com_to_int,2,id_pos);
    id = std::stoi(com_to_int,nullptr,16);
    for (size_t i = 0; i < len; i++)
    {
        if(ptr->ID == id)
        {
            return ptr;
            break;
        }
        else
            *ptr++;
    }
    return nullptr;
}

                    