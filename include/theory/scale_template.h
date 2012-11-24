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

#ifndef SCALE_TEMPLATE_H
#define SCALE_TEMPLATE_H

#include "helpers.h"

/**
 * This class represents a scale template for a musical scale.
 * (e.g The `major` and `minor` scale templates would be used for the Cmajor
 * and Cminor scales respectivly)
 */
class ScaleTemplate
{
public:

    ScaleTemplate();
    ScaleTemplate(string name, note_pattern_t pattern);
    virtual ~ScaleTemplate();

    string name() const;

    note_pattern_t transpose(int n_semitones) const;

private:
    string _name;

    note_pattern_t pattern;

public:
    /**
     * Returns a ScaleTemplate object corresponding to the given name.
     *
     * @param[in]   name    The name of the template pattern
     * @return A ScaleTemplate object
     */
    static const ScaleTemplate from_name(string name)
    {
        /*
        vector<ScaleTemplate>::const_iterator it;
        it = find_if(SCALE_TEMPLATES.begin(), SCALE_TEMPLATES.end(),
                [name](ScaleTemplate tmpl){ return tmpl.name() == name; });
        */
        SCALE_TEMPLATES_t::const_iterator it = SCALE_TEMPLATES.find(name.c_str());

        if (it != SCALE_TEMPLATES.end()) {
            ScaleTemplate scale_template(it->first, it->second);
            return scale_template;
        } else {
            throw (new string("No ScaleTemplate with name matching: "))->append(name);
        }
    }; 
};

#endif
