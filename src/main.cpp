#include <iostream>
// TEST: #include <Chess/Pieces/bishop.hpp>
#include <Chess/game.hpp>

// Tbh, I've never played a real game of chess before, but I *think* I know the basics. In fact I've played, but I've never finished a game of chess.
// I'm pretty much sure that this sh** doesn't cover a lot of edge cases, but I genually don't have any clue what they might be, it works for my simple game, for me against me :0
// It's also my first time using cmake, but it has some cool integration, after you set it up, in VS Code, you literally press one button, plus I'm using clang, making it easier to read the errors, compared to gcc.
// Well, I think, Dennis (ITStep), ofc I used stackoverflow, and I'm happy that I learned what #pragma once is, it's even used in C (much better than #define and #ifdef and so on).
// The board looks nice and it isn't confusing - actulually - rows are x, cols are y, just a note;
// So this thing does indeed work - Checkmate! kk is the winner!, although I'm not sure if it shows the right name, since i've been using only kk's so far
// Also a little disclamer - ofc, I used the internet, because some of the things had no logical explanation in my head, and we helped eachother (with Kristina)
// I haven't tested it for memory leaks, but I'm pretty tired, as well as scared from what I'll see - probably the whole program could be classified as a memory leak, although compared to Windows -> it's still more optimized
// I wonder if anyone's going to read my poem of comments, anyway

// Tech tip: don't make C++ to Pythony - aka removing {} from one-liners, it'll ruin your day - like it did to me (idk why) with the Pawn.cpp file.

int main(){

    Game mainProccess;
    mainProccess.start();

    return 0;
}