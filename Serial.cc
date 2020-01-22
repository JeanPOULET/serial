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
        std::fclose(m_file);
       } 

    OBinaryFile::OBinaryFile(OBinaryFile&& other) noexcept
        : m_file(std::move(other.m_file)){}    

    OBinaryFile& OBinaryFile::operator=(OBinaryFile&& other) noexcept
        {
            std::move(other.m_file);
            return *this;
        }

    std::size_t OBinaryFile::write(const std::byte* data, std::size_t size){
        return std::fwrite(data,size,size,m_file);
        
    }

    OBinaryFile& operator<<(OBinaryFile& file, uint8_t x){
        std::byte b = {(std::byte(x))};
        file.write(&b,1);  
        return file; 
    }

    OBinaryFile& operator<<(OBinaryFile& file, int8_t x){
        std::byte b = std::byte(x); 
        file.write(&b,1);
        return file;
    }

    OBinaryFile& operator<<(OBinaryFile& file, uint16_t x){
        std::byte b[2];
        b[0] = std::byte(x & 0xff);
        b[1] = std::byte(x >> 8 & 0xff);
        file.write(&b[0],1);
        file.write(&b[1],1);
        return file;
    }

    OBinaryFile& operator<<(OBinaryFile& file, int16_t x){
        std::byte b[2];
        b[0] = std::byte(x & 0xff);
        b[1] = std::byte(x >> 8 & 0xff);
        file.write(&b[0],1);
        file.write(&b[1],1);
        return file;
    }

    OBinaryFile& operator<<(OBinaryFile& file, uint32_t x){
        std::byte b[4];
        b[0] = std::byte(x & 0xff);
        b[1] = std::byte(x >> 8 & 0xff);
        b[2] = std::byte(x >> 16 & 0xff);
        b[3] = std::byte(x >> 24 & 0xff);
        for(int i=0;i<4;++i){
            file.write(&b[i],1);
        }
        return file;
    }

    OBinaryFile& operator<<(OBinaryFile& file, int32_t x){
        std::byte b[4];
        b[0] = std::byte(x & 0xff);
        b[1] = std::byte(x >> 8 & 0xff);
        b[2] = std::byte(x >> 16 & 0xff);
        b[3] = std::byte(x >> 24 & 0xff);
        for(int i=0;i<4;++i){
            file.write(&b[i],1);
        }
        return file;
    }

    OBinaryFile& operator<<(OBinaryFile& file, uint64_t x){
        std::byte b[8];
        b[0] = std::byte(x & 0xff);
        b[1] = std::byte(x >> 8 & 0xff);
        b[2] = std::byte(x >> 16 & 0xff);
        b[3] = std::byte(x >> 24 & 0xff);
        b[4] = std::byte(x >> 32 & 0xff);
        b[5] = std::byte(x >> 40 & 0xff);
        b[6] = std::byte(x >> 48 & 0xff);
        b[7] = std::byte(x >> 54 & 0xff);
        for(int i=0;i<8;++i){
            file.write(&b[i],1);
        }
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
            std::fclose(m_file);
        }

    IBinaryFile::IBinaryFile(IBinaryFile&& other) noexcept
        : m_file(std::move(other.m_file)){}

    IBinaryFile& IBinaryFile::operator=(IBinaryFile&& other) noexcept
        {
            std::move(other.m_file);
            return *this;
        }

    std::size_t IBinaryFile::read(std::byte* data, std::size_t size){
        return std::fread(data,size,size,m_file);
    }

    IBinaryFile& operator>>(IBinaryFile& file, uint8_t& x){
        std::byte b;
        file.read(&b,1); 
        x = (uint8_t)b;
        return file;
    }

    IBinaryFile& operator>>(IBinaryFile& file, int8_t& x){
        std::byte b;
        file.read(&b,1);
        x = int8_t(b);
        return file;
    }

    IBinaryFile& operator>>(IBinaryFile& file, uint16_t& x){
        std::byte b[2];
        file.read(&b[0],1);
        file.read(&b[1],1);
        x = (uint16_t) b[1]<<8 | (uint16_t)b[0];
        return file;
    }

    IBinaryFile& operator>>(IBinaryFile& file, int16_t& x){
        std::byte b[2];
        file.read(&b[0],1);
        file.read(&b[1],1);
        x = (int16_t) b[1]<<8 | (int16_t)b[0];
        return file;
    }

    IBinaryFile& operator>>(IBinaryFile& file, uint32_t& x){
        std::byte b[4];
        for(int i=0;i<4;++i){
            file.read(&b[i],1);
        }
        x = (uint32_t) b[3]<<24 | (uint32_t) b[2]<<16 | (uint32_t) b[1]<<8 | (uint32_t) b[0];
        return file;
    }

    IBinaryFile& operator>>(IBinaryFile& file, int32_t& x){
        std::byte b[4];
        for(int i=0;i<4;++i){
            file.read(&b[i],1);
        }
        x = (uint32_t) b[3]<<24 | (uint32_t) b[2]<<16 | (uint32_t) b[1]<<8 | (uint32_t) b[0];
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
