#include "Serial.h"

#include "gtest/gtest.h"

TEST(Read, uint8){
  	{
		serial::OBinaryFile obinary("fichou");
		uint8_t voiture = 42; 
		obinary << voiture;
  	}
  	{
		serial::IBinaryFile ibinary("fichou");
		uint8_t lecture;
		ibinary>>lecture;
		printf("lecture = %d\n",lecture);
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
