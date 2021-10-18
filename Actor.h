#ifndef ACTOR_H_
#define ACTOR_H_

#include <iostream>

class Actor
{
    private:
        std::string name;
        mutable std::string role;
    public:
        Actor() : name("n/a"), role("n/a") { }
        Actor(const std::string n, const std::string r) : name(n), role(r) { }

        std::string getName() const;
        std::string getRole() const;

        void setName(const std::string name);
        void setRole(const std::string role) const;

        std::string show() const;

        friend std::ostream& operator << (std::ostream& out, Actor& actor);
};

#endif

