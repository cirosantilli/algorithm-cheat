/*
Draw a sprite with alpha transparency on top of a background buffer.

Framebuffer is in RGB565 (R is MSB)

Sprite is RGBA8888 (R is MSB).

Requires careful bit manipulations.
*/

#include <assert.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>

#define FB_WIDTH 640
#define FB_HEIGHT 480

/* Frame buffer. */

typedef uint16_t fbType;

fbType frameBuffer[FB_WIDTH * FB_HEIGHT];

fbType fbGetBits(fbType pixel, fbType first, fbType last) {
    return (pixel >> first) & ~(~0 << (last - first + 1));
}

fbType fbGetR(fbType pixel) {
    return fbGetBits(pixel, 11, 15);
}

fbType fbGetG(fbType pixel) {
    return fbGetBits(pixel, 5, 10);
}

fbType fbGetB(fbType pixel) {
    return fbGetBits(pixel, 0, 4);
}

fbType fbMakePixel(fbType r, fbType g, fbType b) {
    return b + (g << 5) + (r << 11);
}

/* Sprite. */

typedef uint32_t spriteType;

spriteType spriteGetBits(spriteType pixel, spriteType first, spriteType last) {
    return (pixel >> first) & ~(~0 << (last - first + 1));
}

spriteType spriteGetR(spriteType pixel) {
    return spriteGetBits(pixel, 24, 31);
}

spriteType spriteGetG(spriteType pixel) {
    return spriteGetBits(pixel, 16, 23);
}

spriteType spriteGetB(spriteType pixel) {
    return spriteGetBits(pixel, 8, 15);
}

spriteType spriteGetAlpha(spriteType pixel) {
    return spriteGetBits(pixel, 0, 7);
}

spriteType spriteMakePixel(spriteType r, spriteType g, spriteType b, spriteType a) {
    return a + (b << 8) + (g << 16) + (r << 24);
}

fbType alphaBlend(fbType fb, spriteType sprite) {
    fbType r, g, b;
    /* TODO can we get away without a double, just integers? */
    double alpha = spriteGetAlpha(sprite) / 255.0;
    double alphaCompl = 1.0 - alpha;
    r = ((8 * fbGetR(fb) * alphaCompl) + (spriteGetR(sprite) * alpha)) / 8;
    g = ((4 * fbGetG(fb) * alphaCompl) + (spriteGetG(sprite) * alpha)) / 4;
    b = ((8 * fbGetB(fb) * alphaCompl) + (spriteGetB(sprite) * alpha)) / 8;
    return fbMakePixel(r, g, b);
}

void DrawSprite(
        fbType *fb,
        size_t fbWidth,
        size_t fbHeight,
        spriteType *sprite,
        size_t spriteX,
        size_t spriteY,
        size_t spriteWidth,
        size_t spriteHeight) {
    size_t x, y, curFbIndex;
    fbType fbPixel;
    spriteType spritePixel;

    for (y = 0; y < spriteY; ++y) {
        for (x = 0; x < spriteX; ++x) {
            curFbIndex = ((spriteY + y) * fbWidth) + (spriteX + x);
            fbPixel = fb[curFbIndex];
            spritePixel = sprite[y * spriteWidth + x];
            fb[curFbIndex] = alphaBlend(fbPixel, spritePixel);
        }
    }
}

int main(void) {

    /* fbGetB */
    assert(fbGetB(0x0000u) == 0x00u);
    assert(fbGetB(0x001Fu) == 0x1Fu);
    assert(fbGetB(0xFF20u) == 0x00u);
    assert(fbGetB(0xFFFFu) == 0x1Fu);

    /* fbGetG */
    assert(fbGetG(0x0000u) == 0x00u);
    assert(fbGetG(0xF81Fu) == 0x00u);
    assert(fbGetG(0x07E0u) == 0x3Fu);
    assert(fbGetG(0xFFFFu) == 0x3Fu);

    /* fbGetR */
    assert(fbGetR(0x0000u) == 0x00u);
    assert(fbGetR(0x07FFu) == 0x00u);
    assert(fbGetR(0xF800u) == 0x1Fu);
    assert(fbGetR(0xFFFFu) == 0x1Fu);

    /* fbMakePixel */
    assert(fbMakePixel(0x1Fu, 0x3Fu, 0x1Fu) == 0xFFFFu);
    assert(fbMakePixel(0x00u, 0x00u, 0x1Fu) == 0x001Fu);
    assert(fbMakePixel(0x00u, 0x3Fu, 0x00u) == 0x07E0u);
    assert(fbMakePixel(0x1Fu, 0x00u, 0x00u) == 0xF800u);

    /* spriteMakePixel */
    assert(spriteMakePixel(0xFFu, 0x00u, 0x00u, 0x00u) == 0xFF000000u);
    assert(spriteMakePixel(0x00u, 0xFFu, 0x00u, 0x00u) == 0x00FF0000u);
    assert(spriteMakePixel(0x00u, 0x00u, 0xFFu, 0x00u) == 0x0000FF00u);
    assert(spriteMakePixel(0x00u, 0x00u, 0x00u, 0xFFu) == 0x000000FFu);

    /* alphaBlend */
    assert(
        alphaBlend(
            fbMakePixel(   0x00u, 0x00u, 0x00u),
            spriteMakePixel(0xFFu, 0xFFu, 0xFFu, 0x00u)
        ) == 0x0000u
    );
    assert(
        alphaBlend(
            fbMakePixel(   0x00u, 0x00u, 0x00u),
            spriteMakePixel(0xFFu, 0xFFu, 0xFFu, 0xFFu)
        ) == 0xFFFFu
    );
    assert(
        alphaBlend(
            fbMakePixel(   0x1Fu, 0x3Fu, 0x1Fu),
            spriteMakePixel(0x00u, 0x00u, 0x00u, 0xFFu)
        ) == 0x0000u
    );
    assert(
        alphaBlend(
            fbMakePixel(   0x1Fu, 0x3Fu, 0x1Fu),
            spriteMakePixel(0x00u, 0x00u, 0x00u, 0x00u)
        ) == 0xFFFFu
    );

    /* Half transparent. */
    /* TODO failing. */
    printf(
        "%x\n%x\n%x\n%x\n",
        fbMakePixel(   0x00u, 0x00u, 0x00u),
        spriteMakePixel(0x00u, 0x00u, 0xFFu, 0x7Fu),
        fbMakePixel(   0x0Fu, 0x00u, 0x0Fu),
        alphaBlend(
            fbMakePixel(   0x00u, 0x00u, 0x00u),
            spriteMakePixel(0x00u, 0x00u, 0xFFu, 0x7Fu)
        )
    );
    /*
    assert(
        alphaBlend(
            fbMakePixel(   0x00u, 0x00u, 0x00u),
            spriteMakePixel(0x00u, 0x00u, 0xFFu, 0x7Fu)
        ) == fbMakePixel(  0x0Fu, 0x00u, 0x0Fu)
    );
    */

    return EXIT_SUCCESS;
}
