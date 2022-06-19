#ifndef TESTFILE_H
#define TESTFILE_H
#include <QString>
#include "createtestwindow.h"

class TestFile
{
public:
    TestFile();
    void writeToFile(QString& path, createTestWindow* testwindow);
};

#endif // TESTFILE_H
