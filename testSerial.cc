#include "Serial.h"

#include "gtest/gtest.h"

TEST(Output, first){
    serial::OBinaryFile obinary("fichou");
    uint8_t voiture =75; 
    obinary << voiture;

    serial::IBinaryFile ibinary("fichou");
    uint8_t lecture;
    ibinary>>lecture;
    printf("%d lecture",lecture);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
