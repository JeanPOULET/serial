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
        b[1] = std::byte(x & 0xff);
        b[0] = std::byte(x >> 8 & 0xff);
        file.write(&b[0],1);
        file.write(&b[1],1);
        return file;
    }

    OBinaryFile& operator<<(OBinaryFile& file, int16_t x){
        std::byte b[2];
        b[1] = std::byte(x & 0xff);
        b[0] = std::byte(x >> 8 & 0xff);
        file.write(&b[0],1);
        file.write(&b[1],1);
        return file;
    }

    OBinaryFile& operator<<(OBinaryFile& file, uint32_t x){
        std::byte b[4];
        b[3] = std::byte(x & 0xff);
        b[2] = std::byte(x >> 8 & 0xff);
        b[1] = std::byte(x >> 16 & 0xff);
        b[0] = std::byte(x >> 24 & 0xff);
        for(int i=0;i<4;++i){
            file.write(&b[i],1);
        }
        return file;
    }

    OBinaryFile& operator<<(OBinaryFile& file, int32_t x){
        std::byte b[4];
        b[3] = std::byte(x & 0xff);
        b[2] = std::byte(x >> 8 & 0xff);
        b[1] = std::byte(x >> 16 & 0xff);
        b[0] = std::byte(x >> 24 & 0xff);
        for(int i=0;i<4;++i){
            file.write(&b[i],1);
        }
        return file;
    }

    OBinaryFile& operator<<(OBinaryFile& file, uint64_t x){
        std::byte b[8];
        b[7] = std::byte(x & 0xff);
        b[6] = std::byte(x >> 8 & 0xff);
        b[5] = std::byte(x >> 16 & 0xff);
        b[4] = std::byte(x >> 24 & 0xff);
        b[3] = std::byte(x >> 32 & 0xff);
        b[2] = std::byte(x >> 40 & 0xff);
        b[1] = std::byte(x >> 48 & 0xff);
        b[0] = std::byte(x >> 56 & 0xff);
        for(int i=0;i<8;++i){
            file.write(&b[i],1);
        }
        return file;
    }

    OBinaryFile& operator<<(OBinaryFile& file, int64_t x){
        std::byte b[8];
        b[7] = std::byte(x & 0xff);
        b[6] = std::byte(x >> 8 & 0xff);
        b[5] = std::byte(x >> 16 & 0xff);
        b[4] = std::byte(x >> 24 & 0xff);
        b[3] = std::byte(x >> 32 & 0xff);
        b[2] = std::byte(x >> 40 & 0xff);
        b[1] = std::byte(x >> 48 & 0xff);
        b[0] = std::byte(x >> 56 & 0xff);
        for(int i=0;i<8;++i){
            file.write(&b[i],1);
        }
        return file;
    }

    OBinaryFile& operator<<(OBinaryFile& file, char x){
        std::byte b =static_cast<std::byte>(x);
        file.write(&b,1);
        return file;
    }

    OBinaryFile& operator<<(OBinaryFile& file, float x){
        uint32_t u;
        std::memcpy(&u,&x,sizeof(uint32_t));
        file << u;
        return file;
    }

    OBinaryFile& operator<<(OBinaryFile& file, double x){
        uint64_t u;
        std::memcpy(&u,&x,sizeof(uint64_t));
        file << u;
        return file;
    }

    OBinaryFile& operator<<(OBinaryFile& file, bool x){
        std::byte b = static_cast<std::byte>(x);
        file.write(&b,1);
        return file;
    }

    OBinaryFile& operator<<(OBinaryFile& file, const std::string& x){
        int32_t lg=static_cast<int32_t>(x.length()-1);
        file<<lg;
        for(int32_t i=0;i<lg;++i){
            char c = x[i];
            file<<c;
        }
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
        x = (uint16_t) b[0]<<8 | (uint16_t)b[1];
        return file;
    }

    IBinaryFile& operator>>(IBinaryFile& file, int16_t& x){
        std::byte b[2];
        file.read(&b[0],1);
        file.read(&b[1],1);
        x = (int16_t) b[0]<<8 | (int16_t)b[1];
        return file;
    }

    IBinaryFile& operator>>(IBinaryFile& file, uint32_t& x){
        std::byte b[4];
        for(int i=0;i<4;++i){
            file.read(&b[i],1);
        }
        x = static_cast<uint32_t> (b[0])<<24 | static_cast<uint32_t> (b[1])<<16 | static_cast<uint32_t> (b[2])<<8 | static_cast<uint32_t> (b[3]);
        return file;
    }

    IBinaryFile& operator>>(IBinaryFile& file, int32_t& x){
        std::byte b[4];
        for(int i=0;i<4;++i){
            file.read(&b[i],1);
        }
        x = std::to_integer<uint32_t> (b[0])<<24 | std::to_integer<uint32_t> (b[1])<<16 | std::to_integer<uint32_t> (b[2])<<8 | std::to_integer<uint32_t> (b[3]);
        return file;
    }

    IBinaryFile& operator>>(IBinaryFile& file, uint64_t& x){
        std::byte b[8];
        for(int i=0;i<8;++i){
            file.read(&b[i],1);
        }
        x = 
        std::to_integer<uint64_t> (b[0])<<56 |std::to_integer<uint64_t> (b[1])<<48 |std::to_integer<uint64_t> (b[2])<<40 |
        std::to_integer<uint64_t> (b[3])<<32 |std::to_integer<uint64_t> (b[4])<<24 | std::to_integer<uint64_t> (b[5])<<16 |
        std::to_integer<uint64_t>(b[6])<<8 | std::to_integer<uint64_t> (b[7]);
        return file;
    }

    IBinaryFile& operator>>(IBinaryFile& file, int64_t& x){
        std::byte b[8];
        for(int i=0;i<8;++i){
            file.read(&b[i],1);
        }
        x = (int64_t) b[0]<<56 |(int64_t) b[1]<<48 |(int64_t) b[2]<<40 |(int64_t) b[3]<<32 |(int64_t) b[4]<<24 | (int64_t) b[5]<<16 | (int64_t) b[6]<<8 | (int64_t) b[7];
        return file;
    }

    IBinaryFile& operator>>(IBinaryFile& file, char& x){
        std::byte b;
        file.read(&b,1);
        x=static_cast<char>(b);
        return file;
    }

    IBinaryFile& operator>>(IBinaryFile& file, float& x){
        uint32_t u;
        file>>u;
        float f;
        std::memcpy(&f,&u,sizeof(float));
        x=f;
        return file;
    }

    IBinaryFile& operator>>(IBinaryFile& file, double& x){
        uint64_t u;
        file>>u;
        double f;
        std::memcpy(&f,&u,sizeof(double));
        x=f;
        return file;
    }

    IBinaryFile& operator>>(IBinaryFile& file, bool& x){
        std::byte b;
        file.read(&b,1);
        x=static_cast<bool>(b);
        return file;
    }
    
    IBinaryFile& operator>>(IBinaryFile& file, std::string& x){
        int32_t lg;
        std::string st;
        file >>lg;
        for(int32_t i=0; i<lg;++i){
            file>>st;
        }
        x = st;
        return file;
    }



}
