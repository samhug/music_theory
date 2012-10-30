#include <gtest/gtest.h>

#include "note.h"

TEST(Note, Initialization) {
    Note note(3, 5);

    EXPECT_EQ(3, note.octave());
    EXPECT_EQ(5, note.note());
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
    EXPECT_EQ(6, note.note());
}

TEST(Note, octave) {
    Note note(0, 0);
    
    note.octave(4);

    EXPECT_EQ(4, note.octave());
}

TEST(Note, note) {
    Note note(0, 0);
    
    note.note(6);

    EXPECT_EQ(6, note.note());
}

TEST(Note, midi_note) {
    Note note = Note::from_midi_note(52);

    EXPECT_EQ(52, note.midi_note());
}
