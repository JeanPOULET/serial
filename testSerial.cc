#include "Serial.h"

#include "gtest/gtest.h"

TEST(Read, uint8){
	uint8_t ecriture =42; 
	uint8_t lecture;
	{
		serial::OBinaryFile obinary("fichou");
		obinary << ecriture;
	}

	{
		serial::IBinaryFile ibinary("fichou");
		ibinary>>lecture;
	}
	EXPECT_EQ(lecture,ecriture);
}

TEST(Read, int8){
	int8_t ecriture =-127;
	int8_t lecture;
	{
		serial::OBinaryFile obinary("fichou");
		obinary << ecriture;
	}

	{
		serial::IBinaryFile ibinary("fichou");
		ibinary>>lecture;
	}
	EXPECT_EQ(lecture,ecriture);
}

TEST(Read, uint16){
	uint16_t ecriture =300; 
	uint16_t lecture;
	{
		serial::OBinaryFile obinary("fichou");
		obinary << ecriture;
	}

	{
		serial::IBinaryFile ibinary("fichou");
		ibinary>>lecture;
		printf("lecture = %d\n",lecture);
	}
	EXPECT_EQ(lecture,ecriture);
}

TEST(Read, uint16_2){
	uint16_t ecriture =65535; 
	uint16_t lecture;
	{
		serial::OBinaryFile obinary("fichou");
		obinary << ecriture;
	}

	{
		serial::IBinaryFile ibinary("fichou");
		ibinary>>lecture;
		printf("lecture = %d\n",lecture);
	}
	EXPECT_EQ(lecture,ecriture);
}

TEST(Read, int16){
	int16_t ecriture = -32768; 
	int16_t lecture;
	{
		serial::OBinaryFile obinary("fichou");
		obinary << ecriture;
	}

	{
		serial::IBinaryFile ibinary("fichou");
		ibinary>>lecture;
		printf("lecture = %d\n",lecture);
	}
	EXPECT_EQ(lecture,ecriture);
}

TEST(Output, char){
	char charEntree ='V'; 
	char CharLu;
  	{
		serial::OBinaryFile obinary("ficCar");
		obinary << charEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficCar");
		ibinary>>CharLu;
		//printf("CharLu = %c\n",CharLu);
	}
	EXPECT_EQ(charEntree, CharLu);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
