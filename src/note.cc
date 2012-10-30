#include <sstream> // for Note::name()

#include "note.h"

/**
 * Constructor for the Note class
 *
 * @param[in]   n   The unwraped note number (e.g [octave_n]*12 + [note_n])
 */
Note::Note(note_t n)
{
    this->_octave = n / 12;
    this->_note = n % 12;
}

/**
 * Overloaded constructor to initialize the Note class using an octave and a
 * note number.
 *
 * @param[in]   octave   The octave number
 * @param[in]   n        The wraped note number
 */
Note::Note(note_t octave, note_t n)
{
    this->_octave = octave;
    this->_note = n;
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
    out << NOTE_SYMBOLS[_note] << _octave;
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
 * Returns the note number within the octave (will be between 0-7 inclusive)
 *
 * @return The note nuber
 */
note_t Note::note() const
{
    return this->_note;
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
 * Sets the note
 *
 * @param[in]   val The note number
 */
void Note::note(note_t val)
{
    this->_note = val;
}

/**
 * Returns the MIDI note number coresponding to this object
 * 
 * @return A MIDI note number
 */
note_t Note::midi_note() const
{
    return (this->octave() * 12) + this->_note - 3;
}

/**
 * Compares two Note objects
 *
 * @param[in]   s   The Note object to compare too
 * @return true if they are equal otherwise, false.
 */
bool Note::operator == (const Note& s) const
{
    return (note() == s.note() && octave() == s.octave());
}

#include <iostream>
/**
 * Stream operator for Google Test object formating
 */
std::ostream& operator<<(std::ostream& os, const Note& note)
{
    return os << "Note[ octave=" << note.octave() << ", note=" << note.note() << " ]";
}
