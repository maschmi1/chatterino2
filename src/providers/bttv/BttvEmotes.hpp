#pragma once

#include <memory>
#include "common/Atomic.hpp"
#include "messages/Emote.hpp"

namespace chatterino {

class BttvEmotes final
{
    static constexpr const char *globalEmoteApiUrl =
        "https://api.betterttv.net/2/emotes";

public:
    BttvEmotes();

    std::shared_ptr<const EmoteMap> global() const;
    boost::optional<EmotePtr> global(const EmoteName &name) const;
    void loadGlobal();

private:
    Atomic<std::shared_ptr<const EmoteMap>> global_;
};

}  // namespace chatterino
