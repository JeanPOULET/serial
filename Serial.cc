#include "Serial.h"

namespace serial {

            /*****************************************************
             *                   OBinaryFile                     *
             *****************************************************/

    OBinaryFile::OBinaryFile(const std::string& filename, OBinaryFile::Mode mode)
        :  m_file(std::fopen(filename.c_str(),mode==Truncate?"wb":"ab"))
        {

            if(nullptr == m_file ){
                throw std::runtime_error("Impossible d'ouvrir le fichier");
            }
        }

    OBinaryFile::~OBinaryFile()
       {
        fclose(m_file);
       } 

    OBinaryFile::OBinaryFile(OBinaryFile&& other) noexcept
        : m_file(std::exchange(other.m_file,nullptr)){}    

    OBinaryFile& OBinaryFile::operator=(OBinaryFile&& other) noexcept
        {
            std::swap(m_file,other.m_file);
            return *this;
        }

    std::size_t OBinaryFile::write(const std::byte* data, std::size_t size){
        return fwrite(data,size,size,m_file);
        
    }

    OBinaryFile& operator<<(OBinaryFile& file, uint8_t x){
        std::byte b = std::byte(x); 
        file.write(&b,1);
        return file; 
    }

    OBinaryFile& operator<<(OBinaryFile& file, int8_t x){
        std::byte b = std::byte(x); 
        file.write(&b,1);
        return file;
    }

    OBinaryFile& operator<<(OBinaryFile& file, uint16_t x){
        return file;
    }

    OBinaryFile& operator<<(OBinaryFile& file, int16_t x){
        return file;
    }

    OBinaryFile& operator<<(OBinaryFile& file, uint32_t x){
        return file;
    }

    OBinaryFile& operator<<(OBinaryFile& file, int32_t x){
        return file;
    }

    OBinaryFile& operator<<(OBinaryFile& file, uint64_t x){
        return file;
    }

    OBinaryFile& operator<<(OBinaryFile& file, int64_t x){
        return file;
    }

    OBinaryFile& operator<<(OBinaryFile& file, char x){
        std::byte b =static_cast<std::byte>(x);
        file.write(&b,1);
        return file;
    }

    OBinaryFile& operator<<(OBinaryFile& file, float x){
        return file;
    }

    OBinaryFile& operator<<(OBinaryFile& file, double x){
        return file;
    }

    OBinaryFile& operator<<(OBinaryFile& file, bool x){
        return file;
    }

    OBinaryFile& operator<<(OBinaryFile& file, const std::string& x){
        return file;
    }
    

            /*****************************************************
             *                   IBinaryFile                     *
             *****************************************************/

    IBinaryFile::IBinaryFile(const std::string& filename)
        : m_file(std::fopen(filename.c_str(),"rb"))
        {
            if(nullptr == m_file){
                throw std::runtime_error("Impossible de lire le fichier");
            }
        }

    IBinaryFile::~IBinaryFile()
        {
            fclose(m_file);
        }

    IBinaryFile::IBinaryFile(IBinaryFile&& other) noexcept
        : m_file(std::exchange(other.m_file,nullptr)){}

    IBinaryFile& IBinaryFile::operator=(IBinaryFile&& other) noexcept
        {
            std::swap(m_file,other.m_file);
            return *this;
        }

    std::size_t IBinaryFile::read(std::byte* data, std::size_t size){
        return fread(data,size,size,m_file);
    }

    IBinaryFile& operator>>(IBinaryFile& file, uint8_t& x){
        std::byte b;
        file.read(&b,1);
        x = uint8_t(b);
        return file;
    }

    IBinaryFile& operator>>(IBinaryFile& file, int8_t& x){
        std::byte b;
        file.read(&b,1);
        x = int8_t(b);
        return file;
    }

    IBinaryFile& operator>>(IBinaryFile& file, uint16_t& x){
        return file;
    }
    

    IBinaryFile& operator>>(IBinaryFile& file, int16_t& x){
        return file;
    }

    IBinaryFile& operator>>(IBinaryFile& file, uint32_t& x){
        return file;
    }

    IBinaryFile& operator>>(IBinaryFile& file, int32_t& x){
        return file;
    }

    IBinaryFile& operator>>(IBinaryFile& file, uint64_t& x){
        return file;
    }

    IBinaryFile& operator>>(IBinaryFile& file, int64_t& x){
        return file;
    }

    IBinaryFile& operator>>(IBinaryFile& file, char& x){
        std::byte b;
        file.read(&b,1);
        x=char(b);
        return file;
    }

    IBinaryFile& operator>>(IBinaryFile& file, float& x){
        return file;
    }

    IBinaryFile& operator>>(IBinaryFile& file, double& x){
        return file;
    }

    IBinaryFile& operator>>(IBinaryFile& file, bool& x){
        return file;
    }
    
    IBinaryFile& operator>>(IBinaryFile& file, std::string& x){
        return file;
    }



}
