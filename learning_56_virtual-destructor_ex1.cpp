#include <iostream>
#include <memory>
#include <string>

class IRunTimeTask{
    public:
    virtual void execute()=0;
    virtual ~IRunTimeTask(){std::cout<<"deleting the base\n";}
};
class LoggedTask:public IRunTimeTask{
    protected:
    std::string m_taskname;
    public:
    LoggedTask(std::string l_task): m_taskname(l_task){
        std::cout<<"logging in for the task "<<m_taskname<<"\n";
    }
    ~LoggedTask() override {std::cout<<"logging wrapup for task "<<m_taskname<<"\n";}
   
};
class DatabaseBackupTask:public LoggedTask{
    private:
    int* m_backupStatusFlag;
    public:
    DatabaseBackupTask(std::string task):LoggedTask(task){
        std::cout<<"creating flag for database backup\n";
        m_backupStatusFlag = new int(1);
    }
    
    void execute() override {
        std::cout<<"Assigned for a task: "<<m_taskname<<"\n";
    }
    ~DatabaseBackupTask()override {
        std::cout<<"deleting backup flag\n";
        delete m_backupStatusFlag;
    }

};
int main(){
    std::string task = "sort database";
    std::unique_ptr<IRunTimeTask> dc = std::make_unique<DatabaseBackupTask>(task);
    dc->execute();   

    return 0;
}