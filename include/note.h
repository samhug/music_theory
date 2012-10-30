#ifndef NOTE_H
#define NOTE_H

#include "theory.h"

/**
 * This class represents a musical note
 */
class Note
{
public:
    Note(note_t n);
    Note(note_t octave, note_t n);

    virtual ~Note();

    string name() const;

    note_t octave() const;
    note_t note() const;

    void octave(note_t val);
    void note(note_t val);

    note_t midi_note() const;

    bool operator == (const Note& s) const;

private:
    note_t _octave;
    note_t _note;

public:
    /** Constructs a Note object from a MIDI note number */
    static Note from_midi_note(note_t n)
    {
        Note note(n+3);
        return note;
    };
};

std::ostream& operator<<(std::ostream& os, const Note& note);
#endif
