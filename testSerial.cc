#include "Serial.h"

#include "gtest/gtest.h"

TEST(Read, uint8){
  uint8_t ecriture =42; 
  {
    serial::OBinaryFile obinary("fichou");
    obinary << ecriture;
  }

  {
    serial::IBinaryFile ibinary("fichou");
    uint8_t lecture;
    ibinary>>lecture;
    EXPECT_EQ(lecture,ecriture);
  }

}
TEST(Read, int8){
  int8_t ecriture =-127;
  {
    serial::OBinaryFile obinary("fichou");
    obinary << ecriture;
  }

  {
    serial::IBinaryFile ibinary("fichou");
    int8_t lecture;
    ibinary>>lecture;
    EXPECT_EQ(lecture,ecriture);
  }
}
TEST(Output, char){
  
    serial::OBinaryFile obinary("ficCar");
    char voiture ='V'; 
    obinary << voiture;

    serial::IBinaryFile ibinary("ficCar");
    char lecture;
    ibinary>>lecture;
    printf("lecture = %c\n",lecture);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
