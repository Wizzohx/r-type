/*
** EPITECH PROJECT, 2020
** B-CPP-501-NCY-5-1-rtype-antoine.mathis-main
** File description:
** ennemy
*/

#ifndef ENNEMY_HPP_
#define ENNEMY_HPP_

class Iennemy {
    public:
        virtual void setx2(float temp) = 0;
        virtual float getx2() = 0;
        virtual void sety2(float temp) = 0;
        virtual float gety2() = 0;
        virtual void setused2(bool temp) = 0;
        virtual bool getused2() = 0;
    protected:
        float x;
        float y;
        bool used;
};

class ennemy : public Iennemy {
    public:
        ennemy();
        ~ennemy();

        void setx2(float temp);
        float getx2();
        void sety2(float temp);
        float gety2();
        void setused2(bool temp);
        bool getused2();

        void create_ennemy();
        void kill_ennemy();
};

#endif /* !ENNEMY_HPP_ */