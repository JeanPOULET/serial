#include "Serial.h"

namespace serial {
    OBinaryFile::OBinaryFile(const std::string& filename, OBinaryFile::Mode mode=Truncate)
        :  m_file(fopen(filename.c_str(),mode==Truncate?"w":"a")){}

    OBinaryFile::~OBinaryFile()
       {
        fclose(m_file);
       } 

    OBinaryFile::OBinaryFile(OBinaryFile&& other) noexcept
        : m_file(std::exchange(other.m_file,nullptr)){}    

    OBinaryFile::OBinaryFile& OBinaryFile::operator=(OBinaryFile&& other) noexcept
        {
            std::swap(m_file,other.m_file);
            return *this;
        }


    IBinaryFile::IBinaryFile(const std::string& filename)
        : m_file(fopen(filename.c_str(),"r")) {}

    IBinaryFile::~IBinaryFile()
        {
            fclose(m_file);
        }

    IBinaryFile::IBinaryFile(IBinaryFile&& other) noexcept
        : m_file(std::exchange(other.m_file,nullptr)){}

    IBinaryFile::IBinaryFile& IBinaryFile::operator=(IBinaryFile&& other) noexcept
        {
            std::swap(m_file,other.m_file);
            return *this;
        }

    
    
}
