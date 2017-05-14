#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>


class FileError : public std::exception {
    public:
        FileError(const std::string& fileIn) : mFile(fileIn) { }
        virtual const char* what() const noexcept override 
        {
            return mMsg.c_str();
        }
        const std::string& getFileName() { return mFile; }

    protected:
        void setMessage(const std::string& message) {
            mMsg = message;
        }
    private:
        std::string mFile, mMsg;
};

class FileOpenError : public FileError {
    public:
        FileOpenError(const std::string& fileNameIn);
};

FileOpenError::FileOpenError(const std::string& fileNameIn) : FileError(fileNameIn)
{
    setMessage("Unable to open " + fileNameIn);
}

class FileReadError : public FileError {
    public:
        FileReadError(const std::string& fileNameIn, int lineNumIn);
        int getLineNum() { return mLineNum; }
    private:
        int mLineNum;
};

FileReadError::FileReadError(const std::string& fileNameIn, int lineNumIn)
    : FileError(fileNameIn), mLineNum(lineNumIn)
{
    std::ostringstream ostr;

    ostr << "Error reading " << fileNameIn << " at line " << lineNumIn;
    setMessage(ostr.str());
}

void readIntegerFile(const std::string& fileName, std::vector<int>& dest) {
    std::ifstream istr;
    int temp;
    std::string line;
    int lineNumber = 0;

    istr.open(fileName.c_str());
    if (istr.fail()) {
        throw FileOpenError(fileName);
    }

    while (!istr.eof()) {
        getline(istr, line);
        lineNumber++;

        std::istringstream lineStream(line);

        while (lineStream >> temp) {
            dest.push_back(temp);
        }

        if (!lineStream.eof()) {
            throw FileReadError(fileName, lineNumber);
        }
    }
}


auto main() -> int {
    std::vector<int> myInts;
    const std::string fileName = "IntegerFile.txt";

    try {
        readIntegerFile(fileName, myInts);
    }
    catch (const FileError& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    for (const auto element : myInts) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
