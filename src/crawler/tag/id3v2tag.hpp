#ifndef COQUILLO_CRAWLER_TAG_ID3V2TAG_H
#define COQUILLO_CRAWLER_TAG_ID3V2TAG_H

#include <QVariantHash>
#include "generic.hpp"

namespace TagLib {
    namespace ID3v2 {
        class Tag;
    }
}

namespace Coquillo {
    namespace Crawler {
        namespace Tag {
            class Id3v2Tag : public Generic {
                public:
                    QVariantHash read(const TagLib::ID3v2::Tag * tag) const;
                    void write(TagLib::ID3v2::Tag * tag, const QVariantHash & values);
            };
        }
    }
}
#endif
