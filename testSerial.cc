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
	char charEntré ='V'; 
	char CharLu;
  	{
		serial::OBinaryFile obinary("ficCar");
		obinary << charEntré;
 	}
	{
		serial::IBinaryFile ibinary("ficCar");
		ibinary>>CharLu;
		//printf("CharLu = %c\n",CharLu);
	}

	EXPECT_EQ(charEntré, CharLu);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
