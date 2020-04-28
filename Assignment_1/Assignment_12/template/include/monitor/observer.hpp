#pragma once
template <class E>
class Observer
{
public:
    void update(E event)
    {
        /* This is where C++ gets a bit nasty
        * its not possible to have a virtual template method
        */
        do_update(&event);
    }

private:
    virtual void do_update(void *event) = 0;
};
