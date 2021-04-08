#include <Arduino.h>
#include "global.h"
#include "success_fail.h"
#define threecables 3
#define second_cable 1
#define third_cable 2
#define fourth_cable 3
#define fifth_cable 4
#define sixth_cable 5
#define FOUR 4
#define TWO 2

void three_cables()

{

    int temp = 0;
    int counter = 0;

    for (int i = 0; i < AMOUNT_OF_CABLES; i++)
    {
        if (cable_color[i] == RED)
        {
            break;
        }

        if (i == (AMOUNT_OF_CABLES - 1))
        {

            for (int j = 0; j < AMOUNT_OF_CABLES; j++)
            {

                if (cable_color[j] != BLACK)
                {

                    if (counter == second_cable)
                    {

                        if (data_in[j] == 1)
                        {
                            success();

                            return;
                        }
                        else
                        {
                            fail();
                            return;
                        }
                    }
                    counter++;
                }
            }
        }
    }
    counter = 0;
    for (int i = 0; i < AMOUNT_OF_CABLES; i++)
    {
        if (cable_color[i] != BLACK)
        {
            if (counter == third_cable)
            {
                if (data_in[i] == 1 && cable_color[i] == WHITE)
                {
                    success();
                    return;
                }
                if (data_in[i] == 0 && cable_color[i] == WHITE)
                {
                    fail();
                    return;
                }
            }

            counter++;
        }
    }
    counter = 0;

    for (int i = 0; i < AMOUNT_OF_CABLES; i++)
    {
        if (cable_color[i] != BLACK)
        {
            if (cable_color[i] == BLUE)
            {
                counter++;
                temp = i;
            }
        }
    }
    if (counter >= second_cable && data_in[temp] == 1)
    {
        success();
        return;
    }
    if (counter >= second_cable && data_in[temp] == 0)
    {
        fail();
        return;
    }

    counter = 0;
    for (int i = 0; i < AMOUNT_OF_CABLES; i++)
    {

        if (counter == third_cable && data_in[i] == 1 && cable_color[i] != BLACK)
        {
            success();
            return;
        }
        if (cable_color[i] != BLACK)
        {
            counter++;
        }
    }
    fail();
    return;
}

void four_cables()
{
    int counter = 0;
    int counter_two = 0;
    int temp = 0;
    int check = 0;

    for (int i = 0; i < AMOUNT_OF_CABLES; i++)
    {
        if (cable_color[i] != BLACK)
        {
            if (cable_color[i] == RED)
            {
                counter++;
                temp = i;
            }
        }
    }
    if (counter > second_cable && data_in[temp] == 1)
    {
        success();
        return;
    }
    if (counter > second_cable && data_in[temp] == 0)
    {
        fail();
        return;
    }
    counter = 0;
    temp = 0;
    check = 0;
    for (int i = 0; i < AMOUNT_OF_CABLES; i++)
    {
        if (cable_color[i] == RED)
        {
            break;
        }
        if (cable_color[i] != BLACK)
        {
            if (check == 0)
            {
                temp = i;
                check = 1;
            }

            if (counter == fourth_cable)
            {
                if (data_in[temp] == 1 && cable_color[i] == YELLOW)
                {
                    success();
                    return;
                }
                if (data_in[temp] == 0 && cable_color[i] == YELLOW)
                {
                    fail();
                    return;
                }
            }

            counter++;
        }
    }
    counter = 0;
    temp = 0;
    check = 0;
    for (int i = 0; i < AMOUNT_OF_CABLES; i++)
    {

        if (cable_color[i] != BLACK)
        {
            if (check == 0)
            {

                temp = i;
                check = 1;
            }
            if (cable_color[i] == BLUE)
            {
                counter++;
            }
        }
    }

    if (counter == 1 && data_in[temp] == 1)
    {
        success();
        return;
    }
    if (counter == 1 && data_in[temp] == 0)
    {
        fail();
        return;
    }
    counter = 0;
    for (int i = 0; i < AMOUNT_OF_CABLES; i++)
    {
        if (cable_color[i] != BLACK)
        {
            counter_two++;
            if (cable_color[i] == YELLOW)
            {
                counter++;
            }

            if (counter > 1 && data_in[i] == 1 && counter_two == FOUR)
            {
                success();
                return;
            }
            if (counter > 1 && data_in[i] == 0 && counter_two == FOUR)
            {
                fail();
                return;
            }
        }
    }
    counter = 0;
    temp = 0;
    for (int i = 0; i < AMOUNT_OF_CABLES; i++)
    {
        if (cable_color[i] != BLACK)
        {

            if (counter == second_cable)
            {
                temp = i;
            }
            if (counter == fourth_cable && data_in[temp] == 1)
            {
                success();
                return;
            }
            if (counter == fourth_cable && data_in[temp] == 0)
            {
                fail();
                return;
            }

            counter++;
        }
    }
    fail();
    return;
}

void five_cables()
{
    int counter = 0;
    int temp = 0;
    int temp_second = 0;
    int check_red = 0;
    int check_yellow = 0;
    int check_purple = 0;
    int check_loop = 0;
    for (int i = 0; i < AMOUNT_OF_CABLES; i++)
    {
        if (cable_color[i] != BLACK)
        {

            if (counter == fourth_cable)
            {
                temp = i;
            }
            if (counter == fifth_cable && cable_color[sixth_cable] == PURPLE)
            {
                if (data_in[temp] == 1)
                {
                    success();
                    return;
                }
                if (data_in[temp] == 0)
                {
                    fail();
                    return;
                }
            }

            counter++;
        }
    }
    temp = 0;
    counter = 0;
    for (int i = 0; i < AMOUNT_OF_CABLES; i++)
    {
        if (cable_color[i] != BLACK)
        {

            if (check_loop == 0)
            {
                check_loop = 1;
                temp = i;
            }
            if (counter == second_cable)
            {
                temp_second = i;
            }

            if (cable_color[i] == RED)
            {
                check_red++;
            }
            if (cable_color[i] == YELLOW)
            {
                check_yellow++;
            }
            if (cable_color[i] == PURPLE)
            {
                check_purple++;
            }
            counter++;
        }
    }
    if (data_in[temp] == 1 && check_red == 1 && check_yellow > 1)
    {
        success();
        return;
    }
    if (data_in[temp] == 0 && check_red == 1 && check_yellow > 1)
    {
        fail();
        return;
    }

    if (data_in[temp_second] == 1 && check_purple == 0)
    {
        success();
        return;
    }
    if (data_in[temp_second] == 0 && check_purple == 0)
    {
        fail();
        return;
    }
    if (data_in[temp] == 1)
    {
        success();
        return;
    }

    fail();
    return;
}

void six_cables()
{
    int counter = 0;
    int check_yellow = 0;
    int check_white = 0;
    int check_red = 0;

    for (int i = 0; i < AMOUNT_OF_CABLES; i++)
    {
        if (cable_color[i] != BLACK)
        {
            if (cable_color[i] == YELLOW)
            {
                check_yellow++;
            }
            if (cable_color[i] == WHITE)
            {
                check_white++;
            }
            if (cable_color[i] == RED)
            {
                check_red++;
            }

            counter++;
        }
    }
    if (check_yellow == 0)
    {
        if (data_in[third_cable] == 1)
        {
            success();
            return;
        }
        if (data_in[third_cable] == 0)
        {
            fail();
            return;
        }
    }

    if (check_yellow == 1 && check_white > 1)
    {
        if (data_in[fourth_cable] == 1)
        {
            success();
            return;
        }
        if (data_in[fourth_cable] == 0)
        {
            fail();
            return;
        }
    }

    if (check_red == 0)
    {
        if (data_in[sixth_cable] == 1)
        {
            success();
            return;
        }
        if (data_in[sixth_cable] == 0)
        {
            fail();
            return;
        }
    }

    if (data_in[fourth_cable] == 1)
    {
        // success();
        return;
    }
    if (data_in[fourth_cable] == 0)
    {
        //fail();
        return;
    }
}