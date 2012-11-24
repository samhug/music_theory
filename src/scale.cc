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

#include <algorithm>

#include "theory/scale.h"

/**
 * Constructs a Scale object using the given tonic and scale template.
 *
 * @param[in]  tonic   The tonic offset of the scale. (ex. 3 = C-scale)
 * @param[in]  tmpl    The scale template to use for the scale.
 */
Scale::Scale(note_t tonic, const ScaleTemplate *tmpl)
{
    assert(tonic < 12); // tonic offset must be between 0-11 inclusive

    this->_tonic = tonic;
    this->tmpl = tmpl;

    this->pattern = tmpl->transpose(tonic); 

    this->_name = NOTE_SYMBOLS[tonic] + tmpl->name();
}

Scale::~Scale() {}

/**
 * Return the name of the scale.
 *
 * @return The name of the scale
 */
string Scale::name() const
{
    return _name;
}

/**
 * Return the tonic offset of the scale.
 *
 * @return The tonic offset
 */
note_t Scale::tonic() const
{
    return _tonic;
}

/**
 * Return the tonic offset of nth pitch in the scale.
 * If n>7 the scale wraps but the offset increaces
 *
 * @param[in]   n   The pitch number
 * @return The tonic offset
 */
int Scale::pitch_offset(int n) const
{
    return (n/7*12) + (12 + this->pattern.at(n % 7) - this->tonic()) % 12;
}

/**
 * Finds the given pitch in the scale.
 *
 * @param[in]   pitch   The pitch to find
 * @return The pitch index in our scale if it exists. Otherwise it returns a NULL value.
 */
size_t Scale::pitch_index(note_t pitch) const
{
    size_t i = distance(this->pattern.begin(), find(this->pattern.begin(), this->pattern.end(), pitch));

    // If the pitch isn't in the scale
    if (i == this->pattern.size()) {
        throw new string ("Pitch not found");
        //TODO: Do I really want to use exceptions?
    }

    return i;
}

/**
 * Helper function to finds the given pitch in the scale.
 *
 * @param[in]   note   The note to find
 * @return The zero-based index of the pitch in our scale if it exists. Otherwise it returns a NULL value.
 */
/*
size_t Scale::pitch_index(Note note) const
{
    return pitch_index(note.pitch());
}
*/

/**
 * Calculates the given interval on the scale starting at the given note.
 *
 * @param[in]   note    The note the interval should start on
 * @param[in]   size The size of the interval
 * @return A Note object representing the note on the end of the interval
 */
Note Scale::interval(Note note, int size) const
{
    // The zero-indexed degree of the pitch on the scale
    int s_deg = this->pitch_index(note.pitch());

    int pitch_delta = this->pitch_offset(s_deg + size) - this->pitch_offset(s_deg);


    // The new note's pitch
    note_t e_pitch = (note.pitch() + pitch_delta) % 12;

    int octave_delta = (note.pitch() + pitch_delta) / 12;

    Note new_note(note.octave() + octave_delta, e_pitch);

    return new_note;
}
