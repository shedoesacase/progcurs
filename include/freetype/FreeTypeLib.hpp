#pragma once
#include <stdexcept>
#include <freetype2/ft2build.h>
#include FT_FREETYPE_H

class FreeTypeLib{
    private:
        FT_Library lib;
        FreeTypeLib();
        ~FreeTypeLib();
    public:
        FreeTypeLib(const FreeTypeLib&) = delete;
        FreeTypeLib& operator=(const FreeTypeLib&) = delete;

        static FreeTypeLib& getinstance();
        FT_Library getLibrary() const;
};