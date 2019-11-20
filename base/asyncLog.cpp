#include"asyncLog.h"
#include<stdarg.h>

std::shared_ptr<std::thread> AsyncLog::thread_ ;
std::mutex AsyncLog::writeMutex_;
std::condition_variable AsyncLog::writeCV_;
std::list<std::string> AsyncLog::dataToWrite_;

bool AsyncLog::Init()
{
    if(thread_ == nullptr)
    {
        thread_.reset(new std::thread(WriteThreadProc));
    }
    return true;
}

void AsyncLog::WriteThreadProc()
{
    while(true)
    {
        std::string somethingToWrite;
        {
            std::unique_lock<std::mutex> lk(writeMutex_);
            writeCV_.wait(lk,[]{return !dataToWrite_.empty();});
            somethingToWrite = dataToWrite_.front();
            dataToWrite_.pop_front();
        }
        std::cout << somethingToWrite << std::endl;
    }
}


void AsyncLog::Output(const char* psFmt,...)
{
    std::string dataToStore;
    int length = 0;
    va_list ap;
    va_start(ap,psFmt);
    length = vsnprintf(NULL,0,psFmt,ap);
    if(length > dataToStore.length())
    {
        dataToStore.resize(length + 1);
    }
    va_end(ap);

    va_list aq;
    va_start(aq,psFmt);
    vsnprintf((char*)dataToStore.data(),length,psFmt,aq);
    va_end(aq);

    std::string threadPrefix = "Thread ";
    std::ostringstream osThreadId;
    osThreadId << std::this_thread::get_id();
    threadPrefix = threadPrefix + osThreadId.str() + ":";
    threadPrefix += dataToStore;

    {
        std::lock_guard<std::mutex> l(writeMutex_);
        dataToWrite_.push_back(threadPrefix);
        writeCV_.notify_one();
    }
}


