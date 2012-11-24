/*
 * Copyright (C) 2012  Samuel Hug
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <gtest/gtest.h>

#include "theory/scale_template.h"

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
