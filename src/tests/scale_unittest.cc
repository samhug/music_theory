#include <gtest/gtest.h>

#include "scale.h"

/**
 * Test that the initialization of Scale works as expected
 */
TEST(Scale, MainTest) {
    ScaleTemplate tmpl = ScaleTemplate::from_name("major");
    Scale scale(3, &tmpl);

    EXPECT_EQ("Cmajor", scale.name());

    // The first note in the scale should be a C
    EXPECT_EQ(3, scale.tonic());
}


/**
 * Test factory initialization with a key name
 */
TEST(Scale, from_key) {
    Scale scale = Scale::from_key("Cmajor");

    EXPECT_EQ("Cmajor", scale.name());

    // The first note in the scale should be a C
    EXPECT_EQ(3, scale.tonic());

}


/**
 * Test retrieving the tonic offset of the nth note in a scale
 */
TEST(Scale, note_offset) {
    Scale scale = Scale::from_key("Cmajor");

    EXPECT_EQ(0, scale.note_offset(0));
    EXPECT_EQ(2, scale.note_offset(1));
    EXPECT_EQ(4, scale.note_offset(2));
    EXPECT_EQ(5, scale.note_offset(3));
    EXPECT_EQ(7, scale.note_offset(4));
    EXPECT_EQ(9, scale.note_offset(5));
    EXPECT_EQ(11, scale.note_offset(6));
}

/**
 * Test retrieving the tonic offset when the note index is in a different octave
 */
TEST(Scale, note_offset_OCTAVE_SPAN) {
    Scale scale = Scale::from_key("Cmajor");

    EXPECT_EQ(12, scale.note_offset(7));
    EXPECT_EQ(14, scale.note_offset(8));
    EXPECT_EQ(16, scale.note_offset(9));
    EXPECT_EQ(17, scale.note_offset(10));
    EXPECT_EQ(19, scale.note_offset(11));
}

/**
 * Test retrieving the tonic offset when the note index is negative
 */
/*
TEST(Scale, note_offset_NEGATIVE) {
    Scale scale = Scale::from_key("Cmajor");

    EXPECT_EQ(-1, scale.note_offset(-1));
    EXPECT_EQ(-3, scale.note_offset(-2));
    EXPECT_EQ(-5, scale.note_offset(-3));
    EXPECT_EQ(-7, scale.note_offset(-4));
    EXPECT_EQ(-8, scale.note_offset(-5));
    EXPECT_EQ(-10, scale.note_offset(-6));
    EXPECT_EQ(-12, scale.note_offset(-7));
}
*/

TEST(Scale, note_index) {
    Scale scale = Scale::from_key("Cmajor");

    EXPECT_EQ(0, scale.note_index(3));
    EXPECT_EQ(1, scale.note_index(5));
    EXPECT_EQ(2, scale.note_index(7));
    EXPECT_EQ(3, scale.note_index(8));
    EXPECT_EQ(4, scale.note_index(10));
    EXPECT_EQ(5, scale.note_index(0));
    EXPECT_EQ(6, scale.note_index(2));

    //EXPECT_THROW(scale.note_index(1), );

}

TEST(Scale, interval) {
    Scale scale = Scale::from_key("Cmajor");

    Note n1(4, 3);
    Note n2(5, 0);
    EXPECT_EQ(n2, scale.interval(n1, 5));

    Note n3(4, 5);
    Note n4(5, 2);
    EXPECT_EQ(n4, scale.interval(n3, 5));

    Note n5(4, 7);
    Note n6(5, 3);
    EXPECT_EQ(n6, scale.interval(n5, 5));

    Note n7(4, 8);
    Note n8(5, 5);
    EXPECT_EQ(n8, scale.interval(n7, 5));

    Note n9(4, 10);
    Note n10(5, 7);
    EXPECT_EQ(n10, scale.interval(n9, 5));

    Note n11(5, 0);
    Note n12(5, 8);
    EXPECT_EQ(n12, scale.interval(n11, 5));

    Note n13(5, 2);
    Note n14(5, 10);
    EXPECT_EQ(n14, scale.interval(n13, 5));
}

TEST(Scale, interval_SIZE) {
    Scale scale = Scale::from_key("Cmajor");
    Note note(4, 3);

    Note n1(4, 3);
    EXPECT_EQ(n1, scale.interval(note, 0));

    Note n2(4, 5);
    EXPECT_EQ(n2, scale.interval(note, 1));

    Note n3(4, 7);
    EXPECT_EQ(n3, scale.interval(note, 2));

    Note n4(4, 8);
    EXPECT_EQ(n4, scale.interval(note, 3));

    Note n5(4, 10);
    EXPECT_EQ(n5, scale.interval(note, 4));

    // Octave increments
    Note n6(5, 0);
    EXPECT_EQ(n6, scale.interval(note, 5));

    Note n7(5, 2);
    EXPECT_EQ(n7, scale.interval(note, 6));
}



/*
TEST(Scale, interval_NEGATIVE) {
    Scale scale = Scale::from_key("Cmajor");
    Note note(4, scale.note_offset(0));

    Note n1(4, 2);
    EXPECT_EQ(n1, scale.interval(note, -1));

    Note n2(4, 0);
    EXPECT_EQ(n2, scale.interval(note, -2));

    // Octave decrements
    Note n3(3, 10);
    EXPECT_EQ(n3, scale.interval(note, -3));

    Note n4(3, 8);
    EXPECT_EQ(n4, scale.interval(note, -4));

    Note n5(3, 7);
    EXPECT_EQ(n5, scale.interval(note, -5));

    Note n6(3, 5);
    EXPECT_EQ(n6, scale.interval(note, -6));

    Note n7(3, 3);
    EXPECT_EQ(n7, scale.interval(note, -7));
}*/
