#include "Serial.h"

#include "gtest/gtest.h"

											/************************************
											 * 			UINT8 & INT8			*
											 ************************************/
TEST(Read, uint8_Min){
	uint8_t ecriture =std::numeric_limits<uint8_t>::min(); 
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

TEST(Read, uint8_Zero){
	uint8_t ecriture =0; 
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

TEST(Read, uint8_Random){
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

TEST(Read, uint8_Max){
	uint8_t ecriture =std::numeric_limits<uint8_t>::max(); 
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
	int8_t ecriture =std::numeric_limits<int8_t>::max();
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

TEST(Read, int8_Zero){
	int8_t ecriture = 0;
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

TEST(Read, int8_ZeroNegatif){
	int8_t ecriture = -0;
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
	int8_t ecriture =std::numeric_limits<int8_t>::max();
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
TEST(Read, uint16_Min){
	uint16_t ecriture =std::numeric_limits<uint16_t>::min(); 
	uint16_t lecture;
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

TEST(Read, uint16_Zero){
	uint16_t ecriture =0; 
	uint16_t lecture;
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

TEST(Read, uint16_Random){
	uint16_t ecriture =300; 
	uint16_t lecture;
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

TEST(Read, uint16_Max){
	uint16_t ecriture =std::numeric_limits<uint16_t>::max(); 
	uint16_t lecture;
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
	}
	EXPECT_EQ(lecture,ecriture);
}

TEST(Read, int16_Zero){
	int16_t ecriture = 0; 
	int16_t lecture;
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

TEST(Read, int16_ZeroNegatif){
	int16_t ecriture = -0; 
	int16_t lecture;
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
	}
	EXPECT_EQ(lecture,ecriture);
}

											/************************************
											 * 			UINT32 & INT32			*
											 ************************************/
TEST(Read, uint32_Min){
	uint32_t ecriture = std::numeric_limits<uint32_t>::min(); 
	uint32_t lecture;
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

TEST(Read, uint32_Zero){
	uint32_t ecriture = 0; 
	uint32_t lecture;
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

TEST(Read, uint32_Random){
	uint32_t ecriture = 579346001; 
	uint32_t lecture;
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

TEST(Read, uint32_Max){
	uint32_t ecriture = std::numeric_limits<uint32_t>::max(); 
	uint32_t lecture;
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
	}
	EXPECT_EQ(lecture,ecriture);
}

TEST(Read, int32_Zero){
	int32_t ecriture = 0; 
	int32_t lecture;
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

TEST(Read, int32_ZeroNegatif){
	int32_t ecriture = -0; 
	int32_t lecture;
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
	}
	EXPECT_EQ(lecture,ecriture);
}


											/************************************
											 * 			UINT64 & INT64			*
											 ************************************/
TEST(Read, uint64_Min){
	uint64_t ecriture = std::numeric_limits<uint64_t>::min(); 
	uint64_t lecture;
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

TEST(Read, uint64_Zero){
	uint64_t ecriture = 0; 
	uint64_t lecture;
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

TEST(Read, uint64_Random){
	uint64_t ecriture = 1200; 
	uint64_t lecture;
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

TEST(Read, uint64_Max){
	uint64_t ecriture = std::numeric_limits<uint64_t>::max(); 
	uint64_t lecture;
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
	}
	EXPECT_EQ(lecture,ecriture);
}

TEST(Read, int64_Zero){
	int64_t ecriture = 0; 
	int64_t lecture;
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

TEST(Read, int64_ZeroNegatif){
	int64_t ecriture = -0; 
	int64_t lecture;
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
	}
	EXPECT_EQ(lecture,ecriture);
}

TEST(Read, float_Zero){
	float ecriture = 0; 
	float lecture;
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

TEST(Read, float_ZeroNegatif){
	float ecriture = -0; 
	float lecture;
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
	}
	EXPECT_EQ(lecture,ecriture);
}

TEST(Read, double_Zero){
	double ecriture = 0; 
	double lecture;
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
TEST(Read, double_ZeroNegatif){
	double ecriture = -0; 
	double lecture;
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
	}
	EXPECT_EQ(lecture,ecriture);
}

TEST(Read, double_Max){
	double ecriture = std::numeric_limits<double>::max(); 
	double lecture;
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
	}
	EXPECT_EQ(boolEntree, boolLu);
}

											/************************************
											 * 				CHAR				*
											 ************************************/
TEST(Read, char_Maj){
	char charEntree ='V'; 
	char charLu;
  	{
		serial::OBinaryFile obinary("ficCar");
		obinary << charEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficCar");
		ibinary>>charLu;
	}
	EXPECT_EQ(charEntree, charLu);
}

TEST(Read, char_Min){
	char charEntree ='h'; 
	char charLu;
  	{
		serial::OBinaryFile obinary("ficCar");
		obinary << charEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficCar");
		ibinary>>charLu;
	}
	EXPECT_EQ(charEntree, charLu);
}

TEST(Read, char_Spe){
	char charEntree ='&'; 
	char charLu;
  	{
		serial::OBinaryFile obinary("ficCar");
		obinary << charEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficCar");
		ibinary>>charLu;
	}
	EXPECT_EQ(charEntree, charLu);
}

											/************************************
											 * 				STRING				*
											 ************************************/
TEST(Read, chaine_superCourte){
	std::string chaineEntree ="z"; 
	std::string chaineLu;
  	{
		serial::OBinaryFile obinary("ficString");
		obinary << chaineEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficString");
		ibinary>>chaineLu;
	}
	EXPECT_EQ(chaineEntree, chaineLu);
}

TEST(Read, chaine_courte){
	std::string chaineEntree ="Bande de petits joueurs"; 
	std::string chaineLu;
  	{
		serial::OBinaryFile obinary("ficString");
		obinary << chaineEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficString");
		ibinary>>chaineLu;
	}
	EXPECT_EQ(chaineEntree, chaineLu);
}

TEST(Read, chaine_longue){
	std::string chaineEntree ="Bande de petits joueurs, faut vous dépêchez si vous voulez trouver le trésor, un demi-million de dollars ça en fait des paquets de clopes, faut aller au fond de la godasse, vous êtes prêt à mourir ?, j'ai toujours voulu vivre au far ouest, y a une équipe rivale qui va vous passez devant, vous vous plaignez que les professeurs vous engueule quand vous faites une erreur et pour une fois que je vous offre l'occasion de vous vengez vous le faite pas ?, on va passer à quelque chose de plus fort !"; 
	std::string chaineLu;
  	{
		serial::OBinaryFile obinary("ficString");
		obinary << chaineEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficString");
		ibinary>>chaineLu;
	}
	EXPECT_EQ(chaineEntree, chaineLu);
}

											/************************************
											 * 				VECTOR				*
											 ************************************/
TEST(Read, vector_uint8){
	std::vector<uint8_t> vectorEntree = {1,2,3};
	std::vector<uint8_t> vectorLu;
  	{
		serial::OBinaryFile obinary("ficTemplate");
		obinary << vectorEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficTemplate");
		ibinary>>vectorLu;
	}
	EXPECT_EQ(vectorEntree, vectorLu);
}

TEST(Read, vector_int8){
	std::vector<int8_t> vectorEntree = {42,-2,3};
	std::vector<int8_t> vectorLu;
  	{
		serial::OBinaryFile obinary("ficTemplate");
		obinary << vectorEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficTemplate");
		ibinary>>vectorLu;
	}
	EXPECT_EQ(vectorEntree, vectorLu);
}

TEST(Read, vector_uint64){
	std::vector<uint64_t> vectorEntree = {11111111111111111, 2222222222, 3333333333, 0};
	std::vector<uint64_t> vectorLu;
  	{
		serial::OBinaryFile obinary("ficTemplate");
		obinary << vectorEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficTemplate");
		ibinary>>vectorLu;
	}
	EXPECT_EQ(vectorEntree, vectorLu);
}

TEST(Read, vector_int64){
	std::vector<int64_t> vectorEntree = {424242424242,-2222222222,33333333333, 0, -0};
	std::vector<int64_t> vectorLu;
  	{
		serial::OBinaryFile obinary("ficTemplate");
		obinary << vectorEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficTemplate");
		ibinary>>vectorLu;
	}
	EXPECT_EQ(vectorEntree, vectorLu);
}

TEST(Read, vector_char){
	std::vector<char> vectorEntree = {'4','$','x'};
	std::vector<char> vectorLu;
  	{
		serial::OBinaryFile obinary("ficTemplate");
		obinary << vectorEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficTemplate");
		ibinary>>vectorLu;
	}
	EXPECT_EQ(vectorEntree, vectorLu);
}

TEST(Read, vector_string){
	std::vector<std::string> vectorEntree = {"xXxGrosB0l0$$3xXx","123456789","J'adore l'Iran dans 20-30 semaines y en aura plus !"};
	std::vector<std::string> vectorLu;
  	{
		serial::OBinaryFile obinary("ficTemplate");
		obinary << vectorEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficTemplate");
		ibinary>>vectorLu;
	}
	EXPECT_EQ(vectorEntree, vectorLu);
}

TEST(Read, vector_bool){
	std::vector<bool> vectorEntree = {true, false, true};
	std::vector<bool> vectorLu;
  	{
		serial::OBinaryFile obinary("ficTemplate");
		obinary << vectorEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficTemplate");
		ibinary>>vectorLu;
	}
	EXPECT_EQ(vectorEntree, vectorLu);
}

											/************************************
											 * 				map				*
											 ************************************/
TEST(Read, array_uint8){
	std::array<uint8_t, 3> arrayEntree = {1,2,3};
	std::array<uint8_t, 3> arrayLu;
  	{
		serial::OBinaryFile obinary("ficTemplate");
		obinary << arrayEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficTemplate");
		ibinary>>arrayLu;
	}
	for(size_t ln = 0; ln < arrayEntree.size(); ln++){
		EXPECT_EQ(arrayEntree[ln], arrayLu[ln]);
	}
}

TEST(Read, array_int8){
	std::array<int8_t, 3> arrayEntree = {1,-2,0};
	std::array<int8_t, 3> arrayLu;
  	{
		serial::OBinaryFile obinary("ficTemplate");
		obinary << arrayEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficTemplate");
		ibinary>>arrayLu;
	}
	for(size_t ln = 0; ln < arrayEntree.size(); ln++){
		EXPECT_EQ(arrayEntree[ln], arrayLu[ln]);
	}
}

TEST(Read, array_string){
	std::array<std::string, 3> arrayEntree = {"Salut les bros c'est LRB","J'aime les patates","Kek"};
	std::array<std::string, 3> arrayLu;
  	{
		serial::OBinaryFile obinary("ficTemplate");
		obinary << arrayEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficTemplate");
		ibinary>>arrayLu;
	}
	for(size_t ln = 0; ln < arrayEntree.size(); ln++){
		EXPECT_EQ(arrayEntree[ln], arrayLu[ln]);
	}
}

TEST(Read, array_char){
	std::array<char, 3> arrayEntree = {'r','[','8'};
	std::array<char, 3> arrayLu;
  	{
		serial::OBinaryFile obinary("ficTemplate");
		obinary << arrayEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficTemplate");
		ibinary>>arrayLu;
	}
	for(size_t ln = 0; ln < arrayEntree.size(); ln++){
		EXPECT_EQ(arrayEntree[ln], arrayLu[ln]);
	}
}

TEST(Read, array_bool){
	std::array<bool, 3> arrayEntree = {true,false,false};
	std::array<bool, 3> arrayLu;
  	{
		serial::OBinaryFile obinary("ficTemplate");
		obinary << arrayEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficTemplate");
		ibinary>>arrayLu;
	}
	for(size_t ln = 0; ln < arrayEntree.size(); ln++){
		EXPECT_EQ(arrayEntree[ln], arrayLu[ln]);
	}
}

TEST(Read, array_uint64){
	std::array<uint64_t, 3> arrayEntree = {11111111111111,2222222222,3333333333};
	std::array<uint64_t, 3> arrayLu;
  	{
		serial::OBinaryFile obinary("ficTemplate");
		obinary << arrayEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficTemplate");
		ibinary>>arrayLu;
	}
	for(size_t ln = 0; ln < arrayEntree.size(); ln++){
		EXPECT_EQ(arrayEntree[ln], arrayLu[ln]);
	}
}

TEST(Read, array_int64){
	std::array<int64_t, 3> arrayEntree = {11111111111,-22222222222,-0};
	std::array<int64_t, 3> arrayLu;
  	{
		serial::OBinaryFile obinary("ficTemplate");
		obinary << arrayEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficTemplate");
		ibinary>>arrayLu;
	}
	for(size_t ln = 0; ln < arrayEntree.size(); ln++){
		EXPECT_EQ(arrayEntree[ln], arrayLu[ln]);
	}
}

											/************************************
											 * 				MAP					*
											 ************************************/
TEST(Read, map_uint8){
	std::map<uint8_t, uint8_t> mapEntree;
	mapEntree[2] = 8;
	mapEntree[9] = 0;
	mapEntree[5] = 5;
	std::map<uint8_t, uint8_t> mapLu;
  	{
		serial::OBinaryFile obinary("ficTemplate");
		obinary << mapEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficTemplate");
		ibinary>>mapLu;
	}
	EXPECT_EQ(mapEntree.size(), mapLu.size());
	EXPECT_TRUE(std::equal(mapEntree.begin(), mapEntree.end, mapLu.begin()));
	EXPECT_TRUE(std::equal(mapLu.begin(), mapLu.end, mapEntree.begin()));
}

TEST(Read, map_int8){
	std::map<int8_t, int8_t> mapEntree;
	mapEntree[2] = 8;
	mapEntree[9] = -0;
	mapEntree[-5] = -5;
	std::map<int8_t, int8_t> mapLu;
  	{
		serial::OBinaryFile obinary("ficTemplate");
		obinary << mapEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficTemplate");
		ibinary>>mapLu;
	}
	EXPECT_EQ(mapEntree.size(), mapLu.size());
	EXPECT_TRUE(std::equal(mapEntree.begin(), mapEntree.end, mapLu.begin());
	EXPECT_TRUE(std::equal(mapLu.begin(), mapLu.end, mapEntree.begin());
}

TEST(Read, map_uint64){
	std::map<uint64_t, uint64_t> mapEntree;
	mapEntree[2] = 11111111111111;
	mapEntree[2222222222] = 22222222222;
	mapEntree[5] = 5;
	std::map<uint64_t, uint64_t> mapLu;
  	{
		serial::OBinaryFile obinary("ficTemplate");
		obinary << mapEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficTemplate");
		ibinary>>mapLu;
	}
	EXPECT_EQ(mapEntree.size(), mapLu.size());
	EXPECT_TRUE(std::equal(mapEntree.begin(), mapEntree.end, mapLu.begin());
	EXPECT_TRUE(std::equal(mapLu.begin(), mapLu.end, mapEntree.begin());
}

TEST(Read, map_int64){
	std::map<int64_t, int64_t> mapEntree;
	mapEntree[11111111111] = 8;
	mapEntree[-9] = -22222222222;
	mapEntree[0] = -0;
	std::map<int64_t, int64_t> mapLu;
  	{
		serial::OBinaryFile obinary("ficTemplate");
		obinary << mapEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficTemplate");
		ibinary>>mapLu;
	}
	EXPECT_EQ(mapEntree.size(), mapLu.size());
	EXPECT_TRUE(std::equal(mapEntree.begin(), mapEntree.end, mapLu.begin());
	EXPECT_TRUE(std::equal(mapLu.begin(), mapLu.end, mapEntree.begin());
}

TEST(Read, map_string){
	std::map<std::string, std::string> mapEntree;
	mapEntree["Salut"] = "Bonjour";
	mapEntree["Ca va ?"] = "Imotep";
	mapEntree["Le lion ne s'associe pas avec le cafard"] = "Eh les romains vous êtes des romaines";
	std::map<std::string, std::string> mapLu;
  	{
		serial::OBinaryFile obinary("ficTemplate");
		obinary << mapEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficTemplate");
		ibinary>>mapLu;
	}
	EXPECT_EQ(mapEntree.size(), mapLu.size());
	EXPECT_TRUE(std::equal(mapEntree.begin(), mapEntree.end, mapLu.begin());
	EXPECT_TRUE(std::equal(mapLu.begin(), mapLu.end, mapEntree.begin());
}

TEST(Read, map_char){
	std::map<char, char> mapEntree;
	mapEntree['4'] = '2';
	mapEntree['S'] = 's';
	mapEntree['-'] = 'é';
	std::map<char, char> mapLu;
  	{
		serial::OBinaryFile obinary("ficTemplate");
		obinary << mapEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficTemplate");
		ibinary>>mapLu;
	}
	EXPECT_EQ(mapEntree.size(), mapLu.size());
	EXPECT_TRUE(std::equal(mapEntree.begin(), mapEntree.end, mapLu.begin());
	EXPECT_TRUE(std::equal(mapLu.begin(), mapLu.end, mapEntree.begin());
}

TEST(Read, map_bool){
	std::map<bool, bool> mapEntree;
	mapEntree[false] = true;
	mapEntree[true] = true;
	mapEntree[false] = true;
	std::map<bool, bool> mapLu;
  	{
		serial::OBinaryFile obinary("ficTemplate");
		obinary << mapEntree;
 	}
	{
		serial::IBinaryFile ibinary("ficTemplate");
		ibinary>>mapLu;
	}
	EXPECT_EQ(mapEntree.size(), mapLu.size());
	EXPECT_TRUE(std::equal(mapEntree.begin(), mapEntree.end, mapLu.begin());
	EXPECT_TRUE(std::equal(mapLu.begin(), mapLu.end, mapEntree.begin());
}


int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
