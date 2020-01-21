#include "Serial.h"

#include "gtest/gtest.h"

TEST(Read, uint8){
    serial::OBinaryFile obinary("fichou");
    uint8_t voiture =75; 
    obinary << voiture;

    serial::IBinaryFile ibinary("fichou");
    uint8_t lecture;
    ibinary>>lecture;
    printf("lecture = %d\n",lecture);
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
