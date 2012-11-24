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

#include "theory/scale_template.h"

ScaleTemplate::ScaleTemplate()
{
}

/**
 * Constructs a ScaleTemplate using the given name and pattern
 * 
 * @param[in]   name    The name of the scale template
 * @param[in]   pattern The pattern for the template
 */
ScaleTemplate::ScaleTemplate(string name, note_pattern_t pattern)
{
    this->_name = name;
    this->pattern = pattern;
}

ScaleTemplate::~ScaleTemplate() {}

/**
 * Returns the name of the ScaleTemplate ex. "major", "minor"
 *
 * @return The name of the ScaleTemplate
 */
string ScaleTemplate::name() const
{
    return _name;
}

/**
 * Transpose the scale pattern n_semitones for different keys
 *
 * @param[in] n_semitones   The number of semitones to shift the pattern
 * @return The pattern shifted by n_semitones
 */
note_pattern_t ScaleTemplate::transpose(int n_semitones) const
{
    // Wrap between 0 and 11 inclusive
    n_semitones = (n_semitones + 12) % 12;

    // Copy the template pattern
    note_pattern_t new_pattern(this->pattern);

    for (note_pattern_t::iterator it=new_pattern.begin(); it < new_pattern.end(); it++) {
        *it = ((*it) + n_semitones) % 12;
    }

    return new_pattern;
}
