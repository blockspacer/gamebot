#ifndef MESSAGES_HPP
#define MESSAGES_HPP

#include "config.hpp"
#include "parse.hpp"
#include <string>
#include <vector>

namespace qb::messages
{
inline std::string queue_start(const std::vector<std::string>& cmd)
{
    if (cmd.empty()) return "Not queuing for any games, eh?";
    return "Queuing for games: " + qb::parse::concatenate_quoted(cmd) + "! Reacting does nothing!";
}

inline std::string cannot_store(const std::vector<std::string>& ignored)
{
    return "Error: Cannot store more than " + qb::config::max_skribble_wordsize_s +
           " characters in a single word. The following words were not saved: " +
           qb::parse::concatenate_quoted(ignored);
}

inline std::string did_store(const std::vector<std::string>& ignored)
{
    return "Stored the following words for Skribbl: " + qb::parse::concatenate_quoted(ignored);
}

inline std::string did_store(const std::vector<std::string>& ignored, const std::string& loc)
{
    return "Stored the following words for Skribbl to the group '" + loc +
           "': " + qb::parse::concatenate_quoted(ignored);
}

// const std::string online{"Of course I'm online. 100% uptime, my friend. 100% uptime."};
std::string online();
const std::string help{
    "Storing command is \"!qb s\" followed by each word (or phrase), separated by commas."};
} // namespace qb::messages

#endif // MESSAGES_HPP
