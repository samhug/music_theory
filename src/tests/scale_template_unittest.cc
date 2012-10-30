#include <gtest/gtest.h>

#include "scale_template.h"

TEST(ScaleTemplate, name) {
    note_pattern_t pattern ({0, 1, 2, 3, 4, 5, 6});
    ScaleTemplate scale_tmpl("major",  pattern);

    EXPECT_STREQ("major", scale_tmpl.name().c_str());
}


TEST(ScaleTemplate, transpose) {

    note_pattern_t pattern ({0, 2, 4, 5, 7, 9, 11});
    ScaleTemplate scale_tmpl("Major",  pattern);


    note_pattern_t p2 ({1, 3, 5, 6, 8, 10, 0});
    EXPECT_EQ(p2, scale_tmpl.transpose(1));

    note_pattern_t p3 ({2, 4, 6, 7, 9, 11, 1});
    EXPECT_EQ(p3, scale_tmpl.transpose(2));

    note_pattern_t p4 ({10, 0, 2, 3, 5, 7, 9});
    EXPECT_EQ(p4, scale_tmpl.transpose(-2));
}
