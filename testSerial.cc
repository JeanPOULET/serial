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

TEST(Read, int8_Negative){
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

TEST(Read, int8_Positive){
	int8_t ecriture =127;
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
		//printf("lecture = %d\n",lecture);
	}
	EXPECT_EQ(lecture,ecriture);
}

TEST(Read, uint16_MaxValue){
	uint16_t ecriture =65535; 
	uint16_t lecture;
	{
		serial::OBinaryFile obinary("fichou");
		obinary << ecriture;
	}

	{
		serial::IBinaryFile ibinary("fichou");
		ibinary>>lecture;
		//printf("lecture = %d\n",lecture);
	}
	EXPECT_EQ(lecture,ecriture);
}

TEST(Read, int16_Negative){
	int16_t ecriture = -32768; 
	int16_t lecture;
	{
		serial::OBinaryFile obinary("fichou");
		obinary << ecriture;
	}

	{
		serial::IBinaryFile ibinary("fichou");
		ibinary>>lecture;
		//printf("lecture = %d\n",lecture);
	}
	EXPECT_EQ(lecture,ecriture);
}

TEST(Read, int16_Positive){
	int16_t ecriture = 32768; 
	int16_t lecture;
	{
		serial::OBinaryFile obinary("fichou");
		obinary << ecriture;
	}

	{
		serial::IBinaryFile ibinary("fichou");
		ibinary>>lecture;
		//printf("lecture = %d\n",lecture);
	}
	EXPECT_EQ(lecture,ecriture);
}

TEST(Read, uint32_MaxValue){
	uint32_t ecriture = 4294967295; 
	uint32_t lecture;
	{
		serial::OBinaryFile obinary("fichou");
		obinary << ecriture;
	}

	{
		serial::IBinaryFile ibinary("fichou");
		ibinary>>lecture;
		//printf("lecture = %d\n",lecture);
	}
	EXPECT_EQ(lecture,ecriture);
}

TEST(Read, int32_Positive){
	int32_t ecriture = 2147483647; 
	int32_t lecture;
	{
		serial::OBinaryFile obinary("fichou");
		obinary << ecriture;
	}

	{
		serial::IBinaryFile ibinary("fichou");
		ibinary>>lecture;
		//printf("lecture = %d\n",lecture);
	}
	EXPECT_EQ(lecture,ecriture);
}

TEST(Read, int32_Negative){
	int32_t ecriture = -2147483647; 
	int32_t lecture;
	{
		serial::OBinaryFile obinary("fichou");
		obinary << ecriture;
	}

	{
		serial::IBinaryFile ibinary("fichou");
		ibinary>>lecture;
		//printf("lecture = %d\n",lecture);
	}
	EXPECT_EQ(lecture,ecriture);
}


TEST(Read, uint64_MaxValue){
	uint64_t ecriture = 18446744073709551614; 
	uint64_t lecture;
	{
		serial::OBinaryFile obinary("fichou");
		obinary << ecriture;
	}

	{
		serial::IBinaryFile ibinary("fichou");
		ibinary>>lecture;
		//printf("lecture = %ld\n",lecture);
	}
	EXPECT_EQ(lecture,ecriture);
}

TEST(Read, int64_Positive){
	int64_t ecriture = 9223372036854775807; 
	int64_t lecture;
	{
		serial::OBinaryFile obinary("fichou");
		obinary << ecriture;
	}

	{
		serial::IBinaryFile ibinary("fichou");
		ibinary>>lecture;
		//printf("lecture = %ld\n",lecture);
	}
	EXPECT_EQ(lecture,ecriture);
}

TEST(Read, int64_Negative){
	int64_t ecriture = -9223372036854775807; 
	int64_t lecture;
	{
		serial::OBinaryFile obinary("fichou");
		obinary << ecriture;
	}

	{
		serial::IBinaryFile ibinary("fichou");
		ibinary>>lecture;
		//printf("lecture = %ld\n",lecture);
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
