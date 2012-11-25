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

#include "theory/helpers.h"

TEST(parse_key, basic_test) {
    string tonic;
    string tmpl;
    
    ASSERT_TRUE(parse_key_name("Cmajor", &tonic, &tmpl));
    EXPECT_STREQ("C", tonic.c_str());
    EXPECT_STREQ("major", tmpl.c_str());

    ASSERT_TRUE(parse_key_name("Eminor", &tonic, &tmpl));
    EXPECT_STREQ("E", tonic.c_str());
    EXPECT_STREQ("minor", tmpl.c_str());
}
