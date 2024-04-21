#include "gtest/gtest.h"
#include "Marfa.h"
#include "Catalog_online.h"
#include "Termometru.h"
#include "Termometru_alcool_lemn.h"
#include "Termometru_electric.h"

TEST(MarfaTest, ConstructorTest) {
    Marfa marfa("TestMedicine", 50);
    // Add assertions to test the constructor behavior
    EXPECT_EQ(marfa.medicine(), "TestMedicine");
    EXPECT_EQ(marfa.price(), 50);
}

TEST(MarfaTest, DestructorTest) {
    Marfa* marfaPtr = new Marfa("TestMedicine", 50);
    EXPECT_NO_THROW(delete marfaPtr);
}




TEST(CatalogOnlineTest, ConstructorTest) {
    Catalog_online catalog("TestName", "TestAddress");
    // Add assertions to test the constructor behavior
    EXPECT_EQ(catalog.nom(), "TestName");
    EXPECT_EQ(catalog.adr(), "TestAddress");
}

TEST(CatalogOnlineTest, DestructorTest) {
    Catalog_online* catalogPtr = new Catalog_online("TestName", "TestAddress");
    EXPECT_NO_THROW(delete catalogPtr);
}

TEST(TermometruElectricTest, ConstructorTest) {
    Termometru_electric termometru("TestFirma", 100, 200);
    // Add assertions to test the constructor behavior
    EXPECT_EQ(termometru.getFirma(), "TestFirma");
    EXPECT_EQ(termometru.getPret(), 100);
    EXPECT_EQ(termometru.cap(), 200);
}

TEST(TermometruElectricTest, DestructorTest) {
    Termometru_electric* termometruPtr = new Termometru_electric("TestFirma", 100, 200);
    EXPECT_NO_THROW(delete termometruPtr);
}



TEST(MarfaTest, MedicineFunctionTest) {
    Marfa marfa("TestMedicine", 50);
    EXPECT_EQ(marfa.medicine(), "TestMedicine");
}

TEST(MarfaTest, PriceFunctionTest) {
    Marfa marfa("TestMedicine", 50);
    EXPECT_EQ(marfa.price(), 50);
}

TEST(CatalogOnlineTest, AdaugareMedicamenteFunctionTest) {
    Catalog_online catalog;
    Marfa marfa("TestMedicine", 50);
    catalog.adaugare_medicamente(marfa);
    EXPECT_EQ(catalog.nr_medicamente(), 1);
}

TEST(TermometruElectricTest, TempMaxFunctionTest) {
    Termometru_electric termometru("TestFirma", 100, 200);
    // Redirect cout to a stringstream to capture output
    std::stringstream ss;
    std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
    termometru.temp_max();
    std::cout.rdbuf(old_cout); // Restore cout
    // Test if the output matches the expected value
    EXPECT_EQ(ss.str(), "Temperatura maxima a termometrului electric TestFirma este de 100 de grade");
}

