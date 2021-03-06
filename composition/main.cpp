#include <iostream>

#include "box.h"
#include "block.h"

using namespace std;

int main()
{
    Box box(Vec3(-1, -1, -1), Vec3(1, 1, 1));
    Box bo2(Vec3(-0.3, -0.4, -0.5), Vec3(2.5, 2.4, 2.3));

    Box inter = box.intersect(bo2);
    cout << "intersect: " << inter << " volume: " << inter.volume() << endl;

	Block block;

	system("pause");
    return 0;
}
