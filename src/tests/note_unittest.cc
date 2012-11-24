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

#include "theory/note.h"

TEST(Note, Initialization) {
    Note note(3, 5);

    EXPECT_EQ(3, note.octave());
    EXPECT_EQ(5, note.pitch());
}

TEST(Note, comparison_operator) {
    Note note1(3, 5);
    Note note2(3, 5);
    Note note3(4, 5);
    Note note4(3, 6);

    EXPECT_TRUE(note1 == note2);
    EXPECT_FALSE(note1 == note3);
    EXPECT_FALSE(note1 == note4);
}

TEST(Note, from_midi_note) {
    Note note = Note::from_midi_note(2*12 + 6 -3);

    EXPECT_EQ(2, note.octave());
    EXPECT_EQ(6, note.pitch());
}

TEST(Note, from_frequency) {
    EXPECT_EQ(Note::from_frequency(220), Note::from_midi_note(57));
    EXPECT_EQ(Note::from_frequency(440), Note::from_midi_note(69));
    EXPECT_EQ(Note::from_frequency(880), Note::from_midi_note(81));
}

TEST(Note, octave) {
    Note note(0, 0);
    
    note.octave(4);

    EXPECT_EQ(4, note.octave());
}

TEST(Note, pitch) {
    Note note(0, 0);
    
    note.pitch(6);

    EXPECT_EQ(6, note.pitch());
}

TEST(Note, freq) {
    Note n1 = Note::from_frequency(220.0);
    EXPECT_DOUBLE_EQ(220, n1.freq());

    Note n2 = Note::from_frequency(440.0);
    EXPECT_DOUBLE_EQ(440, n2.freq());

    Note n3 = Note::from_frequency(880.0);
    EXPECT_DOUBLE_EQ(880, n3.freq());
}

TEST(Note, midi_note) {
    Note note = Note::from_midi_note(52);

    EXPECT_EQ(52, note.midi_note());
}
