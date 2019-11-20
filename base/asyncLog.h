#ifndef __ASYNC_LOG_H__
#define __ASYNC_LOG_H__

#include<stdio.h>
#include<string>
#include<list>
#include<thread>
#include<memory>
#include<mutex>
#include<condition_variable>
#include<iostream>
#include<sstream>

enum LOG_LEVEL 
{
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING
};

class AsyncLog
{
public:
   static void Output(const char* psFmt,...);
   static bool Init();

private:
   static std::mutex writeMutex_;
   static std::condition_variable writeCV_;
   static std::list<std::string> dataToWrite_;
   static std::shared_ptr<std::thread> thread_; 
   static void WriteThreadProc();

    // 不允许生成对象
    AsyncLog() = delete;
    ~AsyncLog() = delete;
    AsyncLog(const AsyncLog& rhs) = delete;
    AsyncLog& operator=(const AsyncLog& rhs) = delete;

};

#endif