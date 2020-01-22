#include "Serial.h"

#include "gtest/gtest.h"

											/************************************
											 * 			UINT8 & INT8			*
											 ************************************/
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

TEST(Read, int8_Min){
	int8_t ecriture =std::numeric_limits<int>::min();
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

TEST(Read, int8_Random){
	int8_t ecriture = -52;
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

TEST(Read, int8_Max){
	int8_t ecriture =std::numeric_limits<int>::max();
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

											/************************************
											 * 			UINT16 & INT16			*
											 ************************************/
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
	uint16_t ecriture =std::numeric_limits<uint16_t>::max(); 
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

TEST(Read, int16_Min){
	int16_t ecriture = std::numeric_limits<int16_t>::min(); 
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

TEST(Read, int16_Random){
	int16_t ecriture = 25600; 
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

TEST(Read, int16_Max){
	int16_t ecriture = std::numeric_limits<int16_t>::max(); 
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

											/************************************
											 * 			UINT32 & INT32			*
											 ************************************/
TEST(Read, uint32_MaxValue){
	uint32_t ecriture = std::numeric_limits<uint32_t>::max(); 
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

TEST(Read, int32_Max){
	int32_t ecriture = std::numeric_limits<int32_t>::max(); 
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

TEST(Read, int32_Random){
	int32_t ecriture = 16323; 
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

TEST(Read, int32_Min){
	int32_t ecriture = std::numeric_limits<int32_t>::min(); 
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

											/************************************
											 * 			UINT64 & INT64			*
											 ************************************/
TEST(Read, uint64_MaxValue){
	uint64_t ecriture = std::numeric_limits<uint64_t>::max(); 
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

TEST(Read, int64_Max){
	int64_t ecriture = std::numeric_limits<int64_t>::max(); 
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

TEST(Read, int64_Random){
	int64_t ecriture = 56781435288858; 
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

TEST(Read, int64_Min){
	int64_t ecriture = std::numeric_limits<int64_t>::min(); 
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

											/************************************
											 * 				FLOAT				*
											 ************************************/
TEST(Read, float_Min){
	float ecriture = std::numeric_limits<float>::min(); 
	float lecture;
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

TEST(Read, float_Random){
	float ecriture = 82.543; 
	float lecture;
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

TEST(Read, float_Max){
	float ecriture = std::numeric_limits<float>::max(); 
	float lecture;
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

											/************************************
											 * 				DOUBLE				*
											 ************************************/
TEST(Read, double_Min){
	double ecriture = std::numeric_limits<double>::min(); 
	double lecture;
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

TEST(Read, double_Random){
	double ecriture = 82.543; 
	double lecture;
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

TEST(Read, double_Max){
	double ecriture = std::numeric_limits<double>::min(); 
	double lecture;
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
											/************************************
											 * 				BOOL				*
											 ************************************/
TEST(Read, bool_false){
	bool boolEntree =false; 
	bool boolLu;
  	{
		serial::OBinaryFile obinary("ficCar");
		obinary << boolEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficCar");
		ibinary>>boolLu;
		//printf("CharLu = %c\n",CharLu);
	}
	EXPECT_EQ(boolEntree, boolLu);
}

TEST(Read, bool_true){
	bool boolEntree =true; 
	bool boolLu;
  	{
		serial::OBinaryFile obinary("ficCar");
		obinary << boolEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficCar");
		ibinary>>boolLu;
		//printf("CharLu = %c\n",CharLu);
	}
	EXPECT_EQ(boolEntree, boolLu);
}

											/************************************
											 * 				CHAR				*
											 ************************************/
TEST(Read, char){
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
