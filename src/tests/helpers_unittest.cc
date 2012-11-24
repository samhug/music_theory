#include <gtest/gtest.h>

#include "theory/helpers.h"

TEST(parse_key, basic_test) {
    string tonic;
    string tmpl;
    
    ASSERT_TRUE(parse_key_name("Cmajor", &tonic, &tmpl));
    EXPECT_EQ("C", tonic);
    EXPECT_EQ("major", tmpl);

    ASSERT_TRUE(parse_key_name("Eminor", &tonic, &tmpl));
    EXPECT_EQ("E", tonic);
    EXPECT_EQ("minor", tmpl);
}
