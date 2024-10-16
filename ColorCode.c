#include "ColorCode.h"
#include <assert.h>
#include <string.h>

const char* MajorColorNames[] = {
    "White", "Red", "Black", "Yellow", "Violet"
};

const char* MinorColorNames[] = {
    "Blue", "Orange", "Green", "Brown", "Slate"
};

const int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);
const int MAX_COLORPAIR_NAME_CHARS = 16;

void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    sprintf(buffer, "%s %s",
        MajorColorNames[colorPair->majorColor],
        MinorColorNames[colorPair->minorColor]);
}

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor = (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

int GetPairNumberFromColor(const ColorPair* colorPair) {
    return colorPair->majorColor * numberOfMinorColors + colorPair->minorColor + 1;
}

void PrintColorReferenceManual() {
    printf("Color Pair Reference Manual:\n");
    for (int major = 0; major < 5; ++major) {
        for (int minor = 0; minor < 5; ++minor) {
            ColorPair colorPair = { (enum MajorColor)major, (enum MinorColor)minor };
            char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
            ColorPairToString(&colorPair, colorPairNames);
            printf("Pair Number %d: %s\n", GetPairNumberFromColor(&colorPair), colorPairNames);
        }
    }
}
