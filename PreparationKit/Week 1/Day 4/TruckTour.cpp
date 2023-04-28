#include <bits/stdc++.h>

/*
 * Complete the 'truckTour' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY petrolpumps as parameter.
 */
int truckTour(std::vector<std::vector<int>> petrolpumps)
{
    int indexPump, fuel = 0;
    bool found = false;
    int nextStop;

    for (indexPump = 0; !found && indexPump < petrolpumps.size(); indexPump++)
    {
        fuel += petrolpumps[indexPump][0];
        bool reachedEnd = false;
        int currStop = indexPump;
        while (!reachedEnd && fuel > 0)
        {
            if (currStop + 1 == petrolpumps.size())
                nextStop = 0;
            else
                nextStop = currStop + 1;

            fuel -= petrolpumps[currStop][1];

            if (fuel > 0)
            {
                if (nextStop == indexPump)
                {
                    found = true;
                    reachedEnd = true;
                }
                else
                {
                    fuel += petrolpumps[nextStop][0];
                    currStop = nextStop;
                }
            }
            else
            {
                reachedEnd = true;
                fuel = 0;
            }
        }
    }
    return nextStop;
}