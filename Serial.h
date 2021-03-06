#ifndef SERIAL_H
#define SERIAL_H

#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <array>
#include <map>
#include <set>
#include <string>
#include <vector>

namespace serial {

  /**
   * @brief A file to be written
   */
  class OBinaryFile {
  public:
    /**
     * @brief The mode for opening the file
     */
    enum Mode {
      Truncate,
      Append,
    };

    /**
     * @brief Constructor
     *
     * Opens the file for writing or throws a `std::runtime_error` in case of
     * error.
     */
    OBinaryFile(const std::string& filename, Mode mode = Truncate);

    OBinaryFile(const OBinaryFile&) = delete;
    OBinaryFile(OBinaryFile&& other) noexcept;

    OBinaryFile& operator=(const OBinaryFile&) = delete;
    OBinaryFile& operator=(OBinaryFile&& other) noexcept;

    /**
     * @brief Closes the file
     */
    ~OBinaryFile();

    /**
     * @brief Write `size` bytes pointed by `data` in the file
     *
     * Returns the number of bytes actually written
     */
    std::size_t write(const std::byte* data, std::size_t size);
  private:
    std::FILE* m_file;
  };

  /**
   * @brief A file to be read
   */
  class IBinaryFile {
  public:
    /**
     * @brief Constructor
     *
     * Opens the file for reading or throws a `std::runtime_error` in case of
     * error.
     */
    IBinaryFile(const std::string& filename);

    IBinaryFile(const IBinaryFile&) = delete;
    IBinaryFile(IBinaryFile&& other) noexcept;

    IBinaryFile& operator=(const IBinaryFile&) = delete;
    IBinaryFile& operator=(IBinaryFile&& other) noexcept;

    /**
     * @brief Closes the file
     */
    ~IBinaryFile();

    /**
     * @brief Read `size` bytes from the file and store them in the buffer
     * pointed by `data`.
     *
     * Returns the number of bytes actually read.
     */
    std::size_t read(std::byte* data, std::size_t size);

  private:
    std::FILE* m_file;
  };


  OBinaryFile& operator<<(OBinaryFile& file, uint8_t x);
  OBinaryFile& operator<<(OBinaryFile& file, int8_t x);
  OBinaryFile& operator<<(OBinaryFile& file, uint16_t x);
  OBinaryFile& operator<<(OBinaryFile& file, int16_t x);
  OBinaryFile& operator<<(OBinaryFile& file, uint32_t x);
  OBinaryFile& operator<<(OBinaryFile& file, int32_t x);
  OBinaryFile& operator<<(OBinaryFile& file, uint64_t x);
  OBinaryFile& operator<<(OBinaryFile& file, int64_t x);
  OBinaryFile& operator<<(OBinaryFile& file, char x);
  OBinaryFile& operator<<(OBinaryFile& file, float x);
  OBinaryFile& operator<<(OBinaryFile& file, double x);
  OBinaryFile& operator<<(OBinaryFile& file, bool x);
  OBinaryFile& operator<<(OBinaryFile& file, const std::string& x);

  template<typename T>
  OBinaryFile& operator<<(OBinaryFile& file, const std::vector<T>& x) {
    uint32_t lg = static_cast<uint32_t>(x.size());
    file<<lg;
    T var;
    for(uint32_t i=0; i<lg;++i){
      var = x[i];
      file<<var;

    }
    return file;
  }

  template<typename T, std::size_t N>
  OBinaryFile& operator<<(OBinaryFile& file, const std::array<T,N>& x) {
    uint32_t lg = static_cast<uint32_t>(x.size());
    T var;
    for(uint32_t i=0; i<lg;++i){
      var = x[i];
      file<<var;

    }

    return file;
  }

  template<typename K, typename V>
  OBinaryFile& operator<<(OBinaryFile& file, const std::map<K,V>& x) {
    uint32_t lg = static_cast<uint32_t>(x.size());
    file<<lg;
    K varL;
    V varR;
    for(auto i=x.begin();i!=x.end();++i){
      varL = i->first;
      varR = i->second;
      file<<varL;
      file<<varR;
    }

    return file;
  }

  template<typename T>
  OBinaryFile& operator<<(OBinaryFile& file, const std::set<T>& x) {
    uint32_t lg = static_cast<uint32_t>(x.size());
    file<<lg;
    T var;
    for(auto i=x.begin();i!=x.end();++i){
      var = *i;
      file<<var;

    }
    return file;
  }

  IBinaryFile& operator>>(IBinaryFile& file, int8_t& x);
  IBinaryFile& operator>>(IBinaryFile& file, uint8_t& x);
  IBinaryFile& operator>>(IBinaryFile& file, int16_t& x);
  IBinaryFile& operator>>(IBinaryFile& file, uint16_t& x);
  IBinaryFile& operator>>(IBinaryFile& file, int32_t& x);
  IBinaryFile& operator>>(IBinaryFile& file, uint32_t& x);
  IBinaryFile& operator>>(IBinaryFile& file, int64_t& x);
  IBinaryFile& operator>>(IBinaryFile& file, uint64_t& x);
  IBinaryFile& operator>>(IBinaryFile& file, char& x);
  IBinaryFile& operator>>(IBinaryFile& file, float& x);
  IBinaryFile& operator>>(IBinaryFile& file, double& x);
  IBinaryFile& operator>>(IBinaryFile& file, bool& x);
  IBinaryFile& operator>>(IBinaryFile& file, std::string& x);

  template<typename T>
  IBinaryFile& operator>>(IBinaryFile& file, std::vector<T>& x) {
    uint32_t lg;
    file>>lg;
    std::vector<T> vect;
    T tmp;
    for(uint32_t i = 0 ; i < lg ; ++i){
      file>>tmp;
      vect.push_back(tmp);
    }
    x = vect;
    return file;
  }

  template<typename T, std::size_t N>
  IBinaryFile& operator>>(IBinaryFile& file, std::array<T, N>& x) {
    uint32_t lg = x.size();

    T tmp;
    for(uint32_t i = 0 ; i < lg ; ++i){
      file>>tmp;
      x[i]=tmp;
    }

    return file;
  }

  template<typename K, typename V>
  IBinaryFile& operator>>(IBinaryFile& file, std::map<K, V>& x) {
    uint32_t lg;
    file>>lg;    
    K tmpL;
    V tmpR;
    for(uint32_t i = 0;i<lg;i++) {
      file>>tmpL;
      file>>tmpR;
      x.insert({tmpL,tmpR});
      
    }
    return file;
  }

  template<typename T>
  IBinaryFile& operator>>(IBinaryFile& file, std::set<T>& x) {
    uint32_t lg;
    file>>lg;
    std::set<T> st;
    T tmp;
    for(uint32_t i = 0 ; i < lg ; ++i){
      file>>tmp;
      st.insert(tmp);
    }
    x = st;
    return file;
  }

} // namespace serial

#endif // SERIAL_H
