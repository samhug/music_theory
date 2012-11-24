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

#ifndef SCALE_H
#define SCALE_H

#include <stdexcept>

#include "helpers.h"
#include "scale_template.h"
#include "note.h"

/**
 * This class represents a musical scale with a tonic offset and a scale template.
 */
class Scale
{
public:
    Scale(note_t tonic, const ScaleTemplate *tmpl);
    virtual ~Scale();

    string name() const;
    note_t tonic() const;

    /** The ScaleTemplate to use for the Scale */
    const ScaleTemplate *tmpl;

    int pitch_offset(int n) const;

    size_t pitch_index(note_t pitch) const;
    //size_t pitch_index(Note note) const;

    Note interval(Note note, int size) const;

private:
    string _name;
    note_t _tonic;

    note_pattern_t pattern;

public:
    /**
     * Factory to construct a Scale object for the specified key.
     *
     * @param[in]   key The name of the key
     * @return A Scale object to represent the given key
     */
    static Scale from_key(string key)
    {

        string tonic_name;
        string pattern_name;
        if (!parse_key_name(key, &tonic_name, &pattern_name)) {
            throw runtime_error("Unrecognized key name");
        }

        // Retrieve the note index of the matched note symbol
        note_t tonic = distance(NOTE_SYMBOLS.begin(), find(NOTE_SYMBOLS.begin(), NOTE_SYMBOLS.end(), tonic_name));

        // Find a scale template with a matching name
        ScaleTemplate tmpl = ScaleTemplate::from_name(pattern_name);

        Scale scale(tonic, &tmpl);
        return scale;
    }
};

#endif
