#include "freetype/FreeTypeLib.hpp"

FreeTypeLib::FreeTypeLib() {
    if (FT_Init_FreeType(&lib)) {
        throw std::runtime_error("error");
    }
}

FreeTypeLib::~FreeTypeLib(){
    FT_Done_FreeType(lib);
}


FreeTypeLib& FreeTypeLib::getinstance(){
    static FreeTypeLib instance;
    return instance;
}

FT_Library FreeTypeLib::getLibrary() const{
    return lib;
}