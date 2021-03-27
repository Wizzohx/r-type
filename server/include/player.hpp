/*
** EPITECH PROJECT, 2020
** r-type
** File description:
** player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

class Iplayer {
    public:
        virtual void kill_player() = 0;
        
        virtual void setx(float temp) = 0;
        virtual float getx() = 0;
        virtual void sety(float temp) = 0;
        virtual float gety() = 0;
        virtual void setbx(float temp) = 0;
        virtual float getbx() = 0;
        virtual void setby(float temp) = 0;
        virtual float getby() = 0;
        virtual void setisshooted(bool temp) = 0;
        virtual bool getisshooted() = 0;
    protected:
        float x;
        float y;
        float bx;
        float by;
        bool isshooted;
};

class player : public Iplayer {
    public:
        player();
        ~player();

        void kill_player();
        void shoot();
        void destroy_shoot();

        void setx(float temp);
        float getx();
        void sety(float temp);
        float gety();
        void setbx(float temp);
        float getbx();
        void setby(float temp);
        float getby();
        void setisshooted(bool temp);
        bool getisshooted();
};

#endif /* !PLAYER_HPP_ */
