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

#include <sstream> // for Note::name()

#include "theory/note.h"

/**
 * Constructor for the Note class
 *
 * @param[in]   n   The unwraped note number (e.g [octave_n]*12 + [pitch_n])
 */
Note::Note(note_t n)
{
    this->_octave = n / 12;
    this->_pitch = n % 12;
}

/**
 * Overloaded constructor to initialize the Note class using an octave and a
 * pitch number.
 *
 * @param[in]   octave   The octave number
 * @param[in]   pitch    The pitch number
 */
Note::Note(note_t octave, note_t pitch)
{
    this->_octave = octave;
    this->_pitch = pitch;
}

/** Deconstructor */
Note::~Note() {}

/**
 * Returns the name of the note ex. "C#5"
 *
 * @return The name of the note
 */
string Note::name() const
{
    std::stringstream out;
    out << NOTE_SYMBOLS[_pitch] << _octave;
    return out.str();
}

/**
 * Returns the octave number
 *
 * @return The octave number of the note
 */
note_t Note::octave() const
{
    return this->_octave;
}

/**
 * Returns the pitch number (will be between 0-7 inclusive)
 *
 * @return The pitch nuber
 */
note_t Note::pitch() const
{
    return this->_pitch;
}

/**
 * Sets the octave
 *
 * @param[in]   val The octave number
 */
void Note::octave(note_t val)
{
    this->_octave = val;
}

/**
 * Sets the pitch
 *
 * @param[in]   pitch The pitch number
 */
void Note::pitch(note_t pitch)
{
    this->_pitch = pitch;
}

/**
 * Returns the MIDI note number coresponding to this object
 * 
 * @return A MIDI note number
 */
note_t Note::midi_note() const
{
    return (this->octave() * 12) + this->_pitch - 3;
}

/**
 * Returns the frequency coresponding to this note
 * See: http://en.wikipedia.org/wiki/Piano_key_frequencies
 *
 * @return A frequency
 */
double Note::freq() const
{
    /* The frequency of the note A4 is 440Hz. Each note is separated by a factor of 2^(1/12). */
    return pow(TWELFTH_ROOT_OF_2, static_cast<int>(this->midi_note()) - A4_MIDI_NUM) * A4_FREQ;
}

/**
 * Compares two Note objects
 *
 * @param[in]   s   The Note object to compare too
 * @return true if they are equal otherwise, false.
 */
bool Note::operator == (const Note& s) const
{
    return (pitch() == s.pitch() && octave() == s.octave());
}

#include <iostream>
/**
 * Stream operator for Google Test object formating
 */
std::ostream& operator<<(std::ostream& os, const Note& note)
{
    return os << "Note[ octave=" << note.octave() << ", pitch=" << note.pitch() << " ]";
}
