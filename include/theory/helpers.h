#ifndef HELPERS_H
#define HELPERS_H

#include <vector>
#include <map>
#include <initializer_list>

#include <boost/regex.hpp>

using namespace std;
using namespace boost;

typedef unsigned int note_t;
typedef vector<note_t> note_pattern_t;

typedef const vector<string> NOTE_SYMBOLS_t;
static NOTE_SYMBOLS_t NOTE_SYMBOLS = {
        "A",  "Bb", "B",  "C",
        "C#", "D",  "Eb", "E",
        "F",  "F#", "G",  "Ab",
};

typedef const map<const string, const note_pattern_t> SCALE_TEMPLATES_t;
static SCALE_TEMPLATES_t SCALE_TEMPLATES = {
    {"major", {0,2,4,5,7,9,11}},
    {"minor", {0,2,3,5,7,8,10}},
};


/**
 * Parses a given key name into its tonic and pattern parts.
 *
 * @param[in]   key     The key name to parse.
 * @param[out]  tonic   The parsed tonic name.
 * @param[out]  pattern The parsed pattern name.
 * @return True on success and False on failure.
 */
static bool parse_key_name(string key, string *tonic, string *pattern)
{
    static const boost::regex e("([A-Ga-g][Bb#]?)(major|minor)", boost::regex_constants::icase);

    match_results<string::const_iterator> match;
    if(boost::regex_match(key, match, e)) {

        *tonic = match[1];
        *pattern = match[2];
        
        return true;
    }

    return false;
}

#endif /* HELPERS_H */
