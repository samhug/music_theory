#ifndef NOTE_H
#define NOTE_H

#include <cmath>

#include "helpers.h"

#define A4_MIDI_NUM 69
#define A4_FREQ     440.0

// 2^(1/12) Rounded to 64 bits
#define TWELFTH_ROOT_OF_2 1.05946309435929526

/**
 * This class represents a musical note
 */
class Note
{
public:
    Note(note_t n);
    Note(note_t octave, note_t pitch);

    virtual ~Note();

    string name() const;

    note_t octave() const;
    note_t pitch() const;

    void octave(note_t val);
    void pitch(note_t pitch);

    note_t midi_note() const;
    double freq() const;

    bool operator == (const Note& s) const;

private:
    note_t _octave;
    note_t _pitch;

public:
    /** Constructs a Note object from a MIDI note number */
    static Note from_midi_note(note_t n)
    {
        Note note(n+3);
        return note;
    };

    /**
     * Constructs a Note object from a frequency
     * See: http://en.wikipedia.org/wiki/Piano_key_frequencies
     */
    static Note from_frequency(double d)
    {
        double n = 12. * log2(d/A4_FREQ) + A4_MIDI_NUM;
        return Note::from_midi_note(static_cast<int>(round(n)));
    };
};

std::ostream& operator<<(std::ostream& os, const Note& note);
#endif
