
#include "task.h"

void ShowMenu()
{
    using std::cout;
    using std::endl;
    cout<<"Select : \n";
    cout<<"1. Add task.\n";
    cout<<"2. Delete Task.\n";
    cout<<"3. Find task by id. \n";
    cout<<"4. Sort by TTL.\n";
    cout<<"5. Show all tasks. \n";
}
Task *Register::FindTask(std::string com)
{
    Task *id_ptr =&reg[0];
    char com_to_int[2];
    uint8_t f_id ,id_pos;
    id_pos = com.find("x");
    id_pos  += 1;
    com.copy(com_to_int,2,id_pos);
    if (com_to_int[0] =='\0' || com_to_int[1] =='\0' )
    {
        return nullptr;
    }
    f_id = std::stoi(com_to_int,nullptr,16);
    for (size_t i = 0; i < reg.size(); i++)
    {
        if(id_ptr->id == f_id)
        {
            id_ptr->indx = i;
            return id_ptr;
            break;
        }
        else
            *id_ptr++;
    }
    return nullptr;
}
void Register::DeleteTask(std::string com)
{
    Task *nt_ptr;
    nt_ptr=nt_ptr->FindTask(com,&reg[0],reg.size());
    if(nt_ptr!=nullptr)
    {
        reg.erase(reg.begin()+(nt_ptr->indx));
        
    }
    else if(nt_ptr==nullptr)
    {
        std::cout<<"No task to remove\n"; 
    }

}
void Register::AddTask(std::string in_str)
{
    Task newTask;
    Task *nt_ptr;
    newTask = newTask.CreateTask(in_str);
    nt_ptr=newTask.FindTask(in_str,&reg[0],reg.size());
    if(nt_ptr!=nullptr)
    {
        *nt_ptr = newTask;
    }
    else if(nt_ptr==nullptr)
    {
        reg.push_back(newTask);
    }
}
void Register::ShowRegisters() 
{
    Task *ptr =&reg[0];
    printf("%-7s %-50s %-10s %-8s %-5s\n","ID","Command","TTL [ms]","Status","Type");
    for(size_t i = 0; i < reg.size(); i++)
    {
        ptr->ShowTask();
        ptr++;
    }
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

    id_pos = com.find("ID = ");
    id_pos  += 7;
    com.copy(task_id_str,2,id_pos);
    newTask.id = std::stoi(task_id_str,nullptr,16);

    if(newTask.id >= 0 && newTask.id <= 15)
        newTask.type = generic;
    else if(newTask.id >= 16 && newTask.id <= 111)
        newTask.type = internal;
    else if(newTask.id >= 112 && newTask.id <= 255)
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
    else if(newTask.ttl>0)
        newTask.status = Active;
    else
        newTask.status = Inactive;
    return newTask;
}

void Task::ShowTask() const
{
    char *stat;
    char *typ;
    switch (status)
    {
    case 0:
        stat = (char*)"Active";
        break;
    case 1:
        stat = (char*)"Inactive";
        break;
    case 2:
        stat =(char*)"Infinity";
    }
    switch (type)
    {
    case 0:
        typ = (char*)"Generic";
        break;
    case 1:
        typ = (char*)"Internal";
        break;
    case 2:
        typ =(char*)"External";
    }

    printf("0x%-5x %-50s %-10d %-8s %-5s\n", id, com ,ttl, stat, typ);
}

Task *Task::FindTask(std::string com, Task * ptr, int len)
{
    char com_to_int[2];
    uint8_t *id_ptr;
    uint8_t id ,id_pos;
    id_pos = com.find("x");
    id_pos  += 1;
    com.copy(com_to_int,2,id_pos);
    if (com_to_int[0] =='\0' || com_to_int[1] =='\0' )
    {
        return nullptr;
    }
    id = std::stoi(com_to_int,nullptr,16);
    for (size_t i = 0; i < len; i++)
    {
        if(ptr->id == id)
        {
            ptr->indx = i;
            return ptr;
            break;
        }
        else
            *ptr++;
    }
    return nullptr;
}
void Register::FindShow(Task * to_show)
{
    if(to_show != nullptr)
    {
        to_show->ShowTask();
    }
    else if (to_show == nullptr)
    {
        std::cout << "Not finded";
    } 
}
void Register::SortTTL()
{
    reg_ttl_sort = reg;
    //sort(reg_ttl_sort.begin(),reg_ttl_sort.end());
    Task *ptr =&reg_ttl_sort[0];
    printf("%-7s %-50s %-10s %-8s %-5s\n","ID","Command","TTL [ms]","Status","Type");
    for(size_t i = 0; i < reg_ttl_sort.size(); i++)
    {
        ptr->ShowTask();
        ptr++;
    }
}                    