// 从左到右有A、B、C三根柱子，其中A柱子上面有从小叠到大的n个圆盘，现要求将A柱子上的圆盘移到C柱子上去，期间只有一个原则：一次只能移到一个盘子且大盘子不能在小盘子上面，求移动的步骤和移动的次数

#include <iostream>
#include <stdio.h>

using namespace std;

int cnt = 0;

void mvOne(char src, char dst)
{
    printf("%c -> %c\n", src, dst);
    ++cnt;
}
void mv(int n, char src, char dst, char tmp)
{
    if (n == 1)
    {
        mvOne(src, dst);
        return;
    }
    mv(n - 1, src, tmp, dst);
    mvOne(src, dst);
    mv(n - 1, tmp, dst, src);
}

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    mv(n, 'A', 'C', 'B');
    cout << cnt;
    return 0;
}