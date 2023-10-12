#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

float randFloat(float max, float min)
{
    return ((float)(rand()) / RAND_MAX) * (max - min) + min;
}

int main()
{
    float x, y, xr, yr;
    int totalPoints = 0, pointsOnThisShot;
    srand(time(nullptr));
    for (int i = 1; i <= 5; i++)
    {
        cout << "Shot " << i << ". Enter x and y coordinates: " << endl;
        cin >> x;
        xr = randFloat(-5, 5);
        x = x + xr;
        cin >> y;
        yr = randFloat(-5, 5);
        y = y + yr;

        pointsOnThisShot = 5 - floor(sqrt(x*x + y*y));
        if (pointsOnThisShot < 0) pointsOnThisShot &= 0;
        totalPoints = totalPoints + pointsOnThisShot;

        cout << "You hit (" << x << "; " << y << "). Shift: xr = " << xr << "; yr = " << yr << endl;
        cout << "Your points in this round - " << pointsOnThisShot << "." << endl << "Total points - " << totalPoints << endl << endl;
    }
    if (totalPoints < 10) cout << "LOSER!!!";
}
