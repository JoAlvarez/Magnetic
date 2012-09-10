#ifndef  __PLAYER_H__
#define  __PLAYER_H__

#include "timer.h"
#include "input.h"
#include "ball.h"

class Player
{
    private:
        Ball*       ball;
        double      score;
        int         souls;
        Input*      input;
        Timer*      times;
        Polarity    p;

    public:
        Player();
        void        checkInput();
        void        startTimer();
        void        stopTimer();
        double      getScore();
        Polarity    getPolarity();
        int         getLives();
        void        setPlayerBall( Ball* b );
        Ball*       getBall();
        ~Player();
};

#endif __PLAYER_H__
