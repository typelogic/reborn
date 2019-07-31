#include <iostream>

#if 0
#include "include/gtest/gtest.h"

void print(std::string);

class Fixture : public testing::Test
{
    public:
    void SetUp() override
    {
        Poco::TemporaryFile tmp;
        mTestHomeFolder = tmp.tempName();
        Poco::File x(mTestHomeFolder);
        x.createDirectories();
    }

    void TearDown() override
    {
        Poco::File x(mTestHomeFolder);
        x.remove(true);
    }

    std::string mTestHomeFolder;
};
#endif 

int main (int argc, char *argv[])
{
    return 0;
}
